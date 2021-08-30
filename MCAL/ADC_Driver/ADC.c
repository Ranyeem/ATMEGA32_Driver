/*
 * ADC.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Raneem
 */
//changeable
static void(*user_func)(void);
#include "ADC.h"
// voltage selecting
#if defined AREF_INTERNAL_VREF
#define VREF 2.56
#elif defined AREF_EXTERNAL_VREF
#define VREF 5.0
#endif

//Selecting Resolution
#if defined (ADC_Resolution_8BIT)
#define ADC_MAX 256
#elif defined (ADC_Resolution_10BIT)
#define ADC_MAX 1024
#endif

void ADC_init()
{
//ENABLE ADC
SET_BIT(ADCSRA, ADEN);

#if defined (ADC_Resolution_8BIT)
SET_BIT(ADMUX, ADLAR);
	#endif
// SELECT VREF
#if defined (AREF_INTERNAL_VREF)
SET_BIT(ADMUX,REFS0);
SET_BIT(ADMUX,REFS1);
#elif defined (AREF_EXTERNAL_VREF)
CLEAR_BIT(ADMUX, REFS1);
SET_BIT(ADMUX,REFS0);
#endif

//select the ADC Pre_scaler
#if defined (ADC_PRESCALER_2)
CLEAR_BIT(ADCSRA, ADPS0);
#elif defined (ADC_PRESCALER_4)
SET_BIT(ADCSRA, ADPS1);
#elif defined (ADC_PRESCALER_8)
SET_BIT(ADCSRA, ADPS1);
SET_BIT(ADCSRA, ADPS0);
#elif defined (ADC_PRESCALER_16)
SET_BIT(ADCSRA, ADPS2);
#elif defined (ADC_PRESCALER_32)
SET_BIT(ADCSRA, ADPS0);
SET_BIT(ADCSRA, ADPS2);
#elif defined (ADC_PRESCALER_64)
SET_BIT(ADCSRA, ADPS1);
SET_BIT(ADCSRA, ADPS2);
#elif defined (ADC_PRESCALER_128)
SET_BIT(ADCSRA, ADPS0);
SET_BIT(ADCSRA, ADPS1);
SET_BIT(ADCSRA, ADPS2);
#endif

}

StdReturn ADC_SetInterrupt_Enable(ADC_enumINT_State_t state)
{
switch (state)
{
    case ADC_INT_ENABLE:
	SET_BIT(ADCSRA, ADIE);
    break;

    case ADC_INT_DISABLE:
    CLEAR_BIT(ADCSRA, ADIE);
    break;

    default:
    return E_NOK ;

}
    return E_OK;
}
void ADC_callback(void(*func_ptr)(void))
{
user_func=func_ptr;
}

ISR(ADC_vect)
{
	(*user_func)();
}

StdReturn ADC_Start_Conversion(uint8 channel)
{
	//еб ЗдК ЪИннннннннннннннннннннШї
      if(channel>7)
      {
    	 return E_NOK;
      }
      else
      {
    	  ADMUX &=CHANNELS_UNSELECT_MASK;
          ADMUX |=channel;
    	  SET_BIT(ADCSRA, ADSC);
      }

      while(!(ADCSRA &(1<<ADIF)));
      return E_NOK;

}

StdReturn ADC_Getvalue(uint32 adcresult)
{
	uint16 adcval_temp;
    #if defined (ADC_RESOLUTION_8BIT)
    adcresult = ADCH;
	#elif defined (ADC_RESOLUTION_10BIT)
    adcval_temp =ADCL + (ADCH<<8);
    //mask the upper bits of ADCH 10 bit of 16 bit of ADC results
    *adcresult =adcval_temp & ADC_10_BIT_MASK
    #endif
    return E_NOK;
}

StdReturn ADC_Read_Value(uint8 channel,uint16 *adcvalue)
{
	//еб ЗдК ЪИннннннннннннннннннннШї
	      if(channel>7)
	      {
	    	 return E_NOK;
	      }
	      else
	      {
	    	  ADMUX &=CHANNELS_UNSELECT_MASK;
	          ADMUX |=channel;
	    	  SET_BIT(ADCSRA, ADSC);
	      }

	      while(!(ADCSRA &(1<<ADIF)));
	      return E_NOK;
	      {
	          #if defined (ADC_RESOLUTION_8BIT)
	          adcresult = ADCH;
	         READ_BIT(ADMUX, ADLAR);
	      	#elif defined (ADC_RESOLUTION_10BIT)
	          adcval_local =ADCL + (ADCH<<8);
	         READ_BIT(ADMUX, ADLAR);
	          *adcresult =adcval_local& ADC_10_BIT_MASK
	          #endif
	          return E_NOK;
	      }

}
StdReturn ADC_Read_volts(uint8 channel , f32 *adcvolt)
{
	uint16 adcval_temp=0;
	//еб ЗдК ЪИннннннннннннннннннннШї
	     if(channel>7)
	      {
	    	 return E_NOK;
	      }
	      else
	      {
	    	  ADC_READ_VALUE(channel,&adcvolt);
	    	  *adcvolt=((f32)adcval_temp*(f32)VREF)/((f32)ADC_MAX);
	      }

	         return E_NOK;

}






