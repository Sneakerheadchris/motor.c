#include <Wire.h>
#include <ArdusatSDK.h>

ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Acceleration accel;
float gforce;

int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 7;
int led6 = 6;
int led7 = 5;
int led8 = 4;
int led9 = 3;
int led10 = 2;
int pindelay = 200;

void setup(void)
{
  serialConnection.begin(9600);
  accel.begin();
  serialConnection.println("timestamp, gforce");

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}

void loop(void)
{
  accel.read();
  gforce = (sqrt(sq(accel.x)+sq(accel.y)+sq(accel.z))/9.8); 
  
  serialConnection.println(valueToJSON("G-Force", DATA_UNIT_METER_PER_SECONDSQUARED, gforce));
   
  if (gforce>1.5) { 
    digitalWrite(led10, HIGH);  
    delay(pindelay);
    }
  else { 
    digitalWrite(led10, LOW); 
    }

    if (gforce>2) { 
    digitalWrite(led9, HIGH);  
    delay(pindelay);
    }
  else { 
    digitalWrite(led9, LOW); 
    }

    if (gforce>2.5) { 
    digitalWrite(led8, HIGH);  
    delay(pindelay);
    }
  else { 
    digitalWrite(led8, LOW); 
    }
  
  if (gforce>3) { 
    digitalWrite(led7, HIGH); 
    delay(pindelay);
    }
  else { 
    digitalWrite(led7, LOW); 
    }
  
   if (gforce>3.5) { 
    digitalWrite(led6, HIGH); 
    delay(pindelay);
    }
  else { 
    digitalWrite(led6, LOW); 
    } 
    
  if (gforce>4) { 
    digitalWrite(led5, HIGH); 
    delay(pindelay);
    }
  else { 
    digitalWrite(led5, LOW); 
    }
  
  if (gforce>4.5) { 
    digitalWrite(led4, HIGH);
    delay(pindelay);
    }
  else { 
    digitalWrite(led4, LOW); 
    }
  
   if (gforce>5) { 
    digitalWrite(led3, HIGH);
    delay(pindelay);
    }
  else { 
    digitalWrite(led3, LOW); 
    } 
  
  if (gforce>5.5) { 
    digitalWrite(led2, HIGH);
    delay(pindelay);
    }
  else { 
    digitalWrite(led2, LOW); 
    }
  
  if (gforce>6) { 
    digitalWrite(led1, HIGH);
    delay(pindelay);
    }
  else { 
    digitalWrite(led1, LOW); 
    }

}
