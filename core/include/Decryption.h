//
// Created by bartek on 7/27/26.
//

#pragma once
#include <string>

#include "FileFormat.h"

namespace core
{
    FileStruct decrypt(const FileStruct &input, const std::array<unsigned char, crypto_secretbox_KEYBYTES>& key);
}