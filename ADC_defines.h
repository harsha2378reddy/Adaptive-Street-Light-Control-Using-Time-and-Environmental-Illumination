//ADC_defines.h

#define FOSC                12000000       // Defines the external oscillator frequency as 12 MHz
#define CCLK                (FOSC*5)       // Calculates the CPU clock frequency (12 MHz × 5 = 60 MHz)
#define PCLK                (CCLK/4)       // Calculates the peripheral clock frequency (60 MHz / 4 = 15 MHz)
#define ADC_CLK             3000000        // Defines the ADC clock frequency as 3 MHz

// ADC control register bit positions
#define PDN_BIT             21             // Power-down control bit; setting it to 1 enables the ADC
#define CLKDIV_BITS         8              // Starting bit position of the ADC clock divider field
#define CLKDIV_VAL          4              // ADC clock divider value
#define ADC_CONV_START_BIT  24             // Starting bit position of the ADC conversion start control field

// ADC data register bit positions
#define DONE_BIT            31             // Indicates whether ADC conversion is completed
#define DIGITAL_DATA_BITS   6              // Starting bit position of the 10-bit ADC result

// ADC channel pin function selection values
#define AIN0_FUNC           0x00400000     // Selects AIN0 function through the corresponding PINSEL bits
#define AIN1_FUNC           0x01000000     // Selects AIN1 function through the corresponding PINSEL bits
#define AIN2_FUNC           0x04000000     // Selects AIN2 function through the corresponding PINSEL bits
#define AIN3_FUNC           0x10000000     // Selects AIN3 function through the corresponding PINSEL bits
