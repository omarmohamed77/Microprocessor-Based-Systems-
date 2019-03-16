#include "../port driver/mcal.h"
/*
steps to write a command (assuming port is initialized):
1. clear Enable, RS and RW bits (PA5, PA6, PA7)
2. write the command on PortB
3. set Enable bit
4. make the appropriate delay
5. clear Enable bit
*/
void LCD_command(char command);