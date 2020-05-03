#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../timerLib/libTimer.h"
#include "lcddraw.h"
#include "lcdutils.h"

int main(){
  configureClocks();
  buzzer_init();
  switch_init();
  led_init();
  lcd_init();
  
  or_sr(0x18);
}
