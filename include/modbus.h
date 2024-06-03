#ifndef MODBUS_H
#define MODBUS_H

#include <vector>
#include <cstdint>

class Modbus {
public:
    Modbus(uint8_t unitID);
    std::vector<uint8_t> buildRequest(uint8_t functionCode, uint16_t startAddr, uint16_t quantity);
    std::vector<uint8_t> buildResponse(uint8_t functionCode, const std::vector<uint8_t>& data);
    bool parseResponse(const std::vector<uint8_t>& response);
    uint16_t crc16(const std::vector<uint8_t>& data);
private:
    uint8_t unitID;
};

#endif // MODBUS_H
