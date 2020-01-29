/*
 * util.c
 *
 *  Created on: Jan 29, 2020
 *      Author: markr
 */



#include "Util.h"

void clearString(char* str, int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
    	str[i] = '\0';
    }

}
