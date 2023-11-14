/** ========================= The file information ========================== */
/**
 *  Project      : AVR_ATmega32_Driver
 *  File name    : DIO_program.c
 *  Created on   : Aug 12, 2023
 *  Author       : ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "BIT_Math.h"
#include "STD_Types.h"
#include "DIO_registers.h"
#include "DIO_interface.h"
#include "DIO_config.h"
/** ========================================================================= */




/** ======================= TWI Functions Implementation ==================== */
/*
 * To set the pin mode: DDRx = (0) -> Input | (1) -> Output
 */
void MCAL_DIO_voidSetPinMode(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_u8PINn, DIOMode_t Copy_DIOMode_tMode)
{
    if(Copy_DIOPort_tDIOx < 4)
    {
	if(Copy_u8PINn < 8)
	{
	    switch(Copy_DIOPort_tDIOx)
	    {
		case DIOA:			/* PORTA */
		    if(Copy_DIOMode_tMode)
		    {
		        SET_BIT(DDRA,Copy_u8PINn);
		    }
		    else
		    {
		        CLR_BIT(DDRA,Copy_u8PINn);
		        if(Copy_DIOMode_tMode == Input_Pullup)
		        {
			    SET_BIT(PORTA,Copy_u8PINn);
		        }
		        else
			{
			    CLR_BIT(PORTA,Copy_u8PINn);
			}
		    }
		    break;
		case DIOB:			/* PORTB */
		    if(Copy_DIOMode_tMode)
		    {
		        SET_BIT(DDRB,Copy_u8PINn);
		    }
		    else
		    {
		        CLR_BIT(DDRB,Copy_u8PINn);
		        if(Copy_DIOMode_tMode == Input_Pullup)
			{
			    SET_BIT(PORTB,Copy_u8PINn);
			}
		        else
			{
		            CLR_BIT(PORTB,Copy_u8PINn);
			}
		    }
		    break;
		case DIOC:			/* PORTC */
		    if(Copy_DIOMode_tMode)
		    {
		        SET_BIT(DDRC,Copy_u8PINn);
		    }
		    else
		    {
		        CLR_BIT(DDRC,Copy_u8PINn);
		        if(Copy_DIOMode_tMode == Input_Pullup)
		        {
			    SET_BIT(PORTC,Copy_u8PINn);
		        }
		        else
			{
			    CLR_BIT(PORTC,Copy_u8PINn);
			}
		    }
		    break;
		case DIOD:			/* PORTD */
		    if(Copy_DIOMode_tMode)
		    {
		        SET_BIT(DDRD,Copy_u8PINn);
		    }
		    else
		    {
		        CLR_BIT(DDRD,Copy_u8PINn);
		        if(Copy_DIOMode_tMode == Input_Pullup)
			{
			    SET_BIT(PORTD,Copy_u8PINn);
			}
		        else
			{
			    CLR_BIT(PORTD,Copy_u8PINn);
			}
		    }
		    break;
	    }
	}
	else
	{
	//Error_Handler();
	}
    }
    else
    {
    //Error_Handler();
    }
}


/*
 *  To write on a specific output pin from PROTx register
 */
void MCAL_DIO_voidWritePin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn, DIOState_t Copy_DIOState_tValue)
{
    if(Copy_DIOPort_tDIOx < 4)
    {
        if(Copy_DIOPin_tPINn < 8)
        {
            switch(Copy_DIOPort_tDIOx)
            {
                case DIOA:			/* PORTA */
		    if(Copy_DIOState_tValue)
		    {
		        SET_BIT(PORTA,Copy_DIOPin_tPINn);
		    }
		    else
		    {
		        CLR_BIT(PORTA,Copy_DIOPin_tPINn);
		    }
		    break;
                case DIOB:			/* PORTB */
		    if(Copy_DIOState_tValue)
		    {
		        SET_BIT(PORTB,Copy_DIOPin_tPINn);
		    }
		    else
		    {
		        CLR_BIT(PORTB,Copy_DIOPin_tPINn);
		    }
		    break;
                case DIOC:			/* PORTC */
		    if(Copy_DIOState_tValue)
		    {
		        SET_BIT(PORTC,Copy_DIOPin_tPINn);
		    }
		    else
		    {
		        CLR_BIT(PORTC,Copy_DIOPin_tPINn);
		    }
		    break;
                case DIOD:			/* PORTD */
		    if(Copy_DIOState_tValue)
		    {
		        SET_BIT(PORTD,Copy_DIOPin_tPINn);
		    }
		    else
		    {
		        CLR_BIT(PORTD,Copy_DIOPin_tPINn);
		    }
		    break;
            }
        }
    }
    else
    {
        //Error_Handler();
    }
}


/*
 * To read a specific output pin from PINx register
 */
u8 MCAL_DIO_u8ReadPin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn)
{
    u8 pinValue = 0;
    if(Copy_DIOPort_tDIOx < 4)
    {
	if(Copy_DIOPin_tPINn < 8)
	{
	    switch(Copy_DIOPort_tDIOx)
	    {
	        case DIOA:			/* PORTA */
		    pinValue = GET_BIT(PINA,Copy_DIOPin_tPINn);
		    break;
		case DIOB:			/* PORTB */
		    pinValue = GET_BIT(PINB,Copy_DIOPin_tPINn);
		    break;
		case DIOC:			/* PORTC */
		    pinValue = GET_BIT(PINC,Copy_DIOPin_tPINn);
		    break;
		case DIOD:			/* PORTD */
		    pinValue = GET_BIT(PIND,Copy_DIOPin_tPINn);
		    break;
	    }
	    return pinValue;
	}
	else
	{
	    //Error_Handler();
	    return 0xFF;
	}
    }
    else
    {
        //Error_Handler();
        return 0xFF;
    }
}


/*
 * To write on the whole PROTx register
 */
void MCAL_DIO_voidWriteWord(DIOPort_t Copy_DIOPort_tDIOx, u8 Copy_u8Word)
{
    if(Copy_DIOPort_tDIOx < 4)
    {
	switch(Copy_DIOPort_tDIOx)
	{
	    case DIOA:			/* PORTA */
		PORTA = Copy_u8Word;
		break;
	    case DIOB:			/* PORTB */
		PORTB = Copy_u8Word;
		break;
	    case DIOC:			/* PORTC */
		PORTC = Copy_u8Word;
		break;
	    case DIOD:			/* PORTD */
		PORTD = Copy_u8Word;
		break;
	}
    }
}


/*
 *  To read the whole PINx register
 */
u8 MCAL_DIO_u8WordRead(DIOPort_t Copy_DIOPort_tDIOx)
{
    u8 portValue = 0;
    if(Copy_DIOPort_tDIOx < 4)
    {
	switch(Copy_DIOPort_tDIOx)
	{
	    case DIOA:			/* PORTA */
		portValue = PINA;
		break;
	    case DIOB:			/* PORTB */
		portValue = PINB;
		break;
	    case DIOC:			/* PORTC */
		portValue = PINC;
		break;
	    case DIOD:			/* PORTD */
		portValue = PIND;
		break;
	    default:
		//No Code
		break;
	}
	return portValue;
    }
    else
    {
	return 0;
    }
}


/*
 * To toggle a certain pin.
 */
void MCAL_DIO_voidTogglePin(DIOPort_t Copy_DIOPort_tDIOx, DIOPin_t Copy_DIOPin_tPINn)
{
    if(Copy_DIOPort_tDIOx < 4)
    {
	if(Copy_DIOPin_tPINn < 8)
	{
	    switch(Copy_DIOPort_tDIOx)
	    {
		    case DIOA:			/* PORTA */
			TOG_BIT(PORTA,Copy_DIOPin_tPINn);
			break;
		    case DIOB:			/* PORTB */
			TOG_BIT(PORTB,Copy_DIOPin_tPINn);
			break;
		    case DIOC:			/* PORTC */
			TOG_BIT(PORTC,Copy_DIOPin_tPINn);
			break;
		    case DIOD:			/* PORTD */
			TOG_BIT(PORTD,Copy_DIOPin_tPINn);
			break;
	    }
	}
	else
	{
		//Error_Handler();
	}
    }
    else
    {
	    //Error_Handler();
    }
}


/*
 * To toggle a complete port register.
 */
void MCAL_DIO_voidTogglePort(DIOPort_t Copy_DIOPort_tDIOx)
{
    if(Copy_DIOPort_tDIOx < 4)
    {
	switch(Copy_DIOPort_tDIOx)
	{
	    case DIOA:			/* PORTA */
		PORTA ^= 0xFF;
		break;
	    case DIOB:			/* PORTB */
		PORTB ^= 0xFF;
		break;
	    case DIOC:			/* PORTC */
		PORTC ^= 0xFF;
		break;
	    case DIOD:			/* PORTD */
		PORTD ^= 0xFF;
		break;
	}
    }
    else
    {
	//Error_Handler();
    }
}
/** ========================================================================= */
