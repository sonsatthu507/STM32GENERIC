#include "stm32_gpio.h"

#include "variant.h"

void stm32GpioClock(GPIO_TypeDef *port) {
    
    #ifdef GPIOA
    if (port == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
    #endif
    #ifdef GPIOB
    if (port == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
    #endif
    #ifdef GPIOC
    if (port == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
    #endif
    #ifdef GPIOD
    if (port == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
    #endif
    #ifdef GPIOE
    if (port == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
    #endif
    #ifdef GPIOF
    if (port == GPIOF) __HAL_RCC_GPIOF_CLK_ENABLE();
    #endif
    #ifdef GPIOG
    if (port == GPIOG) __HAL_RCC_GPIOG_CLK_ENABLE();
    #endif
    #ifdef GPIOH
    if (port == GPIOH) __HAL_RCC_GPIOH_CLK_ENABLE();
    #endif
    #ifdef GPIOI
    if (port == GPIOI) __HAL_RCC_GPIOI_CLK_ENABLE();
    #endif
    #ifdef GPIOJ
    if (port == GPIOJ) __HAL_RCC_GPIOJ_CLK_ENABLE();
    #endif
    #ifdef GPIOK
    if (port == GPIOK) __HAL_RCC_GPIOK_CLK_ENABLE();
    #endif
}

void pinMode(uint8_t pin, uint8_t mode) {
    stm32_port_pin_type port_pin = variant_pin_list[pin];
    
    if (stm32_pwm_disable_callback != NULL) {
        (*stm32_pwm_disable_callback)(port_pin.port, port_pin.pin_mask);
    }

    stm32GpioClock(port_pin.port);
    
    GPIO_InitTypeDef init;
    
    init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    init.Pin = port_pin.pin_mask;
    
    switch ( mode ) {
      case INPUT:
        init.Mode = GPIO_MODE_INPUT;
        init.Pull =  GPIO_NOPULL;
        break;
      
      case INPUT_PULLUP:
        init.Mode = GPIO_MODE_INPUT;
        init.Pull =  GPIO_PULLUP;
        break;
        
      case INPUT_PULLDOWN:
        init.Mode = GPIO_MODE_INPUT;
        init.Pull =  GPIO_PULLDOWN;
        break;
        
      case OUTPUT:
        init.Mode = GPIO_MODE_OUTPUT_PP;
        init.Pull =  GPIO_NOPULL;
        break;
        
      default:
        return;
        break;
    }
    
    HAL_GPIO_Init(port_pin.port, &init);
    
}
