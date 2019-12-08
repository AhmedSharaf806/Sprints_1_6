/*
 * main.c
 *
 *  Created on: Dec 3, 2019
 *      Author: ahmed
 */

#include "led.h"
#include "gpio.h"
#include "softwareDelay.h"
#include "pushButton.h"
#include "timers.h"

enum state{
    Go,
    Stop,
    Ready
}state;


int main(){

    Led_Init(0);
    Led_Init(1);
    Led_Init(2);

    pushButton_Init(1);

    uint8 u8_checkStatus_1; 	//To store the status of every update

    uint8 u8_checkPressed=0; 	//To store if led is on or off before go in release status condition

    timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,0,T0_COMP_MODE);

    while(1)
	{

	    pushButton_Update();

	    u8_checkStatus_1=pushButton_GetStatus(1);

	    static uint8 u8_State=Go;

	    static uint8 u8_SavedState=Go;

	    if(u8_checkStatus_1==Pressed)
	    	    {
	    		Led_Off(0);
	    		Led_Off(2);
	    		Led_On(1);
	    		u8_checkPressed=1; //Store that led has pressed
	    		continue;

	    	    }
	    	else if(u8_checkStatus_1==Released && u8_checkPressed) // to check the release state after pressed state
	    	    {
	    		Led_Off(0);
	    		Led_Off(2);
	    		Led_On(1);
	    		timer0Delay_ms(1000);
	    		Led_Off(1);
	    		u8_checkPressed=0; //reset pressed state to zero
	    		continue;
	    	    }

	    switch(u8_SavedState)
	    {
		case Go:
		    Led_Off(1);
		    Led_Off(2);
		    Led_On(0);
		    u8_State=Stop;
		    timer0Delay_ms(1000);

		    break;
		case Stop:
		    Led_On(1);
		    Led_Off(0);
		    Led_Off(2);
		    u8_State=Ready;
		    timer0Delay_ms(1000);
		    break;
		case Ready:
		    Led_On(2);
		    Led_Off(0);
		    Led_Off(1);
		    u8_State=Go;
		    timer0Delay_ms(1000);
		    break;
	    }

	    u8_SavedState = u8_State;

	}
}
