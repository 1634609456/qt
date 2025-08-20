using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;

namespace YKCat2
{
	#region 数据类型
	#endregion

	#region 枚举定义
	/// <summary>
	/// 系统定义
	/// </summary>
	public enum YKE_SYSTEM_DEFINE
	{
		/// <summary>
		/// 魔数
		/// </summary>
		[Description("魔数")]
		YKE_MAGIC_FLAG = 0x13575A5A,

		/// <summary>
		/// 对应ProCon版本
		/// </summary>
		[Description("对应ProCon版本")]
		YKE_PROCON_VER = 1531,

		/// <summary>
		/// 数字输入数量(bit)
		/// </summary>
		[Description("数字输入数量(bit)")]
		YKE_DIGITAL_INPUT_NUM = 4096,

		/// <summary>
		/// 数字输出数量(bit)
		/// </summary>
		[Description("数字输出数量(bit)")]
		YKE_DIGITAL_OUTPUT_NUM = 4096,

		/// <summary>
		/// 单次同步输出数量(bit)
		/// </summary>
		[Description("单次同步输出数量(bit)")]
		YKE_DIGITAL_OUTPUT_CYCLE_NUM = 1024,

		/// <summary>
		/// 最大的主站数量
		/// </summary>
		[Description("最大的主站数量")]
		YKE_MASTER_NUM = 4,

		/// <summary>
		/// 示波器数量
		/// </summary>
		[Description("示波器数量")]
		YKE_OSC_NUM = 8,

		/// <summary>
		/// 示波器通道数量
		/// </summary>
		[Description("示波器通道数量")]
		YKE_OSC_ITEM_NUM = 64,

		/// <summary>
		/// 插补最大轴数量
		/// </summary>
		[Description("插补最大轴数量")]
		YKE_INTER_AXIS_NUM = 32,

		/// <summary>
		/// 软件位置比较通道数量
		/// </summary>
		[Description("软件位置比较通道数量")]
		YKE_SOFT_COMPARE_NUM = 128,

		/// <summary>
		/// 软件位置比较队列深度
		/// </summary>
		[Description("软件位置比较队列深度")]
		YKE_SOFT_COMPARE_DEPTH = 512,

		/// <summary>
		/// 软探针通道数量
		/// </summary>
		[Description("软探针通道数量")]
		YKE_SOFT_PROBE_NUM = 128,

		/// <summary>
		/// 软探针数据缓存深度
		/// </summary>
		[Description("软探针数据缓存深度")]
		YKE_SOFT_PROBE_DEPTH = 512,

		/// <summary>
		/// 本地卡硬探针数据缓存深度
		/// </summary>
		[Description("本地卡硬探针数据缓存深度")]
		YKE_HARD_PROBE_DEPTH = 512,

		/// <summary>
		/// 轴关联的软探针通道数量
		/// </summary>
		[Description("轴关联的软探针通道数量")]
		YKE_AXIS_SOFT_PROBE_NUM = 4,

		/// <summary>
		/// 螺距补偿最大点数
		/// </summary>
		[Description("螺距补偿最大点数")]
		YKE_PITCH1D_NUM = 2048,

		/// <summary>
		/// 二维补偿最大点数
		/// </summary>
		[Description("二维补偿最大点数")]
		YKE_PITCH2D_NUM = 512,

		/// <summary>
		/// 控制事件通道数量
		/// </summary>
		[Description("控制事件通道数量")]
		YKE_EVENT_NUM = 1024,

		/// <summary>
		/// 等待事件通道数量
		/// </summary>
		[Description("等待事件通道数量")]
		YKE_WAIT_NUM = 1024,

		/// <summary>
		/// 坐标系数量
		/// </summary>
		[Description("坐标系数量")]
		YKE_GROUP_NUM = 32,

		/// <summary>
		/// 坐标系数据空间
		/// </summary>
		[Description("坐标系数据空间")]
		YKE_GROUP_DEPTH = 4096,

		/// <summary>
		/// 坐标系内并行输出数量
		/// </summary>
		[Description("坐标系内并行输出数量")]
		YKE_GROUP_OUTPUT_NUM = 32,

		/// <summary>
		/// 轴数量
		/// </summary>
		[Description("轴数量")]
		YKE_AXIS_NUM = 1024,

		/// <summary>
		/// 日志采集通道数量
		/// </summary>
		[Description("日志采集通道数量")]
		YKE_LOGGER_ITEM = 32,

		/// <summary>
		/// 流程跟踪通道数量
		/// </summary>
		[Description("流程跟踪通道数量")]
		YKE_EXC_CONDI = 16,

		/// <summary>
		/// 通用数据寄存器数量
		/// </summary>
		[Description("通用数据寄存器数量")]
		YKE_GENDATA_SIZE = 0x100000,

		/// <summary>
		/// 特殊数据寄存器数量
		/// </summary>
		[Description("特殊数据寄存器数量")]
		YKE_SPDATA_SIZE = 0x10000,

		/// <summary>
		/// 急停输入信号数量
		/// </summary>
		[Description("急停输入信号数量")]
		YKE_EMG_STOP_INPUT_NUM = 8,

		/// <summary>
		/// 急停输出信号数量
		/// </summary>
		[Description("急停输出信号数量")]
		YKE_EMG_STOP_OUTPUT_NUM = 4,

		/// <summary>
		/// 急停通道数量
		/// </summary>
		[Description("急停通道数量")]
		YKE_EMG_STOP_NUM = 32,

		/// <summary>
		/// PVT运动缓冲区深度
		/// </summary>
		[Description("PVT运动缓冲区深度")]
		YKE_PVT_DEPTH = 4096,

		/// <summary>
		/// 文件路径缓冲区长度
		/// </summary>
		[Description("文件路径缓冲区长度")]
		YKE_FILE_PATH_SIZE = 512,

		/// <summary>
		/// 文件名缓冲区长度
		/// </summary>
		[Description("文件名缓冲区长度")]
		YKE_FILE_NAME_SIZE = 64,

		/// <summary>
		/// 最大进程数量
		/// </summary>
		[Description("最大进程数量")]
		YKE_LOGGER_PROCCESS = 32,

		/// <summary>
		/// 多轴联动通道数量
		/// </summary>
		[Description("多轴联动通道数量")]
		YKE_MULTI_AXIS_NUM = 128,

		/// <summary>
		/// 圆形区域数量
		/// </summary>
		[Description("圆形区域数量")]
		YKE_CIRCLE_ZONE_NUM = 32,

		/// <summary>
		/// API缓冲区通道数量
		/// </summary>
		[Description("API缓冲区通道数量")]
		YKE_API_BUFFER_NUM = 512,
	};

	/// <summary>
	/// 函数返回值定义
	/// </summary>
	public enum YKE_RESULT_CODE
	{
		/// <summary>
		/// 正常
		/// </summary>
		[Description("正常")]
		YKE_RET_OK = 0,

		/// <summary>
		/// 实时进程加载失败
		/// </summary>
		[Description("实时进程加载失败")]
		YKE_RET_SYS_LOAD_RTA = 0x0100,

		/// <summary>
		/// 和runtime连接失败
		/// </summary>
		[Description("和runtime连接失败")]
		YKE_RET_SYS_OPEN_GW = 0x0101,

		/// <summary>
		/// 请使用SysLoadLib连接runtime
		/// </summary>
		[Description("请使用SysLoadLib连接runtime")]
		YKE_RET_SYS_CONNECT_GW = 0x0102,

		/// <summary>
		/// 打开runtime共享内存失败
		/// </summary>
		[Description("打开runtime共享内存失败")]
		YKE_RET_SYS_OPEN_MEM = 0x0103,

		/// <summary>
		/// 网关超时
		/// </summary>
		[Description("网关超时")]
		YKE_RET_SYS_GW_TIMOUT = 0x0104,

		/// <summary>
		/// 授权权限不够
		/// </summary>
		[Description("授权权限不够")]
		YKE_RET_SYS_LIC = 0x0105,

		/// <summary>
		/// 实时系统没有启动
		/// </summary>
		[Description("实时系统没有启动")]
		YKE_RET_SYS_RTOS = 0x0106,

		/// <summary>
		/// Runtime已经退出或者重启,请重新连接
		/// </summary>
		[Description("Runtime已经退出或者重启,请重新连接")]
		YKE_RET_SYS_EXIT = 0x0107,

		/// <summary>
		/// 冷复位失败
		/// </summary>
		[Description("冷复位失败")]
		YKE_RET_SYS_COLD = 0x0108,

		/// <summary>
		/// 服务操作没有访问权限,请检查进程是否具备管理员权限。
		/// </summary>
		[Description("服务操作没有访问权限,请检查进程是否具备管理员权限。")]
		YKE_RET_SYS_ACCESS = 0x0109,

		/// <summary>
		/// 库文件不匹配,从安装目录更新库文件(.h .dll)到应用程序
		/// </summary>
		[Description("库文件不匹配,从安装目录更新库文件(.h .dll)到应用程序")]
		YKE_RET_SYS_MISMATCH = 0x010a,

		/// <summary>
		/// 多语言文件加载错误
		/// </summary>
		[Description("多语言文件加载错误")]
		YKE_RET_SYS_LANG_TEXT = 0x010b,

		/// <summary>
		/// 字符串中存在中文字符。日志文件/实时程序文件中不能含有中文字符。
		/// </summary>
		[Description("字符串中存在中文字符。日志文件/实时程序文件中不能含有中文字符。")]
		YKE_RET_SYS_CHN = 0x010c,

		/// <summary>
		/// 不支持的功能
		/// </summary>
		[Description("不支持的功能")]
		YKE_RET_SYS_FUN = 0x010d,

		/// <summary>
		/// 内存分配失败
		/// </summary>
		[Description("内存分配失败")]
		YKE_RET_SYS_DYNC_MEM = 0x010e,

		/// <summary>
		/// 系统冷复位后需重启应用程序
		/// </summary>
		[Description("系统冷复位后需重启应用程序")]
		YKE_RET_SYS_COLD_ERR = 0x010f,

		/// <summary>
		/// 主站A未启用
		/// </summary>
		[Description("主站A未启用")]
		YKE_RET_SYS_NODEA_ENA = 0x0110,

		/// <summary>
		/// 指定主站未运行
		/// </summary>
		[Description("指定主站未运行")]
		YKE_RET_SYS_NODEO = 0x0111,

		/// <summary>
		/// 主站B未启用
		/// </summary>
		[Description("主站B未启用")]
		YKE_RET_SYS_NODEB_ENA = 0x0112,

		/// <summary>
		/// 主站B未运行
		/// </summary>
		[Description("主站B未运行")]
		YKE_RET_SYS_NODEB_RUN = 0x0113,

		/// <summary>
		/// 主站C未启用
		/// </summary>
		[Description("主站C未启用")]
		YKE_RET_SYS_NODEC_ENA = 0x0114,

		/// <summary>
		/// 主站C未运行
		/// </summary>
		[Description("主站C未运行")]
		YKE_RET_SYS_NODEC_RUN = 0x0115,

		/// <summary>
		/// 主站D未启用
		/// </summary>
		[Description("主站D未启用")]
		YKE_RET_SYS_NODED_ENA = 0x0116,

		/// <summary>
		/// 主站D未运行
		/// </summary>
		[Description("主站D未运行")]
		YKE_RET_SYS_NODED_RUN = 0x0117,

		/// <summary>
		/// Runtime未运行
		/// </summary>
		[Description("Runtime未运行")]
		YKE_RET_SYS_RUNTIME_STOP = 0x0118,

		/// <summary>
		/// 实时系统内存设置太小
		/// </summary>
		[Description("实时系统内存设置太小")]
		YKE_RET_SYS_INTIME_MEM = 0x0119,

		/// <summary>
		/// 指定主站未运行
		/// </summary>
		[Description("指定主站未运行")]
		YKE_RET_SYS_NODE_ENA = 0x011E,

		/// <summary>
		/// 非法的主站序号
		/// </summary>
		[Description("非法的主站序号")]
		YKE_RET_SYS_NODE_IDX = 0x011F,

		/// <summary>
		/// 文件夹创建失败
		/// </summary>
		[Description("文件夹创建失败")]
		YKE_RET_SYS_CREATE_DIR = 0x0120,

		/// <summary>
		/// COPPELIA仿真连接失败
		/// </summary>
		[Description("COPPELIA仿真连接失败")]
		YKE_RET_SYS_SIM_CONNECT = 0x0121,

		/// <summary>
		/// 访问了空对象
		/// </summary>
		[Description("访问了空对象")]
		YKE_RET_SYS_NULL = 0x0122,

		/// <summary>
		/// YKCat2服务未注册
		/// </summary>
		[Description("YKCat2服务未注册")]
		YKE_RET_YKSRV_NOT_INSTALL = 0x0123,

		/// <summary>
		/// YKCat2服务未启动
		/// </summary>
		[Description("YKCat2服务未启动")]
		YKE_RET_SYS_YKSRV_NOT_START = 0x0124,

		/// <summary>
		/// YKCat2服务操作失败
		/// </summary>
		[Description("YKCat2服务操作失败")]
		YKE_RET_YKSRV_OP_FAIL = 0x0125,

		/// <summary>
		/// 无权限访问YKCat2服务,请检查进程是否具备管理员权限。
		/// </summary>
		[Description("无权限访问YKCat2服务,请检查进程是否具备管理员权限。")]
		YKE_RET_YKSRV_ACCESS = 0x0126,

		/// <summary>
		/// 使用了不同版本的API库,更新ProCon时请同步更新YKCat2.dll到运行程序目录下
		/// </summary>
		[Description("使用了不同版本的API库,更新ProCon时请同步更新YKCat2.dll到运行程序目录下")]
		YKE_RET_SYS_API_VER = 0x012F,

		/// <summary>
		/// 函数日志已读完
		/// </summary>
		[Description("函数日志已读完")]
		YKE_RET_SYS_LOG_NULL = 0x0130,

		/// <summary>
		/// 命令没有记录到NTF缓冲区
		/// </summary>
		[Description("命令没有记录到NTF缓冲区")]
		YKE_RET_API_BUFFER_N = 0x141,

		/// <summary>
		/// YKCatN连接失败
		/// </summary>
		[Description("YKCatN连接失败")]
		YKE_RET_SYS_YKCATN_CONNECT = 0x0180,

		/// <summary>
		/// YKCatN通讯超时
		/// </summary>
		[Description("YKCatN通讯超时")]
		YKE_RET_SYS_YKCATN_TIMEOUT = 0x0181,

		/// <summary>
		/// YKCatN通讯句柄异常
		/// </summary>
		[Description("YKCatN通讯句柄异常")]
		YKE_RET_SYS_YKCATN_HANDLE = 0x0182,

		/// <summary>
		/// YKCatN通讯数据包过大
		/// </summary>
		[Description("YKCatN通讯数据包过大")]
		YKE_RET_SYS_YKCATN_SIZE = 0x0183,

		/// <summary>
		/// YKCatN通讯数据包长度不匹配
		/// </summary>
		[Description("YKCatN通讯数据包长度不匹配")]
		YKE_RET_SYS_YKCATN_LEN = 0x0184,

		/// <summary>
		/// YKCatN通讯数据包指令名称过长
		/// </summary>
		[Description("YKCatN通讯数据包指令名称过长")]
		YKE_RET_SYS_YKCATN_NAME = 0x0185,

		/// <summary>
		/// YKCatN通讯数据包指令参数过多
		/// </summary>
		[Description("YKCatN通讯数据包指令参数过多")]
		YKE_RET_SYS_YKCATN_PARA = 0x0186,

		/// <summary>
		/// 输入参数非法
		/// </summary>
		[Description("输入参数非法")]
		YKE_RET_INS_PARA = 0x0200,

		/// <summary>
		/// 无效的负数
		/// </summary>
		[Description("无效的负数")]
		YKE_RET_INS_NEG = 0x0201,

		/// <summary>
		/// 非法的浮点数
		/// </summary>
		[Description("非法的浮点数")]
		YKE_RET_INS_DOUBLE = 0x0202,

		/// <summary>
		/// 无效的枚举值
		/// </summary>
		[Description("无效的枚举值")]
		YKE_RET_INS_ENUM = 0x0203,

		/// <summary>
		/// 无效的指针
		/// </summary>
		[Description("无效的指针")]
		YKE_RET_INS_PTR = 0x0204,

		/// <summary>
		/// 硬急停信号有效
		/// </summary>
		[Description("硬急停信号有效")]
		YKE_RET_EMG_HARD = 0x0220,

		/// <summary>
		/// 软急停信号有效
		/// </summary>
		[Description("软急停信号有效")]
		YKE_RET_EMG_SOFT = 0x0221,

		/// <summary>
		/// 硬限位被触发
		/// </summary>
		[Description("硬限位被触发")]
		YKE_RET_LIMIT_H = 0x0230,

		/// <summary>
		/// 软限位被触发
		/// </summary>
		[Description("软限位被触发")]
		YKE_RET_LIMIT_S = 0x0231,

		/// <summary>
		/// 圆形区域保护被触发
		/// </summary>
		[Description("圆形区域保护被触发")]
		YKE_RET_CIRCLE_ZONE = 0x0232,

		/// <summary>
		/// 延时输出数量超出限制
		/// </summary>
		[Description("延时输出数量超出限制")]
		YKE_RET_IO_REVERSE_BUFFER_OV = 0x0240,

		/// <summary>
		/// 仿真运动指定的位置条件未满足
		/// </summary>
		[Description("仿真运动指定的位置条件未满足")]
		YKE_RET_AXIS_SIM_POS = 0x0300,

		/// <summary>
		/// 仿真运动指定的时间条件未满足
		/// </summary>
		[Description("仿真运动指定的时间条件未满足")]
		YKE_RET_AXIS_SIM_TIM = 0x0301,

		/// <summary>
		/// 仿真运动计算超时
		/// </summary>
		[Description("仿真运动计算超时")]
		YKE_RET_AXIS_SIM_TIMOUT = 0x0302,

		/// <summary>
		/// 仿真运动变参数失败
		/// </summary>
		[Description("仿真运动变参数失败")]
		YKE_RET_AXIS_SIM_INP = 0x0303,

		/// <summary>
		/// 轴不在位置运动或速度运动中
		/// </summary>
		[Description("轴不在位置运动或速度运动中")]
		YKE_RET_AXIS_OVERRIDE_INVALID = 0x0313,

		/// <summary>
		/// 轴正在使用中
		/// </summary>
		[Description("轴正在使用中")]
		YKE_RET_AXIS_BUSY = 0x0314,

		/// <summary>
		/// 轴未使能
		/// </summary>
		[Description("轴未使能")]
		YKE_RET_AXIS_READY = 0x0315,

		/// <summary>
		/// 轴序号不存在
		/// </summary>
		[Description("轴序号不存在")]
		YKE_RET_AXIS_INDEX = 0x0316,

		/// <summary>
		/// 运动模式不匹配
		/// </summary>
		[Description("运动模式不匹配")]
		YKE_RET_AXIS_MOTION_TYPE = 0x0317,

		/// <summary>
		/// 此功能需要轴切换成CSP模式
		/// </summary>
		[Description("此功能需要轴切换成CSP模式")]
		YKE_RET_AXIS_CSP = 0x0318,

		/// <summary>
		/// 不支持的运动曲线
		/// </summary>
		[Description("不支持的运动曲线")]
		YKE_RET_AXIS_CURVE = 0x0319,

		/// <summary>
		/// 主轴模式已启用,禁用此功能
		/// </summary>
		[Description("主轴模式已启用,禁用此功能")]
		YKE_RET_FOLLOW_MASTER = 0x0400,

		/// <summary>
		/// 凸轮主轴位置要求单调增加
		/// </summary>
		[Description("凸轮主轴位置要求单调增加")]
		YKE_RET_FOLLOW_CAM_MPOS = 0x0401,

		/// <summary>
		/// 多轴联动通道忙
		/// </summary>
		[Description("多轴联动通道忙")]
		YKE_RET_MULTI_AXIS_ACITVE = 0x0420,

		/// <summary>
		/// 多轴联动轴数量超过范围
		/// </summary>
		[Description("多轴联动轴数量超过范围")]
		YKE_RET_MULTI_AXIS_NUM = 0x0421,

		/// <summary>
		/// 联动轴不在同一个主站内
		/// </summary>
		[Description("联动轴不在同一个主站内")]
		YKE_RET_MULTI_AXIS_NODE = 0x0430,

		/// <summary>
		/// 单轴连续运动缓冲区溢出
		/// </summary>
		[Description("单轴连续运动缓冲区溢出")]
		YKE_RET_PVT_BUFFER_OV = 0x0500,

		/// <summary>
		/// PVT第一行数据位置必须为0
		/// </summary>
		[Description("PVT第一行数据位置必须为0")]
		YKE_RET_PVT_FIRST = 0x0501,

		/// <summary>
		/// PVTS最少需要增加2个点
		/// </summary>
		[Description("PVTS最少需要增加2个点")]
		YKE_RET_PVTS_NUM = 0x0502,

		/// <summary>
		/// 分配PVTS内存失败
		/// </summary>
		[Description("分配PVTS内存失败")]
		YKE_RET_PVTS_DYNC = 0x0503,

		/// <summary>
		/// PVTS时间参数错误
		/// </summary>
		[Description("PVTS时间参数错误")]
		YKE_RET_PVTS_TIM = 0x0504,

		/// <summary>
		/// PT加速度比例参数错误
		/// </summary>
		[Description("PT加速度比例参数错误")]
		YKE_RET_PT_ACC = 0x0505,

		/// <summary>
		/// PVTS第一点启动速度必须为0
		/// </summary>
		[Description("PVTS第一点启动速度必须为0")]
		YKE_RET_PVTS_SVEL = 0x0506,

		/// <summary>
		/// 坐标系已初始化
		/// </summary>
		[Description("坐标系已初始化")]
		YKE_RET_GROUP_INIT = 0x0600,

		/// <summary>
		/// 坐标系未初始化
		/// </summary>
		[Description("坐标系未初始化")]
		YKE_RET_GROUP_DEINIT = 0x0601,

		/// <summary>
		/// 坐标系轴序号重复
		/// </summary>
		[Description("坐标系轴序号重复")]
		YKE_RET_GROUP_AXIS_INDEX_REPEAT = 0x0602,

		/// <summary>
		/// 坐标系运行中
		/// </summary>
		[Description("坐标系运行中")]
		YKE_RET_GROUP_ACTIVE = 0x0603,

		/// <summary>
		/// 坐标系缓冲区已满,缓冲区最大容量4096
		/// </summary>
		[Description("坐标系缓冲区已满,缓冲区最大容量4096")]
		YKE_RET_GROUP_BUFFER_FULL = 0x0604,

		/// <summary>
		/// 坐标系内的轴有报警
		/// </summary>
		[Description("坐标系内的轴有报警")]
		YKE_RET_GROUP_AXIS_WARN = 0x0605,

		/// <summary>
		/// 坐标系有报警
		/// </summary>
		[Description("坐标系有报警")]
		YKE_RET_GROUP_WARN = 0x0606,

		/// <summary>
		/// 坐标系内的轴处于单轴运行模式
		/// </summary>
		[Description("坐标系内的轴处于单轴运行模式")]
		YKE_RET_GROUP_AXIS_SINGLE = 0x0607,

		/// <summary>
		/// 坐标系绑定的轴需要在CSP模式下
		/// </summary>
		[Description("坐标系绑定的轴需要在CSP模式下")]
		YKE_RET_GROUP_AXIS_CSP = 0x0608,

		/// <summary>
		/// 坐标系外轴和内部轴重合
		/// </summary>
		[Description("坐标系外轴和内部轴重合")]
		YKE_RET_GROUP_AXIS_INDEX_REPEAT2 = 0x0609,

		/// <summary>
		/// 坐标系暂停中
		/// </summary>
		[Description("坐标系暂停中")]
		YKE_RET_GROUP_PAUSE = 0x0610,

		/// <summary>
		/// 有相对指令不支持暂停模式
		/// </summary>
		[Description("有相对指令不支持暂停模式")]
		YKE_RET_GROUP_INC = 0x0611,

		/// <summary>
		/// 坐标系正在减速停止
		/// </summary>
		[Description("坐标系正在减速停止")]
		YKE_RET_GROUP_STOPPING = 0x0612,

		/// <summary>
		/// 龙门从轴不能加在轴列表中
		/// </summary>
		[Description("龙门从轴不能加在轴列表中")]
		YKE_RET_GROUP_AXIS_GANTRY = 0x0613,

		/// <summary>
		/// 坐标系轴不在同一个主站内
		/// </summary>
		[Description("坐标系轴不在同一个主站内")]
		YKE_RET_GROUP_AXIS_NODE = 0x0614,

		/// <summary>
		/// 在螺距补偿禁用状态下更新配置
		/// </summary>
		[Description("在螺距补偿禁用状态下更新配置")]
		YKE_RET_PITCH_ENA = 0x0700,

		/// <summary>
		/// 螺距补偿和2D补偿不能同时启用
		/// </summary>
		[Description("螺距补偿和2D补偿不能同时启用")]
		YKE_RET_PITCH_REPEAT = 0x0701,

		/// <summary>
		/// 补偿值大于了间距的20%
		/// </summary>
		[Description("补偿值大于了间距的20%")]
		YKE_RET_PITCH_DATA = 0x0702,

		/// <summary>
		/// 禁止在伺服下使能状态下启用/禁用机械补偿
		/// </summary>
		[Description("禁止在伺服下使能状态下启用/禁用机械补偿")]
		YKE_RET_PITCH_DRV = 0x0703,

		/// <summary>
		/// 补偿功能已启用,禁用此功能
		/// </summary>
		[Description("补偿功能已启用,禁用此功能")]
		YKE_RET_PITCH_USED = 0x0704,

		/// <summary>
		/// 总线未初始化完成,在ProR中查看总线日志及当前报警。
		/// </summary>
		[Description("总线未初始化完成,在ProR中查看总线日志及当前报警。")]
		YKE_RET_BUS_INIT = 0x0800,

		/// <summary>
		/// SDO列表溢出
		/// </summary>
		[Description("SDO列表溢出")]
		YKE_RET_BUS_SDO_OV = 0x0801,

		/// <summary>
		/// SDO站号不存在
		/// </summary>
		[Description("SDO站号不存在")]
		YKE_RET_BUS_SDO_U = 0x0802,

		/// <summary>
		/// SDO对象字典不存在或者不可读写
		/// </summary>
		[Description("SDO对象字典不存在或者不可读写")]
		YKE_RET_BUS_SDO_OD = 0x0803,

		/// <summary>
		/// SDO对象字典访问超时
		/// </summary>
		[Description("SDO对象字典访问超时")]
		YKE_RET_BUS_SDO_TIMOUT = 0x0804,

		/// <summary>
		/// 对象字典未加入到PDO中
		/// </summary>
		[Description("对象字典未加入到PDO中")]
		YKE_RET_BUS_OD_PDO = 0x0805,

		/// <summary>
		/// 对象字典已加入到PDO中
		/// </summary>
		[Description("对象字典已加入到PDO中")]
		YKE_RET_BUS_OD_SDO = 0x0806,

		/// <summary>
		/// 对象字典被系统使用,请使用专用函数操作
		/// </summary>
		[Description("对象字典被系统使用,请使用专用函数操作")]
		YKE_RET_BUS_OD_RD = 0x0807,

		/// <summary>
		/// 仿真模式不支持总线扫描
		/// </summary>
		[Description("仿真模式不支持总线扫描")]
		YKE_RET_BUS_SIM_SCAN = 0x0808,

		/// <summary>
		/// 未开启数据抓包功能
		/// </summary>
		[Description("未开启数据抓包功能")]
		YKE_RET_BUS_SNAP_UNUSED = 0x0809,

		/// <summary>
		/// 数据包缓冲区为空
		/// </summary>
		[Description("数据包缓冲区为空")]
		YKE_RET_BUS_SNAP_IDEL = 0x0810,

		/// <summary>
		/// 驱动器有报警
		/// </summary>
		[Description("驱动器有报警")]
		YKE_RET_ERROR_DRV_WARN = 0x0820,

		/// <summary>
		/// 软件探针功能已启用不能修改配置
		/// </summary>
		[Description("软件探针功能已启用不能修改配置")]
		YKE_RET_PROBE_ACTIVE = 0x0900,

		/// <summary>
		/// 软件位置比较功能已启用不能修改配置
		/// </summary>
		[Description("软件位置比较功能已启用不能修改配置")]
		YKE_RET_SOFT_COMPARE_ACTIVE = 0x0a00,

		/// <summary>
		/// 位置比较器缓冲区队列已满,在空闲数量大于0时写入比较数据
		/// </summary>
		[Description("位置比较器缓冲区队列已满,在空闲数量大于0时写入比较数据")]
		YKE_RET_COMPARE_BUFFER_OV = 0x0a01,

		/// <summary>
		/// 固定模式/线性模式的位置比较器,开始比较后不能再写入数据
		/// </summary>
		[Description("固定模式/线性模式的位置比较器,开始比较后不能再写入数据")]
		YKE_RET_COMPARE_BUFFER_FIX = 0x0a02,

		/// <summary>
		/// 加载NTF(C#)实时程序失败
		/// </summary>
		[Description("加载NTF(C#)实时程序失败")]
		YKE_RET_NTF_LOAD = 0x0B00,

		/// <summary>
		/// 实时程序文件不存在
		/// </summary>
		[Description("实时程序文件不存在")]
		YKE_RET_NTF_EXIST = 0x0B01,

		/// <summary>
		/// 等待对象初始化失败
		/// </summary>
		[Description("等待对象初始化失败")]
		YKE_RET_WAIT_INIT = 0x0B60,

		/// <summary>
		/// 等待对象被删除
		/// </summary>
		[Description("等待对象被删除")]
		YKE_RET_WAIT_DEL = 0x0B61,

		/// <summary>
		/// 等待对象超时
		/// </summary>
		[Description("等待对象超时")]
		YKE_RET_WAIT_TIMEOUT = 0x0B62,

		/// <summary>
		/// 等待对象失败(操作系统错误)
		/// </summary>
		[Description("等待对象失败(操作系统错误)")]
		YKE_RET_WAIT_FAIL = 0x0B63,

		/// <summary>
		/// 等待通道忙
		/// </summary>
		[Description("等待通道忙")]
		YKE_RET_WAIT_BUSY = 0x0B64,

		/// <summary>
		/// 等待对象失败(打开事件失败)
		/// </summary>
		[Description("等待对象失败(打开事件失败)")]
		YKE_RET_WAIT_OPEN = 0x0B65,

		/// <summary>
		/// 等待对象失败(热复位)
		/// </summary>
		[Description("等待对象失败(热复位)")]
		YKE_RET_WAIT_SYS_RESET = 0x0B66,

		/// <summary>
		/// 等待对象失败(runtime退出)
		/// </summary>
		[Description("等待对象失败(runtime退出)")]
		YKE_RET_WAIT_INS_RESET = 0x0B67,

		/// <summary>
		/// 等待对象失败(runtime退出)
		/// </summary>
		[Description("等待对象失败(runtime退出)")]
		YKE_RET_WAIT_EXIT = 0x0B68,

		/// <summary>
		/// ProEn工程共享内存打开
		/// </summary>
		[Description("ProEn工程共享内存打开")]
		YKE_RET_PROEN_SHAREM = 0x0C00,

		/// <summary>
		/// ProEn工程注册失败
		/// </summary>
		[Description("ProEn工程注册失败")]
		YKE_RET_PROEN_OV = 0x0C01,

		/// <summary>
		/// ProEn工程已经打开
		/// </summary>
		[Description("ProEn工程已经打开")]
		YKE_RET_PROEN_EXIST = 0x0C02,

		/// <summary>
		/// ProEn工程文件打开失败
		/// </summary>
		[Description("ProEn工程文件打开失败")]
		YKE_RET_PROEN_OPEN_FAIL = 0x0C10,

		/// <summary>
		/// ProEn工程文件格式错误
		/// </summary>
		[Description("ProEn工程文件格式错误")]
		YKE_RET_PROEN_MAGIC_FAIL = 0x0C11,

		/// <summary>
		/// 下载ProEn工程文件超时
		/// </summary>
		[Description("下载ProEn工程文件超时")]
		YKE_RET_PROEN_TIMEOUT = 0x0C12,

		/// <summary>
		/// 文件路径长度太短(小于5)
		/// </summary>
		[Description("文件路径长度太短(小于5)")]
		YKE_RET_PROEN_FILENAME = 0x0C13,

		/// <summary>
		/// 文件扩展名错误,文件由ProEN导出,扩展名为bprj
		/// </summary>
		[Description("文件扩展名错误,文件由ProEN导出,扩展名为bprj")]
		YKE_RET_PROEN_FILE_EXT = 0x0C14,

		/// <summary>
		/// 关联信号不在同一个主站内
		/// </summary>
		[Description("关联信号不在同一个主站内")]
		YKE_RET_EVENT_NODE = 0x0d00,

		/// <summary>
		/// 事件已启动
		/// </summary>
		[Description("事件已启动")]
		YKE_RET_EVENT_BUSY = 0x0d01,

		/// <summary>
		/// 指定编码器不存在
		/// </summary>
		[Description("指定编码器不存在")]
		YKE_RET_EVENT_ENCODER = 0x0d02,

		/// <summary>
		/// 圆形区域参数未初始化
		/// </summary>
		[Description("圆形区域参数未初始化")]
		YKE_RET_CIRCLE_ZONE_INIT = 0x0d40,

		/// <summary>
		/// 圆形区域轴序号重复
		/// </summary>
		[Description("圆形区域轴序号重复")]
		YKE_RET_CIRCLE_ZONE_INDEX = 0x0d41,

		/// <summary>
		/// 硬件锁访问超时
		/// </summary>
		[Description("硬件锁访问超时")]
		YKE_RET_DOGGLE_TIMEOUT = 0x0d80,

		/// <summary>
		/// NTF未初始化
		/// </summary>
		[Description("NTF未初始化")]
		YKE_RET_NTF_INIT = 0x0da0,

		/// <summary>
		/// NTF API缓冲区未初始化
		/// </summary>
		[Description("NTF API缓冲区未初始化")]
		YKE_RET_NTF_API_BUFFER_INIT = 0x0da1,

		/// <summary>
		/// NTF API缓冲区通道未初始化
		/// </summary>
		[Description("NTF API缓冲区通道未初始化")]
		YKE_RET_NTF_API_BUFFER_CH_INIT = 0x0da2,

		/// <summary>
		/// NTF API缓冲区通道内缓冲区溢出
		/// </summary>
		[Description("NTF API缓冲区通道内缓冲区溢出")]
		YKE_RET_NTF_API_BUFFER_CH_OV = 0x0da3,

		/// <summary>
		/// NTF API缓冲区指令无法识别
		/// </summary>
		[Description("NTF API缓冲区指令无法识别")]
		YKE_RET_NTF_API_BUFFER_INS = 0x0da4,

		/// <summary>
		/// NTF API缓冲区忙
		/// </summary>
		[Description("NTF API缓冲区忙")]
		YKE_RET_NTF_API_BUFFER_ACTIVE = 0x0da5,

		/// <summary>
		/// 示波器启用通道数为0
		/// </summary>
		[Description("示波器启用通道数为0")]
		YKE_RET_OSC_ZERO_ENA = 0x0e00,

		/// <summary>
		/// 示波器已经启用,禁止变更参数
		/// </summary>
		[Description("示波器已经启用,禁止变更参数")]
		YKE_RET_OSC_ACTIVE = 0x0e01,

		/// <summary>
		/// 编码器已和轴绑定,不能修改值
		/// </summary>
		[Description("编码器已和轴绑定,不能修改值")]
		YKE_RET_PCI_ENCODER_AXIS = 0x0e20,
	};

	/// <summary>
	/// 运动错误代码
	/// </summary>
	public enum YKE_MC_ERROR
	{
		/// <summary>
		/// 无错误
		/// </summary>
		[Description("无错误")]
		YKE_ERR_MC_OK = 0x0000,

		/// <summary>
		/// 软急停信号有效导致轴停止
		/// </summary>
		[Description("软急停信号有效导致轴停止")]
		YKE_ERR_MC_SOFT_EMG = 0x0001,

		/// <summary>
		/// 硬急停信号有效导致轴停止
		/// </summary>
		[Description("硬急停信号有效导致轴停止")]
		YKE_ERR_MC_HARD_EMG = 0x0002,

		/// <summary>
		/// 系统停止或热复位导致轴停止
		/// </summary>
		[Description("系统停止或热复位导致轴停止")]
		YKE_ERR_MC_SYS_STOP = 0x0003,

		/// <summary>
		/// 轴未上使能
		/// </summary>
		[Description("轴未上使能")]
		YKE_ERR_MC_AXIS_READY = 0x0101,

		/// <summary>
		/// 正硬限位被触发
		/// </summary>
		[Description("正硬限位被触发")]
		YKE_ERR_MC_LIMIT_HARDP = 0x0102,

		/// <summary>
		/// 负硬限位被触发
		/// </summary>
		[Description("负硬限位被触发")]
		YKE_ERR_MC_LIMIT_HARDN = 0x0103,

		/// <summary>
		/// 正软限位被触发
		/// </summary>
		[Description("正软限位被触发")]
		YKE_ERR_MC_LIMIT_SOFTP = 0x0104,

		/// <summary>
		/// 负软限位被触发
		/// </summary>
		[Description("负软限位被触发")]
		YKE_ERR_MC_LIMIT_SOFTN = 0x0105,

		/// <summary>
		/// 位置跟随误差过大
		/// </summary>
		[Description("位置跟随误差过大")]
		YKE_ERR_MC_POSITION_LAG = 0x0106,

		/// <summary>
		/// 规划完成后,反馈位置在指定时间(默认3秒)内未到达指定范围内
		/// </summary>
		[Description("规划完成后,反馈位置在指定时间(默认3秒)内未到达指定范围内")]
		YKE_ERR_MC_INP = 0x0107,

		/// <summary>
		/// 驱动器控制模式不匹配
		/// </summary>
		[Description("驱动器控制模式不匹配")]
		YKE_ERR_MC_DRV_OP_MODE = 0x0108,

		/// <summary>
		/// 正在运动中不能切换模式
		/// </summary>
		[Description("正在运动中不能切换模式")]
		YKE_ERR_MC_DRV_OP_MODE_ACTIVE = 0x0109,

		/// <summary>
		/// 从轴已停止
		/// </summary>
		[Description("从轴已停止")]
		YKE_ERR_MC_AXIS_SLAVE_STOP = 0x010a,

		/// <summary>
		/// 规划完成后,脉冲型驱动器未给出到位信号
		/// </summary>
		[Description("规划完成后,脉冲型驱动器未给出到位信号")]
		YKE_ERR_MC_DRV_INP = 0x010b,

		/// <summary>
		/// 硬跟随轴和主轴位置偏差过大
		/// </summary>
		[Description("硬跟随轴和主轴位置偏差过大")]
		YKE_ERR_MC_GANTRY_LAG = 0x0120,

		/// <summary>
		/// 回原点过程中,在指定距离内未找到限位开关
		/// </summary>
		[Description("回原点过程中,在指定距离内未找到限位开关")]
		YKE_ERR_MC_HOME_LIMIT = 0x0150,

		/// <summary>
		/// 回原点过程中,在指定距离内未找到原点开关
		/// </summary>
		[Description("回原点过程中,在指定距离内未找到原点开关")]
		YKE_ERR_MC_HOME_HOME = 0x0151,

		/// <summary>
		/// 回原点过程中,在指定距离内未找到探针
		/// </summary>
		[Description("回原点过程中,在指定距离内未找到探针")]
		YKE_ERR_MC_HOME_PROBE = 0x0152,

		/// <summary>
		/// 35/37模式,不能在限位位置回原
		/// </summary>
		[Description("35/37模式,不能在限位位置回原")]
		YKE_ERR_MC_HOME_3537 = 0x0153,

		/// <summary>
		/// 异常碰限位停止
		/// </summary>
		[Description("异常碰限位停止")]
		YKE_ERR_MC_HOME_STOP1 = 0x0154,

		/// <summary>
		/// 回原过程中,探针访问(SDO)出错
		/// </summary>
		[Description("回原过程中,探针访问(SDO)出错")]
		YKE_ERR_MC_HOME_TOUCH = 0x0155,

		/// <summary>
		/// 回原输入信号所在从站模块已经掉线
		/// </summary>
		[Description("回原输入信号所在从站模块已经掉线")]
		YKE_ERR_MC_HOME_OFFLINE = 0x0156,

		/// <summary>
		/// 脉冲轴探针未配置
		/// </summary>
		[Description("脉冲轴探针未配置")]
		YKE_ERR_MC_PLS_PROBE_CONFIG = 0x160,

		/// <summary>
		/// 二维补偿变化量超过了最高速度
		/// </summary>
		[Description("二维补偿变化量超过了最高速度")]
		YKE_ERR_MC_PITCH2D_VEL = 0x170,

		/// <summary>
		/// 驱动器发生报警
		/// </summary>
		[Description("驱动器发生报警")]
		YKE_ERR_MC_DRV_WARN = 0x0200,

		/// <summary>
		/// 驱动器PP模式发生错误
		/// </summary>
		[Description("驱动器PP模式发生错误")]
		YKE_ERR_MC_DRV_PP = 0x0201,

		/// <summary>
		/// 驱动器回原时发生错误6041.13=1
		/// </summary>
		[Description("驱动器回原时发生错误6041.13=1")]
		YKE_ERR_MC_DRV_HM = 0x0202,

		/// <summary>
		/// PV模式下SDO访问出错
		/// </summary>
		[Description("PV模式下SDO访问出错")]
		YKE_ERR_MC_PV_SDO = 0x0203,

		/// <summary>
		/// PP模式下SDO访问出错
		/// </summary>
		[Description("PP模式下SDO访问出错")]
		YKE_ERR_MC_PP_SDO = 0x0204,

		/// <summary>
		/// 转矩相关寄存器未加入到PDO中
		/// </summary>
		[Description("转矩相关寄存器未加入到PDO中")]
		YKE_ERR_MC_TORQUE_PDO = 0x0208,

		/// <summary>
		/// 驱动器上使能失败
		/// </summary>
		[Description("驱动器上使能失败")]
		YKE_ERR_MC_POWER_ON = 0x0210,

		/// <summary>
		/// 清除驱动器报警失败
		/// </summary>
		[Description("清除驱动器报警失败")]
		YKE_ERR_MC_CLR_DRV = 0x0211,

		/// <summary>
		/// 轨迹运动错误
		/// </summary>
		[Description("轨迹运动错误")]
		YKE_ERR_MC_GROUP_PATH = 0x0250,

		/// <summary>
		/// 圆参数错误
		/// </summary>
		[Description("圆参数错误")]
		YKE_ERR_MC_GROUP_CIR = 0x0251,

		/// <summary>
		/// 坐标系中的轴有报警
		/// </summary>
		[Description("坐标系中的轴有报警")]
		YKE_ERR_MC_GROUP_AXIS = 0x0252,

		/// <summary>
		/// 坐标系内轴序号错误
		/// </summary>
		[Description("坐标系内轴序号错误")]
		YKE_ERR_MC_GROUP_AXIS_INDEX = 0x0253,

		/// <summary>
		/// 坐标系中的轴已在外部启动
		/// </summary>
		[Description("坐标系中的轴已在外部启动")]
		YKE_ERR_MC_GROUP_AXIS_ACTIVE1 = 0x0254,

		/// <summary>
		/// 坐标系中的轴未到位
		/// </summary>
		[Description("坐标系中的轴未到位")]
		YKE_ERR_MC_GROUP_AXIS_INPOS = 0x0255,

		/// <summary>
		/// 坐标系中的输出轴已经启动
		/// </summary>
		[Description("坐标系中的输出轴已经启动")]
		YKE_ERR_MC_GROUP_AXIS_ACTIVE2 = 0x0256,

		/// <summary>
		/// 坐标系中的轴未使能
		/// </summary>
		[Description("坐标系中的轴未使能")]
		YKE_ERR_MC_GROUP_AXIS_READY = 0x0257,

		/// <summary>
		/// 坐标系轴已到限位
		/// </summary>
		[Description("坐标系轴已到限位")]
		YKE_ERR_MC_GROUP_AXIS_LIMIT = 0x0258,

		/// <summary>
		/// 坐标系硬急停有效
		/// </summary>
		[Description("坐标系硬急停有效")]
		YKE_ERR_MC_GROUP_HARD_EMG = 0x0259,

		/// <summary>
		/// 坐标系软急停有效
		/// </summary>
		[Description("坐标系软急停有效")]
		YKE_ERR_MC_GROUP_SOFT_EMG = 0x025a,

		/// <summary>
		/// 需要开启CNC扩展坐标系选项
		/// </summary>
		[Description("需要开启CNC扩展坐标系选项")]
		YKE_ERR_MC_GROUP_CNC_EXT = 0x0260,

		/// <summary>
		/// CNC最多支持4个坐标系
		/// </summary>
		[Description("CNC最多支持4个坐标系")]
		YKE_ERR_MC_GROUP_CNC_NUM = 0x0261,

		/// <summary>
		/// CNC当前模式下不支持直线插补指令
		/// </summary>
		[Description("CNC当前模式下不支持直线插补指令")]
		YKE_ERR_MC_GROUP_CNC_LINE = 0x0262,

		/// <summary>
		/// CNC当前模式下不支持圆弧插补指令
		/// </summary>
		[Description("CNC当前模式下不支持圆弧插补指令")]
		YKE_ERR_MC_GROUP_CNC_CIR = 0x0263,

		/// <summary>
		/// CNC当前模式下不支持G代码指令
		/// </summary>
		[Description("CNC当前模式下不支持G代码指令")]
		YKE_ERR_MC_GROUP_CNC_GCODE = 0x0264,

		/// <summary>
		/// CNC当前模式下不支持文件加工指令
		/// </summary>
		[Description("CNC当前模式下不支持文件加工指令")]
		YKE_ERR_MC_GROUP_CNC_FILE = 0x0265,

		/// <summary>
		/// 定义结束
		/// </summary>
		[Description("定义结束")]
		YKE_ERR_MC_END = 0x0300,
	};

	/// <summary>
	/// 系统错误类型
	/// </summary>
	public enum YKE_SYSTEM_ERROR
	{
		/// <summary>
		/// 无错误
		/// </summary>
		[Description("无错误")]
		YKE_ERR_SYS_APP_NONE = 0x0000,

		/// <summary>
		/// 配置文件版本太高
		/// </summary>
		[Description("配置文件版本太高")]
		YKE_ERR_SYS_FILE_VER = 0x0001,

		/// <summary>
		/// 配置文件格式不对
		/// </summary>
		[Description("配置文件格式不对")]
		YKE_ERR_SYS_FILE_CFG = 0x0002,

		/// <summary>
		/// 配置文件不存在
		/// </summary>
		[Description("配置文件不存在")]
		YKE_ERR_SYS_FILE_EXIST = 0x0003,

		/// <summary>
		/// 配置文件读取失败
		/// </summary>
		[Description("配置文件读取失败")]
		YKE_ERR_SYS_FILE_READ = 0x0004,

		/// <summary>
		/// 脉冲卡配置版本过低
		/// </summary>
		[Description("脉冲卡配置版本过低")]
		YKE_ERR_SYS_CARD_VER1 = 0x0005,

		/// <summary>
		/// 脉冲卡配置版本过高
		/// </summary>
		[Description("脉冲卡配置版本过高")]
		YKE_ERR_SYS_CARD_VER2 = 0x0006,

		/// <summary>
		/// 脉冲卡固件版本过低
		/// </summary>
		[Description("脉冲卡固件版本过低")]
		YKE_ERR_SYS_BRD_VER = 0x0007,

		/// <summary>
		/// 实时系统基准不正确
		/// </summary>
		[Description("实时系统基准不正确")]
		YKE_ERR_SYS_CLK_BASE = 0x0008,

		/// <summary>
		/// 低于125us周期不支持总线和脉冲混用
		/// </summary>
		[Description("低于125us周期不支持总线和脉冲混用")]
		YKE_ERR_SYS_DC_125US = 0x0009,

		/// <summary>
		/// 基础运动库版本不匹配
		/// </summary>
		[Description("基础运动库版本不匹配")]
		YKE_ERR_SYS_YKGROUP_VER = 0x000A,

		/// <summary>
		/// 脉冲卡无法识别
		/// </summary>
		[Description("脉冲卡无法识别")]
		YKE_ERR_SYS_CARD_UNKNOWN = 0x000B,

		/// <summary>
		/// 总线周期小于等于250us时,请使用专用PC
		/// </summary>
		[Description("总线周期小于等于250us时,请使用专用PC")]
		YKE_ERR_SYS_250us_PC = 0x000C,

		/// <summary>
		/// CNC运动库初始化失败
		/// </summary>
		[Description("CNC运动库初始化失败")]
		YKE_ERR_SYS_APP_INIT_I = 0x0010,

		/// <summary>
		/// NTF(CPP)加载失败
		/// </summary>
		[Description("NTF(CPP)加载失败")]
		YKE_ERR_SYS_NTF_LOAD = 0x0011,

		/// <summary>
		/// NTF(CPP)库初始化失败
		/// </summary>
		[Description("NTF(CPP)库初始化失败")]
		YKE_ERR_SYS_NTF_INIT = 0x0012,

		/// <summary>
		/// 实时系统节点B未启用
		/// </summary>
		[Description("实时系统节点B未启用")]
		YKE_ERR_SYS_NODEB_ENA = 0x0013,

		/// <summary>
		/// 实时系统节点C未启用
		/// </summary>
		[Description("实时系统节点C未启用")]
		YKE_ERR_SYS_NODEC_ENA = 0x0014,

		/// <summary>
		/// 实时系统节点D未启用
		/// </summary>
		[Description("实时系统节点D未启用")]
		YKE_ERR_SYS_NODED_ENA = 0x0015,

		/// <summary>
		/// 主站B服务加载失败
		/// </summary>
		[Description("主站B服务加载失败")]
		YKE_ERR_SYS_NODEB_FAIL = 0x0016,

		/// <summary>
		/// 主站C服务加载失败
		/// </summary>
		[Description("主站C服务加载失败")]
		YKE_ERR_SYS_NODEC_FAIL = 0x0017,

		/// <summary>
		/// 主站D服务加载失败
		/// </summary>
		[Description("主站D服务加载失败")]
		YKE_ERR_SYS_NODED_FAIL = 0x0018,

		/// <summary>
		/// NTF负载超过了总线周期时间
		/// </summary>
		[Description("NTF负载超过了总线周期时间")]
		YKE_ERR_SYS_NTF_PAYLOAD = 0x0019,

		/// <summary>
		/// 本地脉冲卡初始化失败,解决后请手动清除本警告
		/// </summary>
		[Description("本地脉冲卡初始化失败,解决后请手动清除本警告")]
		YKE_ERR_SYS_BRD_INIT = 0x0020,

		/// <summary>
		/// 应用程序超时
		/// </summary>
		[Description("应用程序超时")]
		YKE_ERR_SYS_APP_WTD = 0x0030,

		/// <summary>
		/// 缺少授权权限
		/// </summary>
		[Description("缺少授权权限")]
		YKE_ERR_SYS_LIC = 0x0031,

		/// <summary>
		/// 动态内存分配失败
		/// </summary>
		[Description("动态内存分配失败")]
		YKE_ERR_SYS_DYNC_MEM = 0x0032,

		/// <summary>
		/// 网络没有链接
		/// </summary>
		[Description("网络没有链接")]
		YKE_ERR_SYS_APP_CHK_NIC = 0x0040,

		/// <summary>
		/// 从站数量不匹配
		/// </summary>
		[Description("从站数量不匹配")]
		YKE_ERR_SYS_SLAVE_CHKNUM = 0x0041,

		/// <summary>
		/// 非ECAT数据帧
		/// </summary>
		[Description("非ECAT数据帧")]
		YKE_ERR_SYS_LINK_ECAT = 0x0042,

		/// <summary>
		/// 和DC主站失去同步
		/// </summary>
		[Description("和DC主站失去同步")]
		YKE_ERR_SYS_DC_SHIFT = 0x0043,

		/// <summary>
		/// PDO通讯有错误,链路已断开
		/// </summary>
		[Description("PDO通讯有错误,链路已断开")]
		YKE_ERR_SYS_DISCONNECT = 0x0044,

		/// <summary>
		/// 第1帧有从站未处理数据
		/// </summary>
		[Description("第1帧有从站未处理数据")]
		YKE_ERR_SYS_PDO1_WKC = 0x0045,

		/// <summary>
		/// 第2帧有从站未处理数据
		/// </summary>
		[Description("第2帧有从站未处理数据")]
		YKE_ERR_SYS_PDO2_WKC = 0x0046,

		/// <summary>
		/// 第3帧有从站未处理数据
		/// </summary>
		[Description("第3帧有从站未处理数据")]
		YKE_ERR_SYS_PDO3_WKC = 0x0047,

		/// <summary>
		/// 第4帧有从站未处理数据
		/// </summary>
		[Description("第4帧有从站未处理数据")]
		YKE_ERR_SYS_PDO4_WKC = 0x0048,

		/// <summary>
		/// 启动参数中有无法识别的数据类型
		/// </summary>
		[Description("启动参数中有无法识别的数据类型")]
		YKE_ERR_SYS_DATA_TYPE = 0x004a,

		/// <summary>
		/// 环网冗余的主从网口插反了
		/// </summary>
		[Description("环网冗余的主从网口插反了")]
		YKE_ERR_SYS_NIC_SWAP = 0x004b,

		/// <summary>
		/// 系统配置发生变化,请执行热复位命令
		/// </summary>
		[Description("系统配置发生变化,请执行热复位命令")]
		YKE_ERR_SYS_APP_HDCHANGE = 0x0051,

		/// <summary>
		/// DC周期发生变化
		/// </summary>
		[Description("DC周期发生变化")]
		YKE_ERR_SYS_DC_CYCLE = 0x0052,

		/// <summary>
		/// 脉冲轴发送队列溢出
		/// </summary>
		[Description("脉冲轴发送队列溢出")]
		YKE_ERR_SYS_PLS_OVERFLOW = 0x0060,

		/// <summary>
		/// 脉冲轴频率超限制
		/// </summary>
		[Description("脉冲轴频率超限制")]
		YKE_ERR_SYS_PLS_MAX = 0x0061,

		/// <summary>
		/// 脉冲卡配置发生变化
		/// </summary>
		[Description("脉冲卡配置发生变化")]
		YKE_ERR_SYS_APP_BRDCHANGE = 0x0062,

		/// <summary>
		/// 急停信号所在从站模块已经掉线
		/// </summary>
		[Description("急停信号所在从站模块已经掉线")]
		YKE_ERR_SYS_EMG_OFFLINE = 0x070,

		/// <summary>
		/// 软急停急停信号已生效
		/// </summary>
		[Description("软急停急停信号已生效")]
		YKE_ERR_SYS_EMG_SOFT = 0x071,

		/// <summary>
		/// 硬急停急停信号已生效
		/// </summary>
		[Description("硬急停急停信号已生效")]
		YKE_ERR_SYS_EMG_HARD = 0x072,

		/// <summary>
		/// 事件中轴启动失败
		/// </summary>
		[Description("事件中轴启动失败")]
		YKE_ERR_EVENT_START_AXIS = 0x080,

		/// <summary>
		/// 事件中坐标系启动失败
		/// </summary>
		[Description("事件中坐标系启动失败")]
		YKE_ERR_EVENT_START_GROUP = 0x081,

		/// <summary>
		/// 事件中读PDO失败
		/// </summary>
		[Description("事件中读PDO失败")]
		YKE_ERR_EVENT_READ_PDO = 0x082,

		/// <summary>
		/// 事件中写PDO失败
		/// </summary>
		[Description("事件中写PDO失败")]
		YKE_ERR_EVENT_WRITE_PDO = 0x083,
	};

	/// <summary>
	/// 从站错误类型
	/// </summary>
	public enum YKE_SLAVE_ERROR
	{
		/// <summary>
		/// 无
		/// </summary>
		[Description("无")]
		YKE_ERR_SLAVE_PDO_NONE = 0x0000,

		/// <summary>
		/// 非法的PDO数据类型
		/// </summary>
		[Description("非法的PDO数据类型")]
		YKE_ERR_SLAVE_PDO_DTYPE = 0x0100,

		/// <summary>
		/// PDO配置不完整
		/// </summary>
		[Description("PDO配置不完整")]
		YKE_ERR_SLAVE_PDO = 0x0101,

		/// <summary>
		/// 制造商ID不匹配
		/// </summary>
		[Description("制造商ID不匹配")]
		YKE_ERR_SLAVE_VID = 0x0102,

		/// <summary>
		/// 产品ID不匹配
		/// </summary>
		[Description("产品ID不匹配")]
		YKE_ERR_SLAVE_PID = 0x0103,

		/// <summary>
		/// 切换到Init状态失败
		/// </summary>
		[Description("切换到Init状态失败")]
		YKE_ERR_SLAVE_TO_INIT = 0x0104,

		/// <summary>
		/// 切换到PreOP状态失败
		/// </summary>
		[Description("切换到PreOP状态失败")]
		YKE_ERR_SLAVE_TO_PREOP = 0x0105,

		/// <summary>
		/// 切换到SafeOP状态失败
		/// </summary>
		[Description("切换到SafeOP状态失败")]
		YKE_ERR_SLAVE_TO_SAFEOP = 0x0106,

		/// <summary>
		/// 切换到OP状态失败
		/// </summary>
		[Description("切换到OP状态失败")]
		YKE_ERR_SLAVE_TO_OP = 0x0107,

		/// <summary>
		/// SDO写对象字典数据失败
		/// </summary>
		[Description("SDO写对象字典数据失败")]
		YKE_ERR_SLAVE_SDO_WRITE = 0x0108,

		/// <summary>
		/// SDO读对象字典数据失败
		/// </summary>
		[Description("SDO读对象字典数据失败")]
		YKE_ERR_SLAVE_SDO_READ = 0x0109,

		/// <summary>
		/// SDO访问出错
		/// </summary>
		[Description("SDO访问出错")]
		YKE_ERR_SLAVE_SDO = 0x010a,

		/// <summary>
		/// SDO读写队列溢出
		/// </summary>
		[Description("SDO读写队列溢出")]
		YKE_ERR_SLAVE_SDO_OVER = 0x010b,

		/// <summary>
		/// 访问不存在的从站
		/// </summary>
		[Description("访问不存在的从站")]
		YKE_ERR_SLAVE_INDEX = 0x010c,

		/// <summary>
		/// 从站已经断线
		/// </summary>
		[Description("从站已经断线")]
		YKE_ERR_SLAVE_OFFLINE = 0x010d,

		/// <summary>
		/// 驱动器报警复位失败
		/// </summary>
		[Description("驱动器报警复位失败")]
		YKE_ERR_SLAVE_RST = 0x010e,

		/// <summary>
		/// 驱动器发生报警
		/// </summary>
		[Description("驱动器发生报警")]
		YKE_ERR_SLAVE_DRVW = 0x010f,

		/// <summary>
		/// SDO邮箱状态超时
		/// </summary>
		[Description("SDO邮箱状态超时")]
		YKE_ERR_SLAVE_SM_TIMEOUT = 0x0110,
	};

	/// <summary>
	/// 主站选择
	/// </summary>
	public enum YKE_NODE
	{
		/// <summary>
		/// 主站A
		/// </summary>
		[Description("主站A")]
		YKE_ECAT_A = 0,

		/// <summary>
		/// 主站B
		/// </summary>
		[Description("主站B")]
		YKE_ECAT_B = 1,

		/// <summary>
		/// 主站C
		/// </summary>
		[Description("主站C")]
		YKE_ECAT_C = 2,

		/// <summary>
		/// 主站D
		/// </summary>
		[Description("主站D")]
		YKE_ECAT_D = 3,

		/// <summary>
		/// 节点E
		/// </summary>
		[Description("节点E")]
		YKE_NODE_E = 4,

		/// <summary>
		/// 节点F
		/// </summary>
		[Description("节点F")]
		YKE_NODE_F = 5,

		/// <summary>
		/// 节点G
		/// </summary>
		[Description("节点G")]
		YKE_NODE_G = 6,

		/// <summary>
		/// 节点H
		/// </summary>
		[Description("节点H")]
		YKE_NODE_H = 7,
	};

	/// <summary>
	/// 轴物理层类型
	/// </summary>
	public enum YKE_AXIS_PHY
	{
		/// <summary>
		/// 虚拟轴
		/// </summary>
		[Description("虚拟轴")]
		YKE_AXIS_PHY_VIRTUAL = 0,

		/// <summary>
		/// 总线轴
		/// </summary>
		[Description("总线轴")]
		YKE_AXIS_PHY_ETHERCAT = 1,

		/// <summary>
		/// 脉冲轴
		/// </summary>
		[Description("脉冲轴")]
		YKE_AXIS_PHY_PULSE = 2,
	};

	/// <summary>
	/// 数字IO物理层类型
	/// </summary>
	public enum YKE_DIO_PHY
	{
		/// <summary>
		/// 本地PCI卡
		/// </summary>
		[Description("本地PCI卡")]
		YKE_DIO_PHY_PCI = 0,

		/// <summary>
		/// 总线IO
		/// </summary>
		[Description("总线IO")]
		YKE_DIO_PHY_EBUS_DIO = 1,

		/// <summary>
		/// 网关IO
		/// </summary>
		[Description("网关IO")]
		YKE_DIO_PHY_EBUS_GW = 2,

		/// <summary>
		/// 驱动器IO
		/// </summary>
		[Description("驱动器IO")]
		YKE_DIO_PHY_EBUS_DRV = 3,
	};

	/// <summary>
	/// 停止类型
	/// </summary>
	public enum YKE_AXIS_STOP_TYPE
	{
		/// <summary>
		/// 无
		/// </summary>
		[Description("无")]
		YKE_AXIS_STOP_NONE = 0,

		/// <summary>
		/// 急停
		/// </summary>
		[Description("急停")]
		YKE_AXIS_STOP_EMG = 1,

		/// <summary>
		/// 指令停止
		/// </summary>
		[Description("指令停止")]
		YKE_AXIS_STOP_INS = 2,

		/// <summary>
		/// 硬限位停止
		/// </summary>
		[Description("硬限位停止")]
		YKE_AXIS_STOP_HARD_LIMIT = 3,

		/// <summary>
		/// 软限位停止
		/// </summary>
		[Description("软限位停止")]
		YKE_AXIS_STOP_SOFT_LIMIT = 4,

		/// <summary>
		/// 驱动报警
		/// </summary>
		[Description("驱动报警")]
		YKE_AXIS_STOP_DRIVER = 5,

		/// <summary>
		/// 主轴停止
		/// </summary>
		[Description("主轴停止")]
		YKE_AXIS_STOP_MASTER = 6,

		/// <summary>
		/// 从轴停止
		/// </summary>
		[Description("从轴停止")]
		YKE_AXIS_STOP_SLAVE = 7,

		/// <summary>
		/// 跟随误差过大
		/// </summary>
		[Description("跟随误差过大")]
		YKE_AXIS_STOP_FOLLOW = 8,

		/// <summary>
		/// 触发停止
		/// </summary>
		[Description("触发停止")]
		YKE_AXIS_STOP_TRIGGER = 9,

		/// <summary>
		/// 事件停止
		/// </summary>
		[Description("事件停止")]
		YKE_AXIS_STOP_EVENT = 10,

		/// <summary>
		/// 圆形区域停止
		/// </summary>
		[Description("圆形区域停止")]
		YKE_AXIS_STOP_CIRCLE_ZONE = 11,

		/// <summary>
		/// runtime停止
		/// </summary>
		[Description("runtime停止")]
		YKE_AXIS_STOP_RUNTIME = 20,
	};

	/// <summary>
	/// 轴等待信号类型
	/// </summary>
	public enum YKE_AXIS_WAIT_TYPE
	{
		/// <summary>
		/// 等待轴ACTIVE信号为OFF
		/// </summary>
		[Description("等待轴ACTIVE信号为OFF")]
		YKE_AXIS_WAIT_ACITVE_OFF = 0,

		/// <summary>
		/// 等待轴ACTIVE信号为ON
		/// </summary>
		[Description("等待轴ACTIVE信号为ON")]
		YKE_AXIS_WAIT_ACITVE_ON = 1,
	};

	/// <summary>
	/// 数字输入等待类型
	/// </summary>
	public enum YKE_DIGITAL_INPUT_WAIT_TYPE
	{
		/// <summary>
		/// 数字输入信号为OFF
		/// </summary>
		[Description("数字输入信号为OFF")]
		YKE_DIGITAL_INPUT_WAIT_OFF = 0,

		/// <summary>
		/// 数字输入信号为ON
		/// </summary>
		[Description("数字输入信号为ON")]
		YKE_DIGITAL_INPUT_WAIT_ON = 1,
	};

	/// <summary>
	/// 事件等待类型
	/// </summary>
	public enum YKE_EVENT_WAIT_TYPE
	{
		/// <summary>
		/// 等待事件完成
		/// </summary>
		[Description("等待事件完成")]
		YKE_EVENT_WAIT_FINISH = 0,

		/// <summary>
		/// 等待事件启动
		/// </summary>
		[Description("等待事件启动")]
		YKE_EVENT_WAIT_START = 1,
	};

	/// <summary>
	/// 运动曲线
	/// </summary>
	public enum YKE_CURVE_TYPE
	{
		/// <summary>
		/// S形
		/// </summary>
		[Description("S形")]
		YKE_CURVE_S7 = 0,

		/// <summary>
		/// 梯形
		/// </summary>
		[Description("梯形")]
		YKE_CURVE_T7 = 1,

		/// <summary>
		/// 带平滑的梯形
		/// </summary>
		[Description("带平滑的梯形")]
		YKE_CURVE_TS = 2,

		/// <summary>
		/// 时间定义加速度的梯形曲线
		/// </summary>
		[Description("时间定义加速度的梯形曲线")]
		YKE_CURVE_T7_TIME = 3,

		/// <summary>
		/// 比率定义加速度的S形曲线
		/// </summary>
		[Description("比率定义加速度的S形曲线")]
		YKE_CURVE_S7_RATE = 4,
	};

	/// <summary>
	/// 开关配置
	/// </summary>
	public enum YKE_SWITCH_TYPE
	{
		/// <summary>
		/// 无效配置
		/// </summary>
		[Description("无效配置")]
		YKE_SWITCH_NONE = 0,

		/// <summary>
		/// COE对象字典(总线轴专用)
		/// </summary>
		[Description("COE对象字典(总线轴专用)")]
		YKE_SWITCH_COE_REG = 1,

		/// <summary>
		/// 全局IO序号
		/// </summary>
		[Description("全局IO序号")]
		YKE_SWITCH_GLOBAL_DIO = 2,

		/// <summary>
		/// 本地IO序号(本地脉冲卡专用)
		/// </summary>
		[Description("本地IO序号(本地脉冲卡专用)")]
		YKE_SWITCH_LOCAL_DIO = 3,

		/// <summary>
		/// 机械限位(总线轴专用)
		/// </summary>
		[Description("机械限位(总线轴专用)")]
		YKE_SWITCH_MECHANICAL = 4,
	};

	/// <summary>
	/// 语言选择
	/// </summary>
	public enum YKE_LANGUAGE
	{
		/// <summary>
		/// 中文
		/// </summary>
		[Description("中文")]
		YKE_LNG_CHN = 0,
	};

	/// <summary>
	/// 缓冲模式
	/// </summary>
	public enum YKE_BUFFER_MODE
	{
		/// <summary>
		/// 无效
		/// </summary>
		[Description("无效")]
		YKE_BUFFER_NONE = 0x0000,

		/// <summary>
		/// 缓冲
		/// </summary>
		[Description("缓冲")]
		YKE_BUFFERED = 0x0001,

		/// <summary>
		/// 以低速平滑
		/// </summary>
		[Description("以低速平滑")]
		YKE_BLENDING_LOW = 0x0002,

		/// <summary>
		/// 以前段速平滑
		/// </summary>
		[Description("以前段速平滑")]
		YKE_BLENDING_PREV = 0x0003,

		/// <summary>
		/// 以后段速平滑
		/// </summary>
		[Description("以后段速平滑")]
		YKE_BLENDING_NEXT = 0x0004,

		/// <summary>
		/// 以高速平滑
		/// </summary>
		[Description("以高速平滑")]
		YKE_BLENDING_HIGH = 0x0005,
	};

	/// <summary>
	/// 过渡方式
	/// </summary>
	public enum YKE_TRANSITION_MODE
	{
		/// <summary>
		/// 无过渡
		/// </summary>
		[Description("无过渡")]
		YKE_TRANS_NONE = 0x0000,

		/// <summary>
		/// 拐角距离
		/// </summary>
		[Description("拐角距离")]
		YKE_CORNER_DISTANCE = 0x0003,

		/// <summary>
		/// 最大拐角误差
		/// </summary>
		[Description("最大拐角误差")]
		YKE_MAX_CORNER_DEVIATION = 0x0004,
	};

	/// <summary>
	/// 圆弧辅助点模式
	/// </summary>
	public enum YKE_CIRCULAR_AUX_MODE
	{
		/// <summary>
		/// 指定圆弧上一点
		/// </summary>
		[Description("指定圆弧上一点")]
		YKE_CIRCULAR_BORDER = 0x0000,

		/// <summary>
		/// 指定圆心
		/// </summary>
		[Description("指定圆心")]
		YKE_CIRCULAR_CENTER = 0x0001,
	};

	/// <summary>
	/// 圆弧路径选择
	/// </summary>
	public enum YKE_CIRCULAR_PATH_CHOICE
	{
		/// <summary>
		/// 顺时针,圆心模式使用
		/// </summary>
		[Description("顺时针,圆心模式使用")]
		YKE_CIRCULAR_CLOCKWISE = 0x0000,

		/// <summary>
		/// 逆时针,圆心模式使用
		/// </summary>
		[Description("逆时针,圆心模式使用")]
		YKE_CIRCULAR_COUNTERCLOCKWISE = 0x0001,

		/// <summary>
		/// 辅助点指定,辅助点模式使用
		/// </summary>
		[Description("辅助点指定,辅助点模式使用")]
		YKE_CIRCULAR_DEFINED_BY_AUX_POINT = 0x0002,
	};

	/// <summary>
	/// 运动方向
	/// </summary>
	public enum YKE_DIRECTION
	{
		/// <summary>
		/// 正方向运动
		/// </summary>
		[Description("正方向运动")]
		YKE_DIRECTION_POSITIVE = 0,

		/// <summary>
		/// 负方向运动
		/// </summary>
		[Description("负方向运动")]
		YKE_DIRECTION_NEGATIVE = 1,

		/// <summary>
		/// 禁止使用
		/// </summary>
		[Description("禁止使用")]
		YKE_DIRECTION_NONE = 2,
	};

	/// <summary>
	/// 回原点方式
	/// </summary>
	public enum YKE_HOME_MODE
	{
		/// <summary>
		/// 0:未定义
		/// </summary>
		[Description("0:未定义")]
		YKE_HOME_MODE_00 = 0,

		/// <summary>
		/// 1:离开负限位后,第一个探针标记回原
		/// </summary>
		[Description("1:离开负限位后,第一个探针标记回原")]
		YKE_HOME_MODE_01 = 1,

		/// <summary>
		/// 2:离开正限位后,第一个探针标记回原
		/// </summary>
		[Description("2:离开正限位后,第一个探针标记回原")]
		YKE_HOME_MODE_02 = 2,

		/// <summary>
		/// 3:离开原点开关后,第一个探针标记回原(正向原点开关)
		/// </summary>
		[Description("3:离开原点开关后,第一个探针标记回原(正向原点开关)")]
		YKE_HOME_MODE_03 = 3,

		/// <summary>
		/// 4:接触原点开关后,第一个探针标记回原(正向原点开关)
		/// </summary>
		[Description("4:接触原点开关后,第一个探针标记回原(正向原点开关)")]
		YKE_HOME_MODE_04 = 4,

		/// <summary>
		/// 5:离开原点开关后,第一个探针标记回原(负向原点开关)
		/// </summary>
		[Description("5:离开原点开关后,第一个探针标记回原(负向原点开关)")]
		YKE_HOME_MODE_05 = 5,

		/// <summary>
		/// 6:接触原点开关后,第一个探针标记回原(负向原点开关)
		/// </summary>
		[Description("6:接触原点开关后,第一个探针标记回原(负向原点开关)")]
		YKE_HOME_MODE_06 = 6,

		/// <summary>
		/// 7:离开原点开关的负边沿后,第一个探针标记回原,初始正向运动
		/// </summary>
		[Description("7:离开原点开关的负边沿后,第一个探针标记回原,初始正向运动")]
		YKE_HOME_MODE_07 = 7,

		/// <summary>
		/// 8:接触原点开关的负边沿后,第一个探针标记回原,初始正向运动
		/// </summary>
		[Description("8:接触原点开关的负边沿后,第一个探针标记回原,初始正向运动")]
		YKE_HOME_MODE_08 = 8,

		/// <summary>
		/// 9:接触原点开关的正边沿后,第一个探针标记回原,初始正向运动
		/// </summary>
		[Description("9:接触原点开关的正边沿后,第一个探针标记回原,初始正向运动")]
		YKE_HOME_MODE_09 = 9,

		/// <summary>
		/// 10:离开原点开关的正边沿后,第一个探针标记回原,初始正向运动
		/// </summary>
		[Description("10:离开原点开关的正边沿后,第一个探针标记回原,初始正向运动")]
		YKE_HOME_MODE_10 = 10,

		/// <summary>
		/// 11:离开原点开关的正边沿后,第一个探针标记回原,初始负向运动
		/// </summary>
		[Description("11:离开原点开关的正边沿后,第一个探针标记回原,初始负向运动")]
		YKE_HOME_MODE_11 = 11,

		/// <summary>
		/// 12:接触原点开关的正边沿后,第一个探针标记回原,初始负向运动
		/// </summary>
		[Description("12:接触原点开关的正边沿后,第一个探针标记回原,初始负向运动")]
		YKE_HOME_MODE_12 = 12,

		/// <summary>
		/// 13:接触原点开关的负边沿后,第一个探针标记回原,初始负向运动
		/// </summary>
		[Description("13:接触原点开关的负边沿后,第一个探针标记回原,初始负向运动")]
		YKE_HOME_MODE_13 = 13,

		/// <summary>
		/// 14:离开原点开关的负边沿后,第一个探针标记回原,初始负向运动
		/// </summary>
		[Description("14:离开原点开关的负边沿后,第一个探针标记回原,初始负向运动")]
		YKE_HOME_MODE_14 = 14,

		/// <summary>
		/// 15:未实现
		/// </summary>
		[Description("15:未实现")]
		YKE_HOME_MODE_15 = 15,

		/// <summary>
		/// 16:未实现
		/// </summary>
		[Description("16:未实现")]
		YKE_HOME_MODE_16 = 16,

		/// <summary>
		/// 17:负限位下降沿
		/// </summary>
		[Description("17:负限位下降沿")]
		YKE_HOME_MODE_17 = 17,

		/// <summary>
		/// 18:正限位下降沿
		/// </summary>
		[Description("18:正限位下降沿")]
		YKE_HOME_MODE_18 = 18,

		/// <summary>
		/// 19:原点开关下降沿回原(正向原点开关)
		/// </summary>
		[Description("19:原点开关下降沿回原(正向原点开关)")]
		YKE_HOME_MODE_19 = 19,

		/// <summary>
		/// 20:原点开关上升沿回原(正向原点开关)
		/// </summary>
		[Description("20:原点开关上升沿回原(正向原点开关)")]
		YKE_HOME_MODE_20 = 20,

		/// <summary>
		/// 21:原点开关下降沿回原(负向原点开关)
		/// </summary>
		[Description("21:原点开关下降沿回原(负向原点开关)")]
		YKE_HOME_MODE_21 = 21,

		/// <summary>
		/// 22:原点开关上升沿回原(负向原点开关)
		/// </summary>
		[Description("22:原点开关上升沿回原(负向原点开关)")]
		YKE_HOME_MODE_22 = 22,

		/// <summary>
		/// 23:原点开关负边下降沿回原,初始正向运动
		/// </summary>
		[Description("23:原点开关负边下降沿回原,初始正向运动")]
		YKE_HOME_MODE_23 = 23,

		/// <summary>
		/// 24:原点开关负边上升沿回原,初始正向运动
		/// </summary>
		[Description("24:原点开关负边上升沿回原,初始正向运动")]
		YKE_HOME_MODE_24 = 24,

		/// <summary>
		/// 25:原点开关正边上升沿回原,初始正向运动
		/// </summary>
		[Description("25:原点开关正边上升沿回原,初始正向运动")]
		YKE_HOME_MODE_25 = 25,

		/// <summary>
		/// 26:原点开关正边下降沿回原,初始正向运动
		/// </summary>
		[Description("26:原点开关正边下降沿回原,初始正向运动")]
		YKE_HOME_MODE_26 = 26,

		/// <summary>
		/// 27:原点开关正边下降沿回原,初始负向运动
		/// </summary>
		[Description("27:原点开关正边下降沿回原,初始负向运动")]
		YKE_HOME_MODE_27 = 27,

		/// <summary>
		/// 28:原点开关正边上升沿回原,初始负向运动
		/// </summary>
		[Description("28:原点开关正边上升沿回原,初始负向运动")]
		YKE_HOME_MODE_28 = 28,

		/// <summary>
		/// 29:原点开关负边上升沿回原,初始负向运动
		/// </summary>
		[Description("29:原点开关负边上升沿回原,初始负向运动")]
		YKE_HOME_MODE_29 = 29,

		/// <summary>
		/// 30:原点开关负边下降沿回原,初始负向运动
		/// </summary>
		[Description("30:原点开关负边下降沿回原,初始负向运动")]
		YKE_HOME_MODE_30 = 30,

		/// <summary>
		/// 31:未实现
		/// </summary>
		[Description("31:未实现")]
		YKE_HOME_MODE_31 = 31,

		/// <summary>
		/// 32:未实现
		/// </summary>
		[Description("32:未实现")]
		YKE_HOME_MODE_32 = 32,

		/// <summary>
		/// 33:负向找探针
		/// </summary>
		[Description("33:负向找探针")]
		YKE_HOME_MODE_33 = 33,

		/// <summary>
		/// 34:正向找探针
		/// </summary>
		[Description("34:正向找探针")]
		YKE_HOME_MODE_34 = 34,

		/// <summary>
		/// 35:当前位置为原点
		/// </summary>
		[Description("35:当前位置为原点")]
		YKE_HOME_MODE_35 = 35,

		/// <summary>
		/// 36:未实现
		/// </summary>
		[Description("36:未实现")]
		YKE_HOME_MODE_36 = 36,

		/// <summary>
		/// 37:当前位置为原点
		/// </summary>
		[Description("37:当前位置为原点")]
		YKE_HOME_MODE_37 = 37,

		/// <summary>
		/// 38:绝对编码器回原
		/// </summary>
		[Description("38:绝对编码器回原")]
		YKE_HOME_MODE_ABS = 38,
	};

	/// <summary>
	/// 轴停止命令减速度选择
	/// </summary>
	public enum YKE_STOP_DEC
	{
		/// <summary>
		/// 使用YKS_AxisProfileBase.stop_dec_smooth参数
		/// </summary>
		[Description("使用YKS_AxisProfileBase.stop_dec_smooth参数")]
		YKE_STOP_SEL_SMOOTH = 0,

		/// <summary>
		/// 使用YKS_AxisProfileBase.stop_dec_emg参数
		/// </summary>
		[Description("使用YKS_AxisProfileBase.stop_dec_emg参数")]
		YKE_STOP_SEL_EMG = 1,

		/// <summary>
		/// 使用指令减速度
		/// </summary>
		[Description("使用指令减速度")]
		YKE_STOP_SEL_INS = 2,
	};

	/// <summary>
	/// 编码器模式
	/// </summary>
	public enum YKE_ENCODER_MODE
	{
		/// <summary>
		/// 脉冲+方向
		/// </summary>
		[Description("脉冲+方向")]
		YKE_ENCODER_MODE_PD = 0,

		/// <summary>
		/// 正反脉冲
		/// </summary>
		[Description("正反脉冲")]
		YKE_ENCODER_MODE_PN = 1,

		/// <summary>
		/// 正交模式
		/// </summary>
		[Description("正交模式")]
		YKE_ENCODER_MODE_AB4 = 2,
	};

	/// <summary>
	/// 比较器模式
	/// </summary>
	public enum YKE_COMPARE_MODE
	{
		/// <summary>
		/// 固定位置
		/// </summary>
		[Description("固定位置")]
		YKE_COMPARE_MODE_FIX = 0,

		/// <summary>
		/// 线性模式
		/// </summary>
		[Description("线性模式")]
		YKE_COMPARE_MODE_LINE = 1,

		/// <summary>
		/// 先进先出
		/// </summary>
		[Description("先进先出")]
		YKE_COMPARE_MODE_FIFO = 2,
	};

	/// <summary>
	/// 输入信号触发模式
	/// </summary>
	public enum YKE_TRIG_MODE
	{
		/// <summary>
		/// 上升沿
		/// </summary>
		[Description("上升沿")]
		YKE_TRIG_MODE_UPEDGE = 0,

		/// <summary>
		/// 下降沿
		/// </summary>
		[Description("下降沿")]
		YKE_TRIG_MODE_DOWNEDGE = 1,

		/// <summary>
		/// 高电平
		/// </summary>
		[Description("高电平")]
		YKE_TRIG_MODE_HGIHLEVEL = 2,

		/// <summary>
		/// 低电平
		/// </summary>
		[Description("低电平")]
		YKE_TRIG_MODE_LOWLEVEL = 3,

		/// <summary>
		/// 沿变化
		/// </summary>
		[Description("沿变化")]
		YKE_TRIG_MODE_EDGE = 4,
	};

	/// <summary>
	/// 示波器触发模式
	/// </summary>
	public enum YKE_OSC_TRIG_TYPE
	{
		/// <summary>
		/// 自由运行
		/// </summary>
		[Description("自由运行")]
		YKE_OSC_TRIG_FREE = 0,

		/// <summary>
		/// 手动触发
		/// </summary>
		[Description("手动触发")]
		YKE_OSC_TRIG_MANUAL = 1,

		/// <summary>
		/// 上升沿
		/// </summary>
		[Description("上升沿")]
		YKE_OSC_TRIG_UPEDGE = 2,

		/// <summary>
		/// 下降沿
		/// </summary>
		[Description("下降沿")]
		YKE_OSC_TRIG_DOWNEDGE = 3,

		/// <summary>
		/// 高电平
		/// </summary>
		[Description("高电平")]
		YKE_OSC_TRIG_HIGHLEVEL = 4,

		/// <summary>
		/// 低电平
		/// </summary>
		[Description("低电平")]
		YKE_OSC_TRIG_LOWLEVEL = 5,

		/// <summary>
		/// 沿变化
		/// </summary>
		[Description("沿变化")]
		YKE_OSC_TRIG_UPDOWN = 6,
	};

	/// <summary>
	/// 示波器监控对象类型
	/// </summary>
	public enum YKE_OSC_ITEM_TYPE
	{
		/// <summary>
		/// 轴数据
		/// </summary>
		[Description("轴数据")]
		YKE_OSC_ITEM_AXIS = 0,

		/// <summary>
		/// 对象字典,适用总线驱动器
		/// </summary>
		[Description("对象字典,适用总线驱动器")]
		YKE_OSC_ITEM_OD = 1,

		/// <summary>
		/// UG寄存器,适用总线驱动器
		/// </summary>
		[Description("UG寄存器,适用总线驱动器")]
		YKE_OSC_ITEM_UG = 2,

		/// <summary>
		/// 数字输入
		/// </summary>
		[Description("数字输入")]
		YKE_OSC_ITEM_DI = 3,

		/// <summary>
		/// 数字输出
		/// </summary>
		[Description("数字输出")]
		YKE_OSC_ITEM_DO = 4,

		/// <summary>
		/// 通用数据寄存器
		/// </summary>
		[Description("通用数据寄存器")]
		YKE_OSC_ITEM_DATA_REG = 5,

		/// <summary>
		/// 系统信息
		/// </summary>
		[Description("系统信息")]
		YKE_OSC_ITEM_SYS = 6,

		/// <summary>
		/// 坐标系信息
		/// </summary>
		[Description("坐标系信息")]
		YKE_OSC_ITEM_GROUP = 7,

		/// <summary>
		/// 本地编码器
		/// </summary>
		[Description("本地编码器")]
		YKE_OSC_ITEM_ENCODER = 8,

		/// <summary>
		/// 事件
		/// </summary>
		[Description("事件")]
		YKE_OSC_ITEM_EVENT = 9,

		/// <summary>
		/// 多轴联动
		/// </summary>
		[Description("多轴联动")]
		YKE_OSC_ITEM_MULTI_AXIS = 10,

		/// <summary>
		/// 等待事件
		/// </summary>
		[Description("等待事件")]
		YKE_OSC_ITEM_WAIT = 11,
	};

	/// <summary>
	/// 轴信息采样数据类型
	/// </summary>
	public enum YKE_AXIS_ITEM_TYPE
	{
		/// <summary>
		/// 规划速度
		/// </summary>
		[Description("规划速度")]
		YKE_AXIS_ITEM_CMD_VEL = 0,

		/// <summary>
		/// 实际速度
		/// </summary>
		[Description("实际速度")]
		YKE_AXIS_ITEM_ACT_VEL = 1,

		/// <summary>
		/// 规划位置
		/// </summary>
		[Description("规划位置")]
		YKE_AXIS_ITEM_CMD_POS = 2,

		/// <summary>
		/// 实际位置
		/// </summary>
		[Description("实际位置")]
		YKE_AXIS_ITEM_ACT_POS = 3,

		/// <summary>
		/// 给定转矩
		/// </summary>
		[Description("给定转矩")]
		YKE_AXIS_ITEM_CMD_TQ = 4,

		/// <summary>
		/// 实际转矩
		/// </summary>
		[Description("实际转矩")]
		YKE_AXIS_ITEM_ACT_TQ = 5,

		/// <summary>
		/// 规划加速度
		/// </summary>
		[Description("规划加速度")]
		YKE_AXIS_ITEM_CMD_ACC = 6,

		/// <summary>
		/// 规划变加速度
		/// </summary>
		[Description("规划变加速度")]
		YKE_AXIS_ITEM_CMD_JERK = 7,

		/// <summary>
		/// 目标位置
		/// </summary>
		[Description("目标位置")]
		YKE_AXIS_ITEM_TARGET_POS = 11,

		/// <summary>
		/// 控制模式
		/// </summary>
		[Description("控制模式")]
		YKE_AXIS_ITEM_COE_MODE = 12,

		/// <summary>
		/// 编码器值
		/// </summary>
		[Description("编码器值")]
		YKE_AXIS_ITEM_ENCODER = 13,

		/// <summary>
		/// 轴报警信号
		/// </summary>
		[Description("轴报警信号")]
		YKE_AXIS_ITEM_WARN_ID = 14,

		/// <summary>
		/// 螺距补偿量
		/// </summary>
		[Description("螺距补偿量")]
		YKE_AXIS_ITEM_PITCH = 15,

		/// <summary>
		/// 反向间隙补偿量
		/// </summary>
		[Description("反向间隙补偿量")]
		YKE_AXIS_ITEM_BACKLASH = 16,

		/// <summary>
		/// 规划完成信号
		/// </summary>
		[Description("规划完成信号")]
		YKE_AXIS_ITEM_CMD_DONE = 20,

		/// <summary>
		/// Active信号(UINT32)
		/// </summary>
		[Description("Active信号(UINT32)")]
		YKE_AXIS_ITEM_ACTIVE1 = 21,

		/// <summary>
		/// Active信号(BOOL)
		/// </summary>
		[Description("Active信号(BOOL)")]
		YKE_AXIS_ITEM_ACTIVE2 = 22,

		/// <summary>
		/// Done信号
		/// </summary>
		[Description("Done信号")]
		YKE_AXIS_ITEM_DONE = 23,

		/// <summary>
		/// 驱动器Ready
		/// </summary>
		[Description("驱动器Ready")]
		YKE_AXIS_ITEM_POWER_ON = 24,

		/// <summary>
		/// 变参数标记
		/// </summary>
		[Description("变参数标记")]
		YKE_AXIS_ITEM_CHANGE = 25,

		/// <summary>
		/// 剩余规划时间
		/// </summary>
		[Description("剩余规划时间")]
		YKE_AXIS_ITEM_REMAIN_TIM = 30,

		/// <summary>
		/// 规划总时间
		/// </summary>
		[Description("规划总时间")]
		YKE_AXIS_ITEM_TOTAL_TIM = 31,

		/// <summary>
		/// 已运行时间
		/// </summary>
		[Description("已运行时间")]
		YKE_AXIS_ITEM_COMPLETE_TIM = 32,

		/// <summary>
		/// 位置跟随误差(滤波前)
		/// </summary>
		[Description("位置跟随误差(滤波前)")]
		YKE_AXIS_ITEM_POS_LAG = 40,

		/// <summary>
		/// 位置跟随误差(滤波后)
		/// </summary>
		[Description("位置跟随误差(滤波后)")]
		YKE_AXIS_ITEM_POS_LAG_FILTER = 41,

		/// <summary>
		/// 和主轴的规划位置偏差
		/// </summary>
		[Description("和主轴的规划位置偏差")]
		YKE_AXIS_ITEM_GANTRY_CMDERR = 42,

		/// <summary>
		/// 和主轴的实际位置偏差
		/// </summary>
		[Description("和主轴的实际位置偏差")]
		YKE_AXIS_ITEM_GANTRY_ACTERR = 43,

		/// <summary>
		/// 硬件原点开关
		/// </summary>
		[Description("硬件原点开关")]
		YKE_AXIS_ITEM_HOME = 50,

		/// <summary>
		/// 硬件正限位
		/// </summary>
		[Description("硬件正限位")]
		YKE_AXIS_ITEM_HD_POSITIVE = 51,

		/// <summary>
		/// 硬件负限位
		/// </summary>
		[Description("硬件负限位")]
		YKE_AXIS_ITEM_HD_NEGATIVE = 52,

		/// <summary>
		/// 软件正限位
		/// </summary>
		[Description("软件正限位")]
		YKE_AXIS_ITEM_SOFT_POSITIVE = 53,

		/// <summary>
		/// 软件负限位
		/// </summary>
		[Description("软件负限位")]
		YKE_AXIS_ITEM_SOFT_NEGATIVE = 54,

		/// <summary>
		/// 反馈到位1
		/// </summary>
		[Description("反馈到位1")]
		YKE_AXIS_ITEM_INPOS1 = 60,

		/// <summary>
		/// 反馈到位2
		/// </summary>
		[Description("反馈到位2")]
		YKE_AXIS_ITEM_INPOS2 = 61,

		/// <summary>
		/// 反馈到位3
		/// </summary>
		[Description("反馈到位3")]
		YKE_AXIS_ITEM_INPOS3 = 62,

		/// <summary>
		/// 反馈到位4
		/// </summary>
		[Description("反馈到位4")]
		YKE_AXIS_ITEM_INPOS4 = 63,

		/// <summary>
		/// 反馈到位5
		/// </summary>
		[Description("反馈到位5")]
		YKE_AXIS_ITEM_INPOS5 = 64,

		/// <summary>
		/// 反馈到位6
		/// </summary>
		[Description("反馈到位6")]
		YKE_AXIS_ITEM_INPOS6 = 65,

		/// <summary>
		/// 用户测试值
		/// </summary>
		[Description("用户测试值")]
		YKE_AXIS_ITEM_USER_TEST = 100,
	};

	/// <summary>
	/// 事件数据类型
	/// </summary>
	public enum YKE_EVENT_ITEM_TYPE
	{
		/// <summary>
		/// 启动命令
		/// </summary>
		[Description("启动命令")]
		YKE_EVENT_ITEM_START = 0,

		/// <summary>
		/// 事件状态
		/// </summary>
		[Description("事件状态")]
		YKE_EVENT_ITEM_STATUS = 1,
	};

	/// <summary>
	/// 多轴联动数据采集类型
	/// </summary>
	public enum YKE_MULTI_AXIS_ITEM_TYPE
	{
		/// <summary>
		/// active信号
		/// </summary>
		[Description("active信号")]
		YKE_MULTI_AXIS_ITEM_ACTIVE = 0,

		/// <summary>
		/// done信号
		/// </summary>
		[Description("done信号")]
		YKE_MULTI_AXIS_ITEM_DONE = 1,

		/// <summary>
		/// 剩余的规划时间
		/// </summary>
		[Description("剩余的规划时间")]
		YKE_MULTI_AXIS_ITEM_REMAIN_TIM = 10,

		/// <summary>
		/// 规划总时间
		/// </summary>
		[Description("规划总时间")]
		YKE_MULTI_AXIS_ITEM_TOTAL_TIM = 11,

		/// <summary>
		/// 加速度
		/// </summary>
		[Description("加速度")]
		YKE_MULTI_AXIS_ITEM_ACCELERATION = 21,
	};

	/// <summary>
	/// 等待事件数据采集类型
	/// </summary>
	public enum YKE_WAIT_ITEM_TYPE
	{
		/// <summary>
		/// active信号
		/// </summary>
		[Description("active信号")]
		YKE_WAIT_ITEM_ACTIVE = 0,
	};

	/// <summary>
	/// 轴跟随信息
	/// </summary>
	public enum YKE_AXIS_FOLLOW_TYPE
	{
		/// <summary>
		/// 规划位置
		/// </summary>
		[Description("规划位置")]
		YKE_AXIS_FOLLOW_CMD_POS = 0,

		/// <summary>
		/// 实际位置
		/// </summary>
		[Description("实际位置")]
		YKE_AXIS_FOLLOW_ACT_POS = 1,
	};

	/// <summary>
	/// 轴位置比较模式
	/// </summary>
	public enum YKE_AXIS_COMPARE_TYPE
	{
		/// <summary>
		/// 规划位置
		/// </summary>
		[Description("规划位置")]
		YKE_AXIS_COMPARE_CMD_POS = 0,

		/// <summary>
		/// 实际位置
		/// </summary>
		[Description("实际位置")]
		YKE_AXIS_COMPARE_ACT_POS = 1,
	};

	/// <summary>
	/// 坐标系跟随信息
	/// </summary>
	public enum YKE_FOLLOW_GROUP_TYPE
	{
		/// <summary>
		/// XY已移动距离
		/// </summary>
		[Description("XY已移动距离")]
		YKE_FOLLOW_GROUP_DIST_2D = 10,

		/// <summary>
		/// XYZ已移动距离
		/// </summary>
		[Description("XYZ已移动距离")]
		YKE_FOLLOW_GROUP_DIST_3D = 11,
	};

	/// <summary>
	/// 系统信息采样数据类型
	/// </summary>
	public enum YKE_SYSTEM_ITEM_TYPE
	{
		/// <summary>
		/// 运动周期抖动ms
		/// </summary>
		[Description("运动周期抖动ms")]
		YKE_SYS_ITEM_MOTICK = 0,

		/// <summary>
		/// 当前同步抖动ms
		/// </summary>
		[Description("当前同步抖动ms")]
		YKE_SYS_ITEM_DC_JITTER = 1,

		/// <summary>
		/// 厂家调试0
		/// </summary>
		[Description("厂家调试0")]
		YKE_SYS_ITEM_DC_ADJUST = 2,

		/// <summary>
		/// CPU频率
		/// </summary>
		[Description("CPU频率")]
		YKE_SYS_ITEM_CPU_FREQ = 3,

		/// <summary>
		/// YKGROUP负率ms
		/// </summary>
		[Description("YKGROUP负率ms")]
		YKE_SYS_ITEM_PAYLOAD_YKG = 4,

		/// <summary>
		/// NTF负载ms
		/// </summary>
		[Description("NTF负载ms")]
		YKE_SYS_ITEM_PAYLOAD_NTF = 5,

		/// <summary>
		/// CNC负载ms
		/// </summary>
		[Description("CNC负载ms")]
		YKE_SYS_ITEM_PAYLOAD_CNC = 6,

		/// <summary>
		/// 总负载ms
		/// </summary>
		[Description("总负载ms")]
		YKE_SYS_ITEM_PAYLOAD_ALL = 7,

		/// <summary>
		/// 厂家调试1
		/// </summary>
		[Description("厂家调试1")]
		YKE_SYS_ITEM_TEST1 = 31,

		/// <summary>
		/// 厂家调试2
		/// </summary>
		[Description("厂家调试2")]
		YKE_SYS_ITEM_TEST2 = 32,

		/// <summary>
		/// 厂家调试3
		/// </summary>
		[Description("厂家调试3")]
		YKE_SYS_ITEM_TEST3 = 33,

		/// <summary>
		/// 厂家调试4
		/// </summary>
		[Description("厂家调试4")]
		YKE_SYS_ITEM_TEST4 = 34,

		/// <summary>
		/// 厂家调试5
		/// </summary>
		[Description("厂家调试5")]
		YKE_SYS_ITEM_TEST5 = 35,
	};

	/// <summary>
	/// 设置驱动器控制模式,总线轴专用
	/// </summary>
	public enum YKE_DRV_OP_MODE
	{
		/// <summary>
		/// 无效选项
		/// </summary>
		[Description("无效选项")]
		YKE_DRV_OP_MODE_NONE = 0,

		/// <summary>
		/// 轮廓位置模式(PP)
		/// </summary>
		[Description("轮廓位置模式(PP)")]
		YKE_DRV_OP_MODE_PP = 1,

		/// <summary>
		/// 轮廓速度模式(PV)
		/// </summary>
		[Description("轮廓速度模式(PV)")]
		YKE_DRV_OP_MODE_PV = 3,

		/// <summary>
		/// 转矩模式(TQ)
		/// </summary>
		[Description("转矩模式(TQ)")]
		YKE_DRV_OP_MODE_TQ = 4,

		/// <summary>
		/// 回原模式(HM)
		/// </summary>
		[Description("回原模式(HM)")]
		YKE_DRV_OP_MODE_HM = 6,

		/// <summary>
		/// 周期位置模式(CSP)
		/// </summary>
		[Description("周期位置模式(CSP)")]
		YKE_DRV_OP_MODE_CSP = 8,

		/// <summary>
		/// 周期速度模式(CSV)
		/// </summary>
		[Description("周期速度模式(CSV)")]
		YKE_DRV_OP_MODE_CSV = 9,

		/// <summary>
		/// 周期转矩模式(CST)
		/// </summary>
		[Description("周期转矩模式(CST)")]
		YKE_DRV_OP_MODE_CST = 10,
	};

	/// <summary>
	/// 跟随方式
	/// </summary>
	public enum YKE_AXIS_FOLLOW_MODE
	{
		/// <summary>
		/// 比例跟随
		/// </summary>
		[Description("比例跟随")]
		YKE_AXIS_FOLLOW_SCALE = 0,

		/// <summary>
		/// 加减速跟随
		/// </summary>
		[Description("加减速跟随")]
		YKE_AXIS_FOLLOW_ACC = 1,
	};

	/// <summary>
	/// 传送带同步状态
	/// </summary>
	public enum YKE_CONVEYOR_SYNC_STATUS
	{
		/// <summary>
		/// 同步中
		/// </summary>
		[Description("同步中")]
		YKE_CONVEYOR_SYNC_SYNC_ACTIVE = 0,

		/// <summary>
		/// 同步失败
		/// </summary>
		[Description("同步失败")]
		YKE_CONVEYOR_SYNC_FAIL = 1,

		/// <summary>
		/// 同步完成
		/// </summary>
		[Description("同步完成")]
		YKE_CONVEYOR_SYNC_DONE = 2,
	};

	/// <summary>
	/// 脉冲模式
	/// </summary>
	public enum YKE_PULSE_MODE
	{
		/// <summary>
		/// 脉冲+方向
		/// </summary>
		[Description("脉冲+方向")]
		YKE_PULSE_DIR = 0,

		/// <summary>
		/// 正反向脉冲
		/// </summary>
		[Description("正反向脉冲")]
		YKE_PULSE_PN = 1,
	};

	/// <summary>
	/// 捕获源
	/// </summary>
	public enum YKE_CAPTURE_SOURCE
	{
		/// <summary>
		/// 捕获编码器
		/// </summary>
		[Description("捕获编码器")]
		YKE_CAPTURE_ENCODER = 0,

		/// <summary>
		/// 捕获规划脉冲
		/// </summary>
		[Description("捕获规划脉冲")]
		YKE_CAPTURE_CMD_PULSE = 1,
	};

	/// <summary>
	/// 凸轮曲线
	/// </summary>
	public enum YKE_CAM_CURVE
	{
		/// <summary>
		/// 多项式
		/// </summary>
		[Description("多项式")]
		YKE_CAM_CURVE_POLY = 0,

		/// <summary>
		/// 样条
		/// </summary>
		[Description("样条")]
		YKE_CAM_CURVE_SPLINE = 1,
	};

	/// <summary>
	/// 双轴混合模式
	/// </summary>
	public enum YKE_COMBINE_MODE
	{
		/// <summary>
		/// 加法
		/// </summary>
		[Description("加法")]
		YKE_COMBINE_ADD = 0,

		/// <summary>
		/// 减法
		/// </summary>
		[Description("减法")]
		YKE_COMBINE_SUB = 1,

		/// <summary>
		/// 合成距离
		/// </summary>
		[Description("合成距离")]
		YKE_COMBINE_DIST = 10,
	};

	/// <summary>
	/// 总线从站配置操作内容
	/// </summary>
	public enum YKE_SLAVE_ITEM
	{
		/// <summary>
		/// 站点移除(总线上未连实物)  值定义 0=不移除 非0=移除
		/// </summary>
		[Description("站点移除(总线上未连实物)  值定义 0=不移除 非0=移除")]
		YKE_SLAVE_ITEM_REMOVE = 1,

		/// <summary>
		/// 站点启用(总线上有实物并通电) 值定义0=禁用 非0=启用
		/// </summary>
		[Description("站点启用(总线上有实物并通电) 值定义0=禁用 非0=启用")]
		YKE_SLAVE_ITEM_ENABLE = 2,
	};

	/// <summary>
	/// 数据类型
	/// </summary>
	public enum YKE_DATA_TYPE
	{
		/// <summary>
		/// 8位有符号
		/// </summary>
		[Description("8位有符号")]
		YKE_INT8 = 0,

		/// <summary>
		/// 8位无符号
		/// </summary>
		[Description("8位无符号")]
		YKE_UINT8 = 1,

		/// <summary>
		/// 16位有符号
		/// </summary>
		[Description("16位有符号")]
		YKE_INT16 = 2,

		/// <summary>
		/// 16位无符号
		/// </summary>
		[Description("16位无符号")]
		YKE_UINT16 = 3,

		/// <summary>
		/// 32位有符号
		/// </summary>
		[Description("32位有符号")]
		YKE_INT32 = 4,

		/// <summary>
		/// 32位无符号
		/// </summary>
		[Description("32位无符号")]
		YKE_UINT32 = 5,
	};

	/// <summary>
	/// 布尔数据
	/// </summary>
	public enum YKE_BOOL
	{
		/// <summary>
		/// 否
		/// </summary>
		[Description("否")]
		YKE_FALSE = 0,

		/// <summary>
		/// 是
		/// </summary>
		[Description("是")]
		YKE_TRUE = 1,
	};

	/// <summary>
	/// 运动模式
	/// </summary>
	public enum YKE_MOTION_TYPE
	{
		/// <summary>
		/// 无效
		/// </summary>
		[Description("无效")]
		YKE_MOTION_NONE = 0,

		/// <summary>
		/// 位置运动
		/// </summary>
		[Description("位置运动")]
		YKE_MOTION_POSITION = 1,

		/// <summary>
		/// 速度运动
		/// </summary>
		[Description("速度运动")]
		YKE_MOTION_VELOCITY = 2,

		/// <summary>
		/// 转矩
		/// </summary>
		[Description("转矩")]
		YKE_MOTION_TORQUE = 3,

		/// <summary>
		/// 回原
		/// </summary>
		[Description("回原")]
		YKE_MOTION_HOME = 4,

		/// <summary>
		/// 软跟随
		/// </summary>
		[Description("软跟随")]
		YKE_MOTION_SOFT_FOLLOW = 5,

		/// <summary>
		/// 硬跟随
		/// </summary>
		[Description("硬跟随")]
		YKE_MOTION_HARD_FOLLOW = 6,

		/// <summary>
		/// 坐标系
		/// </summary>
		[Description("坐标系")]
		YKE_MOTION_GROUP = 7,

		/// <summary>
		/// 多轴联动
		/// </summary>
		[Description("多轴联动")]
		YKE_MOTION_MULTI_AXIS = 8,

		/// <summary>
		/// PVT
		/// </summary>
		[Description("PVT")]
		YKE_MOTION_PVT = 9,
	};

	/// <summary>
	/// 连接错误类型
	/// </summary>
	public enum YKE_LINK_ERROR
	{
		/// <summary>
		/// 无错误
		/// </summary>
		[Description("无错误")]
		YKE_ERR_LINK_NONE = 0,

		/// <summary>
		/// 有帧未处理
		/// </summary>
		[Description("有帧未处理")]
		YKE_ERR_LINK_WKC = 1,

		/// <summary>
		/// 帧发送失败
		/// </summary>
		[Description("帧发送失败")]
		YKE_ERR_LINK_SEND = 2,

		/// <summary>
		/// 帧接收失败
		/// </summary>
		[Description("帧接收失败")]
		YKE_ERR_LINK_REV = 3,

		/// <summary>
		/// 读AL寄存器出错
		/// </summary>
		[Description("读AL寄存器出错")]
		YKE_ERR_LINK_READREG = 4,

		/// <summary>
		/// 发送数据帧超过了1480字节
		/// </summary>
		[Description("发送数据帧超过了1480字节")]
		YKE_ERR_LINK_SEND_SIZE = 13,

		/// <summary>
		/// 发送队列超过了32个
		/// </summary>
		[Description("发送队列超过了32个")]
		YKE_ERR_LINK_SEND_QUENE = 14,

		/// <summary>
		/// 接收数据失败
		/// </summary>
		[Description("接收数据失败")]
		YKE_ERR_LINK_REV_QUENE = 15,

		/// <summary>
		/// 接收缓冲区分配失败
		/// </summary>
		[Description("接收缓冲区分配失败")]
		YKE_ERR_LINK_ALLOC_REV = 22,

		/// <summary>
		/// 发送缓冲区分配失败
		/// </summary>
		[Description("发送缓冲区分配失败")]
		YKE_ERR_LINK_ALLOC_SEND = 23,

		/// <summary>
		/// DC同步调整量过大
		/// </summary>
		[Description("DC同步调整量过大")]
		YKE_ERR_LINK_DC_ADJUST = 27,

		/// <summary>
		/// 环网冗余已断开
		/// </summary>
		[Description("环网冗余已断开")]
		YKE_ERR_LINK_REDUNDANCY = 31,
	};

	/// <summary>
	/// 总线状态
	/// </summary>
	public enum YKE_BUS_STATUS
	{
		/// <summary>
		/// 无总线活动
		/// </summary>
		[Description("无总线活动")]
		YKE_BUS_STATUS_IDEL = 0,

		/// <summary>
		/// 初始化中
		/// </summary>
		[Description("初始化中")]
		YKE_BUS_STATUS_INITING = 1,

		/// <summary>
		/// 初始化发生错误
		/// </summary>
		[Description("初始化发生错误")]
		YKE_BUS_STATUS_ERR = 2,

		/// <summary>
		/// 完全运行中
		/// </summary>
		[Description("完全运行中")]
		YKE_BUS_STATUS_RUNNING = 10,
	};

	/// <summary>
	/// 同步运动模式
	/// </summary>
	public enum YKE_SYNC_AXIS_MODE
	{
		/// <summary>
		/// 按轴最大限制运行
		/// </summary>
		[Description("按轴最大限制运行")]
		YKE_SYNC_AXIS_LIMIT = 0,

		/// <summary>
		/// 以最慢的轴做参考同时到达
		/// </summary>
		[Description("以最慢的轴做参考同时到达")]
		YKE_SYNC_AXIS_SLOWEST = 1,

		/// <summary>
		/// 以最远的轴做参考同时到达
		/// </summary>
		[Description("以最远的轴做参考同时到达")]
		YKE_SYNC_AXIS_FARTHESET = 2,

		/// <summary>
		/// 以指定时间运行
		/// </summary>
		[Description("以指定时间运行")]
		YKE_SYNC_FIX_TIME = 3,
	};

	/// <summary>
	/// 坐标系报警后输出状态
	/// </summary>
	public enum YKE_GROUP_OUTPUT_IN_WARN
	{
		/// <summary>
		/// 保持当前状态
		/// </summary>
		[Description("保持当前状态")]
		YKE_GROUP_OUTPUT_IN_WARN_KEEP = 0,

		/// <summary>
		/// 置位
		/// </summary>
		[Description("置位")]
		YKE_GROUP_OUTPUT_IN_WARN_HIGH = 1,

		/// <summary>
		/// 复位
		/// </summary>
		[Description("复位")]
		YKE_GROUP_OUTPUT_IN_WARN_LOW = 2,
	};

	/// <summary>
	/// 急停信号有效后给轴的控制命令
	/// </summary>
	public enum YKE_EMG_AXIS_BEGAVIOR
	{
		/// <summary>
		/// 保持
		/// </summary>
		[Description("保持")]
		YKE_EMG_AXIS_KEEP = 0,

		/// <summary>
		/// 停止
		/// </summary>
		[Description("停止")]
		YKE_EMG_AXIS_STOP = 1,

		/// <summary>
		/// 停止并下使能
		/// </summary>
		[Description("停止并下使能")]
		YKE_EMG_AXIS_POWEROFF = 2,
	};

	/// <summary>
	/// 坐标系采样数据类型
	/// </summary>
	public enum YKE_GROUP_ITEM_TYPE
	{
		/// <summary>
		/// 忙信号
		/// </summary>
		[Description("忙信号")]
		YKE_GROUP_ITEM_ACTIVE = 0,

		/// <summary>
		/// 完成信号
		/// </summary>
		[Description("完成信号")]
		YKE_GROUP_ITEM_DONE = 1,

		/// <summary>
		/// 当前运动行 从1开始
		/// </summary>
		[Description("当前运动行 从1开始")]
		YKE_GROUP_ITEM_CUR_LINE = 10,

		/// <summary>
		/// 当前行MARK
		/// </summary>
		[Description("当前行MARK")]
		YKE_GROUP_ITEM_CURMARK = 11,

		/// <summary>
		/// 当前速度
		/// </summary>
		[Description("当前速度")]
		YKE_GROUP_ITEM_VEL = 12,

		/// <summary>
		/// 当前加速度
		/// </summary>
		[Description("当前加速度")]
		YKE_GROUP_ITEM_ACC = 13,

		/// <summary>
		/// 当前JERK,未实现
		/// </summary>
		[Description("当前JERK,未实现")]
		YKE_GROUP_ITEM_JERK = 14,

		/// <summary>
		/// 报警标记
		/// </summary>
		[Description("报警标记")]
		YKE_GROUP_ITEM_WARN1 = 15,

		/// <summary>
		/// 报警代码
		/// </summary>
		[Description("报警代码")]
		YKE_GROUP_ITEM_WARN2 = 16,

		/// <summary>
		/// XY合成速度
		/// </summary>
		[Description("XY合成速度")]
		YKE_GROUP_ITEM_VEL_2D = 20,

		/// <summary>
		/// XYZ合成速度
		/// </summary>
		[Description("XYZ合成速度")]
		YKE_GROUP_ITEM_VEL_3D = 21,

		/// <summary>
		/// XY已移动距离
		/// </summary>
		[Description("XY已移动距离")]
		YKE_GROUP_ITEM_DIST_2D = 22,

		/// <summary>
		/// XYZ已移动距离
		/// </summary>
		[Description("XYZ已移动距离")]
		YKE_GROUP_ITEM_DIST_3D = 23,

		/// <summary>
		/// 工件X位置
		/// </summary>
		[Description("工件X位置")]
		YKE_GROUP_ITEM_WORKPIECE_X = 30,

		/// <summary>
		/// 工件Y位置
		/// </summary>
		[Description("工件Y位置")]
		YKE_GROUP_ITEM_WORKPIECE_Y = 31,

		/// <summary>
		/// 工件Z位置
		/// </summary>
		[Description("工件Z位置")]
		YKE_GROUP_ITEM_WORKPIECE_Z = 32,

		/// <summary>
		/// 工件A位置
		/// </summary>
		[Description("工件A位置")]
		YKE_GROUP_ITEM_WORKPIECE_A = 33,

		/// <summary>
		/// 工件B位置
		/// </summary>
		[Description("工件B位置")]
		YKE_GROUP_ITEM_WORKPIECE_B = 34,

		/// <summary>
		/// 工件C位置
		/// </summary>
		[Description("工件C位置")]
		YKE_GROUP_ITEM_WORKPIECE_C = 35,

		/// <summary>
		/// 调试用1
		/// </summary>
		[Description("调试用1")]
		YKE_GROUP_ITEM_DEBUG1 = 100,

		/// <summary>
		/// 调试用2
		/// </summary>
		[Description("调试用2")]
		YKE_GROUP_ITEM_DEBUG2 = 101,

		/// <summary>
		/// 调试用3
		/// </summary>
		[Description("调试用3")]
		YKE_GROUP_ITEM_DEBUG3 = 102,

		/// <summary>
		/// 调试用4
		/// </summary>
		[Description("调试用4")]
		YKE_GROUP_ITEM_DEBUG4 = 103,

		/// <summary>
		/// 调试用5
		/// </summary>
		[Description("调试用5")]
		YKE_GROUP_ITEM_DEBUG5 = 104,
	};

	/// <summary>
	/// 坐标系中位置比较模式
	/// </summary>
	public enum YKE_GROUP_COMPARE_MODE
	{
		/// <summary>
		/// 到达后立即输出
		/// </summary>
		[Description("到达后立即输出")]
		YKE_GROUP_COMPARE_START_IMMEDIATELY = 0,

		/// <summary>
		/// 到达下一段终点后立即输出
		/// </summary>
		[Description("到达下一段终点后立即输出")]
		YKE_GROUP_COMPARE_END_IMMEDIATELY = 1,

		/// <summary>
		/// 以下一段起点为参考延时指定时间输出ms
		/// </summary>
		[Description("以下一段起点为参考延时指定时间输出ms")]
		YKE_GROUP_COMPARE_COMPLETED_TIME = 2,

		/// <summary>
		/// 以下一段起点为参考移动指定距离输出(用户单位)
		/// </summary>
		[Description("以下一段起点为参考移动指定距离输出(用户单位)")]
		YKE_GROUP_COMPARE_COMPLETED_DIST = 3,

		/// <summary>
		/// 以下一段终点为参考提前指定时间输出ms
		/// </summary>
		[Description("以下一段终点为参考提前指定时间输出ms")]
		YKE_GROUP_COMPARE_REMAINING_TIME = 4,

		/// <summary>
		/// 以下一段终点为参考提前指定距离输出(用户单位)
		/// </summary>
		[Description("以下一段终点为参考提前指定距离输出(用户单位)")]
		YKE_GROUP_COMPARE_REMAINING_DIST = 5,

		/// <summary>
		/// 下一段已运行距离超过指定比率(0~1)后输出
		/// </summary>
		[Description("下一段已运行距离超过指定比率(0~1)后输出")]
		YKE_GROUP_COMPARE_COMPLETED_RATE = 6,
	};

	/// <summary>
	/// 坐标系中数字输出模式
	/// </summary>
	public enum YKE_GROUP_DO_MODE
	{
		/// <summary>
		/// 单次输出
		/// </summary>
		[Description("单次输出")]
		YKE_GROUP_DO_SINGLE = 0,

		/// <summary>
		/// 多脉冲输出,开关交替输出
		/// </summary>
		[Description("多脉冲输出,开关交替输出")]
		YKE_GROUP_DO_ALTERNATE = 1,

		/// <summary>
		/// 单脉冲输出
		/// </summary>
		[Description("单脉冲输出")]
		YKE_GROUP_DO_PULSE = 2,
	};

	/// <summary>
	/// 坐标系中PWM跟随模式
	/// </summary>
	public enum YKE_GROUP_PWM_MODE
	{
		/// <summary>
		/// 固定参数输出
		/// </summary>
		[Description("固定参数输出")]
		YKE_GROUP_PWM_FIX = 0,

		/// <summary>
		/// 占空比自动调整
		/// </summary>
		[Description("占空比自动调整")]
		YKE_GROUP_PWM_DUTY = 1,

		/// <summary>
		/// 频率自动调整
		/// </summary>
		[Description("频率自动调整")]
		YKE_GROUP_PWM_FREQ = 2,
	};

	/// <summary>
	/// 轴类型,coppylia仿真使用
	/// </summary>
	public enum YKE_AXIS_SIM_TYPE
	{
		/// <summary>
		/// 直线轴
		/// </summary>
		[Description("直线轴")]
		YKE_AXIS_SIM_LINEAR = 0,

		/// <summary>
		/// 旋转轴
		/// </summary>
		[Description("旋转轴")]
		YKE_AXIS_SIM_ROTARY = 1,
	};

	/// <summary>
	/// 触发类型
	/// </summary>
	public enum YKE_TRIGGER_TYPE
	{
		/// <summary>
		/// 剩余时间(毫秒单位)
		/// </summary>
		[Description("剩余时间(毫秒单位)")]
		YKE_TRIGGER_REMAINING_TIME = 0,

		/// <summary>
		/// 剩余距离(用户单位)
		/// </summary>
		[Description("剩余距离(用户单位)")]
		YKE_TRIGGER_REMAINGING_DISTANCE = 1,

		/// <summary>
		/// 完成的时刻
		/// </summary>
		[Description("完成的时刻")]
		YKE_TRIGGER_SAMETIME_COMPLETION = 2,

		/// <summary>
		/// 运行时间(毫秒单位)
		/// </summary>
		[Description("运行时间(毫秒单位)")]
		YKE_TRIGGER_COMPLETED_TIME = 3,

		/// <summary>
		/// 完成距离(用户单位)
		/// </summary>
		[Description("完成距离(用户单位)")]
		YKE_TRIGGER_COMPLETED_DISTANCE = 4,

		/// <summary>
		/// 参考运动停止时,触发运动再经过一定的时间才停止,未实现
		/// </summary>
		[Description("参考运动停止时,触发运动再经过一定的时间才停止,未实现")]
		YKE_TRIGGER_STAGGERED_TIME_COMPLETION = 5,

		/// <summary>
		/// 参考运动停止时,触发运动再经过一定的距离才停止,未实现
		/// </summary>
		[Description("参考运动停止时,触发运动再经过一定的距离才停止,未实现")]
		YKE_TRIGGER_STAGGERED_DISTANCE_COMPLETION = 6,
	};

	/// <summary>
	/// 信号源
	/// </summary>
	public enum YKE_SIGNAL_SOURCE_TYPE
	{
		/// <summary>
		/// 数字输入
		/// </summary>
		[Description("数字输入")]
		YKE_SIGNAL_SOURCE_INPUT = 0,

		/// <summary>
		/// 数字输出
		/// </summary>
		[Description("数字输出")]
		YKE_SIGNAL_SOURCE_OUTPUT = 1,

		/// <summary>
		/// 控制事件
		/// </summary>
		[Description("控制事件")]
		YKE_SIGNAL_SOURCE_EVENT = 2,

		/// <summary>
		/// 通用数据寄存器
		/// </summary>
		[Description("通用数据寄存器")]
		YKE_SIGNAL_SOURCE_REG = 3,
	};

	/// <summary>
	/// 两个BIT位合成条件
	/// </summary>
	public enum YKE_LOGIC_CONDITIONS
	{
		/// <summary>
		/// 当两个指定的IO位均为TRUE时,条件为TRUE
		/// </summary>
		[Description("当两个指定的IO位均为TRUE时,条件为TRUE")]
		YKE_LOGIC_AND = 0,

		/// <summary>
		/// 两个指定的IO位中的任何一个为TRUE时,条件为TRUE
		/// </summary>
		[Description("两个指定的IO位中的任何一个为TRUE时,条件为TRUE")]
		YKE_LOGIC_OR = 1,

		/// <summary>
		/// 当两个指定的IO位均为TRUE时,条件为FALSE
		/// </summary>
		[Description("当两个指定的IO位均为TRUE时,条件为FALSE")]
		YKE_LOGIC_NAND = 2,

		/// <summary>
		/// 当两个指定的IO位中的任何一个为TRUE时,条件为FALSE
		/// </summary>
		[Description("当两个指定的IO位中的任何一个为TRUE时,条件为FALSE")]
		YKE_LOGIC_NOR = 3,
	};

	/// <summary>
	/// 事件状态
	/// </summary>
	public enum YKE_EVENT_STATUS_TYTE
	{
		/// <summary>
		/// 空闲
		/// </summary>
		[Description("空闲")]
		YKE_EVENT_STATUS_IDEL = 0,

		/// <summary>
		/// 等待事件发生
		/// </summary>
		[Description("等待事件发生")]
		YKE_EVENT_STATUS_WAIT = 5,

		/// <summary>
		/// 等待事件重新启动
		/// </summary>
		[Description("等待事件重新启动")]
		YKE_EVENT_STATUS_RESTART = 10,

		/// <summary>
		/// 延时中
		/// </summary>
		[Description("延时中")]
		YKE_EVENT_STATUS_DELAY = 15,

		/// <summary>
		/// 事件已经发生
		/// </summary>
		[Description("事件已经发生")]
		YKE_EVENT_STATUS_FINISH = 20,
	};

	/// <summary>
	/// M/H辅助功能相对过渡段执行时间类型
	/// </summary>
	public enum YKE_CNC_ACTION_TYPE
	{
		/// <summary>
		/// 平滑轮廓中(default)
		/// </summary>
		[Description("平滑轮廓中(default)")]
		YKE_CNC_ACTION_INTER = 0,

		/// <summary>
		/// 平滑轮廓前
		/// </summary>
		[Description("平滑轮廓前")]
		YKE_CNC_ACTION_PRE = 1,

		/// <summary>
		/// 平滑轮廓后
		/// </summary>
		[Description("平滑轮廓后")]
		YKE_CNC_ACTION_POST = 2,
	};

	/// <summary>
	/// Akima样条过渡切向类型
	/// </summary>
	public enum YKE_CNC_ASPLINE_TRANS_TYPE
	{
		/// <summary>
		/// 算法自动计算(default)
		/// </summary>
		[Description("算法自动计算(default)")]
		YKE_CNC_ASPLINE_TRANS_AUTO = 0,

		/// <summary>
		/// 前后段切向自动
		/// </summary>
		[Description("前后段切向自动")]
		YKE_CNC_ASPLINE_TRANS_TANGENTIAL = 1,

		/// <summary>
		/// 用户设置
		/// </summary>
		[Description("用户设置")]
		YKE_CNC_ASPLINE_TRANS_USER = 2,
	};

	/// <summary>
	/// HSC_Surface平滑变加速监控类型
	/// </summary>
	public enum YKE_CNC_CHECK_JERK_TYPE
	{
		/// <summary>
		/// 不监控(default)
		/// </summary>
		[Description("不监控(default)")]
		YKE_CNC_CHECKJERK_NO = 0,

		/// <summary>
		/// 几何曲线监控
		/// </summary>
		[Description("几何曲线监控")]
		YKE_CNC_CHECKJERK_GEOMERTRIC = 1,

		/// <summary>
		/// 非线性曲线监控
		/// </summary>
		[Description("非线性曲线监控")]
		YKE_CNC_CHECKJERK_NOLIEAR = 2,
	};

	/// <summary>
	/// HSC_Serface平滑圆弧优化类型
	/// </summary>
	public enum YKE_HSC_CIR_MODE
	{
		/// <summary>
		/// 圆弧轮廓平滑(default)
		/// </summary>
		[Description("圆弧轮廓平滑(default)")]
		YKE_HSC_CIR_MODE_CONTOUR = 0,

		/// <summary>
		/// 圆周运动无轮廓平滑
		/// </summary>
		[Description("圆周运动无轮廓平滑")]
		YKE_HSC_CIR_MODE_NOCONTOUR = 1,

		/// <summary>
		/// 圆弧轮廓平滑+长路径圆优化
		/// </summary>
		[Description("圆弧轮廓平滑+长路径圆优化")]
		YKE_HSC_CIR_MODE_CONTOUR_LONG = 2,
	};

	/// <summary>
	/// CNC指令模式
	/// </summary>
	public enum YKE_CNC_INS_MODE
	{
		/// <summary>
		/// API模式
		/// </summary>
		[Description("API模式")]
		YKE_CNC_INS_API = 0,

		/// <summary>
		/// 文件模式
		/// </summary>
		[Description("文件模式")]
		YKE_CNC_INS_FILE = 1,

		/// <summary>
		/// 外部GUI控制
		/// </summary>
		[Description("外部GUI控制")]
		YKE_CNC_EXTERN = 2,
	};

	/// <summary>
	/// 日志过滤选择
	/// </summary>
	public enum YKE_LOGGER_FILTER_TYPE
	{
		/// <summary>
		/// 采集所有指令
		/// </summary>
		[Description("采集所有指令")]
		YKE_LOGGER_FILTER_ALL = 0,

		/// <summary>
		/// 采集item中指定的指令
		/// </summary>
		[Description("采集item中指定的指令")]
		YKE_LOGGER_FILTER_INCLUDE = 1,

		/// <summary>
		/// 采集item中未指定的指令
		/// </summary>
		[Description("采集item中未指定的指令")]
		YKE_LOGGER_FILTER_EXCLUDE = 2,
	};

	/// <summary>
	/// 授权状态
	/// </summary>
	public enum YKE_LICENSE_STATUS
	{
		/// <summary>
		/// 正常
		/// </summary>
		[Description("正常")]
		YKE_LICENSE_OK = 0,

		/// <summary>
		/// 轴授权数量不够
		/// </summary>
		[Description("轴授权数量不够")]
		YKE_LICENSE_AXIS = 1,

		/// <summary>
		/// 坐标系授权数量不够
		/// </summary>
		[Description("坐标系授权数量不够")]
		YKE_LICENSE_GROUP = 2,

		/// <summary>
		/// 无视觉授权
		/// </summary>
		[Description("无视觉授权")]
		YKE_LICENSE_VISION = 3,

		/// <summary>
		/// 电子凸轮授权数量不够
		/// </summary>
		[Description("电子凸轮授权数量不够")]
		YKE_LICENSE_ECAM = 4,

		/// <summary>
		/// 无PLC授权
		/// </summary>
		[Description("无PLC授权")]
		YKE_LICENSE_PLC = 5,

		/// <summary>
		/// 无可视化授权
		/// </summary>
		[Description("无可视化授权")]
		YKE_LICENSE_HMI = 6,

		/// <summary>
		/// 无实时通讯授权
		/// </summary>
		[Description("无实时通讯授权")]
		YKE_LICENSE_RT = 7,

		/// <summary>
		/// 无NTF授权
		/// </summary>
		[Description("无NTF授权")]
		YKE_LICENSE_NTF = 8,

		/// <summary>
		/// 250us及以下总线周期需要专用PC支持
		/// </summary>
		[Description("250us及以下总线周期需要专用PC支持")]
		YKE_LICENSE_PC_250 = 9,

		/// <summary>
		/// 无API授权
		/// </summary>
		[Description("无API授权")]
		YKE_LICENSE_API = 10,

		/// <summary>
		/// 临时授权识别码不匹配
		/// </summary>
		[Description("临时授权识别码不匹配")]
		YKE_LICENSE_SUID = 20,

		/// <summary>
		/// 临时授权已到期
		/// </summary>
		[Description("临时授权已到期")]
		YKE_LICENSE_TEMP = 21,

		/// <summary>
		/// 授权解码失败
		/// </summary>
		[Description("授权解码失败")]
		YKE_LICENSE_SHELL = 30,
	};

	/// <summary>
	/// 工程配置数据掩码,按位定义
	/// </summary>
	public enum YKE_PROJECT_MASK
	{
		/// <summary>
		/// 全局配置
		/// </summary>
		[Description("全局配置")]
		YKE_PROJECT_GCONFIG = 0x01,

		/// <summary>
		/// 轴配置数据
		/// </summary>
		[Description("轴配置数据")]
		YKE_PROJECT_AXIS = 0x02,

		/// <summary>
		/// 本地高速卡数据
		/// </summary>
		[Description("本地高速卡数据")]
		YKE_PROJECT_CARD = 0x04,

		/// <summary>
		/// 总线配置数据
		/// </summary>
		[Description("总线配置数据")]
		YKE_PROJECT_ECAT = 0x08,
	};

	/// <summary>
	/// 扫描内容
	/// </summary>
	public enum YKE_SCAN_INFO
	{
		/// <summary>
		/// 无效
		/// </summary>
		[Description("无效")]
		YKE_SCAN_NONE = 0x00,

		/// <summary>
		/// 读制造商信息
		/// </summary>
		[Description("读制造商信息")]
		YKE_SCAN_VID = 0x01,

		/// <summary>
		/// 读槽位信息,网关使用
		/// </summary>
		[Description("读槽位信息,网关使用")]
		YKE_SCAN_SLOT = 0x02,
	};

	/// <summary>
	/// 总线初始化状态
	/// </summary>
	public enum YKE_PDS_PHASE
	{
		/// <summary>
		/// 空闲
		/// </summary>
		[Description("空闲")]
		YKE_PDS_NONE = 0x00,

		/// <summary>
		/// 已加载配置文件
		/// </summary>
		[Description("已加载配置文件")]
		YKE_PDS_LOAD = 10,

		/// <summary>
		/// 进入INIT模式
		/// </summary>
		[Description("进入INIT模式")]
		YKE_PDS_ING = 20,

		/// <summary>
		/// EEP读取完成
		/// </summary>
		[Description("EEP读取完成")]
		YKE_PDS_EEP = 21,

		/// <summary>
		/// 进入PREOP模式
		/// </summary>
		[Description("进入PREOP模式")]
		YKE_PDS_PREOP = 24,

		/// <summary>
		/// 进入SAFEOP模式
		/// </summary>
		[Description("进入SAFEOP模式")]
		YKE_PDS_SAFEOP = 25,

		/// <summary>
		/// PDO开始工作
		/// </summary>
		[Description("PDO开始工作")]
		YKE_PDS_PDO = 30,

		/// <summary>
		/// 完全运行状态
		/// </summary>
		[Description("完全运行状态")]
		YKE_PDS_RUN = 40,
	};

	/// <summary>
	/// 加密狗类型
	/// </summary>
	public enum YKE_DOGGLE_TYPE
	{
		/// <summary>
		/// 加密锁A
		/// </summary>
		[Description("加密锁A")]
		YKE_DOGGLE_A = 0,

		/// <summary>
		/// 加密锁B
		/// </summary>
		[Description("加密锁B")]
		YKE_DOGGLE_B = 1,
	};

	/// <summary>
	/// PLC命令类型
	/// </summary>
	public enum YKE_PLC_CMD_TYPE
	{
		/// <summary>
		/// 无效
		/// </summary>
		[Description("无效")]
		YKE_PLC_CMD_NONE = 0,

		/// <summary>
		/// 程序运行
		/// </summary>
		[Description("程序运行")]
		YKE_PLC_CMD_PRG_START = 1,

		/// <summary>
		/// 程序停止
		/// </summary>
		[Description("程序停止")]
		YKE_PLC_CMD_PRG_STOP = 2,

		/// <summary>
		/// PLC Runtime退出
		/// </summary>
		[Description("PLC Runtime退出")]
		YKE_PLC_CMD_SYS_EXIT = 10,
	};

	/// <summary>
	/// 特性寄存器功能定义
	/// </summary>
	public enum YKE_SPEC_REG
	{
		/// <summary>
		/// 250usON 250usOFF
		/// </summary>
		[Description("250usON 250usOFF")]
		YKE_500US_TICK = 0,

		/// <summary>
		/// 500usON 500usOFF
		/// </summary>
		[Description("500usON 500usOFF")]
		YKE_1MS_TICK = 1,

		/// <summary>
		/// 2.5msON 2.5msOFF
		/// </summary>
		[Description("2.5msON 2.5msOFF")]
		YKE_5MS_TICK = 2,

		/// <summary>
		/// 25msON 25msOFF
		/// </summary>
		[Description("25msON 25msOFF")]
		YKE_50MS_TICK = 3,

		/// <summary>
		/// 250msON 250msOFF
		/// </summary>
		[Description("250msON 250msOFF")]
		YKE_500MS_TICK = 4,

		/// <summary>
		/// 15sON 15sOFF
		/// </summary>
		[Description("15sON 15sOFF")]
		YKE_30S_TICK = 5,

		/// <summary>
		/// 时钟秒
		/// </summary>
		[Description("时钟秒")]
		YKE_TIME_SEC = 10,

		/// <summary>
		/// 时钟分
		/// </summary>
		[Description("时钟分")]
		YKE_TIME_MIN = 11,

		/// <summary>
		/// 时钟小时
		/// </summary>
		[Description("时钟小时")]
		YKE_TIME_HOUR = 12,

		/// <summary>
		/// 时钟日
		/// </summary>
		[Description("时钟日")]
		YKE_TIME_DAY = 13,

		/// <summary>
		/// 时钟月
		/// </summary>
		[Description("时钟月")]
		YKE_TIME_MONTH = 14,

		/// <summary>
		/// 时钟年
		/// </summary>
		[Description("时钟年")]
		YKE_TIME_YEAR = 15,

		/// <summary>
		/// 星期
		/// </summary>
		[Description("星期")]
		YKE_TIME_WEEK = 16,

		/// <summary>
		/// 可视化当前页面,从1开始
		/// </summary>
		[Description("可视化当前页面,从1开始")]
		YKE_HMI_CURRENT_PAGE = 100,

		/// <summary>
		/// 切换可视化页面,从1开始
		/// </summary>
		[Description("切换可视化页面,从1开始")]
		YKE_HMI_CHANGE_PAGE = 101,

		/// <summary>
		/// 切换当前用户,0变1有效
		/// </summary>
		[Description("切换当前用户,0变1有效")]
		YKE_HMI_CHANGE_USER = 102,

		/// <summary>
		/// 切换当前配方,0变1有效
		/// </summary>
		[Description("切换当前配方,0变1有效")]
		YKE_HMI_CHANGE_RECIPE = 103,

		/// <summary>
		/// 重启可视化
		/// </summary>
		[Description("重启可视化")]
		YKE_HMI_RESTART = 110,

		/// <summary>
		/// 关闭可视化
		/// </summary>
		[Description("关闭可视化")]
		YKE_HMI_CLOSE = 111,

		/// <summary>
		/// 待切换用户密码,占用2个寄存器
		/// </summary>
		[Description("待切换用户密码,占用2个寄存器")]
		YKE_HMI_CUR_USER_PW = 118,

		/// <summary>
		/// 待切换用户名称,占用20个寄存器
		/// </summary>
		[Description("待切换用户名称,占用20个寄存器")]
		YKE_HMI_CHANGE_USER_NAME = 120,

		/// <summary>
		/// 当前用户名称,占用20个寄存器
		/// </summary>
		[Description("当前用户名称,占用20个寄存器")]
		YKE_HMI_CUR_USER_NAME = 140,

		/// <summary>
		/// 当前配方名称,占用20个寄存器
		/// </summary>
		[Description("当前配方名称,占用20个寄存器")]
		YKE_HMI_CUR_RECIPE_NAME = 160,

		/// <summary>
		/// 待切换配方名称,占用20个寄存器
		/// </summary>
		[Description("待切换配方名称,占用20个寄存器")]
		YKE_HMI_CHANGE_RECIPE_NAME = 180,
	};
	#endregion

	#region 结构体定义
	/// <summary>
	/// 3坐标值
	/// </summary>
	unsafe public struct YKS_POINT3
	{
		/// <summary>
		/// X坐标
		/// </summary>
		[Description("X坐标")]
		public double x;

		/// <summary>
		/// Y坐标
		/// </summary>
		[Description("Y坐标")]
		public double y;

		/// <summary>
		/// Z坐标
		/// </summary>
		[Description("Z坐标")]
		public double z;
	}

	/// <summary>
	/// 输入信号配置
	/// </summary>
	unsafe public struct YKS_AxisSwitchConfig
	{
		/// <summary>
		/// 输入类型
		/// </summary>
		[Description("输入类型")]
		public YKE_SWITCH_TYPE type;

		/// <summary>
		/// 探针配置:类型为YKE_SWITCH_COE_REG时:0=z相 1=ext
		/// 限位原点配置:类型为YKE_SWITCH_COE_REG表示60FD的bit序号,类型为YKE_SWITCH_GLOBAL_DIO表示DI字节序号
		/// </summary>
		[Description("探针配置:类型为YKE_SWITCH_COE_REG时:0=z相 1=ext;限位原点配置:类型为YKE_SWITCH_COE_REG表示60FD的bit序号,类型为YKE_SWITCH_GLOBAL_DIO表示DI字节序号")]
		public UInt32 byte_offset;

		/// <summary>
		/// 类型为YKE_SWITCH_COE_REG时无效,类型为YKE_SWITCH_GLOBAL_DIO表示DI位偏移[0,7)
		/// </summary>
		[Description("类型为YKE_SWITCH_COE_REG时无效,类型为YKE_SWITCH_GLOBAL_DIO表示DI位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// 探针配置: FALSE=上升沿 TRUE=下降沿
		/// 对Z相无效
		/// 限位原点配置: TRUE=逻辑取反
		/// </summary>
		[Description("探针配置: FALSE=上升沿 TRUE=下降沿;对Z相无效;限位原点配置: TRUE=逻辑取反")]
		public YKE_BOOL inv_or_edge;

		/// <summary>
		/// 位置偏差(0,DOUBLE_MAX](unit),YKE_SWITCH_MECHANICAL模式有效
		/// </summary>
		[Description("位置偏差(0,DOUBLE_MAX](unit),YKE_SWITCH_MECHANICAL模式有效")]
		public double position_error;

		/// <summary>
		/// 偏差保持时间[0,DOUBLE_MAX](ms),YKE_SWITCH_MECHANICAL模式有效
		/// </summary>
		[Description("偏差保持时间[0,DOUBLE_MAX](ms),YKE_SWITCH_MECHANICAL模式有效")]
		public double hold_time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];
	}

	/// <summary>
	/// 系统配置
	/// </summary>
	unsafe public struct YKS_SysProfile
	{
		/// <summary>
		/// runtime启动路径
		/// </summary>
		[Description("runtime启动路径")]
		public fixed sbyte path[260];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res6;

		/// <summary>
		/// 配置的轴数量
		/// </summary>
		[Description("配置的轴数量")]
		public UInt32 config_axis_num;

		/// <summary>
		/// 数字输入组数量
		/// </summary>
		[Description("数字输入组数量")]
		public UInt32 config_input_size;

		/// <summary>
		/// 数字输出组数量
		/// </summary>
		[Description("数字输出组数量")]
		public UInt32 config_output_size;

		/// <summary>
		/// 加密锁A序列号
		/// </summary>
		[Description("加密锁A序列号")]
		public UInt32 dog_serial_numberA;

		/// <summary>
		/// 加密锁B序列号
		/// </summary>
		[Description("加密锁B序列号")]
		public fixed sbyte dog_serial_numberB[64];

		/// <summary>
		/// 加密锁A内存空间,字节单位
		/// </summary>
		[Description("加密锁A内存空间,字节单位")]
		public UInt32 dog_mem_sizeA;

		/// <summary>
		/// 加密锁B内存空间,字节单位
		/// </summary>
		[Description("加密锁B内存空间,字节单位")]
		public UInt32 dog_mem_sizeB;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public double res0;

		/// <summary>
		/// 轴授权数量
		/// </summary>
		[Description("轴授权数量")]
		public UInt32 dog_axis_num;

		/// <summary>
		/// 轴使用数量
		/// </summary>
		[Description("轴使用数量")]
		public UInt32 dog_axis_used;

		/// <summary>
		/// 凸轮授权数量
		/// </summary>
		[Description("凸轮授权数量")]
		public UInt32 dog_ecam_num;

		/// <summary>
		/// 凸轮使用数量
		/// </summary>
		[Description("凸轮使用数量")]
		public UInt32 dog_ecam_used;

		/// <summary>
		/// 视觉授权标记
		/// </summary>
		[Description("视觉授权标记")]
		public UInt32 dog_vision_num;

		/// <summary>
		/// 视觉使用标记
		/// </summary>
		[Description("视觉使用标记")]
		public UInt32 dog_vision_used;

		/// <summary>
		/// PLC授权标记
		/// </summary>
		[Description("PLC授权标记")]
		public UInt32 dog_plc_num;

		/// <summary>
		/// PLC使用标记
		/// </summary>
		[Description("PLC使用标记")]
		public UInt32 dog_plc_used;

		/// <summary>
		/// 可视化授权标记
		/// </summary>
		[Description("可视化授权标记")]
		public UInt32 dog_hmi_num;

		/// <summary>
		/// 可视化使用标记
		/// </summary>
		[Description("可视化使用标记")]
		public UInt32 dog_hmi_used;

		/// <summary>
		/// 实时通讯授权标记
		/// </summary>
		[Description("实时通讯授权标记")]
		public UInt32 dog_comm_num;

		/// <summary>
		/// 实时通讯使用标记
		/// </summary>
		[Description("实时通讯使用标记")]
		public UInt32 dog_comm_used;

		/// <summary>
		/// CAD授权标记
		/// </summary>
		[Description("CAD授权标记")]
		public UInt32 dog_cad_num;

		/// <summary>
		/// CAD使用标记
		/// </summary>
		[Description("CAD使用标记")]
		public UInt32 dog_cad_used;

		/// <summary>
		/// 坐标系授权数量
		/// </summary>
		[Description("坐标系授权数量")]
		public UInt32 dog_group_num;

		/// <summary>
		/// 坐标系使用数量
		/// </summary>
		[Description("坐标系使用数量")]
		public UInt32 dog_group_used;

		/// <summary>
		/// NTF授权标记
		/// </summary>
		[Description("NTF授权标记")]
		public UInt32 dog_dotNetRT_num;

		/// <summary>
		/// NTF使用标记
		/// </summary>
		[Description("NTF使用标记")]
		public UInt32 dog_dotNetRT_used;

		/// <summary>
		/// TRUE:使用临时授权
		/// </summary>
		[Description("TRUE:使用临时授权")]
		public YKE_BOOL dog_date_flag;

		/// <summary>
		/// 临时授权识别码
		/// </summary>
		[Description("临时授权识别码")]
		public UInt32 dog_date_uid;

		/// <summary>
		/// 临时授权到期时间:年
		/// </summary>
		[Description("临时授权到期时间:年")]
		public UInt32 dog_date_year;

		/// <summary>
		/// 临时授权到期时间:月
		/// </summary>
		[Description("临时授权到期时间:月")]
		public UInt32 dog_date_month;

		/// <summary>
		/// 临时授权到期时间:日
		/// </summary>
		[Description("临时授权到期时间:日")]
		public UInt32 dog_date_day;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res1;

		/// <summary>
		/// 专用PC授权标记
		/// </summary>
		[Description("专用PC授权标记")]
		public UInt32 dog_pc_num;

		/// <summary>
		/// 专用PC使用标记
		/// </summary>
		[Description("专用PC使用标记")]
		public UInt32 dog_pc_used;

		/// <summary>
		/// 授权状态
		/// </summary>
		[Description("授权状态")]
		public YKE_LICENSE_STATUS lic_status;

		/// <summary>
		/// 授权错误标记
		/// TRUE=有错误 FALSE=无错误
		/// </summary>
		[Description("授权错误标记;TRUE=有错误 FALSE=无错误")]
		public YKE_BOOL dog_err;

		/// <summary>
		/// 主站启用 TRUE=已启用 FALSE=未启用
		/// </summary>
		[Description("主站启用 TRUE=已启用 FALSE=未启用")]
		public YKE_BOOL node_ena0;

		[Description("主站启用 TRUE=已启用 FALSE=未启用")]
		public YKE_BOOL node_ena1;

		[Description("主站启用 TRUE=已启用 FALSE=未启用")]
		public YKE_BOOL node_ena2;

		[Description("主站启用 TRUE=已启用 FALSE=未启用")]
		public YKE_BOOL node_ena3;

		/// <summary>
		/// TRUE=已启用CNC FALSE=未启用CNC
		/// </summary>
		[Description("TRUE=已启用CNC FALSE=未启用CNC")]
		public YKE_BOOL cnc_enable0;

		[Description("TRUE=已启用CNC FALSE=未启用CNC")]
		public YKE_BOOL cnc_enable1;

		[Description("TRUE=已启用CNC FALSE=未启用CNC")]
		public YKE_BOOL cnc_enable2;

		[Description("TRUE=已启用CNC FALSE=未启用CNC")]
		public YKE_BOOL cnc_enable3;

		/// <summary>
		/// Runtime版本
		/// </summary>
		[Description("Runtime版本")]
		public UInt32 runtime_ver;

		/// <summary>
		/// 内部库版本
		/// </summary>
		[Description("内部库版本")]
		public UInt32 plann_ver;

		/// <summary>
		/// TRUE=windows仿真模式 FALSE=实时模式
		/// </summary>
		[Description("TRUE=windows仿真模式 FALSE=实时模式")]
		public YKE_BOOL sim_mode;

		/// <summary>
		/// 总线数据抓包节点
		/// </summary>
		[Description("总线数据抓包节点")]
		public YKE_NODE ecat_snap_node;

		/// <summary>
		/// 总线数据抓包区间
		/// </summary>
		[Description("总线数据抓包区间")]
		public UInt32 ecat_snap_span;

		/// <summary>
		/// PLC启用
		/// </summary>
		[Description("PLC启用")]
		public UInt32 plc_enable;

		/// <summary>
		/// PLC运行节点
		/// </summary>
		[Description("PLC运行节点")]
		public YKE_NODE plc_node;

		/// <summary>
		/// API授权标记
		/// </summary>
		[Description("API授权标记")]
		public UInt32 dog_api_num;

		/// <summary>
		/// API使用标记
		/// </summary>
		[Description("API使用标记")]
		public UInt32 dog_api_used;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res5[31];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[32];
	}

	/// <summary>
	/// 数字输入输出配置
	/// </summary>
	unsafe public struct YKS_DigitalIO
	{
		/// <summary>
		/// 字节偏移
		/// </summary>
		[Description("字节偏移")]
		public UInt32 byte_offset;

		/// <summary>
		/// 位偏移[0,7)
		/// </summary>
		[Description("位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// FALSE=不取反 TRUE=取反
		/// </summary>
		[Description("FALSE=不取反 TRUE=取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;
	}

	/// <summary>
	/// 数字输入配置
	/// </summary>
	unsafe public struct YKS_DigitalInput
	{
		/// <summary>
		/// FALSE=不启用 TRUE=启用
		/// </summary>
		[Description("FALSE=不启用 TRUE=启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// 字节偏移[0,512)
		/// </summary>
		[Description("字节偏移[0,512)")]
		public UInt32 byte_index;

		/// <summary>
		/// 位偏移[0,7)
		/// </summary>
		[Description("位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// FALSE=不取反 TRUE=取反
		/// </summary>
		[Description("FALSE=不取反 TRUE=取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 滤波时间[0,1000](ms)
		/// </summary>
		[Description("滤波时间[0,1000](ms)")]
		public double filter_tim;

		/// <summary>
		/// 当前状态 FALSE=OFF TRUE=ON
		/// </summary>
		[Description("当前状态 FALSE=OFF TRUE=ON")]
		public YKE_BOOL value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[7];
	}

	/// <summary>
	/// 数字输出配置
	/// </summary>
	unsafe public struct YKS_DigitalOutput
	{
		/// <summary>
		/// FALSE=不启用 TRUE=启用
		/// </summary>
		[Description("FALSE=不启用 TRUE=启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// 字节偏移[0,512)
		/// </summary>
		[Description("字节偏移[0,512)")]
		public UInt32 byte_index;

		/// <summary>
		/// 位偏移[0,7)
		/// </summary>
		[Description("位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// 输出有效值 FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出有效值 FALSE=OFF TRUE=ON")]
		public YKE_BOOL valid;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 同步数字输出配置
	/// </summary>
	unsafe public struct YKS_DigitalOutputCycle
	{
		/// <summary>
		/// 字节偏移[0,512)
		/// </summary>
		[Description("字节偏移[0,512)")]
		public UInt32 byte_index;

		/// <summary>
		/// 位偏移[0,7)
		/// </summary>
		[Description("位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// 输出有效值 FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出有效值 FALSE=OFF TRUE=ON")]
		public YKE_BOOL valid;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[4];
	}

	/// <summary>
	/// windows蓝屏后的行为
	/// </summary>
	unsafe public struct YKS_BlueScreenConfig
	{
		/// <summary>
		/// FALSE=不启用 TRUE=启用
		/// </summary>
		[Description("FALSE=不启用 TRUE=启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// FALSE=不处理 TRUE=停止所有轴
		/// </summary>
		[Description("FALSE=不处理 TRUE=停止所有轴")]
		public YKE_BOOL stop_axis;

		/// <summary>
		/// FALSE=不处理 TRUE=关闭所有IO
		/// </summary>
		[Description("FALSE=不处理 TRUE=关闭所有IO")]
		public YKE_BOOL close_output;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];
	}

	/// <summary>
	/// 硬件急停配置信息
	/// </summary>
	unsafe public struct YKS_HardEmgProfile
	{
		/// <summary>
		/// 急停输入
		/// </summary>
		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input0;

		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input1;

		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input2;

		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input3;

		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input4;

		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input5;

		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input6;

		[Description("急停输入")]
		public YKS_DigitalInput emg_stop_input7;

		/// <summary>
		/// 急停输出
		/// </summary>
		[Description("急停输出")]
		public YKS_DigitalOutput emg_stop_output0;

		[Description("急停输出")]
		public YKS_DigitalOutput emg_stop_output1;

		[Description("急停输出")]
		public YKS_DigitalOutput emg_stop_output2;

		[Description("急停输出")]
		public YKS_DigitalOutput emg_stop_output3;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 全局状态信息
	/// </summary>
	unsafe public struct YKS_EmgStatus
	{
		/// <summary>
		/// 软件急停信号状态 FALSE=无效 TRUE=有效
		/// </summary>
		[Description("软件急停信号状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_soft;

		/// <summary>
		/// 急停输入状态 FALSE=无效 TRUE=有效
		/// </summary>
		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input0;

		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input1;

		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input2;

		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input3;

		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input4;

		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input5;

		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input6;

		[Description("急停输入状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL emg_stop_input7;

		/// <summary>
		/// 急停输入状态(按位定义8个急停输入结果)
		/// </summary>
		[Description("急停输入状态(按位定义8个急停输入结果)")]
		public UInt32 emg_stop_input_all;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[4];
	}

	/// <summary>
	/// 总线实时信息
	/// </summary>
	unsafe public struct YKS_BusStatus
	{
		/// <summary>
		/// 配置的从站数量,包含未启用站点和移除站点
		/// </summary>
		[Description("配置的从站数量,包含未启用站点和移除站点")]
		public UInt32 config_num;

		/// <summary>
		/// 配置中未移除的从站数量
		/// </summary>
		[Description("配置中未移除的从站数量")]
		public UInt32 useable_num;

		/// <summary>
		/// 实际检测到的从站数量
		/// </summary>
		[Description("实际检测到的从站数量")]
		public UInt32 active_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 系统最小负载(ms)
		/// </summary>
		[Description("系统最小负载(ms)")]
		public double min_payload;

		/// <summary>
		/// 系统最大负载(ms)
		/// </summary>
		[Description("系统最大负载(ms)")]
		public double max_payload;

		/// <summary>
		/// 系统当前负载(ms)
		/// </summary>
		[Description("系统当前负载(ms)")]
		public double cur_payload;

		/// <summary>
		/// 最小DC偏移(ms)
		/// </summary>
		[Description("最小DC偏移(ms)")]
		public double min_shift;

		/// <summary>
		/// 最大DC偏移(ms)
		/// </summary>
		[Description("最大DC偏移(ms)")]
		public double max_shift;

		/// <summary>
		/// 当前DC偏移(ms)
		/// </summary>
		[Description("当前DC偏移(ms)")]
		public double cur_shift;

		/// <summary>
		/// 总线周期(ms)
		/// </summary>
		[Description("总线周期(ms)")]
		public double dc_cycle;

		/// <summary>
		/// 帧丢失计数
		/// </summary>
		[Description("帧丢失计数")]
		public UInt32 lost_frames;

		/// <summary>
		/// WKC丢失帧计数
		/// </summary>
		[Description("WKC丢失帧计数")]
		public UInt32 lost_wkc;

		/// <summary>
		/// 主站激活标记 FALSE=未激活 TRUE=已激活
		/// </summary>
		[Description("主站激活标记 FALSE=未激活 TRUE=已激活")]
		public YKE_BOOL master_active;

		/// <summary>
		/// 掉线的从站数量
		/// </summary>
		[Description("掉线的从站数量")]
		public UInt32 offline_num;

		/// <summary>
		/// 每us中CPU的Tick数量
		/// </summary>
		[Description("每us中CPU的Tick数量")]
		public ulong cpu_ticks;

		/// <summary>
		/// YKG最大负载(ms)
		/// </summary>
		[Description("YKG最大负载(ms)")]
		public double max_ykg_payload;

		/// <summary>
		/// YKG当前负载(ms)
		/// </summary>
		[Description("YKG当前负载(ms)")]
		public double cur_ykg_payload;

		/// <summary>
		/// NT最大负载(ms)
		/// </summary>
		[Description("NT最大负载(ms)")]
		public double max_nt_payload;

		/// <summary>
		/// NT当前负载(ms)
		/// </summary>
		[Description("NT当前负载(ms)")]
		public double cur_nt_payload;

		/// <summary>
		/// CNC最大负载(ms)
		/// </summary>
		[Description("CNC最大负载(ms)")]
		public double max_cnc_payload;

		/// <summary>
		/// CNC当前负载(ms)
		/// </summary>
		[Description("CNC当前负载(ms)")]
		public double cur_cnc_payload;

		/// <summary>
		/// 心跳计数,每个运动周期加1
		/// </summary>
		[Description("心跳计数,每个运动周期加1")]
		public ulong heart_tick;

		/// <summary>
		/// 系统错误类型
		/// </summary>
		[Description("系统错误类型")]
		public YKE_SYSTEM_ERROR sys_error_type;

		/// <summary>
		/// 系统层错误代码1
		/// </summary>
		[Description("系统层错误代码1")]
		public UInt32 sys_error_code1;

		/// <summary>
		/// 系统层错误代码2
		/// </summary>
		[Description("系统层错误代码2")]
		public UInt32 sys_error_code2;

		/// <summary>
		/// 链路层错误类型
		/// </summary>
		[Description("链路层错误类型")]
		public YKE_LINK_ERROR link_error_type;

		/// <summary>
		/// 链路层错误代码1
		/// </summary>
		[Description("链路层错误代码1")]
		public UInt32 link_error_code1;

		/// <summary>
		/// 链路层错误代码2
		/// </summary>
		[Description("链路层错误代码2")]
		public UInt32 link_error_code2;

		/// <summary>
		/// 总线状态
		/// </summary>
		[Description("总线状态")]
		public YKE_BUS_STATUS bus_status;

		/// <summary>
		/// 系统SDO队列空闲数量
		/// </summary>
		[Description("系统SDO队列空闲数量")]
		public UInt32 sys_sdo_idel;

		/// <summary>
		/// 用户SDO队列空闲数量
		/// </summary>
		[Description("用户SDO队列空闲数量")]
		public UInt32 user_sdo_idel;

		/// <summary>
		/// 通讯帧长度(byte)
		/// </summary>
		[Description("通讯帧长度(byte)")]
		public fixed UInt32 frame_length[16];

		/// <summary>
		/// 总线运行阶段
		/// </summary>
		[Description("总线运行阶段")]
		public YKE_PDS_PHASE pds_phase;

		/// <summary>
		/// 调试用1
		/// </summary>
		[Description("调试用1")]
		public UInt32 debug1;

		/// <summary>
		/// 调试用2
		/// </summary>
		[Description("调试用2")]
		public UInt32 debug2;

		/// <summary>
		/// 调试用3
		/// </summary>
		[Description("调试用3")]
		public UInt32 debug3;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[9];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[32];
	}

	/// <summary>
	/// 总线数据包的辅助信息
	/// </summary>
	unsafe public struct YKS_BusPacketHeader
	{
		/// <summary>
		/// 时间(毫秒单位)
		/// </summary>
		[Description("时间(毫秒单位)")]
		public double time;

		/// <summary>
		/// TRUE=接收的数据 FALSE=发送的数据
		/// </summary>
		[Description("TRUE=接收的数据 FALSE=发送的数据")]
		public YKE_BOOL rev_flag;

		/// <summary>
		/// 源mac地址
		/// </summary>
		[Description("源mac地址")]
		public fixed Byte source_mac[6];

		/// <summary>
		/// 目标mac地址
		/// </summary>
		[Description("目标mac地址")]
		public fixed Byte destion_mac[6];

		/// <summary>
		/// 数据包类型,EhterCAT为0x88A4
		/// </summary>
		[Description("数据包类型,EhterCAT为0x88A4")]
		public UInt32 ethernet_type;

		/// <summary>
		/// 数据长度
		/// </summary>
		[Description("数据长度")]
		public UInt32 length;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[4];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[4];
	}

	/// <summary>
	/// SDO命令状态
	/// </summary>
	unsafe public struct YKS_SdoStatus
	{
		/// <summary>
		/// FLASE=命令未完成 TRUE=命令已完成,数据有效
		/// </summary>
		[Description("FLASE=命令未完成 TRUE=命令已完成,数据有效")]
		public YKE_BOOL valid;

		/// <summary>
		/// 返回数据
		/// </summary>
		[Description("返回数据")]
		public UInt32 data;

		/// <summary>
		/// 时间开销(ms)
		/// </summary>
		[Description("时间开销(ms)")]
		public double tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];
	}

	/// <summary>
	/// 总线从站状态
	/// </summary>
	unsafe public struct YKS_SlaveStatus
	{
		/// <summary>
		/// 0x130寄存器当前值
		/// </summary>
		[Description("0x130寄存器当前值")]
		public UInt16 esc_status;

		/// <summary>
		/// 前面板ID
		/// </summary>
		[Description("前面板ID")]
		public UInt16 station_id;

		/// <summary>
		/// 时钟偏差(ns) 0x92C寄存器
		/// </summary>
		[Description("时钟偏差(ns) 0x92C寄存器")]
		public Int32 clock_offset;

		/// <summary>
		/// 错误类型
		/// </summary>
		[Description("错误类型")]
		public YKE_SLAVE_ERROR slave_error_type;

		/// <summary>
		/// 错误代码
		/// </summary>
		[Description("错误代码")]
		public UInt32 slave_error_code;

		/// <summary>
		/// COE访问错误的主索引(高16位)和子索引(低16位)
		/// </summary>
		[Description("COE访问错误的主索引(高16位)和子索引(低16位)")]
		public UInt32 coe_type;

		/// <summary>
		/// COE标准错误代码
		/// </summary>
		[Description("COE标准错误代码")]
		public UInt32 coe_code;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 al_res;

		/// <summary>
		/// AL寄存器的值(0x130)锁存值
		/// </summary>
		[Description("AL寄存器的值(0x130)锁存值")]
		public UInt32 al_code;

		/// <summary>
		/// FALSE=未掉线 TRUE=已掉线
		/// </summary>
		[Description("FALSE=未掉线 TRUE=已掉线")]
		public YKE_BOOL offline;

		/// <summary>
		/// PDO开始地址,字节单位
		/// </summary>
		[Description("PDO开始地址,字节单位")]
		public UInt32 pdo_start;

		/// <summary>
		/// PDO数据数量,字节单位
		/// </summary>
		[Description("PDO数据数量,字节单位")]
		public UInt32 pdo_length;

		/// <summary>
		/// 配置文件中的制造商ID
		/// </summary>
		[Description("配置文件中的制造商ID")]
		public UInt32 user_vid;

		/// <summary>
		/// 配置文件中的产品ID
		/// </summary>
		[Description("配置文件中的产品ID")]
		public UInt32 user_pid;

		/// <summary>
		/// 配置文件中的修订号
		/// </summary>
		[Description("配置文件中的修订号")]
		public UInt32 user_revsion;

		/// <summary>
		/// 实际读回来的制造商ID
		/// </summary>
		[Description("实际读回来的制造商ID")]
		public UInt32 eep_vid;

		/// <summary>
		/// 际读回来的产品ID
		/// </summary>
		[Description("际读回来的产品ID")]
		public UInt32 eep_pid;

		/// <summary>
		/// 实际读回来的修订号
		/// </summary>
		[Description("实际读回来的修订号")]
		public UInt32 eep_revsion;

		/// <summary>
		/// ESC端口状态 FALSE=无链接 TRUE=有链接
		/// </summary>
		[Description("ESC端口状态 FALSE=无链接 TRUE=有链接")]
		public YKE_BOOL port_link0;

		[Description("ESC端口状态 FALSE=无链接 TRUE=有链接")]
		public YKE_BOOL port_link1;

		[Description("ESC端口状态 FALSE=无链接 TRUE=有链接")]
		public YKE_BOOL port_link2;

		[Description("ESC端口状态 FALSE=无链接 TRUE=有链接")]
		public YKE_BOOL port_link3;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[9];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[24];
	}

	/// <summary>
	/// 从站PDO配置
	/// </summary>
	unsafe public struct YKS_SlavePdoConfig
	{
		/// <summary>
		/// 主索引
		/// </summary>
		[Description("主索引")]
		public UInt32 main_index;

		/// <summary>
		/// 子索引
		/// </summary>
		[Description("子索引")]
		public UInt32 sub_index;

		/// <summary>
		/// 位数量
		/// </summary>
		[Description("位数量")]
		public UInt32 bit_num;

		/// <summary>
		/// 位偏移
		/// </summary>
		[Description("位偏移")]
		public UInt32 bit_offset;

		/// <summary>
		/// G索引
		/// </summary>
		[Description("G索引")]
		public UInt32 g_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 模轴参数
	/// </summary>
	unsafe public struct YKS_AxisProfileModulo
	{
		/// <summary>
		/// FALSE=禁用模轴 TRUE=启用模轴
		/// </summary>
		[Description("FALSE=禁用模轴 TRUE=启用模轴")]
		public YKE_BOOL enable;

		/// <summary>
		/// 驱动器模轴状态 FALSE=否 TRUE=是
		/// </summary>
		[Description("驱动器模轴状态 FALSE=否 TRUE=是")]
		public YKE_BOOL drv_modulo_status;

		/// <summary>
		/// 单圈脉冲数量
		/// </summary>
		[Description("单圈脉冲数量")]
		public UInt32 single_encoder_count;

		/// <summary>
		/// 半圈模式(从最近的方向移动到目的地) FALSE=禁用 TRUE=启用
		/// </summary>
		[Description("半圈模式(从最近的方向移动到目的地) FALSE=禁用 TRUE=启用")]
		public YKE_BOOL half_turn;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 单轴运动曲线参数
	/// </summary>
	unsafe public struct YKS_AxisProfileMotion
	{
		/// <summary>
		/// 加速曲线选择
		/// </summary>
		[Description("加速曲线选择")]
		public YKE_CURVE_TYPE curve_type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 启动速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("启动速度(0,DOUBLE_MAX](unit/s)")]
		public double start_velocity;

		/// <summary>
		/// 停止速度[0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("停止速度[0,DOUBLE_MAX](unit/s)")]
		public double stop_velocity;

		/// <summary>
		/// 运行速度[0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度[0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 加速时间[0,DOUBLE_MAX](ms)
		/// KE_CURVE_T7_TIME模式使用
		/// </summary>
		[Description("加速时间[0,DOUBLE_MAX](ms);KE_CURVE_T7_TIME模式使用")]
		public double acc_time;

		/// <summary>
		/// 减速时间[0,DOUBLE_MAX](ms)
		/// KE_CURVE_T7_TIME模式使用
		/// </summary>
		[Description("减速时间[0,DOUBLE_MAX](ms);KE_CURVE_T7_TIME模式使用")]
		public double dec_time;

		/// <summary>
		/// 加速段比率[0,1]
		/// YKE_CURVE_S7_RATE模式使用
		/// </summary>
		[Description("加速段比率[0,1];YKE_CURVE_S7_RATE模式使用")]
		public double acc_rate;

		/// <summary>
		/// 减速段比率[0,1]
		/// YKE_CURVE_S7_RATE模式使用
		/// </summary>
		[Description("减速段比率[0,1];YKE_CURVE_S7_RATE模式使用")]
		public double dec_rate;

		/// <summary>
		/// 加速段的变加速度[0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("加速段的变加速度[0,DOUBLE_MAX](unit/s^3)")]
		public double jerk_acc;

		/// <summary>
		/// 减速段的变加速度[0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("减速段的变加速度[0,DOUBLE_MAX](unit/s^3)")]
		public double jerk_dec;

		/// <summary>
		/// 匀速段最小时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("匀速段最小时间[0,DOUBLE_MAX](ms)")]
		public double constant_velocity_time;

		/// <summary>
		/// 匀加速段最小时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("匀加速段最小时间[0,DOUBLE_MAX](ms)")]
		public double constant_acc_time;

		/// <summary>
		/// 匀减速度段最小时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("匀减速度段最小时间[0,DOUBLE_MAX](ms)")]
		public double constant_dec_time;

		/// <summary>
		/// 平滑时间[0,DOUBLE_MAX](ms)
		/// YKE_CURVE_TS模式使用
		/// </summary>
		[Description("平滑时间[0,DOUBLE_MAX](ms);YKE_CURVE_TS模式使用")]
		public double smooth_time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[28];
	}

	/// <summary>
	/// 单轴基本运动参数配置
	/// </summary>
	unsafe public struct YKS_AxisProfileBase
	{
		/// <summary>
		/// 最高速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("最高速度(0,DOUBLE_MAX](unit/s)")]
		public double max_velocity;

		/// <summary>
		/// 最大加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("最大加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double max_acceleration;

		/// <summary>
		/// 最大变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("最大变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double max_jerk;

		/// <summary>
		/// 急停时的减速度(0,DOUBLE_MAX](unit/s^2),如碰硬限位,急停stop指令
		/// </summary>
		[Description("急停时的减速度(0,DOUBLE_MAX](unit/s^2),如碰硬限位,急停stop指令")]
		public double stop_dec_emg;

		/// <summary>
		/// 缓停时的减速度(0,DOUBLE_MAX](unit/s^2),如缓停stop指令
		/// </summary>
		[Description("缓停时的减速度(0,DOUBLE_MAX](unit/s^2),如缓停stop指令")]
		public double stop_dec_smooth;

		/// <summary>
		/// 软限位有效的减速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("软限位有效的减速度(0,DOUBLE_MAX](unit/s^3)")]
		public double stop_dec_limitsoft;

		/// <summary>
		/// 停止时的变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("停止时的变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double stop_dec_jerk;

		/// <summary>
		/// CNC管理单轴运动
		/// FALSE=禁用 TRUE=启用
		/// </summary>
		[Description("CNC管理单轴运动;FALSE=禁用 TRUE=启用")]
		public YKE_BOOL enable_cnc;

		/// <summary>
		/// 急停信号有效后给轴的控制命令
		/// </summary>
		[Description("急停信号有效后给轴的控制命令")]
		public YKE_EMG_AXIS_BEGAVIOR emg_behavior;

		/// <summary>
		/// 关联的急停通道,按位定义
		/// </summary>
		[Description("关联的急停通道,按位定义")]
		public UInt32 emg_mask;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 调试用
		/// </summary>
		[Description("调试用")]
		public double debug1;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[16];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res2[16];
	}

	/// <summary>
	/// 单轴基本运动参数,到位相关
	/// </summary>
	unsafe public struct YKS_AxisProfileInp
	{
		/// <summary>
		/// 位置到位范围[0,DOUBLE_MAX](unit) 0=不启用
		/// </summary>
		[Description("位置到位范围[0,DOUBLE_MAX](unit) 0=不启用")]
		public double inp;

		/// <summary>
		/// 到位稳定时间[0,YKS_AxisProfileInp.inp_timout)(ms)
		/// </summary>
		[Description("到位稳定时间[0,YKS_AxisProfileInp.inp_timout)(ms)")]
		public double inp_tim;

		/// <summary>
		/// 到位超时时间[0,3000](ms)
		/// </summary>
		[Description("到位超时时间[0,3000](ms)")]
		public double inp_timout;

		/// <summary>
		/// 反馈位置到位范围1[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("反馈位置到位范围1[0,DOUBLE_MAX](uint)")]
		public double inp1_fb;

		/// <summary>
		/// 反馈位置到位范围2[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("反馈位置到位范围2[0,DOUBLE_MAX](uint)")]
		public double inp2_fb;

		/// <summary>
		/// 反馈位置到位范围3[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("反馈位置到位范围3[0,DOUBLE_MAX](uint)")]
		public double inp3_fb;

		/// <summary>
		/// 反馈位置到位范围4[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("反馈位置到位范围4[0,DOUBLE_MAX](uint)")]
		public double inp4_fb;

		/// <summary>
		/// 反馈位置到位范围5[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("反馈位置到位范围5[0,DOUBLE_MAX](uint)")]
		public double inp5_fb;

		/// <summary>
		/// 反馈位置到位范围6[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("反馈位置到位范围6[0,DOUBLE_MAX](uint)")]
		public double inp6_fb;

		/// <summary>
		/// 转矩到位范围(0.1%单位)
		/// </summary>
		[Description("转矩到位范围(0.1%单位)")]
		public double tq_inp;

		/// <summary>
		/// 转矩到位稳定时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("转矩到位稳定时间[0,DOUBLE_MAX](ms)")]
		public double tq_tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 单轴基本运动参数, 跟随误差相关
	/// </summary>
	unsafe public struct YKS_AxisProfilePositionLag
	{
		/// <summary>
		/// 跟随误差检查时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("跟随误差检查时间[0,DOUBLE_MAX](ms)")]
		public double position_lag_tim;

		/// <summary>
		/// 最大跟随误差[0,DOUBLE_MAX](uint) 0=不启用
		/// </summary>
		[Description("最大跟随误差[0,DOUBLE_MAX](uint) 0=不启用")]
		public double position_lag_limit;

		/// <summary>
		/// 跟随误差(YKS_AxisStatusPosition.position_lag_filter)滤波时间[0,100](ms)
		/// </summary>
		[Description("跟随误差(YKS_AxisStatusPosition.position_lag_filter)滤波时间[0,100](ms)")]
		public double position_lag_filter_time;

		/// <summary>
		/// 和主轴的最大位置偏差限制[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("和主轴的最大位置偏差限制[0,DOUBLE_MAX](uint)")]
		public double master_position_lag_limit;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 清驱动器报警机制设置
	/// </summary>
	unsafe public struct YKS_AxisProfileClearDrv
	{
		/// <summary>
		/// 等待清除完成时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("等待清除完成时间[0,DOUBLE_MAX](ms)")]
		public double wait_tim;

		/// <summary>
		/// 重试次数[0,100]
		/// </summary>
		[Description("重试次数[0,100]")]
		public UInt32 retry;

		/// <summary>
		/// 驱动器无报警情况下
		/// FALSE=不发命令到驱动器 TRUE=发命令到驱动器
		/// </summary>
		[Description("驱动器无报警情况下;FALSE=不发命令到驱动器 TRUE=发命令到驱动器")]
		public YKE_BOOL force;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 轴使能机制设置
	/// </summary>
	unsafe public struct YKS_AxisProfilePowerOn
	{
		/// <summary>
		/// 等待使能完成时间[0,60000](ms)
		/// </summary>
		[Description("等待使能完成时间[0,60000](ms)")]
		public double wait_tim;

		/// <summary>
		/// YKS_AxisStatusBase.power_on信号有效后YKS_AxisStatusBase.active信号锁定时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("YKS_AxisStatusBase.power_on信号有效后YKS_AxisStatusBase.active信号锁定时间[0,DOUBLE_MAX](ms)")]
		public double lock_tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 轴前馈配置
	/// </summary>
	unsafe public struct YKS_AxisProfileFeedforward
	{
		/// <summary>
		/// 前馈启用 FALSE=未启用 TRUE=启用
		/// </summary>
		[Description("前馈启用 FALSE=未启用 TRUE=启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 速度权重
		/// </summary>
		[Description("速度权重")]
		public double velocity_weighting;

		/// <summary>
		/// 速度延时输出
		/// </summary>
		[Description("速度延时输出")]
		public double velocity_delay;

		/// <summary>
		/// 加速度权重
		/// </summary>
		[Description("加速度权重")]
		public double acceleration_weighting;

		/// <summary>
		/// 加速度延时输出
		/// </summary>
		[Description("加速度延时输出")]
		public double acceleration_delay;

		/// <summary>
		/// jerk权重
		/// </summary>
		[Description("jerk权重")]
		public double jerk_weighting;

		/// <summary>
		/// jerk延时输出
		/// </summary>
		[Description("jerk延时输出")]
		public double jerk_delay;

		/// <summary>
		/// 全局权重
		/// </summary>
		[Description("全局权重")]
		public double global_weighting;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 轴基本配置
	/// </summary>
	unsafe public struct YKS_AxisConfigBase
	{
		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// 轴类型
		/// </summary>
		[Description("轴类型")]
		public YKE_AXIS_PHY phy_type;

		/// <summary>
		/// 轴主序号
		/// </summary>
		[Description("轴主序号")]
		public UInt32 phy_main;

		/// <summary>
		/// 轴子序号
		/// </summary>
		[Description("轴子序号")]
		public UInt32 phy_sub;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[16];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[16];
	}

	/// <summary>
	/// 规划信息
	/// </summary>
	unsafe public struct YKS_AxisStatusPlanner
	{
		/// <summary>
		/// 规划器标记,内部使用
		/// </summary>
		[Description("规划器标记,内部使用")]
		public UInt32 plann_flag;

		/// <summary>
		/// 规划完成 FALSE=未完成 TRUE=已完成
		/// </summary>
		[Description("规划完成 FALSE=未完成 TRUE=已完成")]
		public YKE_BOOL command_done;

		/// <summary>
		/// 规划已完成时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("规划已完成时间[0,DOUBLE_MAX](ms)")]
		public double command_done_time;

		/// <summary>
		/// 规划器运行时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("规划器运行时间[0,DOUBLE_MAX](ms)")]
		public double command_run_time;

		/// <summary>
		/// 实际运行时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("实际运行时间[0,DOUBLE_MAX](ms)")]
		public double actual_run_time;

		/// <summary>
		/// 规划的总运动时间[-1,DOUBLE_MAX](ms)
		/// </summary>
		[Description("规划的总运动时间[-1,DOUBLE_MAX](ms)")]
		public double command_total_time;

		/// <summary>
		/// 剩余规划时间[-1,DOUBLE_MAX](ms)
		/// </summary>
		[Description("剩余规划时间[-1,DOUBLE_MAX](ms)")]
		public double command_remain_time;

		/// <summary>
		/// 变参数的时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("变参数的时间[0,DOUBLE_MAX](ms)")]
		public double change_time;

		/// <summary>
		/// 算法耗时[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("算法耗时[0,DOUBLE_MAX](ms)")]
		public double payload;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[16];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[16];
	}

	/// <summary>
	/// 轴位置相关状态
	/// </summary>
	unsafe public struct YKS_AxisStatusPosition
	{
		/// <summary>
		/// 原始位置(编码器反馈值)[INT32_MIN,INT32_MAX](pulse)
		/// </summary>
		[Description("原始位置(编码器反馈值)[INT32_MIN,INT32_MAX](pulse)")]
		public Int32 encoder_raw_position;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 位置偏差(上位机位置减去驱动器位置)[INT32_MIN,INT32_MAX](pulse)
		/// </summary>
		[Description("位置偏差(上位机位置减去驱动器位置)[INT32_MIN,INT32_MAX](pulse)")]
		public Int64 position_offset;

		/// <summary>
		/// 位置跟随误差(无滤波)[DOUBLE_MIN,DOUBLE_MAX](uint)
		/// </summary>
		[Description("位置跟随误差(无滤波)[DOUBLE_MIN,DOUBLE_MAX](uint)")]
		public double position_lag;

		/// <summary>
		/// 滤波(YKS_AxisProfilePositionLag.position_lag_filter_time)后的位置跟随误差[DOUBLE_MIN,DOUBLE_MAX](uint)
		/// </summary>
		[Description("滤波(YKS_AxisProfilePositionLag.position_lag_filter_time)后的位置跟随误差[DOUBLE_MIN,DOUBLE_MAX](uint)")]
		public double position_lag_filter;

		/// <summary>
		/// 反馈位置1比较到位 FALSE=未到位 TRUE=已到位
		/// </summary>
		[Description("反馈位置1比较到位 FALSE=未到位 TRUE=已到位")]
		public YKE_BOOL fb_inp1;

		/// <summary>
		/// 反馈位置2比较到位 FALSE=未到位 TRUE=已到位
		/// </summary>
		[Description("反馈位置2比较到位 FALSE=未到位 TRUE=已到位")]
		public YKE_BOOL fb_inp2;

		/// <summary>
		/// 反馈位置3比较到位 FALSE=未到位 TRUE=已到位
		/// </summary>
		[Description("反馈位置3比较到位 FALSE=未到位 TRUE=已到位")]
		public YKE_BOOL fb_inp3;

		/// <summary>
		/// 反馈位置4比较到位 FALSE=未到位 TRUE=已到位
		/// </summary>
		[Description("反馈位置4比较到位 FALSE=未到位 TRUE=已到位")]
		public YKE_BOOL fb_inp4;

		/// <summary>
		/// 反馈位置5比较到位 FALSE=未到位 TRUE=已到位
		/// </summary>
		[Description("反馈位置5比较到位 FALSE=未到位 TRUE=已到位")]
		public YKE_BOOL fb_inp5;

		/// <summary>
		/// 反馈位置6比较到位 FALSE=未到位 TRUE=已到位
		/// </summary>
		[Description("反馈位置6比较到位 FALSE=未到位 TRUE=已到位")]
		public YKE_BOOL fb_inp6;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[16];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[16];
	}

	/// <summary>
	/// 轴补偿状态
	/// </summary>
	unsafe public struct YKS_AxisStatusCompensation
	{
		/// <summary>
		/// 螺距补偿启用 FALSE=未启用 TRUE=启用
		/// </summary>
		[Description("螺距补偿启用 FALSE=未启用 TRUE=启用")]
		public YKE_BOOL pitch1d_active;

		/// <summary>
		/// 二维补偿启用 FALSE=未启用 TRUE=启用
		/// </summary>
		[Description("二维补偿启用 FALSE=未启用 TRUE=启用")]
		public YKE_BOOL pitch2d_active;

		/// <summary>
		/// 间隙补偿启用 FALSE=未启用 TRUE=启用
		/// </summary>
		[Description("间隙补偿启用 FALSE=未启用 TRUE=启用")]
		public YKE_BOOL backlash_active;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 螺距补偿量 螺距补偿/二维补偿给定[DOUBLE_MIN,DOUBLE_MAX](uint)
		/// </summary>
		[Description("螺距补偿量 螺距补偿/二维补偿给定[DOUBLE_MIN,DOUBLE_MAX](uint)")]
		public double pitch_value;

		/// <summary>
		/// 间隙补偿量
		/// </summary>
		[Description("间隙补偿量")]
		public double backlash_value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 轴跟随状态
	/// </summary>
	unsafe public struct YKS_AxisStatusFollow
	{
		/// <summary>
		/// 软跟随运动的主轴  FALSE=否 TRUE=是
		/// </summary>
		[Description("软跟随运动的主轴  FALSE=否 TRUE=是")]
		public YKE_BOOL follow_master;

		/// <summary>
		/// 硬跟随开启 FALSE=未开启 TRUE=已开启
		/// </summary>
		[Description("硬跟随开启 FALSE=未开启 TRUE=已开启")]
		public YKE_BOOL gantry_enable;

		/// <summary>
		/// 硬跟随主轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("硬跟随主轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 gantry_master_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 与硬跟随主轴的实际位置偏差[DOUBLE_MIN,DOUBLE_MAX](uint)
		/// </summary>
		[Description("与硬跟随主轴的实际位置偏差[DOUBLE_MIN,DOUBLE_MAX](uint)")]
		public double gantry_actual_err;

		/// <summary>
		/// 与软件跟随主轴的实际位置偏差[DOUBLE_MIN,DOUBLE_MAX](uint)
		/// </summary>
		[Description("与软件跟随主轴的实际位置偏差[DOUBLE_MIN,DOUBLE_MAX](uint)")]
		public double follow_actual_err;

		/// <summary>
		/// 传送带同步状态
		/// </summary>
		[Description("传送带同步状态")]
		public YKE_CONVEYOR_SYNC_STATUS converyor_sync_status;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[7];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 轴基本状态
	/// </summary>
	unsafe public struct YKS_AxisStatusBase
	{
		/// <summary>
		/// 运动类型
		/// </summary>
		[Description("运动类型")]
		public YKE_MOTION_TYPE motion_type;

		/// <summary>
		/// 停止类型
		/// </summary>
		[Description("停止类型")]
		public YKE_AXIS_STOP_TYPE stop_type;

		/// <summary>
		/// 运动方向
		/// </summary>
		[Description("运动方向")]
		public YKE_DIRECTION direction;

		/// <summary>
		/// 轴使能状态 FALSE=未使能  TRUE=已使能
		/// </summary>
		[Description("轴使能状态 FALSE=未使能  TRUE=已使能")]
		public YKE_BOOL power_on;

		/// <summary>
		/// 回原状态  FALSE=未完成  TRUE=已完成
		/// </summary>
		[Description("回原状态  FALSE=未完成  TRUE=已完成")]
		public YKE_BOOL is_homed;

		/// <summary>
		/// 轴运动状态 FALSE=空闲  TRUE=忙
		/// </summary>
		[Description("轴运动状态 FALSE=空闲  TRUE=忙")]
		public UInt32 active;

		/// <summary>
		/// 指令完成状态  FALSE=未完成  TRUE=已完成
		/// </summary>
		[Description("指令完成状态  FALSE=未完成  TRUE=已完成")]
		public YKE_BOOL done;

		/// <summary>
		/// 锁存的Busy值
		/// </summary>
		[Description("锁存的Busy值")]
		public UInt32 lock_busy;

		/// <summary>
		/// 轴报警状态 bit0:运动轴错误 bit1:驱动器错误
		/// 0=无错误 1=有错误
		/// </summary>
		[Description("轴报警状态 bit0:运动轴错误 bit1:驱动器错误;0=无错误 1=有错误")]
		public UInt32 warnning;

		/// <summary>
		/// 运动轴错误代码
		/// </summary>
		[Description("运动轴错误代码")]
		public YKE_MC_ERROR axis_warn_id;

		/// <summary>
		/// 驱动器报警代码, 等于603F寄存器内容
		/// </summary>
		[Description("驱动器报警代码, 等于603F寄存器内容")]
		public UInt32 drv_error_id;

		/// <summary>
		/// TRUE=关联的总线站点已掉线 FLASE=未掉线
		/// </summary>
		[Description("TRUE=关联的总线站点已掉线 FLASE=未掉线")]
		public YKE_BOOL offline;

		/// <summary>
		/// 原点信号状态  FALSE=信号无效  TRUE=信号有效
		/// </summary>
		[Description("原点信号状态  FALSE=信号无效  TRUE=信号有效")]
		public YKE_BOOL home_switch;

		/// <summary>
		/// 硬件正限位状态 FALSE=信号无效  TRUE=信号有效
		/// </summary>
		[Description("硬件正限位状态 FALSE=信号无效  TRUE=信号有效")]
		public YKE_BOOL limit_switch_pos;

		/// <summary>
		/// 硬件负限位状态 FALSE=信号无效  TRUE=信号有效
		/// </summary>
		[Description("硬件负限位状态 FALSE=信号无效  TRUE=信号有效")]
		public YKE_BOOL limit_switch_neg;

		/// <summary>
		/// 正软限位到位状态 FALSE=信号无效  TRUE=信号有效
		/// </summary>
		[Description("正软限位到位状态 FALSE=信号无效  TRUE=信号有效")]
		public YKE_BOOL limit_soft_pos;

		/// <summary>
		/// 负软限位到位状态 FALSE=信号无效  TRUE=信号有效
		/// </summary>
		[Description("负软限位到位状态 FALSE=信号无效  TRUE=信号有效")]
		public YKE_BOOL limit_soft_neg;

		/// <summary>
		/// 软急停状态,按位定义
		/// </summary>
		[Description("软急停状态,按位定义")]
		public UInt32 soft_emg;

		/// <summary>
		/// 硬急停状态,按位定义
		/// </summary>
		[Description("硬急停状态,按位定义")]
		public UInt32 hard_emg;

		/// <summary>
		/// 圆形区域保护,按位定义 0=不在限位区域内  1=在限位区域内
		/// </summary>
		[Description("圆形区域保护,按位定义 0=不在限位区域内  1=在限位区域内")]
		public UInt32 circle_zone;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[16];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[16];
	}

	/// <summary>
	/// 多轴运动状态
	/// </summary>
	unsafe public struct YKS_MultiAxisStatus
	{
		/// <summary>
		/// TRUE=运行中 FLASE=空闲
		/// </summary>
		[Description("TRUE=运行中 FLASE=空闲")]
		public YKE_BOOL active;

		/// <summary>
		/// TRUE=运行完成 FALSE=未完成
		/// </summary>
		[Description("TRUE=运行完成 FALSE=未完成")]
		public YKE_BOOL done;

		/// <summary>
		/// 错误代码
		/// </summary>
		[Description("错误代码")]
		public YKE_MC_ERROR error;

		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// 规划总时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("规划总时间[0,DOUBLE_MAX](ms)")]
		public double total_tim;

		/// <summary>
		/// 运行距离
		/// </summary>
		[Description("运行距离")]
		public double completed_dist;

		/// <summary>
		/// 剩余距离[0,DOUBLE_MAX](uint)
		/// </summary>
		[Description("剩余距离[0,DOUBLE_MAX](uint)")]
		public double remain_dist;

		/// <summary>
		/// 运行时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("运行时间[0,DOUBLE_MAX](ms)")]
		public double completed_tim;

		/// <summary>
		/// 剩余时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("剩余时间[0,DOUBLE_MAX](ms)")]
		public double remain_tim;

		/// <summary>
		/// 调试状态
		/// </summary>
		[Description("调试状态")]
		public UInt32 debug1;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[9];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 轴软件探针配置
	/// </summary>
	unsafe public struct YKS_AxisProbeConfigSoft
	{
		/// <summary>
		/// 触发输入
		/// </summary>
		[Description("触发输入")]
		public YKS_DigitalIO input;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// FALSE=重复触发  TRUE=只触发一次
		/// </summary>
		[Description("FALSE=重复触发  TRUE=只触发一次")]
		public YKE_BOOL trig_once;

		/// <summary>
		/// 触发内容
		/// </summary>
		[Description("触发内容")]
		public YKE_AXIS_ITEM_TYPE item;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 软件探针状态
	/// </summary>
	unsafe public struct YKS_AxisProbeStatusSoft
	{
		/// <summary>
		/// 激活状态 FALSE=未激活 TRUE=已激活
		/// </summary>
		[Description("激活状态 FALSE=未激活 TRUE=已激活")]
		public YKE_BOOL active;

		/// <summary>
		/// 触发次数
		/// </summary>
		[Description("触发次数")]
		public UInt32 count;

		/// <summary>
		/// 触发值[DOUBLE_MIN,DOUBLE_MAX]
		/// </summary>
		[Description("触发值[DOUBLE_MIN,DOUBLE_MAX]")]
		public double value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 回原点参数
	/// </summary>
	unsafe public struct YKS_AxisHomeConfig
	{
		/// <summary>
		/// 速度曲线
		/// </summary>
		[Description("速度曲线")]
		public YKE_CURVE_TYPE curve_type;

		/// <summary>
		/// 回原点模式,参考CIA402规范
		/// </summary>
		[Description("回原点模式,参考CIA402规范")]
		public YKE_HOME_MODE mode;

		/// <summary>
		/// 找到探针并减速停止后不回到探针位置
		/// FALSE=禁用  TRUE=启用
		/// </summary>
		[Description("找到探针并减速停止后不回到探针位置;FALSE=禁用  TRUE=启用")]
		public YKE_BOOL out_of_probe;

		/// <summary>
		/// 提前开启探针
		/// FALSE=禁用  TRUE=启用
		/// </summary>
		[Description("提前开启探针;FALSE=禁用  TRUE=启用")]
		public YKE_BOOL pre_probe;

		/// <summary>
		/// 探针通道[0,1] 总线轴使用
		/// </summary>
		[Description("探针通道[0,1] 总线轴使用")]
		public UInt32 index_probe;

		/// <summary>
		/// 回原完成后不修改当前位置,否则用logic_position设为当前位置
		/// FALSE=禁用  TRUE=启用
		/// </summary>
		[Description("回原完成后不修改当前位置,否则用logic_position设为当前位置;FALSE=禁用  TRUE=启用")]
		public YKE_BOOL keep_position;

		/// <summary>
		/// TRUE=驱动器编码器清零(调用驱动器35号模式回原)
		/// </summary>
		[Description("TRUE=驱动器编码器清零(调用驱动器35号模式回原)")]
		public YKE_BOOL clear_encoder;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[7];

		/// <summary>
		/// 回原完成后的当前位置值[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("回原完成后的当前位置值[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double logic_position;

		/// <summary>
		/// 搜索速([0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("搜索速([0,DOUBLE_MAX](unit/s)")]
		public double vel_high;

		/// <summary>
		/// 爬行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("爬行速度(0,DOUBLE_MAX](unit/s)")]
		public double vel_low;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 找限位/原点开关的最大移动量(0,DOUBLE_MAX](unit)
		/// 未设置时默认值5000
		/// </summary>
		[Description("找限位/原点开关的最大移动量(0,DOUBLE_MAX](unit);未设置时默认值5000")]
		public double switch_move;

		/// <summary>
		/// 找探针的最大移动量(0,DOUBLE_MAX](unit)
		/// 未设置时默认值5000
		/// </summary>
		[Description("找探针的最大移动量(0,DOUBLE_MAX](unit);未设置时默认值5000")]
		public double probe_move;

		/// <summary>
		/// 参考探针/开关的移动距离(0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("参考探针/开关的移动距离(0,DOUBLE_MAX](unit)")]
		public double offset;

		/// <summary>
		/// 转矩限制0.1/100单位 (0x6072:0) 设0时不做限制
		/// </summary>
		[Description("转矩限制0.1/100单位 (0x6072:0) 设0时不做限制")]
		public double torque_limit;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 运动仿真规划信息
	/// </summary>
	unsafe public struct YKS_MovePositionSimResult
	{
		/// <summary>
		/// 加速段时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("加速段时间[0,DOUBLE_MAX](ms)")]
		public double acc_tim;

		/// <summary>
		/// 匀速段时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("匀速段时间[0,DOUBLE_MAX](ms)")]
		public double constant_tim;

		/// <summary>
		/// 减速段时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("减速段时间[0,DOUBLE_MAX](ms)")]
		public double dec_tim;

		/// <summary>
		/// 总时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("总时间[0,DOUBLE_MAX](ms)")]
		public double total_tim;

		/// <summary>
		/// 速度峰值[DOUBLE_MIN,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("速度峰值[DOUBLE_MIN,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 经过指定时间时的位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("经过指定时间时的位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double position_of_time;

		/// <summary>
		/// 经过指定时间时的速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("经过指定时间时的速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)")]
		public double velocity_of_time;

		/// <summary>
		/// 经过指定时间时的加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("经过指定时间时的加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)")]
		public double acceleration_of_time;

		/// <summary>
		/// 经过指定时间时的变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("经过指定时间时的变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)")]
		public double jerk_of_time;

		/// <summary>
		/// 移动到指定位置时的时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("移动到指定位置时的时间[0,DOUBLE_MAX](ms)")]
		public double time_of_position;

		/// <summary>
		/// 移动到指定位置时的速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("移动到指定位置时的速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)")]
		public double velocity_of_position;

		/// <summary>
		/// 移动到指定位置时的加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("移动到指定位置时的加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)")]
		public double acceleration_of_position;

		/// <summary>
		/// 移动到指定位置时的变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("移动到指定位置时的变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)")]
		public double jerk_of_position;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[16];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[16];
	}

	/// <summary>
	/// 绝对运动配置
	/// </summary>
	unsafe public struct YKS_MoveAbsoluteConfig
	{
		/// <summary>
		/// 目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double position;

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 仿真运动变参数配置
	/// </summary>
	unsafe public struct YKS_MovePositionSimTrigger
	{
		/// <summary>
		/// 启用变参数
		/// </summary>
		[Description("启用变参数")]
		public YKE_BOOL enable;

		/// <summary>
		/// 触发模式
		/// FALSE=trigger_type和trigger_value指定的触发条件
		/// TRUE=在指定位置(at_position)变参数完成
		/// </summary>
		[Description("触发模式;FALSE=trigger_type和trigger_value指定的触发条件;TRUE=在指定位置(at_position)变参数完成")]
		public YKE_BOOL at_mode;

		/// <summary>
		/// 触发类型
		/// at_mode为FALSE有效
		/// </summary>
		[Description("触发类型;at_mode为FALSE有效")]
		public YKE_TRIGGER_TYPE trigger_type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 时间或者距离
		/// at_mode为FALSE有效
		/// </summary>
		[Description("时间或者距离;at_mode为FALSE有效")]
		public double trigger_value;

		/// <summary>
		/// 指定位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// at_mode为TRUE有效
		/// </summary>
		[Description("指定位置[DOUBLE_MIN,DOUBLE_MAX](unit);at_mode为TRUE有效")]
		public double at_position;

		/// <summary>
		/// 新的运动参数
		/// </summary>
		[Description("新的运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 新的目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("新的目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double new_position;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 仿真运动启动配置
	/// </summary>
	unsafe public struct YKS_MovePositionSimConfig
	{
		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double position;

		/// <summary>
		/// 指定时间(at_time)的类型
		/// FALSE=经过的时间 TRUE=剩余的时间
		/// </summary>
		[Description("指定时间(at_time)的类型;FALSE=经过的时间 TRUE=剩余的时间")]
		public YKE_BOOL time_type;

		/// <summary>
		/// FALSE=轴当前位置为启动位置 TRUE=指定start_pos为启动位置
		/// </summary>
		[Description("FALSE=轴当前位置为启动位置 TRUE=指定start_pos为启动位置")]
		public YKE_BOOL set_start_pos;

		/// <summary>
		/// 开始位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("开始位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double start_pos;

		/// <summary>
		/// 指定位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("指定位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double at_position;

		/// <summary>
		/// 指定时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("指定时间[0,DOUBLE_MAX](ms)")]
		public double at_time;

		/// <summary>
		/// FALSE=不返回指定时间或位置时的相关信息 TRUE=返回指定时间或位置时的相关信息
		/// </summary>
		[Description("FALSE=不返回指定时间或位置时的相关信息 TRUE=返回指定时间或位置时的相关信息")]
		public YKE_BOOL at_calc;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[15];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[16];
	}

	/// <summary>
	/// 传送带运动配置
	/// </summary>
	unsafe public struct YKS_MoveConveyorConfig
	{
		/// <summary>
		/// 传送带移动方向
		/// </summary>
		[Description("传送带移动方向")]
		public YKE_DIRECTION direction;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 最远距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("最远距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double distance;

		/// <summary>
		/// 传送带速度
		/// </summary>
		[Description("传送带速度")]
		public double velocity;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 相对运动配置
	/// </summary>
	unsafe public struct YKS_MoveRelativeConfig
	{
		/// <summary>
		/// 相对位移量[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("相对位移量[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double distance;

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 速度运动配置
	/// </summary>
	unsafe public struct YKS_MoveVelocityConfig
	{
		/// <summary>
		/// 运动方向
		/// </summary>
		[Description("运动方向")]
		public YKE_DIRECTION direction;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 转矩运动配置
	/// </summary>
	unsafe public struct YKS_MoveTorqueConfig
	{
		/// <summary>
		/// 速度限制[0,DOUBLE_MAX](r/min)
		/// </summary>
		[Description("速度限制[0,DOUBLE_MAX](r/min)")]
		public double velocity_max;

		/// <summary>
		/// 转矩值(0.1%单位)
		/// </summary>
		[Description("转矩值(0.1%单位)")]
		public double torque;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 间隙补偿配置
	/// </summary>
	unsafe public struct YKS_BacklashConfig
	{
		/// <summary>
		/// 补偿方向
		/// </summary>
		[Description("补偿方向")]
		public YKE_DIRECTION dir;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 最大补偿量
		/// </summary>
		[Description("最大补偿量")]
		public double backlash_high;

		/// <summary>
		/// 最小补偿量
		/// </summary>
		[Description("最小补偿量")]
		public double backlash_low;

		/// <summary>
		/// 距参考位置的最远距离
		/// 大于此距离将施加最大间隙补偿量
		/// </summary>
		[Description("距参考位置的最远距离;大于此距离将施加最大间隙补偿量")]
		public double distance_high;

		/// <summary>
		/// 距参考位置的最近距离
		/// 低于该距离将施加最小间隙补偿偏移量
		/// </summary>
		[Description("距参考位置的最近距离;低于该距离将施加最小间隙补偿偏移量")]
		public double distance_low;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 一维螺距补偿配置
	/// </summary>
	unsafe public struct YKS_PitchError1DConfig
	{
		/// <summary>
		/// 补偿数量(0,YKE_PITCH1D_NUM]
		/// </summary>
		[Description("补偿数量(0,YKE_PITCH1D_NUM]")]
		public UInt32 count;

		/// <summary>
		/// 补偿原点[0,YKE_PITCH1D_NUM)
		/// </summary>
		[Description("补偿原点[0,YKE_PITCH1D_NUM)")]
		public UInt32 origin_index;

		/// <summary>
		/// 原始点的坐标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("原始点的坐标位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double origin_position;

		/// <summary>
		/// 补偿间隔[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("补偿间隔[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double pitch_interval;

		/// <summary>
		/// 调整速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("调整速度(0,DOUBLE_MAX](unit/s)")]
		public double catchup_velocity;

		/// <summary>
		/// 调整加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("调整加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double catchup_acceleration;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 二维螺距补偿配置
	/// </summary>
	unsafe public struct YKS_PitchError2DConfig
	{
		/// <summary>
		/// 生成补偿数据轴序号X[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("生成补偿数据轴序号X[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index0;

		/// <summary>
		/// 生成补偿数据轴序号Y[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("生成补偿数据轴序号Y[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index1;

		/// <summary>
		/// X补偿原点[0,YKE_PITCH2D_NUM)
		/// </summary>
		[Description("X补偿原点[0,YKE_PITCH2D_NUM)")]
		public UInt32 origin_index0;

		/// <summary>
		/// Y补偿原点[0,YKE_PITCH2D_NUM)
		/// </summary>
		[Description("Y补偿原点[0,YKE_PITCH2D_NUM)")]
		public UInt32 origin_index1;

		/// <summary>
		/// X补偿数量(0,YKE_PITCH2D_NUM]
		/// </summary>
		[Description("X补偿数量(0,YKE_PITCH2D_NUM]")]
		public UInt32 count0;

		/// <summary>
		/// Y补偿数量(0,YKE_PITCH2D_NUM]
		/// </summary>
		[Description("Y补偿数量(0,YKE_PITCH2D_NUM]")]
		public UInt32 count1;

		/// <summary>
		/// 原始点的坐标位置X[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("原始点的坐标位置X[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double origin_position0;

		/// <summary>
		/// 原始点的坐标位置Y[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("原始点的坐标位置Y[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double origin_position1;

		/// <summary>
		/// X方向间隔[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("X方向间隔[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double pitch_interval0;

		/// <summary>
		/// Y方向间隔[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("Y方向间隔[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double pitch_interval1;

		/// <summary>
		/// 调整速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("调整速度(0,DOUBLE_MAX](unit/s)")]
		public double catchup_velocity;

		/// <summary>
		/// 调整加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("调整加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double catchup_acceleration;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 单轴跟随配置
	/// </summary>
	unsafe public struct YKS_FollowAxis1Config
	{
		/// <summary>
		/// 跟随方式
		/// </summary>
		[Description("跟随方式")]
		public YKE_AXIS_FOLLOW_MODE mode;

		/// <summary>
		/// 主轴信息选择
		/// </summary>
		[Description("主轴信息选择")]
		public YKE_AXIS_FOLLOW_TYPE source;

		/// <summary>
		/// 主轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("主轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_master;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分子[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double numerator;

		/// <summary>
		/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分母[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double denominator;

		/// <summary>
		/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 双轴跟随配置
	/// </summary>
	unsafe public struct YKS_FollowAxis2Config
	{
		/// <summary>
		/// 轴合成类型
		/// </summary>
		[Description("轴合成类型")]
		public YKE_COMBINE_MODE combine_mode;

		/// <summary>
		/// 跟随方式
		/// </summary>
		[Description("跟随方式")]
		public YKE_AXIS_FOLLOW_MODE follow_mode;

		/// <summary>
		/// 主轴1信息选择
		/// </summary>
		[Description("主轴1信息选择")]
		public YKE_AXIS_FOLLOW_TYPE source1;

		/// <summary>
		/// 主轴2信息选择
		/// </summary>
		[Description("主轴2信息选择")]
		public YKE_AXIS_FOLLOW_TYPE source2;

		/// <summary>
		/// 主轴1序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("主轴1序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_master1;

		/// <summary>
		/// 主轴2序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("主轴2序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_master2;

		/// <summary>
		/// 分量分子1  合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分量分子1  合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double numerator1;

		/// <summary>
		/// 分量分母1 合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分量分母1 合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double denominator1;

		/// <summary>
		/// 分量分子2  合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分量分子2  合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double numerator2;

		/// <summary>
		/// 分量分母2 合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分量分母2 合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double denominator2;

		/// <summary>
		/// 合成分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("合成分子[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double numerator3;

		/// <summary>
		/// 合成分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("合成分母[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double denominator3;

		/// <summary>
		/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// UG跟随配置
	/// </summary>
	unsafe public struct YKS_FollowUgConfig
	{
		/// <summary>
		/// 跟随曲线类型
		/// </summary>
		[Description("跟随曲线类型")]
		public YKE_AXIS_FOLLOW_MODE mode;

		/// <summary>
		/// 主站选择
		/// </summary>
		[Description("主站选择")]
		public YKE_NODE master;

		/// <summary>
		/// U序号
		/// </summary>
		[Description("U序号")]
		public UInt32 u_index;

		/// <summary>
		/// G序号
		/// </summary>
		[Description("G序号")]
		public UInt32 g_index;

		/// <summary>
		/// FALSE=16模式 TRUE=32模式
		/// </summary>
		[Description("FALSE=16模式 TRUE=32模式")]
		public YKE_BOOL bit32;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// UG信号滤波时间[0,1000](ms)
		/// </summary>
		[Description("UG信号滤波时间[0,1000](ms)")]
		public double filter_tim;

		/// <summary>
		/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分子[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double numerator;

		/// <summary>
		/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分母[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double denominator;

		/// <summary>
		/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系跟随配置
	/// </summary>
	unsafe public struct YKS_FollowGroupConfig
	{
		/// <summary>
		/// 坐标系序号
		/// </summary>
		[Description("坐标系序号")]
		public UInt32 group_index;

		/// <summary>
		/// 跟随模式
		/// </summary>
		[Description("跟随模式")]
		public YKE_AXIS_FOLLOW_MODE mode;

		/// <summary>
		/// 源数据
		/// </summary>
		[Description("源数据")]
		public YKE_FOLLOW_GROUP_TYPE source;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分子[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double numerator;

		/// <summary>
		/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分母[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double denominator;

		/// <summary>
		/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地编码器跟随配置
	/// </summary>
	unsafe public struct YKS_FollowEncoderConfig
	{
		/// <summary>
		/// 跟随曲线类型
		/// </summary>
		[Description("跟随曲线类型")]
		public YKE_AXIS_FOLLOW_MODE mode;

		/// <summary>
		/// 卡序号,默认为0
		/// </summary>
		[Description("卡序号,默认为0")]
		public UInt32 card_index;

		/// <summary>
		/// 编码器通道
		/// </summary>
		[Description("编码器通道")]
		public UInt32 encoder_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 编码器信号滤波时间[0,1000](ms)
		/// </summary>
		[Description("编码器信号滤波时间[0,1000](ms)")]
		public double filter_tim;

		/// <summary>
		/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分子[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double numerator;

		/// <summary>
		/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
		/// </summary>
		[Description("分母[DOUBLE_MIN,DOUBLE_MAX] 0除外")]
		public double denominator;

		/// <summary>
		/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 凸轮配置
	/// </summary>
	unsafe public struct YKS_CamInConfig
	{
		/// <summary>
		/// 数据表行数
		/// </summary>
		[Description("数据表行数")]
		public UInt32 count;

		/// <summary>
		/// 曲线类型
		/// </summary>
		[Description("曲线类型")]
		public YKE_CAM_CURVE curve;

		/// <summary>
		/// 主轴序号
		/// </summary>
		[Description("主轴序号")]
		public UInt32 axis_master;

		/// <summary>
		/// FALSE=单次运行 TRUE=周期运行
		/// </summary>
		[Description("FALSE=单次运行 TRUE=周期运行")]
		public YKE_BOOL periodic;

		/// <summary>
		/// 保留,固定写FALSE=相对模式
		/// </summary>
		[Description("保留,固定写FALSE=相对模式")]
		public YKE_BOOL master_absolute;

		/// <summary>
		/// 保留,固定写FALSE=相对模式
		/// </summary>
		[Description("保留,固定写FALSE=相对模式")]
		public YKE_BOOL slave_absolute;

		/// <summary>
		/// 主轴缩放系数[DOUBLE_MIN,DOUBLE_MAX]
		/// </summary>
		[Description("主轴缩放系数[DOUBLE_MIN,DOUBLE_MAX]")]
		public double master_scale;

		/// <summary>
		/// 从轴缩放系数[DOUBLE_MIN,DOUBLE_MAX]
		/// </summary>
		[Description("从轴缩放系数[DOUBLE_MIN,DOUBLE_MAX]")]
		public double slave_scale;

		/// <summary>
		/// 保留,默认写0
		/// </summary>
		[Description("保留,默认写0")]
		public double master_offset;

		/// <summary>
		/// 保留,默认写0
		/// </summary>
		[Description("保留,默认写0")]
		public double slave_offset;

		/// <summary>
		/// 启动距离[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("启动距离[0,DOUBLE_MAX](unit)")]
		public double start_distance;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 凸轮数据
	/// </summary>
	unsafe public struct YKS_CamTable
	{
		/// <summary>
		/// 主轴位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("主轴位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double master_position;

		/// <summary>
		/// 从轴位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("从轴位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double slave_position;

		/// <summary>
		/// 速度比例:多项式模式用[DOUBLE_MIN,DOUBLE_MAX]
		/// </summary>
		[Description("速度比例:多项式模式用[DOUBLE_MIN,DOUBLE_MAX]")]
		public double vel_rate;

		/// <summary>
		/// 加速度比例:多项式模式用[DOUBLE_MIN,DOUBLE_MAX]
		/// </summary>
		[Description("加速度比例:多项式模式用[DOUBLE_MIN,DOUBLE_MAX]")]
		public double acc_rate;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系设置,最大32轴
	/// </summary>
	unsafe public struct YKS_GroupConfig
	{
		/// <summary>
		/// 缓冲区深度[256,YKE_GROUP_DEPTH]
		/// </summary>
		[Description("缓冲区深度[256,YKE_GROUP_DEPTH]")]
		public UInt32 buffer_depth;

		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴序号列表,全局轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表,全局轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// CNC通道 FALSE=禁用  TRUE=启用
		/// </summary>
		[Description("CNC通道 FALSE=禁用  TRUE=启用")]
		public YKE_BOOL cnc_enable;

		/// <summary>
		/// CNC运行模式
		/// </summary>
		[Description("CNC运行模式")]
		public YKE_CNC_INS_MODE cnc_mode;

		/// <summary>
		/// 闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启
		/// </summary>
		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop0;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop1;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop2;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop3;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop4;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop5;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop6;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop7;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop8;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop9;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop10;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop11;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop12;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop13;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop14;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop15;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop16;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop17;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop18;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop19;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop20;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop21;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop22;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop23;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop24;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop25;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop26;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop27;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop28;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop29;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop30;

		[Description("闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启")]
		public YKE_BOOL close_loop31;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系配置
	/// </summary>
	unsafe public struct YKS_GroupProfile
	{
		/// <summary>
		/// 最高速度[0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("最高速度[0,DOUBLE_MAX](unit/s)")]
		public double max_velocity;

		/// <summary>
		/// 急停时的减速度[0,DOUBLE_MAX](unit/s^2),如碰限位,下使能等
		/// </summary>
		[Description("急停时的减速度[0,DOUBLE_MAX](unit/s^2),如碰限位,下使能等")]
		public double stop_dec_emg;

		/// <summary>
		/// 缓停时的减速度[0,DOUBLE_MAX](unit/s^2),如stop指令
		/// </summary>
		[Description("缓停时的减速度[0,DOUBLE_MAX](unit/s^2),如stop指令")]
		public double stop_dec_smooth;

		/// <summary>
		/// 停止时的变加速度[0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("停止时的变加速度[0,DOUBLE_MAX](unit/s^3)")]
		public double stop_dec_jerk;

		/// <summary>
		/// 发生报警时,输出端口的行为
		/// </summary>
		[Description("发生报警时,输出端口的行为")]
		public YKE_GROUP_OUTPUT_IN_WARN output_in_warm;

		/// <summary>
		/// 关联的急停通道号 按位定义
		/// </summary>
		[Description("关联的急停通道号 按位定义")]
		public UInt32 emg_mask;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内CNC配置
	/// </summary>
	unsafe public struct YKS_CncProfile
	{
		/// <summary>
		/// 进给倍率(0, 1500]
		/// </summary>
		[Description("进给倍率(0, 1500]")]
		public double feed_rate;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[16];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[16];
	}

	/// <summary>
	/// MARK坐标系转换
	/// </summary>
	unsafe public struct YKS_GroupTransMarkConfig
	{
		/// <summary>
		/// 旋转中心x(以图纸坐标为参考)
		/// </summary>
		[Description("旋转中心x(以图纸坐标为参考)")]
		public double rotate_x;

		/// <summary>
		/// 旋转中心y(以图纸坐标为参考)
		/// </summary>
		[Description("旋转中心y(以图纸坐标为参考)")]
		public double rotate_y;

		/// <summary>
		/// 原点偏移x(以图纸坐标为参考)
		/// </summary>
		[Description("原点偏移x(以图纸坐标为参考)")]
		public double offset_x;

		/// <summary>
		/// 原点偏移y(以图纸坐标为参考)
		/// </summary>
		[Description("原点偏移y(以图纸坐标为参考)")]
		public double offset_y;

		/// <summary>
		/// X方向涨缩比例(以图纸坐标为参考)
		/// </summary>
		[Description("X方向涨缩比例(以图纸坐标为参考)")]
		public double scale_x;

		/// <summary>
		/// Y方向涨缩比例(以图纸坐标为参考)
		/// </summary>
		[Description("Y方向涨缩比例(以图纸坐标为参考)")]
		public double scale_y;

		/// <summary>
		/// 旋转弧度(-PI~PI)
		/// </summary>
		[Description("旋转弧度(-PI~PI)")]
		public double angle;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 坐标系附加的XY输出
	/// </summary>
	unsafe public struct YKS_GroupAddiXYConfig
	{
		/// <summary>
		/// X轴序号
		/// </summary>
		[Description("X轴序号")]
		public UInt32 axis_x;

		/// <summary>
		/// Y轴序号
		/// </summary>
		[Description("Y轴序号")]
		public UInt32 axis_y;

		/// <summary>
		/// 坐标转换
		/// </summary>
		[Description("坐标转换")]
		public YKS_GroupTransMarkConfig trans_config;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 坐标系基本状态
	/// </summary>
	unsafe public struct YKS_GroupStatusBase
	{
		/// <summary>
		/// 运行主站
		/// </summary>
		[Description("运行主站")]
		public YKE_NODE master;

		/// <summary>
		/// 初始化状态  FALSE=未初始化 TRUE=已初始化
		/// </summary>
		[Description("初始化状态  FALSE=未初始化 TRUE=已初始化")]
		public YKE_BOOL inited;

		/// <summary>
		/// 运动状态   FALSE=未运动 TRUE=运动中
		/// </summary>
		[Description("运动状态   FALSE=未运动 TRUE=运动中")]
		public YKE_BOOL active;

		/// <summary>
		/// 指令完成状态 FALSE=未完成 TRUE=已完成
		/// </summary>
		[Description("指令完成状态 FALSE=未完成 TRUE=已完成")]
		public YKE_BOOL done;

		/// <summary>
		/// 报警标记 FALSE=无报警 TRUE=有报警
		/// </summary>
		[Description("报警标记 FALSE=无报警 TRUE=有报警")]
		public YKE_BOOL warnning;

		/// <summary>
		/// 暂停状态 FALSE:不是 TRUE:是
		/// </summary>
		[Description("暂停状态 FALSE:不是 TRUE:是")]
		public YKE_BOOL pause;

		/// <summary>
		/// 报警代码
		/// </summary>
		[Description("报警代码")]
		public YKE_MC_ERROR warn_id;

		/// <summary>
		/// 规划器报警代码
		/// </summary>
		[Description("规划器报警代码")]
		public UInt32 plan_warn;

		/// <summary>
		/// 软急停状态,按位定义
		/// </summary>
		[Description("软急停状态,按位定义")]
		public UInt32 soft_emg;

		/// <summary>
		/// 硬急停状态,按位定义
		/// </summary>
		[Description("硬急停状态,按位定义")]
		public UInt32 hard_emg;

		/// <summary>
		/// 运动缓冲区空闲数量[0,4096]
		/// </summary>
		[Description("运动缓冲区空闲数量[0,4096]")]
		public UInt32 buffer_idel;

		/// <summary>
		/// 当前运动行,从1开始[0,UINT32_MAX]
		/// </summary>
		[Description("当前运动行,从1开始[0,UINT32_MAX]")]
		public UInt32 running_line;

		/// <summary>
		/// 运动任务当前mark[0,UINT32_MAX]
		/// </summary>
		[Description("运动任务当前mark[0,UINT32_MAX]")]
		public UInt32 running_mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// XY已经移动的距离[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("XY已经移动的距离[0,DOUBLE_MAX](unit)")]
		public double distance_2d;

		/// <summary>
		/// XYZ已经移动的距离[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("XYZ已经移动的距离[0,DOUBLE_MAX](unit)")]
		public double distance_3d;

		/// <summary>
		/// XY当前合成速度[0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("XY当前合成速度[0,DOUBLE_MAX](unit/s)")]
		public double velocity_2d;

		/// <summary>
		/// XYZ当前合成速度[0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("XYZ当前合成速度[0,DOUBLE_MAX](unit/s)")]
		public double velocity_3d;

		/// <summary>
		/// 规划速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("规划速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)")]
		public double velocity_feed;

		/// <summary>
		/// 规划加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("规划加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)")]
		public double acceleration_feed;

		/// <summary>
		/// 规划运行时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("规划运行时间[0,DOUBLE_MAX](ms)")]
		public double command_time;

		/// <summary>
		/// 实际运行时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("实际运行时间[0,DOUBLE_MAX](ms)")]
		public double actual_time;

		/// <summary>
		/// 规划器类型
		/// </summary>
		[Description("规划器类型")]
		public UInt32 plann_type;

		/// <summary>
		/// 调试2
		/// </summary>
		[Description("调试2")]
		public UInt32 debug_phase;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[24];
	}

	/// <summary>
	/// 坐标系CNC模块状态, 须开启CNC选项
	/// </summary>
	unsafe public struct YKS_GroupStatusCnc
	{
		/// <summary>
		/// 工件坐标系下的XYZABC方向位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("工件坐标系下的XYZABC方向位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double workpiece_pos[6];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[24];
	}

	/// <summary>
	/// 坐标系直线插补,绝对模式
	/// </summary>
	unsafe public struct YKS_MoveLinearAbsoluteConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double position[32];

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res1;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 坐标系直线插补,相对模式
	/// </summary>
	unsafe public struct YKS_MoveLinearRelativeConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double distance[32];

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res1;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 坐标系螺旋插补,相对模式
	/// </summary>
	unsafe public struct YKS_MoveHelixRelativeConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 方向选择
		/// </summary>
		[Description("方向选择")]
		public YKE_CIRCULAR_PATH_CHOICE path_choice;

		/// <summary>
		/// 辅助点模式,仅圆心模式支持绽放/收敛螺旋线
		/// </summary>
		[Description("辅助点模式,仅圆心模式支持绽放/收敛螺旋线")]
		public YKE_CIRCULAR_AUX_MODE aux_mode;

		/// <summary>
		/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 distance;

		/// <summary>
		/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 aux_point;

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 圈数[0,UINT32_MAX]
		/// </summary>
		[Description("圈数[0,UINT32_MAX]")]
		public UInt32 circle;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 坐标系螺旋插补,绝对模式
	/// </summary>
	unsafe public struct YKS_MoveHelixAbsoluteConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 方向选择
		/// </summary>
		[Description("方向选择")]
		public YKE_CIRCULAR_PATH_CHOICE path_choice;

		/// <summary>
		/// 辅助点模式,仅支持圆心模式,支持绽放/收敛螺旋线
		/// </summary>
		[Description("辅助点模式,仅支持圆心模式,支持绽放/收敛螺旋线")]
		public YKE_CIRCULAR_AUX_MODE aux_mode;

		/// <summary>
		/// 终点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("终点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 end_point;

		/// <summary>
		/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 aux_point;

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 圈数[0,UINT32_MAX]
		/// </summary>
		[Description("圈数[0,UINT32_MAX]")]
		public UInt32 circle;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 坐标系圆弧插补,绝对模式
	/// </summary>
	unsafe public struct YKS_MoveCircularAbsoluteConfig
	{
		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 轴数量[2,3]
		/// </summary>
		[Description("轴数量[2,3]")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 终点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("终点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double position[32];

		/// <summary>
		/// 方向选择
		/// </summary>
		[Description("方向选择")]
		public YKE_CIRCULAR_PATH_CHOICE path_choice;

		/// <summary>
		/// 辅助点模式
		/// </summary>
		[Description("辅助点模式")]
		public YKE_CIRCULAR_AUX_MODE aux_mode;

		/// <summary>
		/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 aux_point;

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 坐标系圆弧插补,相对模式
	/// </summary>
	unsafe public struct YKS_MoveCircularRelativeConfig
	{
		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 轴数量[2,3]
		/// </summary>
		[Description("轴数量[2,3]")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double distance[32];

		/// <summary>
		/// 方向选择
		/// </summary>
		[Description("方向选择")]
		public YKE_CIRCULAR_PATH_CHOICE path_choice;

		/// <summary>
		/// 辅助点模式
		/// </summary>
		[Description("辅助点模式")]
		public YKE_CIRCULAR_AUX_MODE aux_mode;

		/// <summary>
		/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 aux_point;

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 坐标系Cardinal样条插补,相对模式
	/// </summary>
	unsafe public struct YKS_MoveCardinalRelativeConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double distance[32];

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res1;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 坐标系Cardinal样条插补,绝对模式
	/// </summary>
	unsafe public struct YKS_MoveCardinalAbsoluteConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double position[32];

		/// <summary>
		/// 运行速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("运行速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 加速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("加速度(0,DOUBLE_MAX](unit/s^2)")]
		public double acceleration;

		/// <summary>
		/// 减速度(0,DOUBLE_MAX](unit/s^2)
		/// </summary>
		[Description("减速度(0,DOUBLE_MAX](unit/s^2)")]
		public double deceleration;

		/// <summary>
		/// 变加速度(0,DOUBLE_MAX](unit/s^3)
		/// </summary>
		[Description("变加速度(0,DOUBLE_MAX](unit/s^3)")]
		public double jerk;

		/// <summary>
		/// 缓冲模式
		/// </summary>
		[Description("缓冲模式")]
		public YKE_BUFFER_MODE buffer_mode;

		/// <summary>
		/// 过渡模式
		/// </summary>
		[Description("过渡模式")]
		public YKE_TRANSITION_MODE trans_mode;

		/// <summary>
		/// 过度参数[0,DOUBLE_MAX](unit)
		/// </summary>
		[Description("过度参数[0,DOUBLE_MAX](unit)")]
		public YKS_POINT3 trans_para;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res1;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 轴信号等待条件
	/// </summary>
	unsafe public struct YKS_WaitAxis
	{
		/// <summary>
		/// 轴数量[1, 32]
		/// </summary>
		[Description("轴数量[1, 32]")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴列表
		/// </summary>
		[Description("轴列表")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 等待类型
		/// </summary>
		[Description("等待类型")]
		public YKE_AXIS_WAIT_TYPE type;

		/// <summary>
		/// 超时时间(ms),负数表示一直等待
		/// </summary>
		[Description("超时时间(ms),负数表示一直等待")]
		public double timeout;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 数字输入信号等待条件
	/// </summary>
	unsafe public struct YKS_WaitDigitalInput
	{
		/// <summary>
		/// 信号数量[1, 32]
		/// </summary>
		[Description("信号数量[1, 32]")]
		public UInt32 di_num;

		/// <summary>
		/// 字节序号
		/// </summary>
		[Description("字节序号")]
		public fixed UInt32 byte_offset[32];

		/// <summary>
		/// 位偏移
		/// </summary>
		[Description("位偏移")]
		public fixed UInt32 bit_offset[32];

		/// <summary>
		/// 等待类型
		/// </summary>
		[Description("等待类型")]
		public YKE_DIGITAL_INPUT_WAIT_TYPE type;

		/// <summary>
		/// 超时时间(ms),负数表示一直等待
		/// </summary>
		[Description("超时时间(ms),负数表示一直等待")]
		public double timeout;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 事件信号等待条件
	/// </summary>
	unsafe public struct YKS_WaitEvent
	{
		/// <summary>
		/// 事件数量[1,32]
		/// </summary>
		[Description("事件数量[1,32]")]
		public UInt32 event_num;

		/// <summary>
		/// 事件序号(0, YKE_EVENT_NUM]
		/// </summary>
		[Description("事件序号(0, YKE_EVENT_NUM]")]
		public fixed UInt32 event_index[32];

		/// <summary>
		/// 等待类型
		/// </summary>
		[Description("等待类型")]
		public YKE_EVENT_WAIT_TYPE type;

		/// <summary>
		/// 超时时间(ms),负数表示一直等待
		/// </summary>
		[Description("超时时间(ms),负数表示一直等待")]
		public double timeout;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 等待状态
	/// </summary>
	unsafe public struct YKS_WaitStatus
	{
		/// <summary>
		/// FALSE=空闲 TRUE=等待中
		/// </summary>
		[Description("FALSE=空闲 TRUE=等待中")]
		public YKE_BOOL active;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 已等待时间(ms)
		/// </summary>
		[Description("已等待时间(ms)")]
		public double time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 圆形区域保护配置
	/// </summary>
	unsafe public struct YKS_CircleZoneConfig
	{
		/// <summary>
		/// 轴数量,固定为2
		/// </summary>
		[Description("轴数量,固定为2")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴列表
		/// </summary>
		[Description("轴列表")]
		public fixed UInt32 axis_list[3];

		/// <summary>
		/// FALSE=使用规划位置 TRUE=使用反馈位置
		/// </summary>
		[Description("FALSE=使用规划位置 TRUE=使用反馈位置")]
		public YKE_BOOL use_feedback;

		/// <summary>
		/// FALSE=圆内区域有效 TRUE=圆外区域有效
		/// </summary>
		[Description("FALSE=圆内区域有效 TRUE=圆外区域有效")]
		public YKE_BOOL outside;

		/// <summary>
		/// 停止减速度选择
		/// </summary>
		[Description("停止减速度选择")]
		public YKE_STOP_DEC stop_dec;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 圆心位置
		/// </summary>
		[Description("圆心位置")]
		public fixed double center[3];

		/// <summary>
		/// 半径
		/// </summary>
		[Description("半径")]
		public double radius;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 圆形区域保护状态
	/// </summary>
	unsafe public struct YKS_CircleZoneStatus
	{
		/// <summary>
		/// FALSE=禁用 TRUE=启用
		/// </summary>
		[Description("FALSE=禁用 TRUE=启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// FALSE=有效区域 TRUE=无效区域
		/// </summary>
		[Description("FALSE=有效区域 TRUE=无效区域")]
		public YKE_BOOL invalid;
	}

	/// <summary>
	/// 本地PCI卡配置信息
	/// </summary>
	unsafe public struct YKS_CardConfigPCI
	{
		/// <summary>
		/// 0:T serial
		/// </summary>
		[Description("0:T serial")]
		public UInt32 type;

		/// <summary>
		/// 硬件版本
		/// </summary>
		[Description("硬件版本")]
		public UInt32 hardware_ver;

		/// <summary>
		/// 固件版本
		/// </summary>
		[Description("固件版本")]
		public UInt32 firmware_ver;

		/// <summary>
		/// 数字输入数量 (bit单位)
		/// </summary>
		[Description("数字输入数量 (bit单位)")]
		public UInt32 dinput_num;

		/// <summary>
		/// 数字输出数量 (bit单位)
		/// </summary>
		[Description("数字输出数量 (bit单位)")]
		public UInt32 doutput_num;

		/// <summary>
		/// 轴数量
		/// </summary>
		[Description("轴数量")]
		public UInt32 axis_num;

		/// <summary>
		/// 编码器数量
		/// </summary>
		[Description("编码器数量")]
		public UInt32 encode_num;

		/// <summary>
		/// 位置比较器数量
		/// </summary>
		[Description("位置比较器数量")]
		public UInt32 compare_num;

		/// <summary>
		/// 位置锁存器数量
		/// </summary>
		[Description("位置锁存器数量")]
		public UInt32 capture_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地PCI卡脉冲轴IO信息
	/// </summary>
	unsafe public struct YKS_AxisStausPCI
	{
		/// <summary>
		/// 脉冲口序号
		/// </summary>
		[Description("脉冲口序号")]
		public UInt32 pls_pin;

		/// <summary>
		/// 方向口序号
		/// </summary>
		[Description("方向口序号")]
		public UInt32 dir_pin;

		/// <summary>
		/// 脉冲模式
		/// </summary>
		[Description("脉冲模式")]
		public YKE_PULSE_MODE mode;

		/// <summary>
		/// 占空比 1~100
		/// </summary>
		[Description("占空比 1~100")]
		public UInt32 duty;

		/// <summary>
		/// 负限位状态  FALSE=无效 TRUE=有效
		/// </summary>
		[Description("负限位状态  FALSE=无效 TRUE=有效")]
		public YKE_BOOL switch_limit_negative;

		/// <summary>
		/// 正限位状态  FALSE=无效 TRUE=有效
		/// </summary>
		[Description("正限位状态  FALSE=无效 TRUE=有效")]
		public YKE_BOOL switch_limit_positive;

		/// <summary>
		/// 原点状态  FALSE=无效 TRUE=有效
		/// </summary>
		[Description("原点状态  FALSE=无效 TRUE=有效")]
		public YKE_BOOL switch_home;

		/// <summary>
		/// 驱动状态  FALSE=未准备好 TRUE=已准备好
		/// </summary>
		[Description("驱动状态  FALSE=未准备好 TRUE=已准备好")]
		public YKE_BOOL drv_ready;

		/// <summary>
		/// 驱动报警 FALSE=无报警 TRUE=有报警
		/// </summary>
		[Description("驱动报警 FALSE=无报警 TRUE=有报警")]
		public YKE_BOOL drv_warn;

		/// <summary>
		/// 驱动到位状态  FALSE=未到位 TRUE=已到位
		/// </summary>
		[Description("驱动到位状态  FALSE=未到位 TRUE=已到位")]
		public YKE_BOOL drv_inp;

		/// <summary>
		/// 驱动使能状态 FALSE=未使能 TRUE=已使能
		/// </summary>
		[Description("驱动使能状态 FALSE=未使能 TRUE=已使能")]
		public YKE_BOOL drv_enable;

		/// <summary>
		/// 驱动报警清除信号状态 FALSE=无效 TRUE=有效
		/// </summary>
		[Description("驱动报警清除信号状态 FALSE=无效 TRUE=有效")]
		public YKE_BOOL drv_reset;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地PCI高速卡编码器配置
	/// </summary>
	unsafe public struct YKS_EncoderConfig
	{
		/// <summary>
		/// 模式
		/// </summary>
		[Description("模式")]
		public YKE_ENCODER_MODE mode;

		/// <summary>
		/// A输入极性  FALSE=正极性 TRUE=负极性
		/// </summary>
		[Description("A输入极性  FALSE=正极性 TRUE=负极性")]
		public YKE_BOOL polarity_a;

		/// <summary>
		/// B输入极性  FALSE=正极性 TRUE=负极性
		/// </summary>
		[Description("B输入极性  FALSE=正极性 TRUE=负极性")]
		public YKE_BOOL polarity_b;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地PCI高速卡位置比较器配置
	/// </summary>
	unsafe public struct YKS_CompareConfig
	{
		/// <summary>
		/// 比较模式
		/// </summary>
		[Description("比较模式")]
		public YKE_COMPARE_MODE mode;

		/// <summary>
		/// 启用二维模式
		/// 未实现
		/// </summary>
		[Description("启用二维模式;未实现")]
		public YKE_BOOL enable_2d;

		/// <summary>
		/// 输出持续时间[0,10.23](ms); 最大10.23ms
		/// </summary>
		[Description("输出持续时间[0,10.23](ms); 最大10.23ms")]
		public double keep_time;

		/// <summary>
		/// 比较数量,线性模式用[0,511]  0=无限多
		/// </summary>
		[Description("比较数量,线性模式用[0,511]  0=无限多")]
		public UInt32 number;

		/// <summary>
		/// X方向间距,线性模式用[INT32_MIN,INT32_MAX](pulse)
		/// </summary>
		[Description("X方向间距,线性模式用[INT32_MIN,INT32_MAX](pulse)")]
		public Int32 spacing1;

		/// <summary>
		/// Y方向间距,线性模式用[INT32_MIN,INT32_MAX](pulse)
		/// </summary>
		[Description("Y方向间距,线性模式用[INT32_MIN,INT32_MAX](pulse)")]
		public Int32 spacing2;

		/// <summary>
		/// 输出0启用 FALSE=禁止输出 TRUE=允许输出
		/// </summary>
		[Description("输出0启用 FALSE=禁止输出 TRUE=允许输出")]
		public YKE_BOOL ena_bit0;

		/// <summary>
		/// 输出1启用 FALSE=禁止输出 TRUE=允许输出
		/// </summary>
		[Description("输出1启用 FALSE=禁止输出 TRUE=允许输出")]
		public YKE_BOOL ena_bit1;

		/// <summary>
		/// 输出2启用 FALSE=禁止输出 TRUE=允许输出
		/// </summary>
		[Description("输出2启用 FALSE=禁止输出 TRUE=允许输出")]
		public YKE_BOOL ena_bit2;

		/// <summary>
		/// 输出3启用 FALSE=禁止输出 TRUE=允许输出
		/// </summary>
		[Description("输出3启用 FALSE=禁止输出 TRUE=允许输出")]
		public YKE_BOOL ena_bit3;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[7];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 监控对象：轴
	/// </summary>
	unsafe public struct YKS_OscItemAxis
	{
		/// <summary>
		/// 轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 index;

		/// <summary>
		/// 轴数据选择
		/// </summary>
		[Description("轴数据选择")]
		public YKE_AXIS_ITEM_TYPE type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：坐标系
	/// </summary>
	unsafe public struct YKS_OscItemGroup
	{
		/// <summary>
		/// 坐标系序号[0,YKE_GROUP_NUM)
		/// </summary>
		[Description("坐标系序号[0,YKE_GROUP_NUM)")]
		public UInt32 index;

		/// <summary>
		/// 数据选择
		/// </summary>
		[Description("数据选择")]
		public YKE_GROUP_ITEM_TYPE type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：对象字典
	/// </summary>
	unsafe public struct YKS_OscItemSlaveObject
	{
		/// <summary>
		/// 主站选择
		/// </summary>
		[Description("主站选择")]
		public YKE_NODE node;

		/// <summary>
		/// 从站序号
		/// </summary>
		[Description("从站序号")]
		public UInt32 slave_index;

		/// <summary>
		/// COE对象字典,主索引
		/// </summary>
		[Description("COE对象字典,主索引")]
		public UInt32 main_index;

		/// <summary>
		/// COE对象字典,子索引
		/// </summary>
		[Description("COE对象字典,子索引")]
		public UInt32 sub_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：UG
	/// </summary>
	unsafe public struct YKS_OscItemSlaveUG
	{
		/// <summary>
		/// 主站选择
		/// </summary>
		[Description("主站选择")]
		public YKE_NODE node;

		/// <summary>
		/// 从站序号
		/// </summary>
		[Description("从站序号")]
		public UInt32 slave_index;

		/// <summary>
		/// G序号
		/// </summary>
		[Description("G序号")]
		public UInt32 g_index;

		/// <summary>
		/// FALSE=16bit模式 TRUE=32bit模式
		/// </summary>
		[Description("FALSE=16bit模式 TRUE=32bit模式")]
		public YKE_BOOL g_dword;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：数字输入
	/// </summary>
	unsafe public struct YKS_OscItemDI
	{
		/// <summary>
		/// 字节序号[0,512)
		/// </summary>
		[Description("字节序号[0,512)")]
		public UInt32 byte_index;

		/// <summary>
		/// 位偏移[0,7)
		/// </summary>
		[Description("位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：数字输出
	/// </summary>
	unsafe public struct YKS_OscItemDO
	{
		/// <summary>
		/// 字节序号[0,512)
		/// </summary>
		[Description("字节序号[0,512)")]
		public UInt32 byte_index;

		/// <summary>
		/// 位偏移[0,7)
		/// </summary>
		[Description("位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：通用寄存器
	/// </summary>
	unsafe public struct YKS_OscItemReg
	{
		/// <summary>
		/// 序号[0,YKE_GENDATA_SIZE)
		/// </summary>
		[Description("序号[0,YKE_GENDATA_SIZE)")]
		public UInt32 index;

		/// <summary>
		/// 数据类型
		/// </summary>
		[Description("数据类型")]
		public YKE_DATA_TYPE data_type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：系统信息
	/// </summary>
	unsafe public struct YKS_OscItemSystem
	{
		/// <summary>
		/// 主站选择
		/// </summary>
		[Description("主站选择")]
		public YKE_NODE node;

		/// <summary>
		/// 系统信息
		/// </summary>
		[Description("系统信息")]
		public YKE_SYSTEM_ITEM_TYPE type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：编码器
	/// </summary>
	unsafe public struct YKS_OscItemEncoder
	{
		/// <summary>
		/// 卡选择,默认0
		/// </summary>
		[Description("卡选择,默认0")]
		public UInt32 card_index;

		/// <summary>
		/// 序号
		/// </summary>
		[Description("序号")]
		public UInt32 encoder_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：事件
	/// </summary>
	unsafe public struct YKS_OscItemEvent
	{
		/// <summary>
		/// 事件序号[0,YKE_EVENT_NUM)
		/// </summary>
		[Description("事件序号[0,YKE_EVENT_NUM)")]
		public UInt32 index;

		/// <summary>
		/// 事件数据选择
		/// </summary>
		[Description("事件数据选择")]
		public YKE_EVENT_ITEM_TYPE type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：多轴联动
	/// </summary>
	unsafe public struct YKS_OscItemMultiAxis
	{
		/// <summary>
		/// 通道号[0,YKE_MULTI_AXIS_NUM)
		/// </summary>
		[Description("通道号[0,YKE_MULTI_AXIS_NUM)")]
		public UInt32 index;

		/// <summary>
		/// 数据选择
		/// </summary>
		[Description("数据选择")]
		public YKE_MULTI_AXIS_ITEM_TYPE type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象：等待事件
	/// </summary>
	unsafe public struct YKS_OscItemWait
	{
		/// <summary>
		/// 通道号[0,YKE_WAIT_NUM)
		/// </summary>
		[Description("通道号[0,YKE_WAIT_NUM)")]
		public UInt32 index;

		/// <summary>
		/// 数据选择
		/// </summary>
		[Description("数据选择")]
		public YKE_WAIT_ITEM_TYPE type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[2];
	}

	/// <summary>
	/// 监控对象
	/// </summary>
	unsafe public struct YKS_OscItem
	{
		/// <summary>
		/// FALSE=未启用 TRUE=启用
		/// </summary>
		[Description("FALSE=未启用 TRUE=启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// 采集类型
		/// </summary>
		[Description("采集类型")]
		public YKE_OSC_ITEM_TYPE type;

		/// <summary>
		/// 轴配置
		/// </summary>
		[Description("轴配置")]
		public YKS_OscItemAxis axis;

		/// <summary>
		/// 坐标系配置
		/// </summary>
		[Description("坐标系配置")]
		public YKS_OscItemGroup group;

		/// <summary>
		/// 对象字典配置
		/// </summary>
		[Description("对象字典配置")]
		public YKS_OscItemSlaveObject coe_obj;

		/// <summary>
		/// UG配置
		/// </summary>
		[Description("UG配置")]
		public YKS_OscItemSlaveUG ug;

		/// <summary>
		/// 数字输入配置
		/// </summary>
		[Description("数字输入配置")]
		public YKS_OscItemDI digital_input;

		/// <summary>
		/// 数字输出配置
		/// </summary>
		[Description("数字输出配置")]
		public YKS_OscItemDO digital_output;

		/// <summary>
		/// 通用数据寄存器
		/// </summary>
		[Description("通用数据寄存器")]
		public YKS_OscItemReg gen_data_reg;

		/// <summary>
		/// 系统信息
		/// </summary>
		[Description("系统信息")]
		public YKS_OscItemSystem sys_info;

		/// <summary>
		/// 编码器
		/// </summary>
		[Description("编码器")]
		public YKS_OscItemEncoder encoder;

		/// <summary>
		/// 事件
		/// </summary>
		[Description("事件")]
		public YKS_OscItemEvent sys_event;

		/// <summary>
		/// 多轴联动
		/// </summary>
		[Description("多轴联动")]
		public YKS_OscItemMultiAxis multi_axis;

		/// <summary>
		/// 等待事件
		/// </summary>
		[Description("等待事件")]
		public YKS_OscItemWait wait;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[24];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[24];
	}

	/// <summary>
	/// 打印日志其他配置
	/// </summary>
	unsafe public struct YKS_LoggerItemConfig
	{
		/// <summary>
		/// 单轴 TRUE=启用 FALSE=禁用
		/// </summary>
		[Description("单轴 TRUE=启用 FALSE=禁用")]
		public YKE_BOOL axis_enable;

		/// <summary>
		/// 单轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("单轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// 坐标系 TRUE=启用 FALSE=禁用
		/// </summary>
		[Description("坐标系 TRUE=启用 FALSE=禁用")]
		public YKE_BOOL group_enable;

		/// <summary>
		/// 坐标系序号[0,YKE_GROUP_NUM)
		/// </summary>
		[Description("坐标系序号[0,YKE_GROUP_NUM)")]
		public UInt32 group_index;

		/// <summary>
		/// 硬件卡通道 TRUE=启用 FALSE=禁用
		/// </summary>
		[Description("硬件卡通道 TRUE=启用 FALSE=禁用")]
		public YKE_BOOL card_enable;

		/// <summary>
		/// 硬件卡通道序号
		/// </summary>
		[Description("硬件卡通道序号")]
		public UInt32 card_index;

		/// <summary>
		/// ethercat从站 TRUE=启用 FALSE=禁用
		/// </summary>
		[Description("ethercat从站 TRUE=启用 FALSE=禁用")]
		public YKE_BOOL bus_enable;

		/// <summary>
		/// ethercat从站序号
		/// </summary>
		[Description("ethercat从站序号")]
		public UInt32 slave_index;

		/// <summary>
		/// 事件 TRUE=启用 FALSE=禁用
		/// </summary>
		[Description("事件 TRUE=启用 FALSE=禁用")]
		public YKE_BOOL event_enable;

		/// <summary>
		/// 事件序号[0,YKE_EVENT_NUM)
		/// </summary>
		[Description("事件序号[0,YKE_EVENT_NUM)")]
		public UInt32 event_index;

		/// <summary>
		/// 多轴联动  TRUE=启用 FALSE=禁用
		/// </summary>
		[Description("多轴联动  TRUE=启用 FALSE=禁用")]
		public YKE_BOOL multi_axis_enable;

		/// <summary>
		/// 多轴联动通道号[0,YKE_MULTI_AXIS_NUM)
		/// </summary>
		[Description("多轴联动通道号[0,YKE_MULTI_AXIS_NUM)")]
		public UInt32 multi_axis_index;

		/// <summary>
		/// 等待功能  TRUE=启用 FALSE=禁用
		/// </summary>
		[Description("等待功能  TRUE=启用 FALSE=禁用")]
		public YKE_BOOL wait_enable;

		/// <summary>
		/// 等待通道号[0,YKE_WAIT_NUM)
		/// </summary>
		[Description("等待通道号[0,YKE_WAIT_NUM)")]
		public UInt32 wait_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res2[8];
	}

	/// <summary>
	/// 日志配置
	/// </summary>
	unsafe public struct YKS_LoggerConfig
	{
		/// <summary>
		/// 文件路径
		/// </summary>
		[Description("文件路径")]
		public fixed sbyte file_path[512];

		/// <summary>
		/// 文件名,不带扩展名
		/// 间隔指定时间生成新的文件
		/// </summary>
		[Description("文件名,不带扩展名;间隔指定时间生成新的文件")]
		public fixed sbyte file_name[64];

		/// <summary>
		/// 生成新文件的间隔时间[0,DOUBLE_MAX](h)
		/// </summary>
		[Description("生成新文件的间隔时间[0,DOUBLE_MAX](h)")]
		public double interval;

		/// <summary>
		/// 数字输出指令 FALSE=不采集 TRUE=采集
		/// </summary>
		[Description("数字输出指令 FALSE=不采集 TRUE=采集")]
		public YKE_BOOL do_output;

		/// <summary>
		/// 用户数据 FALSE=不采集 TRUE=采集
		/// </summary>
		[Description("用户数据 FALSE=不采集 TRUE=采集")]
		public YKE_BOOL user_data;

		/// <summary>
		/// 返回值错误的指令 FALSE=不采集 TRUE=采集
		/// </summary>
		[Description("返回值错误的指令 FALSE=不采集 TRUE=采集")]
		public YKE_BOOL ret_ng;

		/// <summary>
		/// 返回值正常的指令 FALSE=不采集 TRUE=采集
		/// </summary>
		[Description("返回值正常的指令 FALSE=不采集 TRUE=采集")]
		public YKE_BOOL ret_ok;

		/// <summary>
		/// 为0的参数 FALSE=不采集 TRUE=采集
		/// </summary>
		[Description("为0的参数 FALSE=不采集 TRUE=采集")]
		public YKE_BOOL zero_value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[10];

		/// <summary>
		/// 采集过滤类型
		/// </summary>
		[Description("采集过滤类型")]
		public YKE_LOGGER_FILTER_TYPE filter_type;

		/// <summary>
		/// 采集配置
		/// </summary>
		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config0;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config1;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config2;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config3;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config4;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config5;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config6;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config7;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config8;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config9;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config10;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config11;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config12;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config13;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config14;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config15;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config16;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config17;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config18;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config19;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config20;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config21;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config22;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config23;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config24;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config25;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config26;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config27;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config28;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config29;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config30;

		[Description("采集配置")]
		public YKS_LoggerItemConfig item_config31;
	}

	/// <summary>
	/// 保留
	/// </summary>
	unsafe public struct YKS_ExcTrackItem
	{
		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 file;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 line;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public Int32 value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 tick;
	}

	/// <summary>
	/// 保留
	/// </summary>
	unsafe public struct YKS_ExcTrackConfig
	{
		/// <summary>
		/// 缓存数量
		/// </summary>
		[Description("缓存数量")]
		public UInt32 item_number;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public YKS_LoggerItemConfig item_config0;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config1;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config2;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config3;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config4;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config5;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config6;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config7;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config8;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config9;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config10;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config11;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config12;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config13;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config14;

		[Description("保留")]
		public YKS_LoggerItemConfig item_config15;
	}

	/// <summary>
	/// 软模式位置比较器配置
	/// </summary>
	unsafe public struct YKS_CompareConfigSoft
	{
		/// <summary>
		/// 比较模式
		/// </summary>
		[Description("比较模式")]
		public YKE_COMPARE_MODE mode;

		/// <summary>
		/// 启用二维模式,未实现
		/// </summary>
		[Description("启用二维模式,未实现")]
		public YKE_BOOL enable_2d;

		/// <summary>
		/// 比较源
		/// </summary>
		[Description("比较源")]
		public YKS_OscItem source;

		/// <summary>
		/// 比较数量:线性模式用[0,511] 0=无限多
		/// </summary>
		[Description("比较数量:线性模式用[0,511] 0=无限多")]
		public UInt32 number;

		/// <summary>
		/// 未使用
		/// </summary>
		[Description("未使用")]
		public UInt32 res;

		/// <summary>
		/// 输出0的值 FALSE=关 TRUE=开
		/// </summary>
		[Description("输出0的值 FALSE=关 TRUE=开")]
		public YKE_BOOL out0_enable;

		/// <summary>
		/// 输出0字节序号[0,512)
		/// </summary>
		[Description("输出0字节序号[0,512)")]
		public UInt32 out0_byte;

		/// <summary>
		/// 输出0位偏移[0,7)
		/// </summary>
		[Description("输出0位偏移[0,7)")]
		public UInt32 out0_offset;

		/// <summary>
		/// 输出1的值 FALSE=关 TRUE=开
		/// </summary>
		[Description("输出1的值 FALSE=关 TRUE=开")]
		public YKE_BOOL out1_enable;

		/// <summary>
		/// 输出1字节序号[0,512)
		/// </summary>
		[Description("输出1字节序号[0,512)")]
		public UInt32 out1_byte;

		/// <summary>
		/// 输出1位偏移[0,7)
		/// </summary>
		[Description("输出1位偏移[0,7)")]
		public UInt32 out1_offset;

		/// <summary>
		/// 输出2的值 FALSE=关 TRUE=开
		/// </summary>
		[Description("输出2的值 FALSE=关 TRUE=开")]
		public YKE_BOOL out2_enable;

		/// <summary>
		/// 输出2字节序号[0,512)
		/// </summary>
		[Description("输出2字节序号[0,512)")]
		public UInt32 out2_byte;

		/// <summary>
		/// 输出2位偏移[0,7)
		/// </summary>
		[Description("输出2位偏移[0,7)")]
		public UInt32 out2_offset;

		/// <summary>
		/// 输出3的值 FALSE=关 TRUE=开
		/// </summary>
		[Description("输出3的值 FALSE=关 TRUE=开")]
		public YKE_BOOL out3_enable;

		/// <summary>
		/// 输出3字节序号[0,512)
		/// </summary>
		[Description("输出3字节序号[0,512)")]
		public UInt32 out3_byte;

		/// <summary>
		/// 输出3位偏移[0,7)
		/// </summary>
		[Description("输出3位偏移[0,7)")]
		public UInt32 out3_offset;

		/// <summary>
		/// X方向间距,线性模式用[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("X方向间距,线性模式用[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double spacing1;

		/// <summary>
		/// Y方向间距,线性模式用 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("Y方向间距,线性模式用 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double spacing2;

		/// <summary>
		/// 比较值门限, 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("比较值门限, 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double threshold;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地PCI高速卡位置比较器比较数据
	/// </summary>
	unsafe public struct YKS_CompareItemData
	{
		/// <summary>
		/// 比较值1[INT32_MIN,INT_MAX](pulse)
		/// </summary>
		[Description("比较值1[INT32_MIN,INT_MAX](pulse)")]
		public Int32 value1;

		/// <summary>
		/// 比较值2, 二维模式有效[INT32_MIN,INT_MAX](pulse)
		/// </summary>
		[Description("比较值2, 二维模式有效[INT32_MIN,INT_MAX](pulse)")]
		public Int32 value2;

		/// <summary>
		/// 比较值门限(脉冲距离), 二维模式有效[INT32_MIN,INT_MAX](pulse)
		/// </summary>
		[Description("比较值门限(脉冲距离), 二维模式有效[INT32_MIN,INT_MAX](pulse)")]
		public UInt32 threshold;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 输出值0, Xmen无效 Tseries有效
		/// FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值0, Xmen无效 Tseries有效;FALSE=OFF TRUE=ON")]
		public YKE_BOOL out_bit0;

		/// <summary>
		/// 输出值1, Xmen无效 Tseries有效
		/// FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值1, Xmen无效 Tseries有效;FALSE=OFF TRUE=ON")]
		public YKE_BOOL out_bit1;

		/// <summary>
		/// 输出值2, Xmen无效 Tseries有效
		/// FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值2, Xmen无效 Tseries有效;FALSE=OFF TRUE=ON")]
		public YKE_BOOL out_bit2;

		/// <summary>
		/// 输出值3, Xmen无效 Tseries有效
		/// FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值3, Xmen无效 Tseries有效;FALSE=OFF TRUE=ON")]
		public YKE_BOOL out_bit3;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 软件模式位置比较器比较数据
	/// </summary>
	unsafe public struct YKS_CompareItemDataSoft
	{
		/// <summary>
		/// 比较值1[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("比较值1[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double cmp_value1;

		/// <summary>
		/// 比较值2, 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("比较值2, 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double cmp_value2;

		/// <summary>
		/// 输出值0 FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值0 FALSE=OFF TRUE=ON")]
		public YKE_BOOL out0_value;

		/// <summary>
		/// 输出值1 FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值1 FALSE=OFF TRUE=ON")]
		public YKE_BOOL out1_value;

		/// <summary>
		/// 输出值2 FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值2 FALSE=OFF TRUE=ON")]
		public YKE_BOOL out2_value;

		/// <summary>
		/// 输出值3 FALSE=OFF TRUE=ON
		/// </summary>
		[Description("输出值3 FALSE=OFF TRUE=ON")]
		public YKE_BOOL out3_value;

		/// <summary>
		/// 输出0保持时间[0,DOUBLE_MAX](ms)  0:一直保持
		/// </summary>
		[Description("输出0保持时间[0,DOUBLE_MAX](ms)  0:一直保持")]
		public double out0_time;

		/// <summary>
		/// 输出1保持时间[0,DOUBLE_MAX](ms)  0:一直保持
		/// </summary>
		[Description("输出1保持时间[0,DOUBLE_MAX](ms)  0:一直保持")]
		public double out1_time;

		/// <summary>
		/// 输出2保持时间[0,DOUBLE_MAX](ms)  0:一直保持
		/// </summary>
		[Description("输出2保持时间[0,DOUBLE_MAX](ms)  0:一直保持")]
		public double out2_time;

		/// <summary>
		/// 输出3保持时间[0,DOUBLE_MAX](ms)  0:一直保持
		/// </summary>
		[Description("输出3保持时间[0,DOUBLE_MAX](ms)  0:一直保持")]
		public double out3_time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地PCI高速卡位置比较器状态
	/// </summary>
	unsafe public struct YKS_CompareStatus
	{
		/// <summary>
		/// 数据队列头位置
		/// </summary>
		[Description("数据队列头位置")]
		public UInt32 que_head;

		/// <summary>
		/// 数据队列尾位置
		/// </summary>
		[Description("数据队列尾位置")]
		public UInt32 que_tail;

		/// <summary>
		/// 硬件缓冲区空闲数量
		/// </summary>
		[Description("硬件缓冲区空闲数量")]
		public UInt32 hd_idel;

		/// <summary>
		/// 硬件缓冲区待比较数量
		/// </summary>
		[Description("硬件缓冲区待比较数量")]
		public UInt32 hd_active;

		/// <summary>
		/// 已经完成的比较数量
		/// </summary>
		[Description("已经完成的比较数量")]
		public UInt32 hd_finish;

		/// <summary>
		/// 软件缓冲区空闲数量 线性模式无效
		/// </summary>
		[Description("软件缓冲区空闲数量 线性模式无效")]
		public UInt32 soft_idel;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 软件模式位置比较器状态
	/// </summary>
	unsafe public struct YKS_CompareStatusSoft
	{
		/// <summary>
		/// 数据队列头位置
		/// </summary>
		[Description("数据队列头位置")]
		public UInt32 que_head;

		/// <summary>
		/// 数据队列尾位置
		/// </summary>
		[Description("数据队列尾位置")]
		public UInt32 que_tail;

		/// <summary>
		/// 全部比较完成 FALSE=未完成  TRUE=已完成
		/// </summary>
		[Description("全部比较完成 FALSE=未完成  TRUE=已完成")]
		public YKE_BOOL finish;

		/// <summary>
		/// 比较成功的次数
		/// </summary>
		[Description("比较成功的次数")]
		public UInt32 success;

		/// <summary>
		/// 错误次数
		/// </summary>
		[Description("错误次数")]
		public UInt32 error_count;

		/// <summary>
		/// FALSE=空闲  TRUE=运行中
		/// </summary>
		[Description("FALSE=空闲  TRUE=运行中")]
		public YKE_BOOL active;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地PCI高速卡位置锁存配置
	/// </summary>
	unsafe public struct YKS_CaptureConfig
	{
		/// <summary>
		/// 锁存源选择
		/// </summary>
		[Description("锁存源选择")]
		public YKE_CAPTURE_SOURCE source_type;

		/// <summary>
		/// 沿选择 FALSE=上升沿 TRUE=下降沿
		/// </summary>
		[Description("沿选择 FALSE=上升沿 TRUE=下降沿")]
		public YKE_BOOL edge;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 本地PCI高速卡PWM输出配置
	/// </summary>
	unsafe public struct YKS_PwmConfig
	{
		/// <summary>
		/// 脉冲频率(Hz)
		/// </summary>
		[Description("脉冲频率(Hz)")]
		public double freq;

		/// <summary>
		/// 占空比, 0~1
		/// </summary>
		[Description("占空比, 0~1")]
		public double duty;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内数字输出配置
	/// </summary>
	unsafe public struct YKS_GroupDoConfig
	{
		/// <summary>
		/// 位置比较模式
		/// </summary>
		[Description("位置比较模式")]
		public YKE_GROUP_COMPARE_MODE cmp_mode;

		/// <summary>
		/// 输出模式
		/// </summary>
		[Description("输出模式")]
		public YKE_GROUP_DO_MODE out_mode;

		/// <summary>
		/// 数字输出字节序号[0,512)
		/// </summary>
		[Description("数字输出字节序号[0,512)")]
		public UInt32 byte_index;

		/// <summary>
		/// 数字输出位偏移[0,7)
		/// </summary>
		[Description("数字输出位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// 输出值 FALSE=关 TRUE=开
		/// </summary>
		[Description("输出值 FALSE=关 TRUE=开")]
		public YKE_BOOL value;

		/// <summary>
		/// 参考线段数量
		/// </summary>
		[Description("参考线段数量")]
		public UInt32 span;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 规划位置或实际位置选择
		/// </summary>
		[Description("规划位置或实际位置选择")]
		public YKE_AXIS_COMPARE_TYPE cmp_src;

		/// <summary>
		/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
		/// </summary>
		[Description("时间(ms)或者距离(unit)或者比率 与输出模式相关")]
		public double time_dist_rate;

		/// <summary>
		/// 单脉冲输出单位 FALSE=距离(unit) TRUE=时间(ms)
		/// </summary>
		[Description("单脉冲输出单位 FALSE=距离(unit) TRUE=时间(ms)")]
		public YKE_BOOL single_unit;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res2;

		/// <summary>
		/// 单脉冲模式下的持续距离(unit)或时间(ms)[0,DOUBLE_MAX]
		/// </summary>
		[Description("单脉冲模式下的持续距离(unit)或时间(ms)[0,DOUBLE_MAX]")]
		public double single_time_dist;

		/// <summary>
		/// 交替输出模式下的打开次数 0=无限次数
		/// </summary>
		[Description("交替输出模式下的打开次数 0=无限次数")]
		public UInt32 number;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 交替输出模式下输出为ON状态的距离(unit)或时间(ms)
		/// </summary>
		[Description("交替输出模式下输出为ON状态的距离(unit)或时间(ms)")]
		public double time_dist_on;

		/// <summary>
		/// 交替输出模式下输出为OFF的距离(unit)或时间(ms)
		/// </summary>
		[Description("交替输出模式下输出为OFF的距离(unit)或时间(ms)")]
		public double time_dist_off;

		/// <summary>
		/// 交替输出的单位 FALSE=距离(unit) TRUE=时间(ms)
		/// </summary>
		[Description("交替输出的单位 FALSE=距离(unit) TRUE=时间(ms)")]
		public YKE_BOOL alter_unit;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res3[8];
	}

	/// <summary>
	/// 坐标系内PWM输出配置
	/// </summary>
	unsafe public struct YKS_GroupPwmConfig
	{
		/// <summary>
		/// 位置比较模式
		/// </summary>
		[Description("位置比较模式")]
		public YKE_GROUP_COMPARE_MODE cmp_mode;

		/// <summary>
		/// 规划位置或实际位置选择
		/// </summary>
		[Description("规划位置或实际位置选择")]
		public YKE_AXIS_COMPARE_TYPE cmp_src;

		/// <summary>
		/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
		/// </summary>
		[Description("时间(ms)或者距离(unit)或者比率 与输出模式相关")]
		public double time_dist_rate;

		/// <summary>
		/// 参考线段数量
		/// </summary>
		[Description("参考线段数量")]
		public UInt32 span;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 跟随模式
		/// </summary>
		[Description("跟随模式")]
		public YKE_GROUP_PWM_MODE pwm_mode;

		/// <summary>
		/// 卡序号,固定为0
		/// </summary>
		[Description("卡序号,固定为0")]
		public UInt32 card_index;

		/// <summary>
		/// 脉冲序号
		/// </summary>
		[Description("脉冲序号")]
		public UInt32 index;

		/// <summary>
		/// 输出值 FLASE=关 TRUE=开
		/// </summary>
		[Description("输出值 FLASE=关 TRUE=开")]
		public YKE_BOOL value;

		/// <summary>
		/// 速度滤波时间(ms)
		/// </summary>
		[Description("速度滤波时间(ms)")]
		public double filter_tim;

		/// <summary>
		/// 频率(Hz)
		/// </summary>
		[Description("频率(Hz)")]
		public double freq_value;

		/// <summary>
		/// 占空比
		/// </summary>
		[Description("占空比")]
		public double duty_value;

		/// <summary>
		/// 跟随模式下频率和速度的比例
		/// </summary>
		[Description("跟随模式下频率和速度的比例")]
		public double freq_scale;

		/// <summary>
		/// 跟随模式下占空比和速度的比例
		/// </summary>
		[Description("跟随模式下占空比和速度的比例")]
		public double duty_scale;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内PDO写入配置
	/// </summary>
	unsafe public struct YKS_GroupWritePdoConfig
	{
		/// <summary>
		/// 比较模式
		/// </summary>
		[Description("比较模式")]
		public YKE_GROUP_COMPARE_MODE cmp_mode;

		/// <summary>
		/// 规划位置或实际位置选择
		/// </summary>
		[Description("规划位置或实际位置选择")]
		public YKE_AXIS_COMPARE_TYPE cmp_src;

		/// <summary>
		/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
		/// </summary>
		[Description("时间(ms)或者距离(unit)或者比率 与输出模式相关")]
		public double time_dist_rate;

		/// <summary>
		/// 参考线段数量
		/// </summary>
		[Description("参考线段数量")]
		public UInt32 span;

		/// <summary>
		/// 识别码
		/// </summary>
		[Description("识别码")]
		public UInt32 mark;

		/// <summary>
		/// 主站选择
		/// </summary>
		[Description("主站选择")]
		public YKE_NODE master;

		/// <summary>
		/// 从站序号
		/// </summary>
		[Description("从站序号")]
		public UInt32 slave_index;

		/// <summary>
		/// 主索引
		/// </summary>
		[Description("主索引")]
		public UInt32 main_index;

		/// <summary>
		/// 子索引
		/// </summary>
		[Description("子索引")]
		public UInt32 sub_index;

		/// <summary>
		/// 数据类型
		/// </summary>
		[Description("数据类型")]
		public YKE_DATA_TYPE data_type;

		/// <summary>
		/// 写入值
		/// </summary>
		[Description("写入值")]
		public UInt32 value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内寄存器写入配置
	/// </summary>
	unsafe public struct YKS_GroupWriteRegisterConfig
	{
		/// <summary>
		/// 比较模式
		/// </summary>
		[Description("比较模式")]
		public YKE_GROUP_COMPARE_MODE cmp_mode;

		/// <summary>
		/// 规划位置或实际位置选择
		/// </summary>
		[Description("规划位置或实际位置选择")]
		public YKE_AXIS_COMPARE_TYPE cmp_src;

		/// <summary>
		/// 寄存器序号[0,YKE_GENDATA_SIZE)
		/// </summary>
		[Description("寄存器序号[0,YKE_GENDATA_SIZE)")]
		public UInt32 index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
		/// </summary>
		[Description("时间(ms)或者距离(unit)或者比率 与输出模式相关")]
		public double time_dist_rate;

		/// <summary>
		/// 参考线段数量
		/// </summary>
		[Description("参考线段数量")]
		public UInt32 span;

		/// <summary>
		/// 识别码
		/// </summary>
		[Description("识别码")]
		public UInt32 mark;

		/// <summary>
		/// 数据类型
		/// </summary>
		[Description("数据类型")]
		public YKE_DATA_TYPE data_type;

		/// <summary>
		/// 写入值
		/// </summary>
		[Description("写入值")]
		public UInt32 value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内启动事件配置
	/// </summary>
	unsafe public struct YKS_GroupWriteEventConfig
	{
		/// <summary>
		/// 比较模式
		/// </summary>
		[Description("比较模式")]
		public YKE_GROUP_COMPARE_MODE cmp_mode;

		/// <summary>
		/// 规划位置或实际位置选择
		/// </summary>
		[Description("规划位置或实际位置选择")]
		public YKE_AXIS_COMPARE_TYPE cmp_src;

		/// <summary>
		/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
		/// </summary>
		[Description("时间(ms)或者距离(unit)或者比率 与输出模式相关")]
		public double time_dist_rate;

		/// <summary>
		/// 参考线段数量
		/// </summary>
		[Description("参考线段数量")]
		public UInt32 span;

		/// <summary>
		/// 识别码
		/// </summary>
		[Description("识别码")]
		public UInt32 mark;

		/// <summary>
		/// 事件序号[0,YKE_EVENT_NUM)
		/// </summary>
		[Description("事件序号[0,YKE_EVENT_NUM)")]
		public UInt32 index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系外轴绝对运动配置
	/// </summary>
	unsafe public struct YKS_GroupMoveAbsoluteConfig
	{
		/// <summary>
		/// 位置比较模式
		/// </summary>
		[Description("位置比较模式")]
		public YKE_GROUP_COMPARE_MODE cmp_mode;

		/// <summary>
		/// 规划位置或实际位置选择
		/// </summary>
		[Description("规划位置或实际位置选择")]
		public YKE_AXIS_COMPARE_TYPE cmp_src;

		/// <summary>
		/// 时间(毫秒单位)或者距离(用户单位)或者比率 与输出模式相关
		/// </summary>
		[Description("时间(毫秒单位)或者距离(用户单位)或者比率 与输出模式相关")]
		public double time_dist_rate;

		/// <summary>
		/// 参考线段数量
		/// </summary>
		[Description("参考线段数量")]
		public UInt32 span;

		/// <summary>
		/// 识别码
		/// </summary>
		[Description("识别码")]
		public UInt32 mark;

		/// <summary>
		/// 轴序号
		/// </summary>
		[Description("轴序号")]
		public UInt32 axis_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 运动配置
		/// </summary>
		[Description("运动配置")]
		public YKS_MoveAbsoluteConfig movabs;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res1[8];
	}

	/// <summary>
	/// 坐标系外轴相对运动配置
	/// </summary>
	unsafe public struct YKS_GroupMoveRelativeConfig
	{
		/// <summary>
		/// 位置比较模式
		/// </summary>
		[Description("位置比较模式")]
		public YKE_GROUP_COMPARE_MODE cmp_mode;

		/// <summary>
		/// 规划位置或实际位置选择
		/// </summary>
		[Description("规划位置或实际位置选择")]
		public YKE_AXIS_COMPARE_TYPE cmp_src;

		/// <summary>
		/// 时间(毫秒单位)或者距离(用户单位)或者比率 与输出模式相关
		/// </summary>
		[Description("时间(毫秒单位)或者距离(用户单位)或者比率 与输出模式相关")]
		public double time_dist_rate;

		/// <summary>
		/// 参考线段数量
		/// </summary>
		[Description("参考线段数量")]
		public UInt32 span;

		/// <summary>
		/// 识别码
		/// </summary>
		[Description("识别码")]
		public UInt32 mark;

		/// <summary>
		/// 轴序号
		/// </summary>
		[Description("轴序号")]
		public UInt32 axis_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 运动配置
		/// </summary>
		[Description("运动配置")]
		public YKS_MoveRelativeConfig movinc;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res1[8];
	}

	/// <summary>
	/// 坐标系内延时配置
	/// </summary>
	unsafe public struct YKS_GroupDelayConfig
	{
		/// <summary>
		/// 延时时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("延时时间[0,DOUBLE_MAX](ms)")]
		public double delay_ms;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内等待数字输入配置
	/// </summary>
	unsafe public struct YKS_GroupDigitalInputConfig
	{
		/// <summary>
		/// 数字输入字节序号[0,512)
		/// </summary>
		[Description("数字输入字节序号[0,512)")]
		public UInt32 byte_index;

		/// <summary>
		/// 数字输入位偏移[0,7)
		/// </summary>
		[Description("数字输入位偏移[0,7)")]
		public UInt32 bit_offset;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// 标记[0,UINT32_MAX]
		/// </summary>
		[Description("标记[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内等待外轴运动完成
	/// </summary>
	unsafe public struct YKS_GroupWaitAxisConfig
	{
		/// <summary>
		/// 轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// 等待信号
		/// </summary>
		[Description("等待信号")]
		public YKE_AXIS_ITEM_TYPE item_type;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 触发值
		/// </summary>
		[Description("触发值")]
		public double trig_value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内等待PDO值
	/// </summary>
	unsafe public struct YKS_GroupWaitPdoConfig
	{
		/// <summary>
		/// 主站选择
		/// </summary>
		[Description("主站选择")]
		public YKE_NODE master;

		/// <summary>
		/// 从站序号
		/// </summary>
		[Description("从站序号")]
		public UInt32 slave_index;

		/// <summary>
		/// 主索引
		/// </summary>
		[Description("主索引")]
		public UInt32 main_index;

		/// <summary>
		/// 子索引
		/// </summary>
		[Description("子索引")]
		public UInt32 sub_index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// 数据类型
		/// </summary>
		[Description("数据类型")]
		public YKE_DATA_TYPE data_type;

		/// <summary>
		/// 等待值
		/// </summary>
		[Description("等待值")]
		public UInt32 value;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内等待寄存器值
	/// </summary>
	unsafe public struct YKS_GroupWaitRegisterConfig
	{
		/// <summary>
		/// 寄存器序号[0,YKE_GENDATA_SIZE)
		/// </summary>
		[Description("寄存器序号[0,YKE_GENDATA_SIZE)")]
		public UInt32 index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// 数据类型
		/// </summary>
		[Description("数据类型")]
		public YKE_DATA_TYPE data_type;

		/// <summary>
		/// 等待值
		/// </summary>
		[Description("等待值")]
		public UInt32 value;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 坐标系内等待事件
	/// </summary>
	unsafe public struct YKS_GroupWaitEventConfig
	{
		/// <summary>
		/// 事件通道号[0,YKE_EVENT_NUM)
		/// </summary>
		[Description("事件通道号[0,YKE_EVENT_NUM)")]
		public UInt32 index;

		/// <summary>
		/// 等待信号
		/// </summary>
		[Description("等待信号")]
		public YKE_EVENT_WAIT_TYPE type;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// Cardinal样条配置
	/// </summary>
	unsafe public struct YKS_GroupCardinalConfig
	{
		/// <summary>
		/// 张力系数(0,1)
		/// </summary>
		[Description("张力系数(0,1)")]
		public double tensive;

		/// <summary>
		/// 识别码[0,UINT32_MAX]
		/// </summary>
		[Description("识别码[0,UINT32_MAX]")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 示波器监控数据配置
	/// </summary>
	unsafe public struct YKS_OscConfig
	{
		/// <summary>
		/// 采集点数(0,80000]
		/// </summary>
		[Description("采集点数(0,80000]")]
		public UInt32 depth;

		/// <summary>
		/// 采样周期间隔(0,UINT32_MAX],以采样单位为基准
		/// </summary>
		[Description("采样周期间隔(0,UINT32_MAX],以采样单位为基准")]
		public UInt32 interval;

		/// <summary>
		/// 采样单位 FALSE=运动周期 TRUE=PLC周期
		/// </summary>
		[Description("采样单位 FALSE=运动周期 TRUE=PLC周期")]
		public YKE_BOOL unit;

		/// <summary>
		/// 触发通道[0,YKE_OSC_ITEM_NUM)
		/// </summary>
		[Description("触发通道[0,YKE_OSC_ITEM_NUM)")]
		public UInt32 trig_ch;

		/// <summary>
		/// 触发阀值[DOUBLE_MIN,DOUBLE_MAX]
		/// </summary>
		[Description("触发阀值[DOUBLE_MIN,DOUBLE_MAX]")]
		public double trig_val;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_OSC_TRIG_TYPE trig_mode;

		/// <summary>
		/// 触发位置[0,100]
		/// </summary>
		[Description("触发位置[0,100]")]
		public UInt32 trig_pos;

		/// <summary>
		/// 触发次数 FALSE=单次触发 TRUE=重复触发
		/// </summary>
		[Description("触发次数 FALSE=单次触发 TRUE=重复触发")]
		public YKE_BOOL trig_once;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 示波器采集状态
	/// </summary>
	unsafe public struct YKS_OscStatus
	{
		/// <summary>
		/// 触发状态 FALSE=未触发 TRUE=已经触发
		/// </summary>
		[Description("触发状态 FALSE=未触发 TRUE=已经触发")]
		public YKE_BOOL trig_flag;

		/// <summary>
		/// 触发位置
		/// </summary>
		[Description("触发位置")]
		public UInt32 trig_index;

		/// <summary>
		/// 触发后的剩余采集次数
		/// </summary>
		[Description("触发后的剩余采集次数")]
		public UInt32 remain;

		/// <summary>
		/// 触发后数据采集状态 FALSE=未完成 TRUE=已完成
		/// </summary>
		[Description("触发后数据采集状态 FALSE=未完成 TRUE=已完成")]
		public YKE_BOOL finish;

		/// <summary>
		/// 采集环形缓冲区大小(double)
		/// </summary>
		[Description("采集环形缓冲区大小(double)")]
		public UInt32 buff_size;

		/// <summary>
		/// 缓冲区有效数据数量(double)
		/// </summary>
		[Description("缓冲区有效数据数量(double)")]
		public UInt32 buff_valid;

		/// <summary>
		/// FALSE=数据未溢出 TRUE=数据有溢出
		/// </summary>
		[Description("FALSE=数据未溢出 TRUE=数据有溢出")]
		public YKE_BOOL over_flow;

		/// <summary>
		/// 示波器内轴通道报警状态
		/// 按位定义 0=无报警 1=有报警
		/// </summary>
		[Description("示波器内轴通道报警状态;按位定义 0=无报警 1=有报警")]
		public YKE_BOOL axis_warn;

		/// <summary>
		/// 采集主站的总线周期(ms)
		/// </summary>
		[Description("采集主站的总线周期(ms)")]
		public double master_period;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 数字IO关联的硬件信息
	/// </summary>
	unsafe public struct YKS_DigitalIOHardInfo
	{
		/// <summary>
		/// TRUE=有效序号 FALSE=不存在的序号
		/// </summary>
		[Description("TRUE=有效序号 FALSE=不存在的序号")]
		public YKE_BOOL valid;

		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// IO类型
		/// </summary>
		[Description("IO类型")]
		public YKE_DIO_PHY type;

		/// <summary>
		/// 总线站号
		/// </summary>
		[Description("总线站号")]
		public UInt32 index1;

		/// <summary>
		/// 网关内序号
		/// </summary>
		[Description("网关内序号")]
		public UInt32 index2;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 软限位设置
	/// </summary>
	unsafe public struct YKS_AxisSoftLimitConfig
	{
		/// <summary>
		/// 正软限位位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("正软限位位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double positive;

		/// <summary>
		/// 负软限位位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("负软限位位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double negative;

		/// <summary>
		/// FALSE=禁用 TRUE=启用
		/// </summary>
		[Description("FALSE=禁用 TRUE=启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 硬限位启用
	/// </summary>
	unsafe public struct YKS_AxisHardLimitConfig
	{
		/// <summary>
		/// 正向硬限位
		/// FALSE=禁用 TRUE=启用
		/// </summary>
		[Description("正向硬限位;FALSE=禁用 TRUE=启用")]
		public YKE_BOOL enable_positive;

		/// <summary>
		/// 负向硬限位
		/// FALSE=禁用 TRUE=启用
		/// </summary>
		[Description("负向硬限位;FALSE=禁用 TRUE=启用")]
		public YKE_BOOL enable_negative;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];
	}

	/// <summary>
	/// 多轴直线插补运动,相对模式
	/// </summary>
	unsafe public struct YKS_LinearInterpolationRelativeConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴序号列表[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double distance[32];

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 延时指定时间后(相对启动时刻)启动变参数 [0,DOUBLE_MAX](ms) 保留
		/// </summary>
		[Description("延时指定时间后(相对启动时刻)启动变参数 [0,DOUBLE_MAX](ms) 保留")]
		public double change_tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 多轴直线插补运动,绝对模式
	/// </summary>
	unsafe public struct YKS_LinearInterpolationAbsoluteConfig
	{
		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴序号列表[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double position[32];

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 延时指定时间后(相对启动时刻)启动变参数
		/// </summary>
		[Description("延时指定时间后(相对启动时刻)启动变参数")]
		public double change_tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 多轴直线同步运动,相对模式
	/// </summary>
	unsafe public struct YKS_LinearSyncRelativeConfig
	{
		/// <summary>
		/// 同步模式
		/// </summary>
		[Description("同步模式")]
		public YKE_SYNC_AXIS_MODE sync_mode;

		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴序号列表[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double distance[32];

		/// <summary>
		/// 延时指定时间后(相对启动时刻)启动变参数
		/// </summary>
		[Description("延时指定时间后(相对启动时刻)启动变参数")]
		public double change_tim;

		/// <summary>
		/// 指定运行时间 YKE_SYNC_FIX_TIME使用
		/// </summary>
		[Description("指定运行时间 YKE_SYNC_FIX_TIME使用")]
		public double run_time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 多轴直线同步运动,绝对模式
	/// </summary>
	unsafe public struct YKS_LinearSyncAbsoluteConfig
	{
		/// <summary>
		/// 同步模式
		/// </summary>
		[Description("同步模式")]
		public YKE_SYNC_AXIS_MODE sync_mode;

		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴序号列表[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double position[32];

		/// <summary>
		/// 延时指定时间后(相对启动时刻)启动变参数
		/// </summary>
		[Description("延时指定时间后(相对启动时刻)启动变参数")]
		public double change_tim;

		/// <summary>
		/// 指定运行时间(ms) YKE_SYNC_FIX_TIME模式使用
		/// </summary>
		[Description("指定运行时间(ms) YKE_SYNC_FIX_TIME模式使用")]
		public double run_time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 多轴同时启动
	/// </summary>
	unsafe public struct YKS_SyncStartConfig
	{
		/// <summary>
		/// 同步模式
		/// </summary>
		[Description("同步模式")]
		public YKE_SYNC_AXIS_MODE sync_mode;

		/// <summary>
		/// 轴数量[2,YKE_MULTI_AXIS_NUM]
		/// </summary>
		[Description("轴数量[2,YKE_MULTI_AXIS_NUM]")]
		public UInt32 axis_num;

		/// <summary>
		/// 轴序号列表[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public fixed double position[32];

		/// <summary>
		/// 延时指定时间后(相对启动时刻)启动变参数
		/// </summary>
		[Description("延时指定时间后(相对启动时刻)启动变参数")]
		public double change_tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 圆弧插补,相对模式
	/// </summary>
	unsafe public struct YKS_CircularInterpolationRelativeConfig
	{
		/// <summary>
		/// 轴数量[2,3]
		/// </summary>
		[Description("轴数量[2,3]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴序号列表[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 distance;

		/// <summary>
		/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 aux_point;

		/// <summary>
		/// 方向选择
		/// </summary>
		[Description("方向选择")]
		public YKE_CIRCULAR_PATH_CHOICE path_choice;

		/// <summary>
		/// 辅助点模式
		/// </summary>
		[Description("辅助点模式")]
		public YKE_CIRCULAR_AUX_MODE aux_mode;

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// 圆弧插补,绝对模式
	/// </summary>
	unsafe public struct YKS_CircularInterpolationAbsoluteConfig
	{
		/// <summary>
		/// 轴数量[2,3]
		/// </summary>
		[Description("轴数量[2,3]")]
		public UInt32 axis_num;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 轴序号列表[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号列表[0,YKE_AXIS_NUM)")]
		public fixed UInt32 axis_list[32];

		/// <summary>
		/// 终点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("终点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 end_point;

		/// <summary>
		/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public YKS_POINT3 aux_point;

		/// <summary>
		/// 方向选择
		/// </summary>
		[Description("方向选择")]
		public YKE_CIRCULAR_PATH_CHOICE path_choice;

		/// <summary>
		/// 辅助点模式
		/// </summary>
		[Description("辅助点模式")]
		public YKE_CIRCULAR_AUX_MODE aux_mode;

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[4];
	}

	/// <summary>
	/// 探针配置
	/// </summary>
	unsafe public struct YKS_ProbeConfigSoft
	{
		/// <summary>
		/// 数字输入
		/// </summary>
		[Description("数字输入")]
		public YKS_DigitalIO input;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 捕获对象
		/// </summary>
		[Description("捕获对象")]
		public YKS_OscItem item;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 探针状态
	/// </summary>
	unsafe public struct YKS_ProbeStatusSoft
	{
		/// <summary>
		/// 激活状态 FALSE=未激活  TRUE=已激活
		/// </summary>
		[Description("激活状态 FALSE=未激活  TRUE=已激活")]
		public YKE_BOOL active;

		/// <summary>
		/// 探针值状态 FALSE=无效  TRUE=有效
		/// </summary>
		[Description("探针值状态 FALSE=无效  TRUE=有效")]
		public YKE_BOOL valid;

		/// <summary>
		/// 探针值
		/// </summary>
		[Description("探针值")]
		public double value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[4];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[4];
	}

	/// <summary>
	/// 触发配置
	/// </summary>
	unsafe public struct YKS_AxisTrigger
	{
		/// <summary>
		/// 触发条件参考的轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("触发条件参考的轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// 触发类型
		/// </summary>
		[Description("触发类型")]
		public YKE_TRIGGER_TYPE type;

		/// <summary>
		/// 触发值
		/// </summary>
		[Description("触发值")]
		public double value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 轴触发状态
	/// </summary>
	unsafe public struct YKS_AxisTriggerStatus
	{
		/// <summary>
		/// FALSE=空闲 TRUE=等待触发
		/// </summary>
		[Description("FALSE=空闲 TRUE=等待触发")]
		public YKE_BOOL active;

		/// <summary>
		/// 触发参考轴[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("触发参考轴[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// 触发类型
		/// </summary>
		[Description("触发类型")]
		public YKE_TRIGGER_TYPE type;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 触发值
		/// </summary>
		[Description("触发值")]
		public double value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res2[8];
	}

	/// <summary>
	/// 单信号触发参数
	/// </summary>
	unsafe public struct YKS_TriggerArgOneSignal
	{
		/// <summary>
		/// 信号源选择
		/// </summary>
		[Description("信号源选择")]
		public YKE_SIGNAL_SOURCE_TYPE type;

		/// <summary>
		/// 事件或寄存器序号 YKE_SIGNAL_SOURCE_EVENT/YKE_SIGNAL_SOURCE_REG使用
		/// </summary>
		[Description("事件或寄存器序号 YKE_SIGNAL_SOURCE_EVENT/YKE_SIGNAL_SOURCE_REG使用")]
		public UInt32 index;

		/// <summary>
		/// IO序号 YKE_SIGNAL_SOURCE_INPUT/YKE_SIGNAL_SOURCE_OUTPUT使用
		/// </summary>
		[Description("IO序号 YKE_SIGNAL_SOURCE_INPUT/YKE_SIGNAL_SOURCE_OUTPUT使用")]
		public YKS_DigitalIO inout;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 双信号触发参数
	/// </summary>
	unsafe public struct YKS_TriggerArgTwoSignal
	{
		/// <summary>
		/// 号源1
		/// </summary>
		[Description("号源1")]
		public YKE_SIGNAL_SOURCE_TYPE type1;

		/// <summary>
		/// 信号源2
		/// </summary>
		[Description("信号源2")]
		public YKE_SIGNAL_SOURCE_TYPE type2;

		/// <summary>
		/// IO1序号
		/// </summary>
		[Description("IO1序号")]
		public YKS_DigitalIO inout1;

		/// <summary>
		/// IO1序号
		/// </summary>
		[Description("IO1序号")]
		public YKS_DigitalIO inout2;

		/// <summary>
		/// 事件1或寄存器1序号
		/// </summary>
		[Description("事件1或寄存器1序号")]
		public UInt32 index1;

		/// <summary>
		/// 事件2或寄存器2序号
		/// </summary>
		[Description("事件2或寄存器2序号")]
		public UInt32 index2;

		/// <summary>
		/// 运算逻辑
		/// </summary>
		[Description("运算逻辑")]
		public YKE_LOGIC_CONDITIONS op_logic;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 轴位置条件触发
	/// </summary>
	unsafe public struct YKS_TriggerArgAxisPosition
	{
		/// <summary>
		/// 轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// TRUE=当指定轴静止或正向运动时不会触发输出
		/// </summary>
		[Description("TRUE=当指定轴静止或正向运动时不会触发输出")]
		public YKE_BOOL disable_positive_direction;

		/// <summary>
		/// TRUE=当指定轴静止或负向运动时不会触发输出
		/// </summary>
		[Description("TRUE=当指定轴静止或负向运动时不会触发输出")]
		public YKE_BOOL disable_negative_direction;

		/// <summary>
		/// FALSE=监控规划位置 TRUE=监控实际位置
		/// </summary>
		[Description("FALSE=监控规划位置 TRUE=监控实际位置")]
		public YKE_BOOL use_feedback;

		/// <summary>
		/// TRUE=此输入功能逻辑取反 FALSE=不取反
		/// </summary>
		[Description("TRUE=此输入功能逻辑取反 FALSE=不取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 触发时的位置
		/// </summary>
		[Description("触发时的位置")]
		public double position;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 轴时间条件触发
	/// </summary>
	unsafe public struct YKS_TriggerArgAxisTime
	{
		/// <summary>
		/// 轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// FALSE=使用已运行时间 TRUE=使用剩余时间
		/// </summary>
		[Description("FALSE=使用已运行时间 TRUE=使用剩余时间")]
		public YKE_BOOL use_remain;

		/// <summary>
		/// TRUE=此输入功能逻辑取反 FALSE=不取反
		/// </summary>
		[Description("TRUE=此输入功能逻辑取反 FALSE=不取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 参考时间
		/// </summary>
		[Description("参考时间")]
		public double time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 轴速度条件触发
	/// </summary>
	unsafe public struct YKS_TriggerArgAxisVelocity
	{
		/// <summary>
		/// 轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// FALSE=监控规划速度 TRUE=监控实际速度
		/// </summary>
		[Description("FALSE=监控规划速度 TRUE=监控实际速度")]
		public YKE_BOOL use_feedback;

		/// <summary>
		/// TRUE=此输入功能逻辑取反 FALSE=不取反
		/// </summary>
		[Description("TRUE=此输入功能逻辑取反 FALSE=不取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 触发时的速度(0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("触发时的速度(0,DOUBLE_MAX](unit/s)")]
		public double velocity;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 轴转矩条件触发
	/// </summary>
	unsafe public struct YKS_TriggerArgAxisTorque
	{
		/// <summary>
		/// 轴序号
		/// </summary>
		[Description("轴序号")]
		public UInt32 axis_index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// FALSE=监控规划转矩 TRUE=监控实际转矩
		/// </summary>
		[Description("FALSE=监控规划转矩 TRUE=监控实际转矩")]
		public YKE_BOOL use_feedback;

		/// <summary>
		/// TRUE=此输入功能逻辑取反 FALSE=不取反
		/// </summary>
		[Description("TRUE=此输入功能逻辑取反 FALSE=不取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 触发时的转矩(0.1%单位)
		/// </summary>
		[Description("触发时的转矩(0.1%单位)")]
		public double torque;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 从站PDO触发条件
	/// </summary>
	unsafe public struct YKS_TriggerArgSlavePDO
	{
		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// 从站站号
		/// </summary>
		[Description("从站站号")]
		public UInt32 slave_index;

		/// <summary>
		/// 对象字典主索引
		/// </summary>
		[Description("对象字典主索引")]
		public UInt32 main_index;

		/// <summary>
		/// 对象字典子索引
		/// </summary>
		[Description("对象字典子索引")]
		public UInt32 sub_index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// 数据类型
		/// </summary>
		[Description("数据类型")]
		public YKE_DATA_TYPE data_type;

		/// <summary>
		/// TRUE=此输入功能逻辑取反 FALSE=不取反
		/// </summary>
		[Description("TRUE=此输入功能逻辑取反 FALSE=不取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 触发值
		/// </summary>
		[Description("触发值")]
		public Int32 value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 编码器触发条件
	/// </summary>
	unsafe public struct YKS_TriggerArgEncoder
	{
		/// <summary>
		/// 通道号
		/// </summary>
		[Description("通道号")]
		public UInt32 index;

		/// <summary>
		/// 触发模式
		/// </summary>
		[Description("触发模式")]
		public YKE_TRIG_MODE trig_mode;

		/// <summary>
		/// TRUE=此输入功能逻辑取反 FALSE=不取反
		/// </summary>
		[Description("TRUE=此输入功能逻辑取反 FALSE=不取反")]
		public YKE_BOOL inv;

		/// <summary>
		/// 触发值
		/// </summary>
		[Description("触发值")]
		public Int32 value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:位参数写入
	/// </summary>
	unsafe public struct YKS_TriggerOutputOneBit
	{
		/// <summary>
		/// 信号源
		/// </summary>
		[Description("信号源")]
		public YKE_SIGNAL_SOURCE_TYPE type;

		/// <summary>
		/// 事件或寄存器索引号
		/// YKE_SIGNAL_SOURCE_EVENT/YKE_SIGNAL_SOURCE_REG模式使用
		/// </summary>
		[Description("事件或寄存器索引号;YKE_SIGNAL_SOURCE_EVENT/YKE_SIGNAL_SOURCE_REG模式使用")]
		public UInt32 index;

		/// <summary>
		/// 数字输入输出选择
		/// YKE_SIGNAL_SOURCE_INPUT/YKE_SIGNAL_SOURCE_OUTPUT模式使用
		/// </summary>
		[Description("数字输入输出选择;YKE_SIGNAL_SOURCE_INPUT/YKE_SIGNAL_SOURCE_OUTPUT模式使用")]
		public YKS_DigitalIO inout;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为低电平
		/// </summary>
		[Description("TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为低电平")]
		public YKE_BOOL set_off_state;

		/// <summary>
		/// TRUE=启用延时翻转
		/// </summary>
		[Description("TRUE=启用延时翻转")]
		public YKE_BOOL enable_reverse;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 延时时间
		/// </summary>
		[Description("延时时间")]
		public double delay_ms;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:轴停止
	/// </summary>
	unsafe public struct YKS_TriggerOutputStopAxis
	{
		/// <summary>
		/// 轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// 停止速度选择
		/// </summary>
		[Description("停止速度选择")]
		public YKE_STOP_DEC stop_dec;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];
	}

	/// <summary>
	/// 触发输出:启动坐标系
	/// </summary>
	unsafe public struct YKS_TriggerOutputStartGroup
	{
		/// <summary>
		/// 坐标系序号[0,YKE_GROUP_NUM)
		/// </summary>
		[Description("坐标系序号[0,YKE_GROUP_NUM)")]
		public UInt32 group_index;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:启动多轴联动
	/// </summary>
	unsafe public struct YKS_TriggerOutputStartMultiAxis
	{
		/// <summary>
		/// 多轴联动序号[0,YKE_MULTI_AXIS_NUM)
		/// </summary>
		[Description("多轴联动序号[0,YKE_MULTI_AXIS_NUM)")]
		public UInt32 index;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:启动轴
	/// </summary>
	unsafe public struct YKS_TriggerOutputStartAxis
	{
		/// <summary>
		/// 轴序号[0,YKE_AXIS_NUM)
		/// </summary>
		[Description("轴序号[0,YKE_AXIS_NUM)")]
		public UInt32 axis_index;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// 目标位置[DOUBLE_MIN,DOUBLEMAX](unit)
		/// </summary>
		[Description("目标位置[DOUBLE_MIN,DOUBLEMAX](unit)")]
		public double position;

		/// <summary>
		/// 运动参数
		/// </summary>
		[Description("运动参数")]
		public YKS_AxisProfileMotion motion;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:触发软急停信号
	/// </summary>
	unsafe public struct YKS_TriggerOutputSoftEmgStop
	{
		/// <summary>
		/// 急停通道序号
		/// </summary>
		[Description("急停通道序号")]
		public UInt32 channel;

		/// <summary>
		/// 单次触发 FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("单次触发 FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:从站PDO写入
	/// </summary>
	unsafe public struct YKS_TriggerOutputSlavePDO
	{
		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// 从站站号
		/// </summary>
		[Description("从站站号")]
		public UInt32 slave_index;

		/// <summary>
		/// 对象字典主索引
		/// </summary>
		[Description("对象字典主索引")]
		public UInt32 main_index;

		/// <summary>
		/// 对象字典子索引
		/// </summary>
		[Description("对象字典子索引")]
		public UInt32 sub_index;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为低电平
		/// </summary>
		[Description("TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为低电平")]
		public YKE_BOOL set_off_state;

		/// <summary>
		/// 数据类型
		/// </summary>
		[Description("数据类型")]
		public YKE_DATA_TYPE data_type;

		/// <summary>
		/// 写入值
		/// </summary>
		[Description("写入值")]
		public UInt32 value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:写入轴目标转矩
	/// </summary>
	unsafe public struct YKS_TriggerOutputTargetTorque
	{
		/// <summary>
		/// 轴序号
		/// </summary>
		[Description("轴序号")]
		public UInt32 axis_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 转矩值
		/// </summary>
		[Description("转矩值")]
		public double value;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为0
		/// </summary>
		[Description("TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为0")]
		public YKE_BOOL set_off_state;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:延时
	/// </summary>
	unsafe public struct YKS_TriggerOutputDelayMs
	{
		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 延时时间(ms)
		/// </summary>
		[Description("延时时间(ms)")]
		public double value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 触发输出:写数据寄存器
	/// </summary>
	unsafe public struct YKS_TriggerOutputDataReg
	{
		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// FALSE=多次触发 TRUE=单次触发
		/// </summary>
		[Description("FALSE=多次触发 TRUE=单次触发")]
		public YKE_BOOL single_shot;

		/// <summary>
		/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为0
		/// </summary>
		[Description("TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为0")]
		public YKE_BOOL set_off_state;

		/// <summary>
		/// 数据寄存器索引
		/// </summary>
		[Description("数据寄存器索引")]
		public UInt32 index;

		/// <summary>
		/// 写入值
		/// </summary>
		[Description("写入值")]
		public UInt32 value;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// 事件状态
	/// </summary>
	unsafe public struct YKS_EventStatus
	{
		/// <summary>
		/// 主站
		/// </summary>
		[Description("主站")]
		public YKE_NODE master;

		/// <summary>
		/// 事件状态
		/// </summary>
		[Description("事件状态")]
		public YKE_EVENT_STATUS_TYTE status;

		/// <summary>
		/// 错误代码
		/// </summary>
		[Description("错误代码")]
		public YKE_SYSTEM_ERROR error;

		/// <summary>
		/// 触发次数
		/// </summary>
		[Description("触发次数")]
		public UInt32 triged;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res[8];
	}

	/// <summary>
	/// PT数据
	/// </summary>
	unsafe public struct YKS_PTData
	{
		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double position;

		/// <summary>
		/// 时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("时间[0,DOUBLE_MAX](ms)")]
		public double tim;

		/// <summary>
		/// 加速度变化时间比[0,1]
		/// </summary>
		[Description("加速度变化时间比[0,1]")]
		public double acc_add_percent;
	}

	/// <summary>
	/// PVT数据
	/// </summary>
	unsafe public struct YKS_PVTData
	{
		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double position;

		/// <summary>
		/// 时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("时间[0,DOUBLE_MAX](ms)")]
		public double tim;

		/// <summary>
		/// 速度[0,DOUBLE_MAX](unit/s)
		/// </summary>
		[Description("速度[0,DOUBLE_MAX](unit/s)")]
		public double velocity;
	}

	/// <summary>
	/// PVTS数据
	/// </summary>
	unsafe public struct YKS_PVTSData
	{
		/// <summary>
		/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("位置[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double position;

		/// <summary>
		/// 时间[0,DOUBLE_MAX](ms)
		/// </summary>
		[Description("时间[0,DOUBLE_MAX](ms)")]
		public double tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public double res;
	}

	/// <summary>
	/// PVT运动状态
	/// </summary>
	unsafe public struct YKS_PVTStatus
	{
		/// <summary>
		/// 缓冲区空闲数量[0,YKE_PVT_DEPTH]
		/// </summary>
		[Description("缓冲区空闲数量[0,YKE_PVT_DEPTH]")]
		public UInt32 idel;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[7];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// 看门狗状态
	/// </summary>
	unsafe public struct YKS_WDTStatus
	{
		/// <summary>
		/// 看门狗启用状态  FALSE=未启用 TRUE=已启用
		/// </summary>
		[Description("看门狗启用状态  FALSE=未启用 TRUE=已启用")]
		public YKE_BOOL enable;

		/// <summary>
		/// 看门狗触发状态  FALSE=未触发 TRUE=已触发
		/// </summary>
		[Description("看门狗触发状态  FALSE=未触发 TRUE=已触发")]
		public YKE_BOOL trigged;

		/// <summary>
		/// 超时时间
		/// </summary>
		[Description("超时时间")]
		public double timeout;

		/// <summary>
		/// 剩余触发时间
		/// </summary>
		[Description("剩余触发时间")]
		public double remain_tim;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res2[8];
	}

	/// <summary>
	/// CNC轴参数写入
	/// </summary>
	unsafe public struct YKS_CncGCode
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// G代码
		/// </summary>
		[Description("G代码")]
		public fixed sbyte gcode[160];
	}

	/// <summary>
	/// 基于控制点的AKIMA样条配置
	/// </summary>
	unsafe public struct YKS_CncASplineConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 起始过渡切向
		/// Default(算法自动计算)
		/// </summary>
		[Description("起始过渡切向;Default(算法自动计算)")]
		public YKE_CNC_ASPLINE_TRANS_TYPE start_trans_type;

		/// <summary>
		/// 终止过渡切向
		/// Default(算法自动计算)
		/// </summary>
		[Description("终止过渡切向;Default(算法自动计算)")]
		public YKE_CNC_ASPLINE_TRANS_TYPE end_trans_type;

		/// <summary>
		/// 用户指定起始切向
		/// </summary>
		[Description("用户指定起始切向")]
		public fixed double start_Vector[3];

		/// <summary>
		/// 用户指定终止切向
		/// </summary>
		[Description("用户指定终止切向")]
		public fixed double end_Vector[3];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res1[4];
	}

	/// <summary>
	/// CNC轮廓角偏差平滑配置
	/// </summary>
	unsafe public struct YKS_CncContourDevConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 辅助功能(M/H)执行位置
		/// Default(平滑轮廓中)
		/// </summary>
		[Description("辅助功能(M/H)执行位置;Default(平滑轮廓中)")]
		public YKE_CNC_ACTION_TYPE action_time;

		/// <summary>
		/// 变加速监控
		/// Default(不监控)
		/// </summary>
		[Description("变加速监控;Default(不监控)")]
		public YKE_CNC_CHECK_JERK_TYPE check_jerk;

		/// <summary>
		/// 轮廓过渡路径速度是否恒定
		/// Default(否)
		/// </summary>
		[Description("轮廓过渡路径速度是否恒定;Default(否)")]
		public YKE_BOOL vel_const;

		/// <summary>
		/// 最大轮廓偏差
		/// </summary>
		[Description("最大轮廓偏差")]
		public double path_dev_max;

		/// <summary>
		/// 最大角度偏差
		/// </summary>
		[Description("最大角度偏差")]
		public double track_dev_max;

		/// <summary>
		/// 后续相关路径的最小长度
		/// </summary>
		[Description("后续相关路径的最小长度")]
		public double relevant_path_min;

		/// <summary>
		/// 后续相关路径的最小角度
		/// </summary>
		[Description("后续相关路径的最小角度")]
		public double relevant_track_min;

		/// <summary>
		/// 优化后路径长度相对原路径长度比例
		/// </summary>
		[Description("优化后路径长度相对原路径长度比例")]
		public double remain_part;

		/// <summary>
		/// 轮廓过渡生效最大夹角
		/// </summary>
		[Description("轮廓过渡生效最大夹角")]
		public double angle_max;
	}

	/// <summary>
	/// CNC轮廓角距离平滑配置
	/// </summary>
	unsafe public struct YKS_CncContourDistConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 辅助功能(M/H)执行位置
		/// Default(平滑轮廓中)
		/// </summary>
		[Description("辅助功能(M/H)执行位置;Default(平滑轮廓中)")]
		public YKE_CNC_ACTION_TYPE action_time;

		/// <summary>
		/// 变加速监控
		/// Default(不监控)
		/// </summary>
		[Description("变加速监控;Default(不监控)")]
		public YKE_CNC_CHECK_JERK_TYPE check_jerk;

		/// <summary>
		/// 轮廓过渡路径速度是否恒定
		/// Default(否)
		/// </summary>
		[Description("轮廓过渡路径速度是否恒定;Default(否)")]
		public YKE_BOOL vel_const;

		/// <summary>
		/// 最大角度偏差
		/// </summary>
		[Description("最大角度偏差")]
		public double track_dev_max;

		/// <summary>
		/// 过渡前段段拐角距离
		/// </summary>
		[Description("过渡前段段拐角距离")]
		public double pre_dist;

		/// <summary>
		/// 过渡后段拐角距离
		/// </summary>
		[Description("过渡后段拐角距离")]
		public double post_dist;

		/// <summary>
		/// 后续相关路径的最小长度
		/// </summary>
		[Description("后续相关路径的最小长度")]
		public double relevant_path_min;

		/// <summary>
		/// 后续相关路径的最小角度
		/// </summary>
		[Description("后续相关路径的最小角度")]
		public double relevant_track_min;

		/// <summary>
		/// 优化后路径长度相对原路径长度比例
		/// </summary>
		[Description("优化后路径长度相对原路径长度比例")]
		public double remain_part;

		/// <summary>
		/// 轮廓过渡生效最大夹角
		/// </summary>
		[Description("轮廓过渡生效最大夹角")]
		public double angle_max;
	}

	/// <summary>
	/// CNC动态轮廓优化平滑配置
	/// </summary>
	unsafe public struct YKS_CncContourDistSoftConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 最大允许路径偏移角距离(对称)
		/// </summary>
		[Description("最大允许路径偏移角距离(对称)")]
		public double path_dist;

		/// <summary>
		/// 路径偏离最大角度
		/// </summary>
		[Description("路径偏离最大角度")]
		public double track_dist;

		/// <summary>
		/// 最大加速度
		/// 轴最大加速度百分比[0%-100%]
		/// </summary>
		[Description("最大加速度;轴最大加速度百分比[0%-100%]")]
		public double acc_max;

		/// <summary>
		/// 最小加速度
		/// 轴最大加速度百分比[0%-100%]
		/// </summary>
		[Description("最小加速度;轴最大加速度百分比[0%-100%]")]
		public double acc_min;

		/// <summary>
		/// 变加速斜坡时间[0%-10000%]
		/// </summary>
		[Description("变加速斜坡时间[0%-10000%]")]
		public double ramp_time;

		/// <summary>
		/// 线性块分割百分比[0%-100%]
		/// </summary>
		[Description("线性块分割百分比[0%-100%]")]
		public double dist_weight;
	}

	/// <summary>
	/// CNC进给主轴动态轮廓优化平滑配置
	/// </summary>
	unsafe public struct YKS_CncContourDistMasterConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 最大允许路径偏移角距离(对称)
		/// </summary>
		[Description("最大允许路径偏移角距离(对称)")]
		public double path_dist;

		/// <summary>
		/// 最大加速度
		/// 轴最大加速度百分比[0%-100%]
		/// </summary>
		[Description("最大加速度;轴最大加速度百分比[0%-100%]")]
		public double acc_max;

		/// <summary>
		/// 最小加速度
		/// 轴最大加速度百分比[0%-100%]
		/// </summary>
		[Description("最小加速度;轴最大加速度百分比[0%-100%]")]
		public double acc_min;

		/// <summary>
		/// 变加速斜坡时间[0%-10000%]
		/// </summary>
		[Description("变加速斜坡时间[0%-10000%]")]
		public double ramp_time;

		/// <summary>
		/// 线性块分割百分比[0%-100%]
		/// </summary>
		[Description("线性块分割百分比[0%-100%]")]
		public double dist_weight;
	}

	/// <summary>
	/// CNC插入点平滑配置
	/// </summary>
	unsafe public struct YKS_CncContourPosConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 辅助功能(M/H)执行位置
		/// Default(平滑轮廓中)
		/// </summary>
		[Description("辅助功能(M/H)执行位置;Default(平滑轮廓中)")]
		public YKE_CNC_ACTION_TYPE action_time;

		/// <summary>
		/// 变加速监控
		/// Default(不监控)
		/// </summary>
		[Description("变加速监控;Default(不监控)")]
		public YKE_CNC_CHECK_JERK_TYPE check_jerk;

		/// <summary>
		/// 轮廓过渡路径速度是否恒定
		/// Default(否)
		/// </summary>
		[Description("轮廓过渡路径速度是否恒定;Default(否)")]
		public YKE_BOOL vel_const;

		/// <summary>
		/// 过渡前段段拐角距离
		/// </summary>
		[Description("过渡前段段拐角距离")]
		public double pre_dist;

		/// <summary>
		/// 过渡后段拐角距离
		/// </summary>
		[Description("过渡后段拐角距离")]
		public double post_dist;

		/// <summary>
		/// POS模式插入点坐标,三维[posX,posY,posZ]
		/// </summary>
		[Description("POS模式插入点坐标,三维[posX,posY,posZ]")]
		public fixed double pos_position[3];
	}

	/// <summary>
	/// CNC完整轮廓动态优化平滑配置
	/// </summary>
	unsafe public struct YKS_CncContourPtpConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 是否合并块
		/// Default(否)
		/// </summary>
		[Description("是否合并块;Default(否)")]
		public YKE_BOOL merge;

		/// <summary>
		/// 辅助功能(M/H)执行位置
		/// Default(平滑轮廓中)
		/// </summary>
		[Description("辅助功能(M/H)执行位置;Default(平滑轮廓中)")]
		public YKE_CNC_ACTION_TYPE action_time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 最大轮廓偏差
		/// </summary>
		[Description("最大轮廓偏差")]
		public double path_dev_max;

		/// <summary>
		/// 最大允许路径偏移角距离(对称)
		/// </summary>
		[Description("最大允许路径偏移角距离(对称)")]
		public double path_dist;
	}

	/// <summary>
	/// HSC_B样条平滑配置
	/// </summary>
	unsafe public struct YKS_CncHscBConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 是否合并块
		/// Default(否)
		/// </summary>
		[Description("是否合并块;Default(否)")]
		public YKE_BOOL merge;

		/// <summary>
		/// 路径偏差超过path_dev_max,是否自动取消B样条平滑
		/// Default(否)
		/// </summary>
		[Description("路径偏差超过path_dev_max,是否自动取消B样条平滑;Default(否)")]
		public YKE_BOOL auto_off_path;

		/// <summary>
		/// 角度偏差超过track_dev_max,是否自动取消B样条平滑
		/// Default(否)
		/// </summary>
		[Description("角度偏差超过track_dev_max,是否自动取消B样条平滑;Default(否)")]
		public YKE_BOOL auto_off_track;

		/// <summary>
		/// 遇到快速移动(G00)指令,是否自动取消B样条平滑
		/// Default(否)
		/// </summary>
		[Description("遇到快速移动(G00)指令,是否自动取消B样条平滑;Default(否)")]
		public YKE_BOOL auto_off_rapid;

		/// <summary>
		/// 遇到精确停止(G60/G360)指令,是否自动取消B样条平滑
		/// Default(否)
		/// </summary>
		[Description("遇到精确停止(G60/G360)指令,是否自动取消B样条平滑;Default(否)")]
		public YKE_BOOL auto_off_exactStop;

		/// <summary>
		/// 最大路径误差
		/// </summary>
		[Description("最大路径误差")]
		public double path_dev_max;

		/// <summary>
		/// 最大角度误差
		/// </summary>
		[Description("最大角度误差")]
		public double track_dev_max;

		/// <summary>
		/// B样条平滑生效的最大路径长度,大于指定值,则自动取消B样条平滑
		/// 0-不取消
		/// </summary>
		[Description("B样条平滑生效的最大路径长度,大于指定值,则自动取消B样条平滑;0-不取消")]
		public double path_len_max;

		/// <summary>
		/// B样条平滑生效的最大夹角。大于指定值,则自动取消B样条平滑
		/// 0-160°
		/// </summary>
		[Description("B样条平滑生效的最大夹角。大于指定值,则自动取消B样条平滑;0-160°")]
		public double angle_max;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res1[4];
	}

	/// <summary>
	/// HSC_Surface平滑配置
	/// </summary>
	unsafe public struct YKS_CncHscSConfig
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 圆周运动轮廓
		/// Default(圆弧轮廓平滑)
		/// </summary>
		[Description("圆周运动轮廓;Default(圆弧轮廓平滑)")]
		public YKE_HSC_CIR_MODE cir_mode;

		/// <summary>
		/// 变加速监控
		/// Default(不监控)
		/// </summary>
		[Description("变加速监控;Default(不监控)")]
		public YKE_CNC_CHECK_JERK_TYPE check_jerk;

		/// <summary>
		/// 快速移动(G00)指令,是否自动取消平滑
		/// Default(否)
		/// </summary>
		[Description("快速移动(G00)指令,是否自动取消平滑;Default(否)")]
		public YKE_BOOL auto_off_rapid;

		/// <summary>
		/// 是否合并块
		/// Default(否)
		/// </summary>
		[Description("是否合并块;Default(否)")]
		public YKE_BOOL merge;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res0;

		/// <summary>
		/// 最小圆角,小于指定角度,则使用样条曲线近似处理。
		/// </summary>
		[Description("最小圆角,小于指定角度,则使用样条曲线近似处理。")]
		public double cir_min_angle;

		/// <summary>
		/// 快速移动最大角度误差
		/// </summary>
		[Description("快速移动最大角度误差")]
		public double track_dev_rapid;

		/// <summary>
		/// 最大路径误差
		/// </summary>
		[Description("最大路径误差")]
		public double path_dev_max;

		/// <summary>
		/// 快速移动过渡最大误差,默认path_dev_max
		/// </summary>
		[Description("快速移动过渡最大误差,默认path_dev_max")]
		public double path_dev_rapid;

		/// <summary>
		/// 平滑生效的最大夹角,大于指定值,则自动取消B样条平滑
		/// 0-160°
		/// </summary>
		[Description("平滑生效的最大夹角,大于指定值,则自动取消B样条平滑;0-160°")]
		public double angle_max;

		/// <summary>
		/// 最小半径,小于指定半径或小于path_dev,则使用样条曲线近似处理。
		/// </summary>
		[Description("最小半径,小于指定半径或小于path_dev,则使用样条曲线近似处理。")]
		public double cir_min_radius;

		/// <summary>
		/// cir_mode=2时,长圆的最小长度。
		/// </summary>
		[Description("cir_mode=2时,长圆的最小长度。")]
		public double cir_long_length;

		/// <summary>
		/// 最大角度误差
		/// </summary>
		[Description("最大角度误差")]
		public double track_dev_max;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed double res[8];
	}

	/// <summary>
	/// HSC_PCS1平滑参数
	/// </summary>
	unsafe public struct YKS_CncHscPcs1Config
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 最大轮廓误差
		/// </summary>
		[Description("最大轮廓误差")]
		public double contour_error_Max;
	}

	/// <summary>
	/// HSC_PCS2平滑参数
	/// </summary>
	unsafe public struct YKS_CncHscPcs2Config
	{
		/// <summary>
		/// 用户标记
		/// </summary>
		[Description("用户标记")]
		public UInt32 mark;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 最大轮廓误差
		/// </summary>
		[Description("最大轮廓误差")]
		public double contour_error_Max;
	}

	/// <summary>
	/// 写CNC参数状态
	/// </summary>
	unsafe public struct YKS_CncParaStatus
	{
		/// <summary>
		/// 命令状态 0:未完成 1:已完成
		/// </summary>
		[Description("命令状态 0:未完成 1:已完成")]
		public YKE_BOOL done;

		/// <summary>
		/// 状态 1:完成 2:有错误
		/// </summary>
		[Description("状态 1:完成 2:有错误")]
		public UInt32 status;

		/// <summary>
		/// 读命令的返回值
		/// </summary>
		[Description("读命令的返回值")]
		public fixed sbyte value[128];

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public fixed UInt32 res1[8];
	}
#endregion

	/// <summary>
	/// ProCon
	/// </summary>
	public class ProCon
	{
		#region 系统
		/// <summary>
		/// 连接NT控制器
		/// </summary>
		/// <param name="ip_addr">ip地址</param>
		/// <param name="ip_port">端口号，默认50001</param>
		/// <param name="handle">返回的句柄</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysConnect(Byte[] ip_addr, UInt32 ip_port, out Int32 handle);

		/// <summary>
		/// 断开NT控制器
		/// </summary>
		/// <param name="handle">通讯句柄</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysClose(Int32 handle);

		/// <summary>
		/// 获取库文件(YKCAT2.dll)版本
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="version">当前版本号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSysVersion(Int32 handle, out UInt32 version);

		/// <summary>
		/// 获取Runtime版本
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="version">当前版本号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetRuntimeVersion(Int32 handle, out UInt32 version);

		/// <summary>
		/// 获取线程ID
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="id">线程ID</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetThreadID(Int32 handle, out UInt32 id);

		/// <summary>
		/// 打开和Runtime(ProR)之间的通讯通道
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysLoadLib(Int32 handle);

		/// <summary>
		/// 释放系统资源，程序退出时调用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysUnloadLib(Int32 handle);

		/// <summary>
		/// 设置应用程序看门狗超时时间
		/// 可用于上位机异常关闭时自动停止轴运动及输出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="enable">FALSE:不启用 TRUE:启用</param>
		/// <param name="tim">超时时间(ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAppWDT(Int32 handle, YKE_BOOL enable, double tim);

		/// <summary>
		/// 重置应用程序看门狗
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearAppWDT(Int32 handle);

		/// <summary>
		/// 获取应用程序看门狗状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAppWDT(Int32 handle, out YKS_WDTStatus status);

		/// <summary>
		/// 开始日志记录
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="process_id">进程ID</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartLogger(Int32 handle, UInt32 process_id);

		/// <summary>
		/// 停止日志记录
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopLogger(Int32 handle);

		/// <summary>
		/// 获取开启日志的进程ID
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="process_id">进程ID</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetLoggerProcessID(Int32 handle, out UInt32 process_id);

		/// <summary>
		/// 写日志配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetLoggerConfig(Int32 handle, YKS_LoggerConfig config);

		/// <summary>
		/// 读日志配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetLoggerConfig(Int32 handle, out YKS_LoggerConfig config);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config">配饰</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_InitExcData(Int32 handle, YKS_ExcTrackConfig config);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="item_data">保留</param>
		/// <param name="ret_size">保留</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetExcData(Int32 handle, out YKS_ExcTrackItem item_data, out UInt32 ret_size);

		/// <summary>
		/// 获取进程名称
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="process_id">进程ID</param>
		/// <param name="name">进程名称</param>
		/// <param name="size">缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetProcessName(Int32 handle, UInt32 process_id, Byte[] name, UInt32 size);

		/// <summary>
		/// 获取调用运动库的进程列表
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="process_num">进程数量</param>
		/// <param name="process_id">进程ID,至少16个元素空间</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetProcessNumber(Int32 handle, out UInt32 process_num, UInt32[] process_id);

		/// <summary>
		/// 获取当前进程ID
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="process_id">进程ID</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetProcessID(Int32 handle, out UInt32 process_id);

		/// <summary>
		/// 获取本进程函数调用记录，每次最多返回1行
		/// </summary>
		/// <param name="handle">固定为0</param>
		/// <param name="buff">缓冲区地址</param>
		/// <param name="size">缓冲区大小</param>
		/// <param name="count">返回的字符数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadFunLog(Int32 handle, Byte[] buff, UInt32 size, out UInt32 count);

		/// <summary>
		/// 获取系统配置信息
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config"></param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSysProfile(Int32 handle, out YKS_SysProfile config);

		/// <summary>
		/// 获取当前报警信息
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="buff">缓冲区，不小于2048字节</param>
		/// <param name="size">缓冲区尺寸</param>
		/// <param name="num">报警数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadSysWarn(Int32 handle, Byte[] buff, UInt32 size, out UInt32 num);

		/// <summary>
		/// 获取系统日志
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="buff">缓冲区，不小于2048字节</param>
		/// <param name="size">缓冲区尺寸</param>
		/// <param name="ret_size">实际返回数据大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadSysLog(Int32 handle, Byte[] buff, UInt32 size, out UInt32 ret_size);

		/// <summary>
		/// 清除缓存中的日志
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearSysLog(Int32 handle);

		/// <summary>
		/// 向管理任务发送命令
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="run_stop">YKE_FALSE=停止(轴会停止，输出会关闭) YKE_TRUE=运行</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SendMgmtCmd(Int32 handle, YKE_NODE master, YKE_BOOL run_stop);

		/// <summary>
		/// 获取runtime运行状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="status">0=停止 1=运行 2=过渡状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadMgmtStatus(Int32 handle, YKE_NODE master, out UInt32 status);

		/// <summary>
		/// 冷复位，此动作会重启实时系统和Runtime
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="delay">服务停止后延时指定时间后再开启服务(ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysColdReset(Int32 handle, double delay);

		/// <summary>
		/// 热复位。复位runtime，轴运动停止，关输出。复位A节点时,默认复位其他节点
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysWarmReset(Int32 handle, YKE_NODE master);

		/// <summary>
		/// 启动Runtime服务
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysStartService(Int32 handle);

		/// <summary>
		/// 停止Runtime服务
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysStopService(Int32 handle);

		/// <summary>
		/// 检测Runtime服务是否处于运行状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="status">TRUE:已运行 FALSE:未运行</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysCheckService(Int32 handle, out YKE_BOOL status);

		/// <summary>
		/// 注册runtime服务
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="path">runtime根目录</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysRegisterService(Int32 handle, Byte[] path);

		/// <summary>
		/// 注销runtime服务
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysUnRegisterService(Int32 handle);

		/// <summary>
		/// 获取服务注册状态和服务文件路径
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="registered">TRUE:已注册 FALSE:未注册</param>
		/// <param name="path">路径缓冲区</param>
		/// <param name="size">路径缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SysGetService(Int32 handle, out YKE_BOOL registered, Byte[] path, UInt32 size);

		/// <summary>
		/// 设置硬急停配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetHardEmgProfile(Int32 handle, UInt32 channel, YKS_HardEmgProfile config);

		/// <summary>
		/// 获取硬急停配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
		/// <param name="config"></param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetHardEmgProfile(Int32 handle, UInt32 channel, out YKS_HardEmgProfile config);

		/// <summary>
		/// 设置软急停信号有效
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetEmgStopSoft(Int32 handle, UInt32 channel);

		/// <summary>
		/// 清除软急停信号有效
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearEmgStopSoft(Int32 handle, UInt32 channel);

		/// <summary>
		/// 获取急停状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
		/// <param name="status">返回状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadEmgStatus(Int32 handle, UInt32 channel, out YKS_EmgStatus status);

		/// <summary>
		/// 设置Windows蓝屏后的行为
		/// 未实现
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetBlueScreenConfig(Int32 handle, YKS_BlueScreenConfig config);

		/// <summary>
		/// 获取ProEN工程ID
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="prj_id">工程ID缓冲区</param>
		/// <param name="size">缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetProjectID(Int32 handle, Byte[] prj_id, UInt32 size);

		/// <summary>
		/// 加载由ProEn导出的工程配置数据(bprj扩展名)
		/// 注意下载前会主动停止正在运动中的轴
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="filename">路径及文件名称</param>
		/// <param name="mask">数据掩码按位定义(YKE_PROJECT_MASK),置位时下载对应的数据</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_LoadProjectData(Int32 handle, Byte[] filename, UInt32 mask);

		/// <summary>
		/// 获取给PLC模块的控制命令
		/// 内部使用
		/// </summary>
		/// <param name="command">命令</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetPLCCommand(out YKE_PLC_CMD_TYPE command);

		/// <summary>
		/// 写入PLC状态
		/// 内部使用
		/// </summary>
		/// <param name="handle">保留</param>
		/// <param name="status">命令</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetPLCStatus(Int32 handle, UInt32 status);

		/// <summary>
		/// 向PLC发送控制命令
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="command">控制命令</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SendPLCCommand(Int32 handle, YKE_PLC_CMD_TYPE command);

		/// <summary>
		/// 清除系统报警
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearSysWarn(Int32 handle, YKE_NODE master);

		/// <summary>
		/// 设置总线事件间隔时间
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="tim">时间[0,](ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetBusEventTime(Int32 handle, YKE_NODE master, double tim);

		/// <summary>
		/// 获取总线事件间隔时间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="tim">时间[0,](ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetBusEventTime(Int32 handle, YKE_NODE master, out double tim);

		/// <summary>
		/// 等待总线任务事件，指定时间触发一次
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WaitBusEvent(Int32 handle, YKE_NODE master);

		/// <summary>
		/// 读总线通讯数据帧
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="header">帧头信息</param>
		/// <param name="buff">缓冲区地址</param>
		/// <param name="size">缓冲区大小,大于1500</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadBusPacket(Int32 handle, out YKS_BusPacketHeader header, Byte[] buff, UInt32 size);

		/// <summary>
		/// 写通用寄存器,UIN32模式
		/// 支持API缓冲区
		/// YKE_GENDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 UINT32单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDataRegU32(Int32 handle, UInt32 offset, UInt32[] data, UInt32 size);

		/// <summary>
		/// 读通用寄存器,UIN32模式
		/// YKE_GENDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 UINT32单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDataRegU32(Int32 handle, UInt32 offset, UInt32[] data, UInt32 size);

		/// <summary>
		/// 写通用寄存器,double模式
		/// 支持API缓冲区
		/// YKE_GENDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 double单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDataRegDouble(Int32 handle, UInt32 offset, double[] data, UInt32 size);

		/// <summary>
		/// 读通用寄存器,double模式
		/// YKE_GENDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 double单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDataRegDouble(Int32 handle, UInt32 offset, double[] data, UInt32 size);

		/// <summary>
		/// 获取通用寄存器在内存中的首地址
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="hi_addr">内存地址(高32位)</param>
		/// <param name="lo_addr">内存地址(低32位)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetDataRegAddress(Int32 handle, out UInt32 hi_addr, out UInt32 lo_addr);

		/// <summary>
		/// 写特殊功能寄存器,UIN32模式
		/// 支持API缓冲区
		/// YKE_SPDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 UINT32单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteSpecRegU32(Int32 handle, UInt32 offset, UInt32[] data, UInt32 size);

		/// <summary>
		/// 读特殊功能寄存器,UIN32模式
		/// YKE_SPDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 UINT32单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadSpecRegU32(Int32 handle, UInt32 offset, UInt32[] data, UInt32 size);

		/// <summary>
		/// 写特殊功能寄存器,double模式
		/// 支持API缓冲区
		/// YKE_SPDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 double单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteSpecRegDouble(Int32 handle, UInt32 offset, double[] data, UInt32 size);

		/// <summary>
		/// 读特殊功能寄存器,double模式
		/// YKE_SPDATA_SIZE个UINT32空间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">数据指针</param>
		/// <param name="size">数据数量 double单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadSpecRegDouble(Int32 handle, UInt32 offset, double[] data, UInt32 size);

		/// <summary>
		/// 获取特殊寄存器在内存中的首地址
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="hi_addr">内存地址(高32位)</param>
		/// <param name="lo_addr">内存地址(低32位)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSpecRegAddress(Int32 handle, out UInt32 hi_addr, out UInt32 lo_addr);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="name">工程名称</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ProEnAddPrj(Int32 handle, Byte[] name);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="name">工程名称</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ProEnDelPrj(Int32 handle, Byte[] name);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="name">工程名称</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ProEnCheckPrj(Int32 handle, Byte[] name);

		/// <summary>
		/// ProEn写配置数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="type">数量类型</param>
		/// <param name="data">数据</param>
		/// <param name="size">数据大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ProEnWriteData(Int32 handle, UInt32 type, Byte[] data, UInt32 size);

		/// <summary>
		/// 读硬件锁用户区数据
		/// 阻塞模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="type">硬件锁类型</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">缓冲区</param>
		/// <param name="size">期望读出的数据大小(byte)，最大4096字节</param>
		/// <param name="result">实际读出的数据大小(byte)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDoggleData(Int32 handle, YKE_DOGGLE_TYPE type, UInt32 offset, Byte[] data, UInt32 size, out Int32 result);

		/// <summary>
		/// 写硬件锁用户区数据
		/// 阻塞模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="type">硬件锁类型</param>
		/// <param name="offset">地址偏移</param>
		/// <param name="data">缓冲区</param>
		/// <param name="size">期望写入的数据大小(byte)，最大4096字节</param>
		/// <param name="result">实际写入的数据大小(byte)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDoggleData(Int32 handle, YKE_DOGGLE_TYPE type, UInt32 offset, Byte[] data, UInt32 size, out Int32 result);
		#endregion

		#region 总线
		/// <summary>
		/// 断开总线连接，断开后再次调用复位命令可恢复总线运行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_DisconnectBus(Int32 handle, YKE_NODE master);

		/// <summary>
		/// 热复位并扫描从站
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="info">扫描内容</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ScanBus(Int32 handle, YKE_NODE master, YKE_SCAN_INFO info);

		/// <summary>
		/// 获得总线信息
		/// </summary>
		/// <param name="master">主站选择</param>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="info"></param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadBusStatus(Int32 handle, YKE_NODE master, out YKS_BusStatus info);

		/// <summary>
		/// 清除总线负载率/同步偏移/帧丢失数量
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearBusValue(Int32 handle, YKE_NODE master);

		/// <summary>
		/// 清除总线报警
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearBusWarn(Int32 handle, YKE_NODE master);

		/// <summary>
		/// 配置总线节点信息
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="slaveIndex">站点序号，从0开始</param>
		/// <param name="item">配置内容，热复位后生效</param>
		/// <param name="value">配置值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetBusConfig(Int32 handle, YKE_NODE master, UInt32 slaveIndex, YKE_SLAVE_ITEM item, Int32 value);

		/// <summary>
		/// 获取总线节点信息
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="slaveIndex">站点序号，从0开始</param>
		/// <param name="item">配置内容</param>
		/// <param name="value">返回的配置值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetBusConfig(Int32 handle, YKE_NODE master, UInt32 slaveIndex, YKE_SLAVE_ITEM item, out Int32 value);

		/// <summary>
		/// 获得从站名称，名称在ProEn中设置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="slaveIndex">站点序号，从0开始</param>
		/// <param name="name">返回名称，至少分配64字节</param>
		/// <param name="size">name缓冲区尺寸</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSlaveAlias(Int32 handle, YKE_NODE master, UInt32 slaveIndex, Byte[] name, UInt32 size);

		/// <summary>
		/// 获得总线各站点状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="slaveIndex">站点序号，从0开始</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadSlaveStatus(Int32 handle, YKE_NODE master, UInt32 slaveIndex, out YKS_SlaveStatus status);

		/// <summary>
		/// 读从站输出PDO数量
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标</param>
		/// <param name="master">主站</param>
		/// <param name="slaveIndex">从站序号</param>
		/// <param name="number">返回数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSlaveTxPdoNumber(Int32 handle, YKE_NODE master, UInt32 slaveIndex, out UInt32 number);

		/// <summary>
		/// 读从站输出PDO配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标</param>
		/// <param name="master">主站</param>
		/// <param name="slaveIndex">从站序号</param>
		/// <param name="pdoIndex">PDO序号，从0开始</param>
		/// <param name="config">返回数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSlaveTxPdoConfig(Int32 handle, YKE_NODE master, UInt32 slaveIndex, UInt32 pdoIndex, out YKS_SlavePdoConfig config);

		/// <summary>
		/// 读从站输入PDO数量
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标</param>
		/// <param name="master">主站</param>
		/// <param name="slaveIndex">从站序号</param>
		/// <param name="number">返回数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSlaveRxPdoNumber(Int32 handle, YKE_NODE master, UInt32 slaveIndex, out UInt32 number);

		/// <summary>
		/// 读从站输入PDO配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标</param>
		/// <param name="master">主站</param>
		/// <param name="slaveIndex">从站序号</param>
		/// <param name="pdoIndex">PDO序号，从0开始</param>
		/// <param name="config">返回配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSlaveRxPdoConfig(Int32 handle, YKE_NODE master, UInt32 slaveIndex, UInt32 pdoIndex, out YKS_SlavePdoConfig config);
		#endregion

		#region PDO/SDO
		/// <summary>
		/// 设置系统保留PDO保护标志
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="uIndex">站点序号</param>
		/// <param name="check">TRUE=开启写入保护 FALSE=关闭写入保护</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetPDOProtect(Int32 handle, YKE_NODE master, UInt32 uIndex, YKE_BOOL check);

		/// <summary>
		/// 获取系统保留PDO保护标志
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="uIndex">站点序号</param>
		/// <param name="check">TRUE=开启写入保护 FALSE=关闭写入保护</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetPDOProtect(Int32 handle, YKE_NODE master, UInt32 uIndex, out YKE_BOOL check);

		/// <summary>
		/// 基于UG索引写PDO数据
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="slaveIndex">站点序号</param>
		/// <param name="gIndex">G索引号，在从站配置的过程数据页面查看</param>
		/// <param name="ptr">写入数据</param>
		/// <param name="size">数据长度，16bit单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WritePDOIndex(Int32 handle, YKE_NODE master, UInt32 slaveIndex, UInt32 gIndex, UInt16[] ptr, UInt32 size);

		/// <summary>
		/// 基于UG索引读PDO数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="slaveIndex">站点序号</param>
		/// <param name="gIndex">G索引号，在从站配置的过程数据页面查看</param>
		/// <param name="ptr">返回数据</param>
		/// <param name="size">数据长度，16bit单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadPDOIndex(Int32 handle, YKE_NODE master, UInt32 slaveIndex, UInt32 gIndex, UInt16[] ptr, UInt32 size);

		/// <summary>
		/// 基于对象字典索引读PDO数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站</param>
		/// <param name="slaveIndex">站点序号</param>
		/// <param name="mainIndex">对象字典主索引</param>
		/// <param name="subIndex">对象字典子索引</param>
		/// <param name="ptr">返回数据</param>
		/// <param name="size">数据长度，16bit单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadPDOObject(Int32 handle, YKE_NODE master, UInt32 slaveIndex, UInt32 mainIndex, UInt32 subIndex, UInt16[] ptr, UInt32 size);

		/// <summary>
		/// 基于对象字典索引写PDO数据
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站</param>
		/// <param name="slaveIndex">站点序号</param>
		/// <param name="mainIndex">对象字典主索引</param>
		/// <param name="subIndex">对象字典子索引</param>
		/// <param name="ptr">写入数据</param>
		/// <param name="size">数据长度，16bit单位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WritePDOObject(Int32 handle, YKE_NODE master, UInt32 slaveIndex, UInt32 mainIndex, UInt32 subIndex, UInt16[] ptr, UInt32 size);

		/// <summary>
		/// 启动SDO写命令
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="slaveIndex">站点序号</param>
		/// <param name="mainIndex">对象主索引</param>
		/// <param name="subIndex">对象子索引</param>
		/// <param name="byteNum">数量(字节单位)</param>
		/// <param name="val">写入值</param>
		/// <param name="sdoIndex">返回的SDO队列索引</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteSDOCmd(Int32 handle, YKE_NODE master, UInt32 slaveIndex, UInt32 mainIndex, UInt32 subIndex, UInt32 byteNum, UInt32 val, out UInt32 sdoIndex);

		/// <summary>
		/// 启动SDO读命令
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="uIndex">站点序号</param>
		/// <param name="mainIndex">对象主索引</param>
		/// <param name="subIndex">对象子索引</param>
		/// <param name="byteNum">数量(字节单位)</param>
		/// <param name="sdoIndex">返回的SDO队列索引</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadSDOCmd(Int32 handle, YKE_NODE master, UInt32 uIndex, UInt32 mainIndex, UInt32 subIndex, UInt32 byteNum, out UInt32 sdoIndex);

		/// <summary>
		/// 读SDO队列状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="sdoIndex">SDO队列索引</param>
		/// <param name="status">返回状态</param>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadSDOStatus(Int32 handle, YKE_NODE master, UInt32 sdoIndex, out YKS_SdoStatus status);

		/// <summary>
		/// 获得SDO队列空闲数量
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="num">返回的空闲数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSDOIdel(Int32 handle, YKE_NODE master, out UInt32 num);
		#endregion

		#region 数字IO
		/// <summary>
		/// 按位读数字输出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDigitalOutputBit(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, out YKE_BOOL value);

		/// <summary>
		/// 按位批量读数字输出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
		/// <param name="size">读取数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDigitalOutputBits(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, YKE_BOOL[] value, UInt32 size);

		/// <summary>
		/// 按位写数字输出
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">写入值: FALSE=OFF  TRUE=ON</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalOutputBit(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, YKE_BOOL value);

		/// <summary>
		/// 按位批量写数字输出
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7</param>
		/// <param name="value">写入值: FALSE=OFF  TRUE=ON</param>
		/// <param name="size">写入数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalOutputBits(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, YKE_BOOL[] value, UInt32 size);

		/// <summary>
		/// 按字节读数字输出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)，每组8位</param>
		/// <param name="value">输出值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDigitalOutputByte(Int32 handle, UInt32 byteIndex, out Byte value);

		/// <summary>
		/// 按字节写数字输出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)，每组8位</param>
		/// <param name="value">输出值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalOutputByte(Int32 handle, UInt32 byteIndex, Byte value);

		/// <summary>
		/// 按字节写数字输出(带掩码)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="mask">按位定义，对应位为0时无效，为1时输出按value值输出</param>
		/// <param name="value">按位定义，输出值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalOutputMask(Int32 handle, UInt32 byteIndex, Byte mask, Byte value);

		/// <summary>
		/// 按位设置数字输出在热复位时的保持行为
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="hold">写入值: 0=不保持  1=保持</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetDigitalOutputHold(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, YKE_BOOL hold);

		/// <summary>
		/// 读取数字输出在热复位时的保持行为
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="hold">FALSE=不保持  TRUE=保持</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetDigitalOutputHold(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, out YKE_BOOL hold);

		/// <summary>
		/// 写数字输入滤波时间(ms)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="filter">滤波时间[0,1000](ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalInputFilter(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, double filter);

		/// <summary>
		/// 读数字输入滤波时间(ms)
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="filter">滤波时间[0,1000](ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDigitalInputFilter(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, out double filter);

		/// <summary>
		/// 按位读数字输入
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDigitalInputBit(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, out YKE_BOOL value);

		/// <summary>
		/// 按位批量读数字输入
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
		/// <param name="size">读取数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDigitalInputBits(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, YKE_BOOL[] value, UInt32 size);

		/// <summary>
		/// 按位写数字输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value"> FALSE=OFF  TRUE=ON</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalInputBit(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, YKE_BOOL value);

		/// <summary>
		/// 按字节读数字输入
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">组序号[0,YKE_DIGITAL_INPUT_NUM/8)，每组8位</param>
		/// <param name="value">输入值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadDigitalInputByte(Int32 handle, UInt32 byteIndex, out Byte value);

		/// <summary>
		/// 按字节写数字输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">组序号[0,YKE_DIGITAL_INPUT_NUM/8)，每组8位</param>
		/// <param name="value">输入值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalInputByte(Int32 handle, UInt32 byteIndex, Byte value);

		/// <summary>
		/// 读数字输入(软件滤波前)的上升沿计数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">返回值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadInputEdgeCount1(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, out UInt32 value);

		/// <summary>
		/// 写数字输入(软件滤波前)的上升沿计数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">写入值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteInputEdgeCount1(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, UInt32 value);

		/// <summary>
		/// 读数字输入(软件滤波后)的上升沿计数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">返回值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadInputEdgeCount2(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, out UInt32 value);

		/// <summary>
		/// 写数字输入(软件滤波后)的上升沿计数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="value">写入值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteInputEdgeCount2(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, UInt32 value);

		/// <summary>
		/// 读数字输入的硬件信息
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
		/// <param name="phy">物理位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadInputLocation(Int32 handle, UInt32 byteIndex, out YKS_DigitalIOHardInfo phy);

		/// <summary>
		/// 读数字输出的硬件信息
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="phy">物理位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadOutputLocation(Int32 handle, UInt32 byteIndex, out YKS_DigitalIOHardInfo phy);

		/// <summary>
		/// 延时翻转输出
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
		/// <param name="bitOffset">位偏移[0,7]</param>
		/// <param name="time">延时时间(ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReverseDigitalOutputBit(Int32 handle, UInt32 byteIndex, UInt32 bitOffset, double time);

		/// <summary>
		/// 同步数字输出
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="output">输出列表</param>
		/// <param name="size">输出数量(0, YKE_DIGITAL_OUTPUT_CYCLE_NUM]</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteDigitalOutputCycle(Int32 handle, YKS_DigitalOutputCycle[] output, UInt32 size);
		#endregion

		#region 软件位置比较
		/// <summary>
		/// 软件模式比较器参数配置
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCompareConfigSoft(Int32 handle, UInt32 channel, YKS_CompareConfigSoft config);

		/// <summary>
		/// 获取软件模式比较器参数配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCompareConfigSoft(Int32 handle, UInt32 channel, out YKS_CompareConfigSoft config);

		/// <summary>
		/// 设置比较值
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
		/// <param name="itemdata">比较配置，内部含有512个缓冲区</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCompareValueSoft(Int32 handle, UInt32 channel, YKS_CompareItemDataSoft itemdata);

		/// <summary>
		/// 获取软件模式比较器状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
		/// <param name="status">返回值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadCompareStatusSoft(Int32 handle, UInt32 channel, out YKS_CompareStatusSoft status);

		/// <summary>
		/// 软件模式比较器开始
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartCompareSoft(Int32 handle, UInt32 channel);

		/// <summary>
		/// 停止软件模式比较器
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopCompareSoft(Int32 handle, UInt32 channel);

		/// <summary>
		/// 写入软件探针配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetProbeConfigSoft(Int32 handle, UInt32 channel, YKS_ProbeConfigSoft config);

		/// <summary>
		/// 读取软件探针配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetProbeConfigSoft(Int32 handle, UInt32 channel, out YKS_ProbeConfigSoft config);

		/// <summary>
		/// 启动软件探针
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartProbeSoft(Int32 handle, UInt32 channel);

		/// <summary>
		/// 停止软件探针
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopProbeSoft(Int32 handle, UInt32 channel);

		/// <summary>
		/// 获取软件探针状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
		/// <param name="status">返回状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadProbeStatusSoft(Int32 handle, UInt32 channel, out YKS_ProbeStatusSoft status);
		#endregion

		#region 轴设置/信息
		/// <summary>
		/// 设置规划方向的当量，初始化完成后先设置当量，再使用和当量有关的函数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="dist">位移当量，浮点格式</param>
		/// <param name="pulse">脉冲当量，浮点格式</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCommandEquiv(Int32 handle, UInt32 axisIndex, double dist, double pulse);

		/// <summary>
		/// 获取规划方向的当量，初始化完成后先设置当量，再使用和当量有关的函数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="dist">位移当量，浮点格式</param>
		/// <param name="pulse">脉冲当量，浮点格式</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCommandEquiv(Int32 handle, UInt32 axisIndex, out double dist, out double pulse);

		/// <summary>
		/// 获取反馈方向当量比例，以规划方向当量为参考，未实现
		/// 总线轴有效
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="scale">比例</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetFeedbackEquivScale(Int32 handle, UInt32 axisIndex, out double scale);

		/// <summary>
		/// 设置反馈方向当量比例，以规划方向当量为参考，未实现
		/// 总线轴有效
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="scale">比例</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetFeedbackEquivScale(Int32 handle, UInt32 axisIndex, double scale);

		/// <summary>
		/// 设置转动方向
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="rotate_dir">FALSE:和驱动器一致  TRUE:和驱动器相反</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetRotateDir(Int32 handle, UInt32 axisIndex, YKE_BOOL rotate_dir);

		/// <summary>
		/// 获取转动方向
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="rotate_dir">FALSE:和驱动器一致  TRUE:和驱动器相反</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetRotateDir(Int32 handle, UInt32 axisIndex, out YKE_BOOL rotate_dir);

		/// <summary>
		/// 设置模轴配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfileModulo(Int32 handle, UInt32 axisIndex, YKS_AxisProfileModulo config);

		/// <summary>
		/// 获取模轴配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfileModulo(Int32 handle, UInt32 axisIndex, out YKS_AxisProfileModulo config);

		/// <summary>
		/// 获得单圈数量
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="counter">单圈数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisModuloCounter(Int32 handle, UInt32 axisIndex, out Int32 counter);

		/// <summary>
		/// 设置软限位
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">限位配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisSoftLimit(Int32 handle, UInt32 axisIndex, YKS_AxisSoftLimitConfig config);

		/// <summary>
		/// 获取软限位配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisSoftLimit(Int32 handle, UInt32 axisIndex, out YKS_AxisSoftLimitConfig config);

		/// <summary>
		/// 写入硬限位启用配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisHardLimitEnable(Int32 handle, UInt32 axisIndex, YKS_AxisHardLimitConfig config);

		/// <summary>
		/// 获取硬限位启用配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisHardLimitEnable(Int32 handle, UInt32 axisIndex, out YKS_AxisHardLimitConfig config);

		/// <summary>
		/// 设置最大转矩值
		/// 支持API缓冲区
		/// 对象字典(0x6072:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisMaxTorqueLimit(Int32 handle, UInt32 axisIndex, double value);

		/// <summary>
		/// 获取最大转矩值
		/// 对象字典(0x6072:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisMaxTorqueLimit(Int32 handle, UInt32 axisIndex, out double value);

		/// <summary>
		/// 设置正方向转矩限制值
		/// 支持API缓冲区
		/// 对象字典(0x60E0:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisPositiveTorqueLimit(Int32 handle, UInt32 axisIndex, double value);

		/// <summary>
		/// 获取正方向转矩限制值
		/// 对象字典(0x60E0:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisPositiveTorqueLimit(Int32 handle, UInt32 axisIndex, out double value);

		/// <summary>
		/// 设置负方向转矩限制值
		/// 支持API缓冲区
		/// 对象字典(0x60E1:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisNegativeTorqueLimit(Int32 handle, UInt32 axisIndex, double value);

		/// <summary>
		/// 获取负方向转矩限制值
		/// 对象字典(0x60E1:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisNegativeTorqueLimit(Int32 handle, UInt32 axisIndex, out double value);

		/// <summary>
		/// 设置最大电流限制值
		/// 支持API缓冲区
		/// 对象字典(0x6073:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">电流限制值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisMaxCurrentLimit(Int32 handle, UInt32 axisIndex, double value);

		/// <summary>
		/// 获取最大电流限制值
		/// 对象字典(0x6073:00)必须加到PDO中
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">电流限制值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisMaxCurrentLimit(Int32 handle, UInt32 axisIndex, out double value);

		/// <summary>
		/// 获得规划位置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisCommandPosition(Int32 handle, UInt32 axisIndex, out double position);

		/// <summary>
		/// 获得实际位置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisActualPosition(Int32 handle, UInt32 axisIndex, out double position);

		/// <summary>
		/// 获得目标位置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisTargetPosition(Int32 handle, UInt32 axisIndex, out double position);

		/// <summary>
		/// 获取轴的原始位置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisRawPosition(Int32 handle, UInt32 axisIndex, out Int32 position);

		/// <summary>
		/// 获得规划速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="velocity">速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisCommandVelocity(Int32 handle, UInt32 axisIndex, out double velocity);

		/// <summary>
		/// 获得实际速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="velocity">速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisActualVelocity(Int32 handle, UInt32 axisIndex, out double velocity);

		/// <summary>
		/// 获得规划加速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="acceleration">加速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisCommandAcceleration(Int32 handle, UInt32 axisIndex, out double acceleration);

		/// <summary>
		/// 获得变加速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="jerk">变加速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisCommandJerk(Int32 handle, UInt32 axisIndex, out double jerk);

		/// <summary>
		/// 获得给定转矩，需要在PDO中配置转矩对象字典
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="torque">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisCommandTorque(Int32 handle, UInt32 axisIndex, out double torque);

		/// <summary>
		/// 获得实际转矩，需要在PDO中配置转矩对象字典
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="torque">转矩值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisActualTorque(Int32 handle, UInt32 axisIndex, out double torque);

		/// <summary>
		/// 设置用户自定义数据
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="mask">掩码</param>
		/// <param name="value">写入值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisUserData(Int32 handle, UInt32 axisIndex, UInt32 mask, UInt32 value);

		/// <summary>
		/// 获取用户自定义数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="value">返回的值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisUserData(Int32 handle, UInt32 axisIndex, out UInt32 value);

		/// <summary>
		/// 读轴的基本配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisConfigBase(Int32 handle, UInt32 axisIndex, out YKS_AxisConfigBase config);

		/// <summary>
		/// 读轴规划状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisStatusPlanner(Int32 handle, UInt32 axisIndex, out YKS_AxisStatusPlanner status);

		/// <summary>
		/// 读轴位置相关状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisStatusPosition(Int32 handle, UInt32 axisIndex, out YKS_AxisStatusPosition status);

		/// <summary>
		/// 读轴机械补偿状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisStatusCompensation(Int32 handle, UInt32 axisIndex, out YKS_AxisStatusCompensation status);

		/// <summary>
		/// 读轴跟随状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisStatusFollow(Int32 handle, UInt32 axisIndex, out YKS_AxisStatusFollow status);

		/// <summary>
		/// 读轴基本状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisStatusBase(Int32 handle, UInt32 axisIndex, out YKS_AxisStatusBase status);

		/// <summary>
		/// 读轴触发状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisTriggerStatus(Int32 handle, UInt32 axisIndex, out YKS_AxisTriggerStatus status);

		/// <summary>
		/// 轴公共参数设置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">轴配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfileBase(Int32 handle, UInt32 axisIndex, YKS_AxisProfileBase config);

		/// <summary>
		/// 获得轴公共参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">轴配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfileBase(Int32 handle, UInt32 axisIndex, out YKS_AxisProfileBase config);

		/// <summary>
		/// 运动参数设置
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfileMotion(Int32 handle, UInt32 axisIndex, YKS_AxisProfileMotion config);

		/// <summary>
		/// 获得运动参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfileMotion(Int32 handle, UInt32 axisIndex, out YKS_AxisProfileMotion config);

		/// <summary>
		/// 设置轴到位配置
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">到位配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfileInp(Int32 handle, UInt32 axisIndex, YKS_AxisProfileInp config);

		/// <summary>
		/// 获取轴到位配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">到位配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfileInp(Int32 handle, UInt32 axisIndex, out YKS_AxisProfileInp config);

		/// <summary>
		/// 设置轴跟随误差配置
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">跟随误差配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfilePositionLag(Int32 handle, UInt32 axisIndex, YKS_AxisProfilePositionLag config);

		/// <summary>
		/// 获取轴跟随配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">跟随误差配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfilePositionLag(Int32 handle, UInt32 axisIndex, out YKS_AxisProfilePositionLag config);

		/// <summary>
		/// 获得轴使用列表
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisNum">返回值，轴数量</param>
		/// <param name="axisList">轴序号列表</param>
		/// <param name="size">axisList缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisList(Int32 handle, out UInt32 axisNum, UInt32[] axisList, UInt32 size);

		/// <summary>
		/// 设置驱动器控制模式，总线轴专用
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="mode">模式</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisDrvOpMode(Int32 handle, UInt32 axisIndex, YKE_DRV_OP_MODE mode);

		/// <summary>
		/// 获取驱动器控制模式，总线轴专用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="mode">模式</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisDrvOpMode(Int32 handle, UInt32 axisIndex, out YKE_DRV_OP_MODE mode);

		/// <summary>
		/// 设置轴报警屏蔽配置
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="mask">屏蔽配置，按位定义 BIT0=硬限位 BIT1=保留 BIT2=软限位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisWarnMask(Int32 handle, UInt32 axisIndex, UInt32 mask);

		/// <summary>
		/// 获取轴报警屏蔽配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="mask">屏蔽配置，按位定义 BIT0=硬限位  BIT1=保留 BIT2=软限位</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisWarnMask(Int32 handle, UInt32 axisIndex, out UInt32 mask);

		/// <summary>
		/// 获取轴名称，名称在ProEn中设置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="name">返回名称，至少分配64字节</param>
		/// <param name="size">name缓冲区尺寸</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisAlias(Int32 handle, UInt32 axisIndex, Byte[] name, UInt32 size);

		/// <summary>
		/// 清除轴的回原完成状态(YKS_AxisStatusBase.is_homed)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearAxisHomed(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 设置轴的回原完成状态(YKS_AxisStatusBase.is_homed)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisHomed(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 将指编码器指定位置设为原点
		/// 绝对值编码器工况下使用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="encoder_value">设定值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisHomeAbsEncoder(Int32 handle, UInt32 axisIndex, Int32 encoder_value);

		/// <summary>
		/// 获取原点对应的编码器值(由YKM_SetAxisHomeAbsEncoder写入)
		/// 绝对值编码器工况下使用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="encoder_value">返回值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisHomeAbsEncoder(Int32 handle, UInt32 axisIndex, out Int32 encoder_value);

		/// <summary>
		/// 写入正限位开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchLimitPositive(Int32 handle, UInt32 axisIndex, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 读取正限位开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchLimitPositive(Int32 handle, UInt32 axisIndex, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 写入负限位开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchLimitNegative(Int32 handle, UInt32 axisIndex, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 读取负限位开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchLimitNegative(Int32 handle, UInt32 axisIndex, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 写入原点开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchHome(Int32 handle, UInt32 axisIndex, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 读取原点开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchHome(Int32 handle, UInt32 axisIndex, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 写入探针开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号 (0~1)  0/1为硬件探针函数使用</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchProbe(Int32 handle, UInt32 axisIndex, UInt32 channel, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 读取探针开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号 (0~1)  0/1为硬件探针函数使用</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchProbe(Int32 handle, UInt32 axisIndex, UInt32 channel, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 写入回原探针开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetHomeProbe(Int32 handle, UInt32 axisIndex, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 读取回原探针开关配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetHomeProbe(Int32 handle, UInt32 axisIndex, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 设置当前位置，将当前位置设置为指定值
		/// 支持API缓冲区
		/// 会清除IsHomed信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">指定位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisPosition(Int32 handle, UInt32 axisIndex, double position);

		/// <summary>
		/// 设置清除驱动器报警重试参数，总线轴有效
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="profile"></param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfileClearDrv(Int32 handle, UInt32 axisIndex, YKS_AxisProfileClearDrv profile);

		/// <summary>
		/// 获取清除驱动器报警重试参数，总线轴有效
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="profile">返回配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfileClearDrv(Int32 handle, UInt32 axisIndex, out YKS_AxisProfileClearDrv profile);

		/// <summary>
		/// 清除驱动器报警
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearDrvWarn(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 复位轴状态，清除报警
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearAxisWarn(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 获取轴使能参数，总线轴有效
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="profile">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfilePowerOn(Int32 handle, UInt32 axisIndex, out YKS_AxisProfilePowerOn profile);

		/// <summary>
		/// 设置轴使能参数，总线轴有效
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="profile">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfilePowerOn(Int32 handle, UInt32 axisIndex, YKS_AxisProfilePowerOn profile);

		/// <summary>
		/// 获取轴前馈参数，总线轴有效
		/// 未实现
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="profile">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProfileFeedforward(Int32 handle, UInt32 axisIndex, out YKS_AxisProfileFeedforward profile);

		/// <summary>
		/// 设置轴前馈参数，总线轴有效
		/// 未实现
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="profile">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProfileFeedforward(Int32 handle, UInt32 axisIndex, YKS_AxisProfileFeedforward profile);

		/// <summary>
		/// 轴使能
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_PowerOn(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 轴去使能
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_PowerOff(Int32 handle, UInt32 axisIndex);
		#endregion

		#region 单轴运动
		/// <summary>
		/// 单轴停止
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="dec_sel">减速度选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopAxis(Int32 handle, UInt32 axisIndex, YKE_STOP_DEC dec_sel);

		/// <summary>
		/// 触发轴停止
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="dec_sel">减速度选择</param>
		/// <param name="trigger">触发条件</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopAxisTrigger(Int32 handle, UInt32 axisIndex, YKE_STOP_DEC dec_sel, YKS_AxisTrigger trigger);

		/// <summary>
		/// 启动回原点
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartHome(Int32 handle, UInt32 axisIndex, YKS_AxisHomeConfig config);

		/// <summary>
		/// 获取回原点配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetHomeConfig(Int32 handle, UInt32 axisIndex, out YKS_AxisHomeConfig config);

		/// <summary>
		/// 绝对运动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">目标位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveAbsolute(Int32 handle, UInt32 axisIndex, double position);

		/// <summary>
		/// 绝对运动(带运动参数)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveAbsoluteEx(Int32 handle, UInt32 axisIndex, YKS_MoveAbsoluteConfig config);

		/// <summary>
		/// 绝对运动(条件触发)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <param name="trigger">触发条件</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveAbsoluteTrigger(Int32 handle, UInt32 axisIndex, YKS_MoveAbsoluteConfig config, YKS_AxisTrigger trigger);

		/// <summary>
		/// 绝对运动(事件触发)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveAbsoluteEvent(Int32 handle, UInt32 axisIndex, YKS_MoveAbsoluteConfig config);

		/// <summary>
		/// 相对运动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="distance">移动距离</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveRelative(Int32 handle, UInt32 axisIndex, double distance);

		/// <summary>
		/// 相对运动(带运动参数)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveRelativeEx(Int32 handle, UInt32 axisIndex, YKS_MoveRelativeConfig config);

		/// <summary>
		/// 相对运动(条件触发)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <param name="trigger">触发条件</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveRelativeTrigger(Int32 handle, UInt32 axisIndex, YKS_MoveRelativeConfig config, YKS_AxisTrigger trigger);

		/// <summary>
		/// 相对运动(事件触发)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveRelativeEvent(Int32 handle, UInt32 axisIndex, YKS_MoveRelativeConfig config);

		/// <summary>
		/// 运动仿真
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <param name="result">规划结果</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MovePositionSim(Int32 handle, UInt32 axisIndex, YKS_MovePositionSimConfig config, out YKS_MovePositionSimResult result);

		/// <summary>
		/// 运动仿真，带变参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <param name="trigger">变参数配置</param>
		/// <param name="result">规划结果</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MovePositionSimEx(Int32 handle, UInt32 axisIndex, YKS_MovePositionSimConfig config, YKS_MovePositionSimTrigger trigger, out YKS_MovePositionSimResult result);

		/// <summary>
		/// 速度运动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="velocity">新速度</param>
		/// <param name="direction">运动方向</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveVelocity(Int32 handle, UInt32 axisIndex, double velocity, YKE_DIRECTION direction);

		/// <summary>
		/// 速度运动(带运动参数)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveVelocityEx(Int32 handle, UInt32 axisIndex, YKS_MoveVelocityConfig config);

		/// <summary>
		/// 传送带运动
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveConveyor(Int32 handle, UInt32 axisIndex, YKS_MoveConveyorConfig config);

		/// <summary>
		/// 写入单信号事件触发条件
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">保留，固定为0</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteAxisEventOneSignal(Int32 handle, UInt32 axisIndex, UInt32 channel, YKS_TriggerArgOneSignal config);

		/// <summary>
		/// 写入双信号事件触发条件
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">保留，固定为0</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteAxisEventTwoSignal(Int32 handle, UInt32 axisIndex, UInt32 channel, YKS_TriggerArgTwoSignal config);

		/// <summary>
		/// 速度运动(条件触发)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <param name="trigger">触发条件</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveVelocityTrigger(Int32 handle, UInt32 axisIndex, YKS_MoveVelocityConfig config, YKS_AxisTrigger trigger);

		/// <summary>
		/// 速度运动(事件触发)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">运动配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveVelocityEvent(Int32 handle, UInt32 axisIndex, YKS_MoveVelocityConfig config);

		/// <summary>
		/// 转矩运动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveTorque(Int32 handle, UInt32 axisIndex, YKS_MoveTorqueConfig config);

		/// <summary>
		/// 修改目标位置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">新的位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_OverridePosition(Int32 handle, UInt32 axisIndex, double position);

		/// <summary>
		/// 修改目标速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="velocity">新的速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_OverrideVelocity(Int32 handle, UInt32 axisIndex, double velocity);

		/// <summary>
		/// 修改加速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="acc">新的加速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_OverrideAcceleration(Int32 handle, UInt32 axisIndex, double acc);

		/// <summary>
		/// 修改减速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="dec">新的减速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_OverrideDeceleration(Int32 handle, UInt32 axisIndex, double dec);

		/// <summary>
		/// 修改加速度过程的变加速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="jerk_acc">新的变加速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_OverrideJerkAcc(Int32 handle, UInt32 axisIndex, double jerk_acc);

		/// <summary>
		/// 修改减速过程的变加速度
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="jerk_dec">新的变加速度</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_OverrideJerkDec(Int32 handle, UInt32 axisIndex, double jerk_dec);

		/// <summary>
		/// 在指定位置生效新参数
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="motion">新的运动参数</param>
		/// <param name="position">指定位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_OverrideAtPosition(Int32 handle, UInt32 axisIndex, YKS_AxisProfileMotion motion, double position);
		#endregion

		#region PVT
		/// <summary>
		/// 写入PT数据，支持动态添加
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="data">配置</param>
		/// <param name="size">数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WritePTData(Int32 handle, UInt32 axisIndex, YKS_PTData[] data, UInt32 size);

		/// <summary>
		/// 写入PVT数据，支持动态添加
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="data">配置</param>
		/// <param name="size">数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WritePVTData(Int32 handle, UInt32 axisIndex, YKS_PVTData[] data, UInt32 size);

		/// <summary>
		/// 写入PVTS数据
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="start_velocity">启动速度</param>
		/// <param name="end_velocity">停止速度</param>
		/// <param name="data">配置</param>
		/// <param name="size">数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WritePVTSData(Int32 handle, UInt32 axisIndex, double start_velocity, double end_velocity, YKS_PVTSData[] data, UInt32 size);

		/// <summary>
		/// 启动PT运动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MovePVTStart(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 同时启动多轴的PT运动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisNum">轴数量, 最大32轴</param>
		/// <param name="axisList">轴序号列表</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveMultiPVTStart(Int32 handle, UInt32 axisNum, UInt32[] axisList);

		/// <summary>
		/// 获取PVT缓冲区状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">返回状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadPVTStatus(Int32 handle, UInt32 axisIndex, out YKS_PVTStatus status);

		/// <summary>
		/// 清除PVT数据
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearPVTData(Int32 handle, UInt32 axisIndex);
		#endregion

		#region 跟随运动
		/// <summary>
		/// 轴跟随其他单轴
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_FollowAxis1(Int32 handle, UInt32 axisIndex, YKS_FollowAxis1Config config);

		/// <summary>
		/// 轴跟随其他2轴
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_FollowAxis2(Int32 handle, UInt32 axisIndex, YKS_FollowAxis2Config config);

		/// <summary>
		/// 轴跟随UG数据
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_FollowUG(Int32 handle, UInt32 axisIndex, YKS_FollowUgConfig config);

		/// <summary>
		/// 轴跟随本地编码器
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_FollowEncoderPCI(Int32 handle, UInt32 axisIndex, YKS_FollowEncoderConfig config);

		/// <summary>
		///	轴跟随坐标系数据
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_FollowGroup(Int32 handle, UInt32 axisIndex, YKS_FollowGroupConfig config);
		#endregion

		#region 电子凸轮
		/// <summary>
		/// 写入凸轮配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">写入配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCamInConfig(Int32 handle, UInt32 axisIndex, YKS_CamInConfig config);

		/// <summary>
		/// 读取凸轮配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">返回配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCamInConfig(Int32 handle, UInt32 axisIndex, out YKS_CamInConfig config);

		/// <summary>
		/// 设置凸轮表数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="rowIndex">表行数</param>
		/// <param name="data">数据</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCamTable(Int32 handle, UInt32 axisIndex, UInt32 rowIndex, YKS_CamTable data);

		/// <summary>
		/// 获取凸轮表的一行数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="rowIndex">表行号，从0开始</param>
		/// <param name="data">行数据</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCamTable(Int32 handle, UInt32 axisIndex, UInt32 rowIndex, out YKS_CamTable data);

		/// <summary>
		/// 启动凸轮
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartCamIn(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 凸轮表求解，厂家使用
		/// </summary>
		/// <param name="table">输入数据</param>
		/// <param name="size">数据数量</param>
		/// <param name="result">解析结果</param>
		/// <param name="type">曲线类型</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_CalcCam(YKS_CamTable[] table, UInt32 size, double[] result, YKE_CAM_CURVE type);

		/// <summary>
		/// 获取凸轮表插值，厂家使用
		/// </summary>
		/// <param name="result">解析结果</param>
		/// <param name="size">数据数量</param>
		/// <param name="key">输入值</param>
		/// <param name="value">输出值</param>
		/// <param name="type">曲线类型</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCam(double[] result, UInt32 size, double key, out double value, YKE_CAM_CURVE type);
		#endregion

		#region 多轴同步运动
		/// <summary>
		/// 直线插补，相对模式
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="config">参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_LinearInterpolationRelative(Int32 handle, UInt32 channel, YKS_LinearInterpolationRelativeConfig config);

		/// <summary>
		/// 直线插补，绝对模式
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="config">参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_LinearInterpolationAbsolute(Int32 handle, UInt32 channel, YKS_LinearInterpolationAbsoluteConfig config);

		/// <summary>
		/// 多轴直线同步运动，绝对模式
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="config">参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_LinearSyncAbsolute(Int32 handle, UInt32 channel, YKS_LinearSyncAbsoluteConfig config);

		/// <summary>
		/// 多轴直线同步运动，相对模式
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="config">参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_LinearSyncRelative(Int32 handle, UInt32 channel, YKS_LinearSyncRelativeConfig config);

		/// <summary>
		/// 圆弧运动，相对模式
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="config">参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_CircularInterpolationRelative(Int32 handle, UInt32 channel, YKS_CircularInterpolationRelativeConfig config);

		/// <summary>
		/// 圆弧运动，绝对模式
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="config">参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_CircularInterpolationAbsolute(Int32 handle, UInt32 channel, YKS_CircularInterpolationAbsoluteConfig config);

		/// <summary>
		/// 停止多轴联动
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="dec_sel">保留</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopMultiAxis(Int32 handle, UInt32 channel, YKE_STOP_DEC dec_sel);

		/// <summary>
		/// 获取多轴联动状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道序号 0~127</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadMultiAxisStatus(Int32 handle, UInt32 channel, out YKS_MultiAxisStatus status);

		/// <summary>
		/// 多轴同时启动，绝对模式
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveSyncAbsolute(Int32 handle, YKS_SyncStartConfig config);
		#endregion

		#region 坐标系运动
		/// <summary>
		/// 设置坐标系参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetGroupProfile(Int32 handle, UInt32 groupIndex, YKS_GroupProfile config);

		/// <summary>
		/// 获取坐标系参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetGroupProfile(Int32 handle, UInt32 groupIndex, out YKS_GroupProfile config);

		/// <summary>
		/// 坐标系轴绑定,2到32轴
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_InitGroup(Int32 handle, UInt32 groupIndex, YKS_GroupConfig config);

		/// <summary>
		/// 获取坐标系绑定配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetGroupConfig(Int32 handle, UInt32 groupIndex, out YKS_GroupConfig config);

		/// <summary>
		/// 将轴从坐标系移出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_DeInitGroup(Int32 handle, UInt32 groupIndex);

		/// <summary>
		/// 写CNC通道配置，在坐标系初始化前调用生效
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">CNC通道配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCncProfile(Int32 handle, UInt32 groupIndex, YKS_CncProfile config);

		/// <summary>
		/// 读CNC通道配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">CNC通道配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCncProfile(Int32 handle, UInt32 groupIndex, out YKS_CncProfile config);

		/// <summary>
		/// 获取坐标系基础状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="status">状态值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadGroupStatusBase(Int32 handle, UInt32 groupIndex, out YKS_GroupStatusBase status);

		/// <summary>
		/// 获取坐标系CNC状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="status">状态值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadGroupStatusCnc(Int32 handle, UInt32 groupIndex, out YKS_GroupStatusCnc status);

		/// <summary>
		/// 清除坐标系报警
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearGroupWarn(Int32 handle, UInt32 groupIndex);

		/// <summary>
		/// 停止坐标系运动
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="dec_sel">停止减速度选择</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopGroup(Int32 handle, UInt32 groupIndex, YKE_STOP_DEC dec_sel);

		/// <summary>
		/// 启动坐标系运动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartGroup(Int32 handle, UInt32 groupIndex);

		/// <summary>
		/// 暂停坐标系运行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_PauseGroup(Int32 handle, UInt32 groupIndex);

		/// <summary>
		/// 坐标系内直线插补，绝对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveLinearAbsolute(Int32 handle, UInt32 groupIndex, YKS_MoveLinearAbsoluteConfig config);

		/// <summary>
		/// 坐标系内直线插补，相对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveLinearRelative(Int32 handle, UInt32 groupIndex, YKS_MoveLinearRelativeConfig config);

		/// <summary>
		/// 坐标系内螺旋插补，绝对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveHelixAbsolute(Int32 handle, UInt32 groupIndex, YKS_MoveHelixAbsoluteConfig config);

		/// <summary>
		/// 坐标系内螺旋插补，相对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveHelixRelative(Int32 handle, UInt32 groupIndex, YKS_MoveHelixRelativeConfig config);

		/// <summary>
		/// 坐标系内圆弧插补，绝对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveCircularAbsolute(Int32 handle, UInt32 groupIndex, YKS_MoveCircularAbsoluteConfig config);

		/// <summary>
		/// 坐标系内圆弧插补，相对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveCircularRelative(Int32 handle, UInt32 groupIndex, YKS_MoveCircularRelativeConfig config);

		/// <summary>
		/// Cardinal样条插补，相对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveCardinalRelative(Int32 handle, UInt32 groupIndex, YKS_MoveCardinalRelativeConfig config);

		/// <summary>
		/// Cardinal样条插补，绝对模式
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_MoveCardinalAbsolute(Int32 handle, UInt32 groupIndex, YKS_MoveCardinalAbsoluteConfig config);

		/// <summary>
		/// 坐标系内数字输出，参考下一段运动行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupDigitalOutput(Int32 handle, UInt32 groupIndex, YKS_GroupDoConfig config);

		/// <summary>
		/// 坐标系内PWM输出，参考下一段运动行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">PWM输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupPwmOutput(Int32 handle, UInt32 groupIndex, YKS_GroupPwmConfig config);

		/// <summary>
		/// 坐标系内写入PDO，参考下一段运动行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">PDO配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWritePDO(Int32 handle, UInt32 groupIndex, YKS_GroupWritePdoConfig config);

		/// <summary>
		/// 坐标系内写入通用数据寄存器，参考下一段运动行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">VD配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWriteRegister(Int32 handle, UInt32 groupIndex, YKS_GroupWriteRegisterConfig config);

		/// <summary>
		/// 坐标系内启动事件，参考下一段运动行
		/// </summary>
		/// <param name="handle"></param>
		/// <param name="groupIndex"></param>
		/// <param name="config"></param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWriteEvent(Int32 handle, UInt32 groupIndex, YKS_GroupWriteEventConfig config);

		/// <summary>
		/// Cardinal样条插补参数设置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWriteTensive(Int32 handle, UInt32 groupIndex, YKS_GroupCardinalConfig config);

		/// <summary>
		/// 坐标系外轴相对运动配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupMoveRelative(Int32 handle, UInt32 groupIndex, YKS_GroupMoveRelativeConfig config);

		/// <summary>
		/// 坐标系外轴绝对运动配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupMoveAbsolute(Int32 handle, UInt32 groupIndex, YKS_GroupMoveAbsoluteConfig config);

		/// <summary>
		/// 坐标系内延时
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">延时配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupDelay(Int32 handle, UInt32 groupIndex, YKS_GroupDelayConfig config);

		/// <summary>
		/// 坐标系内等待数字输入
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">数字输入配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWaitDigitalInput(Int32 handle, UInt32 groupIndex, YKS_GroupDigitalInputConfig config);

		/// <summary>
		/// 坐标系内等待外轴完成
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">外轴配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWaitAxis(Int32 handle, UInt32 groupIndex, YKS_GroupWaitAxisConfig config);

		/// <summary>
		/// 坐标系内等待PDO数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">PDO配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWaitPdo(Int32 handle, UInt32 groupIndex, YKS_GroupWaitPdoConfig config);

		/// <summary>
		/// 坐标系内等待通用数据寄存器
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">寄存器配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWaitRegister(Int32 handle, UInt32 groupIndex, YKS_GroupWaitRegisterConfig config);

		/// <summary>
		/// 坐标系内等待事件信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">事件配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWaitEvent(Int32 handle, UInt32 groupIndex, YKS_GroupWaitEventConfig config);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">Mark配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupTransMarkOn(Int32 handle, UInt32 groupIndex, YKS_GroupTransMarkConfig config);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupTransMarkOff(Int32 handle, UInt32 groupIndex);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系编号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupAddiXYOn(Int32 handle, UInt32 groupIndex, YKS_GroupAddiXYConfig config);

		/// <summary>
		/// 保留
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系编号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupAddiXYOff(Int32 handle, UInt32 groupIndex);

		/// <summary>
		/// 视觉Mark转换
		/// </summary>
		/// <param name="ptRef">图纸坐标</param>
		/// <param name="ptReal">实际坐标</param>
		/// <param name="config">转换结果</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_CalcMark(double[] ptRef, double[] ptReal, out YKS_GroupTransMarkConfig config);
		#endregion

		#region CNC控制
		/// <summary>
		/// 写G代码命令
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">G代码</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupWriteGCode(Int32 handle, UInt32 groupIndex, YKS_CncGCode config);

		/// <summary>
		/// 加载NC文件进行加工
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="filename">文件全路径</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupLoadFile(Int32 handle, UInt32 groupIndex, Byte[] filename);

		/// <summary>
		/// 基于控制点的AKIMA样条配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncASpline(Int32 handle, UInt32 groupIndex, YKS_CncASplineConfig config);

		/// <summary>
		/// 关闭样条平滑
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="mark">用户标记</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncSplineClose(Int32 handle, UInt32 groupIndex, UInt32 mark);

		/// <summary>
		/// CNC轮廓角偏差平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncContourDev(Int32 handle, UInt32 groupIndex, YKS_CncContourDevConfig config);

		/// <summary>
		/// CNC轮廓角距离平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncContourDist(Int32 handle, UInt32 groupIndex, YKS_CncContourDistConfig config);

		/// <summary>
		/// CNC动态轮廓优化平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncContourDistSoft(Int32 handle, UInt32 groupIndex, YKS_CncContourDistSoftConfig config);

		/// <summary>
		/// CNC进给主轴动态轮廓优化平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config"></param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncContourDistMaster(Int32 handle, UInt32 groupIndex, YKS_CncContourDistMasterConfig config);

		/// <summary>
		/// CNC插入点平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncContourPos(Int32 handle, UInt32 groupIndex, YKS_CncContourPosConfig config);

		/// <summary>
		/// CNC完整轮廓动态优化平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncContourPtp(Int32 handle, UInt32 groupIndex, YKS_CncContourPtpConfig config);

		/// <summary>
		/// 关闭轮廓平滑
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="mark">用户标记</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncContourClose(Int32 handle, UInt32 groupIndex, UInt32 mark);

		/// <summary>
		/// HSC_B样条平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncHscB(Int32 handle, UInt32 groupIndex, YKS_CncHscBConfig config);

		/// <summary>
		/// HSC_Surface平滑配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncHscS(Int32 handle, UInt32 groupIndex, YKS_CncHscSConfig config);

		/// <summary>
		/// HSC_PCS1平滑参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncHscPcs1(Int32 handle, UInt32 groupIndex, YKS_CncHscPcs1Config config);

		/// <summary>
		/// HSC_PCS2平滑参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncHscPcs2(Int32 handle, UInt32 groupIndex, YKS_CncHscPcs2Config config);

		/// <summary>
		/// 关闭HSC平滑
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="groupIndex">坐标系序号</param>
		/// <param name="mark">用户标记</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GroupCncHscClose(Int32 handle, UInt32 groupIndex, UInt32 mark);

		/// <summary>
		/// 读CNC的轴参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="para_name">参数名称</param>
		/// <param name="size_name">参数数据缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadCncParaCmd(Int32 handle, UInt32 axisIndex, Byte[] para_name, UInt32 size_name);

		/// <summary>
		/// 写CNC的轴参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="para_name">参数名称</param>
		/// <param name="size_name">参数数据缓冲区大小</param>
		/// <param name="para_value">参数值</param>
		/// <param name="size_value">值缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteCncParaCmd(Int32 handle, UInt32 axisIndex, Byte[] para_name, UInt32 size_name, Byte[] para_value, UInt32 size_value);

		/// <summary>
		/// 读CNC参数操作状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="status">返回状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadCncParaStatus(Int32 handle, UInt32 axisIndex, out YKS_CncParaStatus status);
		#endregion

		#region 探针
		/// <summary>
		/// 启动硬件探针
		/// 总线轴探针参数在总线节点中设置
		/// 脉冲轴探针参数在脉冲节点中设置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号 (0~1)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartProbeHard(Int32 handle, UInt32 axisIndex, UInt32 channel);

		/// <summary>
		/// 停止硬件探针
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号 (0~1)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopProbeHard(Int32 handle, UInt32 axisIndex, UInt32 channel);

		/// <summary>
		/// 获取硬件探针状态及值
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号 (0~1)</param>
		/// <param name="status">返回状态 0=未完成 1=完成</param>
		/// <param name="position">返回的探针位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadProbeStatusHard(Int32 handle, UInt32 axisIndex, UInt32 channel, out UInt32 status, out double position);

		/// <summary>
		/// 获取轴软件探针配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号(0~3)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetAxisProbeConfigSoft(Int32 handle, UInt32 axisIndex, UInt32 channel, out YKS_AxisProbeConfigSoft config);

		/// <summary>
		/// 设置轴软件探针配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号(0~3)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetAxisProbeConfigSoft(Int32 handle, UInt32 axisIndex, UInt32 channel, YKS_AxisProbeConfigSoft config);

		/// <summary>
		/// 轴软件探针状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号(0~3)</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisProbeStatusSoft(Int32 handle, UInt32 axisIndex, UInt32 channel, out YKS_AxisProbeStatusSoft status);

		/// <summary>
		/// 轴软件探针启动
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号(0~3)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartAxisProbeSoft(Int32 handle, UInt32 axisIndex, UInt32 channel);

		/// <summary>
		/// 轴软件探针停止
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="channel">通道号(0~3)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopAxisProbeSoft(Int32 handle, UInt32 axisIndex, UInt32 channel);
		#endregion

		#region 控制事件
		/// <summary>
		/// 单IO触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">信号源</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputOneSignal(Int32 handle, UInt32 channel, YKS_TriggerArgOneSignal input);

		/// <summary>
		/// 双IO触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">信号源</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputTwoSignal(Int32 handle, UInt32 channel, YKS_TriggerArgTwoSignal input);

		/// <summary>
		/// 轴位置触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputAxisPosition(Int32 handle, UInt32 channel, YKS_TriggerArgAxisPosition input);

		/// <summary>
		/// 轴时间触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputAxisTime(Int32 handle, UInt32 channel, YKS_TriggerArgAxisTime input);

		/// <summary>
		/// 轴速度触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">信号源</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputAxisVelocity(Int32 handle, UInt32 channel, YKS_TriggerArgAxisVelocity input);

		/// <summary>
		/// 轴转矩触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">信号源</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputAxisTorque(Int32 handle, UInt32 channel, YKS_TriggerArgAxisTorque input);

		/// <summary>
		/// 从站PDO触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">信号源</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputSlavePDO(Int32 handle, UInt32 channel, YKS_TriggerArgSlavePDO input);

		/// <summary>
		/// 编码器触发输入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
		/// <param name="input">信号源</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventInputEncoder(Int32 handle, UInt32 channel, YKS_TriggerArgEncoder input);

		/// <summary>
		/// 触发输出:位参数写入
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputOneSignal(Int32 handle, UInt32 channel, YKS_TriggerOutputOneBit output);

		/// <summary>
		/// 触发输出:停止轴
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputStopAxis(Int32 handle, UInt32 channel, YKS_TriggerOutputStopAxis output);

		/// <summary>
		/// 触发输出:启动坐标系
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputStartGroup(Int32 handle, UInt32 channel, YKS_TriggerOutputStartGroup output);

		/// <summary>
		/// 触发输出:启动单轴
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputStartAxis(Int32 handle, UInt32 channel, YKS_TriggerOutputStartAxis output);

		/// <summary>
		/// 触发输出:软急停
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputSoftEmgStop(Int32 handle, UInt32 channel, YKS_TriggerOutputSoftEmgStop output);

		/// <summary>
		/// 触发输出:写PDO
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">通道号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputSlavePDO(Int32 handle, UInt32 channel, YKS_TriggerOutputSlavePDO output);

		/// <summary>
		/// 触发输出:启动多轴联动
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <param name="motion">运动配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputMultiAxis(Int32 handle, UInt32 channel, YKS_TriggerOutputStartMultiAxis output, YKS_LinearSyncAbsoluteConfig motion);

		/// <summary>
		/// 触发输出:写目标转矩
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputTargetTorque(Int32 handle, UInt32 channel, YKS_TriggerOutputTargetTorque output);

		/// <summary>
		/// 触发输出:延时
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputDelayMs(Int32 handle, UInt32 channel, YKS_TriggerOutputDelayMs output);

		/// <summary>
		/// 触发输出:写通用数据寄存器
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
		/// <param name="output">输出配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEventOutputDataReg(Int32 handle, UInt32 channel, YKS_TriggerOutputDataReg output);

		/// <summary>
		/// 启动事件
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,1023)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_EnableEvent(Int32 handle, UInt32 channel);

		/// <summary>
		/// 禁用事件
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,1023)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_DisableEvent(Int32 handle, UInt32 channel);

		/// <summary>
		/// 获取事件状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="status">返回的状态</param>
		/// <param name="channel">通道[0,1023)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadEventStatus(Int32 handle, UInt32 channel, out YKS_EventStatus status);
		#endregion

		#region PCI硬件卡
		/// <summary>
		/// 获取PCI控制数量
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="num">返回数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCardNumPCI(Int32 handle, out UInt32 num);

		/// <summary>
		/// 获取PCI控制卡信息
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCardConfigPCI(Int32 handle, UInt32 card_index, out YKS_CardConfigPCI config);

		/// <summary>
		/// 获取脉冲轴的IO状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="status">IO状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadAxisStatusPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_AxisStausPCI status);

		/// <summary>
		/// 设置脉冲轴的驱动Ready信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchDrvReadyPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 获取脉冲轴的驱动Ready信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchDrvReadyPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 设置脉冲轴的驱动报警信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchDrvWarnPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 获取脉冲轴的驱动报警信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchDrvWarnPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 设置脉冲轴的驱动到位信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchDrvInpPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 获取脉冲轴的驱动到位信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchDrvInpPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 设置脉冲轴的驱动使能信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchDrvEnablePCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 获取脉冲轴的驱动使能信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchDrvEnablePCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 设置脉冲轴的驱动复位信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetSwitchDrvResetPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_AxisSwitchConfig config);

		/// <summary>
		/// 获取脉冲轴的驱动复位信号
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetSwitchDrvResetPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_AxisSwitchConfig config);

		/// <summary>
		/// 参数配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">编码器序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetEncoderConfigPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_EncoderConfig config);

		/// <summary>
		/// 获取配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">编码器序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetEncoderConfigPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_EncoderConfig config);

		/// <summary>
		/// 设置编码器的当前值
		/// Xmen:只能设0
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">编码器序号</param>
		/// <param name="value">当前值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteEncoderValuePCI(Int32 handle, UInt32 card_index, UInt32 channel, Int32 value);

		/// <summary>
		/// 获取编码器的当前值
		/// Xmen:只能设0
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">编码器序号</param>
		/// <param name="value">当前值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadEncoderValuePCI(Int32 handle, UInt32 card_index, UInt32 channel, out Int32 value);

		/// <summary>
		/// 编码器开始计数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">编码器序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartEncoderPCI(Int32 handle, UInt32 card_index, UInt32 channel);

		/// <summary>
		/// 编码器停止计数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">编码器序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopEncoderPCI(Int32 handle, UInt32 card_index, UInt32 channel);

		/// <summary>
		/// 比较器参数配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">比较器序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCompareConfigPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_CompareConfig config);

		/// <summary>
		/// 获取比较器参数配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">比较器序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCompareConfigPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_CompareConfig config);

		/// <summary>
		/// 设置比较值
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">比较器序号</param>
		/// <param name="itemdata">比较配置，内部含有512个缓冲区</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCompareValuePCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_CompareItemData itemdata);

		/// <summary>
		/// 获取比较器状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">比较器序号</param>
		/// <param name="status">返回值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadCompareStatusPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_CompareStatus status);

		/// <summary>
		/// 比较器开始
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">比较器序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartComparePCI(Int32 handle, UInt32 card_index, UInt32 channel);

		/// <summary>
		/// 停止比较器
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">比较器序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopComparePCI(Int32 handle, UInt32 card_index, UInt32 channel);

		/// <summary>
		/// 锁存器参数配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">锁存器序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCaptureConfigPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_CaptureConfig config);

		/// <summary>
		/// 获取锁存器参数配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">锁存器序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCaptureConfigPCI(Int32 handle, UInt32 card_index, UInt32 channel, out YKS_CaptureConfig config);

		/// <summary>
		/// 获取锁存器的状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">锁存器序号</param>
		/// <param name="status">0:无数据 1:有数据</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadCaptureStatusPCI(Int32 handle, UInt32 card_index, UInt32 channel, out UInt32 status);

		/// <summary>
		/// 获取锁存器的当前值
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">锁存器序号</param>
		/// <param name="value">锁存值</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadCaptureValuePCI(Int32 handle, UInt32 card_index, UInt32 channel, out Int32 value);

		/// <summary>
		/// 锁存器开始
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">锁存器序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartCapturePCI(Int32 handle, UInt32 card_index, UInt32 channel);

		/// <summary>
		/// 停止锁存器
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">锁存器序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopCapturePCI(Int32 handle, UInt32 card_index, UInt32 channel);

		/// <summary>
		/// 启动PWM输出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">通道号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartPwmPCI(Int32 handle, UInt32 card_index, UInt32 channel, YKS_PwmConfig config);

		/// <summary>
		/// 停止PWM输出
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="card_index">卡序号</param>
		/// <param name="channel">通道号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopPwmPCI(Int32 handle, UInt32 card_index, UInt32 channel);
		#endregion

		#region 机械补偿
		/// <summary>
		/// 设置间隙补偿参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetBacklashConfig(Int32 handle, UInt32 axisIndex, YKS_BacklashConfig config);

		/// <summary>
		/// 获取间隙补偿参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetBacklashConfig(Int32 handle, UInt32 axisIndex, out YKS_BacklashConfig config);

		/// <summary>
		/// 启用间隙补偿
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_EnableBacklash(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 禁用间隙补偿
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_DisableBacklash(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 设置螺距补偿配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetPitchError1DConfig(Int32 handle, UInt32 axisIndex, YKS_PitchError1DConfig config);

		/// <summary>
		/// 获取螺距补偿配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetPitchError1DConfig(Int32 handle, UInt32 axisIndex, out YKS_PitchError1DConfig config);

		/// <summary>
		/// 设置螺距补偿数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="pos_data">正向补偿数据</param>
		/// <param name="neg_data">负向补偿数据</param>
		/// <param name="size">单方向数据数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetPitchError1DData(Int32 handle, UInt32 axisIndex, double[] pos_data, double[] neg_data, UInt32 size);

		/// <summary>
		/// 获取螺距补偿数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="pos_data">正向补偿数据</param>
		/// <param name="neg_data">负向补偿数据</param>
		/// <param name="size">单方向数据数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetPitchError1DData(Int32 handle, UInt32 axisIndex, double[] pos_data, double[] neg_data, UInt32 size);

		/// <summary>
		/// 启用螺距补偿
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_EnablePitchError1D(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 禁用螺距补偿
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_DisablePitchError1D(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 设置二维补偿配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetPitchError2DConfig(Int32 handle, UInt32 axisIndex, YKS_PitchError2DConfig config);

		/// <summary>
		/// 获取二维补偿配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetPitchError2DConfig(Int32 handle, UInt32 axisIndex, out YKS_PitchError2DConfig config);

		/// <summary>
		/// 设置二维补偿数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="data">数据,先X后Y的排列方式</param>
		/// <param name="size">缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetPitchError2DData(Int32 handle, UInt32 axisIndex, double[] data, UInt32 size);

		/// <summary>
		/// 获取二维补偿数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="data">数据</param>
		/// <param name="size">缓冲区大小</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetPitchError2DData(Int32 handle, UInt32 axisIndex, double[] data, UInt32 size);

		/// <summary>
		/// 启用二维补偿
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_EnablePitchError2D(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 禁用二维补偿
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="axisIndex">轴序号</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_DisablePitchError2D(Int32 handle, UInt32 axisIndex);

		/// <summary>
		/// 设置圆形区域配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetCircleZoneConfig(Int32 handle, UInt32 channel, YKS_CircleZoneConfig config);

		/// <summary>
		/// 获取圆形区域配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetCircleZoneConfig(Int32 handle, UInt32 channel, out YKS_CircleZoneConfig config);

		/// <summary>
		/// 启用圆形区域保护
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_EnableCircleZone(Int32 handle, UInt32 channel);

		/// <summary>
		/// 禁用用圆形区域保护
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_DisableCircleZone(Int32 handle, UInt32 channel);

		/// <summary>
		/// 读取圆形区域状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
		/// <param name="status">状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadCircleZoneStatus(Int32 handle, UInt32 channel, out YKS_CircleZoneStatus status);
		#endregion

		#region 调试用
		/// <summary>
		/// 设置示波器配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetOscConfig(Int32 handle, UInt32 oscIndex, YKS_OscConfig config);

		/// <summary>
		/// 获取示波器配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetOscConfig(Int32 handle, UInt32 oscIndex, out YKS_OscConfig config);

		/// <summary>
		/// 设置示波器采集内容
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <param name="itemIndex">采集对象序号[0,YKE_OSC_ITEM_NUM)</param>
		/// <param name="item">采集配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetOscItem(Int32 handle, UInt32 oscIndex, UInt32 itemIndex, YKS_OscItem item);

		/// <summary>
		/// 获取示波器采集内容
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM</param>
		/// <param name="itemIndex">采集对象序号[0,YKE_OSC_ITEM_NUM)</param>
		/// <param name="item">采集配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_GetOscItem(Int32 handle, UInt32 oscIndex, UInt32 itemIndex, out YKS_OscItem item);

		/// <summary>
		/// 清除示波器所有通道配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ClearOscItem(Int32 handle, UInt32 oscIndex);

		/// <summary>
		/// 读示波器状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM))</param>
		/// <param name="status">返回的状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadOscStatus(Int32 handle, UInt32 oscIndex, out YKS_OscStatus status);

		/// <summary>
		/// 读示波器采集数据
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <param name="buffer">缓冲区地址</param>
		/// <param name="size">缓冲区尺寸</param>
		/// <param name="ret_size">返回的数据个数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadOscData(Int32 handle, UInt32 oscIndex, double[] buffer, UInt32 size, out UInt32 ret_size);

		/// <summary>
		/// 启动示波器采集
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartOsc(Int32 handle, UInt32 oscIndex);

		/// <summary>
		/// 停止示波器采集
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StopOsc(Int32 handle, UInt32 oscIndex);

		/// <summary>
		/// 示波器手动触发
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_TrigOsc(Int32 handle, UInt32 oscIndex);

		/// <summary>
		/// 写轴规划位置，厂家调试用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="magic"></param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="position">位置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WriteCommandPosition(Int32 handle, UInt32 magic, UInt32 axisIndex, double position);
		#endregion

		#region NTF
		/// <summary>
		/// 加载控制台类型的.NET应用程序到实时系统中运行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="exe_name">文件名及路径</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_LoadNTFDotNet(Int32 handle, YKE_NODE master, Byte[] exe_name);

		/// <summary>
		/// 检查NTF(C#)程序状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="exe_name">文件名，不包含路径</param>
		/// <param name="status">返回状态 FALSE=未启动 TRUE=已启动</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_CheckNTFDotNet(Int32 handle, YKE_NODE master, Byte[] exe_name, out YKE_BOOL status);

		/// <summary>
		/// 加载控制台类型的.rta应用程序到实时系统中运行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="file_name">路径及文件名</param>
		/// <param name="para">程序参数</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_LoadRtaApp(Int32 handle, YKE_NODE master, Byte[] file_name, Byte[] para);

		/// <summary>
		/// 检查RTA程序状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="rta_name">程序名称</param>
		/// <param name="status">返回状态 FALSE=未启动 TRUE=已启动</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_CheckRtaApp(Int32 handle, YKE_NODE master, Byte[] rta_name, out YKE_BOOL status);

		/// <summary>
		/// 强制关闭RTA程序
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="master">主站选择</param>
		/// <param name="rta_name">程序名称</param>
		/// <param name="status">返回状态 FALSE=未关闭 TRUE=已关闭</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_KillRtaApp(Int32 handle, YKE_NODE master, Byte[] rta_name, out YKE_BOOL status);

		/// <summary>
		/// 获取NTF打印日志，每次最多返回1行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="node">节点</param>
		/// <param name="buff">缓冲区地址</param>
		/// <param name="size">缓冲区大小</param>
		/// <param name="count">返回的字符数量</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadNTFLog(Int32 handle, YKE_NODE node, Byte[] buff, UInt32 size, out UInt32 count);

		/// <summary>
		/// 设置API缓冲区回调函数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="callback">回调函数句柄</param>
		/// <param name="size"></param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetApiBufferCallBack(Int32 handle, ulong[] callback, UInt32 size);

		/// <summary>
		/// API缓冲区开始记录
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号[0,YKE_API_BUFFER_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_StartApiBufferRecord(Int32 handle, UInt32 channel);

		/// <summary>
		/// API缓冲区停止记录
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号通道号[0,YKE_API_BUFFER_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_EndApiBufferRecord(Int32 handle, UInt32 channel);

		/// <summary>
		/// 设置API缓冲区Mark标记
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号通道号[0,YKE_API_BUFFER_NUM)</param>
		/// <param name="mark">用户标记</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SetApiBufferMark(Int32 handle, UInt32 channel, UInt32 mark);
		#endregion

		#region CoppeliaSim接口
		/// <summary>
		/// 连接Coppelia服务器
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="ipAddress">IP地址</param>
		/// <param name="port">端口</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SimConnect(Int32 handle, Byte[] ipAddress, UInt32 port);

		/// <summary>
		/// 设置关节
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="jointIndex">关节序号</param>
		/// <param name="jointName">关节名称</param>
		/// <param name="axisIndex">轴序号</param>
		/// <param name="axisType">轴类型</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SimJointConfig(Int32 handle, UInt32 jointIndex, Byte[] jointName, UInt32 axisIndex, YKE_AXIS_SIM_TYPE axisType);

		/// <summary>
		/// 仿真启动
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SimStart(Int32 handle);

		/// <summary>
		/// 仿真停止
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SimStop(Int32 handle);

		/// <summary>
		/// 断开连接
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_SimDisconnect(Int32 handle);
		#endregion

		#region 等待事件
		/// <summary>
		/// 等待轴信号(阻塞式)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WaitAxis(Int32 handle, UInt32 channel, YKS_WaitAxis config);

		/// <summary>
		/// 等待数字输入(阻塞式)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WaitDigitalInput(Int32 handle, UInt32 channel, YKS_WaitDigitalInput config);

		/// <summary>
		/// 等待事件信号(阻塞式)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
		/// <param name="config">配置</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WaitEvent(Int32 handle, UInt32 channel, YKS_WaitEvent config);

		/// <summary>
		/// 延时等待(阻塞式)
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
		/// <param name="time">延时时间(ms)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WaitSleepMs(Int32 handle, UInt32 channel, double time);

		/// <summary>
		/// 复位等待事件
		/// 支持API缓冲区
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_WaitReset(Int32 handle, UInt32 channel);

		/// <summary>
		/// 获取等待状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
		/// <param name="status">返回状态</param>
		/// <returns></returns>
		[DllImport("YKCat2.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern YKE_RESULT_CODE YKM_ReadWaitStatus(Int32 handle, UInt32 channel, out YKS_WaitStatus status);
		#endregion

		/// <summary>
		/// 当前报警数据转换
		/// </summary>
		/// <param name="num"></param>
		/// <param name="buff"></param>
		/// <returns></returns>
		public static List<String> TransWarns(UInt32 num, Byte[] buff)
		{
			List<String> result = new List<String>();
			UInt32 count = 0;
			UInt32 offset = 0;
		
			try
			{
				List<Byte> t = new List<Byte>();
				while ((count < num) && (offset < buff.Length))
				{
					if (0 == buff[offset])
					{
						String str = System.Text.Encoding.UTF8.GetString(t.ToArray());
						result.Add(str.Trim());
						t.Clear();
						count++;
					}
					else
					{
						t.Add(buff[offset]);
					}
					offset++;
				}
			}
			catch (Exception)
			{
			}
			return result;
		}
		
		/// <summary>
		/// 系统日志转换
		/// </summary>
		/// <param name="buff"></param>
		/// <returns></returns>
		public static String TransLog(Byte[] buff)
		{
			String str;
			try
			{
				if (0 == buff[0])
					return "";
				List<Byte> t = new List<Byte>();
				for (int idx = 0; idx < buff.Length; idx++)
				{
					if (0 == buff[idx])
						break;
					t.Add(buff[idx]);
				}
				str = System.Text.Encoding.UTF8.GetString(t.ToArray());
				str = str.Trim();
			}
			catch (System.Exception)
			{
				str = "";
			}
			return str;
		}
		
		/// <summary>
		/// 字符串与Byte数组转换
		/// </summary>
		/// <param name="str"></param>
		/// <returns></returns>
		public static Byte[] TransStr(String str)
		{
			Int32 len = str.Length;
			Byte[] buff = new Byte[len + 1];
			Array.Clear(buff, 0, buff.Length);
			try
			{
				for (int idx = 0; idx < len; idx++)
					buff[idx] = Convert.ToByte(str[idx]);
			}
			catch (System.Exception)
			{
			}
			return buff;
		}
		
	}
}




