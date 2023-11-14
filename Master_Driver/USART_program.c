/**
 *	File Description:
 * 	File name: USART_program.c
 *  Created on: Sep 26, 2023
 *  Author: Eng. Mahmoud Sayed
 *
 **/



/* ============================== Include files ============================= */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "USART_registers.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"
/* ========================================================================== */



/* ============================ Global variables ============================ */
void (*TXC_ISR)(void) 	= (void*)0;
void (*RXC_ISR)(void) 	= (void*)0;
void (*UDRE_ISR)(void)	= (void*)0;
/* ========================================================================== */



/** ======================= USART initialization =========================== **/
/*
   USART initialization function:
 	 -> setting the baud rate,
 	 -> enabling the tx & rx,
 	 -> and setting the frame format.
*/
void MCAL_USART_Init(void)					// Change its implementation
{
	u8 Init_UMSEL, Init_UPM1, Init_UPM0, Init_USBS, Init_UCSZ1, Init_UCSZ0,
	Init_UCPOL;

	/// Set the baud rate
	UBRRH = (u8) (USART_UBRR >> 8);
	UBRRL = (u8) USART_UBRR;

	/// Enable receiver and transmitter
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

	/// Set the frame format

	/* Get the UCSRC bits values from configuration parameters */
	Init_UMSEL 	= USART_MODE;
	Init_USBS 	= USART_STOP_BITS;
	Init_UCPOL 	= USART_CLOCK_POL;
	Init_UPM1 	= (USART_PARITY_MODE >> 1);
	Init_UPM0 	= (USART_PARITY_MODE & 0x01);
	Init_UCSZ0 	= (USART_DATA_SIZE & 0x01);
	Init_UCSZ1 	= ((USART_DATA_SIZE >> 1) & 0x01);

	/* Configure the data (character) size */
#if(USART_DATA_SIZE == USART_DATA_SIZE_9_BITS)
	SET_BIT(UCSRB,UCSZ2);
#else
	CLR_BIT(UCSRB,UCSZ2);
#endif

	/* Clear UCSRC register */
	UCSRC = 0x80;

	/* Set all the UCSRC bits */
	UCSRC = ((1 << URSEL) | (Init_UMSEL << UMSEL) | (Init_USBS << USBS) |
			(Init_UCPOL << UCPOL) | (Init_UPM1 << UPM1) | (Init_UPM0 << UPM0) |
			(Init_UCSZ0 << UCSZ0) | (Init_UCSZ1 << UCSZ1));

	/* Configure the USART Data Register Empty Interrupt  */
#if (USART_UDREI == USART_UDREI_ENABLE)
	SET_BIT(UCSRB,UDRIE);
#elif(USART_UDREI == USART_UDREI_DISABLE)
	CLR_BIT(UCSRB,UDRIE);
#endif


}
/** ======================================================================== **/



/** =================== USART Transmit (Polling mode) ====================== **/
/*
   USART Transmit function in the polling mode
   The function will wait until the transmission in completed.
*/
void MCAL_USART_Transmit_PollingMode(TxDataType Data)
{
	/** Disable the interrupt mode transmission **/
	/* Clear the transmission completed interrupt flag */
	SET_BIT(UCSRA,TXC);

	/* Clear the transmission completed interrupt request */
	CLR_BIT(UCSRB,TXCIE);

	/* Assign the TXC_ISR to NULL */
	TXC_ISR = NULL;

	/* Wait for empty transmit buffer */
	while ( !(GET_BIT(UCSRA,UDRE)) );

#if	(USART_DATA_SIZE == USART_DATA_SIZE_9_BITS)
	/* Copy 9th bit to TXB8 */
	UCSRB &= ~(1<<TXB8);

	if(Data & 0x0100)
	{
		UCSRB |= (1<<TXB8);
	}
#endif

	/* Put data into buffer, and then send the data */
	UDR = Data;

	/* Wait for the transmission to be completed */
	while( !(GET_BIT(UCSRA,TXC)) );
}
/** ======================================================================== **/



/** ==================== USART Receive (Polling mode) ====================== **/
/*
   USART Receive function in the polling mode
   The function will wait until the reception process in completed.
*/
RxDataType MCAL_USART_Receive_PollingMode(void)
{
	/** Disable the interrupt mode Receive **/
	/* Clear the reception completed interrupt flag */
	SET_BIT(UCSRA,RXC);

	/* Clear the reception completed interrupt request */
	CLR_BIT(UCSRB,RXCIE);

	/* Assign the RXC_ISR to NULL */
	RXC_ISR = (void*)0;

#if	(USART_DATA_SIZE == USART_DATA_SIZE_9_BITS)
	uint8 status, resh, resl;

	/* Wait for data to be received */
	while ( !(GET_BIT(UCSRA,RXC)) );

	/* Get status and 9th bit, then data from buffer */
	status = UCSRA;
	resh = UCSRB;
	resl = UDR;

	/* If errors exist, return -1 */
	if ( status & ((1<<FE)|(1<<DOR)|(1<<PE)))
	{
		return -1;
	}

	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;

	return ((resh << 8) | resl);
#else
	u8 status;
	/* Wait for data to be received */
	while ( !(GET_BIT(UCSRA,RXC)) );

	/* Get status, if an error exists return -1 */
	status = UCSRA;
	if(status & ((1<<FE)|(1<<DOR)|(1<<PE)))
	{
		return -1;
	}

	/* Get and return received data from buffer */
	return UDR;
#endif
}
/** ======================================================================== **/



/** ================== USART Transmit (Interrupt mode) ===================== **/
/*
   USART Transmit function in the interrupt mode
   When the transmission process is completed, an interrupt request will be
   fired and the program will switch the control to the dedicated ISR.
*/
void MCAL_USART_Transmit_InterruptMode(TxDataType Data, void (*Callback)(void))
{
	/* Wait for empty transmit buffer */
	while ( !(GET_BIT(UCSRA,UDRE)) );

	/* Clear the transmission completed interrupt flag */
	SET_BIT(UCSRA,TXC);

	/* Set the transmission completed interrupt request */
	SET_BIT(UCSRB,TXCIE);

	/* Assign the TXC_ISR to the callback function passed by the user */
	TXC_ISR = Callback;

#if	(USART_DATA_SIZE == USART_DATA_SIZE_9_BITS)
	/* Copy 9th bit to TXB8 */
	UCSRB &= ~(1<<TXB8);

	if(Data & 0x0100)
	{
		UCSRB |= (1<<TXB8);
	}
#endif

	/* Put data into buffer, and then send the data */
	UDR = Data;
}
/** ======================================================================== **/



/** ================== USART Receive (Interrupt mode) ====================== **/
/*
   USART Receive function in the interrupt mode
   When the reception process is completed, an interrupt request will be
   fired and the program will switch the control to the dedicated ISR.
*/
void MCAL_USART_Receive_InterruptMode(void (*Callback)(void))
{
	/* Clear the reception completed interrupt flag */
	SET_BIT(UCSRA,RXC);

	/* Set the reception completed interrupt request */
	SET_BIT(UCSRB,RXCIE);

	/* Assign the RXC_ISR to the callback function passed by the user */
	RXC_ISR = Callback;
}
/** ======================================================================== **/



/** ================== USART Receive (Interrupt mode) ====================== **/
/*
   Read the USART Data received from the buffer.
   This function is only used with the interrupt mode.
*/
RxDataType MCAL_USART_ReadUDR(void)
{
#if	(USART_DATA_SIZE == USART_DATA_SIZE_9_BITS)
	uint8 status, resh, resl;

	/* Get status and 9th bit, then data from buffer */
	status = UCSRA;
	resh = UCSRB;
	resl = UDR;

	/* If errors exist, return -1 */
	if ( status & ((1<<FE)|(1<<DOR)|(1<<PE)))
	{
		return -1;
	}

	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;

	return ((resh << 8) | resl);
#else
	u8 status = UCSRA;

	/* Get status, if an error exists return -1 */
	if(status & ((1<<FE)|(1<<DOR)|(1<<PE)))
	{
		return -1;
	}

	/* Get and return received data from buffer */
	return UDR;
#endif
}
/** ======================================================================== **/



/** ================== USART Transmission Complete ISR ===================== **/
void __vector_15(void) __attribute__((signal,used));
void __vector_15(void)
{
	if( TXC_ISR != ((void*) 0) )
	{
		TXC_ISR();
	}
}
/** ======================================================================== **/



/** =================== USART Data Register Empty ISR ====================== **/
void __vector_14(void) __attribute__((signal,used));
void __vector_14(void)
{
	if( UDRE_ISR != ((void*) 0) )
	{
		UDRE_ISR();
	}
}
/** ======================================================================== **/



/** ==================== USART Reception Complete ISR ====================== **/
void __vector_13(void) __attribute__((signal,used));
void __vector_13(void)
{
	if( RXC_ISR != ((void*) 0) )
	{
		RXC_ISR();
	}
}
/** ======================================================================== **/

