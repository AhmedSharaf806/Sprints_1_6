/*
 * softwareDelay.c
 *
 *  Created on: Dec 3, 2019
 *      Author: ahmed
 */

#include "softwareDelay.h"

/**
 * Description: this delay function operate in a polling manner
 * 				don't use it with RTOSs
 * @param n: the milli-seconds
 */
void SwDelay_ms(uint32 n)
{
    uint32 u32_iterator;
    for(u32_iterator=0; u32_iterator<(93*n); u32_iterator++);
}
