#include <iostream>
#include <vector>
#include "modbus.h"

int main() {
    Modbus modbus(0x01);

    // Build a Modbus request to read holding registers
    std::vector<uint8_t> request = modbus.buildRequest(0x03, 0x0000, 0x0002);

    // Print the request packet
    std::cout << "Request Packet: ";
    for (uint8_t byte : request) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    // Example response (for demonstration purposes)
    std::vector<uint8_t> response = { 0x01, 0x03, 0x04, 0x00, 0x0A, 0x00, 0x0B, 0xD8, 0xF6 };

    // Parse the response packet
    if (modbus.parseResponse(response)) {
        std::cout << "Response is valid." << std::endl;
    } else {
        std::cout << "Response is invalid." << std::endl;
    }

    return 0;
}
