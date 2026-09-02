//
// Created by bartek on 7/27/26.
//

#pragma once

#include <vector>
#include "FileFormat.h"
#include "GenerateKey.h"

namespace core
{
    std::vector<unsigned char> encrypt(std::vector<unsigned char> input,const std::array<unsigned char, crypto_secretbox_NONCEBYTES>& nonce, const PasswordStruct& password);

    const std::array<unsigned char, 16> generate_SALT(const PasswordStruct& password);
    std::array<unsigned char, crypto_secretbox_NONCEBYTES> generate_NONCE(const PasswordStruct& password);
}