#include "STD_TYPES.h"

#include <util/delay.h>
#include "PORT_interface.h"

#include "KPD_interface.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "SPI_interface.h"

void tempreture(void);

int main()
{
	u8 data , x;
	u16 read_adc;
	f16 analog_volt;


	PORT_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	SPI_voidInitSlave();

	while(1)
	{
		data = SPI_u8TransmiterRreciever(10);

		while(data == '1')
		{
			tempreture();
		}
	}

	return 0;
}
void tempreture(void)
{
	u8 result1 , result2;
	u16 Digital_value;
	u8 Tempreture_u8_Out;
	f16 Analog_value;

	Digital_value = ADC_u16GetChannelReading(ADC1); // digital value
	Analog_value = 5.0 * ( (f16) Digital_value / 1023.0);   // analog  value
	Tempreture_u8_Out = Analog_value * 1000 / 10;

	result1 = Tempreture_u8_Out / 10; // write left lcd
	result2 = Tempreture_u8_Out % 10; // write right lcd

	LCD_voidClear();
	LCD_voidSetCursor(0,2);
	LCD_voidSendString("Tempreture");
	LCD_voidSetCursor(1,5);
	LCD_voidSendData(result1+'0');
	LCD_voidSendData(result2+'0');
	_delay_ms(500);
	LCD_voidClear();

	if(Tempreture_u8_Out >= 24)
	{
		DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN0 , DIO_u8PIN_HIGH);
		DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8PIN_LOW);


	}
	else if(Tempreture_u8_Out < 24)
	{
		DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN0 , DIO_u8PIN_LOW);
		DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8PIN_HIGH);
	}


}
