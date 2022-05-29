/*
 * config.c
 *
 *  Created on: May 29, 2022
 *      Author: asten
 */

#include <stdint.h>
#include "config.h"
#include "stm32g4xx_hal.h"

// https://stackoverflow.com/questions/28503808/allocating-memory-in-flash-for-user-data-stm32f4-hal

// FLASH: category 2 device
// https://www.st.com/resource/en/reference_manual/dm00355726-stm32g4-series-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf

//uint32_t* configBlockAddress = (uint32_t*) 0x0801f800;



__attribute__((__section__(".user_data"))) const uint8_t userConfig[32];



void FlashWrite() {
  HAL_FLASH_Unlock();

  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );

  FLASH_EraseInitTypeDef FLASH_EraseInitStruct;
  FLASH_EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
  FLASH_EraseInitStruct.Banks = FLASH_BANK_1;
  FLASH_EraseInitStruct.Page = 63;
  FLASH_EraseInitStruct.NbPages = 1;

  uint32_t eraseInfo;


  HAL_FLASHEx_Erase(&FLASH_EraseInitStruct, &eraseInfo);

  HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, (uint32_t) &userConfig[0], 0xffff0000ffffff00);
  HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, (uint32_t) &userConfig[16], 0xffff0000ffffff00);

  HAL_FLASH_Lock();
}



