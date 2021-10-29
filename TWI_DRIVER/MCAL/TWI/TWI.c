/*
 * ic_square.c
 *
 *  Created on: Oct 21, 2021
 *      Author: Raneem
 */


#include "TWI.h"
#include "../../controller/Atmega32/Registers.h"


//Control registers TWCR

//Enable TWI
void TWI_Init()
{
	SET_BIT(TWCR,TWEN);
}

StdReturn TWI_Acknowledge_Bit_Mode(unsigned int Mode)
{
	switch(Mode)
	{
	case TWI_Ack_connected:
		SET_BIT(TWCR,TWEA);
	break;

	case TWI_Ack_disconnected:
		CLEAR_BIT(TWCR,TWEA);
	break;

	default:
	    return E_NOK;

	}
	return E_OK;
}

//ENABLE & DISABLE OF THE INTERRUPTS FOR THE TWI
StdReturn TWI_SetInterrupt(TWI_enuInterruptState State)
{
  switch (State) {
  case TWI_INTERRUPT_ENABLE:
    //Enable TWI interrupt
    SET_BIT(TWCR, TWIE);
    break;
  case TWI_INTERRUPT_DISABLE:
    //Disable TWI interrupt
    CLEAR_BIT(TWCR, TWIE);
    break;
  default:
    return E_NOK;
  }
  return E_OK;
}


//select the TWI Pre_scaler
#if defined (TWI_PRESCALER_1)
CLEAR_BIT(TWSR, TWPS0);
CLEAR_BIT(TWSR, TWPS1);
#elif defined (TWI_PRESCALER_4)
SET_BIT(TWSR, TWPS0);
CLEAR_BIT(TWSR, TWPS1);
#elif defined (TWI_PRESCALER_16)
CLEAR_BIT(TWSR, TWPS0);
SET_BIT(TWSR, TWPS1);
#elif defined (TWI_PRESCALER_64)
SET_BIT(TWSR, TWPS0);
SET_BIT(TWSR, TWPS1);
#endif

//slave register TWAR

void TWI_Call_Recognition_Enable()
{
	SET_BIT(TWAR,TWGCE);   //Enables the recognition of a General Call
}


