#ifndef CYTRON_SMARTDRIVEDUO_h
#define CYTRON_SMARTDRIVEDUO_h

#include <Arduino.h>
#include <HardwareSerial.h>

enum {
  SERIAL_SIMPLIFIED,
};

class Cytron_SmartDriveDuo
{
  public:
    Cytron_SmartDriveDuo(int mode, int txPin, uint32_t baudrate);
    void initialByte(uint8_t dummyByte);
    void control(signed int motorLeftSpeed, signed int motorRightSpeed);
    
  private:
    HardwareSerial* MDDSSerial;
    uint8_t _mode;
    uint8_t _txPin, _rxPin = 99, _boardId;
    uint8_t commandByte, _motorLSpeed, _motorRSpeed;
};

#endif