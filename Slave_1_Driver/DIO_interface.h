/** ========================= The file information ========================== */
/**
 *  Project      : AVR_ATmega32_Driver
 * 	File name    : DIO_Interface.h
 *  Created on   : Aug 12, 2023
 *  Author       : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ========================= The File Header Guard ========================= */
#ifndef MCAL_DIO_INTERFACE_H
#define MCAL_DIO_INTERFACE_H
/** ========================================================================= */




/** ========================= Defining Enumerations ========================= */
typedef enum DIOMode_enum {Input,Output,Input_Pullup} DIOMode_t;
typedef enum DIOState_enum {Low,High} DIOState_t;
typedef enum DIOPort_enum {DIOA,DIOB,DIOC,DIOD} DIOPort_t;
typedef enum DIOPin_enum {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7} DIOPin_t;
/** ========================================================================= */




/** ======================== Declaring DIO Functions ======================== */
/*
 * To set the pin mode: DDRx = (0) -> Input | (1) -> Output
 */
void MCAL_DIO_voidSetPinMode(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_u8PINn, DIOMode_t Copy_DIOMode_tMode);


/*
 * To write on a specific output pin from PROTx register
 */
void MCAL_DIO_voidWritePin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn, DIOState_t Copy_DIOState_tValue);


/*
 * To read a specific output pin from PINx register
 */
u8 MCAL_DIO_u8ReadPin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn);


/*
 *  To write on the whole PROTx register
 */
void MCAL_DIO_voidWriteWord(DIOPort_t Copy_DIOPort_tDIOx, u8 Copy_u8Word);


/*
 *  To read the whole PINx register
 */
u8 MCAL_DIO_u8WordRead(DIOPort_t Copy_DIOPort_tDIOx);


/*
 * To toggle a certain pin.
 */
void MCAL_DIO_voidTogglePin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn);


/*
 * To toggle a complete port register.
 */
void MCAL_DIO_voidTogglePort(DIOPort_t Copy_DIOPort_tDIOx);
/** ========================================================================= */




#endif /* MCAL_DIO_INTERFACE_H */
/** ============================== END of File ============================== */
