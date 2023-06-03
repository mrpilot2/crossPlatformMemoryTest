

#include "memoryinfo.hpp"

#include <windows.h>

#include <iostream>

 std::optional<unsigned long long> MemoryInfo::getAvailableRAMInBytes() {
    std::cout << "Determining memory on WINDOWS\n";
    MEMORYSTATUSEX memory_status;
    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memory_status)) {
        return memory_status.ullTotalPhys;
    }

    return std::nullopt;
}