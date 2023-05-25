/*
 * cppmain.cpp
 *
 *  Created on: May 25, 2023
 *      Author: claytonfaria
 */
#include "cppmain.h"


[[noreturn]] void cppMain() {
    // do stuff
auto buttonState = GPIO_PIN_RESET;

    // main loop
    while (true) {
//      for (int i = 8; i <= 15; i++) {
//          auto pin = (uint16_t)(1 << i);
//
//          HAL_GPIO_WritePin(GPIOE, pin, GPIO_PIN_SET);
//          HAL_Delay(100);
//          HAL_GPIO_WritePin(GPIOE, pin, GPIO_PIN_RESET);
//      }
//
////      go back
//        for (int i = 15; i >= 8; i--) {
//            auto pin = (uint16_t)(1 << i);
//
//            HAL_GPIO_WritePin(GPIOE, pin, GPIO_PIN_SET);
//            HAL_Delay(100);
//            HAL_GPIO_WritePin(GPIOE, pin, GPIO_PIN_RESET);
//        }

////        make led blink on click
//        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) {
//            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
//            HAL_Delay(100);
//            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
//        }

        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET && buttonState == GPIO_PIN_SET) {
            for (int i = 8; i <= 15; i++) {
                uint16_t pin = GPIO_PIN_0 << i;
                HAL_GPIO_TogglePin(GPIOE, pin);
                HAL_Delay(100);
            }
            buttonState = GPIO_PIN_RESET;

        } else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) {
            buttonState = GPIO_PIN_SET;
        }

    }
}



