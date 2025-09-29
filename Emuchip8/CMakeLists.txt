# CMakeList.txt : CMake project for Emuchip8, include source and define
# project specific logic here.
#

# Find SDL2 using vcpkg
find_package(SDL2 CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (Emuchip8 "main.cpp"  "include/Chip8.h" "Chip8.cpp" "include/Platform.h")

# Link SDL2
target_link_libraries(Emuchip8 PRIVATE SDL2::SDL2 SDL2::SDL2main)

# Set output directory to main project directory
set_target_properties(Emuchip8 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Emuchip8 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
