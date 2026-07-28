#include <fstream>
#include <filesystem>

#include "DecryptFile.h"
#include "Decryption.h"
#include "GenerateKey.h"

void decryptFile(const std::string& pathToFile, const core::FileStruct &file, const std::string &password)
{

    const auto key = core::generateKey(password, file.salt);

    auto decryptedFile = decrypt(file, key);

    const uint32_t fileSize = std::filesystem::file_size(pathToFile);
    decryptedFile.RAW_BYTES.resize(fileSize);

    std::ofstream outPutFile(pathToFile.substr(0, pathToFile.size() - 10), std::ios::binary);
    outPutFile.write(reinterpret_cast<const char *>(decryptedFile.RAW_BYTES.data()), fileSize);
}
