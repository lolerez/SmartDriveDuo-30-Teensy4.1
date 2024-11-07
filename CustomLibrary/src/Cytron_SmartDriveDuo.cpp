/*
Original written by:
  08/05/17  Idris, Cytron Technologies
*/

#include "Cytron_SmartDriveDuo.h"

Cytron_SmartDriveDuo::Cytron_SmartDriveDuo(int mode, int txPin, uint32_t baudrate)
{
  _mode = mode;
  _txPin = txPin;

  if (_txPin == 1) {
    // Use Teensy's built-in Serial1
    MDDSSerial = &Serial1;
    MDDSSerial->begin(baudrate);
    while (!MDDSSerial);
  }
  else if (_txPin == 2) {
    // Use Teensy's built-in Serial2
    MDDSSerial = &Serial2;
    MDDSSerial->begin(baudrate);
    while (!MDDSSerial);
  }
  else {
    // Use Software Serial
    pinMode(_txPin, OUTPUT);
    MDDSSerial = new HardwareSerial1();
    MDDSSerial->begin(baudrate);
  }
}

void Cytron_SmartDriveDuo::initialByte(uint8_t dummyByte)
{
  MDDSSerial->write(dummyByte);
}

void Cytron_SmartDriveDuo::control(signed int motorLSpeed, signed int motorRSpeed)
{
  switch (_mode) {
    case SERIAL_SIMPLIFIED:
      if (motorLSpeed >= 0) {
        commandByte = 0;
        _motorLSpeed = map(motorLSpeed, 0, 100, 0, 63);
      }
      else if (motorLSpeed < 0) {
        commandByte = 0x40;
        _motorLSpeed = map(motorLSpeed, 0, -100, 0, 63);
      }
      commandByte = commandByte | _motorLSpeed;
      MDDSSerial->write(commandByte);

      if (motorRSpeed >= 0) {
        commandByte = 0xC0;
        _motorRSpeed = map(motorRSpeed, 0, 100, 0, 63);
      }
      else if (motorRSpeed < 0) {
        commandByte = 0x80;
        _motorRSpeed = map(motorRSpeed, 0, -100, 0, 63);
      }
      commandByte = commandByte | _motorRSpeed;
      MDDSSerial->write(commandByte);
      break;

    default:
      break;
  }
}