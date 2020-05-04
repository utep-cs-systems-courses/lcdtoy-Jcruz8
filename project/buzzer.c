#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"

#define c 995
#define g 704
#define f 372
#define d 221


void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >>1;
}

int music[10] = {c,c,g,g,f,f,d,d,c,c};

void playMusic(){
  timerAUpmode();
  for(int i = 0; i < 10; i++){
    buzzer_set_period(music[i]);
    __delay_cycles(1500000);
    // P2SEL &= ~BIT7;
  }
  buzzer_set_period(0);
  // P2DIR &= ~BIT6;
}
