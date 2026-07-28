#include <print>
#include <sodium.h>

#include "GenerateKey.h"
namespace core
{
    PasswordStruct generateKey(const std::string &password)
    {
        std::array<unsigned char, crypto_secretbox_KEYBYTES> key{};
        std::array<unsigned char, crypto_pwhash_SALTBYTES> salt{};

        randombytes_buf(salt.data(), crypto_pwhash_SALTBYTES);

        int x = crypto_pwhash(
            key.data(),
            key.size(),
            password.data(),
            password.size(),
            salt.data(),
            crypto_pwhash_OPSLIMIT_MODERATE,
            crypto_pwhash_MEMLIMIT_MODERATE,
            crypto_pwhash_ALG_ARGON2ID13
        );

        return {key, salt};
    }

    std::array<unsigned char, 32> generateKey(const std::string &password, const std::array<unsigned char, crypto_pwhash_SALTBYTES> &salt)
    {
        std::array<unsigned char, crypto_secretbox_KEYBYTES> key{};

        int x = crypto_pwhash(
            key.data(),
            key.size(),
            password.data(),
            password.size(),
            salt.data(),
            crypto_pwhash_OPSLIMIT_MODERATE,
            crypto_pwhash_MEMLIMIT_MODERATE,
            crypto_pwhash_ALG_ARGON2ID13
        );

        return key;
    }
}