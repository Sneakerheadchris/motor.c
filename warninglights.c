#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <ArdusatSDK.h>

Display display;
int demodelay=2000;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  // Clear the OLED screen
  display.clearDisplay();
ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Acceleration accel;
float gforce;

int led1 = 1; //lED's are being assigned to their corresponding pins
int pindelay = 200; //the delay between each LED flash is 200 milliseconds

void setup(void)
{
  serialConnection.begin(9600);
  accel.begin();
  serialConnection.println("timestamp, gforce");

  pinMode(led1, OUTPUT); //each LED is set to only output whatever information is provided
}

void loop(void)
{
  accel.read();
  gforce = (sqrt(sq(accel.x)+sq(accel.y)+sq(accel.z))/9.8); //finding the gforce in the acceleration  
  
  serialConnection.println(valueToJSON("G-Force", DATA_UNIT_METER_PER_SECONDSQUARED, gforce)); //the computer will print how much g force is created in meters/sec squared
   
  if (gforce>6) { 
  display.drawPixel(2, 7, WHITE);
  display.drawPixel(3, 6, WHITE);
  display.drawPixel(4, 2, WHITE);
  display.drawPixel(4, 5, WHITE);
  display.drawPixel(5, 5, WHITE);
  display.drawPixel(6, 5, WHITE);
  display.drawPixel(7, 5, WHITE);
  display.drawPixel(8, 2, WHITE);
  display.drawPixel(8, 5, WHITE);
  display.drawPixel(9, 6, WHITE);
  display.drawPixel(10, 7, WHITE);
  display.display();
  
}
