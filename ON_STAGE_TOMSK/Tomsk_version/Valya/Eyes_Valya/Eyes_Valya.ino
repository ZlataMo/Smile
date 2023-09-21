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
  if (millis() - myTimerEyeLeft > 20)   //моргание левого глаза
  {
    myTimerEyeLeft = millis();
    if (millis() % 4000 > 2000)
      eyeLeft(40);
    else if (millis() % 4000 > 500)
      eyeLeft(0);
  }

  if (millis() - myTimerEyeRight > 20)   //моргание правого глаза
  {
    myTimerEyeRight = millis();
    if (millis() % 4000 > 2000)
      eyeRight(40);
    else if (millis() % 4000 > 500)
      eyeRight(0);
  }

  if (millis() - myTimerEyeLeft > 20)   //левый
  {
    myTimerEyeLeft = millis();
    if (millis() % 4000 > 2000)
      eye_not_Left(40);
    else if (millis() % 4000 > 2000)
      eye_not_Left(0);
  }

  if (millis() - myTimerEyeRight > 20)   //правый
  {
    myTimerEyeRight = millis();
    if (millis() % 4000 > 2000)
      eye_not_Right(0);
    else if (millis() % 4000 > 2000)
      eye_not_Right(40);
  }

  if (Serial2.available() > 0) {
    /*int startByte = Serial2.read();
      if (startByte == 255)
      {
      while (!Serial2.available());
      condition = Serial2.read();
      Serial1.write(condition);
      Serial.println(condition);
      }  */
    condition = Serial2.read();
    Serial1.write(condition);
    Serial.println(condition);
    eye2Left.write(0);
    eye2Right.write(0);
    eyepupilLeft.write(20);
    eyepupilRight.write(20);
    switch (condition) {
      case 0:
        eye2Left.write(60);
        eye2Right.write(60);
        eyepupilLeft.write(60);
        eyepupilRight.write(60);
      case 13:
        if (flag_pov_nach) {
          eyeLeft(60);
          eyeRight(60);
          //
          pupilLeft(60);
          pupilRight(60);
          //
          Serial.println("13");
          myDFPlayer.play(1);     //Саша, а что это?
          delay(7000);
          timerCond = millis();
          condition++;
          flag_pov_nach = false;
        }
      case 14:
      /*Serial.println("14");
        if (millis() - timerCond > 5000) {
        condition++;
        }*/
      case 15:
        if (flag_pov_nach1) {
          Serial.println("15");
          myDFPlayer.play(2);     //А давай его включим?
          timerCond = millis();
          condition++;
          flag_pov_nach1 = false;
        }
      //break;
      case 16:
        Serial.println("16");
        if (millis() - timerCond > 2000) {
          condition = 0;
        }
        break;
      case 2:
        if (flag_pov3) {
          eyelidLeft.write(20);
          eyelidRight.write(20);
          //
          eyepupilLeft.write(40);
          eyepupilRight.write(-40);
          //
          Serial.println("case 2");
          myDFPlayer.play(3);                 //Да, тогда была распростанена устаревшая версия Wi-Fi
          delay(9000);
          condition++;
          flag_pov3 = false;
        }
      //break;
      case 3:
        Serial.println("case 3");
        if (millis() - timerCond > 3000) {
          condition++;
        }
      case 4:
        if (flag_pov4) {
          Serial.println("case 4");
          Serial1.write(4);
          myDFPlayer.play(4);                 //Хм, сеть есть, но мой ментальный модуль принимает только какие-то помехи
          delay(8000);
          condition++;
          flag_pov4 = false;
        }
      //break;
      case 5:
        Serial.println("case 5");
        if (millis() - timerCond > 8000) {
          condition = 0;
        }
        condition = 0;
        break;
      case 6:
        if (flag_pov1) {
          eyepupilLeft.write(-60);
          eyepupilRight.write(60);
          Serial.println("case 6");
          myDFPlayer.play(5);                 //Нет! Подожди!
          condition = 0;
          delay(5000);
          flag_pov1 = false;
        }
        break;
      case 7:
        if (flag_pov2) {
          Serial.println("case 7");
          Serial2.write(1);
          myDFPlayer.play(6);               //Привет
          delay(4000);
          condition = 0;
          flag_pov2 = false;
        }
        break;
      default: break;
    }
  }
}

/*
   myDFPlayer.next();  //Play next mp3
   myDFPlayer.previous();  //Play previous mp3
   myDFPlayer.play(1);  //Play the first mp3
   myDFPlayer.loop(1);  //Loop the first mp3
   myDFPlayer.pause();  //pause the mp3
   myDFPlayer.start();  //start the mp3 from the pause
   myDFPlayer.playFolder(15, 4);  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
   myDFPlayer.enableLoopAll(); //loop all mp3 files.
   myDFPlayer.disableLoopAll(); //stop loop all mp3 files.
   myDFPlayer.playMp3Folder(4); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
   myDFPlayer.advertise(3); //advertise specific mp3 in SD:/ADVERT/0003.mp3; File Name(0~65535)
   myDFPlayer.stopAdvertise(); //stop advertise
   myDFPlayer.playLargeFolder(2, 999); //play specific mp3 in SD:/02/004.mp3; Folder Name(1~10); File Name(1~1000)
   myDFPlayer.loopFolder(5); //loop all mp3 files in folder SD:/05.
   myDFPlayer.randomAll(); //Random play all the mp3.
   myDFPlayer.enableLoop(); //enable loop.
   myDFPlayer.disableLoop(); //disable loop.
*/
