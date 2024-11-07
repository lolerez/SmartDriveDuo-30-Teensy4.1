/* 
 * This example shows how to control MDDS30 in Serial Simplified mode with Arduino.
 * Set MDDS30 input mode to 0b11001100
 * Open Serial Monitor, set baudrate to 9600bps and "No line ending".
 * Send 0: Left motor stops
 *      1: Left motor rotates CW with half speed
 *      2: Left motor rotates CW with full speed
 *      3: Left motor rotates CCW with half speed
 *      4: Left motor rotates CCW with full speed
 *      5: Right motor stops
 *      6: Right motor rotates CW with half speed
 *      7: Right motor rotates CW with full speed
 *      8: Right motor rotates CCW with half speed
 *      9: Right motor rotates CCW with full speed
 * 
 * Note: This example also compatible with MDDS10 and MDDS60
 *
 * Hardware Connection:
 *   Arduino Uno    MDDS30
 *   GND ---------- GND
 *   4 ------------ IN1
 *
 * Related Products:
 * - SmartDriveDuo-30: http://www.cytron.com.my/P-MDDS60
 * - CT UNO: http://www.cytron.com.my/p-ct-uno
 * - DC Brush Motors: http://www.cytron.com.my/c-84-dc-motor
 * - LiPo Battery: http://www.cytron.com.my/c-87-power/c-97-lipo-rechargeable-battery-and-charger
 * - Male to Male Jumper: https://www.cytron.com.my/p-wr-jw-mm65
 *
 * URL: http://www.cytron.com.my
 */

#include <Cytron_SmartDriveDuo.h>


Cytron_SmartDriveDuo smartDriveDuo301(SERIAL_SIMPLIFIED, 1, 115200); // Use Serial1
Cytron_SmartDriveDuo smartDriveDuo302(SERIAL_SIMPLIFIED, 2, 115200); // Use Serial2

void setup()
{

}

void loop()
{
int speedLeft = 10;
int speedRight = 20;

// Control the two motor controllers
smartDriveDuo301.control(speedLeft, speedRight);
smartDriveDuo302.control(speedLeft, speedRight);
}