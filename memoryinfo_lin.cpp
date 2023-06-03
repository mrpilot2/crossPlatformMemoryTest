

#include "memoryinfo.hpp"

#include <fstream>

#include <iostream>
#include <limits>

std::optional<unsigned long long> MemoryInfo::getAvailableRAMInBytes() {
    std::cout << "Determining memory on LINUX\n";
    std::string token;
    std::ifstream file("/proc/meminfo");
    while(file >> token) {
        if(token == "MemTotal:") {
            unsigned long mem;
            if(file >> mem) {
                return mem;
            } else {
                return std::nullopt;
            }
        }
        // Ignore the rest of the line
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return std::nullopt; // Nothing found
}