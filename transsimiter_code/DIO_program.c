
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_interface.h"


void DIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	if (Copy_u8Value == DIO_u8PIN_LOW)
	{
		switch ( Copy_u8Port )
		{
		case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);
		break;
		case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);
		break;
		case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);
		break;
		case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);
		break;
		}
	}
	else if (Copy_u8Value == DIO_u8PIN_HIGH)
	{
		switch ( Copy_u8Port )
		{
		case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin);
		break;
		case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);
		break;
		case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);
		break;
		case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);
		break;
		}
	}
}

void DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	switch ( Copy_u8Port )
	{
	case DIO_u8PORTA : PORTA = Copy_u8Value;
	break;
	case DIO_u8PORTB : PORTB = Copy_u8Value;
	break;
	case DIO_u8PORTC : PORTC = Copy_u8Value;
	break;
	case DIO_u8PORTD : PORTD = Copy_u8Value;
	break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8PinValue ;

	switch ( Copy_u8Port )
	{
	case DIO_u8PORTA : Local_u8PinValue = GET_BIT(PINA,Copy_u8Pin);
	break;
	case DIO_u8PORTB : Local_u8PinValue = GET_BIT(PINB,Copy_u8Pin);
	break;
	case DIO_u8PORTC : Local_u8PinValue = GET_BIT(PINC,Copy_u8Pin);
	break;
	case DIO_u8PORTD : Local_u8PinValue = GET_BIT(PIND,Copy_u8Pin);
	break;
	}

	return Local_u8PinValue;
}
