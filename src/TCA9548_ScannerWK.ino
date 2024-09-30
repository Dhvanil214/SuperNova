#include <Wire.h>

#define TCA_ADDRESS 0x70  // Default address for TCA9548A

// Function to select a TCA9548A channel
void tcaSelect(uint8_t channel) {
  if (channel > 7) return;
  Wire.beginTransmission(TCA_ADDRESS);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

void scanI2C() {
  byte error, address;
  int nDevices;

  for (uint8_t i = 0; i < 8; i++) {  // Scan all 8 channels of the TCA9548A
    tcaSelect(i);
    Serial.print("Scanning TCA9548A channel: ");
    Serial.println(i);

    nDevices = 0;
    for (address = 1; address < 127; address++) {
      Wire.beginTransmission(address);
      error = Wire.endTransmission();

      if (error == 0) {
        Serial.print("I2C device found at address 0x");
        if (address < 16) Serial.print("0");
        Serial.print(address, HEX);
        Serial.println("  !");
        nDevices++;
      } else if (error == 4) {
        Serial.print("Unknown error at address 0x");
        if (address < 16) Serial.print("0");
        Serial.println(address, HEX);
      }
    }

    if (nDevices == 0) {
      Serial.println("No I2C devices found\n");
    } else {
      Serial.println("Done scanning\n");
    }
  }
}

void setup() {
  Wire.begin(32, 33);  // Set SDA to pin 32 and SCL to pin 33
  Serial.begin(115200);
  Serial.println("\nI2C Scanner with TCA9548A");

  scanI2C();  // Start the scan when setup begins
}

void loop() {
  // No need to repeat scanning in loop
  delay(10000);  // Optionally delay 10 seconds to scan again
}
 