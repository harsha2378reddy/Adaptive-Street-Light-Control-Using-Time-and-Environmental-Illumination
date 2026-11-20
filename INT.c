//INT.c

#include <LPC214x.h>                   // Includes LPC214x microcontroller register definitions
#include "types.h"                     // Includes user-defined data types
#include "INT.h"                       // Includes external interrupt function declarations

// Global variable to indicate whether the interrupt has occurred
volatile u32 menu_flag = 0;

// Interrupt Service Routine for External Interrupt 0
void EINT0_ISR(void)__irq
{
    menu_flag = 1;                     // Sets menu_flag to 1 when external interrupt occurs.

    EXTINT = 1;                        // Clears the external interrupt flag.

    VICVectAddr = 0;                   // Informs VIC that the interrupt service routine is completed.
}

// Function to initialize external interrupt
void Init_Interrupt(void)
{
    PINSEL0 &= ~(3 << 2);              // Clears the function selection bits for P0.1.

    PINSEL0 |= (3 << 2);               // Selects EINT0 function on P0.1.

    IODIR0 &= ~(1 << 1);               // Configures P0.1 pin as input.

    EXTMODE |= 1;                      // Configures EINT0 as edge-sensitive interrupt.

    EXTPOLAR &= ~1;                    // Selects falling-edge interrupt.

    VICIntSelect &= ~(1 << 14);        // Configures EINT0 as an IRQ interrupt instead of FIQ.

    VICVectAddr0 = (u32)EINT0_ISR;     // Stores the address of EINT0 interrupt service routine in VIC slot 0.

    VICVectCntl0 = (1 << 5) | 14;      // Enables VIC slot 0 and assigns external interrupt 0 to it.

    EXTINT = 1;                        // Clears any pending external interrupt flag.

    VICIntEnable |= (1 << 14);         // Enables external interrupt 0 in the VIC.
}
