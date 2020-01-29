/*
 * Calculator.c
 *
 *  Created on: Jan 27, 2020
 *      Author: markr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calculator.h"



int evaluateExpression(char *part) {
	int runningResult = 0;
	int i = 0;
	int currentNum = 0;
	int foundFirstNum = 0;
	char operator = ' ';
	do {
		if (part[i] >= '0' && part[i] <= '9') {
			currentNum = currentNum * 10 + (part[i] - '0');
		} else if (part[i] == '+' || part[i] == '-' || part[i] == '*'
				|| part[i] == '/') {
            if(foundFirstNum == 0) {
            	foundFirstNum = 1;
            	runningResult = currentNum;
            }
			switch (operator) {
			case '+':
				runningResult += currentNum;
				break;
			case '-':
				runningResult -= currentNum;
				break;
			case '*':
				runningResult *= currentNum;
				break;
			case '/':
				runningResult /= currentNum;
				break;
			default:
				break;
			}
			operator = part[i];
			currentNum = 0;
		}
		i++;
	} while (part[i] != '\n' && part[i] != '\0');
	switch (operator) {
	case '+':
		runningResult += currentNum;
		break;
	case '-':
		runningResult -= currentNum;
		break;
	case '*':
		runningResult *= currentNum;
		break;
	case '/':
		runningResult /= currentNum;
		break;
	default:
		break;
	}
	return runningResult;
}
