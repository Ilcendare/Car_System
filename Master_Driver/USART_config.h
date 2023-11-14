/**
 *
 * 	File name: USART_config.h
 *  Created on: Sep 26, 2023
 *  Author: Eng. Mahmoud Sayed
 *
 **/

#ifndef MCAL_USART_CONFIG_H
#define MCAL_USART_CONFIG_H


/*
   Writing to UBRR will change the baud rate for the tx & rx:
   For calculating the UBRR with a known baud rate, use the following formulas:

   Async. Normal speed Mode 	->  UBRR = ( system_clock/(16 * baud) ) - 1  <-
   Async. Double speed Mode 	->  UBRR = ( system_clock/( 8 * baud) ) - 1  <-
   Sync. Master Mode			->  UBRR = ( system_clock/( 2 * baud) ) - 1  <-

   -> for a 1MHz system clock, in Async. Normal speed mode:
   		  Baud rate : UBRR value
   		  2400 			25
		  4800 			12
		  9600 			6
		  14.4k 		3
		  19.2k 		2
		  28.8k 		1
		  38.4k 		1
		  57.6k 		0
*/
#define USART_UBRR			(103)


/*
   Setting the USART Mode:
   -> for Asynchronous Mode  	->	USART_ASYNC_MODE
   -> for Synchronous Mode  	->	USART_SYNC_MODE
 */
#define USART_MODE			(USART_ASYNC_MODE)


/*
   Setting the format stop bits:
   -> for 1 stop bit	->	USART_STOP_BIT_1
   -> for 1 stop bit	->	USART_STOP_BIT_2
 */
#define USART_STOP_BITS		(USART_STOP_BIT_1)


/*
   Setting the USART parity mode:
   -> to disable the parity bit 				->	USART_PARITY_DISABLE
   -> to enable the parity mode as even parity 	->	USART_PARITY_EVEN
   -> to enable the parity mode as odd parity 	->	USART_PARITY_ODD
 */
#define USART_PARITY_MODE	(USART_PARITY_DISABLE)


/*
   Setting the USART data size:
   -> for 5-bit data size	->	USART_DATA_SIZE_5_BITS
   -> for 6-bit data size	->	USART_DATA_SIZE_6_BITS
   -> for 7-bit data size	->	USART_DATA_SIZE_7_BITS
   -> for 8-bit data size	->	USART_DATA_SIZE_8_BITS
   -> for 9-bit data size	->	USART_DATA_SIZE_9_BITS
 */
#define USART_DATA_SIZE		(USART_DATA_SIZE_8_BITS)


/*
   Setting the USART clock polarity (for the synchronous mode only):
   -> for rising on tx and falling on rx	->	USART_CLOCK_POL_CONFIG_1
   -> for falling on tx and rising on rx	->	USART_CLOCK_POL_CONFIG_2
 */
#define USART_CLOCK_POL		(USART_CLOCK_POL_CONFIG_1)



/*
   Setting the USART Data Register Empty Interrupt:
   -> to enable the USART Data Register Empty Interrupt -> USART_UDREI_ENABLE
   -> to disable the USART Data Register Empty Interrupt -> USART_UDREI_DISABLE
 */
#define USART_UDREI			(USART_UDREI_DISABLE)


#endif /* MCAL_USART_CONFIG_H */
