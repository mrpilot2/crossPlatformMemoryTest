
#include "memoryinfo.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (auto memory = MemoryInfo::getAvailableRAMInBytes(); memory.has_value())
        std::cout << "Available memory is " << memory.value() << '\n';
    else
        std::cerr << "Could not determine amount of memory installed\n";
    return 0;
}
