/*
 * ADC_interface.h
 *
 *  Created on: Aug 29, 2022
 *      Author: abdul
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0		00000
#define ADC1		00001
#define ADC2		00010
#define ADC3		00011
#define ADC4		00100
#define ADC5		00101
#define ADC6		00110
#define ADC7		00111



void ADC_voidInit(void);

u16 ADC_u16GetChannelReading(u8 Copy_u8Channel);

#endif /* ADC_INTERFACE_H_ */
