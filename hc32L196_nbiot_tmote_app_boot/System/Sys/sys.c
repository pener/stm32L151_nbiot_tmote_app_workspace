/**
  *********************************************************************************************************
  * @file    sys.c
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
#include "sys.h"
#include "flash.h"

/**********************************************************************************************************
 @Function			void HC32_PeripheralClockGate_Init(void)
 @Description			HC32_PeripheralClockGate_Init					: HC32外设时钟门控初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
void HC32_PeripheralClockGate_Init(void)
{
	/* -使能WDT外设时钟门控- */
	Sysctrl_SetPeripheralGate(SysctrlPeripheralWdt, TRUE);
	
	/* -使能SysTick外设时钟门控- */
	Sysctrl_SetPeripheralGate(SysctrlPeripheralTick, TRUE);
	
	/* -使能FLASH外设时钟门控- */
	Sysctrl_SetPeripheralGate(SysctrlPeripheralFlash, TRUE);
	
	/* -使能GPIO外设时钟门控- */
	Sysctrl_SetPeripheralGate(SysctrlPeripheralGpio, TRUE);
	
	/* -使能UART0外设时钟门控- */
	Sysctrl_SetPeripheralGate(SysctrlPeripheralUart0, TRUE);
	
	/* -使能UART1外设时钟门控- */
	Sysctrl_SetPeripheralGate(SysctrlPeripheralUart1, TRUE);
	
	
	
	
	
	
	
	
	
	
	
	
	
}

/**********************************************************************************************************
 @Function			void HC32_RCHClock_Init(void)
 @Description			HC32_RCHClock_Init							: HC32内部RCH高速时钟初始化48MHz
 @Input				void
 @Return				void
**********************************************************************************************************/
void HC32_RCHClock_Init(void)
{
	stc_sysctrl_pll_cfg_t stcPLLCfg;
	stc_sysctrl_clk_cfg_t stcCLKCfg;
	
	/* 1.step: RCH时钟不同频率切换, 需先将时钟切换到RCL, 设置好RCH频率后再切回 */
	
	/* 设定内部低速时钟RCL频率: 32.768KHz */
	Sysctrl_SetRCLTrim(SysctrlRclFreq32768);
	/* 开启内部低速时钟RCL */
	Sysctrl_ClkSourceEnable(SysctrlClkRCL, TRUE);
	/* 切换系统时钟为内部低速时钟RCL */
	Sysctrl_SysClkSwitch(SysctrlClkRCL);
	
	/* 2.step: 系统时钟已切换为RCL, 配置内部高速时钟RCH */
	
	/* 设定内部高速时钟RCH频率: 24MHz */
	Sysctrl_SetRCHTrim(SysctrlRchFreq24MHz);
	/* 开启内部高速时钟RCH */
	Sysctrl_ClkSourceEnable(SysctrlClkRCH, TRUE);
	
	/* 3.step: PLL锁相环配置 */
	
	/* PLL输入时钟频率范围: RCH 24MHz */
	stcPLLCfg.enInFreq			= SysctrlPllInFreq20_24MHz;
	/* PLL输出时钟频率范围: PLL 48MHz */
	stcPLLCfg.enOutFreq			= SysctrlPllOutFreq36_48MHz;
	/* PLL输入时钟源: RCH 24MHz */
	stcPLLCfg.enPllClkSrc		= SysctrlPllRch;
	/* PLL倍频系数: X2 */
	stcPLLCfg.enPllMul			= SysctrlPllMul2;
	/* PLL配置 */
	Sysctrl_SetPLLFreq(&stcPLLCfg);
	/* PLL稳定周期设置: 16384T */
	Sysctrl_SetPLLStableTime(SysctrlPllStableCycle16384);
	/* 开启PLL锁相环 */
	Sysctrl_ClkSourceEnable(SysctrlClkPLL, TRUE);
	
	/* 4.step: 当系统时钟HCLK大于24MHz, 需设置FLASH读等待周期至少为 1 cycle */
	Flash_WaitCycle(FlashWaitCycle1);
	
	/* 5.step: 系统时钟配置 */
	
	/* 时钟源选择: PLL时钟 */
	stcCLKCfg.enClkSrc			= SysctrlClkPLL;
	/* HCLK分频系数 */
	stcCLKCfg.enHClkDiv			= SysctrlHclkDiv1;
	/* PCLK分频系数 */
	stcCLKCfg.enPClkDiv			= SysctrlPclkDiv1;
	/* 系统时钟配置 */
	Sysctrl_ClkInit(&stcCLKCfg);
	
	/* 6.step: 关闭内部低速时钟RCL */
	Sysctrl_ClkSourceEnable(SysctrlClkRCL, FALSE);
}

/**********************************************************************************************************
 @Function			void HC32_XTHClock_Init(void)
 @Description			HC32_XTHClock_Init							: HC32外部XTH高速时钟初始化32MHz
 @Input				void
 @Return				void
**********************************************************************************************************/
void HC32_XTHClock_Init(void)
{
	stc_sysctrl_pll_cfg_t stcPLLCfg;
	stc_sysctrl_clk_cfg_t stcCLKCfg;
	
	/* 1.step: 外部高速时钟XTH配置 */
	
	/* 设定外部高速时钟XTH频率: 8MHz */
	Sysctrl_SetXTHFreq(SysctrlXthFreq6_12MHz);
	/* 设定外部高速时钟XTH驱动能力: 最强驱动 */
	Sysctrl_XTHDriverCfg(SysctrlXtalDriver3);
	/* 设定外部高速时钟XTH稳定周期: 16384T */
	Sysctrl_SetXTHStableTime(SysctrlXthStableCycle16384);
	/* 开启外部高速时钟XTH */
	Sysctrl_ClkSourceEnable(SysctrlClkXTH, TRUE);
	
	/* 2.step: PLL锁相环配置 */
	
	/* PLL输入时钟频率范围: XTH 8MHz */
	stcPLLCfg.enInFreq			= SysctrlPllInFreq6_12MHz;
	/* PLL输出时钟频率范围: PLL 32MHz */
	stcPLLCfg.enOutFreq			= SysctrlPllOutFreq24_36MHz;
	/* PLL输入时钟源: XTH 8MHz */
	stcPLLCfg.enPllClkSrc		= SysctrlPllXthXtal;
	/* PLL倍频系数: X4 */
	stcPLLCfg.enPllMul			= SysctrlPllMul4;
	/* PLL配置 */
	Sysctrl_SetPLLFreq(&stcPLLCfg);
	/* PLL稳定周期设置: 16384T */
	Sysctrl_SetPLLStableTime(SysctrlPllStableCycle16384);
	/* 开启PLL锁相环 */
	Sysctrl_ClkSourceEnable(SysctrlClkPLL, TRUE);
	
	/* 3.step: 当系统时钟HCLK大于24MHz, 需设置FLASH读等待周期至少为 1 cycle	*/
	Flash_WaitCycle(FlashWaitCycle1);
	
	/* 4.step: 系统时钟配置 */
	
	/* 时钟源选择: PLL时钟 */
	stcCLKCfg.enClkSrc			= SysctrlClkPLL;
	/* HCLK分频系数 */
	stcCLKCfg.enHClkDiv			= SysctrlHclkDiv1;
	/* PCLK分频系数 */
	stcCLKCfg.enPClkDiv			= SysctrlPclkDiv1;
	/* 系统时钟配置 */
	Sysctrl_ClkInit(&stcCLKCfg);
	
	/* 5.step: 关闭内部高速时钟RCH */
	Sysctrl_ClkSourceEnable(SysctrlClkRCH, FALSE);
}

/**********************************************************************************************************
 @Function			void HC32_SysTick_Init(void)
 @Description			HC32_SysTick_Init							: HC32系统嘀嗒定时器初始化
 @Input				void
 @Return				void
 @attention			时钟改变后嘀嗒定时器需重新配置
**********************************************************************************************************/
void HC32_SysTick_Init(void)
{
	/* 配置系统嘀嗒定时器 */
	SysTick_Config(SystemCoreClock / 1000);
}
































/**********************************************************************************************************
 @Function			void SysTick_IRQHandler(void)
 @Description			SysTick_IRQHandler							: HC32系统嘀嗒定时器中断处理
 @Input				void
 @Return				void
**********************************************************************************************************/
void SysTick_IRQHandler(void)
{
	HAL_IncTick();
}

/********************************************** END OF FLEE **********************************************/
