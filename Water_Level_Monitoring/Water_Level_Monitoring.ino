#include "thingProperties.h"
#define trigpin D7
#define echopin D6
#define led_1 D0
#define led_2 D1
#define led_3 D2
#define led_4 D3
int duration, distance;
void setup() {
Serial.begin(9600);
delay(1500);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(led_1, OUTPUT);
pinMode(led_2, OUTPUT);
pinMode(led_3, OUTPUT);
pinMode(led_4, OUTPUT);
digitalWrite(led_1, LOW);
digitalWrite(led_2, LOW);
digitalWrite(led_3, LOW);
digitalWrite(led_4, LOW);
initProperties();
ArduinoCloud.begin(ArduinoIoTPreferredConnection);
setDebugMessageLevel(2);
ArduinoCloud.printDebugInfo();
}
void loop() {
ArduinoCloud.update();
digitalWrite(trigpin, HIGH);
delayMicroseconds(1000);
digitalWrite(trigpin, LOW);


if( (distance > 20) && (distance <= 30) )
{
digitalWrite(led_1, LOW);
digitalWrite(led_2, LOW);
digitalWrite(led_3, HIGH);
digitalWrite(led_4, HIGH);
led1=LOW;
led2=LOW;
led3=HIGH;
led4=HIGH;
Serial.println(distance);
water_level=100-distance;
} else
if( (distance > 30) && (distance <= 40) )
{
digitalWrite(led_1, LOW);
digitalWrite(led_2, LOW);
digitalWrite(led_3, LOW);
digitalWrite(led_4, HIGH);
led1=LOW;
led2=LOW;
led3=LOW;
led4=HIGH;
Serial.println(distance);
water_level=100-distance;
} else
if( (distance > 50) )
{
digitalWrite(led_1, LOW);
digitalWrite(led_2, LOW);
digitalWrite(led_3, LOW);
digitalWrite(led_4, LOW);
led1=LOW;
led2=LOW;
led3=LOW;
led4=LOW;
water_level=100-distance;
}


duration = pulseIn(echopin,HIGH);
distance = ( duration / 2) / 29.1;
Serial.println("cm:");
Serial.println(distance);
if( (distance > 0) && (distance <= 10) )
{
digitalWrite(led_1, HIGH);
digitalWrite(led_2, HIGH);
digitalWrite(led_3, HIGH);
digitalWrite(led_4, HIGH);
led1=HIGH;
led2=HIGH;
led3=HIGH;
led4=HIGH;
Serial.println(distance);
water_level=100-distance;
} else
if( (distance > 10) && (distance <= 20) )
{
digitalWrite(led_1, LOW);
digitalWrite(led_2, HIGH);
digitalWrite(led_3, HIGH);
digitalWrite(led_4, HIGH);
led1=LOW;
led2=HIGH;
led3=HIGH;
led4=HIGH;
Serial.println(distance);
water_level=100-distance;
} else

}
void onLed3Change() {
// Do something
}
void onLed2Change() {
// Do something
}
void onLed1Change() {
// Do something
}
void onLed4Change() {
// Do something
}
void onWaterLevelChange() {
// Do something
}