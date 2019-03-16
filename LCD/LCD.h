#define CLEAR 0x01                 // clear the display & reset the cursor to address 00 H position
#define RESET 0x03                 // return the cursor to address 00 H position
#define RIGHT_DIR 0x14             // cursor moves to right
#define LEFT_DIR 0x10              // cursor moves to left
#define DISPLAY_OFF 0x08           // turn off the display
#define DISPLAY_ON_CURSOR_OFF 0x0C // turn on the display & open cursor & cursor flashing

#include "std_types.h"

void LCD_init();