#include <QTRSensors.h>
#include <SparkFun_TB6612.h>

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

//  PINS ASSIGNMENT
#define AIN1 8
#define AIN2 7
#define BIN1 9
#define BIN2 10
#define PWMA 3
#define PWMB 11

// motor
Motor rMotor = Motor (PWMA, AIN1, AIN2);
Motor lMotor = Motor (PWMB, BIN1, BIN2);


// PID values initialization
float kp = 0.305;
float ki = 0.00006;
float kd = 5

// sensor values initialization
const uint8_t sensorArray[8] = {SENSOR8, SENSOR7, SENSOR6, SENSOR5, SENSOR4, SENSOR3, SENSOR2, SENSOR1};
uint8_t sensorValActive[8];
uint8_t position;

//PID threshold values
int P, D, I, previousError, PIDValue, error, lsp, rsp, centerPosition, tempPosition;
centerPosition = 3500;

//Speed threshold values
int minSpeed, maxSpeed, baseSpeed; //255 full pwm range
minSpeed = -225;
maxSpeed = 255;
baseSpeed = 255;


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
  readSensorsActive(sensorValActive);
  
  /*
  NOTE:
  Sensor8 - left most  | sharp left
  Sensor7 -            | stronger than soft
  Sensor6 -            | soft left to the left
  Sensor5 - center     | center
  Sensor4 - center     | center
  Sensor3 -            | soft curve to the right
  Sensor2 -            | stronger than soft   
  Sensor1 - right most  | sharp right
  */

  //main pid calculations:
  // error = centerPosition - position;

  // P = error;
  // I = constrain(I + error, minSpeed, maxSpeed);
  // D = error - previousError;
  // previousError = error;

  // int motorSpeed = (Kp * P) + (Ki * I) + (Kd * D);

  // int lsp = constrain(baseSpeed + motorSpeed, minSpeed, maxSpeed);
  // int rsp = constrain(baseSpeed - motorSpeed, minSpeed, maxSpeed);

  // lmotor.drive(lsp);
  // rmotor.drive(rsp);

  void robot_control()
{
  position = qtr.readLineBlack(sensorValActive);

  if (position >= 3400)
  {
    motor1.drive(minSpeed);
    motor2.drive(maxSpeed);
  }
  else if (position <= 600)
  {
    motor1.drive(maxSpeed);
    motor2.drive(minSpeed);
  }
  else
  {
    error = centerPosition - position;

    P = error;
    I = constrain(I + error, minSpeed, maxSpeed);
    D = error - previousError;
    previousError = error;

    int motorSpeed = (Kp * P) + (Ki * I) + (Kd * D);

    int lsp = constrain(baseSpeed + motorSpeed, minSpeed, maxSpeed);
    int rsp = constrain(baseSpeed - motorSpeed, minSpeed, maxSpeed);

    motor1.drive(lsp);
    motor2.drive(rsp);
  }
}
}

void readSensorsActive (uint8_t* sensorValActive)
{
  digitalWrite(LED_CTRL, HIGH);
  delay(5);

  for (int i=0; i<8; i++)
  {
    sensorValActive[i] = analogRead(sensorArray[i]);
  }

  digitalWrite(LED_CTRL, LOW);
}

// void displayReadings (uint8_t* sensorReadings) {
//   uint8_t val_8 = sensorReadings[0];  
//   uint8_t val_7 = sensorReadings[1];          
//   uint8_t val_6 = sensorReadings[2];    
//   uint8_t val_5 = sensorReadings[3];       
//   uint8_t val_4 = sensorReadings[4];         
//   uint8_t val_3 = sensorReadings[5];      
//   uint8_t val_2 = sensorReadings[6];       
//   uint8_t val_1 = sensorReadings[7];

//   Serial.print("\t");
//   Serial.print("8: ");
//   Serial.print(val_8);
//   Serial.print("\t");
//   Serial.print("7: ");
//   Serial.print(val_7);
//   Serial.print("\t");
//   Serial.print("6: ");
//   Serial.print(val_6);
//   Serial.print("\t");
//   Serial.print("5: ");
//   Serial.print(val_5);
//   Serial.print("\t");
//   Serial.print("4: ");
//   Serial.print(val_4);
//   Serial.print("\t");
//   Serial.print("3: ");
//   Serial.print(val_3);
//   Serial.print("\t");
//   Serial.print("2: ");
//   Serial.print(val_2);
//   Serial.print("\t");
//   Serial.print("1: ");
//   Serial.print(val_1);

//   Serial.println();
// }