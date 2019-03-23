#include <ISADefinitions.h>
#include <ISAButtons.h>
#include <ISALedControl.h>
#include <ISALiquidCrystal.h>
#include <ISA7SegmentDisplay.h>
ISAButtons btn;
ISALedControl lc;
ISALiquidCrystal lcd;
ISA7SegmentDisplay scoreboard;
volatile unsigned int ball_direction, ball_vertical, ball_col, ball_row, left_player, lp_score, right_player, rp_score;


void setup() {
  lcd.begin();
  lc.init();
  btn.init();
  scoreboard.init();
  //ball direction is variable with idea -> 1 = ball is going to left side and if 2 = ball is going to right side
  ball_direction=1;
  //ball vertical -> 0 = ball in the same row, 1 = ball is falling, 2 = ball is go up
  ball_vertical=0;
  ball_col=5;
  ball_row=3;
  left_player=3;
  right_player=3;
  //set start position for ball
  lc.setLed(ball_row,ball_col,true);
  //set start position for left player
  lc.setLed(left_player-1,0,true);
  lc.setLed(left_player,0,true);
  lc.setLed(left_player+1,0,true);
  //set start position for right player
  lc.setLed(right_player-1,7,true);
  lc.setLed(right_player,7,true);
  lc.setLed(right_player+1,7,true);
  lcd.clear();
}

void loop() {
  if(checkGoal()==true){
    clearLeftPlayerPosition();
    clearRightPlayerPosition();
    lc.setLed(ball_row,ball_col,false);
    delay(500);
    lcd.clear();
    lcd.print("Next ball");
    delay(500);
    gameReset();
  }
  scoreboard.displayDigit(rp_score,0);
  scoreboard.displayDigit(lp_score,3);
  lcd.clear();
  clearLeftPlayerPosition();
  clearRightPlayerPosition();
  lc.setLed(ball_row,ball_col,false);
  go_ball();
  ball_up();
  lc.setLed(ball_row,ball_col,true);
  int jleft = analogRead(JOY1Y);
  int jright = analogRead(JOY2Y);
  lcd.print("Great Pong");
  if(jleft<470){
    if(left_player<6){
      left_player++;
    }
  }else{
    if(jleft>570){
      if(left_player>1){
        left_player--;
      }
    }
  }
  if(jright<470){
    if(right_player<6){
        right_player++;
      }
  }else{
    if(jright>570){
      if(right_player>1){
        right_player--;
      }
    }
  }
  setRightPlayerPosition();
  setLeftPlayerPosition();
  delay(100);
}

void clearLeftPlayerPosition(){
  lc.setLed(left_player-1,0,false);
  lc.setLed(left_player,0,false);
  lc.setLed(left_player+1,0,false);
}

void clearRightPlayerPosition(){
  lc.setLed(right_player-1,7,false);
  lc.setLed(right_player,7,false);
  lc.setLed(right_player+1,7,false);
}

void setLeftPlayerPosition(){
  lc.setLed(left_player-1,0,true);
  lc.setLed(left_player,0,true);
  lc.setLed(left_player+1,0,true);
}

void setRightPlayerPosition(){
  lc.setLed(right_player-1,7,true);
  lc.setLed(right_player,7,true);
  lc.setLed(right_player+1,7,true);
}

void go_ball(){
  if(ball_direction==1){
    if((ball_row==left_player-1||ball_row==left_player||ball_row==left_player+1)&&ball_col==1){
      ball_collision();
      ball_direction=2;
      ball_col++;
    }else{
      ball_col--;
    }
  }else{
    if(ball_direction==2){
      if((ball_row==right_player-1||ball_row==right_player||ball_row==right_player+1)&&ball_col==6){
        ball_collision();
        ball_direction=1;
        ball_col--;
      }else{
        ball_col++;
      }
    }
  }
}

void ball_up(){
  if(ball_vertical==2){
    if(ball_row==0){
      ball_vertical=1;
      ball_row++;
    }else{
      ball_row--;
    }
  }else{
    if(ball_vertical==1){
      if(ball_row==7){
        ball_vertical=2;
        ball_row--;
      }else{
        ball_row++;
      }
    }
  }
}

void ball_collision(){
  if(ball_direction==1){
    if(ball_row==left_player-1&&ball_col==1){
      ball_vertical=2;
    }else{
      if(ball_row==left_player+1&&ball_col==1){
        ball_vertical=1;
      }else{
        if(ball_row==left_player&&ball_col==1){
          ball_vertical=0;
        }
      }
    }
  }else{
    if(ball_direction==2){
      if(ball_row==right_player-1&&ball_col==6){
        ball_vertical=2;
      }else{
        if(ball_row==right_player+1&&ball_col==6){
          ball_vertical=1;
        }else{
          if(ball_row==right_player&&ball_col==6){
            ball_vertical=0;
          }
        }
      }
    }
  }
}

bool checkGoal(){
  if(ball_col==0){
    rp_score++;
    lcd.clear();
    lcd.print("Goal!");
    if(rp_score==9){
      lcd.clear();
      lcd.print("Right player win!!!");
    }
    return true;
  }
  if(ball_col==7){
    lp_score++;
    lcd.clear();
    lcd.print("Goal!");
    if(lp_score==9){
      lcd.clear();
      lcd.print("Left player win!!!");
    }
    return true;
  }else{
    return false;
  }
}

void gameReset(){
  ball_direction=1;
  ball_vertical=0;
  ball_col=5;
  ball_row=3;
  left_player=3;
  right_player=3;
}

void newGame(){
  gameReset();
  rp_score=0;
  lp_score=0;
  lcd.clear();
  lcd.print("New Game");
  delay(500);
}
