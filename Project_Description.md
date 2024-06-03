# Modbus Library - Version 1
This project implements a Modbus communication library in C++ for industrial control systems.

## Features of the project:
1. **Modbus Server and Client**: The project implements both Modbus server and client functionalities, allowing for bi-directional communication between devices using the Modbus protocol.

2. **Modbus Protocol Support**: It supports the Modbus RTU protocol, a widely used communication protocol in industrial automation.

3. **Request and Response Handling**: The library provides methods for building Modbus requests and parsing Modbus responses, facilitating seamless communication between devices.

4. **CRC16 Calculation**: It includes a CRC16 calculation method according to the Modbus RTU protocol specification, ensuring data integrity during communication.

5. **Example Usage**: The project offers examples demonstrating how to use the library to simulate Modbus communication between a server and client, aiding developers in understanding and integrating the library into their projects.

## Understand Modbus Portocol:
### Modbus Data Packet Structure
- Modbus RTU Frame:
```
| Address | Function Code | Data       | CRC        |
| 1 byte  | 1 byte        | N bytes    | 2 bytes    |
```

### Modbus TCP Frame
```
| Transaction ID | Protocol ID | Length  | Unit ID | Function Code | Data       |
| 2 bytes        | 2 bytes     | 2 bytes | 1 byte  | 1 byte        | N bytes    |
```

### Common Function Codes
  - `0x01`: Read Coils
  - `0x02`: Read Discrete Inputs
  - `0x03`: Read Holding Registers
  - `0x04`: Read Input Registers
  - `0x05`: Write Single Coil
  - `0x06`: Write Single Register
  - `0x0F`: Write Multiple Coils
  - `0x10`: Write Multiple Registers

## Model-based Diagram:

Below is a sequence diagram illustrating the flow of messages between the Modbus client and server, describing how they interact during communication:

```
+-------------------+          +-------------------+
|      Client       |          |      Server       |
+-------------------+          +-------------------+
      |                          |
      |   buildRequest()         |
      |------------------------->|
      |                          |
      |        Request           |
      |------------------------->|  // Simulated Modbus request
      |                          |
      |                          |
      |                          |
      |                          |
      |        Response          |
      |<-------------------------|  // Simulated Modbus response
      |                          | 
      |                          |
      |      parseResponse()     |
      |<-------------------------|
      |                          |

```

In this diagram:
1. Client Interaction:
  - The client initiates communication by calling the `buildRequest()` method to construct a Modbus request packet.
  - This request packet is then sent to the server.

2. Server Interaction:
  - Upon receiving the request packet, the server processes it and generates a response.
  - The server then sends the response packet back to the client.

3. Response Handling:
  - The client receives the response packet and calls the `parseResponse()` method to interpret it.

## Project Structure:
```
modbus-library/
├── CMakeLists.txt          # CMake configuration file
├── include/                # Header files
│   └── modbus.h
├── src/                    # Source files
│   ├── modbus.cpp
│   └── main.cpp
└── examples/               # Example programs
    └── modbus_example.cpp
```

## Coding Details:

### Main Program (main.cpp)
This  will simulate a Modbus server and client interaction within the same application for simplicity. The server will handle a basic read holding registers request from the client.
1. Includes:
  - `#include <iostream>`: For standard input/output operations.
  - `#include <vector>`: To use the vector container class.
  - `#include <thread>`: For multithreading.
  - `#include "modbus.h"`: Includes the Modbus library header.

2. Server Simulation Function (runServer):
  - Function Definition: `void runServer(Modbus &server)`
  - Simulated Request: Creates a request vector simulating a read holding registers request from a client.
  - Prints Request: Outputs the received request to the console.
  - Simulated Response: Prepares a response vector with two register values.
  - Builds Response: Uses the `buildResponse` method to construct the response packet.
  - Prints Response: Outputs the response to the console.
  - Client Simulation Function (runClient):

3. Function Definition: `void runClient(Modbus &client)`
  - Build Request: Constructs a Modbus request to read holding registers.
  - Prints Request: Outputs the request to the console.
  - Simulated Response: Defines a response vector to simulate server response.
  - Parses Response: Uses the `parseResponse` method to validate the response.
  - Prints Validation Result: Outputs whether the response is valid or not.

4. Main Function:
  - Modbus Instances: Creates Modbus objects for server and client with unit ID 1.
  - Server Thread: Starts the server in a separate thread using `std::thread`.
  - Join Server Thread: Waits for the server thread to complete.
  - Run Client: Calls the `runClient` function in the main thread.

### Header File (modbus.h)

  - `#include <cstdint>`: Includes the standard integer types.
  - `#include <vector>`: Includes the vector container class.
  - `class Modbus`: Defines the Modbus class.
  - `public`: Public members accessible from outside the class.
  - `Modbus(uint8_t unitID)`: Constructor to initialize the unit ID.
  - `std::vector<uint8_t> buildRequest(...)`: Method to build a Modbus request packet.
  - `std::vector<uint8_t> buildResponse(...)`: Method to build a Modbus response packet.
  - `bool parseResponse(...)`: Method to parse a Modbus response packet.
  - `private`: Private members accessible only within the class.
  - `uint16_t crc16(...)`: Method to calculate CRC16 checksum.

### Modbus Implementation (modbus.cpp)

  - `#include "modbus.h"`: Includes the Modbus header file.
  - `#include <iostream>`: Includes the standard I/O stream library.
  - `#include <stdexcept>`: Includes the standard exception library.
  - `Modbus::Modbus(uint8_t unitID)`: unitID(unitID): Initializes the unit ID in the constructor.
  - `std::vector<uint8_t> Modbus::buildRequest(...)`: Builds a Modbus request packet.
  - `std::vector<uint8_t> Modbus::buildResponse(...)`: Builds a Modbus response packet.
  - `bool Modbus::parseResponse(...)`: Parses a Modbus response packet and checks its validity.
  - `uint16_t Modbus::crc16(...)`: Calculates the CRC16 checksum.

### Modbus Example (modbus_example.cpp)

  - `#include <iostream>`: Includes the standard I/O stream library.
  - `#include <vector>`: Includes the vector container class.
  - `#include "modbus.h"`: Includes the Modbus header file.
  - `int main()`: Entry point of the program.
  - `Modbus modbus(0x01)`: Creates a Modbus object with unit ID 1.
  - `std::vector<uint8_t> request = modbus.buildRequest(...)`: Builds a Modbus request packet.
  - `std::cout << "Request Packet: "`: Prints the request packet.
  - `std::vector<uint8_t> response = ...`: Example response packet.
  - `if (modbus.parseResponse(response))`: Parses the response packet and checks its validity.
  - `return 0`: Returns 0, indicating successful execution.

### Root CMake Configuration (CMakeLists.txt)

This configuration ensures that the modbus library is compiled and linked with the main application, creating an executable that demonstrates the Modbus server-client interaction.
  - cmake_minimum_required(VERSION 3.10): Sets the minimum required CMake version to 3.10.
  - project(ModbusLibrary): Defines the project name as `ModbusLibrary`.
  - set(CMAKE_CXX_STANDARD 11): Specifies that the C++ standard to be used is C++11.
  - include_directories(include): Adds the `include` directory to the list of paths that the compiler will search for header files.
  - add_library(modbus STATIC src/modbus.cpp): Defines a static library target named `modbus` using the source file `src/modbus.cpp`.
  - add_executable(modbus_example src/main.cpp): Defines an executable target named `modbus`_example using the source file `src/main.cpp`.
  - target_link_libraries(modbus_example modbus): Links the `modbus` library to the `modbus_example` executable, ensuring that the executable can use the functions defined in the library.

### Summary

- The Modbus Library project provides a robust solution for implementing Modbus communication in industrial control systems. With support for both server and client functionalities, along with features such as request and response handling and CRC16 calculation, it offers a comprehensive toolkit for developers working with Modbus-enabled devices.
- By providing example usage scenarios, the project facilitates easy integration into existing systems and serves as a valuable resource for developers seeking to leverage Modbus communication in their applications. With its adherence to Modbus protocol standards and focus on reliability and ease of use, the Modbus Library project is well-suited for a wide range of industrial automation projects.
