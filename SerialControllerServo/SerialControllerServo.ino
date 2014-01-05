#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 

int inByte = 0;         // incoming serial byte
int count = 0;
int maxPulse = 2080;
int minPulse = 500;
int pin = 9;

void setup()
{
  // attaches the servo on pin 9 to the servo object 
  myservo.attach(pin, minPulse, maxPulse);
  myservo.write(0);
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  pinMode(2, INPUT);   // digital sensor is on digital pin 2
  establishContact();  // send a byte to establish contact until receiver responds 
}

void loop()
{
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.parseInt();
    Serial.print(count);
    Serial.print(":");
    Serial.println(inByte);
    count++;
    myservo.write(inByte);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("Enter number degree: 0 ~ 180");   // send an initial string
    delay(300);
  }
}
