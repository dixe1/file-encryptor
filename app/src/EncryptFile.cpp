#include <fstream>
#include <filesystem>

#include "FileFormat.h"
#include "EncryptFile.h"
#include "Encryption.h"

void encryptFile(const std::string& pathToFile, const std::string& password)
{
    std::ifstream inputFile(pathToFile, std::ios::binary);

    if (!inputFile)
        throw std::runtime_error("Could not open file");

    const uint32_t fileSize = std::filesystem::file_size(pathToFile);
    core::FileStruct inputFileStruct;
    inputFileStruct.RAW_BYTES.resize(fileSize);

    inputFile.read(reinterpret_cast<char *>(inputFileStruct.RAW_BYTES.data()), fileSize);

    auto passwordStruct = core::generateKey(password);



    auto test = encrypt(inputFileStruct.RAW_BYTES, *passwordStruct);

    saveEncryptedFile(test, pathToFile + ".encrypted");
}
