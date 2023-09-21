/*
    Библиотека для управления моторами проекта Time
    v 1.5
    Разработчик Хартанен А.В.
*/

#include <Motors.h>

Motors feet = Motors(9, 8, 44); //pinPWM, pinA, pinB, interruptNumber, directionPin
Motors motorA = Motors(10, 23, 22, 0, 31); //pinPWM, pinA, pinB, interruptNumber, directionPin
Motors motorB = Motors(11, 25, 24, 1, 33); //изменены direction pin. Изначально: 50-53
Motors motorC = Motors(12, 27, 26, 2, 35);
Motors motorD = Motors(13, 29, 28, 3, 37);

int tagRec = 8;
bool walking = 0;
uint32_t myTimer1 = millis();
uint32_t myTimer2 = millis();
uint32_t myTimerPlatform = millis();

void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial2.begin(9600);
  digitalWrite(50, 1);
  digitalWrite(51, 1);
  digitalWrite(52, 1);
  digitalWrite(53, 1);
}

void loop()
{
  feet.set(200);
  mecmove(0,90);
  delay(7000);
  motorA.stop();
  motorB.stop();
  motorC.stop();
  motorD.stop();
  feet.set(0);

}
