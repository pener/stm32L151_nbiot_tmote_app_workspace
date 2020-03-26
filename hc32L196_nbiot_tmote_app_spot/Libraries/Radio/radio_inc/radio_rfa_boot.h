#ifndef __RADIO_RFA_BOOT_H
#define   __RADIO_RFA_BOOT_H

#include "platform_config.h"
#include "radio_compiler_defs.h"
#include "radio_rfa_common.h"

#define Radio_Trf_Printf			Radio_RFA_Boot_Trf_Printf
#define Radio_Trf_Receive_Task	Radio_RFA_Boot_Trf_Receive_Task
#define Radio_Trf_Get_LastRecvtime	Radio_RFA_Boot_Trf_Get_Last_Recvtime

#define RADIO_RFA_BOOT_SDBUF_SIZE	256
#define RADIO_RFA_BOOT_RVBUF_SIZE	256
#define RADIO_RFA_BOOT_PTBUF_SIZE	128

#define RADIO_RFA_BOOT_MAX_PRINTF	30

typedef struct _radio_boot_trf_msg_h
{
	u32						destSN;
	u8						version;
	u8						type;
} __attribute__((packed)) radio_boot_trf_msghead_s;

typedef struct _radio_boot_trf_msg_m
{
	radio_boot_trf_msghead_s		head;
	s8						pData[1];
} __attribute__((packed)) radio_boot_trf_msgdata_s;

typedef struct _radio_boot_trf_heartbeat
{
	radio_boot_trf_msghead_s		head;
	u8						MajorSoftver;
	u8						SubSoftver;
	u8						DevType;
	u8						SubHardver;
	u8						WorkStatus;
} __attribute__((packed)) radio_boot_trf_heartbeat_s;

void Radio_RFA_Boot_Data_Handle_ISR(mrfiPacket_t* rfpacket);

char Radio_RFA_Boot_Receive(u8 *outmsg, u8 *len);

char Radio_RFA_Boot_Send(u8 *inmsg, u8 len);

void Radio_RFA_Boot_Cfg_Buildframe(u8 *inmsg, u8 pkttype, u8 pktnum, u32 sn, u8 *outsend, u8 len);

char Radio_RFA_Boot_Operate_Recvmsg(u8 *inmsg, u8 len);

u32  Radio_RFA_Boot_Trf_Get_Last_Recvtime(void);

void Radio_RFA_Boot_Trf_Receive_Task(void);

void Radio_RFA_Boot_Do_Xmit_Heartbeat(void);

void Radio_RFA_Boot_Xmit_Heartbeat(void);

void Radio_RFA_Boot_Do_RF_Printf(s8* info);

void Radio_RFA_Boot_Trf_Printf(const char *fmt, ...);

#endif /* __RADIO_RFA_BOOT_H */