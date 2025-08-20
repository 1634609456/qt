#ifndef _NOFUNS_
#define _NOFUNS_


#pragma region 数据类型
typedef unsigned char UINT8;
typedef signed char INT8;

typedef unsigned short UINT16;
typedef short INT16;

typedef unsigned int UINT32;
typedef int INT32;

typedef signed long long INT64;
typedef unsigned long long UINT64;

#define NO_API NOS_RESULT_CODE __cdecl
#pragma endregion


#pragma region 数据回调
typedef void(*ThreadCallBack)(void* lpThreadParameter);

typedef UINT16(*NOS_MBusReadWord)(UINT32 slave, UINT32 index);
typedef void(*NOS_MbusWriteWord)(UINT32 slave, UINT32 index, UINT16 value);
typedef UINT32(*NOS_MBusReadBit)(UINT32 slave, UINT32 index);
typedef void(*NOS_MBusWriteBit)(UINT32 slave, UINT32 index, UINT32 value);
#pragma endregion

#pragma region 枚举定义
/// <summary>
/// 函数返回值定义
/// </summary>
typedef enum _NOS_RESULT_CODE
{
	/// <summary>
	/// 正常
	/// </summary>
	NOS_RET_OK = 0x00,

	/// <summary>
	/// 不支持的函数
	/// </summary>
	NOS_RET_FUN = 0x01,

	/// <summary>
	/// 函数执行失败
	/// </summary>
	NOS_RET_FAIL = 0x02,

	/// <summary>
	/// 参数为空
	/// </summary>
	NOS_RET_NULL = 0x04,

	/// <summary>
	/// 参数越界
	/// </summary>
	NOS_RET_PARA = 0x05,

	/// <summary>
	/// 执行前先调用NOS_InitShareMemory初始化共享内存
	/// </summary>
	NOS_RET_SMEM = 0x06,

	/// <summary>
	/// 当前操作需要管理员权限
	/// </summary>
	NOS_RET_ADMIN = 0x07,

	/// <summary>
	/// 接收数据超时
	/// </summary>
	NOS_RET_TIMEOUT = 0x10,

	/// <summary>
	/// MODBUS指令命令不匹配
	/// </summary>
	NOS_RET_CMD = 0x11,

	/// <summary>
	/// 等待命令完成
	/// </summary>
	NOS_RET_WAIT = 0x12,

	/// <summary>
	/// 通讯未连接
	/// </summary>
	NOS_RET_CONNECT = 0x13,

	/// <summary>
	/// 通讯未初始化
	/// </summary>
	NOS_RET_INIT = 0x14,

	/// <summary>
	/// 通讯绑定失败
	/// </summary>
	NOS_RET_BIND = 0x15,

	/// <summary>
	/// 通讯监听失败
	/// </summary>
	NOS_RET_LISTEN = 0x16,
}NOS_RESULT_CODE;

/// <summary>
/// BOOL类型
/// </summary>
typedef enum _NOS_BOOL
{
	/// <summary>
	/// 假
	/// </summary>
	NOS_FALSE = 0,

	/// <summary>
	/// 真
	/// </summary>
	NOS_TRUE = 1,
}NOS_BOOL;

/// <summary>
/// 节点选择
/// </summary>
typedef enum _NOS_NODE
{
	/// <summary>
	/// 节点A
	/// </summary>
	NOS_ECAT_A = 0,

	/// <summary>
	/// 节点B
	/// </summary>
	NOS_ECAT_B = 1,

	/// <summary>
	/// 节点C
	/// </summary>
	NOS_ECAT_C = 2,

	/// <summary>
	/// 节点D
	/// </summary>
	NOS_ECAT_D = 3,

	/// <summary>
	/// 节点E
	/// </summary>
	NOS_NODE_E = 4,

	/// <summary>
	/// 节点F
	/// </summary>
	NOS_NODE_F = 5,

	/// <summary>
	/// 节点G
	/// </summary>
	NOS_NODE_G = 6,

	/// <summary>
	/// 节点H
	/// </summary>
	NOS_NODE_H = 7,
}NOS_NODE;

/// <summary>
/// 事件类型
/// </summary>
typedef enum _NOS_EVENT_CODE
{
	/// <summary>
	/// 超时时间已到
	/// </summary>
	NOS_WAIT_TIMEOUT = 258,

	/// <summary>
	/// 
	/// </summary>
	NOS_WAIT_FOREVER = -1,

	/// <summary>
	/// 无效的句柄
	/// </summary>
	NOS_WAIT_FAILED = NOS_WAIT_FOREVER,

	/// <summary>
	/// 
	/// </summary>
	NOS_STATUS_ABANDONED_WAIT_0 = 0x00000080,

	/// <summary>
	/// 指定事件被删除
	/// </summary>
	NOS_WAIT_ABANDONED_0 = NOS_STATUS_ABANDONED_WAIT_0+0,

	/// <summary>
	/// 
	/// </summary>
	NOS_STATUS_WAIT_0 = 0x00000000,

	/// <summary>
	/// 指定事件被激活
	/// </summary>
	NOS_WAIT_OBJECT_0 = NOS_STATUS_WAIT_0+0,
}NOS_EVENT_CODE;

/// <summary>
/// socket选项
/// </summary>
typedef enum _NOS_OptionType
{
	/// <summary>
	/// turn on debugging info recording
	/// </summary>
	NOS_SO_DEBUG = 0x0001,

	/// <summary>
	/// socket has had listen
	/// </summary>
	NOS_SO_ACCEPTCONN = 0x0002,

	/// <summary>
	/// allow local address reuse
	/// </summary>
	NOS_SO_REUSEADDR = 0x0004,

	/// <summary>
	/// keep connections alive
	/// </summary>
	NOS_SO_KEEPALIVE = 0x0008,

	/// <summary>
	/// just use interface addresses
	/// </summary>
	NOS_SO_DONTROUTE = 0x0010,

	/// <summary>
	/// permit sending of broadcast msgs
	/// </summary>
	NOS_SO_BROADCAST = 0x0020,

	/// <summary>
	/// bypass hardware when possible
	/// </summary>
	NOS_SO_USELOOPBACK = 0x0040,

	/// <summary>
	/// linger on close if data present
	/// </summary>
	NOS_SO_LINGER = 0x0080,

	/// <summary>
	/// leave received OOB data in line
	/// </summary>
	NOS_SO_OOBINLINE = 0x0100,

	/// <summary>
	/// allow local address port reuse
	/// </summary>
	NOS_SO_REUSEPORT = 0x0200,

	/// <summary>
	/// timestamp received dgram traffic
	/// </summary>
	NOS_SO_TIMESTAMP = 0x0400,

	/// <summary>
	/// send buffer size
	/// </summary>
	NOS_SO_SNDBUF = 0x1001,

	/// <summary>
	/// receive buffer size
	/// </summary>
	NOS_SO_RCVBUF = 0x1002,

	/// <summary>
	/// send low-water mark
	/// </summary>
	NOS_SO_SNDLOWAT = 0x1003,

	/// <summary>
	/// receive low-water mark
	/// </summary>
	NOS_SO_RCVLOWAT = 0x1004,

	/// <summary>
	/// send timeout
	/// </summary>
	NOS_SO_SNDTIMEO = 0x1005,

	/// <summary>
	/// receive timeout
	/// </summary>
	NOS_SO_RCVTIMEO = 0x1006,
}NOS_OptionType;

/// <summary>
/// socket关闭策略
/// </summary>
typedef enum _NOS_ShutDownFlag
{
	/// <summary>
	/// shut down the reading side
	/// </summary>
	NOS_SHUT_RD = 0,

	/// <summary>
	/// shut down the writing side
	/// </summary>
	NOS_SHUT_WR = 1,

	/// <summary>
	/// shut down both sides
	/// </summary>
	NOS_SHUT_RDWR = 2,
}NOS_ShutDownFlag;

/// <summary>
/// 消息控制策略
/// </summary>
typedef enum _NOS_MsgFlag
{
	/// <summary>
	/// 非阻塞
	/// </summary>
	NOS_MSG_DONTWAIT = 0x000000080,
}NOS_MsgFlag;
#pragma endregion

#pragma region 基本
/// <summary>
/// 获取内部版本号
/// </summary>
/// <param name="ver"></param>
/// <returns></returns>
NO_API NOS_GetVersion(UINT32* ver);

/// <summary>
/// 获取系统时钟(微秒单位)
/// </summary>
/// <param name="tick"></param>
/// <returns></returns>
NO_API NOS_GetUsTick(UINT64* tick);

/// <summary>
/// 微秒延时，分辨率为实时系统的最小调度周期
/// </summary>
/// <param name="us">微秒单位</param>
/// <returns></returns>
NO_API NOS_SleepUs(UINT32 us);

/// <summary>
/// 选中节点
/// </summary>
/// <param name="node">节点</param>
/// <returns></returns>
NO_API NOS_SetNode(NOS_NODE node);

/// <summary>
/// 设置进程名称
/// </summary>
/// <param name="name">名称,最多12个英文字符</param>
/// <returns></returns>
NO_API NOS_SetRtaName(char* name);
#pragma endregion

#pragma region 共享内存
/// <summary>
/// 共享内存初始化
/// </summary>
/// <param name="rta_name">进程名称，12个英文字符以内</param>
/// <param name="handle">保留，固定填0</param>
/// <returns></returns>
NO_API NOS_InitShareMemory(char* rta_name, UINT64 handle);

/// <summary>
/// 创建共享内存
/// </summary>
/// <param name="name">共享内存名称，8个英文字符以内</param>
/// <param name="size">内存大小，字节单位</param>
/// <param name="addr">返回内存地址</param>
/// <returns></returns>
NO_API NOS_CreateShareMemory(char* name, UINT32 size, UINT64* addr);

/// <summary>
/// 打开共享内存
/// </summary>
/// <param name="nodeIndex">创建共享内存进程所在的节点</param>
/// <param name="rta_name">进程名称</param>
/// <param name="mem_name">共享内存名称</param>
/// <param name="addr">首地址</param>
/// <param name="rtos">FALSE:windows创建的内存 TRUE:rtos创建的内存</param>
/// <returns></returns>
NO_API NOS_OpenShareMemory(NOS_NODE nodeIndex, char *rta_name, char* mem_name, UINT64* addr, NOS_BOOL rtos);

/// <summary>
/// 读共享内存
/// </summary>
/// <param name="addr">共享内存首地址</param>
/// <param name="offset">偏移量，字节单位</param>
/// <param name="data">缓冲区，存放读入数据</param>
/// <param name="num">读取数量，字节单位</param>
/// <returns></returns>
NO_API NOS_ReadShareMemory(UINT64 addr, UINT32 offset, UINT8* data, UINT32 num);

/// <summary>
/// 写共享内存
/// </summary>
/// <param name="addr">共享内存首地址</param>
/// <param name="offset">偏移量，字节单位</param>
/// <param name="data">缓冲区，存放写入数据</param>
/// <param name="num">写入数量，字节单位</param>
/// <returns></returns>
NO_API NOS_WriteShareMemory(UINT64 addr, UINT32 offset, UINT8* data, UINT32 num);
#pragma endregion

#pragma region 事件
/// <summary>
/// 创建事件
/// </summary>
/// <param name="ManualReset">0:当一个等待线程被释放后，系统自动重置事件 1:使用ResetEvent手动将事件重置为无信号状态。</param>
/// <param name="bInitialState">指定初始状态 0:无信号 1:有信号</param>
/// <param name="name">事件名称，仅限于英文字符</param>
/// <param name="handle">返回的事件句柄</param>
/// <returns></returns>
NO_API NOS_CreateEvent(UINT32 ManualReset, UINT32 bInitialState, char* name, UINT64 *handle);

/// <summary>
/// 打开由NOS_CreateEvent创建的事件
/// </summary>
/// <param name="name">事件名称</param>
/// <param name="handle">返回的事件句柄</param>
/// <param name="rtos">0:windows创建的事件 1:rtos创建的事件</param>
/// <returns></returns>
NO_API NOS_OpenEvent(char* name, UINT64* handle, NOS_BOOL rtos);

/// <summary>
/// 关闭事件句柄
/// </summary>
/// <param name="handle">事件句柄</param>
/// <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
/// <returns></returns>
NO_API NOS_CloseEvent(UINT64 handle, NOS_BOOL rtos);

/// <summary>
/// 将指定的事件对象设置为有信号，然后在释放适当数量的等待线程后将其重置为无信号。
/// </summary>
/// <param name="handle">事件句柄</param>
/// <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
/// <returns>0:失败 非0:成功</returns>
NO_API NOS_PulseEvent(UINT64 handle, NOS_BOOL rtos);

/// <summary>
/// 将事件置为无信号状态
/// </summary>
/// <param name="handle">事件句柄</param>
/// <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
/// <returns>0:失败 非0:成功</returns>
NO_API NOS_ResetEvent(UINT64 handle, NOS_BOOL rtos);

/// <summary>
/// 将事件置为有信号状态
/// </summary>
/// <param name="handle">事件句柄</param>
/// <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
/// <returns>0:失败 非0:成功</returns>
NO_API NOS_SetEvent(UINT64 handle, NOS_BOOL rtos);

/// <summary>
/// 等待单个事件
/// </summary>
/// <param name="hHandle">事件句柄</param>
/// <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
/// <param name="dwMilliseconds">超时时间(毫秒单位), INFINITE(0xFFFFFFFF)为永不超时</param>
/// <param name="result">返回代码</param>
/// <returns></returns>
NO_API NOS_WaitForSingleObject(UINT64 hHandle, NOS_BOOL rtos, UINT32 dwMilliseconds, NOS_EVENT_CODE* result);

/// <summary>
/// 等待多个事件
/// </summary>
/// <param name="nCount">事件数量</param>
/// <param name="lpHandles">事件句柄</param>
/// <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
/// <param name="dwMillisecond">超时时间(毫秒单位), INFINITE(0xFFFFFFFF)为永不超时</param>
/// <param name="result">返回代码</param>
/// <returns></returns>
NO_API NOS_WaitForMultipleObjects(UINT64* lpHandles, NOS_BOOL rtos, UINT32 nCount, UINT32 dwMillisecond, NOS_EVENT_CODE* result);
#pragma endregion

#pragma region 线程
/// <summary>
/// 创建线程，栈大小为1Mbyte
/// </summary>
/// <param name="routine">主函数</param>
/// <param name="para">参数</param>
/// <param name="handle">线程句柄</param>
/// <returns></returns>
NO_API NOS_CreateThread(ThreadCallBack routine, void* para, UINT64* handle);

/// <summary>
/// 关闭由NOS_CreateThread创建的线程句柄
/// </summary>
/// <param name="handle">句柄</param>
/// <returns></returns>
NO_API NOS_CloseThreadHandle(UINT64 handle);

/// <summary>
/// 设置NOS_CreateThread线程的优先级
/// </summary>
/// <param name="handle">句柄</param>
/// <param name="priority">优先级(THREAD_PRIORITY_IDLE to THREAD_PRIORITY_TIME_CRITICAL)</param>
/// <returns></returns>
NO_API NOS_SetThreadPriority(UINT64 handle, INT32 priority);

/// <summary>
/// 创建定时器
/// </summary>
/// <param name="handle">主函数</param>
/// <param name="para">参数</param>
/// <param name="stack_size">栈大小</param>
/// <param name="priority">优先级(0~15,值越小优先级越高)</param>
/// <param name="time_us">定时时间(us)</param>
/// <param name="exitcmd">定时器关闭命令 1=</param>
/// <returns></returns>
NO_API NOS_CreateAlarm(ThreadCallBack handle, void* para, UINT32 stack_size, INT32 priority, UINT32 time_us, NOS_BOOL* exitcmd);
#pragma endregion

#pragma region 互斥量
/// <summary>
/// 创建互斥量
/// </summary>
/// <param name="name">名称</param>
/// <param name="bInitialState">FALSE:创建时不获取权限 TRUE:创建时获取权限</param>
/// <param name="handle">返回句柄</param>
/// <returns></returns>
NO_API NOS_CreateMutex(char* name, NOS_BOOL bInitialState, UINT64* handle);

/// <summary>
/// 打开互斥量
/// </summary>
/// <param name="name">互斥量名称</param>
/// <param name="handle">返回句柄</param>
/// <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
/// <returns></returns>
NO_API NOS_OpenMutex(char* name, UINT64* handle, NOS_BOOL rtos);

/// <summary>
/// 获取互斥量
/// </summary>
/// <param name="handle">互斥量句柄</param>
/// <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
/// <param name="timeout">超时时间 小于0代表一直等待</param>
/// <returns></returns>
NO_API NOS_WaitMutex(UINT64 handle, NOS_BOOL rtos, double timeout);

/// <summary>
/// 释放互斥量
/// </summary>
/// <param name="handle">互斥量句柄</param>
/// <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
/// <returns></returns>
NO_API NOS_ReleaseMutex(UINT64 handle, NOS_BOOL rtos);

/// <summary>
/// 关闭互斥量句柄
/// </summary>
/// <param name="handle">互斥量句柄</param>
/// <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
/// <returns></returns>
NO_API NOS_CloseMutex(UINT64 handle, NOS_BOOL rtos);
#pragma endregion

#pragma region 日志
/// <summary>
/// 创建日志服务
/// runtime端创建
/// </summary>
/// <param name="channel">通道序号[0,32)</param>
/// <param name="size">缓冲区尺寸,最大1Mbyte</param>
/// <returns></returns>
NO_API NOS_CreateLogger(UINT32 channel, UINT32 size);

/// <summary>
/// 打开日志服务
/// </summary>
/// <param name="nodeIndex">创建共享内存进程所在的节点</param>
/// <param name="rta_name">进程名称</param>
/// <param name="channel">通道序号[0,32)</param>
/// <param name="rtos">FALSE:windows创建的日志 TRUE:rtos创建的日志</param>
/// <returns></returns>
NO_API NOS_OpenLogger(NOS_NODE nodeIndex, char* rta_name, UINT32 channel, NOS_BOOL rtos);

/// <summary>
/// 写日志,无多线程锁
/// runtime端写入
/// </summary>
/// <param name="channel">通道序号[0,32)</param>
/// <param name="msg">消息</param>
/// <returns></returns>
NO_API NOS_WriteLogger(UINT32 channel, char* msg);

/// <summary>
/// 读日志,有多线程锁
/// windows端读取
/// </summary>
/// <param name="channel">通道序号[0,32)</param>
/// <param name="msg">消息缓冲区</param>
/// <param name="buff_size">缓冲区大小,字节单位</param>
/// <param name="revd_size">实际接收到的数据数量,字节单位</param>
/// <returns></returns>
NO_API NOS_ReadLogger(UINT32 channel, char* msg, UINT32 buff_size, UINT32* revd_size);
#pragma endregion

#pragma region TCP/UDP
/// <summary>
/// 创建UDP句柄
/// </summary>
/// <param name="handle">返回句柄</param>
/// <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
/// <returns></returns>
NO_API NOS_UdpCreate(UINT64 *handle, UINT32 flags);

/// <summary>
/// UDP绑定端口
/// </summary>
/// <param name="handle">句柄</param>
/// <param name="port">端口</param>
/// <returns></returns>
NO_API NOS_UdpBind(UINT64 handle, UINT32 port);

/// <summary>
/// UDP发送数据
/// </summary>
/// <param name="handle">socket句柄</param>
/// <param name="ipaddr">目标ip地址</param>
/// <param name="ipport">目标端口</param>
/// <param name="buffer">数据缓冲区</param>
/// <param name="size">发送数据大小，字节单位</param>
/// <param name="sendNum">实际发送数据大小，字节单位</param>
/// <returns></returns>
NO_API NOS_UdpSend(UINT64 handle, char* ipaddr, UINT32 ipport, char* buffer, UINT32 size, INT32* sendNum);

/// <summary>
/// UDP接收数据
/// </summary>
/// <param name="handle">socket句柄</param>
/// <param name="buffer">数据缓冲区</param>
/// <param name="size">数据缓冲区大小，字节单位</param>
/// <param name="ipaddr">目标ip地址</param>
/// <param name="ipport">目标端口</param>
/// <param name="revNum">实际接收数据大小，字节单位</param>
/// <returns></returns>
NO_API NOS_UdpRecv(UINT64 handle, char* buffer, UINT32 size, char* ipaddr, UINT32 *ipport, INT32* revNum);

/// <summary>
/// 连接TCP服务器
/// </summary>
/// <param name="ipaddr">IP地址</param>
/// <param name="ipport">IP端口</param>
/// <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
/// <param name="handle">返回句柄</param>
/// <returns></returns>
NO_API NOS_TcpClientConnect(char* ipaddr, UINT32 ipport, UINT32 flags, UINT64* handle);

/// <summary>
/// TCP服务器初始化
/// </summary>
/// <param name="port">端口</param>
/// <param name="nBackLog">socket</param>
/// <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
/// <param name="handle">socket句柄</param>
/// <returns></returns>
NO_API NOS_TcpServerInit(UINT32 port, UINT32 nBackLog, UINT32 flags, UINT64 *handle);

/// <summary>
/// 接收连接
/// </summary>
/// <param name="handle">socket句柄</param>
/// <param name="newHandle">新的句柄</param>
/// <param name="clientIpaddr">客户端IP</param>
/// <param name="clientPort">客户端端口</param>
/// <returns></returns>
NO_API NOS_TcpServerAccept(UINT64 handle, UINT64* newHandle, char* clientIpaddr, UINT32* clientPort);

/// <summary>
/// 设置socket
/// </summary>
/// <param name="handle">socket句柄</param>
/// <param name="optionName"></param>
/// <param name="value"></param>
/// <param name="valueLen"></param>
/// <returns></returns>
NO_API NOS_SetSocketOption(UINT64 handle, NOS_OptionType optionName, INT32* value, INT32 valueLen);

/// <summary>
/// 发送
/// </summary>
/// <param name="handle">socket句柄</param>
/// <param name="buffer">发送buffer</param>
/// <param name="bufferLen">待发送长度，字节单位</param>
/// <param name="sendNum">实际发送长度，字节单位</param>
/// <returns></returns>
NO_API NOS_TcpSend(UINT64 handle, char* buffer, UINT32 bufferLen, INT32* sendNum);

/// <summary>
/// 接收
/// </summary>
/// <param name="handle">socket句柄</param>
/// <param name="buffer">接收buffer</param>
/// <param name="bufferLen">待接收长度，字节单位</param>
/// <param name="revdNum">实际接收的数据长度，字节单位</param>
/// <returns></returns>
NO_API NOS_TcpRecv(UINT64 handle, char* buffer, UINT32 bufferLen, INT32 *revdNum);

/// <summary>
/// 关闭socket
/// </summary>
/// <param name="handle">socket句柄</param>
/// <param name="flag"></param>
/// <returns></returns>
NO_API NOS_CloseSocket(UINT64 handle, NOS_ShutDownFlag flag);
#pragma endregion

#pragma region Modbus
/// <summary>
/// Modbus服务器初始化
/// </summary>
/// <param name="port">端口</param>
/// <returns></returns>
NO_API NOS_MBusServerInit(UINT32 port);

/// <summary>
/// 传入Modbus客户端读写字寄存器操作函数
/// </summary>
/// <param name="ReadFun">读函数(MBusReadWord)</param>
/// <param name="WriteFun">写函数(MbusWriteWord)</param>
/// <returns></returns>
NO_API NOS_MBusServerSetWordOp(UINT64 ReadFun, UINT64 WriteFun);

/// <summary>
/// 传入Modbus客户端读写位寄存器操作函数
/// </summary>
/// <param name="ReadFun">读函数(MBusReadBit)</param>
/// <param name="WriteFun">写函数(MBusWriteBit)</param>
/// <returns></returns>
NO_API NOS_MBusServerSetBitOp(UINT64 ReadFun, UINT64 WriteFun);

/// <summary>
/// Modbus客户端初始化
/// </summary>
/// <param name="ipaddr">服务端ip地址</param>
/// <param name="ipport">务端端口</param>
/// <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
/// <param name="timeout">接收超时时间(ms)</param>
/// <param name="handle">返回句柄</param>
/// <returns></returns>
NO_API NOS_MbusClientConnect(char* ipaddr, UINT32 ipport, UINT32 flags, UINT32 timeout, UINT64* handle);

/// <summary>
/// Modbus客户端关闭
/// </summary>
/// <param name="handle">句柄</param>
/// <returns></returns>
NO_API NOS_MbusClientClose(UINT64 handle);

/// <summary>
/// 读字寄存器
/// </summary>
/// <param name="handle">句柄</param>
/// <param name="slave">站号</param>
/// <param name="index">寄存器索引</param>
/// <param name="data">读取数据</param>
/// <param name="num">寄存器数量</param>
/// <returns></returns>
NO_API NOS_MbusClientReadWord(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);

/// <summary>
/// 写字寄存器
/// </summary>
/// <param name="handle">句柄</param>
/// <param name="slave">站号</param>
/// <param name="index">寄存器索引</param>
/// <param name="data">写入数据</param>
/// <param name="num">寄存器数量</param>
/// <returns></returns>
NO_API NOS_MbusClientWriteWord(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);

/// <summary>
/// 读位寄存器
/// </summary>
/// <param name="handle">句柄</param>
/// <param name="slave">站号</param>
/// <param name="index">寄存器索引</param>
/// <param name="data">读取数据</param>
/// <param name="num">寄存器数量</param>
/// <returns></returns>
NO_API NOS_MbusClientReadBit(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);

/// <summary>
/// 写位寄存器
/// </summary>
/// <param name="handle">句柄</param>
/// <param name="slave">站号</param>
/// <param name="index">寄存器索引</param>
/// <param name="data">写入数据</param>
/// <param name="num">寄存器数量</param>
/// <returns></returns>
NO_API NOS_MbusClientWriteBit(UINT64 handle, UINT32 slave, UINT32 index, UINT16* data, UINT32 num);
#pragma endregion

#pragma region 串口
/// <summary>
/// 打开串口 未实现
/// </summary>
/// <param name="com_name">串口名称</param>
/// <param name="handle">返回句柄</param>
/// <returns></returns>
NO_API NOS_OpenComm(char *com_name, INT32* handle);

/// <summary>
/// 关闭串口
/// </summary>
/// <param name="handle">串口句柄</param>
/// <returns></returns>
NO_API NOS_CloseComm(INT32 handle);

/// <summary>
/// 串口设置
/// </summary>
/// <param name="handle">串口句柄</param>
/// <param name="baud"></param>
/// <param name="parity"></param>
/// <param name="dataBit"></param>
/// <param name="stopBit"></param>
/// <returns></returns>
NO_API NOS_SetCommConfig(INT32 handle, UINT32 baud, UINT32 parity, UINT32 dataBit, UINT32 stopBit);

/// <summary>
/// 从串口读数据
/// </summary>
/// <param name="handle">串口句柄</param>
/// <param name="buffer">缓冲区</param>
/// <param name="size">缓冲区大小</param>
/// <param name="reved">实际接收的数量</param>
/// <returns></returns>
NO_API NOS_ReadComm(INT32 handle, UINT8 *buffer, UINT32 size, UINT32 *reved);

/// <summary>
/// 数据发送
/// </summary>
/// <param name="handle">串口句柄</param>
/// <param name="buffer">缓冲区</param>
/// <param name="size">缓冲区大小</param>
/// <param name="reved">实际接收的数量</param>
/// <returns></returns>
NO_API NOS_WriteComm(INT32 handle, UINT8* buffer, UINT32 size, UINT32* reved);

/// <summary>
/// 串口缓冲区设置
/// </summary>
/// <param name="handle">串口句柄</param>
/// <param name="inQueue">输入缓冲区大小</param>
/// <param name="outQueue">输出缓冲区大小</param>
/// <returns></returns>
NO_API NOS_SetupComm(INT32 handle, UINT32 inQueue, UINT32 outQueue);

/// <summary>
/// 发送缓存数据
/// </summary>
/// <param name="handle">串口句柄</param>
/// <returns></returns>
NO_API NOS_FlushCommBuffers(INT32 handle);

/// <summary>
/// 清除缓冲区
/// </summary>
/// <param name="handle">串口句柄</param>
/// <param name="flags">标记</param>
/// <returns></returns>
NO_API NOS_PurgeComm(INT32 handle, UINT32 flags);
#pragma endregion


#endif
