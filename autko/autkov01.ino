#include "ISAMobile.h"

QMC5883 qmc; 
float ang, angChange;
char buffer[64];

void SetPowerLevel(PowerSideEnum side, int level)
{
  level = constrain(level, -255, 255);
  
  if (side == PowerSideEnum::Right) {
    if (level > 0) {
      // do przodu
      digitalWrite(A_PHASE, 1);
      analogWrite(A_ENABLE, level);
    } else if (level < 0) {
      // do tyłu
      digitalWrite(A_PHASE, 0);
      analogWrite(A_ENABLE, -level);
    } else {
      // stop
      digitalWrite(A_PHASE, 0);
      analogWrite(A_ENABLE, 0);
    }
  }
  
  if (side == PowerSideEnum::Left) {
    if (level > 0) {
      // do przodu
      digitalWrite(B_PHASE, 1);
      analogWrite(B_ENABLE, level);
    } else if (level < 0) {
      // do tyłu
      digitalWrite(B_PHASE, 0);
      analogWrite(B_ENABLE, -level);
    } else {
      // stop
      digitalWrite(B_PHASE, 0);
      analogWrite(B_ENABLE, 0);
    }
  } 
}


void setup(void)
{ 
  // Czujniki ultradźwiekowe
  for (int i = (int)UltraSoundSensor::__first; i <= (int)UltraSoundSensor::__last; i++)
  {
    pinMode(ultrasound_trigger_pin[i], OUTPUT);
    pinMode(ultrasound_echo_pin[i], INPUT);
    
    digitalWrite(ultrasound_trigger_pin[i], 0);
  }
  
  // Silniki
  pinMode(A_PHASE, OUTPUT);
  pinMode(A_ENABLE, OUTPUT);
  pinMode(B_PHASE, OUTPUT);
  pinMode(B_ENABLE, OUTPUT);
  
  //pinMode(MODE, OUTPUT); -- podłaczone na krótko ze stanem wysokim
  //digitalWrite(MODE, true);  -- podłaczone na krótko ze stanem wysokim
  
  SetPowerLevel(PowerSideEnum::Left, 0);
  SetPowerLevel(PowerSideEnum::Right, 0);

  // Wejścia enkoderowe
  pinMode(ENCODER_LEFT, INPUT);
  pinMode(ENCODER_RIGHT, INPUT);
  
  Serial.begin(9600);
  
  Wire.begin();
  qmc.init();
  qmc.reset();
}

float getAngle(){
  qmc.measure();
  float value = atan2(qmc.getY(), qmc.getX())*180/3.14159;
  if(value < 0) {
    value += 360;
  }
  return value;
}

void printDataInSerialConsole(){
  char buffer[64];

  while (Serial.available() == 0)
  {
    sprintf(buffer, "\nX=%d Y=%d Z=%d A=%f", qmc.getX(), qmc.getY(), qmc.getZ(), getAngle());
    Serial.print(buffer);
    delay(500);
  }
}

void loop(void){
  SetPowerLevel(PowerSideEnum::Left, 120);
  SetPowerLevel(PowerSideEnum::Right, 120);

  delay(1500);
  
  ang = getAngle(); //90
  do{
    SetPowerLevel(PowerSideEnum::Left, -160);
    SetPowerLevel(PowerSideEnum::Right, 160);
    angChange = getAngle();
    sprintf(buffer, "\n%f:%f:%f", ang, angChange, abs(ang - angChange));
    Serial.print(buffer);
    delay(50);
  }while(abs(ang - angChange) < 90);
  
  //printDataInSerialConsole();
}
