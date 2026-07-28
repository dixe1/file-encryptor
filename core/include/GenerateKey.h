#pragma once
#include <array>
#include <string>
#include <sodium.h>

namespace core
{
    struct PasswordStruct
    {
        std::array<unsigned char, crypto_secretbox_KEYBYTES> key;
        std::array<unsigned char, crypto_pwhash_SALTBYTES> salt;
    };

    // ------------------------

    PasswordStruct generateKey(const std::string& password);

    std::array<unsigned char, crypto_secretbox_KEYBYTES> generateKey
    (
        const std::string& password,
        const std::array<unsigned char, crypto_pwhash_SALTBYTES>& salt
    );
}