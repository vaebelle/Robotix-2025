#include <QTRSensors.h>

//QTR SENSOR PIN ASSIGNMENTS
#define SENSOR1 A0
#define SENSOR2 A1
#define SENSOR3 A2
#define SENSOR4 A3
#define SENSOR5 A4
#define SENSOR6 A5
#define SENSOR7 A6
#define SENSOR8 A7
#define LED_CTRL 6

// sensor values initialization
const uint8_t sensorArray[8] = {SENSOR8, SENSOR7, SENSOR6, SENSOR5, SENSOR4, SENSOR3, SENSOR2, SENSOR1};
uint8_t sensorValActive[8];
uint8_t position;


void setup() {
  Serial.begin(9600);

  for (int i = 0; i <8; i++)
  {
    pinMode(sensorArray[i], INPUT);
  }
  
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A7, A6, A5, A4, A3, A2, A1, A0}, 8);
  pinMode(LED_CTRL, OUTPUT);

}

void loop() {
  position = qtr.readLineBlack(sensorValActive);
  Serial.print(position);
}
