/** ========================= The file information ========================== */
/**
 *  Project     : AVR_ATmega32_Driver
 *  File name   : LCD_configuration.h
 *  Created on  : Aug 15, 2023
 *  Author      : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef HAL_LCD_LCD_CONFIG_H
#define HAL_LCD_LCD_CONFIG_H
/** ========================================================================= */




/** ============================= Configuration ============================= */
/* Configure the LCD pins */
#define RS				DIOA, PIN3
#define E				DIOA, PIN2
#define DB7				DIOB, PIN3
#define DB6				DIOB, PIN2
#define DB5				DIOB, PIN1
#define DB4				DIOB, PIN0


/* Configure the LCD type */
#define LCD_16x2 	(0)
#define LCD_40x2 	(1)
#define LCD_20x4 	(0)
/** ========================================================================= */




#endif /* HAL_LCD_LCD_CONFIG_H_ */
/** ============================== END of File ============================== */
