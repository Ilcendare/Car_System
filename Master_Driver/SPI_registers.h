/** ========================= The file information ========================== */
/**
 *  Project    : AVR_ATmega32_Driver.h
 * 	File name  : SPI_register.h
 *  Created on : Oct 27, 2023
 *  Author     : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_SPI_REGISTERS_H_
#define MCAL_SPI_REGISTERS_H_
/** ========================================================================= */




/** ========================= Registers Definition ========================== */
typedef struct SPSR_struct{
	u8 SPI2X: 1;
	u8      : 5;
	u8 WCOL : 1;
	u8 SPIF : 1;
}SPSR_t;
#define SPSR ((volatile SPSR_t *)0x2E)


typedef struct SPCR_struct{
	u8 SPR : 2;
	u8 CPHA: 1;
	u8 CPOL: 1;
	u8 MSTR: 1;
	u8 DORD: 1;
	u8 SPE : 1;
	u8 SPIE: 1;
}SPCR_t;
#define SPCR ((volatile SPCR_t *)0x2D)


#define SPDR *((volatile u8 *)0x2F)
/** ========================================================================= */




#endif /* MCAL_SPI_REGISTERS_H_ */
/** ============================== END of File ============================== */
