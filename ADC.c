//ADC.c

#include "types.h"                                                // Includes user-defined data types
#include <LPC214x.h>                                              // Includes LPC2148 microcontroller register definitions
#include "ADC_defines.h"                                          // Includes ADC clock, channel and bit-position definitions
#include "ADC.h"                                                  // Includes ADC function declarations
#include "delay.h"                                                // Includes delay function declarations

// Function to initialize the ADC
void Init_ADC(void)
{
    PINSEL1 &= ~(0xFF << 22);                                     // Clears PINSEL1 bits 22 to 29 to configure ADC pins

    PINSEL1 |= AIN0_FUNC;                                         // Configures ADC channel 0 pin as an ADC input
    PINSEL1 |= AIN1_FUNC;                                         // Configures ADC channel 1 pin as an ADC input
    PINSEL1 |= AIN2_FUNC;                                         // Configures ADC channel 2 pin as an ADC input
    PINSEL1 |= AIN3_FUNC;                                         // Configures ADC channel 3 pin as an ADC input

    AD0CR = (1 << PDN_BIT) | (CLKDIV_VAL << CLKDIV_BITS);         // Powers ON ADC and configures the ADC clock divider
}

// Function to read ADC value from the selected channel
void Read_ADC(u8 chNO, u16 *dVal, f32 *eAR)
{
    AD0CR &= 0xFFFFFF00;                                          // Clears the channel selection bits (bits 0 to 7)

    AD0CR |= (1 << chNO);                                         // Selects the required ADC channel

    AD0CR &= ~(7 << ADC_CONV_START_BIT);                          // Clears the START bits to stop any previous conversion

    AD0CR |= (1 << ADC_CONV_START_BIT);                           // Starts the ADC conversion

    delay_US(3);                                                  // Waits for 3 microseconds for ADC conversion

    while(((AD0DR1 >> DONE_BIT) & 1) == 0);                       // Waits until the ADC conversion is completed
                                                                  // DONE bit becomes 1 when conversion is complete

    AD0CR &= ~(7 << ADC_CONV_START_BIT);                          // Clears the START bits after conversion

    *dVal = ((AD0DR1 >> DIGITAL_DATA_BITS) & 1023);               // Extracts the 10-bit digital ADC result from ADC data register
                                                                  // Stores the result in the variable pointed to by dVal
    *eAR = *dVal * (3.3f / 1023);                                 // Converts the digital ADC value into voltage
                                                                  // ADC reference voltage = 3.3V
                                                                  // 1023 is the maximum 10-bit ADC value
}
