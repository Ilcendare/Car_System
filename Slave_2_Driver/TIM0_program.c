/*
 * TIM_program.c
 *
 *  Created on: Aug 24, 2023
 *  Author: ENG. Mahmoud Sayed
 */


#include "BIT_Math.h"
#include "STD_Types.h"
#include "TIM_registers.h"
#include "TIM0_config.h"
#include "TIM0_interface.h"


void (*TIM0_OVF_ISR) (void);
void (*TIM0_COMP_ISR) (void);


/* To Start the TIM0 & Select the timer clock */
void MCAL_TIM0_StartTimer()
{
	TCCR0 |= TIM0_CLK_SOUCRE;	// Configured in the TIM0_config.h file
}


/* To put the initial value to count from */
void MCAL_TIM0_PresetTimer(u8 Copy_Value)
{
	TCNT0 = Copy_Value;
}


/* To Stop the TIM0 */
void MCAL_TIM0_StopTimer()
{
	TCCR0 &= 0b11111000;
}


/* To select the TIM0 mode of operation */
void MCAL_TIM0_SetTimerCompareMode(u8 Mode)
{
	switch(Mode)
	{
	/* ============== NORMAL MODE ============== */
	case TIM0_NORMAL_MODE_OUTPUT_COMPARE_OFF:
		CLR_BIT(TCCR0,6);	//WGM00
		CLR_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		CLR_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_NORMAL_MODE_TOGGLE_ON_COMPARE:
		CLR_BIT(TCCR0,6);	//WGM00
		CLR_BIT(TCCR0,3);	//WGM01

		SET_BIT(TCCR0,4);	//COM00
		CLR_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_NORMAL_MODE_CLEAR_ON_COMPARE:
		CLR_BIT(TCCR0,6);	//WGM00
		CLR_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_NORMAL_MODE_SET_ON_COMPARE:
		CLR_BIT(TCCR0,6);	//WGM00
		CLR_BIT(TCCR0,3);	//WGM01

		SET_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;

		/* ============== CTC MODE ============== */
	case TIM0_CTC_MODE_OUTPUT_COMPARE_OFF:
		CLR_BIT(TCCR0,6);	//WGM00
		SET_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		CLR_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_CTC_MODE_TOGGLE_ON_COMPARE:
		CLR_BIT(TCCR0,6);	//WGM00
		SET_BIT(TCCR0,3);	//WGM01

		SET_BIT(TCCR0,4);	//COM00
		CLR_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_CTC_MODE_CLEAR_ON_COMPARE:
		CLR_BIT(TCCR0,6);	//WGM00
		SET_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_CTC_MODE_SET_ON_COMPARE:
		CLR_BIT(TCCR0,6);	//WGM00
		SET_BIT(TCCR0,3);	//WGM01

		SET_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;

		/* ============== FAST PWM MODE ============== */
	case TIM0_FAST_PWM_MODE_OUTPUT_COMPARE_OFF:
		SET_BIT(TCCR0,6);	//WGM00
		SET_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		CLR_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_FAST_PWM_MODE_NON_INVERTED:
		SET_BIT(TCCR0,6);	//WGM00
		SET_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_FAST_PWM_MODE_INVERTED:
		SET_BIT(TCCR0,6);	//WGM00
		SET_BIT(TCCR0,3);	//WGM01

		SET_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;

		/* ============== PHASE CORRECT PWM MODE ============== */
	case TIM0_PHASE_CORRECT_PWM_MODE_OUTPUT_COMPARE_OFF:
		SET_BIT(TCCR0,6);	//WGM00
		CLR_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		CLR_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_PHASE_CORRECT_PWM_MODE_NON_INVERTED:
		SET_BIT(TCCR0,6);	//WGM00
		CLR_BIT(TCCR0,3);	//WGM01

		CLR_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;

	case TIM0_PHASE_CORRECT_PWM_MODE_INVERTED:
		SET_BIT(TCCR0,6);	//WGM00
		CLR_BIT(TCCR0,3);	//WGM01

		SET_BIT(TCCR0,4);	//COM00
		SET_BIT(TCCR0,5);	//COM01
		break;
	}

}


/* To clear the timer 0 */
void MCAL_TIM0_ClearTimer()
{
	TCNT0 = 0;
}


/* To get the elapsed time since the timer starts from BOTTOM (0x00) */
u8 MCAL_TIM0_GetElapsedTime()
{
	return TCNT0;
}


/* To get the remaining time to reach the TOP value */
u8 MCAL_TIM0_GetRemainingTime(u8 TOP)
{
	return (TOP - TCNT0);
}


/* To let the CPU wait for a specified time (Delay in ms) */
void MCAL_TIM0_BusyWait(u32 Copy_Delay)
{
	MCAL_TIM0_SetCompareValue(199);
	MCAL_TIM0_StartTimer();
	while(Copy_Delay--)
	{
		while(!GET_BIT(TIFR,0));
		SET_BIT(TIFR,0);
	}
	MCAL_TIM0_StartTimer();
}


/* To set the compare value/threshold for timer 0 */
void MCAL_TIM0_SetCompareValue(u8 TOP)
{
	OCR0 = TOP;
}


/* To enable the timer 0 interrupt on overflow */
void MCAL_TIM0_EnableOVFInterrupt(void(*CallbackFunction)(void))
{
	SET_BIT(TIMSK,0);
	if(CallbackFunction != NULL)
	{
		TIM0_OVF_ISR = CallbackFunction;
	}
}


/* To enable the timer 0 interrupt on compare match */
void MCAL_TIM0_EnableCOMPInterrupt(void(*CallbackFunction)(void))
{
	SET_BIT(TIMSK,1);
	if(CallbackFunction != NULL)
	{
		TIM0_COMP_ISR = CallbackFunction;
	}
}


/* To disable the timer 0 interrupt on overflow */
void MCAL_TIM0_DisableOVFInterrupt()
{
	CLR_BIT(TIMSK,0);
	TIM0_OVF_ISR = NULL;
}


/* To disable the timer 0 interrupt on compare match */
void MCAL_TIM0_DisableCOMPInterrupt()
{
	CLR_BIT(TIMSK,1);
	TIM0_COMP_ISR = NULL;
}


void __vector_10(void) __attribute__((signal, used));
void __vector_10(void)		// TIMER0 COMP
{
	if(TIM0_COMP_ISR != NULL)
	{
		TIM0_COMP_ISR();
	}
}


void __vector_11(void) __attribute__((signal, used));
void __vector_11(void)		// TIMER0 OVF
{
	if(TIM0_OVF_ISR != NULL)
	{
		TIM0_OVF_ISR();
	}
}


