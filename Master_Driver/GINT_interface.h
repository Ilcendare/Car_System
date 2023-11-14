/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: GINT_interface.h
 *  Created on	: Oct 23, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_GINT_INTERFACE_H
#define MCAL_GINT_INTERFACE_H
/** ========================================================================= */




/** ======================== Declaring GINT Functions ======================= */
/* Set the Global Interrupt Enable flag in the SREG register */
void MCAL_GINT_SetGIE(void);


/* Clear the Global Interrupt Enable flag in the SREG register */
void MCAL_GINT_ClearGIE(void);
/** ========================================================================= */




#endif /* MCAL_GINT_INTERFACE_H */
/** ============================== END of File ============================== */
