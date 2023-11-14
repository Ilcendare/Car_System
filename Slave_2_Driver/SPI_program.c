/** ========================= The file information ========================== */
/**
 *  Project    : AVR_ATmega32_Driver.h
 * 	File name  : SPI_program.c
 *  Created on : Oct 27, 2023
 *  Author     : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= All the included files ======================== */
#include <util/delay.h>
#include "BIT_Math.h"
#include "STD_Types.h"
#include "SPI_interface.h"
#include "SPI_registers.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "DIO_interface.h"
/** ========================================================================= */




/** ========================== SPI Defined Macros =========================== */
#define SPI_MOSI    DIOB, PIN5
#define SPI_MISO    DIOB, PIN6
#define SPI_SS	    DIOB, PIN4
#define SPI_SCK     DIOB, PIN7
/** ========================================================================= */




/** ========================= SPI Global Variables ========================== */

/** ========================================================================= */




/** ======================= SPI Functions Implementation ==================== */
void MCAL_SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	MCAL_DIO_voidSetPinMode(SPI_MOSI, Output);
	MCAL_DIO_voidSetPinMode(SPI_SCK , Output);
	MCAL_DIO_voidSetPinMode(SPI_MISO, Input );
	MCAL_DIO_voidSetPinMode(SPI_SS  , Input_Pullup );

	/* Enable SPI, Master, set clock rate f_sys/16 */
	SPCR->MSTR  = 1;
	SPCR->SPR   = SPI_CLOCK_RATE;
	SPSR->SPI2X = SPI_2XSPEED;
	SPCR->SPE   = 1;

	_delay_ms(1000);
}


void MCAL_SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	MCAL_DIO_voidSetPinMode(SPI_MOSI, Input);
	MCAL_DIO_voidSetPinMode(SPI_SCK , Input);
	MCAL_DIO_voidSetPinMode(SPI_MISO, Output );
	MCAL_DIO_voidSetPinMode(SPI_SS  , Input );

	/* Enable SPI */
	SPCR->SPE  = 1;
}


void MCAL_SPI_MasterTransmit(u8 Copy_Data)
{
	/* Start transmission, load the data byte to the SPI Data Register */
	SPDR = Copy_Data;

	/* Wait for transmission complete */
	while(!(SPSR->SPIF == 1));
}


u8 MCAL_SPI_SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR->SPIF == 1));

	/* Return data register */
	return SPDR;
}
/** ========================================================================= */
