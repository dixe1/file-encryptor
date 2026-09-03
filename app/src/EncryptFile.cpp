#include <fstream>
#include <filesystem>
#include <array>

#include "EncryptFile.h"

#include <iostream>

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

    auto& passwordStruct = *passwordStructOptional;


// TODO: abstract this into core library

    // Write SALT to file
    outputFile.write(reinterpret_cast<const char *>(passwordStruct.salt.data()), passwordStruct.salt.size());

    std::vector<unsigned char> buffer(1024 * 1024); // 1MB
    while (inputFile.read( reinterpret_cast<std::istream::char_type *>(buffer.data()), buffer.size()) || inputFile.gcount() != 0)
    {
        auto nonce = core::generate_NONCE(passwordStruct);

        const uint64_t chunkSize = inputFile.gcount();
        std::vector<unsigned char> chunk(buffer.begin(), buffer.begin() + chunkSize);

        auto encryptedChunk = core::encrypt(chunk, nonce, passwordStruct);


        // Write NONCE
        outputFile.write(reinterpret_cast<const char *>(nonce.data()), nonce.size());

        // Write size of encrypted data
        outputFile.write(reinterpret_cast<const char *>(&chunkSize), sizeof(chunkSize));

        // Write encrypted data
        outputFile.write(reinterpret_cast<const char *>(encryptedChunk.data()), encryptedChunk.size());
    }
}
