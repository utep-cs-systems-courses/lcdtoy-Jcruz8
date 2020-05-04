Project 3: Graphical LCD TOY

The Makefile contains the commands "make", "make load", and "make clean".

To compile use the command "make", to load it into the msp430 use the command "make load" while
being inside of the project directory.

When the S1 button is pressed the toy will draw a square and play some music.

When the S2 button is pressed the toy will play some music.

When the S3 button is pressed the toy will draw a shape and will move in the
down right direction.

When the S4 button is pressed the toy will clear the screen and make it black.

The stateMachine.c file contains the statemachine and its switch case that
changes its state.

The switches.c file contains how the program reacts to a button press

The buzzer.c file contains the music and the init to make the music.
