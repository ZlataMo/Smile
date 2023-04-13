#include <Servo.h>

#define EAR_L 3
#define EAR_R 5

Servo earL;  // create servo object to control a servo
Servo earR;

int pinD0 = 36;  // Пин к которому подключен D0
int motionDetected = 0;
int sensorVal = 0;
int naprav = 1;

void setup() {
  Serial.begin(9600);
  earL.attach(EAR_L);  // attaches the servo on pin 9 to the servo object
  earR.attach(EAR_R);
  earL.write(30);  // tell servo to go to position in variable 'pos'
        earR.write(170);
  pinMode(pinD0, INPUT);  // Установим вывод A1 как вход
}

void loop() {
  motionDetected = digitalRead(pinD0);  // Считываем показания
  if (motionDetected) {
    naprav *= -1;
    if (naprav > 0) {
      for (int i = 90; i < 120; i++) {
        earL.write(-i);  // tell servo to go to position in variable 'pos'
        earR.write(i);
        delay(5);
      }
    } else {
      for (int i = 90; i > -120; i--) {
        earL.write(-i);  // tell servo to go to position in variable 'pos'
        earR.write(i);
        delay(5);
      }
    }
  }
}