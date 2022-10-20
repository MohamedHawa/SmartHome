#ifndef BIT_MATH_H
#define BIT_MATH_H

#define		SET_BIT(var,bit_position)   	 (var |= (1 << bit_position))

#define		CLR_BIT(var,bit_position)     	 (var &= ~(1 << bit_position))

#define		GET_BIT(var,bit_position)        ((var >> bit_position) & 1 )

#define		tog_bit(var,bit_position)    	 (var ^= (1 << bit_position))

#endif
