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
  return 1;
}

char state2_sounds(){
  buzzer_set_period(1000);
  return 1;
}
char state3_drawShape(int c, int r){
  clearScreen(COLOR_BLUE);
  for(int i = 0; i <= 10; i++){
    for(int j = 0;j<= 10-i; j++){
      drawPixel(c+j, r-i, BLACK);
    }
  }
  col++;
  row++;
}

void state_advance(){
  char changed = 0;

  switch(currentState){
  case 1: changed = state1_lights(); break;
  case 2: changed = state2_sounds(); break;
  case 3: changed = WDT(); break;
  default: clearScreen(COLOR_BLUE);
    // case 3: changed = state3_drawShape(col,row); break;
    //case 4: changed = state4_StopStates(); break;
  }
  led_changed = changed;
  led_update();
}