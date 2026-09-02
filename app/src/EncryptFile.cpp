#include <fstream>
#include <filesystem>
#include <array>
#include <span>

#include "FileFormat.h"
#include "EncryptFile.h"
#include "Encryption.h"

void encryptFile(const std::string& pathToFile, const std::string& password)
{
    std::ifstream inputFile(pathToFile, std::ios::binary);

    if (!inputFile)
        throw std::runtime_error("Could not open file");

    const uint32_t fileSize = std::filesystem::file_size(pathToFile);
    auto passwordStruct = core::generateKey(password);

    core::FileStruct resultFile;
    resultFile.salt = core::generate_SALT(*passwordStruct);
    resultFile.nonce = core::generate_NONCE(*passwordStruct);

    std::vector<unsigned char> buffer(1024);
    while (inputFile.read( reinterpret_cast<std::istream::char_type *>(buffer.data()), buffer.size()) || inputFile.gcount() != 0)
    {

        std::vector<unsigned char> chunk(buffer.begin(), buffer.end() + inputFile.gcount());
        auto encryptedChunk = core::encrypt(std::vector<unsigned char>(chunk), resultFile.nonce, *passwordStruct);
        resultFile.RAW_BYTES.insert(resultFile.RAW_BYTES.end() , encryptedChunk.begin(), encryptedChunk.end());
    }

    core::saveEncryptedFile(resultFile, pathToFile + ".encrypted");
}
