/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: ADC_private.h
 *  Created on	: Oct 24, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_ADC_PRIVATE_H
#define MCAL_ADC_PRIVATE_H
/** ========================================================================= */



/** ==================== Defining ADC Configuration Macros ================== */
/* ADC Voltage Reference Configuration Macros */
#define ADC_VREF_AREF				0b00
#define ADC_VREF_AVCC				0b01
#define ADC_VREF_INTERNAL			0b11

/* ADC Auto Trigger Mode Configuration Macros */
#define ADC_ATS_FREE_RUNNING		0b000
#define	ADC_ATS_ANALOG_COMPARATOR	0b001
#define ADC_ATS_EXTI0				0b010
#define ADC_ATS_TIM0_COMP			0b011
#define ADC_ATS_TIM0_OFV			0b100
#define ADC_ATS_TIM1_COMP_B			0b101
#define ADC_ATS_TIM1_OVF			0b110
#define	ADC_ATS_TIM1_IC				0b111

/* ADC Clock Prescaler Configuration Macros */
#define ADC_CLK_DIV_2				0b001
#define ADC_CLK_DIV_4				0b010
#define ADC_CLK_DIV_8				0b011
#define ADC_CLK_DIV_16				0b100
#define ADC_CLK_DIV_32				0b101
#define ADC_CLK_DIV_64				0b110
#define ADC_CLK_DIV_128				0b111
/** ========================================================================= */




#endif /* MCAL_ADC_PRIVATE_H */
/** ============================== END of File ============================== */
