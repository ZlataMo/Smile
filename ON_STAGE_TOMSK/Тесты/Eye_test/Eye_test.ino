#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

#include <Servo.h>

#define CLOSE_LEFT_EYE 60
#define CLOSE_RIGHT_EYE 0

#define CLOSE_LEFT_PUPIL 40
#define CLOSE_RIGHT_PUPIL 40


#define CLOSE_LEFT_EYE2 0
#define CLOSE_RIGHT_EYE2 70

#define DELTA_EYE 60

Servo eyelidLeft;
Servo eyelidRight;

Servo eyepupilLeft;
Servo eyepupilRight;

Servo eye2Left;
Servo eye2Right;

uint32_t   myTimerEyeLeft = millis();        //Обнуляем таймер
uint32_t   myTimerEyeRight = millis();
uint32_t   myTimerPupilLeft = millis();
uint32_t   myTimerPupilRight = millis();
uint32_t   timerCond = millis();

int condition = -1, conditionRec = -1;
int tagReal = 0, tagShowed = 0;
bool flag_pov1 = true, flag_pov2 = true, flag_pov3 = true, flag_pov4 = true, flag_pov_nach = true, flag_pov_nach1 = true;

void setup()
{
  Serial.begin(9600);         //инициализируем UART USB
  Serial1.begin(9600);        //инициализируем UART связи со светом
  Serial2.begin(9600);        //инициализируем UART связи с платформой
  Serial3.begin(9600);        //инициализируем UART связи с плеером
  Serial.print("\tПривет!\n");
  myDFPlayer.begin(Serial1);  //инициализируем плеер
  myDFPlayer.volume(30);      //от 10 до 30

  eyelidLeft.attach(12);      //инициализируем сервопривод левых век 12
  eyelidRight.attach(11);     //инициализируем сервопривод правых век 11

  eyepupilLeft.attach(10);      //инициализируем сервопривод левой брови 10
  eyepupilRight.attach(9);     //инициализируем сервопривод правой брови 9

  eye2Left.attach(8);      //инициализируем сервопривод левого зрачка 8
  eye2Right.attach(7);     //инициализируем сервопривод правого зрачка 7

  myTimerEyeLeft = millis();  //Обнуляем таймер
  myTimerEyeRight = millis();
  myTimerPupilLeft = millis();
  myTimerPupilRight = millis();
  timerCond = millis();     //Обнуляем таймер

  pupilLeft(40);
  pupilRight(0);

  eye_not_Left(0);
  eye_not_Right(0);

  pinMode(13, 1);
}

void eyeLeft(int desiredPosition)
{
  static int currentPosition = 0;

  if (currentPosition > desiredPosition)
    currentPosition -= 1;
  else if (currentPosition < desiredPosition)
    currentPosition += 1;

  eyelidLeft.write(CLOSE_LEFT_EYE - currentPosition);
}

void eyeRight(int desiredPosition)
{
  static int currentPosition = 0;

  if (currentPosition > desiredPosition)
    currentPosition -= 1;
  else if (currentPosition < desiredPosition)
    currentPosition += 1;

  eyelidRight.write(CLOSE_RIGHT_EYE + currentPosition);
}
//
void pupilLeft(int desiredPosition)
{
  static int currentPosition = 0;

  if (currentPosition > desiredPosition)
    currentPosition -= 1;
  else if (currentPosition < desiredPosition)
    currentPosition += 1;

  eyepupilLeft.write(CLOSE_LEFT_PUPIL - currentPosition);
}
void pupilRight(int desiredPosition)
{
  static int currentPosition = 0;

  if (currentPosition > desiredPosition)
    currentPosition -= 1;
  else if (currentPosition < desiredPosition)
    currentPosition += 1;

  eyepupilRight.write(CLOSE_RIGHT_PUPIL - currentPosition);
}
//
void eye_not_Right(int desiredPosition)
{
  static int currentPosition = 0;

  if (currentPosition > desiredPosition)
    currentPosition -= 1;
  else if (currentPosition < desiredPosition)
    currentPosition += 1;

  eye2Right.write(CLOSE_RIGHT_EYE2 - currentPosition);
}

void eye_not_Left(int desiredPosition)
{
  static int currentPosition = 0;

  if (currentPosition > desiredPosition)
    currentPosition -= 1;
  else if (currentPosition < desiredPosition)
    currentPosition += 1;

  eye2Left.write(CLOSE_LEFT_EYE2 - currentPosition);
}
//

void loop()
{
  myDFPlayer.play(1);     //Не знаю, похоже на робота 30х годов 21го века
  delay(6500);

}
