//This Program makes simple Square or Circle

#define S_RXD 18
#define S_TXD 19

#include <SCServo.h>
SCSCL sc;

const uint16_t PWMA = 25;         
const uint16_t AIN2 = 17;        
const uint16_t AIN1 = 21;         
 

const uint16_t ANALOG_WRITE_BITS = 8;

int freq = 5000;
int channel_A = 0;
int resolution = ANALOG_WRITE_BITS;

void initMotors(){
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  ledcAttachChannel(PWMA, freq, resolution, channel_A);
}

void forwardA(uint16_t pwm){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWMA, pwm);
}

void stopA(uint16_t pwm){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  ledcWrite(PWMA, pwm);
}


void setup() {
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, S_RXD, S_TXD);
  sc.pSerial = &Serial1;
  delay(1000);
  initMotors();
}

void loop() {
  
  sc.WritePos(1, 500, 0, 1000);               //Servo(ID1) moves at max speed=1000, moves to position=500.
  delay(1000);
  forwardA(500);
  delay(2000);
  stopA(0);
  delay(200);
  
  sc.WritePos(1, 420, 0, 1000);               //Turning Right
  delay(500);
  forwardA(500);
  delay(1500);
  stopA(0);
  delay(200);
 
}
