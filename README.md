# Modbus Library

This project implements a Modbus communication library in C++ for industrial control systems. It includes both a Modbus server and client, along with examples demonstrating how to use the library.<br>
<a href="https://github.com/MenakaGodakanda/modbus-library/blob/main/Project_Description.md">Project Description</a>


## Features

- **Modbus Server**: Simulates a Modbus server capable of handling read holding registers requests.
- **Modbus Client**: Implements a Modbus client capable of sending read holding registers requests and parsing responses.
- **CRC16 Calculation**: Includes a CRC16 calculation method for generating CRC values according to the Modbus RTU protocol.
- **Example Usage**: Provides simple examples demonstrating how to use the library to communicate between a Modbus client and server.

## Requirements

- Operating System: Ubuntu (or any other Linux distribution)
- Compiler: g++ (for C++ development)
- Build System: CMake (to manage the build process)
- Editor/IDE: Visual Studio Code (or any other preferred code editor)
- Version Control: Git
- CMake (version 3.10 or higher)

### Install Required Tools
Open a terminal and run the following commands to install the necessary tools:
```sh
sudo apt update
sudo apt install build-essential cmake git
```

## Building

To build the project, follow these steps:

1. Clone this repository
```sh
git clone https://github.com/MenakaGodakanda/modbus-library.git
```

2. Navigate to the project directory: `cd modbus-library`
3. Create a build directory: `mkdir build && cd build`
4. Run CMake: `cmake ..`
5. Build the project: `make`

The output should indicate that the project was built successfully:<br><br>


## Usage

Once built, you can run the `modbus_example` executable to see the library in action. It will simulate a Modbus server receiving a read holding registers request from a client, then responding with data.

```sh
./modbus_example
```

When you run the `modbus_example` executable, you should see the following output:<br><br>


## License

This project is licensed under the MIT License - see the LICENSE file for details.
