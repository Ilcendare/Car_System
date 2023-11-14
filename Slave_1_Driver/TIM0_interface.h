/*
 * TIM_interface.h
 *
 *  Created on: Aug 24, 2023
 *  Author: ENG. Mahmoud Sayed
 */

#ifndef MCAL_TIM0_INTERFACE_H
#define MCAL_TIM0_INTERFACE_H


/** Defining macros for the modes of operation for TIM0 **/
#define TIM0_NORMAL_MODE_OUTPUT_COMPARE_OFF				0
#define TIM0_NORMAL_MODE_TOGGLE_ON_COMPARE				1
#define TIM0_NORMAL_MODE_CLEAR_ON_COMPARE				2
#define TIM0_NORMAL_MODE_SET_ON_COMPARE					3

#define TIM0_CTC_MODE_OUTPUT_COMPARE_OFF				4
#define TIM0_CTC_MODE_TOGGLE_ON_COMPARE					5
#define TIM0_CTC_MODE_CLEAR_ON_COMPARE					6
#define TIM0_CTC_MODE_SET_ON_COMPARE					7

#define TIM0_FAST_PWM_MODE_OUTPUT_COMPARE_OFF			8
#define TIM0_FAST_PWM_MODE_NON_INVERTED					9
#define TIM0_FAST_PWM_MODE_INVERTED						10

#define TIM0_PHASE_CORRECT_PWM_MODE_OUTPUT_COMPARE_OFF	11
#define TIM0_PHASE_CORRECT_PWM_MODE_NON_INVERTED		12
#define TIM0_PHASE_CORRECT_PWM_MODE_INVERTED			13


/* To Stop the TIM0 & Select the timer 0 clock */
void MCAL_TIM0_StartTimer();

/* To Stop the TIM0 */
void MCAL_TIM0_StopTimer();

/* To put the initial value to count from */
void MCAL_TIM0_PresetTimer(u8 Copy_Value);

/* To let the CPU wait for a specified time (Delay in ms) */
void MCAL_TIM0_BusyWait(u32 Copy_Delay);

/* To select the TIM0 mode of operation */
void MCAL_TIM0_SetTimerCompareMode(u8 Mode);

/* To set the timer 0 value (Clear the TCNT0 register) */
void MCAL_TIM0_ClearTimer();

/* To get the elapsed time since the timer starts from BOTTOM (0x00) */
u8 MCAL_TIM0_GetElapsedTime();

/* To get the remaining time to reach the TOP value */
u8 MCAL_TIM0_GetRemainingTime(u8 TOP);

/* To set the compare value/threshold (Set the OCR0 register value) */
void MCAL_TIM0_SetCompareValue(u8 TOP);

/* To enable the timer 0 interrupt on overflow */
void MCAL_TIM0_EnableOVFInterrupt(void(*CallbackFunction)(void));

/* To enable the timer 0 interrupt on compare match */
void MCAL_TIM0_EnableCOMPInterrupt(void(*CallbackFunction)(void));

/* To disable the timer 0 interrupt on overflow */
void MCAL_TIM0_DisableOVFInterrupt();

/* To disable the timer 0 interrupt on compare match */
void MCAL_TIM0_DisableCOMPInterrupt();


#endif /* MCAL_TIM0_INTERFACE_H */
