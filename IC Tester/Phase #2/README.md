# Phase 2 – Design and Implementation of a Digital IC Tester

In Phase 2 of our project, we designed and implemented a digital IC tester using the ATMEGA32 microcontroller. 
The goal was to:
develop a system that could automatically test various ICs from the 74xxx, 40xxx, and 45xxx logic families, determine their functionality, and display their part numbers on an LCD.


## Overview

The system was designed to support ICs with 14, 16, 20, or 24 pins.
Each IC was placed into a socket where Pin 1 aligned with PA.0 of the microcontroller. 
The microcontroller powered the IC, applied logic test patterns, and analyzed output behavior to determine whether the IC functioned correctly.

### Key Features
- Supports 74xxx (TTL), 40xxx and 45xxx (CMOS) digital IC families.
- Automatically identifies correct pinout and applies power using microcontroller I/O.
- Functional testing based on known truth tables.
- Displays the detected IC number on a 16x2 LCD.
- If the IC is not recognized, displays "Unknown IC".

---

## Hardware Design

- **Microcontroller**: ATMEGA32
- **IC Socket**: Used for placing the IC under test; connected to PORTA, PORTB, and PORTC.
- **LCD Display**: A 16x2 character LCD connected to PORTD for displaying IC identification results.
- **Power Supply**: Delivered by configuring specific I/O pins as GND and VCC based on the IC datasheet.

Example:  
To test a 7400 NAND gate IC:
- PA.6 (Pin 7 on IC) was set as output LOW to provide GND.
- PC.0 (Pin 14 on IC) was set as output HIGH to provide VCC.

---

## Software Implementation

- The firmware was developed in Embedded C using **CodeVision AVR**.
- We programmed the microcontroller to:
  - Configure IO pins based on the IC’s datasheet.
  - Send logic input patterns according to the IC’s truth table.
  - Read output responses and compare them with expected values.
  - Identify the IC or mark it as unknown.

---

## Simulation

- A full **Proteus simulation** was built to test the circuit design before deployment.
- The simulation included:
  - The microcontroller
  - LCD
  - Socket connection with sample ICs
  - Logic probes to visualize input/output states

---

## Summary

Phase 2 resulted in a fully functional embedded system capable of:
testing digital ICs, identifying them by behavior, and reporting results via LCD.

The project combined embedded C programming, circuit design, and simulation into a cohesive tool for practical digital IC analysis.
