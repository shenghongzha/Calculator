/**
  ******************************************************************************
  * @file           : MatrixKey.c
  * @author         : sanmu
  * @brief          : Matrix keyboard scanning
  *                 @v1.1:Expand with two extra buttons
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-27
  * @version        : v1.1
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#include "MatrixKey.h"
#include "Keycode.h"

/**
 * @brief Matrix keyboard and expansion button scan code
 * @return key code
 */
uint8_t ScanKey(){
    uint8_t Key;
    Key = 0;
    HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
    if(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin) == GPIO_PIN_RESET){
        Key=16;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R2_GPIO_Port,R2_Pin) == GPIO_PIN_RESET){
        Key=12;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R3_GPIO_Port,R3_Pin) == GPIO_PIN_RESET){
        Key=8;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R4_GPIO_Port,R4_Pin) == GPIO_PIN_RESET){
        Key=4;
        HAL_Delay(20);
    }
    HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);

    HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
    if(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin) == GPIO_PIN_RESET){
        Key=15;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R2_GPIO_Port,R2_Pin) == GPIO_PIN_RESET){
        Key=11;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R3_GPIO_Port,R3_Pin) == GPIO_PIN_RESET){
        Key=7;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R4_GPIO_Port,R4_Pin) == GPIO_PIN_RESET){
        Key=3;
        HAL_Delay(20);
    }
    HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);

    HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
    if(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin) == GPIO_PIN_RESET){
        Key=14;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R2_GPIO_Port,R2_Pin) == GPIO_PIN_RESET){
        Key=10;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R3_GPIO_Port,R3_Pin) == GPIO_PIN_RESET){
        Key=6;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R4_GPIO_Port,R4_Pin) == GPIO_PIN_RESET){
        Key=2;
        HAL_Delay(20);
    }
    HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);

    HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
    if(HAL_GPIO_ReadPin(R1_GPIO_Port,R1_Pin) == GPIO_PIN_RESET){
        Key=13;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R2_GPIO_Port,R2_Pin) == GPIO_PIN_RESET){
        Key=9;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R3_GPIO_Port,R3_Pin) == GPIO_PIN_RESET){
        Key=5;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(R4_GPIO_Port,R4_Pin) == GPIO_PIN_RESET){
        Key=1;
        HAL_Delay(20);
    }
    HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
    /// \brief Extended functionality for calculators
    if(HAL_GPIO_ReadPin(Delete_GPIO_Port,Delete_Pin)==GPIO_PIN_SET){
        Key = 17;
        HAL_Delay(20);
    }
    if(HAL_GPIO_ReadPin(Reset_GPIO_Port,Reset_Pin)==GPIO_PIN_SET){
        Key=18;
        HAL_Delay(20);
    }
    //end

    return keycode[Key];
}

