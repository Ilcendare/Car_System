/** ========================= The file information ========================== */
/**
 *  Project: AVR_ATmega32_Driver
 * 	File name: BIT_manip.h
 *  Created on: Aug 12, 2023
 *  Author: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef LIB_BIT_MATH_H
#define LIB_BIT_MATH_H
/** ========================================================================= */




/** ====================== Defining The Bit Operations ====================== */
/* Bit oriented math */
#define SET_BIT(REG,BIT)			(REG) |=  (1 << (BIT))
#define CLR_BIT(REG,BIT)			(REG) &= ~(1 << (BIT))
#define TOG_BIT(REG,BIT)			(REG) ^=  (1 << (BIT))
#define GET_BIT(REG,BIT)			(((REG) >> (BIT)) & 1)

/* Byte oriented math */
#define SET_REG(REG,BYTE)					(REG |= BYTE)
#define WRITE_REG(REG,BYTE)					(REG = BYTE)
#define WRITE_VALUE(REG,VALUE,SHIFT)		((REG) |= ((VALUE) << (SHIFT)))
#define MASK(REG,VALUE)						((REG) &= (VALUE))
/** ========================================================================= */




#endif /* LIB_BIT_MATH_H_ */
/** ============================== END of File ============================== */
