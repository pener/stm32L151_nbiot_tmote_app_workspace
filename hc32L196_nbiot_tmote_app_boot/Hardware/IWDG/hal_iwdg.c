/**
  *********************************************************************************************************
  * @file    hal_iwdg.c
  * @author  Movebroad -- KK
  * @version V1.0
  * @date    2020-03-04
  * @brief   
  *********************************************************************************************************
  * @attention
  *
  *
  *
  *********************************************************************************************************
  */

#include "platform_config.h"
#include "platform_map.h"
#include "hal_iwdg.h"
#include "delay.h"
#include "usart.h"

/**********************************************************************************************************
 @Function			void HC32_IWDG_Init(en_wdt_time_t enTime)
 @Description			HC32_IWDG_Init								: WDT初始化
 @Input				enTime									: WDT溢出时间
 @Return				void
**********************************************************************************************************/
void HC32_IWDG_Init(en_wdt_time_t enTime)
{
	/* WDT溢出复位 */
	Wdt_Init(WdtResetEn, enTime);
	
	/* 喂狗 */
	Wdt_Feed();
}

/********************************************** END OF FLEE **********************************************/
