//ADC.h

#include "types.h"                             // Includes user-defined data types

void Init_ADC(void);                           // Function prototype to initialize the ADC peripheral
void Read_ADC(u8 chNO, u16 *dVal, f32 *eAR);   // Function prototype to read ADC value and calculate the corresponding analog voltage
