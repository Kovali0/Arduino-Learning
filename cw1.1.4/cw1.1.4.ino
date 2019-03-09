#include <ISADefinitions.h>
char t = 0;

void setup(){
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
}

void loop(){
  delay(1000);
  clear_time();
  t++;
  time_now(t);
}

void clear_time(){
  for (int j = 0; j < 8; j++) {
    digitalWrite(LEDS[j], LOW);
  }
}

void time_now(unsigned char t){
  int bits[8];
  for (int i = 0; i < 8; i++) {
    bits[i] = (t >> i) & 1;
  }
  for (int j = 0; j < 8; j++) {
    if(bits[j]==1){
      digitalWrite(LEDS[j], HIGH);
    }
  }
}
