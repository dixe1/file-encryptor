#pragma once
#include <array>
#include <string>
#include <optional>
#include <sodium.h>

namespace core
{
    struct PasswordStruct
    {
        std::array<unsigned char, crypto_secretbox_KEYBYTES> key;
        std::array<unsigned char, crypto_pwhash_SALTBYTES> salt;
    };

    // ------------------------

    std::optional<PasswordStruct> generateKey(const std::string& password);

    std::optional<std::array<unsigned char, crypto_secretbox_KEYBYTES>> generateKey
    (
        const std::string& password,
        const std::array<unsigned char, crypto_pwhash_SALTBYTES>& salt
    );
}