#include "Encrypt.h"
#include <expected>
#include <print>
#include <stdexcept>
#include <string>

enum class OperationType
{
    ENCRYPT,
    DECRYPT
};

std::expected<OperationType, std::string> setOperationType(const char* argv)
{
    OperationType operation;

    const std::string arg(argv);
    if (arg == "-e" || arg == "encrypt")
    {
        operation = OperationType::ENCRYPT;
    }
    else if (arg == "-d" || arg == "decrypt")
    {
        operation = OperationType::DECRYPT;
    }
    else
    {
        return std::unexpected(std::format("unknown operation type: {}", arg));
    }

    return operation;
}

int main(const int argc, char* argv[])
{
    if (argc <= 3 || argc > 4)
        throw std::runtime_error("Wrong number of arguments");

    std::string filename(argv[1]);
    std::string password(argv[3]);
    OperationType operation;

    if (const auto op = setOperationType(argv[2]))
        operation = *op;
    else
        throw std::runtime_error(op.error());

    switch (operation)
    {
    case OperationType::ENCRYPT:
        testLibSodium();
        break;

    case OperationType::DECRYPT:
        testLibSodium();
        break;

    default:
        throw std::runtime_error("Something went wrong");
    }
}