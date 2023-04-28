# AVR Timer1 LED Blinker

This repository contains an example of using the AVR Timer1 in CTC (Clear Timer on Compare) mode to toggle an LED on an ATmega328P microcontroller. The code is written for the Arduino platform.

## Overview

The Timer1 is configured to trigger a compare match interrupt when its counter reaches the value specified in the `OCR1A` register. When the interrupt occurs, the LED connected to pin 13 (PB5) is toggled. The timer is set to use a prescaler of 1024, and the `OCR1A` value is calculated to generate a 1-second interval between toggles.

## Dependencies

- Arduino IDE or compatible development environment

## Usage

1. Clone this repository or download the provided source code.
2. Open the main `.ino` file in the Arduino IDE or your preferred development environment.
3. Connect your Arduino or compatible microcontroller board to your computer.
4. Select the appropriate board and port in the development environment.
5. Compile and upload the code to the microcontroller.

After the upload, the LED on pin 13 (PB5) should start blinking at a rate of 1 Hz.

## License

This project is released under the [MIT License](LICENSE).
