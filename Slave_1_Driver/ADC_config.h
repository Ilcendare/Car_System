/** ========================= The file information ========================== */
/**
 *  Project     : AVR_ATmega32_Driver
 *  File name   : ADC_config.h
 *  Created on  : Sep 16, 2023
 *  Author      : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_ADC_CONFIG_H
#define MCAL_ADC_CONFIG_H
/** ========================================================================= */




/** ============================= Configuration ============================= */
/*
 * Voltage Reference Selection:
 * 1- AREF pin (External voltage reference) 	->	ADC_VREF_AREF
 * 2- AVCC with external capacitor at AREF pin 	-> 	ADC_VREF_AVCC
 * 3- Internal 2.56V Voltage Reference with
 * external capacitor at AREF pin				-> ADC_VREF_INTERNAL
 */
#define ADC_VOLTAGE_REFERENCE	ADC_VREF_AVCC


/*
 * ADC Left Adjust Result
 *  - To disable the left adjust put (0)
 *  - To enable the left adjust put (1)
 */
#define ADC_LEFT_ADJUST		(0)


/*
 * ADC Auto Trigger:
 * - To disable the ADC auto trigger -> put (0)
 * - To enable the ADC auto trigger -> put (1)
 */
#define ADC_AUTO_TRIGGER_ENABLE		(0)


/*
 * ADC Auto Trigger Sources (Auto trigger must be enabled):
 * Free Running mode				->	ADC_ATS_FREE_RUNNING
 * Analog Comparator				->	ADC_ATS_ANALOG_COMPARATOR
 * External Interrupt Request 0		->	ADC_ATS_EXTI0
 * Timer/Counter0 Compare Match		->	ADC_ATS_TIM0_COMP
 * Timer/Counter0 Overflow			->	ADC_ATS_TIM0_OFV
 * Timer/Counter Compare Match B	->	ADC_ATS_TIM1_COMP_B
 * Timer/Counter1 Overflow			->	ADC_ATS_TIM1_OVF
 * Timer/Counter1 Capture Event		->	ADC_ATS_TIM1_IC
 */
#define	ADC_AUTO_TRIG_SOURCE	ADC_ATS_FREE_RUNNING


/*
 * ADC Clock Division Factors:
 * Clock Division Factor of 2		->	ADC_CLK_DIV_2
 * Clock Division Factor of 4		->	ADC_CLK_DIV_4
 * Clock Division Factor of 8		->	ADC_CLK_DIV_8
 * Clock Division Factor of 16		->	ADC_CLK_DIV_16
 * Clock Division Factor of 32		->	ADC_CLK_DIV_32
 * Clock Division Factor of 64		->	ADC_CLK_DIV_64
 * Clock Division Factor of 128		->	ADC_CLK_DIV_128
 */
#define ADC_CLK_DIV_FACTOR	ADC_CLK_DIV_64
/** ========================================================================= */




#endif /* MCAL_ADC_CONFIG_H */
/** ============================== END of File ============================== */
