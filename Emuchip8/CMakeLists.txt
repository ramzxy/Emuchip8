# CMakeList.txt : CMake project for Emuchip8, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Emuchip8 "Emuchip8.cpp" "Emuchip8.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Emuchip8 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
