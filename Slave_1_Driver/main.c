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
#include "SPI_interface.h"
#include "TIM0_interface.h"
#include "TIM1_interface.h"
#include "ADC_interface.h"
#include "SERVO_interface.h"
#include "SPI_registers.h"



/** ========================================================================= */
/** ========================== User-defined Macros ========================== */
/** ========================================================================= */



#define OC0_PIN        DIOB, PIN3



/** ========================================================================= */
/** ===================== User-defined Global Variables ===================== */
/** ========================================================================= */



u8 Sorvo_A, Sorvo_B, Sorvo_C, Sorvo_D;
u8 Instruction, MotorDirection, Speed, Door, C_State, D_State;



/* ============================== Program Flags ============================= */



/** ========================================================================= */
/** =================== User-defined Functions Prototypes =================== */
/** ========================================================================= */



void InitializeSystem(void);



/** ========================================================================= */
/** ========================= The Main Function ============================= */
/** ========================================================================= */



int main(void)
{
	/* System Initialization */
	InitializeSystem();


	while(1)
	{

		Instruction = MCAL_SPI_SlaveReceive();

		switch(Instruction)
		{
			case 'M':    // Move the motors
				MotorDirection = MCAL_SPI_SlaveReceive();

				if(MotorDirection == 'L' || MotorDirection == 'F')
				{
					Speed = MCAL_SPI_SlaveReceive();
					MCAL_TIM0_SetCompareValue(Speed);
				}


				else if(MotorDirection == 'R')
				{
					MCAL_TIM0_SetCompareValue(0);
				}
				break;


			case 'S':    // Stop the motors
				MCAL_TIM0_SetCompareValue(0);
				break;


			case 'D':    // Door options
				Door = MCAL_SPI_SlaveReceive();

				if(Door == 'A')
				{
					C_State = MCAL_SPI_SlaveReceive();

					if(C_State == '0')
					{
						MCAL_TIM1_SetCompareValue(OC1A, 0);
					}

					else if(C_State == '1')
					{
						MCAL_TIM1_SetCompareValue(OC1A, 3000);
					}
				}

				else if(Door == 'B')
				{
					D_State = MCAL_SPI_SlaveReceive();

					if(D_State == '0')
					{
						MCAL_TIM1_SetCompareValue(OC1B, 0);
					}

					else if(D_State == '1')
					{
						MCAL_TIM1_SetCompareValue(OC1B, 3000);
					}
				}
				break;


			case 'T':
				MCAL_ADC_StartConversion_PollingMode();
				u16 Temp = MCAL_ADC_ReadConversionResult();
				Temp = (((u32)Temp * 5000) / 1024);
				Temp = Temp / 10;
				MCAL_SPI_MasterTransmit((u8)Temp);
				break;
		}
	}
}



/** ========================================================================= */
/** ======================== Initialization Function ======================== */
/** ========================================================================= */



/* This function contains all the initialization required for the system. */
void InitializeSystem(void)
{
	MCAL_SPI_SlaveInit();
	MCAL_TIM0_SetTimerCompareMode(TIM0_PHASE_CORRECT_PWM_MODE_NON_INVERTED);
	MCAL_DIO_voidSetPinMode(OC0_PIN, Output);
	MCAL_TIM0_SetCompareValue(0);
	MCAL_TIM0_StartTimer();
	MCAL_ADC_Init();
	MCAL_ADC_SelectChannel(ADC0);
	HAL_SERVO_Init();
}



/** ========================================================================= */
/** =========== User-defined & Callback Functions Implementation ============ */
/** ========================================================================= */







/** ========================================================================= */
/** ========================================================================= */
/** ========================================================================= */
