# Encoder v2

## About

This is the new and cleaner version of the encoder firmware.

## Toolchain

STM32CubeIDE and ST-Link.

## Git

Master branch contains stable and working code. Use feature branches for developing new features.

## TODO

Below is a rough plan for the project:
- Create scheduler
- Create main state machine
- Implement calibration routing and parameter storage in FLASH (to make development faster)
- Import most of the measure and control stuff from the old project

What now:

Just created this project and made blinky code. Next step is to create a proper scheduler and make 2 state machines, one for LED and another for the main process.

