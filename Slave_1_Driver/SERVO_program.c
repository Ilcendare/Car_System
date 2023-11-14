/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: SERVO_program.h
 *  Created on	: Oct 28, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ================================= Notes ================================= */
/*
	 * The whole cycle time = 20 ms.
	 * The ON time is between 750 us and 2500 us.
	 * 750 us  -> -90 Degree
	 * 2500 us -> 90 Degrees
	 *
	 * Mapping the angle value and the T_ON value will be:
	 * T_ON (in us) = (Angle * ((2500 - 750) / 180)) + 750
	 *
	 * To get the number of ticks for the required ON time:
	 * NO_of_ticks = T_ON (in us)/tick_time (in us)
	 *
	 * The TOP will be calculated as:
	 * TOP = 20,000 / tick_time (in us)
	 * */
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "TIM_registers.h"
#include "TIM1_interface.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"
/** ========================================================================= */




/** ==================== Servo Functions Implementation ===================== */
void HAL_SERVO_Init(void)
{
	/* Initialize the Timer 1 */
	MCAL_TIM1_SetTimerCompareMode(TIM1_FAST_PWM_MODE_OC1A_NON_INVERTED);
	MCAL_TIM1_SetTimerCompareMode(TIM1_FAST_PWM_MODE_OC1B_NON_INVERTED);
	MCAL_DIO_voidSetPinMode(OC1A_PIN, Output);
	MCAL_DIO_voidSetPinMode(OC1B_PIN, Output);

	/* Prepare the Servo motor to be moved to its reference position */
	MCAL_TIM1_SetCompareValue(OC1A, 0);    // Compare match set to zero
	MCAL_TIM1_SetCompareValue(OC1B, 0);    // Compare match set to zero
	ICR1 = 40000;                          // TOP (40,000 * tick time = 20 ms)

	/* Start the timer 1 */
	MCAL_TIM1_EnableTimer();
}


void HAL_SERVO_SetAngle(u16 Copy_Angle)
{
	/* Equation (Mapping) */

	/* Set the new position to the servo motor (by changing the output compare value) */
	MCAL_TIM1_SetCompareValue(OC1A, Copy_Angle);
}
/** ========================================================================= */

