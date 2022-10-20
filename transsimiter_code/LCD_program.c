#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_interface.h"

#include "PORT_config.h"
#include "PORT_regester.h"
#include "PORT_interface.h"
#include "PORT_private.h"

#include "LCD_config.h"
#include "LCD_interface.h"

#include <util/delay.h>

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*set RS pin  to command*/
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_RS_PIN , DIO_u8PIN_LOW);

	/*set RW pin  to Write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_RW_PIN , DIO_u8PIN_LOW);

	/*Send command*/
	DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Command);

	/*send pulse on enable pin	 */
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_u8PIN_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	/*set RS pin  to data*/
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_RS_PIN , DIO_u8PIN_HIGH);

	/*set RW pin  to Write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_RW_PIN , DIO_u8PIN_LOW);

	/*Send data*/
	DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Data);

	/*send pulse on enable pin	 */
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_u8PIN_LOW);
}

void LCD_voidInit(void)          /*look at datasheet*/
{
	_delay_ms(50);
	/*function set*/
	LCD_voidSendCommand(0b00111000);
	/*display on/off control*/
	LCD_voidSendCommand(0b00001110);
	/*display clear*/
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	/*entry mode set*/
	//LCD_voidSendCommand(0b00000110);

}

void LCD_voidSendString(u8 *Copy_u8String)
{
	while(*Copy_u8String != '\0')
	{
		LCD_voidSendData(*(Copy_u8String));
		Copy_u8String++;
	}
}
void LCD_voidClear(void)
{
	LCD_voidSendCommand(0b00000001);
}
void LCD_voidSetCursor(u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8Address = 0;
	if(0 == Copy_u8XPos)
	{
		Local_u8Address = Copy_u8YPos ;
	}
	else if(1 == Copy_u8XPos)
	{
		Local_u8Address = Copy_u8YPos + 0x40 ;
	}
	LCD_voidSendCommand(Local_u8Address + 128);          // 128 because the command has 1 on MSB

}







