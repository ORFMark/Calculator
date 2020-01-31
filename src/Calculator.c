/*
 * Calculator.c
 *
 *  Created on: Jan 27, 2020
 *      Author: markr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Calculator.h"

double evaluateExpression(char *part) {
	double runningResult = 0;
	int i = 0;
	double currentNum = 0;
	int foundFirstNum = 0;
	int foundFractionalPoint = 0;
	char operator = ' ';
	do {
		if ((part[i] >= '0' && part[i] <= '9') || part[i] == '.') {
			if(part[i] == '.') {
				foundFractionalPoint = i;
			} else {
				if(foundFractionalPoint == 0) {
					currentNum = currentNum * 10 + (part[i] - '0');
				} else {
					currentNum += ((part[i] - '0') / (pow(10, i - foundFractionalPoint)));
				}
			}
		} else if (part[i] == '+' || part[i] == '-' || part[i] == '*'
				|| part[i] == '/' || part[i] == '^') {
			if (foundFirstNum == 0) {
				foundFirstNum = 1;
				runningResult = currentNum;
			} else {
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
				case '^':
					runningResult = pow(runningResult, currentNum);
					break;
				default:
					break;
				}
			}
			operator = part[i];
			currentNum = 0;
			foundFractionalPoint = 0;
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
	case '^':
		runningResult = pow(runningResult, currentNum);
		break;
	default:
		break;
	}

	return runningResult;
}
