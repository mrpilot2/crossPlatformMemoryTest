

#ifndef CROSSPLATFORMMEMORYTEST_MEMORYINFO_HPP
#define CROSSPLATFORMMEMORYTEST_MEMORYINFO_HPP

#include <optional>

class MemoryInfo {
public:
    static std::optional<unsigned long long> getAvailableRAMInBytes();
};


#endif //CROSSPLATFORMMEMORYTEST_MEMORYINFO_HPP
