//LCD.h

#include "types.h"                  // Includes user-defined data types

void Writelcd(u8 dat);              // Function prototype to send 8-bit data to LCD
void Cmdlcd(u8 cmd);                // Function prototype to send commands to LCD
void Charlcd(u8 asciival);          // Function prototype to display a single character on LCD
void Initlcd(void);                 // Function prototype to initialize the LCD
void Strlcd(s8 *);                  // Function prototype to display a string on LCD
void u32lcd(u32 n);                 // Function prototype to display an unsigned 32-bit number on LCD
