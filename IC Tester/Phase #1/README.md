# Phase 1 – Data Collection and IC Profiling

In Phase 1 of our IC Tester project, our group focused on:
collecting IC specifications, and profiling the behavior of various integrated circuits using a multimeter.

This phase was essential for building the dataset that would later be used for identification and matching in Phase 2.

## What We Did

### 1. IC Datasheet Collection
Our group received a set of ICs, including both digital (74xxx, 40xxx) and mixed-signal types, in both DIP and SMD packages. We:
- Created a folder named `Datasheets`.
- Collected and uploaded the corresponding datasheets in PDF format, using the IC part numbers as filenames (e.g., `74LS04.pdf`).

### 2. IC Electrical Profiling
Using a multimeter in diode test mode:
- We connected the RED probe to the GND pin of each IC.
- The BLACK probe was then used to test all other pins in sequence.
- The voltage readings were recorded for each pin.

These readings were documented in an Excel file named `G17_IC_Reading.xlsx`. The file contains:
- Pin numbers
- Pin names (where available)
- Measured voltage values

### 3. MATLAB Function Development
We implemented a MATLAB function that:
- Takes the pin voltage readings and total pin count as inputs
- Compares the input data against a known IC dataset
- Attempts to identify the most likely match

## Summary
This phase laid the foundation for our IC recognition system by:
collecting structured data and developing a simple, testable identification mechanism. 


