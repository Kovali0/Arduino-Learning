#include <ISADefinitions.h>
#include <DueTimer.h>

void setup(){
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
}
void loop(){
  for(int i=0; i<8; i++){
    digitalWrite(LEDS[i],HIGH);
    digitalWrite(LEDS[i-1],LOW);
    delay(250);
  }
  for(int j=7; j>=0; j--){
    digitalWrite(LEDS[j-1],HIGH);
    digitalWrite(LEDS[j],LOW);
    delay(250);
  }
}
