#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidInit(void);

void LCD_voidSendString(u8 *Copy_u8String);

void LCD_voidClear(void);

void LCD_voidSetCursor(u8 Copy_u8XPos , u8 Copy_u8YPos);

#endif
