#include <optional>

#include "Decryption.h"
namespace core
{
    std::optional<FileStruct> decrypt(const FileStruct &input, const std::array<unsigned char, crypto_secretbox_KEYBYTES>& key)
    {
        FileStruct result;

        result.RAW_BYTES.resize(input.RAW_BYTES.size() - crypto_secretbox_MACBYTES);

        const int code = crypto_secretbox_open_easy(
                result.RAW_BYTES.data(),
                input.RAW_BYTES.data(),
                input.RAW_BYTES.size(),
                input.nonce.data(),
                key.data()
        );

        if (code != 0)
            return std::nullopt;

        return result;
    }
}