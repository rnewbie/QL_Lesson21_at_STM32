/*
 * bsp.c
 *
 *  Created on: Dec 14, 2021
 *      Author: realmer
 */

#include "stm32f4xx.h"
#include "bsp.h"

static uint32_t volatile l_tickCntr;

void SysTick_Handler(void) {
	l_tickCntr++;
}

void BSP_init(void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN
			| RCC_AHB1ENR_GPIOCEN;
	GPIOA->MODER |= GPIO_MODER_MODE8_0 | GPIO_MODER_MODE9_0;
	GPIOB->MODER |= GPIO_MODER_MODE6_0;
	GPIOC->MODER |= GPIO_MODER_MODE7_0;

	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

	__enable_irq();
}

uint32_t BSP_tickCntr(void) {
	uint32_t tickCntr;

	__disable_irq();
	tickCntr = l_tickCntr;
	__enable_irq();

	return tickCntr;
}

void BSP_delay(uint32_t ticks) {
	uint32_t start = BSP_tickCntr();
	while ((BSP_tickCntr() - start) < ticks) {
		__NOP();
	}
}

void BSP_ledBlueOn(void) {
	LED_BLUE_PORT->BSRR = (1 << LED_BLUE_PIN);
}

void BSP_ledBlueOff(void) {
	LED_BLUE_PORT->BSRR = (1 << (LED_BLUE_PIN + 16));
}

void BSP_ledRedOn(void) {
	LED_RED_PORT->BSRR = (1 << LED_RED_PIN);
}

void BSP_ledRedOff(void) {
	LED_RED_PORT->BSRR = (1 << (LED_RED_PIN + 16));
}

void BSP_ledGreenOn(void) {
	LED_GREEN_PORT->BSRR = (1 << LED_GREEN_PIN);
}

void BSP_ledGreenOff(void) {
	LED_GREEN_PORT->BSRR = (1 << (LED_GREEN_PIN + 16));
}

void BSP_ledYellowOn(void) {
	LED_YELLOW_PORT->BSRR = (1 << LED_YELLOW_PIN);
}

void BSP_ledYellowOff(void) {
	LED_YELLOW_PORT->BSRR = (1 << (LED_YELLOW_PIN + 16));
}

