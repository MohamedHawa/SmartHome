#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_regester.h"
#include "PORT_interface.h"
#include "PORT_private.h"

#include "BIT_MATH.h"

void PORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;

	PORTA = PORTA_INIT;
	PORTB = PORTB_INIT;
	PORTC = PORTC_INIT;
	PORTD = PORTD_INIT;

}
