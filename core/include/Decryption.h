//
// Created by bartek on 7/27/26.
//

#pragma once
#include <optional>

#include "FileFormat.h"

namespace core
{
    std::optional<FileStruct> decrypt(const FileStruct &input, const std::array<unsigned char, crypto_secretbox_KEYBYTES>& key);
}