#include <SCServo.h>

SCSCL sc;

#define S_RXD 18    //Setting the Serial Receive Pins
#define S_TXD 19    //Setting the Serial Transmitting Pins

//The following defines the ESP32 pin of the TB6612 control  
//Motor A
const uint16_t PWMA = 25;         
const uint16_t AIN2 = 17;        
const uint16_t AIN1 = 21;

//Motor B        
const uint16_t BIN1 = 22;       
const uint16_t BIN2 = 23;        
const uint16_t PWMB = 26;   

//Define the precision of the PWM, with a precision of 8, the PWM value is in the range of 0-255 (2^8-1)
const uint16_t ANALOG_WRITE_BITS = 8;

//PWM frequency of pins used for PWM outputs  
int freq = 100000;

//Defines PWM channel
int channel_A = 0;
int channel_B = 1;
int resolution = ANALOG_WRITE_BITS;

void initMotors(){
  //Setting the operating mode of the ESP32 pin used to control the TB6612FNG
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  //Set the channel, frequency, and precision of the ESP32 pin used to control the PWM outputs
  ledcAttachChannel(PWMA, freq, resolution, channel_A);
  ledcAttachChannel(PWMB, freq, resolution, channel_B);
  //Bind PWMA pin to A-channel  
  

  //ledcSetup(channel_B, freq, resolution);
  //ledcAttachPin(PWMB, channel_B);

}

void forwardA(uint16_t pwm){
  //Setting the direction of rotation of the A motor
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  //Setting the PWM output duty cycle of channel A
  ledcWrite(PWMA, pwm);
}

void forwardB(uint16_t pwm){
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  ledcWrite(PWMB, pwm);
}

void setup() {
  //Initialize the motor pin and PWM setting
  Serial.begin(115200);
  //Initializes serial port 1 communication for controlling the serial bus servo's; SERIAL_8N1 is the configuration data, parity, and stop bits; specifies the serial port pins
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  //Set the serial port parameter of the SCServo object to Serial1, indicating that the 1000000 serial port is used to control the servo
  sc.pSerial = &Serial1;
  delay(1000);
  initMotors();
}

void loop() {
  sc.WritePos(1, 500, 0, 1500);    //Move Straight
  delay(754);
  forwardA(400);
  delay(2000);
  forwardA(0);

  sc.WritePos(1, 400, 0, 1500);    // Turn Left
  delay(754);
  forwardA(400);
  delay(2000);
  forwardA(0);

  sc.WritePos(1, 500, 0, 1500);    // Move Straight
  delay(754);
  forwardA(400);
  delay(2000);
  forwardA(0);

  
}