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

Adaptive-Street-Light-Control-Using-Time-and-Environmental-Illumination

├── README.md

├── Source_Code

├── Circuit_Diagrams

├── Project_Photos

|── Documentation

## 7. Systematic Block Diagram

<img width="1536" height="1024" alt="LPC2148 Adaptive Street Light Prototype" src="https://github.com/user-attachments/assets/5d8163a0-ce28-4f80-9205-56cff9d908cf" />

### 8.1 Proteus Circuit Diagram

The circuit was designed and simulated using Proteus Design Suite on a laptop.

<img width="873" height="614" alt="Project" src="https://github.com/user-attachments/assets/2c08ca2b-60d0-402b-9761-0b71b6cc8bcc" />

### 8.3 System Flowchart

<img width="424" height="517" alt="faa7e307-6c0a-4677-bb1a-fcc224d8ff4b" src="https://github.com/user-attachments/assets/3c1d85aa-25b7-4f25-b7c0-bca64937db8b" />

## 10. LCD Display Results
<img width="1600" height="793" alt="WhatsApp Image 2026-11-20 at 12 43 19 AM" src="https://github.com/user-attachments/assets/0ed0f277-1fb3-4773-b1c6-c7ec87be5457" />
<img width="1533" height="570" alt="WhatsApp Image 2026-11-20 at 12 43 20 AM" src="https://github.com/user-attachments/assets/0031b7ac-ce7d-4ebb-8130-5bdc62a2361f" />
<img width="1440" height="539" alt="WhatsApp Image 2026-11-20 at 12 43 21 AM" src="https://github.com/user-attachments/assets/0477bb9b-99aa-498b-9314-a2e48a5d6ba4" />
<img width="1600" height="767" alt="WhatsApp Image 2026-11-20 at 12 43 21 AM (3)" src="https://github.com/user-attachments/assets/41bb8c60-efc5-4f92-8e23-bcaa7a72ddf4" />
<img width="1600" height="582" alt="WhatsApp Image 2026-11-20 at 12 43 21 AM (1)" src="https://github.com/user-attachments/assets/a7796199-b803-4e9f-bf3a-015aedeb19cb" />

## 11. Programming

The microcontroller programming process and HEX file loading can be documented here.

<img width="1600" height="1200" alt="WhatsApp Image 2026-11-20 at 12 43 23 AM" src="https://github.com/user-attachments/assets/beb2dd5e-f368-4a38-b549-afe0c0ac1f1c" />

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

**Project Domain:** Embedded Systems

**Department:** Electronics and Communication Engineering (ECE)

**Project Type:** Hardware Implementation and Embedded C Programming
