/*
 * gpio.c
 *
 *  Created on: Dec 3, 2019
 *      Author: ahmed
 */

#include "gpio.h"


/*===========================PORT Control===============================*/

/**
 * Description: set port direction (which is DDR register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param direction: set the port direction and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */
void gpioPortDirection(uint8 port, uint8 direction){

	switch (port)
	    {
		case GPIOA:
		    PORTA_DIR = direction;
		    break;

		case GPIOB:
		    PORTB_DIR= direction;
		    break;

		case GPIOC:
		    PORTC_DIR = direction;
		    break;

		case GPIOD:
		    PORTD_DIR = direction;
		    break;
	    }
}

/**
 * Description: set the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value: set the port value and takes the following values
 * 				- 0x00 -> Low
 * 				- 0xff -> High
 */
void gpioPortWrite(uint8 port, uint8 value){

	switch (port)
	    {
		case GPIOA:
		    PORTA_DATA = value;
		    break;

		case GPIOB:
		    PORTB_DATA = value;
		    break;

		case GPIOC:
		    PORTC_DATA = value;
		    break;

		case GPIOD:
		    PORTD_DATA = value;
		    break;
	    }
}

/**
 * Description: toggle the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 */
void gpioPortToggle(uint8 port){

	switch (port)
	    {
		case GPIOA:
		    PORTA_DATA ^=HIGH;
		    break;

		case GPIOB:
		    PORTB_DATA ^=HIGH;
		    break;

		case GPIOC:
		    PORTC_DATA ^=HIGH;
		    break;

		case GPIOD:
		    PORTD_DATA ^=HIGH;
		    break;
	    }
}

/**
 * Description: read the current port value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 gpioPortRead(uint8 port){

    uint8 u8_gpioPortRead_Value;
	switch (port)
	    {
		case GPIOA:
		    u8_gpioPortRead_Value = PORTA_PIN;
		    break;

		case GPIOB:
		    u8_gpioPortRead_Value = PORTA_PIN;
		    break;

		case GPIOC:
		    u8_gpioPortRead_Value = PORTA_PIN;
		    break;

		case GPIOD:
		    u8_gpioPortRead_Value = PORTA_PIN;
		    break;
	    }
	return u8_gpioPortRead_Value;
}


/*===========================PIN Control===============================*/

/**
 * Description: set selected pins (more than one pin [ORed]) direction
 *
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to set its direction and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 *
 * @param direction: set the pins direction and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */
void gpioPinDirection(uint8 port, uint8 pins, uint8 direction){

	switch(port)
	{
		    case GPIOA:
			if(direction==INPUT)
			    CLR_BIT(PORTA_DIR,pins);
			else
			    SET_BIT(PORTA_DIR,pins);
			break;

		    case GPIOB:
			if(direction==INPUT)
			    CLR_BIT(PORTB_DIR,pins);
			else
			    SET_BIT(PORTB_DIR,pins);
			break;

		    case GPIOC:
			if(direction==INPUT)
			    CLR_BIT(PORTC_DIR,pins);
			else
			    SET_BIT(PORTC_DIR,pins);
			break;

		    case GPIOD:
			if(direction==INPUT)
			    CLR_BIT(PORTD_DIR,pins);
			else
			    SET_BIT(PORTD_DIR,pins);
			break;
	}
}

/**
 * Description: set selected pins (more than one pin [ORed]) values
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to write its values and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @param value
 */
void gpioPinWrite(uint8 port, uint8 pins, uint8 value){

	switch(port)
	{
		    case GPIOA:
			if(value==LOW)
			    CLR_BIT(PORTA_DATA,pins);
			else
			    SET_BIT(PORTA_DATA,pins);
			break;

		    case GPIOB:
			if(value==LOW)
			    CLR_BIT(PORTB_DATA,pins);
			else
			    SET_BIT(PORTB_DATA,pins);
			break;

		    case GPIOC:
			if(value==LOW)
			    CLR_BIT(PORTC_DATA,pins);
			else
			    SET_BIT(PORTC_DATA,pins);
			break;

		    case GPIOD:
			if(value==LOW)
			    CLR_BIT(PORTD_DATA,pins);
			else
			    SET_BIT(PORTD_DATA,pins);
			break;
	}
}

/**
 * Description: toggle selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pin the user need to toggle it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 */
void gpioPinToggle(uint8 port, uint8 pins){

	switch (port)
	    {
		case GPIOA:
		    TOGGLE_BIT(PORTA_DATA,pins);
		    break;

		case GPIOB:
		    TOGGLE_BIT(PORTB_DATA,pins);
		    break;

		case GPIOC:
		    TOGGLE_BIT(PORTC_DATA,pins);
		    break;

		case GPIOD:
		    TOGGLE_BIT(PORTD_DATA,pins);
		    break;
	    }
}


/**
 * Description: read selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param pin: the selected pin the user need to read it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @return
 */
uint8 gpioPinRead(uint8 port, uint8 pin){

    uint8 u8_gpioPinRead_Value;
	switch (port)
	    {
		case GPIOA:
		    u8_gpioPinRead_Value = GET_BIT(PORTA_PIN,pin);
		    break;

		case GPIOB:
		    u8_gpioPinRead_Value = GET_BIT(PORTB_PIN,pin);
		    break;

		case GPIOC:
		    u8_gpioPinRead_Value = GET_BIT(PORTC_PIN,pin);
		    break;

		case GPIOD:
		    u8_gpioPinRead_Value = GET_BIT(PORTD_PIN,pin);
		    break;
	    }
	return u8_gpioPinRead_Value;
}

/*===========================Upper Nibble Control===============================*/

/**
 * Description: set the upper nibble direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param direction
 */
void gpioUpperNibbleDirection(uint8 port, uint8 direction){


	    switch(port)
		{
		    case GPIOA:
			if(direction==LOW)
			    PORTA_DIR&=(0x0F);
			else
			    PORTA_DIR|=(0xF0);
			break;

		    case GPIOB:
			if(direction==LOW)
			    PORTB_DIR&=(0x0F);
			else
			    PORTB_DIR|=(0xF0);
			break;

		    case GPIOC:
			if(direction==LOW)
			    PORTC_DIR&=(0x0F);
			else
			    PORTC_DIR|=(0xF0);
			break;

		    case GPIOD:
			if(direction==LOW)
			    PORTD_DIR&=(0x0F);
			else
			    PORTD_DIR|=(0xF0);
			break;
		}

}

/**
 * Description: write the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value
 */
void gpioUpperNibbleWrite(uint8 port, uint8 value){

    switch(port)
	{
	    case GPIOA:
		if(value==LOW)
		    PORTA_DATA = (PORTA_DATA & 0x0F);
		else
		    PORTA_DATA = (PORTA_DATA | 0xF0);
		break;

	    case GPIOB:
		if(value==LOW)
		    PORTB_DATA = (PORTB_DATA & 0x0F);
		else
		    PORTB_DATA = (PORTB_DATA | 0xF0);
		break;

	    case GPIOC:
		if(value==LOW)
		    PORTC_DATA = (PORTC_DATA & 0x0F);
		else
		    PORTC_DATA = (PORTC_DATA | 0xF0);
		break;

	    case GPIOD:
		if(value==LOW)
		    PORTD_DATA = (PORTD_DATA & 0x0F);
		else
		    PORTD_DATA = (PORTD_DATA | 0xF0);
		break;
	}

}

/**
 * Description: toggle the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 */
void gpioUpperNibbleToggle(uint8 port){

    switch(port)
	{
	    case GPIOA:
		PORTA_DATA = (PORTA_DATA ^ 0xF0);
		break;

	    case GPIOB:
		PORTB_DATA = (PORTB_DATA ^ 0xF0);
		break;

	    case GPIOC:
		PORTC_DATA = (PORTC_DATA ^ 0xF0);
		break;

	    case GPIOD:
		PORTD_DATA = (PORTD_DATA ^ 0xF0);
		break;
	}
}

/**
 * Description: read the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 gpioUpperNibbleRead(uint8 port){

    uint8 u8_gpioUpperNibbleRead_Value;
    switch(port)
	{
	    case GPIOA:
		u8_gpioUpperNibbleRead_Value=(PORTA_PIN & 0xF0);
		break;

	    case GPIOB:
		u8_gpioUpperNibbleRead_Value=(PORTB_PIN & 0xF0);
		break;

	    case GPIOC:
		u8_gpioUpperNibbleRead_Value=(PORTC_PIN & 0xF0);
		break;

	    case GPIOD:
		u8_gpioUpperNibbleRead_Value=(PORTD_PIN & 0xF0);
		break;
	}

    return u8_gpioUpperNibbleRead_Value;
}


/*===========================Lower Nibble Control===============================*/
/**
 * Description: set the lower nibble direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param direction
 */
void gpioLowerNibbleDirection(uint8 port, uint8 direction){


    switch(port)
	{
	    case GPIOA:
		if(direction==LOW)
		    PORTA_DIR&=(0xF0);
		else
		    PORTA_DIR|=(0x0F);
		break;

	    case GPIOB:
		if(direction==LOW)
		    PORTB_DIR&=(0xF0);
		else
		    PORTB_DIR|=(0x0F);
		break;

	    case GPIOC:
		if(direction==LOW)
		    PORTC_DIR&=(0xF0);
		else
		    PORTC_DIR|=(0x0F);
		break;

	    case GPIOD:
		if(direction==LOW)
		    PORTD_DIR&=(0xF0);
		else
		    PORTD_DIR|=(0x0F);
		break;
	}
}

/**
 * Description: write the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value
 */
void gpioLowerNibbleWrite(uint8 port, uint8 value){

    switch(port)
	{
	    case GPIOA:
		if(value==HIGH)
		    PORTA_DATA = (PORTA_DATA | 0x0F);
		else
		    PORTA_DATA = (PORTA_DATA & 0xF0);
		break;

	    case GPIOB:
		if(value==HIGH)
		    PORTB_DATA = (PORTB_DATA | 0x0F);
		else
		    PORTB_DATA = (PORTB_DATA & 0xF0);
		break;

	    case GPIOC:
		if(value==HIGH)
		    PORTC_DATA = (PORTC_DATA | 0x0F);
		else
		    PORTC_DATA = (PORTC_DATA & 0xF0);
		break;

	    case GPIOD:
		if(value==HIGH)
		    PORTD_DATA = (PORTD_DATA | 0x0F);
		else
		    PORTD_DATA = (PORTD_DATA & 0xF0);
		break;
	}


}


/**
 * Description: toggle the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 */
void gpioLowerNibbleToggle(uint8 port){


    switch(port)
	{
	    case GPIOA:
		PORTA_DATA = (PORTA_DATA ^ 0x0F);
		break;

	    case GPIOB:
		PORTB_DATA = (PORTB_DATA ^ 0x0F);
		break;

	    case GPIOC:
		PORTC_DATA = (PORTC_DATA ^ 0x0F);
		break;

	    case GPIOD:
		PORTD_DATA = (PORTD_DATA ^ 0x0F);
		break;
	}
}


/**
 * Description: read the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 gpioLowerNibbleRead(uint8 port){

    uint8 u8_gpioLowerNibbleRead_Value;
    switch(port)
	{
	    case GPIOA:
		u8_gpioLowerNibbleRead_Value=(PORTA_PIN & 0x0F);
		break;

	    case GPIOB:
		u8_gpioLowerNibbleRead_Value=(PORTB_PIN & 0x0F);
		break;

	    case GPIOC:
		u8_gpioLowerNibbleRead_Value=(PORTC_PIN & 0x0F);
		break;

	    case GPIOD:
		u8_gpioLowerNibbleRead_Value=(PORTD_PIN & 0x0F);
		break;
	}

    return u8_gpioLowerNibbleRead_Value;

}
