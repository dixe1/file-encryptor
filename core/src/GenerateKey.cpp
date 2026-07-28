#include <print>
#include <sodium.h>
#include <optional>

#include "GenerateKey.h"
namespace core
{
    std::optional<PasswordStruct> generateKey(const std::string &password)
    {
        std::array<unsigned char, crypto_secretbox_KEYBYTES> key{};
        std::array<unsigned char, crypto_pwhash_SALTBYTES> salt{};

        randombytes_buf(salt.data(), crypto_pwhash_SALTBYTES);

        const int code = crypto_pwhash(
            key.data(),
            key.size(),
            password.data(),
            password.size(),
            salt.data(),
            crypto_pwhash_OPSLIMIT_MODERATE,
            crypto_pwhash_MEMLIMIT_MODERATE,
            crypto_pwhash_ALG_ARGON2ID13
        );

        if (code != 0)
            return std::nullopt;

        return PasswordStruct{key, salt};
    }

    std::optional<std::array<unsigned char, crypto_secretbox_KEYBYTES>> generateKey(const std::string &password, const std::array<unsigned char, crypto_pwhash_SALTBYTES> &salt)
    {
        std::array<unsigned char, crypto_secretbox_KEYBYTES> key{};

        const int code = crypto_pwhash(
            key.data(),
            key.size(),
            password.data(),
            password.size(),
            salt.data(),
            crypto_pwhash_OPSLIMIT_MODERATE,
            crypto_pwhash_MEMLIMIT_MODERATE,
            crypto_pwhash_ALG_ARGON2ID13
        );

        if (code != 0)
            return std::nullopt;

        return key;
    }
}