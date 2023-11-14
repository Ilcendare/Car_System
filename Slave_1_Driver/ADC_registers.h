/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: ADC_registers.h
 *  Created on	: Sep 16, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_ADC_REGISTERS_H
#define MCAL_ADC_REGISTERS_H
/** ========================================================================= */



/** ================== Define The Bitwise Type of Registers ================= */

/** ========================================================================= */




/** ========================= Defining ADC Registers ======================== */
typedef struct ADMUX_reg_bitwise{
	u8 ADC_Channel      : 5;
	u8 ADC_Left_Adjust  : 1;
	u8 ADC_VREF         : 2;
} ADMUX_reg;
#define ADMUX		((volatile ADMUX_reg *) 0x27)


typedef struct ADCSRA_reg_bitwise{
	u8 ADC_Prescaler : 3;
	u8 ADIE          : 1;
	u8 ADIF          : 1;
	u8 ADATE         : 1;
	u8 ADSC          : 1;
	u8 ADEN          : 1;
} ADCSRA_reg;
#define ADCSRA		((volatile ADCSRA_reg *) 0x26)



#define ADCH		*((volatile u8 *) 0x25)
#define ADCL		*((volatile u8 *) 0x24)
#define ADCLH		*((volatile u16 *)0x24)


typedef struct SFIOR_reg_bitwise{
	u8          : 5;
	u8 ADC_ADTS : 3;
} SFIOR_reg;
#define SFIOR		((volatile SFIOR_reg *) 0x50)
/** ========================================================================= */




#endif /* MCAL_ADC_REGISTERS_H */
/** ============================== END of File ============================== */
