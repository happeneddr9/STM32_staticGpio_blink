/**
 * @Name    : EXTI_handler.h
 * @Date    : 2019年11月24日 下午4:37:09
 * @Author  : happe
 * @brief   :
 */

#ifndef GPIO_EXTI_HANDLER_H_
#define GPIO_EXTI_HANDLER_H_

#include "main.h"

extern "C" {
	void EXTI0_1_IRQHandler();

	void EXTI2_3_IRQHandler();
	void EXTI4_15_IRQHandler();
	void EXTI15_10_IRQHandler();
#if defined(STM32F051)
	void PVD_IRQHandler();
#endif
	void RTC_IRQHandler();
#if defined(STM32F051)
	void TS_IRQHandler();
#endif
}



#endif /* GPIO_EXTI_HANDLER_H_ */
