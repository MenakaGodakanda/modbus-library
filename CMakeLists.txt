cmake_minimum_required(VERSION 3.10)
project(ModbusLibrary)

set(CMAKE_CXX_STANDARD 11)

# Include the directory containing modbus.h
include_directories(include)

# Add the source files for the Modbus library
add_library(modbus STATIC src/modbus.cpp)

# Add the executable for the main application
add_executable(modbus_example src/main.cpp)

# Link the modbus library to the executable
target_link_libraries(modbus_example modbus)
