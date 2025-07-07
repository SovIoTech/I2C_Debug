#include <Arduino.h>
#include <Seeed_Arduino_Relay.h>

Relay relay(RELAY_I2C_ADDRESS); // 0x20

void setup() {
  Serial.begin(115200);
  while (!Serial);
  
  if (!relay.begin()) {
    Serial.println("Relay not found");
    while(1);
  }
  Serial.println("Relay found");
}

void loop() {
  for(int i = 1; i <= 4; i++) {
    Serial.print("Turning ON Relay ");
    Serial.println(i);
    relay.on(i);
    delay(1000);
    
    Serial.print("Turning OFF Relay ");
    Serial.println(i);
    relay.off(i);
    delay(1000);
  }
}
