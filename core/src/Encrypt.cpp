//
// Created by bartek on 9/17/26.
//

#include "Encrypt.h"
#include <iostream>
#include <sodium.h>

void testLibSodium()
{
    unsigned char buffer[1024];
    randombytes(buffer, sizeof(buffer));
    std::cout << buffer << '\n';
}