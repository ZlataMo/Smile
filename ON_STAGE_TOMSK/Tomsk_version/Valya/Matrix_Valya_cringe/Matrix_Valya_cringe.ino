#include <Adafruit_GFX.h>
#include <FastLED_NeoMatrix.h>
#include <FastLED.h>
#include "colors.h" //цвета 
//подключение массивов картинок
#include "SMILE.h"
#include "dvizh.h"
#include "SAD.h"
#include "angry.h"
#include "default.h"
#include "UDIVLENIE.h"
#include "NEW.h"
#include "POLOSKA.h"
#include "NEVERNO.h"

#define PIN 9 //matrix connection pin 
#define mw 16 // ширина
#define mh 8 // высота
#define NUMMATRIX (mw*mh) //количество светодиодов в матрице

#define DISABLE_WHITE //для заполнения белым при старте - закомментировать, для выключения - разкомментировать

int NEWMATRIX = 14; //количество светодиодов в матрице щек
// Max is 255, 32 is a conservative value to not overload
// a USB power supply (500mA) for 12x12 pixels.
int BRIGHTNESS = 16; //яркость

CRGB leds[NUMMATRIX];
CRGB cheeks[14];
CRGB matrixStrelka[64];

// Define matrix width and height.
FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, mw, mh,
    NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG);

void strelka() {
  ODIN();
  delay(700);
  matrix->show();
  DWA();
  delay(700);
  matrix->show();
  TRI();
  delay(700);
  matrix->show();
  CHETIRE();
  delay(700);
  matrix->show();
  PYAT();
  delay(700);
  matrix->show();
  SHEST();
  delay(700);
  matrix->show();
  SEM();
  delay(700);
  matrix->show();
  VOSEM();
  delay(700);
  matrix->show();
}
void ODIN() {
  matrixStrelka[31] = 0x00F000;
}
void DWA() {
  matrixStrelka[31] = 0x00F000;
  //
  matrixStrelka[30] = 0x00F000;
  matrixStrelka[23] = 0x00F000;
  //
  matrixStrelka[39] = 0x00F000;
}
void TRI() {
  matrixStrelka[31] = 0x00F000;
  matrixStrelka[30] = 0x00F000;
  matrixStrelka[29] = 0x00F000;
  //
  matrixStrelka[23] = 0x00F000;
  matrixStrelka[22] = 0x00F000;
  //
  matrixStrelka[39] = 0x00F000;
  matrixStrelka[38] = 0x00F000;
  //
  matrixStrelka[15] = 0x00F000;
  //
  matrixStrelka[47] = 0x00F000;
}
void CHETIRE() {
  matrixStrelka[31] = 0x00F000;
  matrixStrelka[30] = 0x00F000;
  matrixStrelka[29] = 0x00F000;
  matrixStrelka[28] = 0x00F000;
  //
  matrixStrelka[23] = 0x000000;
  matrixStrelka[22] = 0x00F000;
  matrixStrelka[21] = 0x00F000;
  //
  matrixStrelka[39] = 0x000000;
  matrixStrelka[38] = 0x00F000;
  //
  matrixStrelka[15] = 0x000000;
  matrixStrelka[14] = 0x00F000;
  //
  matrixStrelka[47] = 0x000000;
  matrixStrelka[46] = 0x00F000;
}
void PYAT() {
  matrixStrelka[31] = 0x00F000;
  matrixStrelka[30] = 0x00F000;
  matrixStrelka[29] = 0x00F000;
  matrixStrelka[28] = 0x00F000;
  matrixStrelka[27] = 0x00F000;
  //
  matrixStrelka[22] = 0x000000;
  matrixStrelka[21] = 0x00F000;
  matrixStrelka[20] = 0x00F000;
  //
  matrixStrelka[38] = 0x000000;
  matrixStrelka[37] = 0x00F000;
  matrixStrelka[36] = 0x00F000;
  //
  matrixStrelka[14] = 0x000000;
  matrixStrelka[13] = 0x00F000;
  //
  matrixStrelka[46] = 0x000000;
  matrixStrelka[45] = 0x00F000;
}
void SHEST() {
  matrixStrelka[31] = 0x00F000;
  matrixStrelka[30] = 0x00F000;
  matrixStrelka[29] = 0x00F000;
  matrixStrelka[28] = 0x00F000;
  matrixStrelka[27] = 0x00F000;
  matrixStrelka[26] = 0x00F000;
  //
  matrixStrelka[21] = 0x000000;
  matrixStrelka[20] = 0x00F000;
  matrixStrelka[19] = 0x00F000;
  //
  matrixStrelka[37] = 0x000000;
  matrixStrelka[36] = 0x00F000;
  matrixStrelka[35] = 0x00F000;
  //
  matrixStrelka[13] = 0x000000;
  matrixStrelka[12] = 0x00F000;
  //
  matrixStrelka[45] = 0x000000;
  matrixStrelka[44] = 0x00F000;
}
void SEM() {
  matrixStrelka[31] = 0x00F000;
  matrixStrelka[30] = 0x00F000;
  matrixStrelka[29] = 0x00F000;
  matrixStrelka[28] = 0x00F000;
  matrixStrelka[27] = 0x00F000;
  matrixStrelka[26] = 0x00F000;
  matrixStrelka[25] = 0x00F000;
  //
  matrixStrelka[20] = 0x000000;
  matrixStrelka[19] = 0x00F000;
  matrixStrelka[18] = 0x00F000;
  //
  matrixStrelka[36] = 0x000000;
  matrixStrelka[35] = 0x00F000;
  matrixStrelka[34] = 0x00F000;
  //
  matrixStrelka[12] = 0x000000;
  matrixStrelka[11] = 0x00F000;
  //
  matrixStrelka[44] = 0x000000;
  matrixStrelka[43] = 0x00F000;
}
void VOSEM() {
  matrixStrelka[31] = 0x00F000;
  matrixStrelka[30] = 0x00F000;
  matrixStrelka[29] = 0x00F000;
  matrixStrelka[28] = 0x00F000;
  matrixStrelka[27] = 0x00F000;
  matrixStrelka[26] = 0x00F000;
  matrixStrelka[25] = 0x00F000;
  matrixStrelka[24] = 0x00F000;
  //
  matrixStrelka[19] = 0x000000;
  matrixStrelka[18] = 0x00F000;
  matrixStrelka[17] = 0x00F000;
  //
  matrixStrelka[35] = 0x000000;
  matrixStrelka[34] = 0x00F000;
  matrixStrelka[33] = 0x00F000;
  //
  matrixStrelka[11] = 0x000000;
  matrixStrelka[10] = 0x00F000;
  //
  matrixStrelka[43] = 0x000000;
  matrixStrelka[42] = 0x00F000;
}
void OCHISTKA() {
  for (int i = 0; i < 64; i++) {
    matrixStrelka[i] = 0x000000;
  }
  delay(700);
  matrix->show();
}

void setup() {
  // Time for serial port to work?
  delay(1000);
  Serial.begin(9600);
  Serial.print("Init on pin: ");
  Serial.println(PIN);
  Serial.print("Matrix Size: ");
  Serial.print(mw);
  Serial.print(" ");
  Serial.print(mh);
  Serial.print(" ");
  Serial.println(NUMMATRIX);

  Serial1.begin(9600);


  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUMMATRIX  ).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 8>(cheeks, 14 ).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<NEOPIXEL, 10>(matrixStrelka, 64).setCorrection(TypicalLEDStrip);

  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(30);
  Serial.println("If the code crashes here, decrease the brightness or turn off the all white display below");
  // Test full bright of all LEDs. If brightness is too high
  // for your current limit (i.e. USB), decrease it.
  //#define DISABLE_WHITE
#ifndef DISABLE_WHITE
  matrix->fillScreen(LED_WHITE_HIGH);
  matrix->show();
  delay(100);
  matrix->clear();
#endif
}

int condition = 0;
uint32_t myTimer = millis();
int rep = 2, COND = 0;
bool flag_nach = true, flag_pov0 = true, tag_flag1 = true, tag_flag2 = true, tag_flag3 = true, tag_flag0 = true, tag_flag4 = true, tag_flag5 = true;

void loop() {
  // clear the screen after X bitmaps have been displayed and we
  // loop back to the top left corner
  // 8x8 => 1, 16x8 => 2, 17x9 => 6
  static uint8_t pixmap_count = ((mw + 7) / 8) * ((mh + 7) / 8);

  //int bmx = 0, bmy = 0;
  //matrix->fillRect(bmx, bmy, bmx + 16, bmy + 8, LED_BLACK); //очистка матрицы
  //matrix->drawBitmap();
  /*!
    @brief   Draw a PROGMEM-resident 16-bit image (RGB 5/6/5) at the specified
    (x,y) position. For 16-bit display devices; no color reduction performed.
    @param    x   Top left corner x coordinate
    @param    y   Top left corner y coordinate
    @param    bitmap  byte array with 16-bit color bitmap
    @param    w   Width of bitmap in pixels
    @param    h   Height of bitmap in pixels
  */
  //drawRGBBitmap(x координата верхнего левого угла,y координата верхнего левого угла, bitmap byte массив 16бит цветной, ширина в пикселях, высота в пикселях)

  if (flag_nach) { //начальное состояние. Удивление+шевеление ротиком
    matrix->drawRGBBitmap(0, 0, (const uint16_t *) surprised, 16, 8); matrix->show();
    delay(6100);
    Serial.println("1");
    while (rep--) {
      matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
      delay(400);
      matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8); matrix->show();
      delay(400);
    }
    rep = 2;
    matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
    delay(5000);
    Serial.println("2");
    while (rep--) {
      matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
      delay(400);
      matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8); matrix->show();
      delay(400);
    }
    flag_nach = false;
  }

  if (Serial1.available() > 0)
  {
    condition = Serial1.read();
    Serial.println(condition);
    switch (condition)
    {
      case 0:
        /*while (true) {
          Serial.println("Финал"); //щечки зеленым, ротик в стремную улыбку
          matrix->drawRGBBitmap(0, 0, (const uint16_t *) angry, 16, 8); matrix->show();
          /*cheeks[0] = 0x709060;
            for ( int i = 1; i < 15; i++)
            {
            cheeks[i-1] = 0x000000;
            cheeks[i] = 0x309050;
            delay(700);
            matrix->show();
            }
          for ( int i = 0; i < 15; i++)
          {
            cheeks[i] = 0x789345;
            matrix->show();
          }
          delay(900);
          for ( int i = 0; i < 15; i++)
          {
            cheeks[i] = 0x000000;
            matrix->show();
          }
          delay(900);
          }*/
        break;
      case 13:
        Serial.println("case 13");
        break;
      case 15:
        if (tag_flag0) {
          Serial.println("case 15");
          rep = 7;
          while (rep--) {
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
            delay(400);
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8); matrix->show();
            delay(400);
          }
          tag_flag0 = false;
        }
        break;
      case 2:
        if (tag_flag1) {
          Serial.println("case 2");
          matrix->drawRGBBitmap(0, 0, (const uint16_t *) POLOSKA, 16, 8); matrix->show();
          strelka();
          OCHISTKA();
          tag_flag1 = false;
        }
        break;
      case 3:
        if (tag_flag2) {
          Serial.println("case 3");
          rep = 6;
          while (rep--) {
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
            delay(400);
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8); matrix->show();
            delay(400);
          }
          tag_flag2 = false;
        }
        break;
      case 5:
        if (tag_flag3) {
          Serial.println("case 5");
          rep = 6;
          while (rep--) {
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
            delay(400);
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8); matrix->show();
            delay(400);
          }
          tag_flag3 = false;

        }
        break;
      case 7:
        if (tag_flag4) {
          Serial.println("case 7");
          rep = 4;
          while (rep--) {
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
            delay(400);
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8); matrix->show();
            delay(400);
          }
          tag_flag4 = false;
        }
        break;
      case 8:
        if (tag_flag5) {
          Serial.println("case 8");
          rep = 3;
          while (rep--) {
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8); matrix->show();
            delay(400);
            matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8); matrix->show();
            delay(400);
          }
          tag_flag5 = false;
        }
        break;
      case 34:
        for ( int i = 0; i < 64; i = i + 1)
        {
          if ( (millis() - myTimer) % 2000 < 1000)
          {
            if ((i == 1 || i == 2 || i == 3 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 33 || i == 34 || i == 35 || i == 36 || i == 37 || i == 38 || i == 40 || i == 41 || i == 42 || i == 43 || i == 44 || i == 45 || i == 48 || i == 49 || i == 50 || i == 51 || i == 52 || i == 57 || i == 58 || i == 59) ) {
              matrixStrelka[i] = 0x400000;

            }
            //myTimer = millis();
          }
          else {
            if ((i == 1 || i == 2 || i == 3 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 33 || i == 34 || i == 35 || i == 36 || i == 37 || i == 38 || i == 40 || i == 41 || i == 42 || i == 43 || i == 44 || i == 45 || i == 48 || i == 49 || i == 50 || i == 51 || i == 52 || i == 57 || i == 58 || i == 59) ) {
              matrixStrelka[i] = 0x100000;
            }

          }
        }
      default: break;
    }
  }
}

/*void traffic()
  {
  if (millis() - myTimer1 > 500)
  {
    myTimer1 = millis();
    matrix->drawRGBBitmap(0, 0, (const uint16_t *) default_bitmap, 16, 8);
    matrix->show();
  }
  if (millis() - myTimer1 > 1000)
  {
    myTimer1 = millis();
    matrix->drawRGBBitmap(0, 0, (const uint16_t *) dvizh, 16, 8);
    matrix->show();
  }

  }*/
