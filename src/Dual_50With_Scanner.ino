#include <Wire.h>
#include <SparkFun_VL53L1X.h>

#define XSHUT_PIN_FRONT 27
#define XSHUT_PIN_LEFT 16
#define FRONT_SENSOR_ADDRESS 0x29
#define LEFT_SENSOR_ADDRESS 0x39
const int SENSOR_POWER_ON_DELAY = 1000;  // Increase delay to ensure sensors power up/down properly

SFEVL53L1X frontSensor;
SFEVL53L1X leftSensor;

// Function to power on/off the sensors using the XSHUT pin
void sensorShutdown(uint8_t pin, bool state) {
    digitalWrite(pin, state ? HIGH : LOW);
    delay(10);  // Small delay to ensure proper power on/off
}

void initializeSensors() {
    // Step 1: Initialize front sensor (keep left sensor off)
    Serial.println("Initializing front sensor...");
    sensorShutdown(XSHUT_PIN_LEFT, false);  // Ensure left sensor is off
    sensorShutdown(XSHUT_PIN_FRONT, true);  // Turn on front sensor
    delay(SENSOR_POWER_ON_DELAY);  // Delay for power stabilization

    if (frontSensor.begin() != 0) {
        Serial.println("Failed to initialize front sensor!");
        while (1);
    }
    Serial.println("Front sensor initialized.");
    Serial.print("Front Sensor I2C Address: 0x");
    Serial.println(frontSensor.getI2CAddress(), HEX);

    // Step 2: Turn off front sensor and initialize left sensor
    Serial.println("Turning off front sensor...");
    sensorShutdown(XSHUT_PIN_FRONT, false);  // Turn off front sensor
    delay(SENSOR_POWER_ON_DELAY);  // Ensure the front sensor is fully powered down

    Serial.println("Initializing left sensor...");
    sensorShutdown(XSHUT_PIN_LEFT, true);    // Turn on left sensor
    delay(SENSOR_POWER_ON_DELAY);  // Delay for power stabilization

    if (leftSensor.begin() != 0) {
        Serial.println("Failed to initialize left sensor!");
        while (1);
    }
    Serial.print("Left Sensor I2C Address before change: 0x");
    Serial.println(leftSensor.getI2CAddress(), HEX);

    // Change the I2C address to 0x30 if it's not already
    if (leftSensor.getI2CAddress() != LEFT_SENSOR_ADDRESS) {
        leftSensor.setI2CAddress(LEFT_SENSOR_ADDRESS);
        Serial.println("Left sensor address changed to 0x30.");
    }

    Serial.print("Left Sensor I2C Address after change: 0x");
    Serial.println(leftSensor.getI2CAddress(), HEX);

    // Step 3: Re-initialize the front sensor at its default address
    Serial.println("Turning off left sensor...");
    sensorShutdown(XSHUT_PIN_LEFT, false);    // Turn off left sensor
    delay(SENSOR_POWER_ON_DELAY);  // Delay to fully power down left sensor

    Serial.println("Re-initializing front sensor...");
    sensorShutdown(XSHUT_PIN_FRONT, true);   // Power on front sensor
    delay(SENSOR_POWER_ON_DELAY);  // Ensure proper power-up

    if (frontSensor.begin() != 0) {
        Serial.println("Failed to re-initialize front sensor!");
        while (1);
    }
    Serial.println("Front sensor re-initialized.");
    Serial.print("Front Sensor I2C Address: 0x");
    Serial.println(frontSensor.getI2CAddress(), HEX);

  //  sensorShutdown(XSHUT_PIN_LEFT, true);   // Power on front sensor
  //  delay(10);
}

void i2cscanning(){
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    // The I2C scanner uses the return value of
    // Wire.endTransmission to know if a device did acknowledge the transmission
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("Done scanning\n");

  delay(5000);  // Wait 5 seconds before scanning again
}

int16_t readDistance(SFEVL53L1X &sensor) {
    sensor.startRanging();
    while (!sensor.checkForDataReady()) {
        delay(1);  // Wait for data to be ready
    }
    int16_t distance = sensor.getDistance();  // Get distance in mm
    sensor.clearInterrupt();
    sensor.stopRanging();
    return distance;
}

void setup() {
    Wire.begin(32,33);  // I2C communication with SDA on pin 32 and SCL on pin 33
  //  Wire.setClock(100000);  // Set I2C speed to 100 kHz for more reliable communication
    Serial.begin(115200);
    pinMode(XSHUT_PIN_FRONT, OUTPUT);
    pinMode(XSHUT_PIN_LEFT, OUTPUT);

    initializeSensors();  // Initialize the sensors

    Serial.print("Front:");
    Serial.println(frontSensor.getI2CAddress(), HEX);

    Serial.print("Left:");
    Serial.println(leftSensor.getI2CAddress(), HEX);
}

void loop() {

  i2cscanning();

/*    // Read distances from both sensors
    int16_t frontDistance = readDistance(frontSensor);
    Serial.print("Front Distance: ");
    Serial.print(frontDistance);
  //  Serial.print("  ");

    int16_t leftDistance = readDistance(leftSensor);
    Serial.print("Left Distance: ");
    Serial.println(leftDistance);
  
    delay(50);  // Delay for half a second before the next reading*/
}
