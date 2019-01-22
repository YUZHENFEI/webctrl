#include <Servo.h>
HardwareSerial & esp8266 = Serial2;

#define DEBUG true 
#define sg90_pin 9 

Servo sg90; 

int current_position = 0;
int vel = 10; 
int minimum_position = 0; 
int maximum_position = 180;


void setup()
{
sg90.attach(sg90_pin);
sg90.write(maximum_position);
sg90.detach();
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
String command = msg.substring(0, 3); 
String valueStr = msg.substring(4);   
int value = valueStr.toInt();         
if (DEBUG) {
Serial.println(command);
Serial.println(value);
}
delay(100);


//move servo1 to desired angle
if(command == "sr1") {
//limit input angle
if (value >= maximum_position) {
value = maximum_position;
}
if (value <= minimum_position) {
value = minimum_position;
}
sg90.attach(sg90_pin); //attach servo
while(current_position != value) {
if (current_position > value) {
current_position -= 1;
sg90.write(current_position);
delay(100/vel);
}
if (current_position < value) {
current_position += 1;
sg90.write(current_position);
delay(100/vel);
}
}
sg90.detach(); //dettach
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
