//menu.h

#include "types.h"                               // Includes user-defined data types

// External variables for street light ON time
extern u32 ON_HOUR;                              // Stores the ON time hour
extern u32 ON_MIN;                               // Stores the ON time minute

// External variables for street light OFF time
extern u32 OFF_HOUR;                             // Stores the OFF time hour
extern u32 OFF_MIN;                              // Stores the OFF time minute

void Menu(void);                                 // Displays the menu and handles user selections
