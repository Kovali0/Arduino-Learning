#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons btn;

void setup() {
  btn.init();
  for (int L = 0; L < 8; L++) {
    pinMode(LEDS[L], OUTPUT);
  }
  unsigned int t=0;
  bool clock_status=true;
}

void show_time(unsigned int t){
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

void clear_time(){
  for (int j = 0; j < 8; j++) {
    digitalWrite(LEDS[j], LOW);
  }
}

bool on_off(bool clock_status){
  return clock_status = !clock_status;
}

unsigned int reset()(
  clear_time();
  return 0;
}

void loop() {
  //Wstrzymanie zegara 1, wznowienie 2, wyzerowanie 3
  if (btn.buttonPressed(8){
    clock_status = on_of(clock_status);
  }else{
    if (btn.buttonPressed(9){
      clock_status = on_of(clock_status);
    }else{
      if (btn.buttonPressed(10){
        t=reset();
      }
    }
  }
  if(clock_status==true){
    t++;
    time_clear();
  }
  show_time(t);
  delay(1000);
}
