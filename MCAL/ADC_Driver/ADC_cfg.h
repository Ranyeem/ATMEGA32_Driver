/*
 * ADC_cfg.h
 *
 *  Created on: Aug 30, 2021
 *      Author: Raneem
 */

#ifndef ATMEGA32_DRIVER_MCAL_ADC_DRIVER_ADC_CFG_H_
#define ATMEGA32_DRIVER_MCAL_ADC_DRIVER_ADC_CFG_H_



#endif /* ATMEGA32_DRIVER_MCAL_ADC_DRIVER_ADC_CFG_H_ */
#ifndef ADC_cfg.h
#define ADC_cfg.h

/*****ADC clock prescaler********/
//un_select the required prescaler
//#define PRESCALER_2
//#define PRESCALER_4
//#define PRESCALER_8
//#define PRESCALER_16
#define PRESCALER_32
//#define PRESCALER_64
//#define PRESCALER_128

/********ADC resolution**********/
//un_select the required resolution
//#define RESOLUTION_8BIT
#define RESOLUTION_10BIT

/********Aref source**********/
//un_select the required source of Aref
//#define AREF_INTERNAL_VOLTAGE   //internal 2.56 voltage source
#define AREF_EXTERNAL_AVCC        //EXTERNAL Avcc

#endif
