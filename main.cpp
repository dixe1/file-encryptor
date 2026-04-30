#include <print>
#include <fstream>
#include <filesystem>
#include <vector>
#include <random>
#include <optional>
#include <string>

enum Type
{
    FROM_FILE,
    FROM_STRING,
};
struct Info
{
    std::string buffer;
    uint32_t key;
};
std::optional<Info> process(const std::string& fileNameOrString, Type type = FROM_STRING, uint32_t key = std::random_device{}())
{
    std::vector<char> buffer;
    std::ifstream inputFile;
    size_t fileSize{};
    switch (type)
    {
        case FROM_FILE:
            inputFile.open(fileNameOrString, std::ios::binary);
            if (!inputFile)
                return std::nullopt;

            fileSize = std::filesystem::file_size(fileNameOrString);
            buffer.resize(fileSize);
            if(!inputFile.read(buffer.data(), fileSize))
                return std::nullopt;
            break;
        case FROM_STRING:
            fileSize = fileNameOrString.size();
            buffer.resize(fileSize);
            std::ranges::copy(fileNameOrString, buffer.begin());
            break;
        default:
            return std::nullopt;
    }
    std::mt19937 generator(key);
    std::uniform_int_distribution<unsigned char> dist(0, 255);

    for (size_t i{}; i < fileSize; i++)
    {
        buffer[i] ^= dist(generator);
    }

    std::string bufferStr(buffer.data(), fileSize);
    return Info{bufferStr, key};
}

int main()
{
    // auto e1 = process("GitHubPrefix.txt", FROM_FILE);
    // if (!e1)
    //     std::println("error1");
    //
    // auto e2 = process(e1.value().buffer, FROM_STRING, e1.value().key);
    // if (!e2)
    //     std::println("error2");
    //
    // std::println("{}",e1.value().buffer);
    // std::println("{}",e2.value().buffer);
}