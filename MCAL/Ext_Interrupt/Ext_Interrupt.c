/*
 ============================================================================
 Name        : Ext_Interrupt.c
 Author      : Raneem Khaled
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 28/07/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : Source code of External interrupts Driver
 ============================================================================
 */

/***************************************************************
 *********************Includes section************************
 **************************************************************/
#include "Ext_Interrupt.h"


/***************************************************************
 *********************Private data section**********************
 **************************************************************/
static void (*user_func0)(void);
static void (*user_func1)(void);
static void (*user_func2)(void);


/***************************************************************
 ***************Functions implementation section****************
 **************************************************************/
//ISR for the external interrupt 0
ISR( INT0_vect) {
	(*user_func0)();
}

//ISR for the external interrupt 1
ISR( INT1_vect) {
	(*user_func1)();
}

//ISR for the external interrupt 2
ISR( INT2_vect) {
	(*user_func2)();
}

//Initialize external interrupt 0
StdReturn extInt0_init(extInt_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;

	//Enable external interrupt 0 mask
	SET_BIT(GICR, INT0);
  
	//Configure sense control
	switch (senseLevel) {
	case EXTINT_RISING_EDGE:		//Rising edge causes interrupt
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;
	case EXTINT_FALLING_EDGE:		//Falling edge causes interrupt
		SET_BIT(MCUCR, ISC01);
		CLEAR_BIT(MCUCR, ISC00);
		break;
	default:						//Wrong configuration is sent
		return_Loc = E_NOK;
		break;
	}
	//Return API status
	return return_Loc;
}

//Set the user function to be executed on ISR
StdReturn extInt0_callback(void (*func_ptr)(void)) {
	user_func0 = func_ptr;
	return E_OK;
}

// Implement the rest of the functions form Ext_Interrupt.h
StdReturn extInt1_init(extInt_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;


	SET_BIT(GICR, INT1);


	switch (senseLevel) {
	case EXTINT_RISING_EDGE:
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;
	case EXTINT_FALLING_EDGE:
		SET_BIT(MCUCR, ISC01);
		CLEAR_BIT(MCUCR, ISC00);
		break;
	default:
		return_Loc = E_NOK;
		break;
	}

	return return_Loc;
}

StdReturn extInt1_callback(void (*func_ptr)(void)) {
	user_func1 = func_ptr;
	return E_OK;
}
StdReturn extInt2_init(extInt_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;


	SET_BIT(GICR, INT2);


	switch (senseLevel) {
	case EXTINT_RISING_EDGE:
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;
	case EXTINT_FALLING_EDGE:
		SET_BIT(MCUCR, ISC01);
		CLEAR_BIT(MCUCR, ISC00);
		break;
	default:
		return_Loc = E_NOK;
		break;
	}

	return return_Loc;
}

StdReturn extInt2_callback(void (*func_ptr)(void)) {
	user_func2 = func_ptr;
	return E_OK;
}

