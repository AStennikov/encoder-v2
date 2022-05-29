/*
 * scheduler.c
 *
 *  Created on: May 29, 2022
 *      Author: asten
 */

#include <stdint.h>

uint32_t counter = 0;       // variable thet counts SysTick ticks
uint32_t executionTime = 0; // tracks execution time by saving current counter value at the start of SchedulerWaitFor(uint32_t time_ms)


void SchedulerIncrement() {
  ++counter;
}

void SchedulerWaitFor(uint32_t time_ms) {
  executionTime = counter;
  while(counter < time_ms) {}
  counter = 0;
}

uint32_t SchedulerExecutionTime() {
  return executionTime;
}
