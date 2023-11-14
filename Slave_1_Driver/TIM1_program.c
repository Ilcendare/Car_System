/*
 * TIM_program.c
 *
 *  Created on: Aug 24, 2023
 *  Author: ENG. Mahmoud Sayed
 */


#include "BIT_Math.h"
#include "STD_Types.h"
#include "TIM_registers.h"
#include "TIM1_config.h"
#include "TIM1_interface.h"


void (*TIM1_OVF_ISR) (void);
void (*TIM1_COMPA_ISR) (void);
void (*TIM1_COMPB_ISR) (void);
void (*TIM1_CAPT_ISR) (void);


/* To Enable the TIM1 & Select the timer 1 clock */
void MCAL_TIM1_EnableTimer()
{
	TCCR1B |= TIM1_CLK_SOUCRE;
}


/* To Stop the TIM1 */
void MCAL_TIM1_StopTimer()
{
	TCCR1B &= 0b11111000;
}


void MCAL_TIM1_Preset(u16 Copy_PresetValue)
{
	TCNT1 = Copy_PresetValue;
}


/* To select the TIM1 mode of operation */
void MCAL_TIM1_SetTimerCompareMode(u8 Mode)
{
	switch(Mode)
	{

	/* ============== NORMAL MODE ============== */
	case TIM1_NORMAL_MODE_OUTPUT_COMPARE_OC1A_OFF:
		CLR_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	case TIM1_NORMAL_MODE_OUTPUT_COMPARE_OC1B_OFF:
		CLR_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	case TIM1_NORMAL_MODE_TOGGLE_OC1A_ON_COMPARE:
		CLR_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	case TIM1_NORMAL_MODE_TOGGLE_OC1B_ON_COMPARE:
		CLR_BIT(TCCR1A,5);	//COM1B1
		SET_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	case TIM1_NORMAL_MODE_CLEAR_OC1A_ON_COMPARE:
		SET_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	case TIM1_NORMAL_MODE_CLEAR_OC1B_ON_COMPARE:
		SET_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	case TIM1_NORMAL_MODE_SET_OC1A_ON_COMPARE:
		SET_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	case TIM1_NORMAL_MODE_SET_OC1B_ON_COMPARE:
		SET_BIT(TCCR1A,5);	//COM1B1
		SET_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_NORMAL_MODE);
		break;

	/* =============== CTC MODE ================ */
	case TIM1_CTC_MODE_OUTPUT_COMPARE_OC1A_OFF:
		CLR_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	case TIM1_CTC_MODE_OUTPUT_COMPARE_OC1B_OFF:
		CLR_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	case TIM1_CTC_MODE_TOGGLE_OC1A_ON_COMPARE:
		CLR_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	case TIM1_CTC_MODE_TOGGLE_OC1B_ON_COMPARE:
		CLR_BIT(TCCR1A,5);	//COM1B1
		SET_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	case TIM1_CTC_MODE_CLEAR_OC1A_ON_COMPARE:
		SET_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	case TIM1_CTC_MODE_CLEAR_OC1B_ON_COMPARE:
		SET_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	case TIM1_CTC_MODE_SET_OC1A_ON_COMPARE:
		SET_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	case TIM1_CTC_MODE_SET_OC1B_ON_COMPARE:
		SET_BIT(TCCR1A,5);	//COM1B1
		SET_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_CTC_MODE);
		break;

	/* ============= FAST PWM MODE ============ */
	case TIM1_FAST_PWM_MODE_OUTPUT_COMPARE_OC1A_OFF:
		CLR_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_FAST_PWM_MODE);
		break;

	case TIM1_FAST_PWM_MODE_OUTPUT_COMPARE_OC1B_OFF:
		CLR_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_FAST_PWM_MODE);
		break;

	case TIM1_FAST_PWM_MODE_TOGGLE_OC1A_ON_COMPARE:
		CLR_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_FAST_PWM_MODE);
		break;

	case TIM1_FAST_PWM_MODE_OC1A_NON_INVERTED:
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_FAST_PWM_IC_MODE);
		SET_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		break;

	case TIM1_FAST_PWM_MODE_OC1B_NON_INVERTED:
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_FAST_PWM_IC_MODE);
		SET_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		break;

	case TIM1_FAST_PWM_MODE_OC1A_INVERTED:
		SET_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_FAST_PWM_MODE);
		break;

	case TIM1_FAST_PWM_MODE_OC1B_INVERTED:
		SET_BIT(TCCR1A,5);	//COM1B1
		SET_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_FAST_PWM_MODE);
		break;

	/* === PHASE (AND FREQUENCY) CORRECT PWM MODE === */
	case TIM1_PHASE_CORRECT_PWM_MODE_OUTPUT_COMPARE_OC1A_OFF:
		CLR_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_PWM_PHASE_CORRECT_MODE);
		break;

	case TIM1_PHASE_CORRECT_PWM_MODE_OUTPUT_COMPARE_OC1B_OFF:
		CLR_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_PWM_PHASE_CORRECT_MODE);
		break;

	case TIM1_PHASE_CORRECT_PWM_MODE_TOGGLE_OC1A_ON_COMPARE:
		CLR_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_PWM_PHASE_CORRECT_MODE);
		break;

	case TIM1_PHASE_CORRECT_PWM_MODE_OC1A_NON_INVERTED:
		SET_BIT(TCCR1A,7);	//COM1A1
		CLR_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_PWM_PHASE_CORRECT_MODE);
		break;

	case TIM1_PHASE_CORRECT_PWM_MODE_OC1B_NON_INVERTED:
		SET_BIT(TCCR1A,5);	//COM1B1
		CLR_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_PWM_PHASE_CORRECT_MODE);
		break;

	case TIM1_PHASE_CORRECT_PWM_MODE_OC1A_INVERTED:
		SET_BIT(TCCR1A,7);	//COM1A1
		SET_BIT(TCCR1A,6);	//COM1A0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_PWM_PHASE_CORRECT_MODE);
		break;

	case TIM1_PHASE_CORRECT_PWM_MODE_OC1B_INVERTED:
		SET_BIT(TCCR1A,5);	//COM1B1
		SET_BIT(TCCR1A,4);	//COM1B0
		MCAL_TIM1_SetTimerModeOfOperation(TIM1_PWM_PHASE_CORRECT_MODE);
		break;
	}
}


/* To select the TIM1 Waveform generation mode */
void MCAL_TIM1_SetTimerModeOfOperation(u8 Mode)
{
	switch(Mode)
	{
	case TIM1_NORMAL_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		CLR_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_PWM_PHASE_CORRECT_8_BIT_MODE:
		SET_BIT(TCCR1A,0);	//WGM10
		CLR_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_PWM_PHASE_CORRECT_9_BIT_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_PWM_PHASE_CORRECT_10_BIT_MODE:
		SET_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_CTC_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		CLR_BIT(TCCR1A,1);	//WGM11
		SET_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_FAST_PWM_8_BIT_MODE:
		SET_BIT(TCCR1A,0);	//WGM10
		CLR_BIT(TCCR1A,1);	//WGM11
		SET_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_FAST_PWM_9_BIT_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		SET_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_FAST_PWM_10_BIT_MODE:
		SET_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		SET_BIT(TCCR1B,3);	//WGM12
		CLR_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_IC_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		CLR_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		SET_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_MODE:
		SET_BIT(TCCR1A,0);	//WGM10
		CLR_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		SET_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_PWM_PHASE_CORRECT_IC_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		SET_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_PWM_PHASE_CORRECT_MODE:
		SET_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		CLR_BIT(TCCR1B,3);	//WGM12
		SET_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_CTC_IC_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		CLR_BIT(TCCR1A,1);	//WGM11
		SET_BIT(TCCR1B,3);	//WGM12
		SET_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_FAST_PWM_IC_MODE:
		CLR_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		SET_BIT(TCCR1B,3);	//WGM12
		SET_BIT(TCCR1B,4);	//WGM13
		break;

	case TIM1_FAST_PWM_MODE:
		SET_BIT(TCCR1A,0);	//WGM10
		SET_BIT(TCCR1A,1);	//WGM11
		SET_BIT(TCCR1B,3);	//WGM12
		SET_BIT(TCCR1B,4);	//WGM13
		break;
	}
}


/* To clear the timer 1 */
void MCAL_TIM1_ClearTimer()
{
	TCNT1 = 0;
}


/* To get the elapsed time since the timer started from BOTTOM (0x0000) */
u16 MCAL_TIM1_GetElapsedTime(void)
{
	return TCNT1;
}


/* To get the remaining time to reach the TOP value */
u16 MCAL_TIM1_GetRemainingTime(u16 TOP)
{
	return (TOP - TCNT1);
}


/* To set the compare value/threshold */
void MCAL_TIM1_SetCompareValue(u8 OC1x, u16 TOP)
{
	if(OC1x == OC1A)
	{
		OCR1A = TOP;
	}
	else if(OC1x == OC1B)
	{
		OCR1B = TOP;
	}
}


/* To enable the timer 1 interrupt on overflow */
void MCAL_TIM1_EnableOVFInterrupt(void(*CallbackFunction)(void))
{
	SET_BIT(TIMSK,2);
	TIM1_OVF_ISR = CallbackFunction;
}


/* To enable the timer 1 interrupt on input capture */
void MCAL_TIM1_EnableCAPTInterrupt(void(*CallbackFunction)(void))
{
	SET_BIT(TIMSK,5);
	TIM1_CAPT_ISR = CallbackFunction;
}


/* To enable the timer 1 interrupt on compare match */
void MCAL_TIM1_EnableCOMPInterrupt(u8 OC1x, void(*CallbackFunction)(void))
{
	if(OC1x == OC1A)
	{
		SET_BIT(TIMSK,4);
		TIM1_COMPA_ISR = CallbackFunction;
	}
	else if(OC1x == OC1B)
	{
		SET_BIT(TIMSK,3);
		TIM1_COMPB_ISR = CallbackFunction;
	}
}


/* To disable the timer 1 interrupt on input capture */
void MCAL_TIM1_DisableCAPTInterrupt()
{
	CLR_BIT(TIMSK,5);
	TIM1_CAPT_ISR = NULL;
}


/* To disable the timer interrupt on overflow */
void MCAL_TIM1_DisableOVFInterrupt()
{
	CLR_BIT(TIMSK,2);
	TIM1_OVF_ISR = NULL;
}


/* To disable the timer interrupt on compare match */
void MCAL_TIM1_DisableCOMPInterrupt(u8 OC1x)
{
	if(OC1x == OC1A)
	{
		CLR_BIT(TIMSK,4);
		TIM1_COMPA_ISR = NULL;
	}
	else if(OC1x == OC1B)
	{
		CLR_BIT(TIMSK,3);
		TIM1_COMPB_ISR = NULL;
	}

}


void __vector_6(void) __attribute__((signal, used));
void __vector_6(void)		// TIMER1 CAPT
{
	TIM1_CAPT_ISR();
}


void __vector_7(void) __attribute__((signal, used));
void __vector_7(void)		// TIMER1 COMPA
{
	TIM1_COMPA_ISR();
}


void __vector_8(void) __attribute__((signal, used));
void __vector_8(void)		// TIMER1 COMPB
{
	TIM1_COMPB_ISR();
}


void __vector_9(void) __attribute__((signal, used));
void __vector_9(void)		// TIMER1 OVF
{
	TIM1_OVF_ISR();
}
