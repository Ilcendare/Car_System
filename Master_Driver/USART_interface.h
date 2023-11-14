/**
 *
 *  File name: USART_interface.h
 *  Created on: Sep 26, 2023
 *  Author: Eng. Mahmoud Sayed
 *
 **/

#ifndef MCAL_USART_INTERFACE_H
#define MCAL_USART_INTERFACE_H


#if(USART_DATA_SIZE == USART_DATA_SIZE_9_BITS)
typedef u16 RxDataType;
typedef u16 TxDataType;
#else
typedef u8 RxDataType;
typedef u8 TxDataType;
#endif


/*
   USART initialization function:
 	 -> setting the baud rate,
 	 -> enabling the Tx & Rx,
 	 -> and setting the frame format.
*/
void MCAL_USART_Init(void);


/*
   USART Transmit function in the polling mode
   The function will wait until the transmission in completed.
*/
void MCAL_USART_Transmit_PollingMode(TxDataType Data);


/*
   USART Receive function in the polling mode
   The function will wait until the reception process in completed.
*/
RxDataType MCAL_USART_Receive_PollingMode(void);


/*
   USART Transmit function in the interrupt mode
   When the transmission process is completed, an interrupt request will be
   fired and the program will switch the control to the dedicated ISR.
*/
void MCAL_USART_Transmit_InterruptMode(TxDataType Data, void (*Callback)(void));


/*
   USART Receive function in the interrupt mode
   When the reception process is completed, an interrupt request will be
   fired and the program will switch the control to the dedicated ISR.
*/
void MCAL_USART_Receive_InterruptMode(void (*Callback)(void));


/*
   Read the USART Data received from the buffer.
   This function is only used with the interrupt mode.
*/
RxDataType MCAL_USART_ReadUDR(void);

#endif /* MCAL_USART_INTERFACE_H */
