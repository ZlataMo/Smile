#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

#include <Servo.h>

#define CLOSE_LEFT_EYE 40
#define CLOSE_RIGHT_EYE 0
#define DELTA_EYE 40

Servo eyelidLeft;
Servo eyelidRight;

uint32_t myTimer1 = millis();
uint32_t myTimer2 = millis();
uint32_t myTimer3 = millis();
uint32_t myTimer4 = millis();

int currentPosition = 0;
int currentPositionRight = 0;
int currentPositionLeft = 0;
int desiredPosition = 0;
int desiredPositionRight = 0;
int desiredPositionLeft = 0;

int condition = 1, conditionOld = 0, conditionRec = 0;

void eye()
{
  if (currentPosition > desiredPosition)
    currentPosition -= 1;
  else if (currentPosition < desiredPosition)
    currentPosition += 1;

  eyelidLeft.write(CLOSE_LEFT_EYE - currentPosition);
  eyelidRight.write(CLOSE_RIGHT_EYE + currentPosition);
}

void eyeRight()
{
  if (currentPositionRight > desiredPositionRight)
    currentPositionRight -= 1;
  else if (currentPositionRight < desiredPositionRight)
    currentPositionRight += 1;

  eyelidRight.write(CLOSE_RIGHT_EYE + currentPositionRight);
}
void eyeLeft()
{
  if (currentPositionLeft > desiredPositionLeft)
    currentPositionLeft -= 1;
  else if (currentPositionLeft < desiredPositionLeft)
    currentPositionLeft += 1;

  eyelidLeft.write(CLOSE_LEFT_EYE + currentPositionLeft);
}
void setup()
{
  Serial.begin(9600);         //инициализируем UART USB
  Serial1.begin(9600);        //инициализируем UART связи со светом
  Serial3.begin(9600);        //инициализируем UART связи с плеером
  myDFPlayer.begin(Serial3);  //инициализируем плеер
  myDFPlayer.volume(15);

  eyelidLeft.attach(10);      //инициализируем сервопривод левых век
  eyelidRight.attach(2);     //инициализируем сервопривод правых век

  myTimer3 = millis();        //Обнуляем таймер

  pinMode(13, 1);
}

void loop()
{
  (millis() % 200 > 100) ? digitalWrite(13, 1) : digitalWrite(13, 0); //пример короткой записи if/else
  Serial.print(desiredPositionRight);
  Serial.print(desiredPositionLeft);
  Serial.println();
  if (millis() - myTimer2 > 20)   //плавное движение серв
  {
    myTimer2 = millis();
    eye();
    eyeRight();
    eyeLeft();
  }

  if (Serial1.available() > 0)
  {
    conditionRec = Serial1.read();
  }

  if (condition != conditionRec) {
    delay(100);
    Serial1.write(condition);
    //Serial.println(condition);//отправляем состояние "приветствия" контроллеру управления светом
    conditionOld = condition;
  }

  switch (condition)
  {
    case 1:
      Serial1.write(condition);
      desiredPositionRight = 40;
      desiredPositionLeft = 40;
      //desiredPosition = 40;
      myDFPlayer.play(1);             //привествие
      condition++;
      break;
    case 2:
      if (millis() - myTimer3 > 10000)
        condition++;
      break;
    case 3:
      myDFPlayer.play(2);             //я умею показывать различные эмоции
      condition++;
      break;
    case 4:
      if (millis() - myTimer3 > 14000) {
        condition++;
      }
      break;
    case 5:
      myDFPlayer.play(3);           //радость
      condition++;
      break;
    case 6:
      if (millis() - myTimer3 > 16000) {
        condition++;
      }
      break;
    case 7:
      myDFPlayer.play(4);          //грусть/
      condition++;
      break;
    case 8:
      if (millis() - myTimer3 > 18000) {
        condition++;
      }
      break;
    case 9:
      desiredPositionRight = 70;
      desiredPositionLeft = 70;
      //desiredPosition = 70;
      myDFPlayer.play(5);         //удивление
      condition++;
      break;
    case 10:
      if (millis() - myTimer3 > 20000) {
        condition++;
      }
      break;
    case 11:
      desiredPositionRight = 20;
      desiredPositionLeft = 20;
      //desiredPosition = 20;
      myDFPlayer.play(6);       //злость
      condition++;
      break;
    case 12:
      if (millis() - myTimer3 > 22000) {
        condition++;
      }
      break;
    case 13:
      desiredPositionRight = 40;
      desiredPositionLeft = 40;
      //desiredPosition = 40;
      myDFPlayer.play(7);     //смущение
      condition++;
      break;
    case 14:
      if (millis() - myTimer3 > 25000) {
        condition++;
      }
      break;
    case 15:
      myDFPlayer.play(8);    //нейтральное
      condition++;
      break;
    case 16:
      if (millis() - myTimer3 > 28000) {
        condition++;
      }
      break;
    case 17:
      myDFPlayer.play(9);    //А еще я умею
      condition++;
      break;
    case 18:
      if (millis() - myTimer3 > 31000) {
        condition++;
      }
      break;
    case 19:
      myDFPlayer.play(10);    //шевелить глазами
      condition++;
      break;
    case 20:
      if (millis() - myTimer3 > 34000) {
        condition++;
      }
      break;
    case 21:
      desiredPositionRight = 20;
      desiredPositionLeft = 40;
      myDFPlayer.play(11);    //подмигивать
      condition++;
      break;
    case 22:
      if (millis() - myTimer3 > 36000) {
        condition++;
      }
      break;
    case 23:
      myDFPlayer.play(12);    //имитировать ходьбу
      condition++;
      break;
    case 24:
      if (millis() - myTimer3 > 40000) {
        condition++;
      }
      break;
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
