/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: GINT_program.h
 *  Created on	: Oct 23, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "GINT_interface.h"
#include "GINT_register.h"
/** ========================================================================= */




/** =================== EXTI Functions Implementation ======================= */
/* Set the Global Interrupt Enable flag in the SREG register */
void MCAL_GINT_SetGIE(void)
{
	SET_BIT(SREG,7);
}


/* Clear the Global Interrupt Enable flag in the SREG register */
void MCAL_GINT_ClearGIE(void)
{
	CLR_BIT(SREG,7);
}
/** ========================================================================= */
