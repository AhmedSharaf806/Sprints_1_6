/*
 * pushButton.c
 *
 *  Created on: Dec 5, 2019
 *      Author: ahmed
 */

#include "pushButton.h"

#define PRESSED 1
#define RELEASED 0



static pushButton_status gau8str_SaveStatus[4];

/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButton_Init(En_buttonId btn_id){

	switch (btn_id) {

	    case BTN_0:
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
		gau8str_SaveStatus[0].pushButton_saved_status=RELEASED;
		gau8str_SaveStatus[0].pushButton_status_btn=Released;
		break;

	    case BTN_1:
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
		gau8str_SaveStatus[1].pushButton_saved_status=RELEASED;
		gau8str_SaveStatus[1].pushButton_status_btn=Released;
		break;

	    case BTN_2:
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
		gau8str_SaveStatus[2].pushButton_saved_status=RELEASED;
		gau8str_SaveStatus[2].pushButton_status_btn=Released;
		break;

	    case BTN_3:
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
		gau8str_SaveStatus[3].pushButton_saved_status=RELEASED;
		gau8str_SaveStatus[3].pushButton_status_btn=Released;
		break;
	}
}

/**
 * Description: read all BTN_x (where x 0, 1, 2, 3) states and store it in the program
 *
 * @note : this function must be called in the system tick hundler or in the super loop hundler
 */
void pushButton_Update(void){

    uint8 u8_iterator=0;

    for(u8_iterator=0; u8_iterator<2; u8_iterator++)
	{

    if(gpioPinRead(BTN_0_GPIO,BTN_0_BIT)==1 || gpioPinRead(BTN_0_GPIO,BTN_0_BIT)==0)
	{
	    if(gpioPinRead(BTN_0_GPIO,BTN_0_BIT)==1)
		{
		    if(gau8str_SaveStatus[0].pushButton_saved_status==0)
			{
			    gau8str_SaveStatus[0].pushButton_status_btn=Released;
			    gau8str_SaveStatus[0].pushButton_saved_status=1;
			}
		    else if(gau8str_SaveStatus[0].pushButton_saved_status==1)
			{
			    gau8str_SaveStatus[0].pushButton_status_btn=Prepressed;
			    gau8str_SaveStatus[0].pushButton_saved_status=2;
			}
		    else if(gau8str_SaveStatus[0].pushButton_saved_status==2)
			{
			    gau8str_SaveStatus[0].pushButton_status_btn=Pressed;
			    gau8str_SaveStatus[0].pushButton_saved_status=3;
			}
		}

	    else if(gpioPinRead(BTN_0_GPIO,BTN_0_BIT)==0)
		{
		    if(gau8str_SaveStatus[0].pushButton_saved_status==3)
			{
			    gau8str_SaveStatus[0].pushButton_status_btn=Prereleased;
			    gau8str_SaveStatus[0].pushButton_saved_status=2;
			}
		    else if(gau8str_SaveStatus[0].pushButton_saved_status==2)
			{
			    gau8str_SaveStatus[0].pushButton_status_btn=Released;
			    gau8str_SaveStatus[0].pushButton_saved_status=1;
			}
		    else if(gau8str_SaveStatus[0].pushButton_saved_status==1)
			{
			    gau8str_SaveStatus[0].pushButton_status_btn=Released;
			    gau8str_SaveStatus[0].pushButton_saved_status=0;
			}
		}
	}




    if(gpioPinRead(BTN_1_GPIO,BTN_1_BIT)==1 || gpioPinRead(BTN_1_GPIO,BTN_1_BIT)==0)
    	{
    	    if(gpioPinRead(BTN_1_GPIO,BTN_1_BIT)==1)
    		{
    		    if(gau8str_SaveStatus[1].pushButton_saved_status==0)
    			{
    			    gau8str_SaveStatus[1].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[1].pushButton_saved_status=1;
    			}
    		    else if(gau8str_SaveStatus[1].pushButton_saved_status==1)
    			{
    			    gau8str_SaveStatus[1].pushButton_status_btn=Prepressed;
    			    gau8str_SaveStatus[1].pushButton_saved_status=2;
    			}
    		    else if(gau8str_SaveStatus[1].pushButton_saved_status==2)
    			{
    			    gau8str_SaveStatus[1].pushButton_status_btn=Pressed;
    			    gau8str_SaveStatus[1].pushButton_saved_status=3;
    			}
    		}

    	    else if(gpioPinRead(BTN_1_GPIO,BTN_1_BIT)==0)
    		{
    		    if(gau8str_SaveStatus[1].pushButton_saved_status==3)
    			{
    			    gau8str_SaveStatus[1].pushButton_status_btn=Prereleased;
    			    gau8str_SaveStatus[1].pushButton_saved_status=2;
    			}
    		    else if(gau8str_SaveStatus[1].pushButton_saved_status==2)
    			{
    			    gau8str_SaveStatus[1].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[1].pushButton_saved_status=1;
    			}
    		    else if(gau8str_SaveStatus[1].pushButton_saved_status==1)
    			{
    			    gau8str_SaveStatus[1].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[1].pushButton_saved_status=0;
    			}
    		}
    	}




    if(gpioPinRead(BTN_2_GPIO,BTN_2_BIT)==1 || gpioPinRead(BTN_2_GPIO,BTN_2_BIT)==0)
    	{
    	    if(gpioPinRead(BTN_2_GPIO,BTN_2_BIT)==1)
    		{
    		    if(gau8str_SaveStatus[2].pushButton_saved_status==0)
    			{
    			    gau8str_SaveStatus[2].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[2].pushButton_saved_status=1;
    			}
    		    else if(gau8str_SaveStatus[2].pushButton_saved_status==1)
    			{
    			    gau8str_SaveStatus[2].pushButton_status_btn=Prepressed;
    			    gau8str_SaveStatus[2].pushButton_saved_status=2;
    			}
    		    else if(gau8str_SaveStatus[2].pushButton_saved_status==2)
    			{
    			    gau8str_SaveStatus[2].pushButton_status_btn=Pressed;
    			    gau8str_SaveStatus[2].pushButton_saved_status=3;
    			}
    		}

    	    else if(gpioPinRead(BTN_2_GPIO,BTN_2_BIT)==0)
    		{
    		    if(gau8str_SaveStatus[2].pushButton_saved_status==3)
    			{
    			    gau8str_SaveStatus[2].pushButton_status_btn=Prereleased;
    			    gau8str_SaveStatus[2].pushButton_saved_status=2;
    			}
    		    else if(gau8str_SaveStatus[2].pushButton_saved_status==2)
    			{
    			    gau8str_SaveStatus[2].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[2].pushButton_saved_status=1;
    			}
    		    else if(gau8str_SaveStatus[2].pushButton_saved_status==1)
    			{
    			    gau8str_SaveStatus[2].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[2].pushButton_saved_status=0;
    			}
    		}
    	}




    if(gpioPinRead(BTN_3_GPIO,BTN_3_BIT)==1 || gpioPinRead(BTN_3_GPIO,BTN_3_BIT)==0)
    	{
    	    if(gpioPinRead(BTN_3_GPIO,BTN_3_BIT)==1)
    		{
    		    if(gau8str_SaveStatus[3].pushButton_saved_status==0)
    			{
    			    gau8str_SaveStatus[3].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[3].pushButton_saved_status=1;
    			}
    		    else if(gau8str_SaveStatus[3].pushButton_saved_status==1)
    			{
    			    gau8str_SaveStatus[3].pushButton_status_btn=Prepressed;
    			    gau8str_SaveStatus[3].pushButton_saved_status=2;
    			}
    		    else if(gau8str_SaveStatus[3].pushButton_saved_status==2)
    			{
    			    gau8str_SaveStatus[3].pushButton_status_btn=Pressed;
    			    gau8str_SaveStatus[3].pushButton_saved_status=3;
    			}
    		}

    	    else if(gpioPinRead(BTN_3_GPIO,BTN_3_BIT)==0)
    		{
    		    if(gau8str_SaveStatus[3].pushButton_saved_status==3)
    			{
    			    gau8str_SaveStatus[3].pushButton_status_btn=Prereleased;
    			    gau8str_SaveStatus[3].pushButton_saved_status=2;
    			}
    		    else if(gau8str_SaveStatus[3].pushButton_saved_status==2)
    			{
    			    gau8str_SaveStatus[3].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[3].pushButton_saved_status=1;
    			}
    		    else if(gau8str_SaveStatus[3].pushButton_saved_status==1)
    			{
    			    gau8str_SaveStatus[3].pushButton_status_btn=Released;
    			    gau8str_SaveStatus[3].pushButton_saved_status=0;
    			}
    		}
    	}

	timer2Delay_ms(30);
	}
}

/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t pushButton_GetStatus(En_buttonId btn_id){

	uint8 u8_pushButton_GetStatus;
	    switch(btn_id)
		{
		    case BTN_0:
			u8_pushButton_GetStatus=gau8str_SaveStatus[0].pushButton_status_btn;
			break;

		    case BTN_1:
			u8_pushButton_GetStatus=gau8str_SaveStatus[1].pushButton_status_btn;
			break;

		    case BTN_2:
			u8_pushButton_GetStatus=gau8str_SaveStatus[2].pushButton_status_btn;
			break;

		    case BTN_3:
			u8_pushButton_GetStatus=gau8str_SaveStatus[2].pushButton_status_btn;
			break;
		}

	    return u8_pushButton_GetStatus;
}
