/*
 * display.c
 *
 *  Created on: Nov 22, 2022
 *      Author: LENOVO
 */

#include "display.h"

//enum LightsState{PHASE1_GREEN, PHASE1_YELLOW, PHASE1_RED, PHASE2_GREEN, PHASE2_YELLOW, PHASE2_RED};
//enum LightsState statusOfLight_1 = PHASE1_GREEN;
//enum LightsState statusOfLight_2 = PHASE2_GREEN;
//
//unsigned char timeOfPhase = 1;
//
//unsigned char timeOfLight_1 = 0;
//unsigned char timeOfLight_2 = 0;
//
//void display7SEG_1(uint8_t byte)
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, byte&0x01);
//	byte = byte >> 1;
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, byte&0x01);
//	byte = byte >> 1;
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, byte&0x01);
//	byte = byte >> 1;
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, byte&0x01);
//}
//
//void display7SEG_2(uint8_t byte)
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, byte&0x01);
//	byte = byte >> 1;
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, byte&0x01);
//	byte = byte >> 1;
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, byte&0x01);
//	byte = byte >> 1;
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, byte&0x01);
//}
//
//uint8_t ledCount = 0;
//void display7SEG(void){
//	ledCount = (ledCount + 1)%10;
//	display7SEG_1(ledCount);
//	display7SEG_2(ledCount);
//}
//
////On/Off Lights in Phase1
//void Phase1_GreenOn()
//{
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
//}
//void Phase1_GreenOff()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
//}
//
//void Phase1_YellowOn()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
//}
//void Phase1_YellowOff()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
//}
//void Phase1_RedOn()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
//}
//void Phase1_RedOff()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
//}
//
////On/Off Lights in Phase2
//void Phase2_GreenOn()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
//}
//void Phase2_GreenOff()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
//}
//void Phase2_YellowOn()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//}
//void Phase2_YellowOff()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
//}
//void Phase2_RedOn()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
//}
//void Phase2_RedOff()
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
//}
//
////State function for Light display
//void AppTrafficLight_1()
//{
//    switch (statusOfLight_1)
//    {
//        case PHASE1_GREEN:
//            Phase1_GreenOn();
//            Phase1_RedOff();
//            Phase1_YellowOff();
//
//        	if (timeOfLight_1 == 0)
//				{
//					statusOfLight_1 = PHASE1_YELLOW;
//					timeOfLight_1 = timeOfPhase;
//				}
//            break;
//        case PHASE1_YELLOW:
//        	Phase1_GreenOff();
//			Phase1_RedOff();
//			Phase1_YellowOn();
//
//            if (timeOfLight_1 == 0)
//            {
//                statusOfLight_1 = PHASE1_RED;
//                timeOfLight_1 = timeOfPhase;
//            }
//
//            break;
//        case PHASE1_RED:
//        	Phase1_GreenOff();
//			Phase1_RedOn();
//			Phase1_YellowOff();
//
//            if (timeOfLight_1 == 0)
//            {
//                statusOfLight_1 = PHASE1_GREEN;
//                timeOfLight_1 = timeOfPhase;
//            }
//            break;
//        default:
//            statusOfLight_1 = PHASE1_GREEN;
//            break;
//    }
//    timeOfLight_1 = timeOfLight_1 - 1;
//}
//
//void AppTrafficLight_2()
//{
//    switch (statusOfLight_2)
//    {
//        case PHASE2_GREEN:
//            Phase2_RedOff();
//            Phase2_YellowOff();
//            Phase2_GreenOn();
//
//        	if (timeOfLight_2 == 0)
//				{
//					statusOfLight_2 = PHASE2_YELLOW;
//					timeOfLight_2 = timeOfPhase;
//				}
//            break;
//        case PHASE2_YELLOW:
//			Phase2_RedOff();
//			Phase2_YellowOn();
//			Phase2_GreenOff();
//
//            if (timeOfLight_2 == 0)
//            {
//                statusOfLight_2 = PHASE2_RED;
//                timeOfLight_2 = timeOfPhase;
//            }
//
//            break;
//        case PHASE2_RED:
//			Phase2_RedOn();
//			Phase2_YellowOff();
//			Phase2_GreenOff();
//
//            if (timeOfLight_2 == 0)
//            {
//                statusOfLight_2 = PHASE2_GREEN;
//                timeOfLight_2 = timeOfPhase;
//            }
//            break;
//        default:
//            statusOfLight_2 = PHASE2_GREEN;
//            break;
//    }
//    timeOfLight_2 = timeOfLight_2 - 1;
//}

void Led0() {
	HAL_GPIO_TogglePin(led0_GPIO_Port, led0_Pin);
}
void Led1() {
	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
}
void Led2() {
	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
}
void Led3() {
	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
}
void Led4() {
	HAL_GPIO_TogglePin(led4_GPIO_Port, led4_Pin);
}
void Led5() {
	HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
}
