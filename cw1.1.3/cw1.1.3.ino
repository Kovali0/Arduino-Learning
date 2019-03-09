#include <ISADefinitions.h>
void setup(){
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
  char c = 24;
  show(c);
}
void loop(){
}

void show(unsigned char c){
  int bits[8];
  for (int i = 0; i < 8; i++) {
    bits[i] = (c >> i) & 1;
  }
  for (int j = 0; j < 8; j++) {
    if(bits[j]==1){
      digitalWrite(LEDS[j], HIGH);
    }
  }
}
