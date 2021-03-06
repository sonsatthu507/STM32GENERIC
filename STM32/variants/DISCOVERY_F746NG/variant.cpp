#include <Arduino.h>

#include "stm32_gpio.h"

const stm32_port_pin_type variant_pin_list[] = {
  { GPIOC, GPIO_PIN_7 },
  { GPIOC, GPIO_PIN_6 },
  { GPIOG, GPIO_PIN_6 },
  { GPIOB, GPIO_PIN_4 },
  { GPIOG, GPIO_PIN_7 },
  { GPIOA, GPIO_PIN_8 },
  { GPIOH, GPIO_PIN_6 },
  { GPIOI, GPIO_PIN_3 },
  { GPIOI, GPIO_PIN_2 },
  { GPIOA, GPIO_PIN_15},
  { GPIOI, GPIO_PIN_0 },
  { GPIOB, GPIO_PIN_15},
  { GPIOB, GPIO_PIN_14},
  { GPIOI, GPIO_PIN_1 },
  { GPIOB, GPIO_PIN_9 },
  { GPIOB, GPIO_PIN_8 },
  { GPIOA, GPIO_PIN_0 },
  { GPIOF, GPIO_PIN_10},
  { GPIOF, GPIO_PIN_9 },
  { GPIOF, GPIO_PIN_8 },
  { GPIOF, GPIO_PIN_7 },
  { GPIOF, GPIO_PIN_6 },
  
  { GPIOA, GPIO_PIN_1 },
  { GPIOA, GPIO_PIN_2 },
  { GPIOA, GPIO_PIN_3 },
  { GPIOA, GPIO_PIN_4 },
  { GPIOA, GPIO_PIN_5 },
  { GPIOA, GPIO_PIN_6 },
  { GPIOA, GPIO_PIN_7 },
  { GPIOA, GPIO_PIN_9 },
  { GPIOA, GPIO_PIN_10},
  { GPIOA, GPIO_PIN_11},
  { GPIOA, GPIO_PIN_12},
  { GPIOA, GPIO_PIN_13},
  { GPIOA, GPIO_PIN_14},
  { GPIOB, GPIO_PIN_0 },
  { GPIOB, GPIO_PIN_1 },
  { GPIOB, GPIO_PIN_2 },
  { GPIOB, GPIO_PIN_3 },
  { GPIOB, GPIO_PIN_5 },
  { GPIOB, GPIO_PIN_6 },
  { GPIOB, GPIO_PIN_7 },
  { GPIOB, GPIO_PIN_10},
  { GPIOB, GPIO_PIN_11},
  { GPIOB, GPIO_PIN_12},
  { GPIOB, GPIO_PIN_13},
  { GPIOC, GPIO_PIN_0 },
  { GPIOC, GPIO_PIN_1 },
  { GPIOC, GPIO_PIN_2 },
  { GPIOC, GPIO_PIN_3 },
  { GPIOC, GPIO_PIN_4 },
  { GPIOC, GPIO_PIN_5 },
  { GPIOC, GPIO_PIN_8 },
  { GPIOC, GPIO_PIN_9 },
  { GPIOC, GPIO_PIN_10},
  { GPIOC, GPIO_PIN_11},
  { GPIOC, GPIO_PIN_12},
  { GPIOC, GPIO_PIN_13},
  { GPIOC, GPIO_PIN_14},
  { GPIOC, GPIO_PIN_15},
  { GPIOD, GPIO_PIN_0 },
  { GPIOD, GPIO_PIN_1 },
  { GPIOD, GPIO_PIN_2 },
  { GPIOD, GPIO_PIN_3 },
  { GPIOD, GPIO_PIN_4 },
  { GPIOD, GPIO_PIN_5 },
  { GPIOD, GPIO_PIN_6 },
  { GPIOD, GPIO_PIN_7 },
  { GPIOD, GPIO_PIN_8 },
  { GPIOD, GPIO_PIN_9 },
  { GPIOD, GPIO_PIN_10},
  { GPIOD, GPIO_PIN_11},
  { GPIOD, GPIO_PIN_12},
  { GPIOD, GPIO_PIN_13},
  { GPIOD, GPIO_PIN_14},
  { GPIOD, GPIO_PIN_15},
  { GPIOE, GPIO_PIN_0 },
  { GPIOE, GPIO_PIN_1 },
  { GPIOE, GPIO_PIN_2 },
  { GPIOE, GPIO_PIN_3 },
  { GPIOE, GPIO_PIN_4 },
  { GPIOE, GPIO_PIN_5 },
  { GPIOE, GPIO_PIN_6 },
  { GPIOE, GPIO_PIN_7 },
  { GPIOE, GPIO_PIN_8 },
  { GPIOE, GPIO_PIN_9 },
  { GPIOE, GPIO_PIN_10},
  { GPIOE, GPIO_PIN_11},
  { GPIOE, GPIO_PIN_12},
  { GPIOE, GPIO_PIN_13},
  { GPIOE, GPIO_PIN_14},
  { GPIOE, GPIO_PIN_15},
  { GPIOF, GPIO_PIN_0 },
  { GPIOF, GPIO_PIN_1 },
  { GPIOF, GPIO_PIN_2 },
  { GPIOF, GPIO_PIN_3 },
  { GPIOF, GPIO_PIN_4 },
  { GPIOF, GPIO_PIN_5 },
  { GPIOF, GPIO_PIN_11},
  { GPIOF, GPIO_PIN_12},
  { GPIOF, GPIO_PIN_13},
  { GPIOF, GPIO_PIN_14},
  { GPIOF, GPIO_PIN_15},
  { GPIOG, GPIO_PIN_0 },
  { GPIOG, GPIO_PIN_1 },
  { GPIOG, GPIO_PIN_2 },
  { GPIOG, GPIO_PIN_3 },
  { GPIOG, GPIO_PIN_4 },
  { GPIOG, GPIO_PIN_5 },
  { GPIOG, GPIO_PIN_8 },
  { GPIOG, GPIO_PIN_9 },
  { GPIOG, GPIO_PIN_10},
  { GPIOG, GPIO_PIN_11},
  { GPIOG, GPIO_PIN_12},
  { GPIOG, GPIO_PIN_13},
  { GPIOG, GPIO_PIN_14},
  { GPIOG, GPIO_PIN_15},
  { GPIOH, GPIO_PIN_0 },
  { GPIOH, GPIO_PIN_1 },
  { GPIOH, GPIO_PIN_2 },
  { GPIOH, GPIO_PIN_3 },
  { GPIOH, GPIO_PIN_4 },
  { GPIOH, GPIO_PIN_5 },
  { GPIOH, GPIO_PIN_7 },
  { GPIOH, GPIO_PIN_8 },
  { GPIOH, GPIO_PIN_9 },
  { GPIOH, GPIO_PIN_10},
  { GPIOH, GPIO_PIN_11},
  { GPIOH, GPIO_PIN_12},
  { GPIOH, GPIO_PIN_13},
  { GPIOH, GPIO_PIN_14},
  { GPIOH, GPIO_PIN_15},
  { GPIOI, GPIO_PIN_4 },
  { GPIOI, GPIO_PIN_5 },
  { GPIOI, GPIO_PIN_6 },
  { GPIOI, GPIO_PIN_7 },
  { GPIOI, GPIO_PIN_8 },
  { GPIOI, GPIO_PIN_9 },
  { GPIOI, GPIO_PIN_10},
  { GPIOI, GPIO_PIN_11},
  { GPIOI, GPIO_PIN_12},
  { GPIOI, GPIO_PIN_13},
  { GPIOI, GPIO_PIN_14},
  { GPIOI, GPIO_PIN_15},
  { GPIOJ, GPIO_PIN_0 },
  { GPIOJ, GPIO_PIN_1 },
  { GPIOJ, GPIO_PIN_2 },
  { GPIOJ, GPIO_PIN_3 },
  { GPIOJ, GPIO_PIN_4 },
  { GPIOJ, GPIO_PIN_5 },
  { GPIOJ, GPIO_PIN_6 },
  { GPIOJ, GPIO_PIN_7 },
  { GPIOJ, GPIO_PIN_8 },
  { GPIOJ, GPIO_PIN_9 },
  { GPIOJ, GPIO_PIN_10},
  { GPIOJ, GPIO_PIN_11},
  { GPIOJ, GPIO_PIN_12},
  { GPIOJ, GPIO_PIN_13},
  { GPIOJ, GPIO_PIN_14},
  { GPIOJ, GPIO_PIN_15},
  { GPIOK, GPIO_PIN_0 },
  { GPIOK, GPIO_PIN_1 },
  { GPIOK, GPIO_PIN_2 },
  { GPIOK, GPIO_PIN_3 },
  { GPIOK, GPIO_PIN_4 },
  { GPIOK, GPIO_PIN_5 },
  { GPIOK, GPIO_PIN_6 },
  { GPIOK, GPIO_PIN_7 },
};
