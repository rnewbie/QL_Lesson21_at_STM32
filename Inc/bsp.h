/*
 * bsp.h
 *
 *  Created on: Dec 14, 2021
 *      Author: realmer
 */

#ifndef BSP_H_
#define BSP_H_

/* system clock tick [Hz] */
#define BSP_TICKS_PER_SEC (100U)

#define LED_BLUE_PORT	(GPIOA)
#define LED_BLUE_PIN	(8U)
#define LED_RED_PORT	(GPIOA)
#define LED_RED_PIN		(9U)
#define LED_YELLOW_PORT	(GPIOC)
#define LED_YELLOW_PIN	(7U)
#define LED_GREEN_PORT	(GPIOB)
#define LED_GREEN_PIN	(6U)

void BSP_init(void);

uint32_t BSP_tickCntr(void);
void BSP_delay(uint32_t ticks);

void BSP_ledBlueOn(void);
void BSP_ledBlueOff(void);
void BSP_ledRedOn(void);
void BSP_ledRedOff(void);
void BSP_ledYellowOn(void);
void BSP_ledYellowOff(void);
void BSP_ledGreenOn(void);
void BSP_ledGreenOff(void);

#endif /* BSP_H_ */
