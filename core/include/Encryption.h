//
// Created by bartek on 7/27/26.
//

#pragma once

#include <vector>
#include "FileFormat.h"
#include "GenerateKey.h"

namespace core
{
    FileStruct encrypt(std::vector<unsigned char> input, const PasswordStruct& password);
}