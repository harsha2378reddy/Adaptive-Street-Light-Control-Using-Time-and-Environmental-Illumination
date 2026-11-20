# Adaptive-Street-Light-Control-Using-Time-and-Environmental-Illumination

## 1. Project Overview

The **Adaptive Street Light Control System** is an Embedded C-based project developed using an LPC214x microcontroller. It automatically controls street lights based on surrounding light intensity detected by an LDR sensor and predefined ON/OFF schedules maintained by the RTC.

The project integrates ADC, LCD display, 4×4 keypad, LEDs, buzzer, and external interrupt functionality. It was developed using Keil µVision IDE, simulated using Proteus on a laptop, and implemented and tested using a physical hardware kit.

## 2. Project Objectives

- Automatically control street lights based on surrounding light intensity.
- Reduce unnecessary electricity consumption.
- Provide RTC-based automatic ON/OFF scheduling.
- Allow users to configure time and date using a keypad.
- Display real-time system information on an LCD.

## 3. Hardware Components

- LPC214x Microcontroller
- LDR Sensor
- 16×2 LCD Display
- 4×4 Matrix Keypad
- Real-Time Clock (RTC)
- LEDs
- Buzzer
- Power Supply
- Hardware Development Kit
- Connecting Wires

## 4. Software and Tools Used

- Embedded C
- Keil µVision IDE
- Proteus Design Suite
- Flash Magic (for programming, if used)
- LPC214x Microcontroller

## 5. Working Principle

1. The microcontroller initializes the LCD, ADC, RTC, keypad, LEDs, and interrupt.
2. The LDR sensor detects the surrounding light intensity.
3. The ADC converts the analog sensor signal into a digital value.
4. The microcontroller compares the ADC value with a predefined threshold.
5. The RTC checks the configured street light ON and OFF timings.
6. When the schedule is active and darkness is detected, the street lights turn ON.
7. During daylight or outside the configured schedule, the street lights remain OFF.
8. The LCD displays the current time and system information.
9. Users can configure time, date, and street light schedules through the keypad.

## 6. Project Folder Structure

```text
Adaptive-Street-Light-Control/
│
├── README.md
│
├── Source_Code/
│   ├── Main.c
│   ├── LCD.c
│   ├── LCD.h
│   ├── ADC.c
│   ├── ADC.h
│   ├── RTC.c
│   ├── RTC.h
│   ├── KPM.c
│   ├── KPM.h
│   ├── LED.c
│   ├── LED.h
│   ├── INT.c
│   ├── INT.h
│   ├── Menu.c
│   ├── Menu.h
│   ├── RTCedit.c
│   ├── RTCedit.h
│   ├── delay.c
│   ├── delay.h
│   ├── defines.h
│   ├── LCD_defines.h
│   ├── ADC_defines.h
│   ├── KPM_defines.h
│   └── types.h
│
├── Circuit_Diagrams/
│   ├── Proteus_Circuit.png
│   ├── Block_Diagram.png
│   ├── Hardware_Connections.png
│   └── System_Flowchart.png
│
├── Project_Photos/
│   ├── Hardware_Setup/
│   ├── LCD_Display/
│   └── Programming/
│
└── Documentation/
    ├── Working_Principle.md
    └── Pin_Configuration.md
```

## 7. Systematic Block Diagram

![Systematic Block Diagram](Circuit_Diagrams/Block_Diagram.png)

## 8. Circuit Diagrams

### 8.1 Proteus Circuit Diagram

The circuit was designed and simulated using Proteus Design Suite on a laptop.

![Proteus Circuit](Circuit_Diagrams/Proteus_Circuit.png)

### 8.2 Hardware Connections

![Hardware Connections](Circuit_Diagrams/Hardware_Connections.png)

### 8.3 System Flowchart

![System Flowchart](Circuit_Diagrams/System_Flowchart.png)

## 9. Hardware Implementation

The project was implemented and tested using a physical hardware development kit.

### Development Board

![Development Board](Project_Photos/Hardware_Setup/Development_Board.jpeg)

### Complete Hardware Setup

![Complete Hardware Setup](Project_Photos/Hardware_Setup/Complete_Hardware_Setup.jpeg)

### LDR Dark Condition

![Dark Condition](Project_Photos/Hardware_Setup/LDR_Dark_Condition.jpeg)

### LDR Bright Condition

![Bright Condition](Project_Photos/Hardware_Setup/LDR_Bright_Condition.jpeg)

## 10. LCD Display Results

### Project Title Display

![Project Title](Project_Photos/LCD_Display/Project_Title.jpeg)

### RTC Display

![RTC Display](Project_Photos/LCD_Display/RTC_Display.jpeg)

### Street Light ON

![Light ON](Project_Photos/LCD_Display/Light_ON.jpeg)

### Street Light OFF

![Light OFF](Project_Photos/LCD_Display/Light_OFF.jpeg)

## 11. Programming

The microcontroller programming process and HEX file loading can be documented here.

![Flash Magic Programming](Project_Photos/Programming/Flash_Magic_Programming.jpeg)

## 12. How to Run the Project

1. Open the project in Keil µVision IDE.
2. Select the correct LPC214x microcontroller device.
3. Add all required source and header files.
4. Build the project and check for compilation errors.
5. Generate the HEX file.
6. Program the microcontroller using the supported programming method.
7. Power the hardware kit and test the street light operation.

## 13. Future Enhancements

- IoT-based remote monitoring and control.
- Solar-powered street light integration.
- Wireless communication between street lights.
- Energy consumption monitoring.
- Automatic fault detection.

## 14. Author

**Kondavaripalli Harshavardhan Reddy**

Department of Electronics and Communication Engineering (ECE)

## 15. Development Tools

- Keil µVision IDE
- Proteus Design Suite
- Embedded C

## 16. License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

**Project Domain:** Embedded Systems

**Department:** Electronics and Communication Engineering (ECE)

**Project Type:** Hardware Implementation and Embedded C Programming
