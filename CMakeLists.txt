CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

PROJECT(crossPlatformMemoryTest)

SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(crossPlatformMemoryTest main.cpp)

IF(WIN32)
    TARGET_SOURCES(crossPlatformMemoryTest PRIVATE memoryinfo_win.cpp)
ELSEIF (UNIX)
    TARGET_SOURCES(crossPlatformMemoryTest PRIVATE memoryinfo_lin.cpp)
ELSE ()
    TARGET_SOURCES(crossPlatformMemoryTest PRIVATE memoryinfo_mac.cpp)
ENDIF()