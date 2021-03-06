#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  P1OUT |= LED_GREEN;
   while(currentState == 3){
     if(++blink_count == 125){
    state3_drawShape(col,row);
    }
   }
   // if(++blink_count == 125){
    state_advance();
    blink_count = 0;
    // }
  P1OUT &= ~LED_GREEN;
}

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}
/*
void wdt_c_handler(){
  static short count = 0;
  P1OUT |= LED_GREEN;
  count ++;
  if(count == 1){
    state3_drawShape(col, row);
    count = 0;
  }
  P1OUT &= ~LED_GREEN;
}
*/
