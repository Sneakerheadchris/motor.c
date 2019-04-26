#include <Arduino.h>
#include <Wire.h>
#include <ArdusatSDK.h>

ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Acceleration accel;
float gforce;

int led1 = 13; //lED's are being assigned to their corresponding pins
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
    digitalWrite(led1, HIGH);
    delay(pindelay); //when the g force is calculated to be above 6 meters/sec squared, the LED will be determined as set to HIGH
    }
  else { 
    digitalWrite(led1, LOW); //if the value is below the previous value of the if statement, LED is set to LOW
    }

}
