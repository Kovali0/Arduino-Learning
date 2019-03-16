#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons btn;

void setup() {
  btn.init();
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
  int number=0;
  digitalWrite(LED8,HIGH);
}

void show( int number){
  int bits[8];
  for (int i = 0; i < 8; i++) {
    bits[i] = (number >> i) & 1;
  }
  for (int j = 0; j < 8; j++) {
    if(bits[j]==1){
      digitalWrite(LEDS[j], HIGH);
    }
  }
}

void clearLEDS(){
  for (int j = 0; j < 8; j++) {
    digitalWrite(LEDS[j], LOW);
  }
}

void loop() {
  if (btn.buttonPressed(3){
    number-=2;
    clearLEDS();
    show(number);
  }else{
    if (btn.buttonPressed(4){
      number+=2;
      clearLEDS();
      show(number);
    }else{
      if (btn.buttonPressed(11){
        number-=1;
        clearLEDS();
        show(number);
      }else{
        if (btn.buttonPressed(13){
          number+=1;
          clearLEDS();
          show(number);
        }
      }
    }
  }
}
