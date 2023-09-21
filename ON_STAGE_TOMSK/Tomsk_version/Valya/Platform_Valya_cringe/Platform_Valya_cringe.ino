#include <Motors.h>
#define speedM 70
#define melissa millis()

Motors feet = Motors(9, 8, 44); //pinPWM, pinA, pinB, interruptNumber, directionPin(!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
Motors motorA = Motors(10, 23, 22, 0, 31); //pinPWM, pinA, pinB, interruptNumber, directionPin
Motors motorB = Motors(11, 25, 24, 1, 33);
Motors motorC = Motors(12, 27, 26, 2, 35);
Motors motorD = Motors(13, 29, 28, 3, 37);

int tagRec = -1, condition = -1;
bool walking = 0;
bool tag_flag = true,tag_ooo = true, flag = true, flag_nachalo = true;
uint32_t myTimer2 = millis();
uint32_t myTimerPlatform = millis();
uint32_t myTimer = millis(), timerVel = millis(), Timer_dvizh = millis(), timerCond = millis();
int8_t angle[4] = {0, 90, 180, 270};

float K_PROP = 2;

int16_t Aspeed;
int16_t Bspeed;
int16_t Cspeed;
int16_t Dspeed;

void mecmove(float des_angle, float des_vel)

{
  static float des_angle_old = 0;

  if (des_angle_old != des_angle)
  {
    nMotorEncoder[0] = nMotorEncoder[1] = nMotorEncoder[2] = nMotorEncoder[3] = 0;
    timerVel = millis();
    des_angle_old = des_angle;
  }

  float rad_des_angle = radians(des_angle);                         //deg to rad convertion

  Bspeed =  des_vel * sin(rad_des_angle + M_PI_4);    //calculation of voltage multiplier for each mecanum wheel
  Aspeed = des_vel * cos(rad_des_angle + M_PI_4);
  Dspeed = des_vel * cos(rad_des_angle + M_PI_4);
  Cspeed = des_vel * sin(rad_des_angle + M_PI_4);

  motorA.set( -1 * Aspeed );
  motorB.set(Bspeed );
  motorC.set(-1 * Cspeed );
  motorD.set( Dspeed );
}//едет прaвильно прямо!!!
/*
      A___0___B
      |       |
    90|       |270
      |_______|
      C  180  D
  /*/
void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial2.begin(9600);
  digitalWrite(50, 1);
  digitalWrite(51, 1);
  digitalWrite(52, 1);
  digitalWrite(53, 1);
  nMotorEncoder[0] = nMotorEncoder[1] = nMotorEncoder[2] = nMotorEncoder[3] = 0;
  Timer_dvizh = millis();
  timerCond = millis();

  if (flag_nachalo) {
    Serial.println(13);
    while ( melissa % 20000 < 7000) {
      feet.set(400);
      mecmove(350, 120);
    }
    feet.stop();
    motorA.set(0);
    motorB.set(0);
    motorC.set(0);
    motorD.set(0);
    Serial2.write(13);                       //начало, подъезжаем к роботу
    flag_nachalo = false;
    Serial3.write(1);
  }
}

void loop()
{
  int tag = 9;
  if (Serial3.available() > 0)
  {
    tag = Serial3.read();
    delay(100);
    Serial.println(tag);
    if (tag == Serial3.read()) {
      if (tag == 0) {
        Serial.print("Движение за тегом ");
        //Serial.println(condition);
        condition = 1;
      }
      else if (tag == 1) {
        Serial.print("Первое: движение туда-сюда ");
        Serial.println(condition);
        //flag = true;
        condition = 2;
      }
      else if ( tag == 2) {
        Serial.print("Второе: передача данных");
        Serial.println(condition);
        //flag = true;
        condition = 3;
      }
      else if (tag == 3) {
        Serial.print("Третье: передача данных");
        Serial.println(condition);
        condition = 4;
      }
      else if (tag == 6) {
        condition = 5;
      }
    }
    //Serial.println(condition);
    //Serial2.write(255);
    switch (condition)
    {
      case 1:
        Serial.println("case 1");
        Serial2.write(0);
        while (true) {
          if (Serial3.available() > 0)                        //движение за тегом
          {
            int8_t tag_dvizh = Serial3.read();
            if (tag_dvizh > -2 && tag_dvizh < 3) {
              Serial.println(tag_dvizh);
              if (tag_dvizh == 0) {
                while (tag_dvizh == 0) {
                  feet.set(400);
                  tag_dvizh = Serial3.read();
                  motorA.set(-speedM);
                  motorB.set(speedM);
                  motorC.set(-speedM);
                  motorD.set(speedM);
                }
              }
              else if (tag_dvizh == 1) {
                while (tag_dvizh == 1) {
                  feet.set(400);
                  tag_dvizh = Serial3.read();
                  motorA.set(speedM);
                  motorB.set(speedM);
                  motorC.set(speedM);
                  motorD.set(speedM);
                }
              }
              else if (tag_dvizh == -1) {
                while (tag_dvizh == -1) {
                  feet.set(400);
                  tag_dvizh = Serial3.read();
                  motorA.set(-speedM);
                  motorB.set(-speedM);
                  motorC.set(-speedM);
                  motorD.set(-speedM);
                }
              }
              else if (tag_dvizh == 2) {
                delay(50);
                tag_dvizh = Serial3.read();
                while (tag_dvizh == 2) {
                  tag_dvizh = Serial3.read();
                  feet.stop();
                  motorA.set(0);
                  motorB.set(0);
                  motorC.set(0);
                  motorD.set(0);
                }
              }
            }
          }
        }
        break;//*/
      case 2:
        Serial.println("case 2");
        Serial2.write(condition);                     //первый жест, двигаемся туда-сюда
        if (flag) {
          Serial3.write(2);
          feet.set(400);
          mecmove(90, 60);
          delay(3000);
          mecmove(270, 60);
          delay(3000);
        }
        flag = false;
        feet.stop();
        motorA.set(0);
        motorB.set(0);
        motorC.set(0);
        motorD.set(0);
        Serial3.write(3);
        break;
      case 3:
        Serial.println("case 3");
        Serial2.write(6);                     //передаем значение на голос
        break;
      case 4:
        Serial.println("case 4");
        Serial2.write(7);                     //передаем значение на голос
        if (Serial2.available()) {
          if (Serial2.read() == 1) {
            mecmove(0, 90);
            delay(1000);
            motorA.stop();
            motorB.stop();
            motorC.stop();
            motorD.stop();
          }
        }
        break;
      case 5:
        if (tag_ooo) {
          Serial2.write(34);
          feet.set(400);
          mecmove(90, 70);
          delay(3000);
          mecmove(270, 70);
          delay(3000);
          mecmove(180, 70);
          delay(3000);
          mecmove(0, 70);
          delay(3000);
          motorA.set(70);
          motorB.set(70);
          motorC.set(70);
          motorD.set(70);
          delay(2000);
          motorA.stop();
          motorB.stop();
          motorC.stop();
          motorD.stop();
          feet.stop();
          tag_ooo = false;
        }
        else{
          condition = 0;
        }
      default: break;

    }
  }
}
