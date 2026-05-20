# PIC32_interrupt_based_pulse_generator
This is an academic project that demonstrates interrupt-driven timing on the PIC32MX370F512L microcontroller. Timer1 was configured with a 1:256 prescaler to generate periodic interrupts, which were used to toggle LEDs and produce a precise pulse train on PMODA JA7.

## Objective

Use the PIC32 Timer1 peripheral and interrupt system to create a precise hardware-timed delay instead of relying on software delay loops.

## Hardware Used

- PIC32MX370F512L microcontroller board
- MPLAB X IDE
- Oscilloscope
- PMODA output pin JA7
- On-board LEDs LED0 and LED1

## Key Concepts

- Timer peripheral configuration
- Prescaler selection
- Period register calculation
- Interrupt enable/control registers
- Interrupt Service Routine ISR
- Clearing interrupt flags
- Oscilloscope timing verification

## Implementation Summary

Timer1 was configured using the `T1CON` and `PR1` registers. The interrupt system was configured using `IEC0` and `IPC1`, with Timer1 interrupt priority set to level 2.

Inside the Timer1 ISR, the Timer1 interrupt flag in `IFS0` was cleared so that future interrupts could occur repeatedly.

The main loop waits for the interrupt event and toggles the output state to generate a 50% duty-cycle pulse train.

## Timing Calculation

Timer period:

```text
Timer Period = (PR1 + 1) × Prescaler × Instruction Cycle Period
