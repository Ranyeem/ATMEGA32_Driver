/*
 * SPI.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Raneem
 */

#ifndef SPI_H_
#define SPI_H_

#define SPCR           //SPI Control Register
#define SPE            //SPI ENABLE PIN
#define SPIE           //SPI INTERRUPTS ENABLE PIN
#define MSTR
#define SPSR           //SPI Status Register
#define SPIF           //SPI Interrupt Flag
#define SPDR           //SPI Data Register


#include "Service/StdMacros.h"
#include "MCAL/Ext_Interrupt.h"
#include "MCAL/GPIO/GPIO.h"


// DATA SELECTION
typedef enum{
	SPI_INTERRUPT_ENABLE,
	SPI_INTERRUPT_DISABLE
}SPI_enuInterruptState;

typedef enum{
	SPI_MASTER,
	SPI_SLAVE
}SPI_enuMODES;

// SCK Frequency
// if SPI2X IS 0
//#define	SCK_FREQ_FOSC_4		                    //SCK frequency FOSC_4
#define	SCK_FREQ_FOSC_16	                        //SCK frequency FOSC_16
//#define	SCK_FREQ_FOSC_64	                    //SCK frequency FOSC_64
//#define	SCK_FREQ_FOSC_128	                    //SCK frequency FOSC_128

// if SPI2X IS 1
//#define	SCK_FREQ_FOSC_2		                    //SCK frequency FOSC_2
//#define	SCK_FREQ_FOSC_8                       //SCK frequency FOSC_8
//#define	SCK_FREQ_FOSC_32	                    //SCK frequency FOSC_32
//#define	SCK_FREQ_FOSC_64	                    //SCK frequency FOSC_64



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
extern void SPI_init(void);
//Enables/Disables the interrupt for the SPI
extern StdReturn SPI_SetInterrupt(SPI_enuInterruptState state);
//Modes of SPI master and slave
extern StdReturn SPI_ModeS_Selection(SPI_enuMODES mode);
// transmit SPI data
extern StdReturn SPI_DataTransmit(unsigned char Data);
// Receive SPI data
extern StdReturn SPI_ReceiveData(unsigned char *Data);


#endif /* SPI_H_ */
