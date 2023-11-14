/*
 * TIM_interface.h
 *
 *  Created on: Aug 24, 2023
 *  Author: ENG. Mahmoud Sayed
 */

#ifndef MCAL_TIM_INTERFACE_H
#define MCAL_TIM_INTERFACE_H


/** Defining the output compare names **/
#define OC1A 	1
#define OC1B 	2


/** Defining macros for the modes of operation of TIM1 **/
#define TIM1_NORMAL_MODE_OUTPUT_COMPARE_OC1A_OFF			0
#define TIM1_NORMAL_MODE_TOGGLE_OC1A_ON_COMPARE				1
#define TIM1_NORMAL_MODE_CLEAR_OC1A_ON_COMPARE				2
#define TIM1_NORMAL_MODE_SET_OC1A_ON_COMPARE				3

#define TIM1_CTC_MODE_OUTPUT_COMPARE_OC1A_OFF				4
#define TIM1_CTC_MODE_TOGGLE_OC1A_ON_COMPARE				5
#define TIM1_CTC_MODE_CLEAR_OC1A_ON_COMPARE					6
#define TIM1_CTC_MODE_SET_OC1A_ON_COMPARE					7

#define TIM1_FAST_PWM_MODE_OUTPUT_COMPARE_OC1A_OFF			8
#define TIM1_FAST_PWM_MODE_TOGGLE_OC1A_ON_COMPARE			9
#define TIM1_FAST_PWM_MODE_OC1A_NON_INVERTED				10
#define TIM1_FAST_PWM_MODE_OC1A_INVERTED					11

#define TIM1_PHASE_CORRECT_PWM_MODE_OUTPUT_COMPARE_OC1A_OFF	12
#define TIM1_PHASE_CORRECT_PWM_MODE_TOGGLE_OC1A_ON_COMPARE	13
#define TIM1_PHASE_CORRECT_PWM_MODE_OC1A_NON_INVERTED		14
#define TIM1_PHASE_CORRECT_PWM_MODE_OC1A_INVERTED			15
/* ==================================================== */
#define TIM1_NORMAL_MODE_OUTPUT_COMPARE_OC1B_OFF			16
#define TIM1_NORMAL_MODE_TOGGLE_OC1B_ON_COMPARE				17
#define TIM1_NORMAL_MODE_CLEAR_OC1B_ON_COMPARE				18
#define TIM1_NORMAL_MODE_SET_OC1B_ON_COMPARE				19

#define TIM1_CTC_MODE_OUTPUT_COMPARE_OC1B_OFF				20
#define TIM1_CTC_MODE_TOGGLE_OC1B_ON_COMPARE				21
#define TIM1_CTC_MODE_CLEAR_OC1B_ON_COMPARE					22
#define TIM1_CTC_MODE_SET_OC1B_ON_COMPARE					23

#define TIM1_FAST_PWM_MODE_OUTPUT_COMPARE_OC1B_OFF			24
#define TIM1_FAST_PWM_MODE_OC1B_NON_INVERTED				25
#define TIM1_FAST_PWM_MODE_OC1B_INVERTED					26

#define TIM1_PHASE_CORRECT_PWM_MODE_OUTPUT_COMPARE_OC1B_OFF	27
#define TIM1_PHASE_CORRECT_PWM_MODE_OC1B_NON_INVERTED		28
#define TIM1_PHASE_CORRECT_PWM_MODE_OC1B_INVERTED			29

/* TIM1 Waveform Generation Modes */
#define TIM1_NORMAL_MODE									0	/* Default Normal Mode */
#define TIM1_PWM_PHASE_CORRECT_8_BIT_MODE					1
#define TIM1_PWM_PHASE_CORRECT_9_BIT_MODE					2
#define TIM1_PWM_PHASE_CORRECT_10_BIT_MODE					3
#define TIM1_CTC_MODE										4	/* Default CTC Mode */
#define TIM1_FAST_PWM_8_BIT_MODE							5
#define TIM1_FAST_PWM_9_BIT_MODE							6
#define TIM1_FAST_PWM_10_BIT_MODE							7
#define TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_IC_MODE		8
#define TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_MODE			9
#define TIM1_PWM_PHASE_CORRECT_IC_MODE						10
#define TIM1_PWM_PHASE_CORRECT_MODE							11	/* Default PWM phase correct Mode */
#define TIM1_CTC_IC_MODE									12
#define TIM1_FAST_PWM_IC_MODE								13
#define TIM1_FAST_PWM_MODE									14	/* Default Fast PWM Mode */


/* To Enable the TIM1 & Select the timer clock */
void MCAL_TIM1_EnableTimer();

/* To Stop the TIM1 */
void MCAL_TIM1_StopTimer();

void MCAL_TIM1_Preset(u16 Copy_PresetValue);

/* To select the TIM1 mode of operation */
void MCAL_TIM1_SetTimerCompareMode(u8 Mode);

/* To select the TIM1 Waveform generation mode */
void MCAL_TIM1_SetTimerModeOfOperation(u8 Mode);

/* To set the timer value (Clear the TCNT1 register) */
void MCAL_TIM1_ClearTimer();

/* To get the elapsed time since the timer started from BOTTOM (0x0000) */
u16 MCAL_TIM1_GetElapsedTime(void);

/* To get the remaining time to reach the TOP value */
u16 MCAL_TIM1_GetRemainingTime(u16 TOP);

/* To set the compare value/threshold (Set the OCR1 register value) */
void MCAL_TIM1_SetCompareValue(u8 OC1x, u16 TOP);

/* To enable the timer interrupt on overflow */
void MCAL_TIM1_EnableOVFInterrupt(void(*CallbackFunction)(void));

/* To enable the timer 1 interrupt on input capture */
void MCAL_TIM_EnableCAPTInterrupt(void(*CallbackFunction)(void));

/* To enable the timer interrupt on compare match */
void MCAL_TIM1_EnableCOMPInterrupt(u8 OC1x, void(*CallbackFunction)(void));

/* To disable the timer interrupt on overflow */
void MCAL_TIM1_DisableOVFInterrupt();

/* To disable the timer 1 interrupt on input capture */
void MCAL_TIM_DisableCAPTInterrupt();

/* To disable the timer interrupt on compare match */
void MCAL_TIM1_DisableCOMPInterrupt(u8 OC1x);


#endif /* MCAL_TIM_INTERFACE_H */
