/*
 * TIM_registers.h
 *
 *  Created on: Aug 24, 2023
 *  Author: ENG. Mahmoud Sayed
 */

#ifndef MCAL_TIM_REGISTERS_H
#define MCAL_TIM_REGISTERS_H

/** Registers for Timer/counter Interrupt */
#define TIMSK 	*((volatile u8 *)0x59)
#define TIFR 	*((volatile u8 *)0x58)

/** Registers for Timer/Counter 0 */
#define OCR0 	*((volatile u8 *)0x5C)
#define TCNT0 	*((volatile u8 *)0x52)
#define TCCR0 	*((volatile u8 *)0x53)

/** Registers for Timer/Counter 1 */
#define TCCR1A 	*((volatile u8 *)0x4F)
#define TCCR1B 	*((volatile u8 *)0x4E)

#define TCNT1H 	*((volatile u8 *)0x4D)
#define TCNT1L 	*((volatile u8 *)0x4C)
#define TCNT1	*((volatile u16*)0x4C)

#define OCR1AH 	*((volatile u8 *)0x4B)
#define OCR1AL 	*((volatile u8 *)0x4A)
#define OCR1A 	*((volatile u16*)0x4A)

#define OCR1BH 	*((volatile u8 *)0x49)
#define OCR1BL 	*((volatile u8 *)0x48)
#define OCR1B 	*((volatile u16*)0x48)

#define ICR1H 	*((volatile u8 *)0x47)
#define ICR1L 	*((volatile u8 *)0x46)
#define ICR1 	*((volatile u16*)0x46)

/** Registers for Timer/Counter 2 */
#define OCR2 	*((volatile uint8 *)0x43)
#define TCNT2	*((volatile uint8 *)0x44)
#define TCCR2 	*((volatile uint8 *)0x45)

/** ================================================ **/
/** Defining macros for the TIM0 clock source select **/
#define TIM0_NO_CLK_SOURCE				0
#define	TIM0_SYS_CLK					1
#define	TIM0_PRESCALER_8				2
#define	TIM0_PRESCALER_64				3
#define	TIM0_PRESCALER_256				4
#define	TIM0_PRESCALER_1024				5
#define	TIM0_EXTERNAL_FALLING_EDGE		6
#define	TIM0_EXTERNAL_RISING_EDGE		7


/** Defining macros for the TIM1 clock source select **/
#define TIM1_NO_CLK_SOURCE				0
#define	TIM1_SYS_CLK					1
#define	TIM1_PRESCALER_8				2
#define	TIM1_PRESCALER_64				3
#define	TIM1_PRESCALER_256				4
#define	TIM1_PRESCALER_1024				5
#define	TIM1_EXTERNAL_FALLING_EDGE		6
#define	TIM1_EXTERNAL_RISING_EDGE		7


#endif /* MCAL_TIM_REGISTERS_H */
