//
// Created by bartek on 7/27/26.
//

#include "Encryption.h"

namespace core
{
    FileStruct encrypt(std::vector<unsigned char> input, const PasswordStruct& password)
    {
        FileStruct result;
        const size_t fileSize = input.size();

        randombytes_buf(result.nonce.data(), result.nonce.size());

        result.salt = password.salt;

        result.RAW_BYTES.resize(
            input.size() + crypto_secretbox_MACBYTES
        );

        crypto_secretbox_easy(
            result.RAW_BYTES.data(),
            input.data(),
            input.size(),
            result.nonce.data(),
            password.key.data()
            );

        return result;
    }
}