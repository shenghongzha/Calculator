/**
  ******************************************************************************
  * @file           : calculate.c
  * @author         : sanmu
  * @brief          : Complex addition, subtraction, multiplication and division
  *                 @v1.1:Improvement of accuracy
  *                 @v1.2:Added delete and reset functions
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-28
  * @version        : v1.2
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#include "calculate.h"
#include "stdlib.h"

/**
 * @brief Determine whether the symbol is addition, subtraction, multiplication, and division
 * @param c  character
 * @return  ture return 1;false return 0
 */
uint8_t isSymbol(uint8_t c){
    if(c=='-'||c=='+'||c=='*'||c=='/')return 1;
    return 0;
}

/**
 * @brief Determine whether the symbol is number
 * @param c  character
 * @return ture return 1;false return 0
 */
uint8_t isNum(uint8_t c){
    if(c-'0'<=9 && 0 <= c - '0')return 1;
    return 0;
}

/**
 * @brief The mathematical expression is divided into symbol linked list and number linked list
 * @param handle mathematical expression
 * @param size  the length of mathematical expression
 * @param numHead   pointer to the head node of a linked list
 * @param symHead   pointer to the head node of a number linked list
 */
void process(uint8_t* handle,uint8_t size,numbers* numHead, symbols* symHead)
{

    numbers* currentNodeNum=numHead;
    symbols* currentNodeSym=symHead;
    uint8_t isSym = 0;
    uint8_t isNeg = 0;
    uint32_t isFrac = 0;
    uint8_t currentuint8_t;
    double currentNum = 0;
    for (uint8_t i = 0;i<size;i++)
    {
        currentuint8_t = handle[i];
        if(i == 0&&currentuint8_t == '-'){
            isNeg=1;
        }
        if(isNum(currentuint8_t)){
            isSym = 0;
            if(isFrac){
                currentNum += (currentuint8_t-'0')*1.0/isFrac;
                isFrac*=10;
            } else{
                currentNum = currentNum*10+(currentuint8_t-'0');
            }

        }
        if(currentuint8_t == '.')
        {
            isFrac=10;
        }
        if(i!=0&&isSymbol(currentuint8_t)){
            if(isSym &&(currentuint8_t=='-')){
                isNeg=1;
            }
            else{
                isSym = 1;
                if(isNeg)
                {
                    isNeg = 0;
                    isFrac = 0;
                    currentNodeNum->num=-currentNum;
                    currentNodeNum->next =(numbers*)malloc(sizeof(numbers));
                    currentNodeNum = currentNodeNum->next;
                    currentNum = 0;
                }
                else{
                    isFrac = 0;
                    currentNodeNum->num=currentNum;
                    currentNodeNum->next =(numbers*)malloc(sizeof(numbers));
                    currentNodeNum = currentNodeNum->next;
                    currentNum = 0;
                }
                currentNodeSym->sym = currentuint8_t;
                currentNodeSym->next = (symbols*) malloc(sizeof(symbols));
                currentNodeSym = currentNodeSym->next;
                currentNodeSym->sym = 0;
                currentNodeSym->next =NULL;
            }
        }
    }
    if(isNeg)
    {
        currentNodeNum->num=-currentNum;
        currentNodeNum->next = NULL;
    }
    else{
        currentNodeNum->num=currentNum;
        currentNodeNum->next =NULL;
    }

}

/**
 * @brief  Computed expression result
 * @param handle  mathematical expression
 * @param size  the length of mathematical expression
 * @param numHead  pointer to the result node of a linked list
 * @return expression error:correct return 1;incorrect return 0
 */
uint8_t calculate(uint8_t * handle,uint8_t size, numbers* numHead){
//    numbers* numHead = (numbers*)malloc(sizeof(numbers));
    symbols* symHead = (symbols*) malloc(sizeof(symbols));
    process(handle,size,numHead,symHead);
    numbers* currentNodeNum=numHead;
    symbols* currentNodeSym=symHead;
    numbers* freeNum;
    symbols* freeSym;
    while (currentNodeSym->sym!=0){
        switch (currentNodeSym->sym) {
            case '*':
                currentNodeNum->num *=currentNodeNum->next->num;
                freeNum = currentNodeNum->next;
                currentNodeNum->next = currentNodeNum->next->next;
                freeSym = currentNodeSym->next;
                currentNodeSym->sym = currentNodeSym->next->sym;
                currentNodeSym->next = currentNodeSym->next->next;
                free(freeNum);
                free(freeSym);
                break;
            case '/':
                if(currentNodeNum->next->num==0)return 0;
                currentNodeNum->num /=currentNodeNum->next->num;
                freeNum = currentNodeNum->next;
                currentNodeNum->next = currentNodeNum->next->next;
                freeSym = currentNodeSym->next;
                currentNodeSym->sym = currentNodeSym->next->sym;
                currentNodeSym->next = currentNodeSym->next->next;
                free(freeNum);
                free(freeSym);
                break;
            default:
            {
                currentNodeSym =currentNodeSym->next;
                currentNodeNum = currentNodeNum->next;
            }

        }
    }
    currentNodeSym =symHead;
    currentNodeNum = numHead;
    while (currentNodeSym->sym!=0){
        switch (currentNodeSym->sym) {
            case '-':
                currentNodeNum->num -=currentNodeNum->next->num;
                freeNum = currentNodeNum->next;
                currentNodeNum->next = currentNodeNum->next->next;
                freeSym = currentNodeSym->next;
                currentNodeSym->sym = currentNodeSym->next->sym;
                currentNodeSym->next = currentNodeSym->next->next;
                free(freeNum);
                free(freeSym);
                break;
            case '+':
                currentNodeNum->num +=currentNodeNum->next->num;
                freeNum = currentNodeNum->next;
                currentNodeNum->next = currentNodeNum->next->next;
                freeSym = currentNodeSym->next;
                currentNodeSym->sym = currentNodeSym->next->sym;
                currentNodeSym->next = currentNodeSym->next->next;
                free(freeNum);
                free(freeSym);
                break;
        }
    }
    return 1;
}
