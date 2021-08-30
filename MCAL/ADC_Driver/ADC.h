/*
 * ADC.h
 *
 *  Created on: Aug 26, 2021
 *      Author: Raneem
 */
//file guard
#ifndef ATMEGA32_DRIVER_MCAL_ADC_DRIVER_ADC_H_
#define ATMEGA32_DRIVER_MCAL_ADC_DRIVER_ADC_H_
//include

#include "../../Service/StdTypes.h"
#include "../../Service/StdMacros.h"
#include "../../controller/Atmega32/Registers.h"
#include "../../controller/Atmega32/Interrupts.h"
#define CHANNELS_UNSELECT_MASK    0xF8
#define ADC_10_BIT_MASK             0x3FF
typedef enum {
	ADC_INT_ENABLE ,
	ADC_INT_DISABLE
}ADC_enumINT_State_t;

// Function prototypes

extern void ADC_init();
extern StdReturn ADC_Start_Conversion(uint8 channel);
extern StdReturn ADC_Getvalue(uint32 adcresult);
extern StdReturn ADC_Read_Value(uint8 channel,uint16 *adcvalue);
extern StdReturn ADC_Read_volts();

extern StdReturn ADC_SetInterrupt_Enable(ADC_enumINT_State_t state);
extern void ADC_callback(void(*func_ptr)(void));


#endif /* ATMEGA32_DRIVER_MCAL_ADC_DRIVER_ADC_H_ */
