/*
 * scheduler.h
 *
 *  Created on: May 29, 2022
 *      Author: asten
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_


// Increments counter. To be called from SysTick interrupt
void SchedulerIncrement();

// logs execution time, waits until counter reaches time_ms and resets the counter
void SchedulerWaitFor(uint32_t time_ms);

// returns execution time of previous loop
uint32_t SchedulerExecutionTime();





#endif /* INC_SCHEDULER_H_ */
