#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "PORT_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"



u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NO_PREESED;
	u8 Local_u8ColumnIdx , Local_u8RowIdx ;
	u8 Local_u8PinState ;   				  /* this variable used in if statements so i defined it */
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM] =  KPD_ARR_VAL;
	static u8 Local_u8KPDColumnArr[COLUMN_NUM] = {KPD_COLUMN0_PIN , KPD_COLUMN1_PIN , KPD_COLUMN2_PIN , KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[COLUMN_NUM] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
	/* static to prevent stack  overflow because the arrays have large size */
	for(Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx < COLUMN_NUM ; Local_u8ColumnIdx++)
	{
		DIO_voidSetPinValue(KPD_PORT , Local_u8KPDColumnArr[Local_u8ColumnIdx] , DIO_u8PIN_LOW );
		for(Local_u8RowIdx = 0 ; Local_u8RowIdx < ROW_NUM ; Local_u8RowIdx++)
		{
			Local_u8PinState = DIO_u8GetPinValue(KPD_PORT , Local_u8KPDRowArr[Local_u8RowIdx]);
			if(DIO_u8PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8ColumnIdx][Local_u8RowIdx];
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					Local_u8PinState = DIO_u8GetPinValue(KPD_PORT , Local_u8KPDRowArr[Local_u8RowIdx]);
				}
				DIO_voidSetPinValue(KPD_PORT , Local_u8KPDColumnArr[Local_u8ColumnIdx] , DIO_u8PIN_HIGH );
				return Local_u8PressedKey;
			}
		}
		DIO_voidSetPinValue(KPD_PORT , Local_u8KPDColumnArr[Local_u8ColumnIdx] , DIO_u8PIN_HIGH );
	}

	return Local_u8PressedKey;
}
