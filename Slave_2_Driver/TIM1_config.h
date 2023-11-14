/*
 * TIM_config.h
 *
 *  Created on: Aug 24, 2023
 *  Author: ENG. Mahmoud Sayed
 */

#ifndef MCAL_TIM1_CONFIG_H
#define MCAL_TIM1_CONFIG_H

/* Clock source select for TIM1 */
/*
 * Choose from the following:
 * -> No clock source (Timer is off): 						TIM1_NO_CLK_SOURCE
 * -> No prescaling (system clock source is selected): 		TIM1_SYS_CLK
 * -> sys_clk/8 prescaler: 									TIM1_PRESCALER_8
 * -> sys_clk/64 prescaler:									TIM1_PRESCALER_64
 * -> sys_clk/256 prescaler:								TIM1_PRESCALER_256
 * -> sys_clk/1024 prescaler:								TIM1_PRESCALER_1024
 * -> External clock source (falling edge trigger)			TIM1_EXTERNAL_FALLING_EDGE
 * -> External clock source (rising edge trigger)			TIM1_EXTERNAL_RISING_EDGE
 */
#define TIM1_CLK_SOUCRE TIM1_PRESCALER_8
/** ======================================================================== **/

#endif /* MCAL_TIM1_CONFIG_H */
