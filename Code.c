#include <stdint.h>
#include <Servo.h>

#define FLEX_MIN		384
#define FLEX_MAX		783
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_B6  392
#define NOTE_F3  349


// notes to play, corresponding to the 5 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C5,NOTE_B6, NOTE_F3 
};

// The minimum and maximum turning values of the servo.
#define SERVO_MIN		  0
#define SERVO_MAX		180

// Macro used to get number of elements in an array.
#define LENGTH(arr) 	sizeof(arr)/sizeof(arr[0])

uint8_t glove[5] = {A0, A1, A2, A3, A4}; // Glove input pins.
uint8_t robot[5] = {11, 10,  9,  6,  5}; // Servo output pins (PWM).

// Create 5 servo objects to represent our fingers.
Servo finger[5];

uint8_t pin;	// Which pin we are currently using.
int16_t pos;	// The new position to write to the servo.

void setup() {
  Serial.begin(9600);
   pinMode(8, OUTPUT);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(A2, INPUT);
   pinMode(A3, INPUT);
   pinMode(A4, INPUT);
  
  // Setup our inputs here.
  for (pin = 0; pin < LENGTH(glove); pin++) {
    // Use Arduino's built-in resistor (INPUT_PULLUP).
  	pinMode(glove[pin], INPUT_PULLUP);
  }
  
  // Setup our outputs here.
  for (pin = 0; pin < LENGTH(robot); pin++) {
    finger[pin].attach(robot[pin]);
  }
}

void loop()
{
  // For each input pin on the glove...
  for (pin = 0; pin < LENGTH(glove); pin++)
  {
    // Read the current value of the current finger's flex sensor.
    pos = analogRead(glove[pin]);
    
    // Scale this value according to what a servo can do.
    pos = map(pos, FLEX_MIN, FLEX_MAX, SERVO_MIN, SERVO_MAX);
    
    // Print out how much each finger is moving.
    Serial.print(pos); Serial.print("  ");
    
    // Write the new position of the current finger to the servo.
  	finger[pin].write(pos);                  
  }
    Serial.println(digitalRead(A0));
  Serial.println(digitalRead(A1));
  Serial.println(digitalRead(A2));
  Serial.println(digitalRead(A3));
  Serial.println(digitalRead(A4));
   Serial.println(digitalRead(A5));
   Serial.println(digitalRead(A6));
  if (digitalRead(A0) == 1)
  {
    tone(8,  NOTE_A4 , 100);	// plays note c
  }else if (digitalRead(A1) == 1) {
    tone(8, NOTE_B4, 100);	// plays note d
  }else if (digitalRead(A2) == 1) {
    tone(8, NOTE_C5, 100);	// plays note e 
  }else if (digitalRead(A3) == 1) {
    tone(8, NOTE_B6 , 100);	// plays note f 
  }else if (digitalRead(A4) == 1) {
    tone(8, NOTE_F3, 100);	// plays note g
    delay(100);
  }
}
  
