/** ========================= The file information ========================== */
/**
 *  Project: AVR_ATmega32_Driver
 * 	File name: STD_Types.h
 *  Created on: Aug 12, 2023
 *  Author: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef LIB_STD_TYPES_H
#define LIB_STD_TYPES_H
/** ========================================================================= */




/** ====================== Defining The Standard Types ====================== */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;

#undef NULL
#define NULL (void *)0

#undef F_CPU
#define F_CPU 16000000U
/** ========================================================================= */




#endif /* LIB_STD_TYPES_H */
/** ============================== END of File ============================== */
