#include "thingProperties.h"
#include <Servo.h>
Servo myservo;
void setup() {
Serial.begin(9600);
myservo.attach(D8);
delay(1500);
initProperties();
ArduinoCloud.begin(ArduinoIoTPreferredConnection);
setDebugMessageLevel(2);
ArduinoCloud.printDebugInfo();
}
void loop() {
ArduinoCloud.update();
}
void onPositionChange() {
myservo.write(position);
Serial.println(position);
}