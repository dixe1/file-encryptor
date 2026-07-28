//
// Created by bartek on 7/27/26.
//

#pragma once
#include <string>

#include "FileFormat.h"

void decryptFile(const std::string& pathToFile, const core::FileStruct &file, const std::string &password);
