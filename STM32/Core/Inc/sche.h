/*
 * sche.h
 *
 *  Created on: Nov 22, 2022
 *      Author: LENOVO
 */

#ifndef INC_SCHE_H_
#define INC_SCHE_H_

#include "main.h"

#define	SCH_MAX_TASKS	5
#define NO_TASK_ID	0

void SCH_Init(void);
void SCH_Add_Task(void (*pFunction)() ,uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task (int TASK_INDEX);

typedef struct {
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

#endif /* INC_SCHE_H_ */
