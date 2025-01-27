cmake_minimum_required( VERSION 3.11.0)
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

project(dc-template CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(NoInSourceBuilds)

# Optional: include the iwyu cmake module, useful for checking includes
find_program(IWYU_PATH NAMES include-what-you-use iwyu)
# ------------------------------------------ #
# Global cmake variables
# ------------------------------------------ #
set(CMAKE_CXX_STANDARD 20)

# ------------------------------------------ #
# Subdirectories
# ------------------------------------------ #
add_subdirectory(src)