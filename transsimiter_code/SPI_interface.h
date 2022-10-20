/*
 * SPI_interface.h
 *
 *  Created on: Sep 5, 2022
 *      Author: abdul
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster();

void SPI_voidInitSlave();

u8  SPI_u8TransmiterRreciever(u8 Copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
