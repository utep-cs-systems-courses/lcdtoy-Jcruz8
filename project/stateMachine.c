#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcddraw.h"
#include "lcdutils.h"

int col = 20;
int row = 20;

char state1_square(){
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      drawPixel(50+i, 50+j, WHITE);
    }
  }
}

char state2_sounds(){
  playMusic();
  //buzzer_set_period(1000);
}

char state3_drawShape(int c, int r){
  clearScreen(COLOR_BLUE);
  for(int i = 0; i <= 25; i++){
    for(int j = 0;j <= 25-i; j++){
      drawPixel(c+j, r-i, BLACK);
      drawPixel(c-j, r+i, BLACK);
    }
  }
  /*
  for(int f = 0; f <= 25; f++){
    for(int k = 0; k <= 25-f; k++){
  drawPixel(c+k, r-f, COLOR_BLUE);
  drawPixel(c-k, r+f, COLOR_BLUE);
    }
  }
  */
  col += 2;
  row += 2;
  if(col == 100 || row == 100){
    col = 0;
    row = 0;
  }
  state3_drawShape(col, row);
}

//char state4_clear(){
//  clearScreen(COLOR_BLACK);
//}

void state_advance(){
  char changed = 0;

  switch(currentState){
  case 1: changed = state1_square(); break;
  case 2: changed = state2_sounds(); break;
  case 3: changed = state3_drawShape(col, row); break;
    //  case 3: changed = WDT(); break;
  case 4: clearScreen(COLOR_BLACK); break;
  default: break;
  }
  led_changed = changed;
  led_update();
}
