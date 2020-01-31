/*
 ============================================================================
 Name        : Calculator.c
 Author      : Mark Burrell
 Version     :
 Copyright   : Copywrite 2020 by Mark Burrell. This software is freely redistributable with recogniton to the original author
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"
#include "util.h"

#define EQN_MAX_LEN STR_LEN



int main(void) {
	char userEqn[EQN_MAX_LEN];
	double result;
    int idx = 0;
    char userIn = '\0';

    puts("Welcome to the BC emulator V 0.0.1 by Mark Burrell\n Enter an expression, or q to quit");
    fflush(stdout);
    do {
    	clearString(userEqn, EQN_MAX_LEN);
    	idx = -1;
    	do {
    		scanf("%c", &userIn);
    		if(userIn != '\n' && idx < EQN_MAX_LEN - 1) {
    			idx++;
    			userEqn[idx] = userIn;

    		}

    	} while (userIn != '\n' && idx < EQN_MAX_LEN);
    	if(userEqn[idx] != 'q' && userEqn[idx] != 'Q') {
    		result = evaluateExpression(userEqn);
    		printf("%0.03lf\n", result);
    		fflush(stdout);
    	}

    } while (userEqn[idx] != 'q' && userEqn[idx] != 'Q');
    puts("goodbye!\n");
    fflush(stdout);
}

