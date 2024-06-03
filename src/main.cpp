#include <iostream>
#include <vector>
#include <thread>
#include "modbus.h"

void runServer(Modbus &server) {
    // Simulate a server handling a read holding registers request
    std::vector<uint8_t> request = { 0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B };

    std::cout << "Server received request: ";
    for (uint8_t byte : request) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    // Simulate the server's response (e.g., reading two registers with values 0x000A and 0x000B)
    std::vector<uint8_t> data = { 0x00, 0x0A, 0x00, 0x0B }; // Register values
    std::vector<uint8_t> response = server.buildResponse(0x03, data);

    std::cout << "Server sending response: ";
    for (uint8_t byte : response) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;
}

void runClient(Modbus &client) {
    // Build a Modbus request to read holding registers
    std::vector<uint8_t> request = client.buildRequest(0x03, 0x0000, 0x0002);

    // Print the request packet
    std::cout << "Client sending request: ";
    for (uint8_t byte : request) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    // Example response (for demonstration purposes)
    std::vector<uint8_t> response = { 0x01, 0x03, 0x04, 0x00, 0x0A, 0x00, 0x0B, 0x9B, 0xF6 };

    // Parse the response packet
    if (client.parseResponse(response)) {
        std::cout << "Client received valid response." << std::endl;
    } else {
        std::cout << "Client received invalid response." << std::endl;
    }
}

int main() {
    Modbus server(0x01);
    Modbus client(0x01);

    // Start server in a separate thread
    std::thread serverThread(runServer, std::ref(server));
    serverThread.join();

    // Start client in main thread
    runClient(client);

    return 0;
}
