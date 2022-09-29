// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <Servo.h>

Servo servo; 
RTC_DS1307 rtc;
int pos=0;
int lastDayFed=0;
//DateTime timeUpdateChecker;
void setup () {
  pinMode(10, OUTPUT);  //Relay with light
  servo.attach(9);      //Pin 9 servo
 Serial.begin(9600);    
 if (! rtc.begin()) {
   Serial.println("Couldn't find RTC");
 }
 if (! rtc.isrunning()) {
   Serial.println("RTC is NOT running!");
 }
 servo.write(0);
 //attention();
 //feedTurtles();
}
void loop () {
//  if (timeUpdateChecker == rtc.now())         //if time doesn't change then the rtc is not updating the values anymore.
//  Serial.println("RTC broken");
 DateTime now = rtc.now();
 //
 
 
 
// timeUpdateChecker = now;
//if (now.second()%15==0)
//{
  tellTheTime(now);
//}
 if (now.hour() >= 7 && now.hour() <23)        //Morning: turning the lights on
 {
  Serial.println("Day. Light ON");
  digitalWrite(10, LOW);
 }
 
 if (now.hour() == 21&&now.day()%2==1&&now.day()!=lastDayFed)        //Evening: feeding the turtles
 {
  Serial.println("Attention, feeding the turtles");
  attention();
  feedTurtles();
  lastDayFed=now.day();
 }

 //Testing the feeder

//if (now.second() %20 ==0)
//{
//    Serial.println("Attention, feeding the turtles");
//  attention();
 // feedTurtles();
//}

 //End of testong
 

  if (now.hour()>=23||now.hour()<7)         //Night: turning the lights off
  {                           
  Serial.println("Night: Closig lights");
  digitalWrite(10,HIGH);
}
 
 delay(18000);
}

void feedTurtles ()
{
  for (pos = 0; pos <= 138; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
 //shake(180);

 
  for (pos = 138; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
 shake(0);
  
}
void shake(int pos)
{
  if (pos==180)
  {
    servo.write(110);
  delay(80);
  servo.write(120);
  delay(80);
  servo.write(150);
  delay(80);
  servo.write(180);
  delay(80);
  servo.write(150);
  delay(80);
  servo.write(180);
  delay(80);
  }
  else
  {
servo.write(30);
  delay(180);
  servo.write(0);
  delay(180);
  servo.write(30);
  delay(180);
  servo.write(0);
  delay(180);
    
    servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
  servo.write(30);
  delay(100);
  servo.write(0);
  delay(100);
   servo.write(30);
  delay(80);
  servo.write(0);
  delay(80);
  servo.write(30);
  delay(80);
  servo.write(0);
  delay(80);
  servo.write(30);
  delay(80);
  servo.write(0);
  delay(80);
  




  

  
  
  }
  
}

void tellTheTime(DateTime now)
{ 
  
  Serial.print("The time is: ");
   Serial.print(now.hour(), DEC);
 Serial.print(':');
 Serial.print(now.minute(), DEC);
 Serial.print(':');
 Serial.print(now.second(), DEC);
 Serial.println();
}

void attention()
{
  digitalWrite(10, HIGH);
  delay(3500);
  digitalWrite(10,LOW);
  delay(3500);
  digitalWrite(10, HIGH);
  delay(3500);
  digitalWrite(10,LOW);
  delay(3500);
}
