/*
 * timers.c
 *
 *  Created on: Dec 7, 2019
 *      Author: ahmed
 */


#include "timers.h"

static uint8 gu8_timer0Prescaler;
static uint8 gu8_timer1Prescaler;
static uint8 gu8_timer2Prescaler;

/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t mode,En_timer0OC_t OC0,En_timer0perscaler_t prescal, uint8 initialValue, uint8 outputCompare, En_timer0Interrupt_t interruptMask){

    TCCR0 = mode | OC0;

    gu8_timer0Prescaler=prescal;

    TCNT0 = initialValue;

    OCR0 = outputCompare;

    TIMSK|=interruptMask;
}

/**
 * Description:
 * @param value
 */
void timer0Set(uint8 value){

    TCNT0 = value;
}

/**
 * Description:
 * @return
 */
uint8 timer0Read(void){

    return TCNT0;
}

/**
 * Description:
 */
void timer0Start(void){

    TCCR0|=gu8_timer0Prescaler;
}

/**
 * Description:
 */
void timer0Stop(void){

    TCCR0|=T0_NO_CLOCK;

}

/**
 * Description:
 * @param delay
 */
void timer0Delay_ms(uint16 delay){

    uint8 u8_timerModeCheck = GET_BIT(TCCR0,BIT3);

    switch(u8_timerModeCheck)
	{

	    case 0: //Normal Mode

		TCCR0 |= T0_PRESCALER_64;

		uint16 u16_OverflowCounterNM=0; //Count number of overflows

		timer0Set(130); //130 to trick only 125 tricks for 1 overflow

		timer0Start();


		for(u16_OverflowCounterNM=0; u16_OverflowCounterNM<delay; u16_OverflowCounterNM++)
		    {
			while(((TIFR)&(1<<0))==0){};
			SET_BIT(TIFR,BIT0);
			timer0Set(130);
		    }
		timer0Stop();
		break;

	    case 1: //Compare Mode

		TCCR0 |= T0_PRESCALER_64;

		uint16 u16_OverflowCounterCM=0; //Count number of overflows

		uint8  u8_flagCheckCM; //Check overflow

		timer0Set(0); //0 to trick for compared value to check

		timer0Start();

		while(u16_OverflowCounterCM != (delay)) //check delay equal overflow
		    {
			u8_flagCheckCM=0;
			u8_flagCheckCM=GET_BIT(TIFR,BIT1); //store status of TOV0 flag

			if(u8_flagCheckCM==1)//check for overflow
			    {
				u16_OverflowCounterCM++; //increase overflow by 1 everytime
				SET_BIT(TIFR,BIT1);
			    }
		    }
		timer0Stop();
		break;
	}
}

/**
 * Description:
 * @param dutyCycle
 */
void timer0SwPWM(uint8 dutyCycle,uint8 freq){

    uint8 u8_TnctMAX = 8000000/(freq*1000);

    uint8 u8_TcntSTART = 255 - u8_TnctMAX;

    uint16 U8_OCR = ((dutyCycle * u8_TnctMAX)/100) - 1;

    TCNT0 = u8_TcntSTART;

    OCR0 = U8_OCR;

    Led_On(0);

    while(((TIFR)&(1<<1))==0){};

    SET_BIT(TIFR,BIT1);

    Led_Off(0);

    while(((TIFR)&(1<<0))==0){};

    SET_BIT(TIFR,BIT0);

}


/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t mode,En_timer1OC_t OC,En_timer1perscaler_t prescal, uint16 initialValue, uint16 outputCompareA, uint16 outputCompareB, uint16 inputCapture, En_timer1Interrupt_t interruptMask){

    TCCR1 = mode | OC;

    gu8_timer1Prescaler=prescal;

    TCNT1 = initialValue;

    OCR1A = outputCompareA;

    OCR1B = outputCompareB;

    ICR1 = inputCapture;

    TIMSK = interruptMask;


}

/**
 * Description:
 * @param value
 */
void timer1Set(uint16 value){

    TCNT1 = value;
}


/**
 * Description:
 * @return
 */
uint16 timer1Read(void){

    return TCNT1;
}



/**
 * Description:
 */
void timer1Start(void){

    TCCR1 |=gu8_timer1Prescaler;
}

/**
 * Description:
 */
void timer1Stop(void){

    TCCR1 = T1_NO_CLOCK;

}

/**
 * Description:
 * @param delay
 */
void timer1Delay_ms(uint16 delay){

		timer1Init(T1_NORMAL_MODE,T1_OC1_DIS,T1_PRESCALER_64,0,0,0,0,T1_POLLING);


    		uint32 u32_OverflowCounterNM=0; //Count number of overflows

    		timer1Set(65410); //65410 to trick only 125 tricks for 1 overflow

    		timer1Start();

		for(u32_OverflowCounterNM=0; u32_OverflowCounterNM<delay; u32_OverflowCounterNM++)
		    {
			while(((TIFR)&(1<<2))==0){};
			SET_BIT(TIFR,BIT2);
			timer1Set(65410);
		    }
    		timer1Stop();

}

/**
 * Description:
 * @param dutyCycle
 */
void timer1SwPWM(uint8 dutyCycle,uint8 freq){


    uint16 u16_TnctMAX = 8000000/(freq*1000);

    uint16 u16_TcntSTART = 65536 - u16_TnctMAX;

    uint16 U16_OCR = ((dutyCycle * u16_TnctMAX)/100) - 1;

    TCNT1 = u16_TcntSTART;

    OCR1A = U16_OCR;

    Led_On(0);

    while(((TIFR)&(1<<4))==0){};

    SET_BIT(TIFR,BIT4);

    Led_Off(0);

    while(((TIFR)&(1<<2))==0){};

    SET_BIT(TIFR,BIT2);
}





/*===========================Timer2 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer2Init(En_timer2Mode_t mode,En_timer2OC_t OC,En_timer2perscaler_t prescal, uint8 initialValue, uint8 outputCompare, uint8 assynchronous, En_timer2Interrupt_t interruptMask){

    TCCR2 = mode | OC;

    gu8_timer2Prescaler=prescal;

    TCNT2 = initialValue;

    OCR2 = outputCompare;

    TIMSK|=interruptMask;
}
/**
 * Description:
 * @param value
 */
void timer2Set(uint8 value){

    TCNT2 = value;
}

/**
 * Description:
 * @return
 */
uint8 timer2Read(void){

    return TCNT2;
}

/**
 * Description:
 */
void timer2Start(void){

    TCCR2 |= gu8_timer2Prescaler;
}

/**
 * Description:
 */
void timer2Stop(void){

    TCCR2 = T2_NO_CLOCK;
}

/**
 * Description:
 * @param delay
 */
void timer2Delay_ms(uint16 delay){

	TCCR2 |= T2_PRESCALER_64;

	uint16 u16_OverflowCounterNM=0; //Count number of overflows

	timer2Set(130); //5 to trick only 250 tricks for 1 overflow

	timer2Start();


	for(u16_OverflowCounterNM=0; u16_OverflowCounterNM<delay; u16_OverflowCounterNM++)
	    {
		while(((TIFR)&(1<<6))==0){};
		SET_BIT(TIFR,BIT6);
		timer2Set(130);
	    }
	timer2Stop();

}

/**
 * Description:
 * @param dutyCycle
 */
void timer2SwPWM(uint8 dutyCycle,uint8 freq){

	uint8 u8_TnctMAX = 8000000/(freq*1000);

       uint8 u8_TcntSTART = 255 - u8_TnctMAX;

       uint16 U8_OCR = ((dutyCycle * u8_TnctMAX)/100) - 1;

       TCNT2 = u8_TcntSTART;

       OCR2 = U8_OCR;

       Led_On(0);

       while(((TIFR)&(1<<7))==0){};

       SET_BIT(TIFR,BIT7);

       Led_Off(0);

       while(((TIFR)&(1<<6))==0){};

       SET_BIT(TIFR,BIT6);

}

/*
 * user defined
 */
void timer2Delay_us(uint32 delay){

	TCCR2 |= T2_PRESCALER_NO;

	uint16 u16_OverflowCounterNM=0; //Count number of overflows

	timer2Set(247); //247 to trick only 8 tricks for 1 overflow

	timer2Start();


	for(u16_OverflowCounterNM=0; u16_OverflowCounterNM<delay; u16_OverflowCounterNM++)
	    {
		while(((TIFR)&(1<<6))==0){};
		SET_BIT(TIFR,BIT6);
		timer2Set(247);
	    }
	timer2Stop();

}
