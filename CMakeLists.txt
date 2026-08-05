cmake_minimum_required (VERSION 3.29)

project (ep1m)

set(RRS_VERSION 1.9.0)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

option(CLIENT_BUILD "Build for client usage" ON)

add_subdirectory (ep1m)
add_subdirectory (ep1m-autopilot)

if (CLIENT_BUILD)
    add_subdirectory (msud-display)
    add_subdirectory (club-u-display)
endif()

