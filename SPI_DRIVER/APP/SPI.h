/*
 * SPI.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Raneem
 */

#ifndef SPI_H_
#define SPI_H_

#include "../MCAL/GPIO/GPIO.h"
#include "../Service/StdMacros.h"
#include "../MCAL/Ext_Interrupt/Ext_Interrupt.h"


// DATA SELECTION
typedef enum{
	SPI_INTERRUPT_ENABLE,
	SPI_INTERRUPT_DISABLE
}SPI_enuInterruptState;

typedef enum{
	SPI_MASTER,
	SPI_SLAVE
}SPI_enuMODES;


//Define PINS
#define MOSI_PIN		 4
#define MISO_PIN	     5
#define SCK_PIN	         6
#define SS_PIN	       	 7

//Define PORTS
#define MOSI_PORT		GPIO_PORTB
#define MISO_PORT	    GPIO_PORTB
#define SCK_PORT	    GPIO_PORTB
#define SS_PORT	        GPIO_PORTB

// PROTOTYPES SELECTION
//Initialize the SPI module
 void SPI_init(void);
//Enables/Disables the interrupt for the SPI
extern StdReturn SPI_SetInterrupt(SPI_enuInterruptState state);
//Modes of SPI master and slave
extern StdReturn SPI_Modes_Selection(SPI_enuMODES Modes);
// transmit SPI data
extern StdReturn SPI_DataTransmit(unsigned char Data);
// Receive SPI data
extern StdReturn SPI_ReceiveData(unsigned char *Data);


#endif /* SPI_H_ */




