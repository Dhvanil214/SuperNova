#include <Wire.h>
#include <SparkFun_VL53L1X.h> // Include the library for VL53L1X

#define TCAADDR 0x70 // I2C address of TCA9548A

SFEVL53L1X distanceSensor;

void tcaSelect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i); // Select the TCA channel
  Wire.endTransmission();
}



void setup() {
  Serial.begin(115200);

  // Initialize I2C on pins SDA = 32, SCL = 33
  Wire.begin(32, 33);
  
  // Select TCA9548A channel 5 (sensor 3)
  tcaSelect(5);
  if (distanceSensor.init() == false) {
    Serial.println("Sensor 3 (channel 5) not found.");
  } else {
    Serial.println("Sensor 3 (channel 5) found and initialized.");
    distanceSensor.setDistanceModeLong();  // Set to long-range mode
    distanceSensor.setTimingBudgetInMs(50);  // Short timing budget for faster reads
    distanceSensor.startRanging();
  }

  // Select TCA9548A channel 6 (sensor 1)
  tcaSelect(6);
  if (distanceSensor.init() == false) {
    Serial.println("Sensor 1 (channel 6) not found.");
  } else {
    Serial.println("Sensor 1 (channel 6) found and initialized.");
    distanceSensor.setDistanceModeLong();  // Set to long-range mode
    distanceSensor.setTimingBudgetInMs(50);  // Short timing budget for faster reads
    distanceSensor.startRanging();
  }

  // Select TCA9548A channel 7 (sensor 2)
  tcaSelect(7);
  if (distanceSensor.init() == false) {
    Serial.println("Sensor 2 (channel 7) not found.");
  } else {
    Serial.println("Sensor 2 (channel 7) found and initialized.");
    distanceSensor.setDistanceModeLong();
    distanceSensor.setTimingBudgetInMs(50);
    distanceSensor.startRanging();
  }
}

void loop() {
  
  // Select and read from sensor 3 (channel 5)
  tcaSelect(5);
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  uint16_t distance3 = distanceSensor.getDistance();
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();
  Serial.print("Sensor 3 (channel 5) Distance (mm): ");
  Serial.println(distance3);

  // Select and read from sensor 1 (channel 6)
  tcaSelect(6);
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  uint16_t distance1 = distanceSensor.getDistance();
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();
  Serial.print("Sensor 1 (channel 6) Distance (mm): ");
  Serial.println(distance1);

  // Select and read from sensor 2 (channel 7)
  tcaSelect(7);
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  uint16_t distance2 = distanceSensor.getDistance();
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();
  Serial.print("Sensor 2 (channel 7) Distance (mm): ");
  Serial.println(distance2);

  delay(200); // Small delay between readings
}