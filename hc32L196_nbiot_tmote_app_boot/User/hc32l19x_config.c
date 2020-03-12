/**
  *********************************************************************************************************
  * @file    hc32l19x_config.c
  * @author  Movebroad -- KK
  * @version V1.0
  * @date    2020-03-09
  * @brief   1TAB = 5Speace
  *********************************************************************************************************
  * @attention
  *
  *
  *
  *********************************************************************************************************
  */

#include "hc32l19x_config.h"
#include "platform_config.h"
#include "platform_map.h"
#include "delay.h"
#include "usart.h"

HC32_RESET_FLAG_TypeDef			HC32_Reset_Flag = RCC_RESET_FLAG_NONE;

/**********************************************************************************************************
 @Function			HC32_RESET_FLAG_TypeDef HC32_SystemReset_GetStatus(void)
 @Description			HC32_SystemReset_GetStatus					: HC32获取复位标志位
 @Input				void
 @Return				HC32_RESET_FLAG_TypeDef						: 复位标志位
**********************************************************************************************************/
HC32_RESET_FLAG_TypeDef HC32_SystemReset_GetStatus(void)
{
	HC32_RESET_FLAG_TypeDef resetStatus = RCC_RESET_FLAG_NONE;
	
	if (Reset_GetFlag(ResetFlagMskPor5V) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_PORRST;
	}
	else if (Reset_GetFlag(ResetFlagMskPor1_5V) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_PORRST;
	}
	else if (Reset_GetFlag(ResetFlagMskLvd) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_LPWRRST;
	}
	else if (Reset_GetFlag(ResetFlagMskWdt) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_IWDGRST;
	}
	else if (Reset_GetFlag(ResetFlagMskPca) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_PCA;
	}
	else if (Reset_GetFlag(ResetFlagMskLockup) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_LOCKUP;
	}
	else if (Reset_GetFlag(ResetFlagMskSysreq) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_SFTRST;
	}
	else if (Reset_GetFlag(ResetFlagMskRstb) != FALSE) {
		Reset_ClearFlagAll();
		resetStatus = RCC_RESET_FLAG_PINRST;
	}
	
	return resetStatus;
}

/**********************************************************************************************************
 @Function			void HC32_LowPowerIO_Init(void)
 @Description			HC32_LowPowerIO_Init						: HC32低功耗IO初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
void HC32_LowPowerIO_Init(void)
{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

/**********************************************************************************************************
 @Function			static void Device_ModelPower_Init(void)
 @Description			Device_ModelPower_Init						: 外设模块电源初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
static void Device_ModelPower_Init(void)
{
	stc_gpio_cfg_t GPIO_Initure;
	
	DDL_ZERO_STRUCT(GPIO_Initure);
	
	GPIO_Initure.enDir			= GpioDirOut;
	GPIO_Initure.enDrv			= GpioDrvH;
	GPIO_Initure.enPu			= GpioPuDisable;
	GPIO_Initure.enPd			= GpioPdDisable;
	GPIO_Initure.enOD			= GpioOdDisable;
	GPIO_Initure.enCtrlMode		= GpioFastIO;
	Gpio_Init(MODEL_POWER_GPIOx, MODEL_POWER_PIN, &GPIO_Initure);
	
	MODEL_POWER_IO_SET(OFF);
}

/**********************************************************************************************************
 @Function			static void Device_RadarPower_Init(void)
 @Description			Device_RadarPower_Init						: 外设雷达电源初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
static void Device_RadarPower_Init(void)
{
	stc_gpio_cfg_t GPIO_Initure;
	
	DDL_ZERO_STRUCT(GPIO_Initure);
	
	GPIO_Initure.enDir			= GpioDirOut;
	GPIO_Initure.enDrv			= GpioDrvH;
	GPIO_Initure.enPu			= GpioPuDisable;
	GPIO_Initure.enPd			= GpioPdDisable;
	GPIO_Initure.enOD			= GpioOdDisable;
	GPIO_Initure.enCtrlMode		= GpioFastIO;
	Gpio_Init(RADAR_POWER_GPIOx, RADAR_POWER_PIN, &GPIO_Initure);
	
	RADAR_POWER_IO_SET(OFF);
}

/**********************************************************************************************************
 @Function			static void Device_NBIotPower_Init(void)
 @Description			Device_NBIotPower_Init						: 外设NBIoT电源初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
static void Device_NBIotPower_Init(void)
{
	stc_gpio_cfg_t GPIO_Initure;
	
	DDL_ZERO_STRUCT(GPIO_Initure);
	
	GPIO_Initure.enDir			= GpioDirOut;
	GPIO_Initure.enDrv			= GpioDrvH;
	GPIO_Initure.enPu			= GpioPuDisable;
	GPIO_Initure.enPd			= GpioPdDisable;
	GPIO_Initure.enOD			= GpioOdDisable;
	GPIO_Initure.enCtrlMode		= GpioFastIO;
	Gpio_Init(NBIOT_POWER_GPIOx, NBIOT_POWER_PIN, &GPIO_Initure);
	
	NBIOT_POWER_IO_SET(OFF);
}

/**********************************************************************************************************
 @Function			static void Device_VBatePower_Init(void)
 @Description			Device_VBatePower_Init						: 外设VBate电源初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
static void Device_VBatePower_Init(void)
{
	stc_gpio_cfg_t GPIO_Initure;
	
	DDL_ZERO_STRUCT(GPIO_Initure);
	
	GPIO_Initure.enDir			= GpioDirOut;
	GPIO_Initure.enDrv			= GpioDrvH;
	GPIO_Initure.enPu			= GpioPuDisable;
	GPIO_Initure.enPd			= GpioPdDisable;
	GPIO_Initure.enOD			= GpioOdDisable;
	GPIO_Initure.enCtrlMode		= GpioFastIO;
	Gpio_Init(VBATE_POWER_GPIOx, VBATE_POWER_PIN, &GPIO_Initure);
	
	VBATE_POWER_IO_SET(OFF);
}



















/**********************************************************************************************************
 @Function			void HC32_RstPowerIO_Init(void)
 @Description			HC32_RstPowerIO_Init						: HC32复位电源初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
void HC32_RstPowerIO_Init(void)
{
	stc_gpio_cfg_t GPIO_Initure;
	
	DDL_ZERO_STRUCT(GPIO_Initure);
	
	Device_ModelPower_Init();															//外设模块电源初始化
	Device_RadarPower_Init();															//外设雷达电源初始化
	Device_NBIotPower_Init();															//外设NBIoT电源初始化
	Device_VBatePower_Init();															//外设VBate电源初始化
	
	MODEL_POWER_IO_SET(OFF);																//外设模块电源关闭
	RADAR_POWER_IO_SET(OFF);																//外设雷达电源关闭
	NBIOT_POWER_IO_SET(OFF);																//外设NBIoT电源关闭
	VBATE_POWER_IO_SET(OFF);																//外设VBate电源关闭
	
	
	
	
	
	
	
	
	
	
	
	Delay_MS(3000);																	//外设断电3秒
}

/**********************************************************************************************************
 @Function			void HC32_CtrPowerIO_Init(void)
 @Description			HC32_CtrPowerIO_Init						: HC32控制电源初始化
 @Input				void
 @Return				void
**********************************************************************************************************/
void HC32_CtrPowerIO_Init(void)
{
	Device_ModelPower_Init();															//外设模块电源初始化
	Device_RadarPower_Init();															//外设雷达电源初始化
	Device_NBIotPower_Init();															//外设NBIoT电源初始化
	Device_VBatePower_Init();															//外设VBate电源初始化
	
	MODEL_POWER_IO_SET(OFF);																//外设模块电源关闭
	RADAR_POWER_IO_SET(OFF);																//外设雷达电源关闭
	NBIOT_POWER_IO_SET(OFF);																//外设NBIoT电源关闭
	VBATE_POWER_IO_SET(OFF);																//外设VBate电源关闭
}

















































































/********************************************** END OF FLEE **********************************************/