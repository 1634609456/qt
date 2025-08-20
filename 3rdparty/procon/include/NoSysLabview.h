#ifndef _NOSYS_
#define _NOSYS_

typedef unsigned char UINT8;
typedef signed char INT8;

typedef unsigned short UINT16;
typedef short INT16;

typedef unsigned int UINT32;
typedef int INT32;

typedef signed long long INT64;
typedef unsigned long long UINT64;

#define NO_API NOS_RESULT_CODE __cdecl

typedef enum
{
	NOS_RET_OK = 0x00,

	NOS_RET_FUN = 0x01,

	NOS_RET_FAIL = 0x02,

	NOS_RET_NULL = 0x04,

	NOS_RET_PARA = 0x05,

	NOS_RET_SMEM = 0x06,

	NOS_RET_ADMIN = 0x07,

	NOS_RET_TIMEOUT = 0x10,

	NOS_RET_CMD = 0x11,

	NOS_RET_WAIT = 0x12,

	NOS_RET_CONNECT = 0x13,

	NOS_RET_INIT = 0x14,

	NOS_RET_BIND = 0x15,

	NOS_RET_LISTEN = 0x16,
}NOS_RESULT_CODE;

typedef enum
{
	NOS_FALSE = 0,

	NOS_TRUE = 1,
}NOS_BOOL;

typedef enum
{
	NOS_ECAT_A = 0,

	NOS_ECAT_B = 1,

	NOS_ECAT_C = 2,

	NOS_ECAT_D = 3,

	NOS_NODE_E = 4,

	NOS_NODE_F = 5,

	NOS_NODE_G = 6,

	NOS_NODE_H = 7,
}NOS_NODE;

typedef enum
{
	NOS_WAIT_TIMEOUT = 258,

	NOS_WAIT_FOREVER = -1,

	NOS_WAIT_FAILED = NOS_WAIT_FOREVER,

	NOS_STATUS_ABANDONED_WAIT_0 = 0x00000080,

	NOS_WAIT_ABANDONED_0 = NOS_STATUS_ABANDONED_WAIT_0+0,

	NOS_STATUS_WAIT_0 = 0x00000000,

	NOS_WAIT_OBJECT_0 = NOS_STATUS_WAIT_0+0,
}NOS_EVENT_CODE;

typedef enum
{
	NOS_SO_DEBUG = 0x0001,

	NOS_SO_ACCEPTCONN = 0x0002,

	NOS_SO_REUSEADDR = 0x0004,

	NOS_SO_KEEPALIVE = 0x0008,

	NOS_SO_DONTROUTE = 0x0010,

	NOS_SO_BROADCAST = 0x0020,

	NOS_SO_USELOOPBACK = 0x0040,

	NOS_SO_LINGER = 0x0080,

	NOS_SO_OOBINLINE = 0x0100,

	NOS_SO_REUSEPORT = 0x0200,

	NOS_SO_TIMESTAMP = 0x0400,

	NOS_SO_SNDBUF = 0x1001,

	NOS_SO_RCVBUF = 0x1002,

	NOS_SO_SNDLOWAT = 0x1003,

	NOS_SO_RCVLOWAT = 0x1004,

	NOS_SO_SNDTIMEO = 0x1005,

	NOS_SO_RCVTIMEO = 0x1006,
}NOS_OptionType;

typedef enum
{
	NOS_SHUT_RD = 0,

	NOS_SHUT_WR = 1,

	NOS_SHUT_RDWR = 2,
}NOS_ShutDownFlag;

typedef enum
{
	NOS_MSG_DONTWAIT = 0x000000080,
}NOS_MsgFlag;

NO_API NOS_GetVersion(UINT32* ver);

NO_API NOS_GetUsTick(UINT64* tick);

NO_API NOS_SleepUs(UINT32 us);

NO_API NOS_SetNode(NOS_NODE node);

NO_API NOS_SetRtaName(char* name);

NO_API NOS_InitShareMemory(char* rta_name, UINT64 handle);

NO_API NOS_CreateShareMemory(char* name, UINT32 size, UINT64* addr);

NO_API NOS_OpenShareMemory(NOS_NODE nodeIndex, char *rta_name, char* mem_name, UINT64* addr, NOS_BOOL rtos);

NO_API NOS_ReadShareMemory(UINT64 addr, UINT32 offset, UINT8* data, UINT32 num);

NO_API NOS_WriteShareMemory(UINT64 addr, UINT32 offset, UINT8* data, UINT32 num);

NO_API NOS_CreateEvent(UINT32 ManualReset, UINT32 bInitialState, char* name, UINT64 *handle);

NO_API NOS_OpenEvent(char* name, UINT64* handle, NOS_BOOL rtos);

NO_API NOS_CloseEvent(UINT64 handle, NOS_BOOL rtos);

NO_API NOS_PulseEvent(UINT64 handle, NOS_BOOL rtos);

NO_API NOS_ResetEvent(UINT64 handle, NOS_BOOL rtos);

NO_API NOS_SetEvent(UINT64 handle, NOS_BOOL rtos);

NO_API NOS_WaitForSingleObject(UINT64 hHandle, NOS_BOOL rtos, UINT32 dwMilliseconds, NOS_EVENT_CODE* result);

NO_API NOS_WaitForMultipleObjects(UINT64* lpHandles, NOS_BOOL rtos, UINT32 nCount, UINT32 dwMillisecond, NOS_EVENT_CODE* result);


NO_API NOS_CreateMutex(char* name, NOS_BOOL bInitialState, UINT64* handle);

NO_API NOS_OpenMutex(char* name, UINT64* handle, NOS_BOOL rtos);

NO_API NOS_WaitMutex(UINT64 handle, NOS_BOOL rtos, double timeout);

NO_API NOS_ReleaseMutex(UINT64 handle, NOS_BOOL rtos);

NO_API NOS_CloseMutex(UINT64 handle, NOS_BOOL rtos);

NO_API NOS_CreateLogger(UINT32 channel, UINT32 size);

NO_API NOS_OpenLogger(NOS_NODE nodeIndex, char* rta_name, UINT32 channel, NOS_BOOL rtos);

NO_API NOS_WriteLogger(UINT32 channel, char* msg);

NO_API NOS_ReadLogger(UINT32 channel, char* msg, UINT32 buff_size, UINT32* revd_size);

NO_API NOS_UdpCreate(UINT64 *handle, UINT32 flags);

NO_API NOS_UdpBind(UINT64 handle, UINT32 port);

NO_API NOS_UdpSend(UINT64 handle, char* ipaddr, UINT32 ipport, char* buffer, UINT32 size, INT32* sendNum);

NO_API NOS_UdpRecv(UINT64 handle, char* buffer, UINT32 size, char* ipaddr, UINT32 *ipport, INT32* revNum);

NO_API NOS_TcpClientConnect(char* ipaddr, UINT32 ipport, UINT32 flags, UINT64* handle);

NO_API NOS_TcpServerInit(UINT32 port, UINT32 nBackLog, UINT32 flags, UINT64 *handle);

NO_API NOS_TcpServerAccept(UINT64 handle, UINT64* newHandle, char* clientIpaddr, UINT32* clientPort);

NO_API NOS_SetSocketOption(UINT64 handle, NOS_OptionType optionName, INT32* value, INT32 valueLen);

NO_API NOS_TcpSend(UINT64 handle, char* buffer, UINT32 bufferLen, INT32* sendNum);

NO_API NOS_TcpRecv(UINT64 handle, char* buffer, UINT32 bufferLen, INT32 *revdNum);

NO_API NOS_CloseSocket(UINT64 handle, NOS_ShutDownFlag flag);

NO_API NOS_MBusServerInit(UINT32 port);

NO_API NOS_MBusServerSetWordOp(UINT64 ReadFun, UINT64 WriteFun);

NO_API NOS_MBusServerSetBitOp(UINT64 ReadFun, UINT64 WriteFun);

NO_API NOS_MbusClientConnect(char* ipaddr, UINT32 ipport, UINT32 flags, UINT32 timeout, UINT64* handle);

NO_API NOS_MbusClientClose(UINT64 handle);

NO_API NOS_MbusClientReadWord(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);

NO_API NOS_MbusClientWriteWord(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);

NO_API NOS_MbusClientReadBit(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);

NO_API NOS_MbusClientWriteBit(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);

NO_API NOS_OpenComm(char *com_name, INT32* handle);

NO_API NOS_CloseComm(INT32 handle);

NO_API NOS_SetCommConfig(INT32 handle, UINT32 baud, UINT32 parity, UINT32 dataBit, UINT32 stopBit);

NO_API NOS_ReadComm(INT32 handle, UINT8 *buffer, UINT32 size, UINT32 *reved);

NO_API NOS_WriteComm(INT32 handle, UINT8* buffer, UINT32 size, UINT32* reved);

NO_API NOS_SetupComm(INT32 handle, UINT32 inQueue, UINT32 outQueue);

NO_API NOS_FlushCommBuffers(INT32 handle);

NO_API NOS_PurgeComm(INT32 handle, UINT32 flags);


#endif
