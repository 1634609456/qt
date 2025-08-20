from enum import Enum
from ctypes import *
# <summary>
# 函数返回值定义
# </summary>
class NOS_RESULT_CODE (Enum):
	#/ </summary>
	NOS_RET_OK = 0x00

	#/ </summary>
	NOS_RET_FUN = 0x01

	#/ </summary>
	NOS_RET_FAIL = 0x02

	#/ </summary>
	NOS_RET_NULL = 0x04

	#/ </summary>
	NOS_RET_PARA = 0x05

	#/ </summary>
	NOS_RET_SMEM = 0x06

	#/ </summary>
	NOS_RET_ADMIN = 0x07

	#/ </summary>
	NOS_RET_TIMEOUT = 0x10

	#/ </summary>
	NOS_RET_CMD = 0x11

	#/ </summary>
	NOS_RET_WAIT = 0x12

	#/ </summary>
	NOS_RET_CONNECT = 0x13

	#/ </summary>
	NOS_RET_INIT = 0x14

	#/ </summary>
	NOS_RET_BIND = 0x15

	#/ </summary>
	NOS_RET_LISTEN = 0x16

# <summary>
# BOOL类型
# </summary>
class NOS_BOOL (Enum):
	#/ </summary>
	NOS_FALSE = 0

	#/ </summary>
	NOS_TRUE = 1

# <summary>
# 节点选择
# </summary>
class NOS_NODE (Enum):
	#/ </summary>
	NOS_ECAT_A = 0

	#/ </summary>
	NOS_ECAT_B = 1

	#/ </summary>
	NOS_ECAT_C = 2

	#/ </summary>
	NOS_ECAT_D = 3

	#/ </summary>
	NOS_NODE_E = 4

	#/ </summary>
	NOS_NODE_F = 5

	#/ </summary>
	NOS_NODE_G = 6

	#/ </summary>
	NOS_NODE_H = 7

# <summary>
# 事件类型
# </summary>
class NOS_EVENT_CODE (Enum):
	#/ </summary>
	NOS_WAIT_TIMEOUT = 258

	#/ </summary>
	NOS_WAIT_FOREVER = -1

	#/ </summary>
	NOS_WAIT_FAILED = NOS_WAIT_FOREVER

	#/ </summary>
	NOS_STATUS_ABANDONED_WAIT_0 = 0x00000080

	#/ </summary>
	NOS_WAIT_ABANDONED_0 = NOS_STATUS_ABANDONED_WAIT_0+0

	#/ </summary>
	NOS_STATUS_WAIT_0 = 0x00000000

	#/ </summary>
	NOS_WAIT_OBJECT_0 = NOS_STATUS_WAIT_0+0

# <summary>
# socket选项
# </summary>
class NOS_OptionType (Enum):
	#/ </summary>
	NOS_SO_DEBUG = 0x0001

	#/ </summary>
	NOS_SO_ACCEPTCONN = 0x0002

	#/ </summary>
	NOS_SO_REUSEADDR = 0x0004

	#/ </summary>
	NOS_SO_KEEPALIVE = 0x0008

	#/ </summary>
	NOS_SO_DONTROUTE = 0x0010

	#/ </summary>
	NOS_SO_BROADCAST = 0x0020

	#/ </summary>
	NOS_SO_USELOOPBACK = 0x0040

	#/ </summary>
	NOS_SO_LINGER = 0x0080

	#/ </summary>
	NOS_SO_OOBINLINE = 0x0100

	#/ </summary>
	NOS_SO_REUSEPORT = 0x0200

	#/ </summary>
	NOS_SO_TIMESTAMP = 0x0400

	#/ </summary>
	NOS_SO_SNDBUF = 0x1001

	#/ </summary>
	NOS_SO_RCVBUF = 0x1002

	#/ </summary>
	NOS_SO_SNDLOWAT = 0x1003

	#/ </summary>
	NOS_SO_RCVLOWAT = 0x1004

	#/ </summary>
	NOS_SO_SNDTIMEO = 0x1005

	#/ </summary>
	NOS_SO_RCVTIMEO = 0x1006

# <summary>
# socket关闭策略
# </summary>
class NOS_ShutDownFlag (Enum):
	#/ </summary>
	NOS_SHUT_RD = 0

	#/ </summary>
	NOS_SHUT_WR = 1

	#/ </summary>
	NOS_SHUT_RDWR = 2

# <summary>
# 消息控制策略
# </summary>
class NOS_MsgFlag (Enum):
	#/ </summary>
	NOS_MSG_DONTWAIT = 0x000000080

# <summary>
# 获取内部版本号
# </summary>
# <param name="ver"></param>
# <returns></returns>
def NOS_GetVersion(dllPtr, ver):

	return dllPtr.NOS_GetVersion(byref(ver));

# <summary>
# 获取系统时钟(微秒单位)
# </summary>
# <param name="tick"></param>
# <returns></returns>
def NOS_GetUsTick(dllPtr, tick):

	return dllPtr.NOS_GetUsTick(byref(tick));

# <summary>
# 微秒延时，分辨率为实时系统的最小调度周期
# </summary>
# <param name="us">微秒单位</param>
# <returns></returns>
def NOS_SleepUs(dllPtr, us):

	return dllPtr.NOS_SleepUs(us);

# <summary>
# 选中节点
# </summary>
# <param name="node">节点</param>
# <returns></returns>
def NOS_SetNode(dllPtr, node):

	return dllPtr.NOS_SetNode(node);

# <summary>
# 设置进程名称
# </summary>
# <param name="name">名称,最多12个英文字符</param>
# <returns></returns>
def NOS_SetRtaName(dllPtr, name):

	return dllPtr.NOS_SetRtaName(name);

# <summary>
# 共享内存初始化
# </summary>
# <param name="rta_name">进程名称，12个英文字符以内</param>
# <param name="handle">保留，固定填0</param>
# <returns></returns>
def NOS_InitShareMemory(dllPtr, rta_name, handle):

	return dllPtr.NOS_InitShareMemory(rta_name, handle);

# <summary>
# 创建共享内存
# </summary>
# <param name="name">共享内存名称，8个英文字符以内</param>
# <param name="size">内存大小，字节单位</param>
# <param name="addr">返回内存地址</param>
# <returns></returns>
def NOS_CreateShareMemory(dllPtr, name, size, addr):

	return dllPtr.NOS_CreateShareMemory(name, size, byref(addr));

# <summary>
# 打开共享内存
# </summary>
# <param name="nodeIndex">创建共享内存进程所在的节点</param>
# <param name="rta_name">进程名称</param>
# <param name="mem_name">共享内存名称</param>
# <param name="addr">首地址</param>
# <param name="rtos">FALSE:windows创建的内存 TRUE:rtos创建的内存</param>
# <returns></returns>
def NOS_OpenShareMemory(dllPtr, nodeIndex, rta_name, mem_name, addr, rtos):

	return dllPtr.NOS_OpenShareMemory(nodeIndex, rta_name, mem_name, byref(addr), rtos);

# <summary>
# 读共享内存
# </summary>
# <param name="addr">共享内存首地址</param>
# <param name="offset">偏移量，字节单位</param>
# <param name="data">缓冲区，存放读入数据</param>
# <param name="num">读取数量，字节单位</param>
# <returns></returns>
def NOS_ReadShareMemory(dllPtr, addr, offset, data, num):

	return dllPtr.NOS_ReadShareMemory(addr, offset, byref(data), num);

# <summary>
# 写共享内存
# </summary>
# <param name="addr">共享内存首地址</param>
# <param name="offset">偏移量，字节单位</param>
# <param name="data">缓冲区，存放写入数据</param>
# <param name="num">写入数量，字节单位</param>
# <returns></returns>
def NOS_WriteShareMemory(dllPtr, addr, offset, data, num):

	return dllPtr.NOS_WriteShareMemory(addr, offset, data, num);

# <summary>
# 创建事件
# </summary>
# <param name="ManualReset">0:当一个等待线程被释放后，系统自动重置事件 1:使用ResetEvent手动将事件重置为无信号状态。</param>
# <param name="bInitialState">指定初始状态 0:无信号 1:有信号</param>
# <param name="name">事件名称，仅限于英文字符</param>
# <param name="handle">返回的事件句柄</param>
# <returns></returns>
def NOS_CreateEvent(dllPtr, ManualReset, bInitialState, name, handle):

	return dllPtr.NOS_CreateEvent(ManualReset, bInitialState, name, byref(handle));

# <summary>
# 打开由NOS_CreateEvent创建的事件
# </summary>
# <param name="name">事件名称</param>
# <param name="handle">返回的事件句柄</param>
# <param name="rtos">0:windows创建的事件 1:rtos创建的事件</param>
# <returns></returns>
def NOS_OpenEvent(dllPtr, name, handle, rtos):

	return dllPtr.NOS_OpenEvent(name, byref(handle), rtos);

# <summary>
# 关闭事件句柄
# </summary>
# <param name="handle">事件句柄</param>
# <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
# <returns></returns>
def NOS_CloseEvent(dllPtr, handle, rtos):

	return dllPtr.NOS_CloseEvent(handle, rtos);

# <summary>
# 将指定的事件对象设置为有信号，然后在释放适当数量的等待线程后将其重置为无信号。
# </summary>
# <param name="handle">事件句柄</param>
# <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
# <returns>0:失败 非0:成功</returns>
def NOS_PulseEvent(dllPtr, handle, rtos):

	return dllPtr.NOS_PulseEvent(handle, rtos);

# <summary>
# 将事件置为无信号状态
# </summary>
# <param name="handle">事件句柄</param>
# <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
# <returns>0:失败 非0:成功</returns>
def NOS_ResetEvent(dllPtr, handle, rtos):

	return dllPtr.NOS_ResetEvent(handle, rtos);

# <summary>
# 将事件置为有信号状态
# </summary>
# <param name="handle">事件句柄</param>
# <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
# <returns>0:失败 非0:成功</returns>
def NOS_SetEvent(dllPtr, handle, rtos):

	return dllPtr.NOS_SetEvent(handle, rtos);

# <summary>
# 等待单个事件
# </summary>
# <param name="hHandle">事件句柄</param>
# <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
# <param name="dwMilliseconds">超时时间(毫秒单位), INFINITE(0xFFFFFFFF)为永不超时</param>
# <param name="result">返回代码</param>
# <returns></returns>
def NOS_WaitForSingleObject(dllPtr, hHandle, rtos, dwMilliseconds, result):

	return dllPtr.NOS_WaitForSingleObject(hHandle, rtos, dwMilliseconds, byref(result));

# <summary>
# 等待多个事件
# </summary>
# <param name="nCount">事件数量</param>
# <param name="lpHandles">事件句柄</param>
# <param name="rtos">FALSE:windows创建的事件 TRUE:rtos创建的事件</param>
# <param name="dwMillisecond">超时时间(毫秒单位), INFINITE(0xFFFFFFFF)为永不超时</param>
# <param name="result">返回代码</param>
# <returns></returns>
def NOS_WaitForMultipleObjects(dllPtr, lpHandles, rtos, nCount, dwMillisecond, result):

	return dllPtr.NOS_WaitForMultipleObjects(lpHandles, rtos, nCount, dwMillisecond, byref(result));


# <summary>
# 创建互斥量
# </summary>
# <param name="name">名称</param>
# <param name="bInitialState">FALSE:创建时不获取权限 TRUE:创建时获取权限</param>
# <param name="handle">返回句柄</param>
# <returns></returns>
def NOS_CreateMutex(dllPtr, name, bInitialState, handle):

	return dllPtr.NOS_CreateMutex(name, bInitialState, byref(handle));

# <summary>
# 打开互斥量
# </summary>
# <param name="name">互斥量名称</param>
# <param name="handle">返回句柄</param>
# <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
# <returns></returns>
def NOS_OpenMutex(dllPtr, name, handle, rtos):

	return dllPtr.NOS_OpenMutex(name, byref(handle), rtos);

# <summary>
# 获取互斥量
# </summary>
# <param name="handle">互斥量句柄</param>
# <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
# <param name="timeout">超时时间 小于0代表一直等待</param>
# <returns></returns>
def NOS_WaitMutex(dllPtr, handle, rtos, timeout):

	return dllPtr.NOS_WaitMutex(handle, rtos, timeout);

# <summary>
# 释放互斥量
# </summary>
# <param name="handle">互斥量句柄</param>
# <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
# <returns></returns>
def NOS_ReleaseMutex(dllPtr, handle, rtos):

	return dllPtr.NOS_ReleaseMutex(handle, rtos);

# <summary>
# 关闭互斥量句柄
# </summary>
# <param name="handle">互斥量句柄</param>
# <param name="rtos">FALSE:windows创建的互斥量 TRUE:rtos创建的互斥量</param>
# <returns></returns>
def NOS_CloseMutex(dllPtr, handle, rtos):

	return dllPtr.NOS_CloseMutex(handle, rtos);

# <summary>
# 创建日志服务
# runtime端创建
# </summary>
# <param name="channel">通道序号[0,32)</param>
# <param name="size">缓冲区尺寸,最大1Mbyte</param>
# <returns></returns>
def NOS_CreateLogger(dllPtr, channel, size):

	return dllPtr.NOS_CreateLogger(channel, size);

# <summary>
# 打开日志服务
# </summary>
# <param name="nodeIndex">创建共享内存进程所在的节点</param>
# <param name="rta_name">进程名称</param>
# <param name="channel">通道序号[0,32)</param>
# <param name="rtos">FALSE:windows创建的日志 TRUE:rtos创建的日志</param>
# <returns></returns>
def NOS_OpenLogger(dllPtr, nodeIndex, rta_name, channel, rtos):

	return dllPtr.NOS_OpenLogger(nodeIndex, rta_name, channel, rtos);

# <summary>
# 写日志,无多线程锁
# runtime端写入
# </summary>
# <param name="channel">通道序号[0,32)</param>
# <param name="msg">消息</param>
# <returns></returns>
def NOS_WriteLogger(dllPtr, channel, msg):

	return dllPtr.NOS_WriteLogger(channel, msg);

# <summary>
# 读日志,有多线程锁
# windows端读取
# </summary>
# <param name="channel">通道序号[0,32)</param>
# <param name="msg">消息缓冲区</param>
# <param name="buff_size">缓冲区大小,字节单位</param>
# <param name="revd_size">实际接收到的数据数量,字节单位</param>
# <returns></returns>
def NOS_ReadLogger(dllPtr, channel, msg, buff_size, revd_size):

	return dllPtr.NOS_ReadLogger(channel, msg, buff_size, byref(revd_size));

# <summary>
# 创建UDP句柄
# </summary>
# <param name="handle">返回句柄</param>
# <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
# <returns></returns>
def NOS_UdpCreate(dllPtr, handle, flags):

	return dllPtr.NOS_UdpCreate(byref(handle), flags);

# <summary>
# UDP绑定端口
# </summary>
# <param name="handle">句柄</param>
# <param name="port">端口</param>
# <returns></returns>
def NOS_UdpBind(dllPtr, handle, port):

	return dllPtr.NOS_UdpBind(handle, port);

# <summary>
# UDP发送数据
# </summary>
# <param name="handle">socket句柄</param>
# <param name="ipaddr">目标ip地址</param>
# <param name="ipport">目标端口</param>
# <param name="buffer">数据缓冲区</param>
# <param name="size">发送数据大小，字节单位</param>
# <param name="sendNum">实际发送数据大小，字节单位</param>
# <returns></returns>
def NOS_UdpSend(dllPtr, handle, ipaddr, ipport, buffer, size, sendNum):

	return dllPtr.NOS_UdpSend(handle, ipaddr, ipport, buffer, size, byref(sendNum));

# <summary>
# UDP接收数据
# </summary>
# <param name="handle">socket句柄</param>
# <param name="buffer">数据缓冲区</param>
# <param name="size">数据缓冲区大小，字节单位</param>
# <param name="ipaddr">目标ip地址</param>
# <param name="ipport">目标端口</param>
# <param name="revNum">实际接收数据大小，字节单位</param>
# <returns></returns>
def NOS_UdpRecv(dllPtr, handle, buffer, size, ipaddr, ipport, revNum):

	return dllPtr.NOS_UdpRecv(handle, buffer, size, byref(ipaddr), byref(ipport), byref(revNum));

# <summary>
# 连接TCP服务器
# </summary>
# <param name="ipaddr">IP地址</param>
# <param name="ipport">IP端口</param>
# <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
# <param name="handle">返回句柄</param>
# <returns></returns>
def NOS_TcpClientConnect(dllPtr, ipaddr, ipport, flags, handle):

	return dllPtr.NOS_TcpClientConnect(ipaddr, ipport, flags, byref(handle));

# <summary>
# TCP服务器初始化
# </summary>
# <param name="port">端口</param>
# <param name="nBackLog">socket</param>
# <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
# <param name="handle">socket句柄</param>
# <returns></returns>
def NOS_TcpServerInit(dllPtr, port, nBackLog, flags, handle):

	return dllPtr.NOS_TcpServerInit(port, nBackLog, flags, byref(handle));

# <summary>
# 接收连接
# </summary>
# <param name="handle">socket句柄</param>
# <param name="newHandle">新的句柄</param>
# <param name="clientIpaddr">客户端IP</param>
# <param name="clientPort">客户端端口</param>
# <returns></returns>
def NOS_TcpServerAccept(dllPtr, handle, newHandle, clientIpaddr, clientPort):

	return dllPtr.NOS_TcpServerAccept(handle, byref(newHandle), byref(clientIpaddr), byref(clientPort));

# <summary>
# 设置socket
# </summary>
# <param name="handle">socket句柄</param>
# <param name="optionName"></param>
# <param name="value"></param>
# <param name="valueLen"></param>
# <returns></returns>
def NOS_SetSocketOption(dllPtr, handle, optionName, value, valueLen):

	return dllPtr.NOS_SetSocketOption(handle, optionName, value, valueLen);

# <summary>
# 发送
# </summary>
# <param name="handle">socket句柄</param>
# <param name="buffer">发送buffer</param>
# <param name="bufferLen">待发送长度，字节单位</param>
# <param name="sendNum">实际发送长度，字节单位</param>
# <returns></returns>
def NOS_TcpSend(dllPtr, handle, buffer, bufferLen, sendNum):

	return dllPtr.NOS_TcpSend(handle, buffer, bufferLen, byref(sendNum));

# <summary>
# 接收
# </summary>
# <param name="handle">socket句柄</param>
# <param name="buffer">接收buffer</param>
# <param name="bufferLen">待接收长度，字节单位</param>
# <param name="revdNum">实际接收的数据长度，字节单位</param>
# <returns></returns>
def NOS_TcpRecv(dllPtr, handle, buffer, bufferLen, revdNum):

	return dllPtr.NOS_TcpRecv(handle, buffer, bufferLen, byref(revdNum));

# <summary>
# 关闭socket
# </summary>
# <param name="handle">socket句柄</param>
# <param name="flag"></param>
# <returns></returns>
def NOS_CloseSocket(dllPtr, handle, flag):

	return dllPtr.NOS_CloseSocket(handle, flag);

# <summary>
# Modbus服务器初始化
# </summary>
# <param name="port">端口</param>
# <returns></returns>
def NOS_MBusServerInit(dllPtr, port):

	return dllPtr.NOS_MBusServerInit(port);

# <summary>
# 传入Modbus客户端读写字寄存器操作函数
# </summary>
# <param name="ReadFun">读函数(MBusReadWord)</param>
# <param name="WriteFun">写函数(MbusWriteWord)</param>
# <returns></returns>
def NOS_MBusServerSetWordOp(dllPtr, ReadFun, WriteFun):

	return dllPtr.NOS_MBusServerSetWordOp(ReadFun, WriteFun);

# <summary>
# 传入Modbus客户端读写位寄存器操作函数
# </summary>
# <param name="ReadFun">读函数(MBusReadBit)</param>
# <param name="WriteFun">写函数(MBusWriteBit)</param>
# <returns></returns>
def NOS_MBusServerSetBitOp(dllPtr, ReadFun, WriteFun):

	return dllPtr.NOS_MBusServerSetBitOp(ReadFun, WriteFun);

# <summary>
# Modbus客户端初始化
# </summary>
# <param name="ipaddr">服务端ip地址</param>
# <param name="ipport">务端端口</param>
# <param name="flags">控制标记(NOS_MsgFlag)，按位定义</param>
# <param name="timeout">接收超时时间(ms)</param>
# <param name="handle">返回句柄</param>
# <returns></returns>
def NOS_MbusClientConnect(dllPtr, ipaddr, ipport, flags, timeout, handle):

	return dllPtr.NOS_MbusClientConnect(ipaddr, ipport, flags, timeout, byref(handle));

# <summary>
# Modbus客户端关闭
# </summary>
# <param name="handle">句柄</param>
# <returns></returns>
def NOS_MbusClientClose(dllPtr, handle):

	return dllPtr.NOS_MbusClientClose(handle);

# <summary>
# 读字寄存器
# </summary>
# <param name="handle">句柄</param>
# <param name="slave">站号</param>
# <param name="index">寄存器索引</param>
# <param name="data">读取数据</param>
# <param name="num">寄存器数量</param>
# <returns></returns>
def NOS_MbusClientReadWord(dllPtr, handle, slave, index, data, num):

	return dllPtr.NOS_MbusClientReadWord(handle, slave, index, byref(data), num);

# <summary>
# 写字寄存器
# </summary>
# <param name="handle">句柄</param>
# <param name="slave">站号</param>
# <param name="index">寄存器索引</param>
# <param name="data">写入数据</param>
# <param name="num">寄存器数量</param>
# <returns></returns>
def NOS_MbusClientWriteWord(dllPtr, handle, slave, index, data, num):

	return dllPtr.NOS_MbusClientWriteWord(handle, slave, index, data, num);

# <summary>
# 读位寄存器
# </summary>
# <param name="handle">句柄</param>
# <param name="slave">站号</param>
# <param name="index">寄存器索引</param>
# <param name="data">读取数据</param>
# <param name="num">寄存器数量</param>
# <returns></returns>
def NOS_MbusClientReadBit(dllPtr, handle, slave, index, data, num):

	return dllPtr.NOS_MbusClientReadBit(handle, slave, index, byref(data), num);

# <summary>
# 写位寄存器
# </summary>
# <param name="handle">句柄</param>
# <param name="slave">站号</param>
# <param name="index">寄存器索引</param>
# <param name="data">写入数据</param>
# <param name="num">寄存器数量</param>
# <returns></returns>
def NOS_MbusClientWriteBit(dllPtr, handle, slave, index, data, num):

	return dllPtr.NOS_MbusClientWriteBit(handle, slave, index, data, num);

# <summary>
# 打开串口 未实现
# </summary>
# <param name="com_name">串口名称</param>
# <param name="handle">返回句柄</param>
# <returns></returns>
def NOS_OpenComm(dllPtr, com_name, handle):

	return dllPtr.NOS_OpenComm(com_name, byref(handle));

# <summary>
# 关闭串口
# </summary>
# <param name="handle">串口句柄</param>
# <returns></returns>
def NOS_CloseComm(dllPtr, handle):

	return dllPtr.NOS_CloseComm(handle);

# <summary>
# 串口设置
# </summary>
# <param name="handle">串口句柄</param>
# <param name="baud"></param>
# <param name="parity"></param>
# <param name="dataBit"></param>
# <param name="stopBit"></param>
# <returns></returns>
def NOS_SetCommConfig(dllPtr, handle, baud, parity, dataBit, stopBit):

	return dllPtr.NOS_SetCommConfig(handle, baud, parity, dataBit, stopBit);

# <summary>
# 从串口读数据
# </summary>
# <param name="handle">串口句柄</param>
# <param name="buffer">缓冲区</param>
# <param name="size">缓冲区大小</param>
# <param name="reved">实际接收的数量</param>
# <returns></returns>
def NOS_ReadComm(dllPtr, handle, buffer, size, reved):

	return dllPtr.NOS_ReadComm(handle, byref(buffer), size, byref(reved));

# <summary>
# 数据发送
# </summary>
# <param name="handle">串口句柄</param>
# <param name="buffer">缓冲区</param>
# <param name="size">缓冲区大小</param>
# <param name="reved">实际接收的数量</param>
# <returns></returns>
def NOS_WriteComm(dllPtr, handle, buffer, size, reved):

	return dllPtr.NOS_WriteComm(handle, buffer, size, byref(reved));

# <summary>
# 串口缓冲区设置
# </summary>
# <param name="handle">串口句柄</param>
# <param name="inQueue">输入缓冲区大小</param>
# <param name="outQueue">输出缓冲区大小</param>
# <returns></returns>
def NOS_SetupComm(dllPtr, handle, inQueue, outQueue):

	return dllPtr.NOS_SetupComm(handle, inQueue, outQueue);

# <summary>
# 发送缓存数据
# </summary>
# <param name="handle">串口句柄</param>
# <returns></returns>
def NOS_FlushCommBuffers(dllPtr, handle):

	return dllPtr.NOS_FlushCommBuffers(handle);

# <summary>
# 清除缓冲区
# </summary>
# <param name="handle">串口句柄</param>
# <param name="flags">标记</param>
# <returns></returns>
def NOS_PurgeComm(dllPtr, handle, flags):

	return dllPtr.NOS_PurgeComm(handle, flags);


