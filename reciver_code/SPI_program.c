/*

 * SPI_program.c
 *
 *  Created on: Sep 5, 2022
 *      Author: abdul
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_register.h"
#include "SPI_interface.h"

void SPI_voidInitMaster()
{
	/*set master*/
	SET_BIT(SPCR , SPCR_MSTR);

	/*set clock polarity (rising)*/
	CLR_BIT(SPCR , SPCR_CPOL);

	/*set clock phase (sample first)*/
	CLR_BIT(SPCR , SPCR_CPHA);

	/*set frequency prescaler by 16*/
	SET_BIT(SPCR , SPCR_SPR0);
	CLR_BIT(SPCR , SPCR_SPR1);
	CLR_BIT(SPSR , SPSR_SPI2X);

	/*set SPI enable */
	SET_BIT(SPCR , SPCR_SPE);
}
void SPI_voidInitSlave()
{
	/*set slave*/
	CLR_BIT(SPCR , SPCR_MSTR);

	/*set clock polarity (rising)*/
	CLR_BIT(SPCR , SPCR_CPOL);

	/*set clock phase (sample first)*/
	CLR_BIT(SPCR , SPCR_CPHA);

	/*set SPI enable */
	SET_BIT(SPCR , SPCR_SPE);
}
u8  SPI_u8TransmiterRreciever(u8 Copy_u8Data)
{
	/*send data*/
	SPDR = Copy_u8Data;

	/*wait until  transfer complete*/
	while(GET_BIT(SPSR , SPSR_SPIF) == 0);

	/*read data*/
	return SPDR;
}























