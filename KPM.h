// KPM.h

#include "types.h"                // Includes user-defined data types

void InitKPM(void);               // Initializes the keypad
u8 ColScan(void);                 // Checks the status of all keypad columns
u8 RowCheck(void);                // Identifies the pressed key's row
u8 ColCheck(void);                // Identifies the pressed key's column
u8 KeyScan(void);                 // Scans the keypad and returns the pressed key
u32 ReadNum(void);                // Reads a multi-digit number from the keypad
