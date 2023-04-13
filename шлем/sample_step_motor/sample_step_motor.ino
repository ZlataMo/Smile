#include <Stepper.h> // библиотека для шагового двигателя

// количество шагов на 1 оборот, измените значение для вашего мотора
const int stepsPerRevolution = 100;

// устанавливаем порты для подключения драйвера
Stepper myStepper(stepsPerRevolution, 3, 4, 5, 6);

void setup() {
  myStepper.setSpeed(60); // устанавливаем скорость 60 об/мин
}

void loop() {
  // поворачиваем ротор по часовой стрелке
  myStepper.step(stepsPerRevolution);
  delay(500);

  // поворачиваем ротор против часовой стрелки
  myStepper.step(-stepsPerRevolution);
  delay(500);
}