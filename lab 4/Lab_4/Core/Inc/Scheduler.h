/*
 * Scheduler.h
 *
 *  Created on: Dec 7, 2021
 *      Author: buiqu
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "main.h"
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 6
#define NO_TASK_ID 0

typedef struct {
	// Pointer to the task (must be a ’ void ( void ) ’ function )
	void (*pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs.
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	//This is a hint to solve the question below .
	uint32_t TaskID;
} sTask;

unsigned char SCH_Add_Task(void(*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
unsigned char SCH_Delete_Task(const unsigned char TASK_INDEX);
void SCH_Init(void);
void SCH_Update(void);

extern sTask SCH_tasks_G[SCH_MAX_TASKS];
#endif /* INC_SCHEDULER_H_ */
