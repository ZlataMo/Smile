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
bool flag_pov1 = true, flag_Sasha = false, flag_pov6 = true, flag_pov2 = true, flag_pov3 = true, flag_pov4 = true, flag_pov_nach = true, flag_pov_nach1 = true;

void setup()
{
  Serial.begin(9600);         //инициализируем UART USB
  Serial1.begin(9600);        //инициализируем UART связи со светом
  Serial2.begin(9600);        //инициализируем UART связи с платформой
  Serial3.begin(9600);        //инициализируем UART связи с плеером
  Serial.print("\tПривет!\n");
  myDFPlayer.begin(Serial3);  //инициализируем плеер
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
  if (millis() - myTimerEyeLeft > 20)   //плавное движение серв
  {
    myTimerEyeLeft = millis();
    if (millis() % 4000 > 2000)
      eyeLeft(40);
    else if (millis() % 4000 > 500)
      eyeLeft(0);
  }

  if (millis() - myTimerEyeRight > 20)   //плавное движение серв
  {
    myTimerEyeRight = millis();
    if (millis() % 4000 > 2000)
      eyeRight(40);
    else if (millis() % 4000 > 500)
      eyeRight(0);
  }

  if (Serial1.available() > 0) {
    /*int startByte = Serial2.read();
      if (startByte == 255)
      {
      while (!Serial2.available());
      condition = Serial2.read();
      Serial1.write(condition);
      Serial.println(condition);
      }  */

    condition = Serial1.read();
    Serial1.write(condition);
    Serial.print("Condition: ");
    Serial.println(condition);

    if (condition == 8) {
      flag_Sasha = true;
    }
    
    switch (condition) {
      //Саша, а что это?
      case 13:
        if (flag_pov_nach) {
          eyeLeft(60);
          eyeRight(60);
          //
          pupilLeft(60);
          pupilRight(60);
          //
          Serial.println("case 13");
          delay(9000);
          myDFPlayer.play(1);     //Не знаю, похоже на робота 30х годов 21го века
          delay(6500);
          timerCond = millis();
          condition++;
          flag_pov_nach = false;
        }
      case 14:
        Serial.println("case 14");
        if (millis() - timerCond > 7000) {  //а давай его включим!
          condition++;
          timerCond = millis();
        }
      case 15:
        if (flag_pov_nach1) {
          eyeLeft(20);
          eyeRight(20);
          //
          pupilLeft(40);
          pupilRight(-40);
          //
          Serial.println("case 15");
          myDFPlayer.play(2);     //Как? Где у него кнопка? Могу ли я включить его с помощью ментального модуля ?
          delay(6000);
          timerCond = millis();
          condition++;
          flag_pov_nach1 = false;
        }
      //break;
      case 16:
        Serial.println("case 16");
        if (millis() - timerCond > 16000) { //Да, тогда была распростанена устаревшая версия Wi-Fi. Сейчас проверю, не появилась ли неизвестная сеть в списке на частоте 5ГГц?
          condition = 2;  //Хм, сеть есть, но мой ментальный модуль принимает только какие-то помехи. Сейчас попробую подключиться
          timerCond = millis();
        }
        break;
      case 2:
        eyeLeft(20);
        eyeRight(20);
        //
        pupilLeft(40);
        pupilRight(-40);
        //
        Serial.println("case 2");
        myDFPlayer.play(3);                 //Видимо, старая прошивка за время простоя как-то повредилась. Давай попробуем обновить ее до актуальной версии
        delay(8000);
        flag_pov3 = false;
        break;
      case 3:
        if (flag_pov4) {
          eyeLeft(60);
          eyeRight(60);
          //
          pupilLeft(40);
          pupilRight(40);
          //
          Serial.println("case 3");
          myDFPlayer.play(4);                 //Ой, все, не хочу этого слушать! Что там надо сказать?
          delay(5000);
          condition++;
          flag_pov4 = false;
        }
      //break;
      case 4:
        Serial.println("case 4");
        if (millis() - timerCond > 5000) {  //Нет! Подожди! Мы же должны заботиться о своих персональных данных
          condition++;
          timerCond = millis();
        }
        break;
      case 5:
        if (flag_pov1) {
          Serial.println("case 5");
          delay(3000);
          myDFPlayer.play(5);                 //Да кому они нужны? Принимаем! ОДИН
          condition = 0;
          delay(5000);
          flag_pov1 = false;
        }
        break;
      case 6:
        Serial.println("case 6");
        if (millis - timerCond > 3000) { //Инициализация робота, Hello World!
          timerCond = millis();
        }
        break;
      case 7:
        if (flag_pov2) {
          Serial.println("case 7");
          myDFPlayer.play(6);               //Ура! Заработало!
          delay(3000);
          flag_pov2 = false;
        }
        break;
      case 8:
        if (flag_pov6) {
          Serial.println("case 8");
          Serial1.write(1);
          myDFPlayer.play(7);                  //А я Саша
          delay(2000);
          flag_pov6 = false;
          
          break;//*/
        }
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
