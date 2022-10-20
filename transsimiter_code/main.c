#include "STD_TYPES.h"

#include <util/delay.h>
#include "PORT_interface.h"

#include "KPD_interface.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "SPI_interface.h"



void MOTOR_CW(void);
void MOTOR_CCW(void);
void MOTOR_STOP(void);

void BUZZER_ON(void);
void BUZZER_OFF(void);

void PASSWORD_RIGHT(void);
void PASSWORD_Wrong(void);
void PASSWORD_WRONG_3_TRY(void);
void NAMES(void);

int main()
{
	u8 key;
	u8 counter1;
	u8 try;
	u8 counter = 0;
	u8 flag;
	u8 Permenent_u8Password[] = {'7','8','9','0'};
	u8 Password_u8FromUser[4];

	PORT_voidInit();
	LCD_voidInit();
	SPI_voidInitMaster();
	NAMES();

	while(1)
	{

		for(try = 0 ; try < 3 ; try++)
		{
			flag = 0;

			LCD_voidClear();
			LCD_voidSendString("enter password");

			// get password from the user and store it
			for(counter1 = 0 ; counter1 < 4 ; counter1++)
			{
				do
				{
					key = KPD_u8GetPressedKey();
				}while(key == 0xff);

				Password_u8FromUser[counter1] = key;
				LCD_voidSetCursor(1,counter1);
				LCD_voidSendData('*');
			}

			for(counter1 = 0 ; counter1 < 4 ; counter1++)
			{
				if( Password_u8FromUser[counter1]==Permenent_u8Password[counter1])
				{
					flag++;
				}
				else
				{
					break;
				}
			}

			if(flag == 4)
			{
				PASSWORD_RIGHT();
				break;
			}
			else
			{
				PASSWORD_Wrong();
				counter++;
			}
		}

		if(counter == 3)
		{
			PASSWORD_WRONG_3_TRY();
			counter = 0;
		}

	}

	return 0;
}

void MOTOR_CW(void)
{
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN0 , DIO_u8PIN_HIGH);
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8PIN_LOW);
}
void MOTOR_CCW(void)
{
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN0 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8PIN_HIGH);
}
void MOTOR_STOP(void)
{
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN0 , DIO_u8PIN_LOW);
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN1 , DIO_u8PIN_LOW);
}
void BUZZER_ON(void)
{
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8PIN_HIGH);
}
void BUZZER_OFF(void)
{
	DIO_voidSetPinValue(DIO_u8PORTB , DIO_u8PIN2 , DIO_u8PIN_LOW);
}

void PASSWORD_RIGHT(void)
{
	LCD_voidSetCursor(1,0);
	LCD_voidSendString("Welcome");
	_delay_ms(1000);

	LCD_voidClear();
	LCD_voidSendString("Door opening");

	MOTOR_CW();
	_delay_ms(3000);
	MOTOR_STOP();

	LCD_voidClear();
	LCD_voidSendString("Door open");

	SPI_u8TransmiterRreciever('1');

	_delay_ms(1000);

	LCD_voidClear();
	LCD_voidSendString("Door will close");
	_delay_ms(1000);

	LCD_voidClear();
	LCD_voidSendString("Door closing");

	MOTOR_CCW();
	_delay_ms(3000);

	LCD_voidClear();
	LCD_voidSendString("Door closed");
	MOTOR_STOP();

}
void PASSWORD_Wrong(void)
{

	LCD_voidSetCursor(1,0);
	LCD_voidSendString("wrong?");

	BUZZER_ON();
	_delay_ms(1000);
	BUZZER_OFF();

	LCD_voidClear();
}
void PASSWORD_WRONG_3_TRY(void)
{
	LCD_voidClear();
	LCD_voidSendString("doesn't owner");

	LCD_voidSetCursor(1,0);
	LCD_voidSendString("waiting 5 sec");

	BUZZER_ON();
	_delay_ms(5000);
	BUZZER_OFF();

	LCD_voidClear();
}
void NAMES(void)
{
	LCD_voidSetCursor(0,5);
	LCD_voidSendString("Hello");

	LCD_voidSetCursor(1,4);
	LCD_voidSendString("abdallah");
	_delay_ms(1000);

	LCD_voidClear();
	LCD_voidSetCursor(0,5);
	LCD_voidSendString("Hello");

	LCD_voidSetCursor(1,6);
	LCD_voidSendString("amr");
	_delay_ms(1000);

	LCD_voidClear();
	LCD_voidSetCursor(0,5);
	LCD_voidSendString("Hello");

	LCD_voidSetCursor(1,4);
	LCD_voidSendString("mohamed");
	_delay_ms(1000);

	LCD_voidClear();
	LCD_voidSetCursor(0,3);
	LCD_voidSendString("Waiting ...");
	_delay_ms(1000);

	LCD_voidClear();
}


