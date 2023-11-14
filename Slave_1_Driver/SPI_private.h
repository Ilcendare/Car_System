/** ========================= The file information ========================== */
/**
 *  Project    : AVR_ATmega32_Driver.h
 * 	File name  : SPI_private.h
 *  Created on : Oct 27, 2023
 *  Author     : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_SPI_PRIVATE_H_
#define MCAL_SPI_PRIVATE_H_
/** ========================================================================= */




/** ===================== Defining Clock Rate Prescalers ==================== */
#define SPI_CLOCK_RATE_PRESCALER_4    0
#define SPI_CLOCK_RATE_PRESCALER_16   1
#define SPI_CLOCK_RATE_PRESCALER_64   2
#define SPI_CLOCK_RATE_PRESCALER_128  3
#define SPI_CLOCK_RATE_2XSPEED_PRESCALER_2    0
#define SPI_CLOCK_RATE_2XSPEED_PRESCALER_8    1
#define SPI_CLOCK_RATE_2XSPEED_PRESCALER_32   2
#define SPI_CLOCK_RATE_2XSPEED_PRESCALER_64   3

#define SPI_DISABLE_2XSPEED     0
#define SPI_ENABLE_2XSPEED      1
/** ========================================================================= */




#endif /* MCAL_SPI_PRIVATE_H_ */
/** ============================== END of File ============================== */
