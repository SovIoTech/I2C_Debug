#include <Wire.h>

#define RELAY_I2C_ADDRESS 0x20

void setup() {
  Wire.begin(); // Initialize I2C
  Serial.begin(115200);
  Serial.println("4-Channel SPDT Relay Test");
}

void setRelay(uint8_t relayNum, bool state) {
  Wire.beginTransmission(RELAY_I2C_ADDRESS);
  Wire.write(relayNum);  // Relay number (1-4)
  Wire.write(state ? 1 : 0);  // State (1=ON, 0=OFF)
  Wire.endTransmission();
}

void loop() {
  // Example: Cycle through each relay
  for(int i = 1; i <= 4; i++) {
    Serial.print("Turning ON Relay ");
    Serial.println(i);
    setRelay(i, true);
    delay(1000);
    
    Serial.print("Turning OFF Relay ");
    Serial.println(i);
    setRelay(i, false);
    delay(1000);
  }
}
