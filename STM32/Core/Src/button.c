/*
 * button.c
 *
 *  Created on: Sep 27, 2022
 *      Author: LENOVO
 */

#include "button.h"

int TimeOutForKeyPress = 500;

int button_flag = 0;

int flagForLPress = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int isButtonPressed() {
	if (button_flag) {
		button_flag = 0;
		return 1;
	}
	return 0;
}

int isButtonLPressed() {
	if (flagForLPress) {
		flagForLPress = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess() {
	// Set value
	button_flag = 1;
}

void getKeyInput() {
	// Pressed
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(GPIOB, button_Pin);

	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
		if (KeyReg3 != KeyReg2) {
			KeyReg3 = KeyReg2;
			if (KeyReg2 == PRESSED_STATE) {
				if (!flagForLPress) {
					TimeOutForKeyPress = 500;
					subKeyProcess();
				}
				else TimeOutForKeyPress = 100;
			}
			else flagForLPress = 0;
		}
		else {
			TimeOutForKeyPress--;
			if (TimeOutForKeyPress == 0) {
				if (KeyReg2 == PRESSED_STATE) {
					flagForLPress = 1;
					TimeOutForKeyPress = 0;
					KeyReg3 = NORMAL_STATE;
				}
			}
		}
	}
	if (isButtonPressed()) {
		HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
	}
}
