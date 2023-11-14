/** ========================= The file information ========================== */
/**
 *  Project    : AVR_ATmega32_Driver.h
 * 	File name  : SPI_interface.h
 *  Created on : Oct 27, 2023
 *  Author     : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_SPI_INTERFACE_H_
#define MCAL_SPI_INTERFACE_H_
/** ========================================================================= */




/** ======================= SPI Functions Declaration ======================= */
void MCAL_SPI_MasterInit(void);

void MCAL_SPI_SlaveInit(void);

void MCAL_SPI_MasterTransmit(u8 Copy_Data);

u8 MCAL_SPI_SlaveReceive(void);
/** ========================================================================= */




#endif /* MCAL_SPI_INTERFACE_H_ */
/** ============================== END of File ============================== */
