// Line Sensor Array
#define SENSOR8 A7
#define SENSOR7 A6
#define SENSOR6 A5
#define SENSOR5 A4
#define SENSOR4 A3
#define SENSOR3 A2
#define SENSOR2 A1
#define SENSOR1 A0

//#define LED_CTRL 6

void setup() {
  Serial.begin(9600);
  
  pinMode(SENSOR8, INPUT);
  pinMode(SENSOR7, INPUT);
  pinMode(SENSOR6, INPUT);
  pinMode(SENSOR5, INPUT);
  pinMode(SENSOR4, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR1, INPUT);
}

void loop() {
  int val_8 = analogRead(SENSOR8);  
  int val_7 = analogRead(SENSOR7);          
  int val_6 = analogRead(SENSOR6);      
  int val_5 = analogRead(SENSOR5);       
  int val_4 = analogRead(SENSOR4);         
  int val_3 = analogRead(SENSOR3);      
  int val_2 = analogRead(SENSOR2);       
  int val_1 = analogRead(SENSOR1);

  Serial.print("\t");
  Serial.print("8: ");
  Serial.print(val_8);
  Serial.print("\t");
  Serial.print("7: ");
  Serial.print(val_7);
  Serial.print("\t");
  Serial.print("6: ");
  Serial.print(val_6);
  Serial.print("\t");
  Serial.print("5: ");
  Serial.print(val_5);
  Serial.print("\t");
  Serial.print("4: ");
  Serial.print(val_4);
  Serial.print("\t");
  Serial.print("3: ");
  Serial.print(val_3);
  Serial.print("\t");
  Serial.print("2: ");
  Serial.print(val_2);
  Serial.print("\t");
  Serial.print("1: ");
  Serial.print(val_1);

  Serial.println();
}
