/*
 * TIM_config.h
 *
 *  Created on: Aug 24, 2023
 *  Author: ENG. Mahmoud Sayed
 */

#ifndef MCAL_TIM0_CONFIG_H
#define MCAL_TIM0_CONFIG_H

/* Clock source select for TIM0 */
/*
 * Choose from the following:
 * -> No clock source (Timer is off): 						TIM0_NO_CLK_SOURCE
 * -> No prescaling (system clock source is selected): 		TIM0_SYS_CLK
 * -> sys_clk/8 prescaler: 									TIM0_PRESCALER_8
 * -> sys_clk/64 prescaler:									TIM0_PRESCALER_64
 * -> sys_clk/256 prescaler:								TIM0_PRESCALER_256
 * -> sys_clk/1024 prescaler:								TIM0_PRESCALER_1024
 * -> External clock source (falling edge trigger)			TIM0_EXTERNAL_FALLING_EDGE
 * -> External clock source (rising edge trigger)			TIM0_EXTERNAL_RISING_EDGE
 */
#define TIM0_CLK_SOUCRE TIM0_PRESCALER_1024

/** ======================================================================== **/

#endif /* MCAL_TIM0_CONFIG_H */
