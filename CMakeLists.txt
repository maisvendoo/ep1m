cmake_minimum_required (VERSION 3.29)

project (ep1m)

set(RRS_VERSION 1.9.0)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_subdirectory (ep1m)
add_subdirectory (ep1m-autopilot)
add_subdirectory (msud-display)
add_subdirectory (club-u-display)

