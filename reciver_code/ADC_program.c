/*

 * ADC_program.c
 *
 *  Created on: Aug 29, 2022
 *      Author: abdul
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "DIO_interface.h"

void ADC_voidInit(void)
{
	/*AREF as a reference voltage*/
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*Activate left adjust result*/
	CLR_BIT(ADMUX , ADMUX_ADLAR);            // modify here

	/*Set Prescaler to divide by 128*/
	SET_BIT(ADCSRA , ADCSRA_ADPS0);
	SET_BIT(ADCSRA , ADCSRA_ADPS1);
	SET_BIT(ADCSRA , ADCSRA_ADPS2);


	/*Enable ADC peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}

u16 ADC_u16GetChannelReading(u8 Copy_u8Channel)
{

	/*Determining the channel*/
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;

	/* Start conversion*/
	SET_BIT(ADCSRA , ADCSRA_ADSC);
	while(!GET_BIT(ADCSRA , ADCSRA_ADIF));       // Waiting to complete the conversion
	SET_BIT(ADCSRA , ADCSRA_ADIF);				 // To clear the flag


	return ADC;
}




