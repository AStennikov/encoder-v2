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

Scheduler and blinky are done. Working on storing data in FLASH. Erase and write seem to be working in config.c, next steps:
1. Think how to organize data in FLASH.
2. Implement CAN.
3. Create an interface to load and store data via CAN bus, right now all testing is done by compiling the code and it is annoying.
4. Only double words can be written into flash. After writing "0x ffff0000 ffffff00" ST-Link utility shows "0x ffffff00 ffff0000". Word order, watch out!
5. If FLASH is locked between programming different addresses, values at both addresses turn to zero. Do not know what is going on.



