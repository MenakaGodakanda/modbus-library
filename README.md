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
![Screenshot 2024-06-03 221855](https://github.com/MenakaGodakanda/modbus-library/assets/156875412/1d52065a-001f-4ab1-95fd-c4f81bfc1029)<br><br>
![Screenshot 2024-06-03 221905](https://github.com/MenakaGodakanda/modbus-library/assets/156875412/1065fc41-df14-42c1-a1b5-9273d0710f97)

## Usage

Once built, you can run the `modbus_example` executable to see the library in action. It will simulate a Modbus server receiving a read holding registers request from a client, then responding with data.

```sh
./modbus_example
```

When you run the `modbus_example` executable, you should see the following output:<br><br>
![Screenshot 2024-06-03 221919](https://github.com/MenakaGodakanda/modbus-library/assets/156875412/08986294-ed2c-49fb-92bd-098afb30bbcf)

The output shows the exchange of Modbus messages between a client and a server. The server receives a request, processes it, sends a response, and the client successfully receives and validates the response. Here's what each line represents:
1. Server received request: `1 3 0 0 0 2 c4 b`:
This line indicates that the server received a Modbus request. The request is represented as a series of hexadecimal bytes. Here's what each byte means:
    - `1`: Address of the device that sent the request (in this case, it's device 1).
    - `3`: Function code, which specifies the type of Modbus function being requested (in this case, it's a read holding registers request).
    - `0 0`: Starting address of the register being requested (in this case, it's address 0).
    - `0 2`: Number of registers being requested (in this case, it's 2 registers).
    - `c4 b`: CRC (Cyclic Redundancy Check) bytes for error detection.

2. Server sending response: `1 3 0 a 0 b 24 f`:
This line indicates that the server is sending a Modbus response. The response is represented as a series of hexadecimal bytes. Here's what each byte means:
    - `1`: Address of the server responding to the request (in this case, it's server address 1).
    - `3`: Function code, which specifies the type of Modbus function being responded (in this case, it's a read holding registers response).
    - `0 a`: Byte count, indicating the number of data bytes that follow (in this case, it's 10 bytes).
    - `0 0`: Value of the first register requested (in this case, it's the value 0x0000).
    - `0 b`: Value of the second register requested (in this case, it's the value 0x000B).
    - `24 f`: CRC bytes for error detection.

3. Client sending request: `1 3 0 0 0 2 c4 b`:
This line indicates that the client is sending a Modbus request. The request is identical to the one received by the server, indicating that the client is requesting the same data from the server.

4. Client received valid response.
This line indicates that the client received a valid response from the server. The client likely verified the CRC and other aspects of the response packet and determined that it is valid.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
