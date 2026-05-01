#include <filesystem>
#include <print>
#include <optional>
#include <vector>
#include <random>
#include <fstream>

struct Info
{
    std::vector<char> buffer;
    uint32_t key;
};

void process(std::vector<char>& input, uint32_t key)
{
    std::mt19937 generator(key);
    std::uniform_int_distribution<unsigned char> dist(0, 255);

    for (size_t i{}; i < input.size(); i++)
    {
        input[i] ^= dist(generator);
    }
}

// Files
std::optional<Info> encryptFile(const std::string& fileName)
{
    std::ifstream inputFile(fileName, std::ios::binary);
    const auto key = std::random_device{}();
    const auto fileSize = std::filesystem::file_size(fileName);

    std::vector<char> data;
    data.resize(fileSize);
    inputFile.read(data.data(), fileSize);
    process(data, key);

    return Info{data, key};
}
std::vector<char> decryptFile(const std::string& fileName, const uint32_t key)
{
    std::ifstream inputFile(fileName, std::ios::binary);
    const auto fileSize = std::filesystem::file_size(fileName);

    std::vector<char> data;
    data.resize(fileSize);
    inputFile.read(data.data(), fileSize);
    process(data, key);

    return data;
}

// Strings
std::optional<Info> encryptString(const std::string& str)
{
    const auto key = std::random_device{}();

    std::vector<char> data(str.begin(), str.end());
    process(data, key);

    return Info{data, key};
}
std::vector<char> decryptString(const std::string& str, const uint32_t& key)
{
    std::vector<char> data(str.begin(), str.end());
    process(data, key);

    return data;
}


int main()
{
    auto test_1 = encryptFile("GitHubPrefix.txt");
    process(test_1->buffer, test_1->key);   // Decryption
    for (auto& i : test_1->buffer)
        std::print("{}", i);

    std::fstream file("GitHubPrefix.txt");
    std::ostringstream ostr;
    ostr << file.rdbuf();
    auto test_2 = encryptString(ostr.str());

    process(test_2->buffer, test_2->key);   // Decryption
    for (auto& i : test_2->buffer)
        std::print("{}", i);
}