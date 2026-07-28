#include <print>
#include <iostream>

#include "GenerateKey.h"
#include "FileFormat.h"
#include "Encryption.h"
#include "ClearTerminal.h"
#include "DecryptFile.h"
#include "EncryptFile.h"

// TODO: Error handling in app

int main(int argc, char* argv[])
{
    std::string pathToFile = argv[1];

    std::string option;
    bool run = true;
    while (run)
    {
        clearTerminal();
        std::println("1. Encrypt File");
        std::println("2. Decrypt File");
        std::println("3. Exit");

        std::getline(std::cin, option);

        switch (option[0])
        {
            case '1':
                encryptFile(pathToFile, option.substr(2));
                break;

            case '2':
            {
                auto test = core::loadEncryptedFile(pathToFile);
                decryptFile(pathToFile, *test, option.substr(2));
                break;
            }

            case '3':
                run = false;
        }
    }
}