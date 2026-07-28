//
// Created by bartek on 7/27/26.
//

#pragma once
#include <array>
#include <vector>
#include <string>
#include <expected>
#include <sodium.h>

namespace core
{
    struct FileStruct
    {
        std::array<unsigned char, crypto_pwhash_SALTBYTES> salt;
        std::array<unsigned char, crypto_secretbox_NONCEBYTES> nonce;
        std::vector<unsigned char> RAW_BYTES;
    };

    std::expected<FileStruct, std::string> loadEncryptedFile(const std::string& fileName);
    std::string saveEncryptedFile(const FileStruct& input, const std::string& fileName);
}