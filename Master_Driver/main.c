/** ======================================================================== **/
/** ========================= The file information ========================= **/
/** ======================================================================== **/
/**                                                                           **
 *                    Project       :     Car System                          *
 *                    File name     :     main.c                              *
 *                    Created on    :     1 Nov 2023                          *
 *                    Author        :     Eng. Mahmoud Sayed                  *
 **                                                                          **/
/** ======================================================================== **/



/** ========================================================================= */
/** =========================== All Included Files ========================== */
/** ========================================================================= */



#include <stdio.h>
#include <util/delay.h>

#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO_interface.h"
#include "USART_interface.h"
#include "SPI_interface.h"
#include "LCD_interface.h"
#include "GINT_interface.h"
#include "SPI_registers.h"



/** ========================================================================= */
/** ========================== User-defined Macros ========================== */
/** ========================================================================= */


#define    SLAVE_1             DIOA , PIN6
#define    SLAVE_2             DIOA , PIN7
#define    ACTIVE_SLAVE_1      MCAL_DIO_voidWritePin(SLAVE_1, Low);
#define    ACTIVE_SLAVE_2      MCAL_DIO_voidWritePin(SLAVE_2, Low);
#define    DEACTIVE_SLAVE_1    MCAL_DIO_voidWritePin(SLAVE_1, High);
#define    DEACTIVE_SLAVE_2    MCAL_DIO_voidWritePin(SLAVE_2, High);


/** ========================================================================= */
/** ===================== User-defined Global Variables ===================== */
/** ========================================================================= */



u8 Motor_Status = 3, Sorvo_A, Sorvo_B, Sorvo_C, Sorvo_D;
s16 Temperature = 26 ;
u8 Instruction, Speed, Direction, Door, A_State = '0', B_State = '0',
		                         C_State = '0', D_State = '0' ;
u8 TEMP[4];
u8 SPEED[4];
u8 message[] = "Welcome to the car system control program. Pleases read the "
			   "following instructions: \rEnter 'M' to move the car. \rEnter 'D' "
			   "with a door name and the door state.\rEnter 'T' to update the "
			   "temperature reading.\r> ";



/* ============================== Program Flags ============================= */



volatile u8 GetInstruction_flag         =   0;
volatile u8 UpdateStatus_flag           =   1;
volatile u8 WaitingForInstruction_flag  =   0;



/** ========================================================================= */
/** =================== User-defined Functions Prototypes =================== */
/** ========================================================================= */



void InitializeSystem(void);
void GetInstruction(void);
void UpdateStatus(void);
void UpdateGetInstructionFlag(void);
void USART_SendString(const u8 * String);



/** ========================================================================= */
/** ========================= The Main Function ============================= */
/** ========================================================================= */



int main(void)
{
	/* System Initialization */
	InitializeSystem();


	/* Program Introduction Message */
	USART_SendString(message);


	/* Enable the GIE */
	MCAL_GINT_SetGIE();


	while(1)
	{

		if(WaitingForInstruction_flag == 1)
		{
			MCAL_USART_Receive_InterruptMode(UpdateGetInstructionFlag);
		}



		if(GetInstruction_flag == 1)
		{
			GetInstruction();

			GetInstruction_flag = 0;
			UpdateStatus_flag = 1;
		}



		if(UpdateStatus_flag == 1)
		{
			MCAL_GINT_ClearGIE(); // Start of critical section

			UpdateStatus();

			UpdateStatus_flag = 0;
			WaitingForInstruction_flag = 1;

			MCAL_GINT_SetGIE();  // End of critical section
		}

	}
}



/** ========================================================================= */
/** ======================== Initialization Function ======================== */
/** ========================================================================= */



/* This function contains all the initialization required for the system. */
void InitializeSystem(void)
{
	MCAL_USART_Init();
	MCAL_SPI_MasterInit();
	MCAL_DIO_voidSetPinMode(SLAVE_1, Output);
	MCAL_DIO_voidSetPinMode(SLAVE_2, Output);
	HAL_LCD_Init();

	DEACTIVE_SLAVE_1;
	DEACTIVE_SLAVE_2;
}



/** ========================================================================= */
/** =========== User-defined & Callback Functions Implementation ============ */
/** ========================================================================= */



/* Send a string through the USART peripheral */
void USART_SendString(const u8 * String)
{
	for(u8 i = 0; String[i] != '\0'; i++)
	{
		MCAL_USART_Transmit_PollingMode(String[i]);
	}
}



/* Update the car status and show it on the LCD */
void UpdateStatus(void)
{


	/* Show The Motor Status */
	HAL_LCD_WriteString((u8*)"Motor Status: ", 0, 0);
	switch(Motor_Status)
	{
		case 0:
			HAL_LCD_WriteString((u8*)"              ", 0, 14);
			HAL_LCD_WriteString((u8*)"Turned Right", 0, 14);
			break;


		case 1:
			HAL_LCD_WriteString((u8*)"              ", 0, 14);
			HAL_LCD_WriteString((u8*)"Turned Left", 0, 14);
			break;


		case 2:
			HAL_LCD_WriteString((u8*)"              ", 0, 14);
			HAL_LCD_WriteString((u8*)"Moving Forward", 0, 14);
			break;


		default:
			HAL_LCD_WriteString((u8*)"              ", 0, 14);
			HAL_LCD_WriteString((u8*)"Stopped", 0, 14);
	}



	/* Show The Doors status */
	HAL_LCD_WriteString((u8*)"A: ", 0, 30);
	HAL_LCD_WriteString((u8*)" ", 0, 33);
	if(A_State == '0') HAL_LCD_WriteString((u8*)"0", 0, 33);
	else if(A_State == '1') HAL_LCD_WriteString((u8*)"1", 0, 33);


	HAL_LCD_WriteString((u8*)"B: ", 1, 30);
	HAL_LCD_WriteString((u8*)" ", 1, 33);
	if(B_State == '0') HAL_LCD_WriteString((u8*)"0", 1, 33);
	else if(B_State == '1') HAL_LCD_WriteString((u8*)"1", 1, 33);


	HAL_LCD_WriteString((u8*)"C: ", 0, 35);
	HAL_LCD_WriteString((u8*)" ", 0, 38);
	if(C_State == '0') HAL_LCD_WriteString((u8*)"0", 0, 38);
	else if(C_State == '1') HAL_LCD_WriteString((u8*)"1", 0, 38);


	HAL_LCD_WriteString((u8*)"D: ", 1, 35);
	HAL_LCD_WriteString((u8*)" ", 1, 38);
	if(D_State == '0') HAL_LCD_WriteString((u8*)"0", 1, 38);
	else if(D_State == '1') HAL_LCD_WriteString((u8*)"1", 1, 38);


	/* Show The Temperature Reading */
	HAL_LCD_WriteString((u8*)"Temperature: ", 1, 0);
	sprintf((char*)TEMP,"%d",Temperature);
	HAL_LCD_WriteString((u8*)"   ", 1, 13);
	HAL_LCD_WriteString(TEMP, 1, 13);


	/* Show the car speed */
	HAL_LCD_WriteString((u8*)"Speed: ", 1, 18);
	sprintf((char*)SPEED,"%d",Speed);
	HAL_LCD_WriteString((u8*)"   ", 1, 25);
	HAL_LCD_WriteString(SPEED, 1, 25);
}



/* */
void GetInstruction(void)
{
	/* Read The Entered Instruction */
	Instruction = MCAL_USART_ReadUDR();

	/* The two valid instructions are :
	 * 1 - M (for Move motors) + Direction (F: Forward, R: Turn Right, L: Turn Left).
	 * 2 - S (for Stop motors).
	 * 3 - D (for Door options) + Door selection (A, B, C, or D) + (1) for open, or (0) for close.
	 */

	switch(Instruction)
	{
		case 'M':    // Move the motors

			USART_SendString((u8*)"\rPlease, enter the direction of movement: ");
			Direction = MCAL_USART_Receive_PollingMode();    // L or R or F
			USART_SendString((u8*)"\rPlease, enter the speed (from 0 to 9): ");
			u8 d1 = MCAL_USART_Receive_PollingMode();
			//u8 d0 = MCAL_USART_Receive_PollingMode();

			Speed = ((d1 - 48) * 20);


			if(Direction == 'R')
			{
				Motor_Status = 0;    // Turn Right

				ACTIVE_SLAVE_2;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Direction);
				MCAL_SPI_MasterTransmit(Speed);
				DEACTIVE_SLAVE_2;

				ACTIVE_SLAVE_1;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Direction);
				DEACTIVE_SLAVE_1;

			}

			else if(Direction == 'L')
			{
				Motor_Status = 1;    // Turn Left

				ACTIVE_SLAVE_2;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Direction);
				DEACTIVE_SLAVE_2;

				ACTIVE_SLAVE_1;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Direction);
				MCAL_SPI_MasterTransmit(Speed);
				DEACTIVE_SLAVE_1;

			}

			else if(Direction == 'F')
			{
				Motor_Status = 2;        // Move Forward

				ACTIVE_SLAVE_2;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Direction);
				MCAL_SPI_MasterTransmit(Speed);
				DEACTIVE_SLAVE_2;

				ACTIVE_SLAVE_1;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Direction);
				MCAL_SPI_MasterTransmit(Speed);
				DEACTIVE_SLAVE_1;

			}

			else    // Wrong Selection
			{
				USART_SendString((u8*)"\rThis instruction is not valid.");
			}

			USART_SendString((u8*)"\r> ");
		break;


		case 'S':    // Stop the motors movement

			Motor_Status = 3;    // Stop the motors

			ACTIVE_SLAVE_2;
			MCAL_SPI_MasterTransmit(Instruction);
			DEACTIVE_SLAVE_2;

			ACTIVE_SLAVE_1;
			MCAL_SPI_MasterTransmit(Instruction);
			DEACTIVE_SLAVE_1;

			USART_SendString((u8*)"\r> ");
		break;


		case 'D':    // Door options

			USART_SendString((u8*)"\rPlease, enter the door ID: ");

			Door  = MCAL_USART_Receive_PollingMode();    // A, B, C or D

			USART_SendString((u8*)"\rEnter (1) to open the door, (0) to close the door: ");

			if(Door == 'A')         // Door A
			{
				A_State = MCAL_USART_Receive_PollingMode();

				ACTIVE_SLAVE_1;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Door);
				MCAL_SPI_MasterTransmit(A_State);
				DEACTIVE_SLAVE_1
			}

			else if(Door == 'B')    // Door B
			{
				B_State = MCAL_USART_Receive_PollingMode();

				ACTIVE_SLAVE_1;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Door);
				MCAL_SPI_MasterTransmit(B_State);
				DEACTIVE_SLAVE_1
			}

			else if(Door == 'C')    // Door C
			{
				C_State = MCAL_USART_Receive_PollingMode();

				ACTIVE_SLAVE_2;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Door);
				MCAL_SPI_MasterTransmit(C_State);
				DEACTIVE_SLAVE_2
			}

			else if(Door == 'D')    // Door D
			{
				D_State = MCAL_USART_Receive_PollingMode();

				ACTIVE_SLAVE_2;
				MCAL_SPI_MasterTransmit(Instruction);
				MCAL_SPI_MasterTransmit(Door);
				MCAL_SPI_MasterTransmit(D_State);
				DEACTIVE_SLAVE_2;
			}

			else    // Wrong Selection
			{
				USART_SendString((u8*)"\rThis instruction is not valid.");
			}

			USART_SendString((u8*)"\r> ");
		break;


		case 'T':
			ACTIVE_SLAVE_1;
			MCAL_SPI_MasterTransmit(Instruction);
			Temperature = MCAL_SPI_SlaveReceive();
			_delay_ms(50);
			MCAL_SPI_MasterTransmit(Instruction);
			Temperature = MCAL_SPI_SlaveReceive();
			_delay_ms(50);
			DEACTIVE_SLAVE_1;

			USART_SendString((u8*)"\r> ");
		break;


		default:    // Wrong Instruction

			USART_SendString((u8*)"\rThis instruction is not valid. "
					              "Please enter a valid instruction.\r> ");
	}

}


/* */
void UpdateGetInstructionFlag(void)
{
	GetInstruction_flag = 1;
	WaitingForInstruction_flag = 0;
}



/** ========================================================================= */
/** ========================================================================= */
/** ========================================================================= */
