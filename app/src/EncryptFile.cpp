#include <fstream>
#include <filesystem>
#include <array>

#include "EncryptFile.h"
#include "Encryption.h"

void encryptFile(const std::string& pathToFile, const std::string& password)
{
    // TODO: Better error handling
    std::ifstream inputFile(pathToFile, std::ios::binary);
    std::ofstream outputFile(pathToFile + ".encrypted", std::ios::binary);

    if (!inputFile || !outputFile)
        throw std::runtime_error("Could not open file");

    auto passwordStructOptional = core::generateKey(password);

    if (!passwordStructOptional)
        throw std::runtime_error("Could not generate password");

    core::PasswordStruct& passwordStruct = *passwordStructOptional;

    {   // Generate and write SALT to file
        auto salt = core::generate_SALT(passwordStruct);
        outputFile.write(reinterpret_cast<const char *>(salt.data()), salt.size());
    }

    // Generate and write NONCE to file
    auto nonce = core::generate_NONCE(passwordStruct);
    outputFile.write(reinterpret_cast<const char *>(nonce.data()), nonce.size());

    constexpr size_t bufferSize = 2048;
    std::array<unsigned char, bufferSize> buffer{};
    while (inputFile.read( reinterpret_cast<std::istream::char_type *>(buffer.data()), buffer.size()) || inputFile.gcount() != 0)
    {
        // TODO: Clean up this
        std::vector<unsigned char> chunk(buffer.begin(), buffer.end() + inputFile.gcount());
        auto encryptedChunk = core::encrypt(chunk, nonce, passwordStruct);
        outputFile.write(reinterpret_cast<const char *>(encryptedChunk.data()), encryptedChunk.size());
    }
}
