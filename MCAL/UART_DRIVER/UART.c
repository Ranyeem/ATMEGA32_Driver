/*
 * UART.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Raneem
 */

#include "UART.h"
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"

void USART_Init(  )
{
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, RXCIE);

	SET_BIT(UCSRC, URSEL);
	SET_BIT(UCSRC, UPM1);
	SET_BIT(UCSRC, UMSEL);

	UBRRL = 51;

}

StdReturn USART_Transmit( unsigned int data )
{
	while (READ_BIT(UCSRA, UDRE)==0 );

	UDR = data;
	return E_OK;

}

StdReturn USART_Receive(unsigned int *data )
{


	while(READ_BIT(UCSRA, RXC)==0);

	return E_OK;

	*data = UDR;
}






