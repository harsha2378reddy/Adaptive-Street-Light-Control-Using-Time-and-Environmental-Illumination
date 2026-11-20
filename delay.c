//delay.c

#include "types.h"                              // Includes user-defined data types

// Function to generate delay in microseconds
void delay_US(u32 dlyUS)
{
	for(dlyUS*=12; dlyUS>0; dlyUS--);             // Executes 12 loop iterations for each microsecond
}

// Function to generate delay in milliseconds
void delay_MS(u32 dlyMS)
{
	for(dlyMS*=12000; dlyMS>0; dlyMS--);          // Executes 12000 loop iterations for each millisecond
}

// Function to generate delay in seconds
void delay_S(u32 dlyS)
{
	for(dlyS*=12000000; dlyS>0; dlyS--);          // Executes 12000000 loop iterations for each second
}
