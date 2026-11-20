// INT.h

#include "types.h"                    // Includes user-defined data types

extern volatile u32 menu_flag;        // Global flag to indicate that the menu button is pressed
void Init_Interrupt(void);            // Initializes the external interrupt
