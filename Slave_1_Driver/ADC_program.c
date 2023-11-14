/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: ADC_program.c
 *  Created on	: Sep 16, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "ADC_interface.h"
#include "ADC_registers.h"
#include "ADC_private.h"
#include "ADC_config.h"
/** ========================================================================= */




/** ======================= Defining global variables ======================= */
void (*ADC_ISR)(void) = NULL;
/** ========================================================================= */




/** ====================== ADC Functions Implementation ===================== */
void MCAL_ADC_Init(void)
{
	/* Set the ADC VREF */
	ADMUX->ADC_VREF = ADC_VOLTAGE_REFERENCE;

	/* Enable/Disable the ADC left adjust */
#if	(ADC_LEFT_ADJUST == 1)
	ADMUX->ADC_Left_Adjust = 1;
#else
	ADMUX->ADC_Left_Adjust = 0;
#endif

	/* Enable/Disable the ADC Auto trigger mode */
#if (ADC_AUTO_TRIGGER_ENABLE == 1)
	/* Enable the ADC Auto trigger mode */
	ADCSRA->ADATE = 1;

	/* Set the Auto trigger mode source */
	SFIOR->ADC_ADTS = ADC_AUTO_TRIG_SOURCE;
#else
	ADCSRA->ADATE = 0;
#endif

	/* Set the ADC clock division */
	ADCSRA->ADC_Prescaler = ADC_CLK_DIV_FACTOR;

	/* Enable the ADC */
	ADCSRA->ADEN = 1;
}


void MCAL_ADC_Deinit(void)
{
	/* Disable the ADC */
	ADCSRA->ADEN = 0;
}


void MCAL_ADC_SelectChannel(ADC_Channel_t Channel)
{
	/* Set the channel selection */
	ADMUX->ADC_Channel = Channel;
}


void MCAL_ADC_StartConversion_PollingMode(void)
{
	/* Make sure the ADC Interrupt is disabled */
	if(ADCSRA->ADIE == 1)
	{
		ADCSRA->ADIF = 1;	// Clear the ADC Interrupt flag (ADIF)
		ADCSRA->ADIE = 0;	// Clear ADIE

		if(ADC_ISR != NULL)
		{
			ADC_ISR = NULL;
		}
	}

	/* Start the ADC conversion */
	ADCSRA->ADSC = 1;

	/* Poll for the ADC conversion */
	while(ADCSRA->ADSC == 1);
}


void MCAL_ADC_StartConversion_InterruptMode(void(*CallbackFunction)(void))
{
	/* Enable the ADC Interrupt */
	ADCSRA->ADIF = 1;	// Clear the ADC Interrupt flag (ADIF)
	ADCSRA->ADIE = 1;	// Set ADIE

	/* Set the callback function */
	if(CallbackFunction != NULL)
	{
		ADC_ISR = CallbackFunction;
	}

	/* Start the ADC conversion */
	ADCSRA->ADSC = 1;
}


u16	MCAL_ADC_ReadConversionResult(void)
{
#if	(ADC_LEFT_ADJUST == 1)
	uint16 result;
	result = (ADCL >> 6);
	result |= (ADCH << 2);
	return result;
#else
	return ADCLH;
#endif
}
/** ========================================================================= */




/** ===================== ADC ISRs Implementation ========================== */
/* ADC Conversion Complete ISR */
void __vector_16(void)	__attribute__((signal, used));
void __vector_16(void)
{
	if(ADC_ISR != NULL)
	{
		ADC_ISR();
	}
}
/** ========================================================================= */
