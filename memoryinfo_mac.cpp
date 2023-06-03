

#include "memoryinfo.hpp"

#include <sys/sysctl.h>

#include <iostream>

std::optional<unsigned long long> MemoryInfo::getAvailableRAMInBytes() {
    std::cout << "Determining memory on MAC\n";
    int mib[]     = {CTL_HW, HW_MEMSIZE};
    int64_t value = 0;
    size_t length = sizeof(value);

    if (-1 == sysctl(mib, 2, &value, &length, NULL, 0)) {
        return std::nullopt;
    } else {
        return value;
    }
}
