/*
 * SPI.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Raneem
 */
#include "SPI.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../Service/StdMacros.h"
#include "../MCAL/Ext_Interrupt/Ext_Interrupt.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../Controller/ATMEGA32/Registers.h"

//Initialize the SPI module
void SPI_init(void)
{

	SET_BIT(SPCR, SPE);                 //ENABLE SPI

//Select SCK frequency if SPI2X is 0
#if defined(SCK_FREQ_Fosc_4)
                                       //NOTHING TO DO
#elif defined(SCK_FREQ_Fosc_16)
	SET_BIT(SPCR, SPR0);	          //SELECT SCK FREQ FOSC_16
#elif defined(SCK_FREQ_Fosc_64)
	SET_BIT(SPCR, SPR1);	          //SELECT SCK FREQ FOSC_64
#elif defined(SCK_FREQ_Fosc_128)
	SET_BIT(SPCR, SPR0);	          //SELECT SCK FREQ FOSC_128
	SET_BIT(SPCR, SPR1);	          //SELECT SCK FREQ FOSC_128
#endif

//Select SCK frequency if SPI2X is 1
#if defined(SCK_FREQ_Fosc_2)
                                       //NOTHING TO DO
#elif defined(SCK_FREQ_Fosc_8)
	SET_BIT(SPCR, SPR0);	          //SELECT SCK FREQ FOSC_8
#elif defined(SCK_FREQ_Fosc_32)
	SET_BIT(SPCR, SPR1);	          //SELECT SCK FREQ FOSC_32
#elif defined(SCK_FREQ_Fosc_64)
	SET_BIT(SPCR, SPR0);	          //SELECT SCK FREQ FOSC_64
	SET_BIT(SPCR, SPR1);	          //SELECT SCK FREQ FOSC_64
#endif
}

//ENABLE & DISABLE OF THE INTERRUPTS FOR THE SPI
StdReturn SPI_SetInterrupt(SPI_enuInterruptState state) {
	switch (state) {
	case SPI_INTERRUPT_ENABLE:
		//Enable SPI interrupt
		SET_BIT(SPCR, SPIE);
		break;
	case SPI_INTERRUPT_DISABLE:
		//Disable SPI interrupt
		CLEAR_BIT(SPCR, SPIE);
		break;
	default:
		return E_NOK;
	}
	return E_OK;
}

//SELECT SPI MODE MASTER OR SLAVE
StdReturn SPI_Modes_Selection(SPI_enuMODES Modes)
{
	switch (Modes) {
	case SPI_MASTER:
		SET_BIT(SPCR, MSTR);	                                 //ENABLE MASTER
		GPIO_setPinDirection(MOSI_PORT, MOSI_PIN, GPIO_OUTPUT);	//SET MOSI PIN AS OUTPUT
		GPIO_setPinDirection(SCK_PORT, SCK_PIN, GPIO_OUTPUT);	//SET SCK PIN AS OUTPUT
		GPIO_setPinDirection(SS_PORT, SS_PIN, GPIO_OUTPUT);		//SET SS PIN AS OUTPUT
		break;
	case SPI_SLAVE:
		CLEAR_BIT(SPCR, MSTR);	                                 //ENABLE SLAVE
		GPIO_setPinDirection(MISO_PORT, MISO_PIN, GPIO_OUTPUT);	 //SET MISO PIN AS OUTPUT
		break;
	default:
		return E_NOK;
	}
	return E_OK;
}

StdReturn SPI_DataTransmit(unsigned char Data)
{
	GPIO_writePin(SS_PORT, SS_PIN, GPIO_LOW);                       //ENABLE SLAVE
	SPDR = Data;                                                   // START TRANSMISSION
// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
	GPIO_writePin(SS_PORT, SS_PIN, GPIO_HIGH);                    //DISABLE SLAVE
	return E_OK;

}
//SPI_receiveChar
StdReturn SPI_ReceiveData(unsigned char *Data)
{
	//Check the flag
	while (!READ_BIT(SPSR, SPIF));
	*Data = SPDR;                                   //Return the received data

	return E_OK;
}








