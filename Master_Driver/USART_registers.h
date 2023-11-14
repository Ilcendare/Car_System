/**
 * 	File name: USART_registers.h
 *  Created on: Sep 26, 2023
 *  Author: Eng. Mahmoud Sayed
 **/


#ifndef MCAL_USART_REGISTERS_H
#define MCAL_USART_REGISTERS_H


#define UBRRH	*((volatile u8*) 0x40)
#define UCSRC	*((volatile u8*) 0x40)
#define UBRRL	*((volatile u8*) 0x29)
#define UCSRA	*((volatile u8*) 0x2B)
#define UCSRB	*((volatile u8*) 0x2A)
#define UDR		*((volatile u8*) 0x2C)

/* UCSRC bits */
#define URSEL 	7
#define UMSEL	6
#define UPM1 	5
#define UPM0 	4
#define USBS 	3
#define UCSZ1 	2
#define UCSZ0 	1
#define UCPOL	0

/* UCSRA bits */
#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR 	3
#define PE 		2
#define U2X 	1
#define MPCM	0

/* UCSRB bits */
#define RXCIE	7
#define TXCIE	6
#define UDRIE	5
#define RXEN 	4
#define TXEN 	3
#define UCSZ2	2
#define RXB8 	1
#define TXB8	0





#endif /* MCAL_USART_REGISTERS_H */
