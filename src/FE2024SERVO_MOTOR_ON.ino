#include <SCServo.h>

SCSCL sc;

#define S_RXD 18    //Setting the Serial Receive Pins
#define S_TXD 19    //Setting the Serial Transmitting Pins

void setup()
{
  //Initialize serial port communication, this serial port is used for communication between the USB cable and the serial monitor on the computer
  Serial.begin(115200);
  //Initializes serial port 1 communication for controlling the serial bus servo's; SERIAL_8N1 is the configuration data, parity, and stop bits; specifies the serial port pins
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  //Set the serial port parameter of the SCServo object to Serial1, indicating that the 1000000 serial port is used to control the servo
  sc.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  sc.WritePos(1, 400, 0, 1500);    //Set the position, speed and acceleration of servo 1 with a delay of 2s
  delay(754);
  
  sc.WritePos(1, 600, 0, 1500);    //Set the position, speed and acceleration of servo 1 with a delay of 2s(1000 is max and 500 is middle)
  delay(754);
}