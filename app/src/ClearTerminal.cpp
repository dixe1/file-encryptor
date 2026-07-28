#include <print>

void clearTerminal()
{
    std::print("\033[2J\033[H");
}