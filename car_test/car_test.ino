#include "ISAMobile.h"

void setup(void)
{
  
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
  
  
  Wire.begin();
}

void loop() {
  delay(1000);

  SetPowerLevel(PowerSideEnum::Left, 100);
  SetPowerLevel(PowerSideEnum::Right, 100);
  delay(2000);

  SetPowerLevel(PowerSideEnum::Left, 0);
  SetPowerLevel(PowerSideEnum::Right, 0);
  delay(2000);

  SetPowerLevel(PowerSideEnum::Left, -100);
  SetPowerLevel(PowerSideEnum::Right, -100);
  delay(2000);

  SetPowerLevel(PowerSideEnum::Left, 0);
  SetPowerLevel(PowerSideEnum::Right, 0);
  delay(10000);

}

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
