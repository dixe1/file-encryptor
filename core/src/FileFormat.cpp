//
// Created by bartek on 7/27/26.
//

#include <filesystem>
#include <fstream>
#include <expected>

#include "FileFormat.h"
namespace core
{
    std::expected<FileStruct, std::string> loadEncryptedFile(const std::string& fileName)
    {
        FileStruct result;

        const size_t fileSize = std::filesystem::file_size(fileName);

        result.RAW_BYTES.resize(fileSize  - result.salt.size() - result.nonce.size());

        std::ifstream input(fileName, std::ios::binary);

        if (!input)
            return std::unexpected("could not open file");

        if(!input.read(reinterpret_cast<char *>(result.salt.data()), result.salt.size()))
            return std::unexpected("could not read SALT");

        if(!input.read(reinterpret_cast<char *>(result.nonce.data()), result.nonce.size()))
            return std::unexpected("could not read NONCE");

        if(!input.read(reinterpret_cast<char *>(result.RAW_BYTES.data()), result.RAW_BYTES.size()))
            return std::unexpected("could not read RAW_BYTES");

        return result;
    }

    std::string saveEncryptedFile(const FileStruct& input, const std::string& fileName)
    {
        std::ofstream output(fileName, std::ios::binary);

        if(!output)
            return "could not open file";

        if(!output.write(reinterpret_cast<const char *>(input.salt.data()), input.salt.size()))
            return "could not write SALT";

        if(!output.write(reinterpret_cast<const char *>(input.nonce.data()), input.nonce.size()))
            return "could not write NONCE";

        if(!output.write(reinterpret_cast<const char *>(input.RAW_BYTES.data()), input.RAW_BYTES.size()))
            return "could not write RAW_BYTES";

        return "";
    }
}