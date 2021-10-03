/*
 * UART.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Raneem
 */

#ifndef MCAL_UART_DRIVER_UART_H_
#define MCAL_UART_DRIVER_UART_H_

#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"


extern void USART_Init( void );
extern StdReturn USART_Transmit( unsigned int data );             // Sending Frames with 9 Data Bits
extern StdReturn USART_Receive(unsigned int *data );             //Receiving Frames with 9 Data Bits


#endif /* MCAL_UART_DRIVER_UART_H_ */
