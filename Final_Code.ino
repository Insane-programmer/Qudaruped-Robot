#include <Adafruit_PWMServoDriver.h>
#include<Wire.h>
#include<SoftwareSerial.h>

Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver();
#define MIN_PULSEWIDTH 650
#define MAX_PULSEWIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500 
#define FREQUENCY 60

// Define pins for ultrasonic sensor

// Define Variable
// Bluetooth Connection Variables
char data;

void setup() {
  // put your setup code here, to run once:
pwm.begin();
pwm.setPWMFreq(FREQUENCY);
Serial.begin(9600);

//Set coxa Servo motors in Right Position

// For Standing Up:

  pwm.setPWM(8,0,pulseWidth(60));
  pwm.setPWM(9,0,pulseWidth(60));
  pwm.setPWM(10,0,pulseWidth(0));
  pwm.setPWM(11,0,pulseWidth(0));
  delay(1000);
  pwm.setPWM(4,0,pulseWidth(30));
  pwm.setPWM(5,0,pulseWidth(30));
  pwm.setPWM(6,0,pulseWidth(30));
  pwm.setPWM(7,0,pulseWidth(30));
  delay(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
    
{
  // Move leg 1 and 3 Forward
  pwm.setPWM(4,0,pulseWidth(45));
  pwm.setPWM(0,0,pulseWidth(60));
  pwm.setPWM(4,0,pulseWidth(0));
  pwm.setPWM(0,0,pulseWidth(90));
  pwm.setPWM(6,0,pulseWidth(45));
  pwm.setPWM(2,0,pulseWidth(120));
  pwm.setPWM(6,0,pulseWidth(0));
  pwm.setPWM(2,0,pulseWidth(90));
  delay(1000);
  // move leg 2 and 4 Forward
  pwm.setPWM(5,0,pulseWidth(45));
  pwm.setPWM(1,0,pulseWidth(60));
  pwm.setPWM(5,0,pulseWidth(0));
  pwm.setPWM(1,0,pulseWidth(90));
  pwm.setPWM(7,0,pulseWidth(45));
  pwm.setPWM(3,0,pulseWidth(120));
  pwm.setPWM(7,0,pulseWidth(0));
  pwm.setPWM(3,0,pulseWidth(90));
  delay(1000);
}
{
  //Move leg 1 and 3 backward
   pwm.setPWM(4,0,pulseWidth(45));
  pwm.setPWM(0,0,pulseWidth(120));
  pwm.setPWM(4,0,pulseWidth(0));
  pwm.setPWM(0,0,pulseWidth(90));
  pwm.setPWM(6,0,pulseWidth(45));
  pwm.setPWM(2,0,pulseWidth(60));
  pwm.setPWM(6,0,pulseWidth(0));
  pwm.setPWM(2,0,pulseWidth(90));
  delay(1000);
  //Move leg 2 and 4 backward
  pwm.setPWM(5,0,pulseWidth(45));
  pwm.setPWM(1,0,pulseWidth(120));
  pwm.setPWM(5,0,pulseWidth(0));
  pwm.setPWM(1,0,pulseWidth(90));
  pwm.setPWM(7,0,pulseWidth(45));
  pwm.setPWM(3,0,pulseWidth(60));
  pwm.setPWM(7,0,pulseWidth(0));
  pwm.setPWM(3,0,pulseWidth(90));
  delay(1000);
}


  //Set coxa servo positions to zero
  pwm.setPWM(0,0,pulseWidth(0));
  pwm.setPWM(0,0,pulseWidth(0));
  pwm.setPWM(0,0,pulseWidth(0));
  pwm.setPWM(0,0,pulseWidth(0));

}

//For calculating PulseWidth
int pulseWidth(int angle)
{
  int pulse_wide,analog_value;
  pulse_wide =map(angle,0,180,MIN_PULSEWIDTH,MAX_PULSEWIDTH);
  analog_value=int(float(pulse_wide) /1000000*FREQUENCY*4096);
  return analog_value;
}
