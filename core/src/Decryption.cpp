//
// Created by bartek on 7/27/26.
//

#include "Decryption.h"
namespace core
{
    FileStruct decrypt(const FileStruct &input, const std::array<unsigned char, crypto_secretbox_KEYBYTES>& key)
    {
        FileStruct result;

        result.RAW_BYTES.resize(input.RAW_BYTES.size() - crypto_secretbox_MACBYTES);

        int x = crypto_secretbox_open_easy(
                result.RAW_BYTES.data(),
                input.RAW_BYTES.data(),
                input.RAW_BYTES.size(),
                input.nonce.data(),
                key.data()
        );

        return result;
    }
}