/** ========================= The file information ========================== */
/**
 *  Project    : AVR_ATmega32_Driver.h
 * 	File name  : SPI_config.h
 *  Created on : Oct 27, 2023
 *  Author     : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_SPI_CONFIG_H_
#define MCAL_SPI_CONFIG_H_
/** ========================================================================= */




/** ============================= Configuration ============================= */
/*
 * Set the SPI clock (SCK) rate:
 * If the SPI 2X (Double speed) is disabled, use the following Macros:
 * - SPI-CLOCK_RATE_PRESCALER_4
 * - SPI-CLOCK_RATE_PRESCALER_16
 * - SPI-CLOCK_RATE_PRESCALER_64
 * - SPI-CLOCK_RATE_PRESCALER_128
 * If the SPI 2X (Double speed) is enabled, use the following Macros:
 * - SPI_CLOCK_RATE_2XSPEED_PRESCALER_2
 * - SPI_CLOCK_RATE_2XSPEED_PRESCALER_8
 * - SPI_CLOCK_RATE_2XSPEED_PRESCALER_32
 * - SPI_CLOCK_RATE_2XSPEED_PRESCALER_64
 */
#define SPI_CLOCK_RATE SPI_CLOCK_RATE_PRESCALER_16


/*
 * Enable/Disable the SPI double speed feature;
 * - To enable SPI double speed  -> SPI_ENABLE_2XSPEED
 * - To disable SPI double speed -> SPI_DISABLE_2XSPEED
 */
#define SPI_2XSPEED		SPI_DISABLE_2XSPEED
/** ========================================================================= */




#endif /* MCAL_SPI_CONFIG_H_ */
/** ============================== END of File ============================== */
