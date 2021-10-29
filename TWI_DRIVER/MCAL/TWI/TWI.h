/*
 * ic_square.h
 *
 *  Created on: Oct 21, 2021
 *      Author: Raneem
 */

#ifndef MCAL_TWI_TWI_H_
#define MCAL_TWI_TWI_H_

#include "../../Service/StdMacros.h"
#include "../GPIO/GPIO.h"
#include "../Ext_Interrupt/Ext_Interrupt.h"
#include "../../Service/StdTypes.h"
#include "../../controller/Atmega32/Registers.h"
#include "../../controller/Atmega32/Interrupts.h"

// DATA SELECTION
typedef enum{
	TWI_INTERRUPT_ENABLE,
	TWI_INTERRUPT_DISABLE
}TWI_enuInterruptState;

typedef enum{
	TWI_MASTER,
	TWI_SLAVE
}TWI_enuMODES;

//TWI_Acknowledge_Bit_Mode
typedef enum{
	TWI_Ack_connected,
	TWI_Ack_disconnected
};

//Initialize the TWI
 void TWI_Init(void);
 extern StdReturn TWI_Transmit( unsigned int data );
 extern StdReturn TWI_Receive(unsigned int *data );
 extern StdReturn TWI_Acknowledge_Bit_Mode(unsigned int Mode);
 extern StdReturn TWI_SetInterrupt(TWI_enuInterruptState State);
 void TWI_Call_Recognition_Enable();
#endif /* MCAL_TWI_TWI_H_ */
