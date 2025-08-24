#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); // RX, TX
char t;

#define MLa 4     //left motor 1st pin
#define MLb 5     //left motor 2nd pin
#define MRa 6    //right motor 1st pin
#define MRb 7    //right motor 2nd pin
#define BUZ 12  // The pin the BUZZER is connected to
#define LEDF 13  // The pin the FRONT LED is connected to
 
void setup()
{
  Serial.begin(9600);
bluetooth.begin(9600);
pinMode(MLa,OUTPUT);   //left motors forward
pinMode(MLb,OUTPUT);   //left motors reverse
pinMode(MRa,OUTPUT);   //right motors forward
pinMode(MRb,OUTPUT);   //right motors reverse
pinMode(LEDF, OUTPUT); // Declare the FRONT LED as an output
pinMode(BUZ, OUTPUT); // Declare the BUZZER as an output

}
 
void loop() 
{
if(bluetooth.available()>0)
{
  t = bluetooth.read();
  Serial.println(t);
}
 switch(t)
 {
  case 'F':
        {            //move forward(all motors rotate in forward direction)
          digitalWrite(MLa,LOW);
          digitalWrite(MLb,HIGH);
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,HIGH);
          digitalWrite(LEDF,HIGH);
          delay(10);
        }
        digitalWrite(LEDF,LOW);
   break;
   
  case 'B':
        {      //move reverse (all motors rotate in reverse direction)
          digitalWrite(MLa,HIGH);
          digitalWrite(MLb,LOW);
          digitalWrite(MRa,HIGH);
          digitalWrite(MRb,LOW);
          digitalWrite(LEDF,HIGH);
          delay(10);
        }
        digitalWrite(LEDF,LOW);
   break;
   
  case 'L':
        {      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
          digitalWrite(MLa,LOW); 
          digitalWrite(MLb,HIGH); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,LOW);
          digitalWrite(LEDF,HIGH);
        }
        digitalWrite(LEDF,LOW);
   break;
   
  case 'R':
        {      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
          digitalWrite(MLa,LOW); 
          digitalWrite(MLb,LOW); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,HIGH);
          digitalWrite(LEDF,HIGH);
        }
        digitalWrite(LEDF,LOW);
   break;
   
   
      
   case 'V':
        {           //LED ON
          digitalWrite(BUZ,HIGH);
                  }
  break;
  
 case 'v':
        {           //LED ON
          digitalWrite(BUZ,LOW);
                 }
  break;

 case 'W':
        {           //LED ON
          digitalWrite(LEDF,HIGH);
          
        }
  break;

  case 'w':
        {           //LED ON
          digitalWrite(LEDF,LOW);
         
        }
  break;

case 'X':
        {           //LED ON
         
          digitalWrite(BUZ,HIGH);
          digitalWrite(LEDF,HIGH);
          delay(500);
          digitalWrite(BUZ,LOW);
          digitalWrite(LEDF,LOW);
          delay(500);
        
         
        }
   break;
  
  case 'x':
        {           //LED ON
          digitalWrite(BUZ,LOW);
         
        }
   break;

    case 'S':
        {           //STOP (all motors stop)
          digitalWrite(MLa,LOW);
          digitalWrite(MLb,LOW); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,LOW);
          
          
        }

 
        
 }
}
