#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcddraw.h"
#include "lcdutils.h"

int col = 20;
int row = 20;

char state1_lights(){
  green_on = 1;
  red_on = 1;
  led_changed = 1;
  led_update();
}

char state2_sounds(){
  playMusic();
  //buzzer_set_period(1000);
}

char state3_drawShape(int c, int r){
  clearScreen(COLOR_BLUE);
  for(int i = 0; i <= 25; i++){
    for(int j = 0;j<= 25-i; j++){
      drawPixel(c+j, r-i, BLACK);
      drawPixel(c-j, r+i, BLACK);
    }
  }
  col += 2;
  row += 2;
  if(col == 100 || row == 100){
    col = 0;
    row = 0;
  }
  state3_drawShape(col, row);
}

void state_advance(){
  char changed = 0;

  switch(currentState){
  case 1: changed = state1_lights(); break;
  case 2: changed = state2_sounds(); break;
  case 3: changed = state3_drawShape(col, row); break;
    //  case 3: changed = WDT(); break;
    //case 4: changed = state4_StopStates(); break;
  default: break;
  }
  led_changed = changed;
  led_update();
}
