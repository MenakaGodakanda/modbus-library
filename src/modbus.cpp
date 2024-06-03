#include "modbus.h"
#include <iostream>
#include <stdexcept>

Modbus::Modbus(uint8_t unitID) : unitID(unitID) {}

// Function to build a Modbus request packet
std::vector<uint8_t> Modbus::buildRequest(uint8_t functionCode, uint16_t startAddr, uint16_t quantity) {
    std::vector<uint8_t> request = { unitID, functionCode };
    request.push_back(startAddr >> 8);
    request.push_back(startAddr & 0xFF);
    request.push_back(quantity >> 8);
    request.push_back(quantity & 0xFF);
    uint16_t crc = crc16(request);
    request.push_back(crc & 0xFF);
    request.push_back(crc >> 8);
    return request;
}

// Function to build a Modbus response packet
std::vector<uint8_t> Modbus::buildResponse(uint8_t functionCode, const std::vector<uint8_t>& data) {
    std::vector<uint8_t> response = { unitID, functionCode };
    response.insert(response.end(), data.begin(), data.end());
    uint16_t crc = crc16(response);
    response.push_back(crc & 0xFF);
    response.push_back(crc >> 8);
    return response;
}

// Function to parse a Modbus response packet
bool Modbus::parseResponse(const std::vector<uint8_t>& response) {
    if (response.size() < 5) return false;
    uint16_t receivedCrc = (response[response.size() - 1] << 8) | response[response.size() - 2];
    std::vector<uint8_t> data(response.begin(), response.end() - 2);
    return receivedCrc == crc16(data);
}

// Function to calculate CRC16
uint16_t Modbus::crc16(const std::vector<uint8_t>& data) {
    uint16_t crc = 0xFFFF;
    for (size_t pos = 0; pos < data.size(); pos++) {
        crc ^= static_cast<uint16_t>(data[pos]);
        for (int i = 0; i < 8; i++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}
