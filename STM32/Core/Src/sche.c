/*
 * sche.c
 *
 *  Created on: Nov 22, 2022
 *      Author: LENOVO
 */

#include "sche.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void) {
	for (int i = 0; i < SCH_MAX_TASKS; i++) SCH_Delete_Task(i);
}

void SCH_Update(void){
	for(int i = 0; i < SCH_MAX_TASKS; i++){
		if (SCH_tasks_G[i].Delay > 0) SCH_tasks_G[i].Delay--;
		else {
			if (SCH_tasks_G[i].Period)
				SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	int index = 0;
	while (SCH_tasks_G[index].pTask != 0 && index < SCH_MAX_TASKS)
		index++;
	if(index < SCH_MAX_TASKS){
		SCH_tasks_G[index].pTask = pFunction;
		SCH_tasks_G[index].Delay = DELAY;
		SCH_tasks_G[index].Period =  PERIOD;
		SCH_tasks_G[index].RunMe = 0;
		SCH_tasks_G[index].TaskID = index;
	}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
		}
	}
}

void SCH_Delete_Task(int TASK_INDEX) {
	SCH_tasks_G[TASK_INDEX].pTask = NULL;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
}
