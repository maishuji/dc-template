cmake_minimum_required( VERSION 3.11.0)
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

set(TARGET_NAME "my_module")
add_executable(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set_target_properties(${TARGET_NAME} PROPERTIES
                      CMAKE_CXX_STANDARD 20
                      CXX_EXTENSIONS OFF
                      CXX_INCLUDE_WHAT_YOU_USE ${IWYU_PATH}
                      )

# GL must be linked after raylib
if(PLATFORM_DREAMCAST)
    # ---- Dreamcast specific settings ----
    target_link_libraries(${TARGET_NAME} PUBLIC dcplib raylib GL)
else()
    target_link_libraries(${TARGET_NAME} PUBLIC raylib GL)
endif()
message(STATUS "******Dreamcast ? : ${PLATFORM_DREAMCAST}")

if (PLATFORM_DREAMCAST)
    # ---- ROMDISK generation ----
    set(ROMDISK_DIR "romdisk")
    kos_add_romdisk(${TARGET_NAME} ${ROMDISK_DIR})

    # ---- Add target to generate the CDI image ----
    add_generate_cdi_image_for_target(${TARGET_NAME})
endif()

