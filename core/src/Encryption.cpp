//
// Created by bartek on 7/27/26.
//

#include <array>

#include "Encryption.h"

namespace core
{
    std::vector<unsigned char> encrypt(std::vector<unsigned char> input,const std::array<unsigned char, crypto_secretbox_NONCEBYTES>& nonce, const PasswordStruct& password)
    {
        std::vector<unsigned char> result(input.size() + crypto_secretbox_MACBYTES);
        const size_t fileSize = input.size();

        crypto_secretbox_easy(
            result.data(),
            input.data(),
            input.size(),
            nonce.data(),
            password.key.data()
            );

        return result;
    }

    const std::array<unsigned char, 16> generate_SALT(const PasswordStruct& password)
    {
        return password.salt;
    }
    std::array<unsigned char, crypto_secretbox_NONCEBYTES> generate_NONCE(const PasswordStruct& password)
    {
        std::array<unsigned char, crypto_secretbox_NONCEBYTES> nonce;

        randombytes_buf(nonce.data(), nonce.size());

        return nonce;
    }
}