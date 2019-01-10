//   3ds-calc a simple calculator homebrew for the nintendo 3ds
//   Copyright (C) 2019  findus classon

//   This program is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.

//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.

#include <3ds.h>
#include <stdio.h>

int main()
{
//this part is boring stuff for we need for printing to the screen
gfxInitDefault();
PrintConsole topScreen, bottomScreen;
consoleInit(GFX_TOP, &topScreen);
consoleInit(GFX_BOTTOM, &bottomScreen);


/*now we print the cui this is what it will look like

(1)(2)(3) (add)
(4)(5)(6) (subtract)
(7)(8)(9) (divide)
   (0)    (multiply)        (exit)
*/
consoleSelect(&bottomScreen);

//important note be carefull!!! its quite easy to mess up the cui here
printf("\n\n\n\n\n\n(1) (2) (3) (+)\n\n(4) (5) (6) (-)\n\n(7) (8) (9) (/)\n\n    (0)     (x)  (clear screen)   (exit)");

//this is the main loop
while (aptMainLoop()){

hidScanInput();
touchPosition touch;
hidTouchRead(&touch);
consoleSelect(&topScreen);
printf("\n\x1b[2;0H%03d; %03d", touch.px, touch.py);

//this is the touchscreen code basically a bazillion if statements
//the reason we just print to the screen is for debug purposes
if (touch.px > 2 && touch.px < 22 && touch.py > 1 && touch.py < 7 ) {
printf("1");
}

if (touch.px > 31 && touch.px < 54 && touch.py > 1 && touch.py < 7 ) {
printf("2");
}

if (touch.px > 66 && touch.px < 85 && touch.py > 1 && touch.py < 7 ) {
printf("3");
}

if (touch.px > 98 && touch.px < 188 && touch.py > 1 && touch.py < 7 ) {
printf("+");
}

if (touch.px > 2 && touch.px < 22 && touch.py > 15 && touch.py < 22 ) {
printf("4");
}

if (touch.px > 31 && touch.px < 54 && touch.py > 15 && touch.py < 22 ) {
printf("5");
}

if (touch.px > 66 && touch.px < 85 && touch.py > 15 && touch.py < 22 ) {
printf("6");
}

if (touch.px > 98 && touch.px < 188 && touch.py > 15 && touch.py < 22 ) {
printf("-");
}

if (touch.px > 12 && touch.px < 14 && touch.py > 1 && touch.py < 7 ) {
printf("7");
}



gfxSwapBuffers();
gfxFlushBuffers();
gspWaitForVBlank();
}
