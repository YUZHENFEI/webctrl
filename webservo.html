#include <Servo.h>
HardwareSerial & esp8266 = Serial2;
#define DEBUG true 
#define sg92r_pin 9 
#define sg92_pin 10 
Servo sg92r,sg92;

int current_position = 0;
int current_position1 = 0;
int vel = 10; 
int minimum_position = 0; 
int maximum_position = 180;


void setup()
{
sg92r.attach(sg92r_pin);
sg92r.write(maximum_position);
sg92r.detach();
sg92.attach(sg92_pin);
sg92.write(maximum_position);
sg92.detach();
Serial.begin(115200);
esp8266.begin(115200);

esp8266Data("AT+RST\r\n", 2000, DEBUG); //reset module
esp8266Data("AT+CWMODE=1\r\n", 1000, DEBUG); //set station mode
esp8266Data("AT+CWJAP=\"AIFORU-828\",\"aiforu2017\"\r\n", 2000, DEBUG);   //connect wifi network
while(!esp8266.find("OK")) { //wait for connection
} 
esp8266Data("AT+CIFSR\r\n", 1000, DEBUG); 
esp8266Data("AT+CIPMUX=1\r\n", 1000, DEBUG); 
esp8266Data("AT+CIPSERVER=1,80\r\n", 1000, DEBUG); 
}


void loop()
{
if (esp8266.available())  
{
if (esp8266.find("+IPD,")) 
{
String msg;
esp8266.find("?"); 
msg = esp8266.readStringUntil(' '); 
String command = msg.substring(0, 3); // intercept first 3 chars
String valueStr = msg.substring(4);   //intercept from the 5th char
int value = valueStr.toInt();         
if (DEBUG) {
Serial.println(command);
Serial.println(value);
}
delay(100);


//move servo1 to desired angle in vertical direction
if(command == "sr1") {
//limit input angle
if (value >= maximum_position) {
value = maximum_position;
}
if (value <= minimum_position) {
value = minimum_position;
}
sg92r.attach(sg92r_pin); //attach servo
while(current_position != value) {
if (current_position > value) {
current_position -= 1;
sg92r.write(current_position);
delay(100/vel);
}
if (current_position < value) {
current_position += 1;
sg92r.write(current_position);
delay(100/vel);
}
}
sg92r.detach(); //dettach
}

//move servo1 to desired angle in horizontal direction
if(command == "sr2") {
//limit input angle
if (value >= maximum_position) {
value = maximum_position;
}
if (value <= minimum_position) {
value = minimum_position;
}
sg92.attach(sg92_pin); //attach servo
while(current_position1 != value) {
if (current_position1 > value) {
current_position1 -= 1;
sg92.write(current_position1);
delay(100/vel);
}
if (current_position1 < value) {
current_position1 += 1;
sg92.write(current_position1);
delay(100/vel);
}
}
sg92.detach(); //dettach
}


}
}
}


String esp8266Data(String command, const int timeout, boolean debug)
{
String response = "";
esp8266.print(command);
long int time = millis();
while ( (time + timeout) > millis())
{
while (esp8266.available())
{
char c = esp8266.read();
response += c;
}
}
if (debug)
{
Serial.print(response);
}
return response;
}
