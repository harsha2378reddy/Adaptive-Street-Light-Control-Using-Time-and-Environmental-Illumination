//LED.c

#include <LPC214x.h>                        // Includes LPC214x microcontroller register definitions
#include "LED.h"                            // Includes LED function declarations
#include "delay.h"                          // Includes delay function declarations

#define LED 27                              // Defines the starting pin number of LEDs.
#define BUZZER 25                           // Defines the buzzer pin number.

// Function to initialize LEDs and buzzer
void Init_LED(void)
{
	IODIR1 |= (0x0F << LED);                  // Configures P1.27 to P1.30 pins as output for LEDs.
	IODIR0 |= (1 << BUZZER);                  // Configures P0.25 pin as output for buzzer.
 
	IOCLR1 = (0x0F << LED);                   // Initially turns OFF all four LEDs.
	IOCLR0 = (1 << BUZZER);                   // Initially turns OFF the buzzer.
}

// Function to turn ON the streetlight
void Streetlight_ON(void)
{
	IOSET1 = (0x0F << LED);                   // Makes P1.27 to P1.30 HIGH and turns ON all four LEDs.
}

// Function to turn OFF the streetlight
void Streetlight_OFF(void)
{
	IOCLR1 = (0x0F << LED);                   // Makes P1.27 to P1.30 LOW and turns OFF all four LEDs.
}

// Function to generate a buzzer beep
void Buzzer_Beep(void)
{
	IOSET0 = (1 << BUZZER);                   // Makes P0.25 HIGH and turns ON the buzzer.
	delay_MS(100);                            // Keeps the buzzer ON for 100 milliseconds.
	IOCLR0 = (1 << BUZZER);                   // Makes P0.25 LOW and turns OFF the buzzer.
}

