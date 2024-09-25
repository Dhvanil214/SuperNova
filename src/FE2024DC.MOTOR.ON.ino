 

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
  initMotors();
}

void loop() {
  //Call forward function
  forwardA(400);
  forwardB(400);
}