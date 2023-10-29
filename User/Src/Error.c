/**
  ******************************************************************************
  * @file           : Error.c
  * @author         : sanmu
  * @brief          : Error display and handling
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-29
  * @version        : v1.0
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#include "Error.h"
#include "OLED.h"

/**
 * @brief Out of display error
 */
void errorOfR(){
    OLED_Clear();
    OLED_ShowString(1,1,"Error:");
    OLED_ShowString(2,1,"Out of Range!");
    OLED_ShowString(3,4,"Press '='");
    OLED_ShowString(4,2,"to Continue!");
}

/**
 * @brief The divisor is 0 error
 */
void errorDiv0()
{
    OLED_ShowString(4,1,"Err:/0 is Wrong!");
}
