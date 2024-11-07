# Cytron_SmartDriveDuo

Arduino Library for Cytron Smart Drive Duo Motor Driver Series for the teensy

Maintained by Nobody, As is


 Download the library as .zip file and extract it to Arduino libraries directory.
  
to use example: 

Cytron_SmartDriveDuo smartDriveDuo301(SERIAL_SIMPLIFIED, 1, 115200); // Use Serial1
Cytron_SmartDriveDuo smartDriveDuo302(SERIAL_SIMPLIFIED, 2, 115200); // Use Serial2

// Control the two motor controllers
smartDriveDuo301.control(speedLeft, speedRight);
smartDriveDuo302.control(speedLeft, speedRight);
