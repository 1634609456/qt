#ifndef _YKCAT_
#define _YKCAT_

#pragma region 数据类型
typedef unsigned char UINT8;
typedef signed char INT8;

typedef unsigned short UINT16;
typedef short INT16;

typedef unsigned int UINT32;
typedef int INT32;

typedef signed long long INT64;
typedef unsigned long long UINT64;

#define YK_API YKE_RESULT_CODE __cdecl

typedef UINT32(*ApiBufferWriteInsDataType)(UINT32 channel, UINT32 mark, char* buffer, UINT32 buff_size);
typedef UINT32(*ApiBufferRecordType)(UINT32 channel);
#pragma endregion

#pragma region 枚举定义
/// <summary>
/// 系统定义
/// </summary>
typedef enum
{
	/// <summary>
	/// 魔数
	/// </summary>
	YKE_MAGIC_FLAG = 0x13575A5A,

	/// <summary>
	/// 对应ProCon版本
	/// </summary>
	YKE_PROCON_VER = 1531,

	/// <summary>
	/// 数字输入数量(bit)
	/// </summary>
	YKE_DIGITAL_INPUT_NUM = 4096,

	/// <summary>
	/// 数字输出数量(bit)
	/// </summary>
	YKE_DIGITAL_OUTPUT_NUM = 4096,

	/// <summary>
	/// 单次同步输出数量(bit)
	/// </summary>
	YKE_DIGITAL_OUTPUT_CYCLE_NUM = 1024,

	/// <summary>
	/// 最大的主站数量
	/// </summary>
	YKE_MASTER_NUM = 4,

	/// <summary>
	/// 示波器数量
	/// </summary>
	YKE_OSC_NUM = 8,

	/// <summary>
	/// 示波器通道数量
	/// </summary>
	YKE_OSC_ITEM_NUM = 64,

	/// <summary>
	/// 插补最大轴数量
	/// </summary>
	YKE_INTER_AXIS_NUM = 32,

	/// <summary>
	/// 软件位置比较通道数量
	/// </summary>
	YKE_SOFT_COMPARE_NUM = 128,

	/// <summary>
	/// 软件位置比较队列深度
	/// </summary>
	YKE_SOFT_COMPARE_DEPTH = 512,

	/// <summary>
	/// 软探针通道数量
	/// </summary>
	YKE_SOFT_PROBE_NUM = 128,

	/// <summary>
	/// 软探针数据缓存深度
	/// </summary>
	YKE_SOFT_PROBE_DEPTH = 512,

	/// <summary>
	/// 本地卡硬探针数据缓存深度
	/// </summary>
	YKE_HARD_PROBE_DEPTH = 512,

	/// <summary>
	/// 轴关联的软探针通道数量
	/// </summary>
	YKE_AXIS_SOFT_PROBE_NUM = 4,

	/// <summary>
	/// 螺距补偿最大点数
	/// </summary>
	YKE_PITCH1D_NUM = 2048,

	/// <summary>
	/// 二维补偿最大点数
	/// </summary>
	YKE_PITCH2D_NUM = 512,

	/// <summary>
	/// 控制事件通道数量
	/// </summary>
	YKE_EVENT_NUM = 1024,

	/// <summary>
	/// 等待事件通道数量
	/// </summary>
	YKE_WAIT_NUM = 1024,

	/// <summary>
	/// 坐标系数量
	/// </summary>
	YKE_GROUP_NUM = 32,

	/// <summary>
	/// 坐标系数据空间
	/// </summary>
	YKE_GROUP_DEPTH = 4096,

	/// <summary>
	/// 坐标系内并行输出数量
	/// </summary>
	YKE_GROUP_OUTPUT_NUM = 32,

	/// <summary>
	/// 轴数量
	/// </summary>
	YKE_AXIS_NUM = 1024,

	/// <summary>
	/// 日志采集通道数量
	/// </summary>
	YKE_LOGGER_ITEM = 32,

	/// <summary>
	/// 流程跟踪通道数量
	/// </summary>
	YKE_EXC_CONDI = 16,

	/// <summary>
	/// 通用数据寄存器数量
	/// </summary>
	YKE_GENDATA_SIZE = 0x100000,

	/// <summary>
	/// 特殊数据寄存器数量
	/// </summary>
	YKE_SPDATA_SIZE = 0x10000,

	/// <summary>
	/// 急停输入信号数量
	/// </summary>
	YKE_EMG_STOP_INPUT_NUM = 8,

	/// <summary>
	/// 急停输出信号数量
	/// </summary>
	YKE_EMG_STOP_OUTPUT_NUM = 4,

	/// <summary>
	/// 急停通道数量
	/// </summary>
	YKE_EMG_STOP_NUM = 32,

	/// <summary>
	/// PVT运动缓冲区深度
	/// </summary>
	YKE_PVT_DEPTH = 4096,

	/// <summary>
	/// 文件路径缓冲区长度
	/// </summary>
	YKE_FILE_PATH_SIZE = 512,

	/// <summary>
	/// 文件名缓冲区长度
	/// </summary>
	YKE_FILE_NAME_SIZE = 64,

	/// <summary>
	/// 最大进程数量
	/// </summary>
	YKE_LOGGER_PROCCESS = 32,

	/// <summary>
	/// 多轴联动通道数量
	/// </summary>
	YKE_MULTI_AXIS_NUM = 128,

	/// <summary>
	/// 圆形区域数量
	/// </summary>
	YKE_CIRCLE_ZONE_NUM = 32,

	/// <summary>
	/// API缓冲区通道数量
	/// </summary>
	YKE_API_BUFFER_NUM = 512,
}YKE_SYSTEM_DEFINE;

/// <summary>
/// 函数返回值定义
/// </summary>
typedef enum
{
	/// <summary>
	/// 正常
	/// </summary>
	YKE_RET_OK = 0,

	/// <summary>
	/// 实时进程加载失败
	/// </summary>
	YKE_RET_SYS_LOAD_RTA = 0x0100,

	/// <summary>
	/// 和runtime连接失败
	/// </summary>
	YKE_RET_SYS_OPEN_GW = 0x0101,

	/// <summary>
	/// 请使用SysLoadLib连接runtime
	/// </summary>
	YKE_RET_SYS_CONNECT_GW = 0x0102,

	/// <summary>
	/// 打开runtime共享内存失败
	/// </summary>
	YKE_RET_SYS_OPEN_MEM = 0x0103,

	/// <summary>
	/// 网关超时
	/// </summary>
	YKE_RET_SYS_GW_TIMOUT = 0x0104,

	/// <summary>
	/// 授权权限不够
	/// </summary>
	YKE_RET_SYS_LIC = 0x0105,

	/// <summary>
	/// 实时系统没有启动
	/// </summary>
	YKE_RET_SYS_RTOS = 0x0106,

	/// <summary>
	/// Runtime已经退出或者重启,请重新连接
	/// </summary>
	YKE_RET_SYS_EXIT = 0x0107,

	/// <summary>
	/// 冷复位失败
	/// </summary>
	YKE_RET_SYS_COLD = 0x0108,

	/// <summary>
	/// 服务操作没有访问权限,请检查进程是否具备管理员权限。
	/// </summary>
	YKE_RET_SYS_ACCESS = 0x0109,

	/// <summary>
	/// 库文件不匹配,从安装目录更新库文件(.h .dll)到应用程序
	/// </summary>
	YKE_RET_SYS_MISMATCH = 0x010a,

	/// <summary>
	/// 多语言文件加载错误
	/// </summary>
	YKE_RET_SYS_LANG_TEXT = 0x010b,

	/// <summary>
	/// 字符串中存在中文字符。日志文件/实时程序文件中不能含有中文字符。
	/// </summary>
	YKE_RET_SYS_CHN = 0x010c,

	/// <summary>
	/// 不支持的功能
	/// </summary>
	YKE_RET_SYS_FUN = 0x010d,

	/// <summary>
	/// 内存分配失败
	/// </summary>
	YKE_RET_SYS_DYNC_MEM = 0x010e,

	/// <summary>
	/// 系统冷复位后需重启应用程序
	/// </summary>
	YKE_RET_SYS_COLD_ERR = 0x010f,

	/// <summary>
	/// 主站A未启用
	/// </summary>
	YKE_RET_SYS_NODEA_ENA = 0x0110,

	/// <summary>
	/// 指定主站未运行
	/// </summary>
	YKE_RET_SYS_NODEO = 0x0111,

	/// <summary>
	/// 主站B未启用
	/// </summary>
	YKE_RET_SYS_NODEB_ENA = 0x0112,

	/// <summary>
	/// 主站B未运行
	/// </summary>
	YKE_RET_SYS_NODEB_RUN = 0x0113,

	/// <summary>
	/// 主站C未启用
	/// </summary>
	YKE_RET_SYS_NODEC_ENA = 0x0114,

	/// <summary>
	/// 主站C未运行
	/// </summary>
	YKE_RET_SYS_NODEC_RUN = 0x0115,

	/// <summary>
	/// 主站D未启用
	/// </summary>
	YKE_RET_SYS_NODED_ENA = 0x0116,

	/// <summary>
	/// 主站D未运行
	/// </summary>
	YKE_RET_SYS_NODED_RUN = 0x0117,

	/// <summary>
	/// Runtime未运行
	/// </summary>
	YKE_RET_SYS_RUNTIME_STOP = 0x0118,

	/// <summary>
	/// 实时系统内存设置太小
	/// </summary>
	YKE_RET_SYS_INTIME_MEM = 0x0119,

	/// <summary>
	/// 指定主站未运行
	/// </summary>
	YKE_RET_SYS_NODE_ENA = 0x011E,

	/// <summary>
	/// 非法的主站序号
	/// </summary>
	YKE_RET_SYS_NODE_IDX = 0x011F,

	/// <summary>
	/// 文件夹创建失败
	/// </summary>
	YKE_RET_SYS_CREATE_DIR = 0x0120,

	/// <summary>
	/// COPPELIA仿真连接失败
	/// </summary>
	YKE_RET_SYS_SIM_CONNECT = 0x0121,

	/// <summary>
	/// 访问了空对象
	/// </summary>
	YKE_RET_SYS_NULL = 0x0122,

	/// <summary>
	/// YKCat2服务未注册
	/// </summary>
	YKE_RET_YKSRV_NOT_INSTALL = 0x0123,

	/// <summary>
	/// YKCat2服务未启动
	/// </summary>
	YKE_RET_SYS_YKSRV_NOT_START = 0x0124,

	/// <summary>
	/// YKCat2服务操作失败
	/// </summary>
	YKE_RET_YKSRV_OP_FAIL = 0x0125,

	/// <summary>
	/// 无权限访问YKCat2服务,请检查进程是否具备管理员权限。
	/// </summary>
	YKE_RET_YKSRV_ACCESS = 0x0126,

	/// <summary>
	/// 使用了不同版本的API库,更新ProCon时请同步更新YKCat2.dll到运行程序目录下
	/// </summary>
	YKE_RET_SYS_API_VER = 0x012F,

	/// <summary>
	/// 函数日志已读完
	/// </summary>
	YKE_RET_SYS_LOG_NULL = 0x0130,

	/// <summary>
	/// 命令没有记录到NTF缓冲区
	/// </summary>
	YKE_RET_API_BUFFER_N = 0x141,

	/// <summary>
	/// YKCatN连接失败
	/// </summary>
	YKE_RET_SYS_YKCATN_CONNECT = 0x0180,

	/// <summary>
	/// YKCatN通讯超时
	/// </summary>
	YKE_RET_SYS_YKCATN_TIMEOUT = 0x0181,

	/// <summary>
	/// YKCatN通讯句柄异常
	/// </summary>
	YKE_RET_SYS_YKCATN_HANDLE = 0x0182,

	/// <summary>
	/// YKCatN通讯数据包过大
	/// </summary>
	YKE_RET_SYS_YKCATN_SIZE = 0x0183,

	/// <summary>
	/// YKCatN通讯数据包长度不匹配
	/// </summary>
	YKE_RET_SYS_YKCATN_LEN = 0x0184,

	/// <summary>
	/// YKCatN通讯数据包指令名称过长
	/// </summary>
	YKE_RET_SYS_YKCATN_NAME = 0x0185,

	/// <summary>
	/// YKCatN通讯数据包指令参数过多
	/// </summary>
	YKE_RET_SYS_YKCATN_PARA = 0x0186,

	/// <summary>
	/// 输入参数非法
	/// </summary>
	YKE_RET_INS_PARA = 0x0200,

	/// <summary>
	/// 无效的负数
	/// </summary>
	YKE_RET_INS_NEG = 0x0201,

	/// <summary>
	/// 非法的浮点数
	/// </summary>
	YKE_RET_INS_DOUBLE = 0x0202,

	/// <summary>
	/// 无效的枚举值
	/// </summary>
	YKE_RET_INS_ENUM = 0x0203,

	/// <summary>
	/// 无效的指针
	/// </summary>
	YKE_RET_INS_PTR = 0x0204,

	/// <summary>
	/// 硬急停信号有效
	/// </summary>
	YKE_RET_EMG_HARD = 0x0220,

	/// <summary>
	/// 软急停信号有效
	/// </summary>
	YKE_RET_EMG_SOFT = 0x0221,

	/// <summary>
	/// 硬限位被触发
	/// </summary>
	YKE_RET_LIMIT_H = 0x0230,

	/// <summary>
	/// 软限位被触发
	/// </summary>
	YKE_RET_LIMIT_S = 0x0231,

	/// <summary>
	/// 圆形区域保护被触发
	/// </summary>
	YKE_RET_CIRCLE_ZONE = 0x0232,

	/// <summary>
	/// 延时输出数量超出限制
	/// </summary>
	YKE_RET_IO_REVERSE_BUFFER_OV = 0x0240,

	/// <summary>
	/// 仿真运动指定的位置条件未满足
	/// </summary>
	YKE_RET_AXIS_SIM_POS = 0x0300,

	/// <summary>
	/// 仿真运动指定的时间条件未满足
	/// </summary>
	YKE_RET_AXIS_SIM_TIM = 0x0301,

	/// <summary>
	/// 仿真运动计算超时
	/// </summary>
	YKE_RET_AXIS_SIM_TIMOUT = 0x0302,

	/// <summary>
	/// 仿真运动变参数失败
	/// </summary>
	YKE_RET_AXIS_SIM_INP = 0x0303,

	/// <summary>
	/// 轴不在位置运动或速度运动中
	/// </summary>
	YKE_RET_AXIS_OVERRIDE_INVALID = 0x0313,

	/// <summary>
	/// 轴正在使用中
	/// </summary>
	YKE_RET_AXIS_BUSY = 0x0314,

	/// <summary>
	/// 轴未使能
	/// </summary>
	YKE_RET_AXIS_READY = 0x0315,

	/// <summary>
	/// 轴序号不存在
	/// </summary>
	YKE_RET_AXIS_INDEX = 0x0316,

	/// <summary>
	/// 运动模式不匹配
	/// </summary>
	YKE_RET_AXIS_MOTION_TYPE = 0x0317,

	/// <summary>
	/// 此功能需要轴切换成CSP模式
	/// </summary>
	YKE_RET_AXIS_CSP = 0x0318,

	/// <summary>
	/// 不支持的运动曲线
	/// </summary>
	YKE_RET_AXIS_CURVE = 0x0319,

	/// <summary>
	/// 主轴模式已启用,禁用此功能
	/// </summary>
	YKE_RET_FOLLOW_MASTER = 0x0400,

	/// <summary>
	/// 凸轮主轴位置要求单调增加
	/// </summary>
	YKE_RET_FOLLOW_CAM_MPOS = 0x0401,

	/// <summary>
	/// 多轴联动通道忙
	/// </summary>
	YKE_RET_MULTI_AXIS_ACITVE = 0x0420,

	/// <summary>
	/// 多轴联动轴数量超过范围
	/// </summary>
	YKE_RET_MULTI_AXIS_NUM = 0x0421,

	/// <summary>
	/// 联动轴不在同一个主站内
	/// </summary>
	YKE_RET_MULTI_AXIS_NODE = 0x0430,

	/// <summary>
	/// 单轴连续运动缓冲区溢出
	/// </summary>
	YKE_RET_PVT_BUFFER_OV = 0x0500,

	/// <summary>
	/// PVT第一行数据位置必须为0
	/// </summary>
	YKE_RET_PVT_FIRST = 0x0501,

	/// <summary>
	/// PVTS最少需要增加2个点
	/// </summary>
	YKE_RET_PVTS_NUM = 0x0502,

	/// <summary>
	/// 分配PVTS内存失败
	/// </summary>
	YKE_RET_PVTS_DYNC = 0x0503,

	/// <summary>
	/// PVTS时间参数错误
	/// </summary>
	YKE_RET_PVTS_TIM = 0x0504,

	/// <summary>
	/// PT加速度比例参数错误
	/// </summary>
	YKE_RET_PT_ACC = 0x0505,

	/// <summary>
	/// PVTS第一点启动速度必须为0
	/// </summary>
	YKE_RET_PVTS_SVEL = 0x0506,

	/// <summary>
	/// 坐标系已初始化
	/// </summary>
	YKE_RET_GROUP_INIT = 0x0600,

	/// <summary>
	/// 坐标系未初始化
	/// </summary>
	YKE_RET_GROUP_DEINIT = 0x0601,

	/// <summary>
	/// 坐标系轴序号重复
	/// </summary>
	YKE_RET_GROUP_AXIS_INDEX_REPEAT = 0x0602,

	/// <summary>
	/// 坐标系运行中
	/// </summary>
	YKE_RET_GROUP_ACTIVE = 0x0603,

	/// <summary>
	/// 坐标系缓冲区已满,缓冲区最大容量4096
	/// </summary>
	YKE_RET_GROUP_BUFFER_FULL = 0x0604,

	/// <summary>
	/// 坐标系内的轴有报警
	/// </summary>
	YKE_RET_GROUP_AXIS_WARN = 0x0605,

	/// <summary>
	/// 坐标系有报警
	/// </summary>
	YKE_RET_GROUP_WARN = 0x0606,

	/// <summary>
	/// 坐标系内的轴处于单轴运行模式
	/// </summary>
	YKE_RET_GROUP_AXIS_SINGLE = 0x0607,

	/// <summary>
	/// 坐标系绑定的轴需要在CSP模式下
	/// </summary>
	YKE_RET_GROUP_AXIS_CSP = 0x0608,

	/// <summary>
	/// 坐标系外轴和内部轴重合
	/// </summary>
	YKE_RET_GROUP_AXIS_INDEX_REPEAT2 = 0x0609,

	/// <summary>
	/// 坐标系暂停中
	/// </summary>
	YKE_RET_GROUP_PAUSE = 0x0610,

	/// <summary>
	/// 有相对指令不支持暂停模式
	/// </summary>
	YKE_RET_GROUP_INC = 0x0611,

	/// <summary>
	/// 坐标系正在减速停止
	/// </summary>
	YKE_RET_GROUP_STOPPING = 0x0612,

	/// <summary>
	/// 龙门从轴不能加在轴列表中
	/// </summary>
	YKE_RET_GROUP_AXIS_GANTRY = 0x0613,

	/// <summary>
	/// 坐标系轴不在同一个主站内
	/// </summary>
	YKE_RET_GROUP_AXIS_NODE = 0x0614,

	/// <summary>
	/// 在螺距补偿禁用状态下更新配置
	/// </summary>
	YKE_RET_PITCH_ENA = 0x0700,

	/// <summary>
	/// 螺距补偿和2D补偿不能同时启用
	/// </summary>
	YKE_RET_PITCH_REPEAT = 0x0701,

	/// <summary>
	/// 补偿值大于了间距的20%
	/// </summary>
	YKE_RET_PITCH_DATA = 0x0702,

	/// <summary>
	/// 禁止在伺服下使能状态下启用/禁用机械补偿
	/// </summary>
	YKE_RET_PITCH_DRV = 0x0703,

	/// <summary>
	/// 补偿功能已启用,禁用此功能
	/// </summary>
	YKE_RET_PITCH_USED = 0x0704,

	/// <summary>
	/// 总线未初始化完成,在ProR中查看总线日志及当前报警。
	/// </summary>
	YKE_RET_BUS_INIT = 0x0800,

	/// <summary>
	/// SDO列表溢出
	/// </summary>
	YKE_RET_BUS_SDO_OV = 0x0801,

	/// <summary>
	/// SDO站号不存在
	/// </summary>
	YKE_RET_BUS_SDO_U = 0x0802,

	/// <summary>
	/// SDO对象字典不存在或者不可读写
	/// </summary>
	YKE_RET_BUS_SDO_OD = 0x0803,

	/// <summary>
	/// SDO对象字典访问超时
	/// </summary>
	YKE_RET_BUS_SDO_TIMOUT = 0x0804,

	/// <summary>
	/// 对象字典未加入到PDO中
	/// </summary>
	YKE_RET_BUS_OD_PDO = 0x0805,

	/// <summary>
	/// 对象字典已加入到PDO中
	/// </summary>
	YKE_RET_BUS_OD_SDO = 0x0806,

	/// <summary>
	/// 对象字典被系统使用,请使用专用函数操作
	/// </summary>
	YKE_RET_BUS_OD_RD = 0x0807,

	/// <summary>
	/// 仿真模式不支持总线扫描
	/// </summary>
	YKE_RET_BUS_SIM_SCAN = 0x0808,

	/// <summary>
	/// 未开启数据抓包功能
	/// </summary>
	YKE_RET_BUS_SNAP_UNUSED = 0x0809,

	/// <summary>
	/// 数据包缓冲区为空
	/// </summary>
	YKE_RET_BUS_SNAP_IDEL = 0x0810,

	/// <summary>
	/// 驱动器有报警
	/// </summary>
	YKE_RET_ERROR_DRV_WARN = 0x0820,

	/// <summary>
	/// 软件探针功能已启用不能修改配置
	/// </summary>
	YKE_RET_PROBE_ACTIVE = 0x0900,

	/// <summary>
	/// 软件位置比较功能已启用不能修改配置
	/// </summary>
	YKE_RET_SOFT_COMPARE_ACTIVE = 0x0a00,

	/// <summary>
	/// 位置比较器缓冲区队列已满,在空闲数量大于0时写入比较数据
	/// </summary>
	YKE_RET_COMPARE_BUFFER_OV = 0x0a01,

	/// <summary>
	/// 固定模式/线性模式的位置比较器,开始比较后不能再写入数据
	/// </summary>
	YKE_RET_COMPARE_BUFFER_FIX = 0x0a02,

	/// <summary>
	/// 加载NTF(C#)实时程序失败
	/// </summary>
	YKE_RET_NTF_LOAD = 0x0B00,

	/// <summary>
	/// 实时程序文件不存在
	/// </summary>
	YKE_RET_NTF_EXIST = 0x0B01,

	/// <summary>
	/// 等待对象初始化失败
	/// </summary>
	YKE_RET_WAIT_INIT = 0x0B60,

	/// <summary>
	/// 等待对象被删除
	/// </summary>
	YKE_RET_WAIT_DEL = 0x0B61,

	/// <summary>
	/// 等待对象超时
	/// </summary>
	YKE_RET_WAIT_TIMEOUT = 0x0B62,

	/// <summary>
	/// 等待对象失败(操作系统错误)
	/// </summary>
	YKE_RET_WAIT_FAIL = 0x0B63,

	/// <summary>
	/// 等待通道忙
	/// </summary>
	YKE_RET_WAIT_BUSY = 0x0B64,

	/// <summary>
	/// 等待对象失败(打开事件失败)
	/// </summary>
	YKE_RET_WAIT_OPEN = 0x0B65,

	/// <summary>
	/// 等待对象失败(热复位)
	/// </summary>
	YKE_RET_WAIT_SYS_RESET = 0x0B66,

	/// <summary>
	/// 等待对象失败(runtime退出)
	/// </summary>
	YKE_RET_WAIT_INS_RESET = 0x0B67,

	/// <summary>
	/// 等待对象失败(runtime退出)
	/// </summary>
	YKE_RET_WAIT_EXIT = 0x0B68,

	/// <summary>
	/// ProEn工程共享内存打开
	/// </summary>
	YKE_RET_PROEN_SHAREM = 0x0C00,

	/// <summary>
	/// ProEn工程注册失败
	/// </summary>
	YKE_RET_PROEN_OV = 0x0C01,

	/// <summary>
	/// ProEn工程已经打开
	/// </summary>
	YKE_RET_PROEN_EXIST = 0x0C02,

	/// <summary>
	/// ProEn工程文件打开失败
	/// </summary>
	YKE_RET_PROEN_OPEN_FAIL = 0x0C10,

	/// <summary>
	/// ProEn工程文件格式错误
	/// </summary>
	YKE_RET_PROEN_MAGIC_FAIL = 0x0C11,

	/// <summary>
	/// 下载ProEn工程文件超时
	/// </summary>
	YKE_RET_PROEN_TIMEOUT = 0x0C12,

	/// <summary>
	/// 文件路径长度太短(小于5)
	/// </summary>
	YKE_RET_PROEN_FILENAME = 0x0C13,

	/// <summary>
	/// 文件扩展名错误,文件由ProEN导出,扩展名为bprj
	/// </summary>
	YKE_RET_PROEN_FILE_EXT = 0x0C14,

	/// <summary>
	/// 关联信号不在同一个主站内
	/// </summary>
	YKE_RET_EVENT_NODE = 0x0d00,

	/// <summary>
	/// 事件已启动
	/// </summary>
	YKE_RET_EVENT_BUSY = 0x0d01,

	/// <summary>
	/// 指定编码器不存在
	/// </summary>
	YKE_RET_EVENT_ENCODER = 0x0d02,

	/// <summary>
	/// 圆形区域参数未初始化
	/// </summary>
	YKE_RET_CIRCLE_ZONE_INIT = 0x0d40,

	/// <summary>
	/// 圆形区域轴序号重复
	/// </summary>
	YKE_RET_CIRCLE_ZONE_INDEX = 0x0d41,

	/// <summary>
	/// 硬件锁访问超时
	/// </summary>
	YKE_RET_DOGGLE_TIMEOUT = 0x0d80,

	/// <summary>
	/// NTF未初始化
	/// </summary>
	YKE_RET_NTF_INIT = 0x0da0,

	/// <summary>
	/// NTF API缓冲区未初始化
	/// </summary>
	YKE_RET_NTF_API_BUFFER_INIT = 0x0da1,

	/// <summary>
	/// NTF API缓冲区通道未初始化
	/// </summary>
	YKE_RET_NTF_API_BUFFER_CH_INIT = 0x0da2,

	/// <summary>
	/// NTF API缓冲区通道内缓冲区溢出
	/// </summary>
	YKE_RET_NTF_API_BUFFER_CH_OV = 0x0da3,

	/// <summary>
	/// NTF API缓冲区指令无法识别
	/// </summary>
	YKE_RET_NTF_API_BUFFER_INS = 0x0da4,

	/// <summary>
	/// NTF API缓冲区忙
	/// </summary>
	YKE_RET_NTF_API_BUFFER_ACTIVE = 0x0da5,

	/// <summary>
	/// 示波器启用通道数为0
	/// </summary>
	YKE_RET_OSC_ZERO_ENA = 0x0e00,

	/// <summary>
	/// 示波器已经启用,禁止变更参数
	/// </summary>
	YKE_RET_OSC_ACTIVE = 0x0e01,

	/// <summary>
	/// 编码器已和轴绑定,不能修改值
	/// </summary>
	YKE_RET_PCI_ENCODER_AXIS = 0x0e20,
}YKE_RESULT_CODE;

/// <summary>
/// 运动错误代码
/// </summary>
typedef enum
{
	/// <summary>
	/// 无错误
	/// </summary>
	YKE_ERR_MC_OK = 0x0000,

	/// <summary>
	/// 软急停信号有效导致轴停止
	/// </summary>
	YKE_ERR_MC_SOFT_EMG = 0x0001,

	/// <summary>
	/// 硬急停信号有效导致轴停止
	/// </summary>
	YKE_ERR_MC_HARD_EMG = 0x0002,

	/// <summary>
	/// 系统停止或热复位导致轴停止
	/// </summary>
	YKE_ERR_MC_SYS_STOP = 0x0003,

	/// <summary>
	/// 轴未上使能
	/// </summary>
	YKE_ERR_MC_AXIS_READY = 0x0101,

	/// <summary>
	/// 正硬限位被触发
	/// </summary>
	YKE_ERR_MC_LIMIT_HARDP = 0x0102,

	/// <summary>
	/// 负硬限位被触发
	/// </summary>
	YKE_ERR_MC_LIMIT_HARDN = 0x0103,

	/// <summary>
	/// 正软限位被触发
	/// </summary>
	YKE_ERR_MC_LIMIT_SOFTP = 0x0104,

	/// <summary>
	/// 负软限位被触发
	/// </summary>
	YKE_ERR_MC_LIMIT_SOFTN = 0x0105,

	/// <summary>
	/// 位置跟随误差过大
	/// </summary>
	YKE_ERR_MC_POSITION_LAG = 0x0106,

	/// <summary>
	/// 规划完成后,反馈位置在指定时间(默认3秒)内未到达指定范围内
	/// </summary>
	YKE_ERR_MC_INP = 0x0107,

	/// <summary>
	/// 驱动器控制模式不匹配
	/// </summary>
	YKE_ERR_MC_DRV_OP_MODE = 0x0108,

	/// <summary>
	/// 正在运动中不能切换模式
	/// </summary>
	YKE_ERR_MC_DRV_OP_MODE_ACTIVE = 0x0109,

	/// <summary>
	/// 从轴已停止
	/// </summary>
	YKE_ERR_MC_AXIS_SLAVE_STOP = 0x010a,

	/// <summary>
	/// 规划完成后,脉冲型驱动器未给出到位信号
	/// </summary>
	YKE_ERR_MC_DRV_INP = 0x010b,

	/// <summary>
	/// 硬跟随轴和主轴位置偏差过大
	/// </summary>
	YKE_ERR_MC_GANTRY_LAG = 0x0120,

	/// <summary>
	/// 回原点过程中,在指定距离内未找到限位开关
	/// </summary>
	YKE_ERR_MC_HOME_LIMIT = 0x0150,

	/// <summary>
	/// 回原点过程中,在指定距离内未找到原点开关
	/// </summary>
	YKE_ERR_MC_HOME_HOME = 0x0151,

	/// <summary>
	/// 回原点过程中,在指定距离内未找到探针
	/// </summary>
	YKE_ERR_MC_HOME_PROBE = 0x0152,

	/// <summary>
	/// 35/37模式,不能在限位位置回原
	/// </summary>
	YKE_ERR_MC_HOME_3537 = 0x0153,

	/// <summary>
	/// 异常碰限位停止
	/// </summary>
	YKE_ERR_MC_HOME_STOP1 = 0x0154,

	/// <summary>
	/// 回原过程中,探针访问(SDO)出错
	/// </summary>
	YKE_ERR_MC_HOME_TOUCH = 0x0155,

	/// <summary>
	/// 回原输入信号所在从站模块已经掉线
	/// </summary>
	YKE_ERR_MC_HOME_OFFLINE = 0x0156,

	/// <summary>
	/// 脉冲轴探针未配置
	/// </summary>
	YKE_ERR_MC_PLS_PROBE_CONFIG = 0x160,

	/// <summary>
	/// 二维补偿变化量超过了最高速度
	/// </summary>
	YKE_ERR_MC_PITCH2D_VEL = 0x170,

	/// <summary>
	/// 驱动器发生报警
	/// </summary>
	YKE_ERR_MC_DRV_WARN = 0x0200,

	/// <summary>
	/// 驱动器PP模式发生错误
	/// </summary>
	YKE_ERR_MC_DRV_PP = 0x0201,

	/// <summary>
	/// 驱动器回原时发生错误6041.13=1
	/// </summary>
	YKE_ERR_MC_DRV_HM = 0x0202,

	/// <summary>
	/// PV模式下SDO访问出错
	/// </summary>
	YKE_ERR_MC_PV_SDO = 0x0203,

	/// <summary>
	/// PP模式下SDO访问出错
	/// </summary>
	YKE_ERR_MC_PP_SDO = 0x0204,

	/// <summary>
	/// 转矩相关寄存器未加入到PDO中
	/// </summary>
	YKE_ERR_MC_TORQUE_PDO = 0x0208,

	/// <summary>
	/// 驱动器上使能失败
	/// </summary>
	YKE_ERR_MC_POWER_ON = 0x0210,

	/// <summary>
	/// 清除驱动器报警失败
	/// </summary>
	YKE_ERR_MC_CLR_DRV = 0x0211,

	/// <summary>
	/// 轨迹运动错误
	/// </summary>
	YKE_ERR_MC_GROUP_PATH = 0x0250,

	/// <summary>
	/// 圆参数错误
	/// </summary>
	YKE_ERR_MC_GROUP_CIR = 0x0251,

	/// <summary>
	/// 坐标系中的轴有报警
	/// </summary>
	YKE_ERR_MC_GROUP_AXIS = 0x0252,

	/// <summary>
	/// 坐标系内轴序号错误
	/// </summary>
	YKE_ERR_MC_GROUP_AXIS_INDEX = 0x0253,

	/// <summary>
	/// 坐标系中的轴已在外部启动
	/// </summary>
	YKE_ERR_MC_GROUP_AXIS_ACTIVE1 = 0x0254,

	/// <summary>
	/// 坐标系中的轴未到位
	/// </summary>
	YKE_ERR_MC_GROUP_AXIS_INPOS = 0x0255,

	/// <summary>
	/// 坐标系中的输出轴已经启动
	/// </summary>
	YKE_ERR_MC_GROUP_AXIS_ACTIVE2 = 0x0256,

	/// <summary>
	/// 坐标系中的轴未使能
	/// </summary>
	YKE_ERR_MC_GROUP_AXIS_READY = 0x0257,

	/// <summary>
	/// 坐标系轴已到限位
	/// </summary>
	YKE_ERR_MC_GROUP_AXIS_LIMIT = 0x0258,

	/// <summary>
	/// 坐标系硬急停有效
	/// </summary>
	YKE_ERR_MC_GROUP_HARD_EMG = 0x0259,

	/// <summary>
	/// 坐标系软急停有效
	/// </summary>
	YKE_ERR_MC_GROUP_SOFT_EMG = 0x025a,

	/// <summary>
	/// 需要开启CNC扩展坐标系选项
	/// </summary>
	YKE_ERR_MC_GROUP_CNC_EXT = 0x0260,

	/// <summary>
	/// CNC最多支持4个坐标系
	/// </summary>
	YKE_ERR_MC_GROUP_CNC_NUM = 0x0261,

	/// <summary>
	/// CNC当前模式下不支持直线插补指令
	/// </summary>
	YKE_ERR_MC_GROUP_CNC_LINE = 0x0262,

	/// <summary>
	/// CNC当前模式下不支持圆弧插补指令
	/// </summary>
	YKE_ERR_MC_GROUP_CNC_CIR = 0x0263,

	/// <summary>
	/// CNC当前模式下不支持G代码指令
	/// </summary>
	YKE_ERR_MC_GROUP_CNC_GCODE = 0x0264,

	/// <summary>
	/// CNC当前模式下不支持文件加工指令
	/// </summary>
	YKE_ERR_MC_GROUP_CNC_FILE = 0x0265,

	/// <summary>
	/// 定义结束
	/// </summary>
	YKE_ERR_MC_END = 0x0300,
}YKE_MC_ERROR;

/// <summary>
/// 系统错误类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 无错误
	/// </summary>
	YKE_ERR_SYS_APP_NONE = 0x0000,

	/// <summary>
	/// 配置文件版本太高
	/// </summary>
	YKE_ERR_SYS_FILE_VER = 0x0001,

	/// <summary>
	/// 配置文件格式不对
	/// </summary>
	YKE_ERR_SYS_FILE_CFG = 0x0002,

	/// <summary>
	/// 配置文件不存在
	/// </summary>
	YKE_ERR_SYS_FILE_EXIST = 0x0003,

	/// <summary>
	/// 配置文件读取失败
	/// </summary>
	YKE_ERR_SYS_FILE_READ = 0x0004,

	/// <summary>
	/// 脉冲卡配置版本过低
	/// </summary>
	YKE_ERR_SYS_CARD_VER1 = 0x0005,

	/// <summary>
	/// 脉冲卡配置版本过高
	/// </summary>
	YKE_ERR_SYS_CARD_VER2 = 0x0006,

	/// <summary>
	/// 脉冲卡固件版本过低
	/// </summary>
	YKE_ERR_SYS_BRD_VER = 0x0007,

	/// <summary>
	/// 实时系统基准不正确
	/// </summary>
	YKE_ERR_SYS_CLK_BASE = 0x0008,

	/// <summary>
	/// 低于125us周期不支持总线和脉冲混用
	/// </summary>
	YKE_ERR_SYS_DC_125US = 0x0009,

	/// <summary>
	/// 基础运动库版本不匹配
	/// </summary>
	YKE_ERR_SYS_YKGROUP_VER = 0x000A,

	/// <summary>
	/// 脉冲卡无法识别
	/// </summary>
	YKE_ERR_SYS_CARD_UNKNOWN = 0x000B,

	/// <summary>
	/// 总线周期小于等于250us时,请使用专用PC
	/// </summary>
	YKE_ERR_SYS_250us_PC = 0x000C,

	/// <summary>
	/// CNC运动库初始化失败
	/// </summary>
	YKE_ERR_SYS_APP_INIT_I = 0x0010,

	/// <summary>
	/// NTF(CPP)加载失败
	/// </summary>
	YKE_ERR_SYS_NTF_LOAD = 0x0011,

	/// <summary>
	/// NTF(CPP)库初始化失败
	/// </summary>
	YKE_ERR_SYS_NTF_INIT = 0x0012,

	/// <summary>
	/// 实时系统节点B未启用
	/// </summary>
	YKE_ERR_SYS_NODEB_ENA = 0x0013,

	/// <summary>
	/// 实时系统节点C未启用
	/// </summary>
	YKE_ERR_SYS_NODEC_ENA = 0x0014,

	/// <summary>
	/// 实时系统节点D未启用
	/// </summary>
	YKE_ERR_SYS_NODED_ENA = 0x0015,

	/// <summary>
	/// 主站B服务加载失败
	/// </summary>
	YKE_ERR_SYS_NODEB_FAIL = 0x0016,

	/// <summary>
	/// 主站C服务加载失败
	/// </summary>
	YKE_ERR_SYS_NODEC_FAIL = 0x0017,

	/// <summary>
	/// 主站D服务加载失败
	/// </summary>
	YKE_ERR_SYS_NODED_FAIL = 0x0018,

	/// <summary>
	/// NTF负载超过了总线周期时间
	/// </summary>
	YKE_ERR_SYS_NTF_PAYLOAD = 0x0019,

	/// <summary>
	/// 本地脉冲卡初始化失败,解决后请手动清除本警告
	/// </summary>
	YKE_ERR_SYS_BRD_INIT = 0x0020,

	/// <summary>
	/// 应用程序超时
	/// </summary>
	YKE_ERR_SYS_APP_WTD = 0x0030,

	/// <summary>
	/// 缺少授权权限
	/// </summary>
	YKE_ERR_SYS_LIC = 0x0031,

	/// <summary>
	/// 动态内存分配失败
	/// </summary>
	YKE_ERR_SYS_DYNC_MEM = 0x0032,

	/// <summary>
	/// 网络没有链接
	/// </summary>
	YKE_ERR_SYS_APP_CHK_NIC = 0x0040,

	/// <summary>
	/// 从站数量不匹配
	/// </summary>
	YKE_ERR_SYS_SLAVE_CHKNUM = 0x0041,

	/// <summary>
	/// 非ECAT数据帧
	/// </summary>
	YKE_ERR_SYS_LINK_ECAT = 0x0042,

	/// <summary>
	/// 和DC主站失去同步
	/// </summary>
	YKE_ERR_SYS_DC_SHIFT = 0x0043,

	/// <summary>
	/// PDO通讯有错误,链路已断开
	/// </summary>
	YKE_ERR_SYS_DISCONNECT = 0x0044,

	/// <summary>
	/// 第1帧有从站未处理数据
	/// </summary>
	YKE_ERR_SYS_PDO1_WKC = 0x0045,

	/// <summary>
	/// 第2帧有从站未处理数据
	/// </summary>
	YKE_ERR_SYS_PDO2_WKC = 0x0046,

	/// <summary>
	/// 第3帧有从站未处理数据
	/// </summary>
	YKE_ERR_SYS_PDO3_WKC = 0x0047,

	/// <summary>
	/// 第4帧有从站未处理数据
	/// </summary>
	YKE_ERR_SYS_PDO4_WKC = 0x0048,

	/// <summary>
	/// 启动参数中有无法识别的数据类型
	/// </summary>
	YKE_ERR_SYS_DATA_TYPE = 0x004a,

	/// <summary>
	/// 环网冗余的主从网口插反了
	/// </summary>
	YKE_ERR_SYS_NIC_SWAP = 0x004b,

	/// <summary>
	/// 系统配置发生变化,请执行热复位命令
	/// </summary>
	YKE_ERR_SYS_APP_HDCHANGE = 0x0051,

	/// <summary>
	/// DC周期发生变化
	/// </summary>
	YKE_ERR_SYS_DC_CYCLE = 0x0052,

	/// <summary>
	/// 脉冲轴发送队列溢出
	/// </summary>
	YKE_ERR_SYS_PLS_OVERFLOW = 0x0060,

	/// <summary>
	/// 脉冲轴频率超限制
	/// </summary>
	YKE_ERR_SYS_PLS_MAX = 0x0061,

	/// <summary>
	/// 脉冲卡配置发生变化
	/// </summary>
	YKE_ERR_SYS_APP_BRDCHANGE = 0x0062,

	/// <summary>
	/// 急停信号所在从站模块已经掉线
	/// </summary>
	YKE_ERR_SYS_EMG_OFFLINE = 0x070,

	/// <summary>
	/// 软急停急停信号已生效
	/// </summary>
	YKE_ERR_SYS_EMG_SOFT = 0x071,

	/// <summary>
	/// 硬急停急停信号已生效
	/// </summary>
	YKE_ERR_SYS_EMG_HARD = 0x072,

	/// <summary>
	/// 事件中轴启动失败
	/// </summary>
	YKE_ERR_EVENT_START_AXIS = 0x080,

	/// <summary>
	/// 事件中坐标系启动失败
	/// </summary>
	YKE_ERR_EVENT_START_GROUP = 0x081,

	/// <summary>
	/// 事件中读PDO失败
	/// </summary>
	YKE_ERR_EVENT_READ_PDO = 0x082,

	/// <summary>
	/// 事件中写PDO失败
	/// </summary>
	YKE_ERR_EVENT_WRITE_PDO = 0x083,
}YKE_SYSTEM_ERROR;

/// <summary>
/// 从站错误类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 无
	/// </summary>
	YKE_ERR_SLAVE_PDO_NONE = 0x0000,

	/// <summary>
	/// 非法的PDO数据类型
	/// </summary>
	YKE_ERR_SLAVE_PDO_DTYPE = 0x0100,

	/// <summary>
	/// PDO配置不完整
	/// </summary>
	YKE_ERR_SLAVE_PDO = 0x0101,

	/// <summary>
	/// 制造商ID不匹配
	/// </summary>
	YKE_ERR_SLAVE_VID = 0x0102,

	/// <summary>
	/// 产品ID不匹配
	/// </summary>
	YKE_ERR_SLAVE_PID = 0x0103,

	/// <summary>
	/// 切换到Init状态失败
	/// </summary>
	YKE_ERR_SLAVE_TO_INIT = 0x0104,

	/// <summary>
	/// 切换到PreOP状态失败
	/// </summary>
	YKE_ERR_SLAVE_TO_PREOP = 0x0105,

	/// <summary>
	/// 切换到SafeOP状态失败
	/// </summary>
	YKE_ERR_SLAVE_TO_SAFEOP = 0x0106,

	/// <summary>
	/// 切换到OP状态失败
	/// </summary>
	YKE_ERR_SLAVE_TO_OP = 0x0107,

	/// <summary>
	/// SDO写对象字典数据失败
	/// </summary>
	YKE_ERR_SLAVE_SDO_WRITE = 0x0108,

	/// <summary>
	/// SDO读对象字典数据失败
	/// </summary>
	YKE_ERR_SLAVE_SDO_READ = 0x0109,

	/// <summary>
	/// SDO访问出错
	/// </summary>
	YKE_ERR_SLAVE_SDO = 0x010a,

	/// <summary>
	/// SDO读写队列溢出
	/// </summary>
	YKE_ERR_SLAVE_SDO_OVER = 0x010b,

	/// <summary>
	/// 访问不存在的从站
	/// </summary>
	YKE_ERR_SLAVE_INDEX = 0x010c,

	/// <summary>
	/// 从站已经断线
	/// </summary>
	YKE_ERR_SLAVE_OFFLINE = 0x010d,

	/// <summary>
	/// 驱动器报警复位失败
	/// </summary>
	YKE_ERR_SLAVE_RST = 0x010e,

	/// <summary>
	/// 驱动器发生报警
	/// </summary>
	YKE_ERR_SLAVE_DRVW = 0x010f,

	/// <summary>
	/// SDO邮箱状态超时
	/// </summary>
	YKE_ERR_SLAVE_SM_TIMEOUT = 0x0110,
}YKE_SLAVE_ERROR;

/// <summary>
/// 主站选择
/// </summary>
typedef enum
{
	/// <summary>
	/// 主站A
	/// </summary>
	YKE_ECAT_A = 0,

	/// <summary>
	/// 主站B
	/// </summary>
	YKE_ECAT_B = 1,

	/// <summary>
	/// 主站C
	/// </summary>
	YKE_ECAT_C = 2,

	/// <summary>
	/// 主站D
	/// </summary>
	YKE_ECAT_D = 3,

	/// <summary>
	/// 节点E
	/// </summary>
	YKE_NODE_E = 4,

	/// <summary>
	/// 节点F
	/// </summary>
	YKE_NODE_F = 5,

	/// <summary>
	/// 节点G
	/// </summary>
	YKE_NODE_G = 6,

	/// <summary>
	/// 节点H
	/// </summary>
	YKE_NODE_H = 7,
}YKE_NODE;

/// <summary>
/// 轴物理层类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 虚拟轴
	/// </summary>
	YKE_AXIS_PHY_VIRTUAL = 0,

	/// <summary>
	/// 总线轴
	/// </summary>
	YKE_AXIS_PHY_ETHERCAT = 1,

	/// <summary>
	/// 脉冲轴
	/// </summary>
	YKE_AXIS_PHY_PULSE = 2,
}YKE_AXIS_PHY;

/// <summary>
/// 数字IO物理层类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 本地PCI卡
	/// </summary>
	YKE_DIO_PHY_PCI = 0,

	/// <summary>
	/// 总线IO
	/// </summary>
	YKE_DIO_PHY_EBUS_DIO = 1,

	/// <summary>
	/// 网关IO
	/// </summary>
	YKE_DIO_PHY_EBUS_GW = 2,

	/// <summary>
	/// 驱动器IO
	/// </summary>
	YKE_DIO_PHY_EBUS_DRV = 3,
}YKE_DIO_PHY;

/// <summary>
/// 停止类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 无
	/// </summary>
	YKE_AXIS_STOP_NONE = 0,

	/// <summary>
	/// 急停
	/// </summary>
	YKE_AXIS_STOP_EMG = 1,

	/// <summary>
	/// 指令停止
	/// </summary>
	YKE_AXIS_STOP_INS = 2,

	/// <summary>
	/// 硬限位停止
	/// </summary>
	YKE_AXIS_STOP_HARD_LIMIT = 3,

	/// <summary>
	/// 软限位停止
	/// </summary>
	YKE_AXIS_STOP_SOFT_LIMIT = 4,

	/// <summary>
	/// 驱动报警
	/// </summary>
	YKE_AXIS_STOP_DRIVER = 5,

	/// <summary>
	/// 主轴停止
	/// </summary>
	YKE_AXIS_STOP_MASTER = 6,

	/// <summary>
	/// 从轴停止
	/// </summary>
	YKE_AXIS_STOP_SLAVE = 7,

	/// <summary>
	/// 跟随误差过大
	/// </summary>
	YKE_AXIS_STOP_FOLLOW = 8,

	/// <summary>
	/// 触发停止
	/// </summary>
	YKE_AXIS_STOP_TRIGGER = 9,

	/// <summary>
	/// 事件停止
	/// </summary>
	YKE_AXIS_STOP_EVENT = 10,

	/// <summary>
	/// 圆形区域停止
	/// </summary>
	YKE_AXIS_STOP_CIRCLE_ZONE = 11,

	/// <summary>
	/// runtime停止
	/// </summary>
	YKE_AXIS_STOP_RUNTIME = 20,
}YKE_AXIS_STOP_TYPE;

/// <summary>
/// 轴等待信号类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 等待轴ACTIVE信号为OFF
	/// </summary>
	YKE_AXIS_WAIT_ACITVE_OFF = 0,

	/// <summary>
	/// 等待轴ACTIVE信号为ON
	/// </summary>
	YKE_AXIS_WAIT_ACITVE_ON = 1,
}YKE_AXIS_WAIT_TYPE;

/// <summary>
/// 数字输入等待类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 数字输入信号为OFF
	/// </summary>
	YKE_DIGITAL_INPUT_WAIT_OFF = 0,

	/// <summary>
	/// 数字输入信号为ON
	/// </summary>
	YKE_DIGITAL_INPUT_WAIT_ON = 1,
}YKE_DIGITAL_INPUT_WAIT_TYPE;

/// <summary>
/// 事件等待类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 等待事件完成
	/// </summary>
	YKE_EVENT_WAIT_FINISH = 0,

	/// <summary>
	/// 等待事件启动
	/// </summary>
	YKE_EVENT_WAIT_START = 1,
}YKE_EVENT_WAIT_TYPE;

/// <summary>
/// 运动曲线
/// </summary>
typedef enum
{
	/// <summary>
	/// S形
	/// </summary>
	YKE_CURVE_S7 = 0,

	/// <summary>
	/// 梯形
	/// </summary>
	YKE_CURVE_T7 = 1,

	/// <summary>
	/// 带平滑的梯形
	/// </summary>
	YKE_CURVE_TS = 2,

	/// <summary>
	/// 时间定义加速度的梯形曲线
	/// </summary>
	YKE_CURVE_T7_TIME = 3,

	/// <summary>
	/// 比率定义加速度的S形曲线
	/// </summary>
	YKE_CURVE_S7_RATE = 4,
}YKE_CURVE_TYPE;

/// <summary>
/// 开关配置
/// </summary>
typedef enum
{
	/// <summary>
	/// 无效配置
	/// </summary>
	YKE_SWITCH_NONE = 0,

	/// <summary>
	/// COE对象字典(总线轴专用)
	/// </summary>
	YKE_SWITCH_COE_REG = 1,

	/// <summary>
	/// 全局IO序号
	/// </summary>
	YKE_SWITCH_GLOBAL_DIO = 2,

	/// <summary>
	/// 本地IO序号(本地脉冲卡专用)
	/// </summary>
	YKE_SWITCH_LOCAL_DIO = 3,

	/// <summary>
	/// 机械限位(总线轴专用)
	/// </summary>
	YKE_SWITCH_MECHANICAL = 4,
}YKE_SWITCH_TYPE;

/// <summary>
/// 语言选择
/// </summary>
typedef enum
{
	/// <summary>
	/// 中文
	/// </summary>
	YKE_LNG_CHN = 0,
}YKE_LANGUAGE;

/// <summary>
/// 缓冲模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 无效
	/// </summary>
	YKE_BUFFER_NONE = 0x0000,

	/// <summary>
	/// 缓冲
	/// </summary>
	YKE_BUFFERED = 0x0001,

	/// <summary>
	/// 以低速平滑
	/// </summary>
	YKE_BLENDING_LOW = 0x0002,

	/// <summary>
	/// 以前段速平滑
	/// </summary>
	YKE_BLENDING_PREV = 0x0003,

	/// <summary>
	/// 以后段速平滑
	/// </summary>
	YKE_BLENDING_NEXT = 0x0004,

	/// <summary>
	/// 以高速平滑
	/// </summary>
	YKE_BLENDING_HIGH = 0x0005,
}YKE_BUFFER_MODE;

/// <summary>
/// 过渡方式
/// </summary>
typedef enum
{
	/// <summary>
	/// 无过渡
	/// </summary>
	YKE_TRANS_NONE = 0x0000,

	/// <summary>
	/// 拐角距离
	/// </summary>
	YKE_CORNER_DISTANCE = 0x0003,

	/// <summary>
	/// 最大拐角误差
	/// </summary>
	YKE_MAX_CORNER_DEVIATION = 0x0004,
}YKE_TRANSITION_MODE;

/// <summary>
/// 圆弧辅助点模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 指定圆弧上一点
	/// </summary>
	YKE_CIRCULAR_BORDER = 0x0000,

	/// <summary>
	/// 指定圆心
	/// </summary>
	YKE_CIRCULAR_CENTER = 0x0001,
}YKE_CIRCULAR_AUX_MODE;

/// <summary>
/// 圆弧路径选择
/// </summary>
typedef enum
{
	/// <summary>
	/// 顺时针,圆心模式使用
	/// </summary>
	YKE_CIRCULAR_CLOCKWISE = 0x0000,

	/// <summary>
	/// 逆时针,圆心模式使用
	/// </summary>
	YKE_CIRCULAR_COUNTERCLOCKWISE = 0x0001,

	/// <summary>
	/// 辅助点指定,辅助点模式使用
	/// </summary>
	YKE_CIRCULAR_DEFINED_BY_AUX_POINT = 0x0002,
}YKE_CIRCULAR_PATH_CHOICE;

/// <summary>
/// 运动方向
/// </summary>
typedef enum
{
	/// <summary>
	/// 正方向运动
	/// </summary>
	YKE_DIRECTION_POSITIVE = 0,

	/// <summary>
	/// 负方向运动
	/// </summary>
	YKE_DIRECTION_NEGATIVE = 1,

	/// <summary>
	/// 禁止使用
	/// </summary>
	YKE_DIRECTION_NONE = 2,
}YKE_DIRECTION;

/// <summary>
/// 回原点方式
/// </summary>
typedef enum
{
	/// <summary>
	/// 0:未定义
	/// </summary>
	YKE_HOME_MODE_00 = 0,

	/// <summary>
	/// 1:离开负限位后,第一个探针标记回原
	/// </summary>
	YKE_HOME_MODE_01 = 1,

	/// <summary>
	/// 2:离开正限位后,第一个探针标记回原
	/// </summary>
	YKE_HOME_MODE_02 = 2,

	/// <summary>
	/// 3:离开原点开关后,第一个探针标记回原(正向原点开关)
	/// </summary>
	YKE_HOME_MODE_03 = 3,

	/// <summary>
	/// 4:接触原点开关后,第一个探针标记回原(正向原点开关)
	/// </summary>
	YKE_HOME_MODE_04 = 4,

	/// <summary>
	/// 5:离开原点开关后,第一个探针标记回原(负向原点开关)
	/// </summary>
	YKE_HOME_MODE_05 = 5,

	/// <summary>
	/// 6:接触原点开关后,第一个探针标记回原(负向原点开关)
	/// </summary>
	YKE_HOME_MODE_06 = 6,

	/// <summary>
	/// 7:离开原点开关的负边沿后,第一个探针标记回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_07 = 7,

	/// <summary>
	/// 8:接触原点开关的负边沿后,第一个探针标记回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_08 = 8,

	/// <summary>
	/// 9:接触原点开关的正边沿后,第一个探针标记回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_09 = 9,

	/// <summary>
	/// 10:离开原点开关的正边沿后,第一个探针标记回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_10 = 10,

	/// <summary>
	/// 11:离开原点开关的正边沿后,第一个探针标记回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_11 = 11,

	/// <summary>
	/// 12:接触原点开关的正边沿后,第一个探针标记回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_12 = 12,

	/// <summary>
	/// 13:接触原点开关的负边沿后,第一个探针标记回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_13 = 13,

	/// <summary>
	/// 14:离开原点开关的负边沿后,第一个探针标记回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_14 = 14,

	/// <summary>
	/// 15:未实现
	/// </summary>
	YKE_HOME_MODE_15 = 15,

	/// <summary>
	/// 16:未实现
	/// </summary>
	YKE_HOME_MODE_16 = 16,

	/// <summary>
	/// 17:负限位下降沿
	/// </summary>
	YKE_HOME_MODE_17 = 17,

	/// <summary>
	/// 18:正限位下降沿
	/// </summary>
	YKE_HOME_MODE_18 = 18,

	/// <summary>
	/// 19:原点开关下降沿回原(正向原点开关)
	/// </summary>
	YKE_HOME_MODE_19 = 19,

	/// <summary>
	/// 20:原点开关上升沿回原(正向原点开关)
	/// </summary>
	YKE_HOME_MODE_20 = 20,

	/// <summary>
	/// 21:原点开关下降沿回原(负向原点开关)
	/// </summary>
	YKE_HOME_MODE_21 = 21,

	/// <summary>
	/// 22:原点开关上升沿回原(负向原点开关)
	/// </summary>
	YKE_HOME_MODE_22 = 22,

	/// <summary>
	/// 23:原点开关负边下降沿回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_23 = 23,

	/// <summary>
	/// 24:原点开关负边上升沿回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_24 = 24,

	/// <summary>
	/// 25:原点开关正边上升沿回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_25 = 25,

	/// <summary>
	/// 26:原点开关正边下降沿回原,初始正向运动
	/// </summary>
	YKE_HOME_MODE_26 = 26,

	/// <summary>
	/// 27:原点开关正边下降沿回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_27 = 27,

	/// <summary>
	/// 28:原点开关正边上升沿回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_28 = 28,

	/// <summary>
	/// 29:原点开关负边上升沿回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_29 = 29,

	/// <summary>
	/// 30:原点开关负边下降沿回原,初始负向运动
	/// </summary>
	YKE_HOME_MODE_30 = 30,

	/// <summary>
	/// 31:未实现
	/// </summary>
	YKE_HOME_MODE_31 = 31,

	/// <summary>
	/// 32:未实现
	/// </summary>
	YKE_HOME_MODE_32 = 32,

	/// <summary>
	/// 33:负向找探针
	/// </summary>
	YKE_HOME_MODE_33 = 33,

	/// <summary>
	/// 34:正向找探针
	/// </summary>
	YKE_HOME_MODE_34 = 34,

	/// <summary>
	/// 35:当前位置为原点
	/// </summary>
	YKE_HOME_MODE_35 = 35,

	/// <summary>
	/// 36:未实现
	/// </summary>
	YKE_HOME_MODE_36 = 36,

	/// <summary>
	/// 37:当前位置为原点
	/// </summary>
	YKE_HOME_MODE_37 = 37,

	/// <summary>
	/// 38:绝对编码器回原
	/// </summary>
	YKE_HOME_MODE_ABS = 38,
}YKE_HOME_MODE;

/// <summary>
/// 轴停止命令减速度选择
/// </summary>
typedef enum
{
	/// <summary>
	/// 使用YKS_AxisProfileBase.stop_dec_smooth参数
	/// </summary>
	YKE_STOP_SEL_SMOOTH = 0,

	/// <summary>
	/// 使用YKS_AxisProfileBase.stop_dec_emg参数
	/// </summary>
	YKE_STOP_SEL_EMG = 1,

	/// <summary>
	/// 使用指令减速度
	/// </summary>
	YKE_STOP_SEL_INS = 2,
}YKE_STOP_DEC;

/// <summary>
/// 编码器模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 脉冲+方向
	/// </summary>
	YKE_ENCODER_MODE_PD = 0,

	/// <summary>
	/// 正反脉冲
	/// </summary>
	YKE_ENCODER_MODE_PN = 1,

	/// <summary>
	/// 正交模式
	/// </summary>
	YKE_ENCODER_MODE_AB4 = 2,
}YKE_ENCODER_MODE;

/// <summary>
/// 比较器模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 固定位置
	/// </summary>
	YKE_COMPARE_MODE_FIX = 0,

	/// <summary>
	/// 线性模式
	/// </summary>
	YKE_COMPARE_MODE_LINE = 1,

	/// <summary>
	/// 先进先出
	/// </summary>
	YKE_COMPARE_MODE_FIFO = 2,
}YKE_COMPARE_MODE;

/// <summary>
/// 输入信号触发模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 上升沿
	/// </summary>
	YKE_TRIG_MODE_UPEDGE = 0,

	/// <summary>
	/// 下降沿
	/// </summary>
	YKE_TRIG_MODE_DOWNEDGE = 1,

	/// <summary>
	/// 高电平
	/// </summary>
	YKE_TRIG_MODE_HGIHLEVEL = 2,

	/// <summary>
	/// 低电平
	/// </summary>
	YKE_TRIG_MODE_LOWLEVEL = 3,

	/// <summary>
	/// 沿变化
	/// </summary>
	YKE_TRIG_MODE_EDGE = 4,
}YKE_TRIG_MODE;

/// <summary>
/// 示波器触发模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 自由运行
	/// </summary>
	YKE_OSC_TRIG_FREE = 0,

	/// <summary>
	/// 手动触发
	/// </summary>
	YKE_OSC_TRIG_MANUAL = 1,

	/// <summary>
	/// 上升沿
	/// </summary>
	YKE_OSC_TRIG_UPEDGE = 2,

	/// <summary>
	/// 下降沿
	/// </summary>
	YKE_OSC_TRIG_DOWNEDGE = 3,

	/// <summary>
	/// 高电平
	/// </summary>
	YKE_OSC_TRIG_HIGHLEVEL = 4,

	/// <summary>
	/// 低电平
	/// </summary>
	YKE_OSC_TRIG_LOWLEVEL = 5,

	/// <summary>
	/// 沿变化
	/// </summary>
	YKE_OSC_TRIG_UPDOWN = 6,
}YKE_OSC_TRIG_TYPE;

/// <summary>
/// 示波器监控对象类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 轴数据
	/// </summary>
	YKE_OSC_ITEM_AXIS = 0,

	/// <summary>
	/// 对象字典,适用总线驱动器
	/// </summary>
	YKE_OSC_ITEM_OD = 1,

	/// <summary>
	/// UG寄存器,适用总线驱动器
	/// </summary>
	YKE_OSC_ITEM_UG = 2,

	/// <summary>
	/// 数字输入
	/// </summary>
	YKE_OSC_ITEM_DI = 3,

	/// <summary>
	/// 数字输出
	/// </summary>
	YKE_OSC_ITEM_DO = 4,

	/// <summary>
	/// 通用数据寄存器
	/// </summary>
	YKE_OSC_ITEM_DATA_REG = 5,

	/// <summary>
	/// 系统信息
	/// </summary>
	YKE_OSC_ITEM_SYS = 6,

	/// <summary>
	/// 坐标系信息
	/// </summary>
	YKE_OSC_ITEM_GROUP = 7,

	/// <summary>
	/// 本地编码器
	/// </summary>
	YKE_OSC_ITEM_ENCODER = 8,

	/// <summary>
	/// 事件
	/// </summary>
	YKE_OSC_ITEM_EVENT = 9,

	/// <summary>
	/// 多轴联动
	/// </summary>
	YKE_OSC_ITEM_MULTI_AXIS = 10,

	/// <summary>
	/// 等待事件
	/// </summary>
	YKE_OSC_ITEM_WAIT = 11,
}YKE_OSC_ITEM_TYPE;

/// <summary>
/// 轴信息采样数据类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 规划速度
	/// </summary>
	YKE_AXIS_ITEM_CMD_VEL = 0,

	/// <summary>
	/// 实际速度
	/// </summary>
	YKE_AXIS_ITEM_ACT_VEL = 1,

	/// <summary>
	/// 规划位置
	/// </summary>
	YKE_AXIS_ITEM_CMD_POS = 2,

	/// <summary>
	/// 实际位置
	/// </summary>
	YKE_AXIS_ITEM_ACT_POS = 3,

	/// <summary>
	/// 给定转矩
	/// </summary>
	YKE_AXIS_ITEM_CMD_TQ = 4,

	/// <summary>
	/// 实际转矩
	/// </summary>
	YKE_AXIS_ITEM_ACT_TQ = 5,

	/// <summary>
	/// 规划加速度
	/// </summary>
	YKE_AXIS_ITEM_CMD_ACC = 6,

	/// <summary>
	/// 规划变加速度
	/// </summary>
	YKE_AXIS_ITEM_CMD_JERK = 7,

	/// <summary>
	/// 目标位置
	/// </summary>
	YKE_AXIS_ITEM_TARGET_POS = 11,

	/// <summary>
	/// 控制模式
	/// </summary>
	YKE_AXIS_ITEM_COE_MODE = 12,

	/// <summary>
	/// 编码器值
	/// </summary>
	YKE_AXIS_ITEM_ENCODER = 13,

	/// <summary>
	/// 轴报警信号
	/// </summary>
	YKE_AXIS_ITEM_WARN_ID = 14,

	/// <summary>
	/// 螺距补偿量
	/// </summary>
	YKE_AXIS_ITEM_PITCH = 15,

	/// <summary>
	/// 反向间隙补偿量
	/// </summary>
	YKE_AXIS_ITEM_BACKLASH = 16,

	/// <summary>
	/// 规划完成信号
	/// </summary>
	YKE_AXIS_ITEM_CMD_DONE = 20,

	/// <summary>
	/// Active信号(UINT32)
	/// </summary>
	YKE_AXIS_ITEM_ACTIVE1 = 21,

	/// <summary>
	/// Active信号(BOOL)
	/// </summary>
	YKE_AXIS_ITEM_ACTIVE2 = 22,

	/// <summary>
	/// Done信号
	/// </summary>
	YKE_AXIS_ITEM_DONE = 23,

	/// <summary>
	/// 驱动器Ready
	/// </summary>
	YKE_AXIS_ITEM_POWER_ON = 24,

	/// <summary>
	/// 变参数标记
	/// </summary>
	YKE_AXIS_ITEM_CHANGE = 25,

	/// <summary>
	/// 剩余规划时间
	/// </summary>
	YKE_AXIS_ITEM_REMAIN_TIM = 30,

	/// <summary>
	/// 规划总时间
	/// </summary>
	YKE_AXIS_ITEM_TOTAL_TIM = 31,

	/// <summary>
	/// 已运行时间
	/// </summary>
	YKE_AXIS_ITEM_COMPLETE_TIM = 32,

	/// <summary>
	/// 位置跟随误差(滤波前)
	/// </summary>
	YKE_AXIS_ITEM_POS_LAG = 40,

	/// <summary>
	/// 位置跟随误差(滤波后)
	/// </summary>
	YKE_AXIS_ITEM_POS_LAG_FILTER = 41,

	/// <summary>
	/// 和主轴的规划位置偏差
	/// </summary>
	YKE_AXIS_ITEM_GANTRY_CMDERR = 42,

	/// <summary>
	/// 和主轴的实际位置偏差
	/// </summary>
	YKE_AXIS_ITEM_GANTRY_ACTERR = 43,

	/// <summary>
	/// 硬件原点开关
	/// </summary>
	YKE_AXIS_ITEM_HOME = 50,

	/// <summary>
	/// 硬件正限位
	/// </summary>
	YKE_AXIS_ITEM_HD_POSITIVE = 51,

	/// <summary>
	/// 硬件负限位
	/// </summary>
	YKE_AXIS_ITEM_HD_NEGATIVE = 52,

	/// <summary>
	/// 软件正限位
	/// </summary>
	YKE_AXIS_ITEM_SOFT_POSITIVE = 53,

	/// <summary>
	/// 软件负限位
	/// </summary>
	YKE_AXIS_ITEM_SOFT_NEGATIVE = 54,

	/// <summary>
	/// 反馈到位1
	/// </summary>
	YKE_AXIS_ITEM_INPOS1 = 60,

	/// <summary>
	/// 反馈到位2
	/// </summary>
	YKE_AXIS_ITEM_INPOS2 = 61,

	/// <summary>
	/// 反馈到位3
	/// </summary>
	YKE_AXIS_ITEM_INPOS3 = 62,

	/// <summary>
	/// 反馈到位4
	/// </summary>
	YKE_AXIS_ITEM_INPOS4 = 63,

	/// <summary>
	/// 反馈到位5
	/// </summary>
	YKE_AXIS_ITEM_INPOS5 = 64,

	/// <summary>
	/// 反馈到位6
	/// </summary>
	YKE_AXIS_ITEM_INPOS6 = 65,

	/// <summary>
	/// 用户测试值
	/// </summary>
	YKE_AXIS_ITEM_USER_TEST = 100,
}YKE_AXIS_ITEM_TYPE;

/// <summary>
/// 事件数据类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 启动命令
	/// </summary>
	YKE_EVENT_ITEM_START = 0,

	/// <summary>
	/// 事件状态
	/// </summary>
	YKE_EVENT_ITEM_STATUS = 1,
}YKE_EVENT_ITEM_TYPE;

/// <summary>
/// 多轴联动数据采集类型
/// </summary>
typedef enum
{
	/// <summary>
	/// active信号
	/// </summary>
	YKE_MULTI_AXIS_ITEM_ACTIVE = 0,

	/// <summary>
	/// done信号
	/// </summary>
	YKE_MULTI_AXIS_ITEM_DONE = 1,

	/// <summary>
	/// 剩余的规划时间
	/// </summary>
	YKE_MULTI_AXIS_ITEM_REMAIN_TIM = 10,

	/// <summary>
	/// 规划总时间
	/// </summary>
	YKE_MULTI_AXIS_ITEM_TOTAL_TIM = 11,

	/// <summary>
	/// 加速度
	/// </summary>
	YKE_MULTI_AXIS_ITEM_ACCELERATION = 21,
}YKE_MULTI_AXIS_ITEM_TYPE;

/// <summary>
/// 等待事件数据采集类型
/// </summary>
typedef enum
{
	/// <summary>
	/// active信号
	/// </summary>
	YKE_WAIT_ITEM_ACTIVE = 0,
}YKE_WAIT_ITEM_TYPE;

/// <summary>
/// 轴跟随信息
/// </summary>
typedef enum
{
	/// <summary>
	/// 规划位置
	/// </summary>
	YKE_AXIS_FOLLOW_CMD_POS = 0,

	/// <summary>
	/// 实际位置
	/// </summary>
	YKE_AXIS_FOLLOW_ACT_POS = 1,
}YKE_AXIS_FOLLOW_TYPE;

/// <summary>
/// 轴位置比较模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 规划位置
	/// </summary>
	YKE_AXIS_COMPARE_CMD_POS = 0,

	/// <summary>
	/// 实际位置
	/// </summary>
	YKE_AXIS_COMPARE_ACT_POS = 1,
}YKE_AXIS_COMPARE_TYPE;

/// <summary>
/// 坐标系跟随信息
/// </summary>
typedef enum
{
	/// <summary>
	/// XY已移动距离
	/// </summary>
	YKE_FOLLOW_GROUP_DIST_2D = 10,

	/// <summary>
	/// XYZ已移动距离
	/// </summary>
	YKE_FOLLOW_GROUP_DIST_3D = 11,
}YKE_FOLLOW_GROUP_TYPE;

/// <summary>
/// 系统信息采样数据类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 运动周期抖动ms
	/// </summary>
	YKE_SYS_ITEM_MOTICK = 0,

	/// <summary>
	/// 当前同步抖动ms
	/// </summary>
	YKE_SYS_ITEM_DC_JITTER = 1,

	/// <summary>
	/// 厂家调试0
	/// </summary>
	YKE_SYS_ITEM_DC_ADJUST = 2,

	/// <summary>
	/// CPU频率
	/// </summary>
	YKE_SYS_ITEM_CPU_FREQ = 3,

	/// <summary>
	/// YKGROUP负率ms
	/// </summary>
	YKE_SYS_ITEM_PAYLOAD_YKG = 4,

	/// <summary>
	/// NTF负载ms
	/// </summary>
	YKE_SYS_ITEM_PAYLOAD_NTF = 5,

	/// <summary>
	/// CNC负载ms
	/// </summary>
	YKE_SYS_ITEM_PAYLOAD_CNC = 6,

	/// <summary>
	/// 总负载ms
	/// </summary>
	YKE_SYS_ITEM_PAYLOAD_ALL = 7,

	/// <summary>
	/// 厂家调试1
	/// </summary>
	YKE_SYS_ITEM_TEST1 = 31,

	/// <summary>
	/// 厂家调试2
	/// </summary>
	YKE_SYS_ITEM_TEST2 = 32,

	/// <summary>
	/// 厂家调试3
	/// </summary>
	YKE_SYS_ITEM_TEST3 = 33,

	/// <summary>
	/// 厂家调试4
	/// </summary>
	YKE_SYS_ITEM_TEST4 = 34,

	/// <summary>
	/// 厂家调试5
	/// </summary>
	YKE_SYS_ITEM_TEST5 = 35,
}YKE_SYSTEM_ITEM_TYPE;

/// <summary>
/// 设置驱动器控制模式,总线轴专用
/// </summary>
typedef enum
{
	/// <summary>
	/// 无效选项
	/// </summary>
	YKE_DRV_OP_MODE_NONE = 0,

	/// <summary>
	/// 轮廓位置模式(PP)
	/// </summary>
	YKE_DRV_OP_MODE_PP = 1,

	/// <summary>
	/// 轮廓速度模式(PV)
	/// </summary>
	YKE_DRV_OP_MODE_PV = 3,

	/// <summary>
	/// 转矩模式(TQ)
	/// </summary>
	YKE_DRV_OP_MODE_TQ = 4,

	/// <summary>
	/// 回原模式(HM)
	/// </summary>
	YKE_DRV_OP_MODE_HM = 6,

	/// <summary>
	/// 周期位置模式(CSP)
	/// </summary>
	YKE_DRV_OP_MODE_CSP = 8,

	/// <summary>
	/// 周期速度模式(CSV)
	/// </summary>
	YKE_DRV_OP_MODE_CSV = 9,

	/// <summary>
	/// 周期转矩模式(CST)
	/// </summary>
	YKE_DRV_OP_MODE_CST = 10,
}YKE_DRV_OP_MODE;

/// <summary>
/// 跟随方式
/// </summary>
typedef enum
{
	/// <summary>
	/// 比例跟随
	/// </summary>
	YKE_AXIS_FOLLOW_SCALE = 0,

	/// <summary>
	/// 加减速跟随
	/// </summary>
	YKE_AXIS_FOLLOW_ACC = 1,
}YKE_AXIS_FOLLOW_MODE;

/// <summary>
/// 传送带同步状态
/// </summary>
typedef enum
{
	/// <summary>
	/// 同步中
	/// </summary>
	YKE_CONVEYOR_SYNC_SYNC_ACTIVE = 0,

	/// <summary>
	/// 同步失败
	/// </summary>
	YKE_CONVEYOR_SYNC_FAIL = 1,

	/// <summary>
	/// 同步完成
	/// </summary>
	YKE_CONVEYOR_SYNC_DONE = 2,
}YKE_CONVEYOR_SYNC_STATUS;

/// <summary>
/// 脉冲模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 脉冲+方向
	/// </summary>
	YKE_PULSE_DIR = 0,

	/// <summary>
	/// 正反向脉冲
	/// </summary>
	YKE_PULSE_PN = 1,
}YKE_PULSE_MODE;

/// <summary>
/// 捕获源
/// </summary>
typedef enum
{
	/// <summary>
	/// 捕获编码器
	/// </summary>
	YKE_CAPTURE_ENCODER = 0,

	/// <summary>
	/// 捕获规划脉冲
	/// </summary>
	YKE_CAPTURE_CMD_PULSE = 1,
}YKE_CAPTURE_SOURCE;

/// <summary>
/// 凸轮曲线
/// </summary>
typedef enum
{
	/// <summary>
	/// 多项式
	/// </summary>
	YKE_CAM_CURVE_POLY = 0,

	/// <summary>
	/// 样条
	/// </summary>
	YKE_CAM_CURVE_SPLINE = 1,
}YKE_CAM_CURVE;

/// <summary>
/// 双轴混合模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 加法
	/// </summary>
	YKE_COMBINE_ADD = 0,

	/// <summary>
	/// 减法
	/// </summary>
	YKE_COMBINE_SUB = 1,

	/// <summary>
	/// 合成距离
	/// </summary>
	YKE_COMBINE_DIST = 10,
}YKE_COMBINE_MODE;

/// <summary>
/// 总线从站配置操作内容
/// </summary>
typedef enum
{
	/// <summary>
	/// 站点移除(总线上未连实物)  值定义 0=不移除 非0=移除
	/// </summary>
	YKE_SLAVE_ITEM_REMOVE = 1,

	/// <summary>
	/// 站点启用(总线上有实物并通电) 值定义0=禁用 非0=启用
	/// </summary>
	YKE_SLAVE_ITEM_ENABLE = 2,
}YKE_SLAVE_ITEM;

/// <summary>
/// 数据类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 8位有符号
	/// </summary>
	YKE_INT8 = 0,

	/// <summary>
	/// 8位无符号
	/// </summary>
	YKE_UINT8 = 1,

	/// <summary>
	/// 16位有符号
	/// </summary>
	YKE_INT16 = 2,

	/// <summary>
	/// 16位无符号
	/// </summary>
	YKE_UINT16 = 3,

	/// <summary>
	/// 32位有符号
	/// </summary>
	YKE_INT32 = 4,

	/// <summary>
	/// 32位无符号
	/// </summary>
	YKE_UINT32 = 5,
}YKE_DATA_TYPE;

/// <summary>
/// 布尔数据
/// </summary>
typedef enum
{
	/// <summary>
	/// 否
	/// </summary>
	YKE_FALSE = 0,

	/// <summary>
	/// 是
	/// </summary>
	YKE_TRUE = 1,
}YKE_BOOL;

/// <summary>
/// 运动模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 无效
	/// </summary>
	YKE_MOTION_NONE = 0,

	/// <summary>
	/// 位置运动
	/// </summary>
	YKE_MOTION_POSITION = 1,

	/// <summary>
	/// 速度运动
	/// </summary>
	YKE_MOTION_VELOCITY = 2,

	/// <summary>
	/// 转矩
	/// </summary>
	YKE_MOTION_TORQUE = 3,

	/// <summary>
	/// 回原
	/// </summary>
	YKE_MOTION_HOME = 4,

	/// <summary>
	/// 软跟随
	/// </summary>
	YKE_MOTION_SOFT_FOLLOW = 5,

	/// <summary>
	/// 硬跟随
	/// </summary>
	YKE_MOTION_HARD_FOLLOW = 6,

	/// <summary>
	/// 坐标系
	/// </summary>
	YKE_MOTION_GROUP = 7,

	/// <summary>
	/// 多轴联动
	/// </summary>
	YKE_MOTION_MULTI_AXIS = 8,

	/// <summary>
	/// PVT
	/// </summary>
	YKE_MOTION_PVT = 9,
}YKE_MOTION_TYPE;

/// <summary>
/// 连接错误类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 无错误
	/// </summary>
	YKE_ERR_LINK_NONE = 0,

	/// <summary>
	/// 有帧未处理
	/// </summary>
	YKE_ERR_LINK_WKC = 1,

	/// <summary>
	/// 帧发送失败
	/// </summary>
	YKE_ERR_LINK_SEND = 2,

	/// <summary>
	/// 帧接收失败
	/// </summary>
	YKE_ERR_LINK_REV = 3,

	/// <summary>
	/// 读AL寄存器出错
	/// </summary>
	YKE_ERR_LINK_READREG = 4,

	/// <summary>
	/// 发送数据帧超过了1480字节
	/// </summary>
	YKE_ERR_LINK_SEND_SIZE = 13,

	/// <summary>
	/// 发送队列超过了32个
	/// </summary>
	YKE_ERR_LINK_SEND_QUENE = 14,

	/// <summary>
	/// 接收数据失败
	/// </summary>
	YKE_ERR_LINK_REV_QUENE = 15,

	/// <summary>
	/// 接收缓冲区分配失败
	/// </summary>
	YKE_ERR_LINK_ALLOC_REV = 22,

	/// <summary>
	/// 发送缓冲区分配失败
	/// </summary>
	YKE_ERR_LINK_ALLOC_SEND = 23,

	/// <summary>
	/// DC同步调整量过大
	/// </summary>
	YKE_ERR_LINK_DC_ADJUST = 27,

	/// <summary>
	/// 环网冗余已断开
	/// </summary>
	YKE_ERR_LINK_REDUNDANCY = 31,
}YKE_LINK_ERROR;

/// <summary>
/// 总线状态
/// </summary>
typedef enum
{
	/// <summary>
	/// 无总线活动
	/// </summary>
	YKE_BUS_STATUS_IDEL = 0,

	/// <summary>
	/// 初始化中
	/// </summary>
	YKE_BUS_STATUS_INITING = 1,

	/// <summary>
	/// 初始化发生错误
	/// </summary>
	YKE_BUS_STATUS_ERR = 2,

	/// <summary>
	/// 完全运行中
	/// </summary>
	YKE_BUS_STATUS_RUNNING = 10,
}YKE_BUS_STATUS;

/// <summary>
/// 同步运动模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 按轴最大限制运行
	/// </summary>
	YKE_SYNC_AXIS_LIMIT = 0,

	/// <summary>
	/// 以最慢的轴做参考同时到达
	/// </summary>
	YKE_SYNC_AXIS_SLOWEST = 1,

	/// <summary>
	/// 以最远的轴做参考同时到达
	/// </summary>
	YKE_SYNC_AXIS_FARTHESET = 2,

	/// <summary>
	/// 以指定时间运行
	/// </summary>
	YKE_SYNC_FIX_TIME = 3,
}YKE_SYNC_AXIS_MODE;

/// <summary>
/// 坐标系报警后输出状态
/// </summary>
typedef enum
{
	/// <summary>
	/// 保持当前状态
	/// </summary>
	YKE_GROUP_OUTPUT_IN_WARN_KEEP = 0,

	/// <summary>
	/// 置位
	/// </summary>
	YKE_GROUP_OUTPUT_IN_WARN_HIGH = 1,

	/// <summary>
	/// 复位
	/// </summary>
	YKE_GROUP_OUTPUT_IN_WARN_LOW = 2,
}YKE_GROUP_OUTPUT_IN_WARN;

/// <summary>
/// 急停信号有效后给轴的控制命令
/// </summary>
typedef enum
{
	/// <summary>
	/// 保持
	/// </summary>
	YKE_EMG_AXIS_KEEP = 0,

	/// <summary>
	/// 停止
	/// </summary>
	YKE_EMG_AXIS_STOP = 1,

	/// <summary>
	/// 停止并下使能
	/// </summary>
	YKE_EMG_AXIS_POWEROFF = 2,
}YKE_EMG_AXIS_BEGAVIOR;

/// <summary>
/// 坐标系采样数据类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 忙信号
	/// </summary>
	YKE_GROUP_ITEM_ACTIVE = 0,

	/// <summary>
	/// 完成信号
	/// </summary>
	YKE_GROUP_ITEM_DONE = 1,

	/// <summary>
	/// 当前运动行 从1开始
	/// </summary>
	YKE_GROUP_ITEM_CUR_LINE = 10,

	/// <summary>
	/// 当前行MARK
	/// </summary>
	YKE_GROUP_ITEM_CURMARK = 11,

	/// <summary>
	/// 当前速度
	/// </summary>
	YKE_GROUP_ITEM_VEL = 12,

	/// <summary>
	/// 当前加速度
	/// </summary>
	YKE_GROUP_ITEM_ACC = 13,

	/// <summary>
	/// 当前JERK,未实现
	/// </summary>
	YKE_GROUP_ITEM_JERK = 14,

	/// <summary>
	/// 报警标记
	/// </summary>
	YKE_GROUP_ITEM_WARN1 = 15,

	/// <summary>
	/// 报警代码
	/// </summary>
	YKE_GROUP_ITEM_WARN2 = 16,

	/// <summary>
	/// XY合成速度
	/// </summary>
	YKE_GROUP_ITEM_VEL_2D = 20,

	/// <summary>
	/// XYZ合成速度
	/// </summary>
	YKE_GROUP_ITEM_VEL_3D = 21,

	/// <summary>
	/// XY已移动距离
	/// </summary>
	YKE_GROUP_ITEM_DIST_2D = 22,

	/// <summary>
	/// XYZ已移动距离
	/// </summary>
	YKE_GROUP_ITEM_DIST_3D = 23,

	/// <summary>
	/// 工件X位置
	/// </summary>
	YKE_GROUP_ITEM_WORKPIECE_X = 30,

	/// <summary>
	/// 工件Y位置
	/// </summary>
	YKE_GROUP_ITEM_WORKPIECE_Y = 31,

	/// <summary>
	/// 工件Z位置
	/// </summary>
	YKE_GROUP_ITEM_WORKPIECE_Z = 32,

	/// <summary>
	/// 工件A位置
	/// </summary>
	YKE_GROUP_ITEM_WORKPIECE_A = 33,

	/// <summary>
	/// 工件B位置
	/// </summary>
	YKE_GROUP_ITEM_WORKPIECE_B = 34,

	/// <summary>
	/// 工件C位置
	/// </summary>
	YKE_GROUP_ITEM_WORKPIECE_C = 35,

	/// <summary>
	/// 调试用1
	/// </summary>
	YKE_GROUP_ITEM_DEBUG1 = 100,

	/// <summary>
	/// 调试用2
	/// </summary>
	YKE_GROUP_ITEM_DEBUG2 = 101,

	/// <summary>
	/// 调试用3
	/// </summary>
	YKE_GROUP_ITEM_DEBUG3 = 102,

	/// <summary>
	/// 调试用4
	/// </summary>
	YKE_GROUP_ITEM_DEBUG4 = 103,

	/// <summary>
	/// 调试用5
	/// </summary>
	YKE_GROUP_ITEM_DEBUG5 = 104,
}YKE_GROUP_ITEM_TYPE;

/// <summary>
/// 坐标系中位置比较模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 到达后立即输出
	/// </summary>
	YKE_GROUP_COMPARE_START_IMMEDIATELY = 0,

	/// <summary>
	/// 到达下一段终点后立即输出
	/// </summary>
	YKE_GROUP_COMPARE_END_IMMEDIATELY = 1,

	/// <summary>
	/// 以下一段起点为参考延时指定时间输出ms
	/// </summary>
	YKE_GROUP_COMPARE_COMPLETED_TIME = 2,

	/// <summary>
	/// 以下一段起点为参考移动指定距离输出(用户单位)
	/// </summary>
	YKE_GROUP_COMPARE_COMPLETED_DIST = 3,

	/// <summary>
	/// 以下一段终点为参考提前指定时间输出ms
	/// </summary>
	YKE_GROUP_COMPARE_REMAINING_TIME = 4,

	/// <summary>
	/// 以下一段终点为参考提前指定距离输出(用户单位)
	/// </summary>
	YKE_GROUP_COMPARE_REMAINING_DIST = 5,

	/// <summary>
	/// 下一段已运行距离超过指定比率(0~1)后输出
	/// </summary>
	YKE_GROUP_COMPARE_COMPLETED_RATE = 6,
}YKE_GROUP_COMPARE_MODE;

/// <summary>
/// 坐标系中数字输出模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 单次输出
	/// </summary>
	YKE_GROUP_DO_SINGLE = 0,

	/// <summary>
	/// 多脉冲输出,开关交替输出
	/// </summary>
	YKE_GROUP_DO_ALTERNATE = 1,

	/// <summary>
	/// 单脉冲输出
	/// </summary>
	YKE_GROUP_DO_PULSE = 2,
}YKE_GROUP_DO_MODE;

/// <summary>
/// 坐标系中PWM跟随模式
/// </summary>
typedef enum
{
	/// <summary>
	/// 固定参数输出
	/// </summary>
	YKE_GROUP_PWM_FIX = 0,

	/// <summary>
	/// 占空比自动调整
	/// </summary>
	YKE_GROUP_PWM_DUTY = 1,

	/// <summary>
	/// 频率自动调整
	/// </summary>
	YKE_GROUP_PWM_FREQ = 2,
}YKE_GROUP_PWM_MODE;

/// <summary>
/// 轴类型,coppylia仿真使用
/// </summary>
typedef enum
{
	/// <summary>
	/// 直线轴
	/// </summary>
	YKE_AXIS_SIM_LINEAR = 0,

	/// <summary>
	/// 旋转轴
	/// </summary>
	YKE_AXIS_SIM_ROTARY = 1,
}YKE_AXIS_SIM_TYPE;

/// <summary>
/// 触发类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 剩余时间(毫秒单位)
	/// </summary>
	YKE_TRIGGER_REMAINING_TIME = 0,

	/// <summary>
	/// 剩余距离(用户单位)
	/// </summary>
	YKE_TRIGGER_REMAINGING_DISTANCE = 1,

	/// <summary>
	/// 完成的时刻
	/// </summary>
	YKE_TRIGGER_SAMETIME_COMPLETION = 2,

	/// <summary>
	/// 运行时间(毫秒单位)
	/// </summary>
	YKE_TRIGGER_COMPLETED_TIME = 3,

	/// <summary>
	/// 完成距离(用户单位)
	/// </summary>
	YKE_TRIGGER_COMPLETED_DISTANCE = 4,

	/// <summary>
	/// 参考运动停止时,触发运动再经过一定的时间才停止,未实现
	/// </summary>
	YKE_TRIGGER_STAGGERED_TIME_COMPLETION = 5,

	/// <summary>
	/// 参考运动停止时,触发运动再经过一定的距离才停止,未实现
	/// </summary>
	YKE_TRIGGER_STAGGERED_DISTANCE_COMPLETION = 6,
}YKE_TRIGGER_TYPE;

/// <summary>
/// 信号源
/// </summary>
typedef enum
{
	/// <summary>
	/// 数字输入
	/// </summary>
	YKE_SIGNAL_SOURCE_INPUT = 0,

	/// <summary>
	/// 数字输出
	/// </summary>
	YKE_SIGNAL_SOURCE_OUTPUT = 1,

	/// <summary>
	/// 控制事件
	/// </summary>
	YKE_SIGNAL_SOURCE_EVENT = 2,

	/// <summary>
	/// 通用数据寄存器
	/// </summary>
	YKE_SIGNAL_SOURCE_REG = 3,
}YKE_SIGNAL_SOURCE_TYPE;

/// <summary>
/// 两个BIT位合成条件
/// </summary>
typedef enum
{
	/// <summary>
	/// 当两个指定的IO位均为TRUE时,条件为TRUE
	/// </summary>
	YKE_LOGIC_AND = 0,

	/// <summary>
	/// 两个指定的IO位中的任何一个为TRUE时,条件为TRUE
	/// </summary>
	YKE_LOGIC_OR = 1,

	/// <summary>
	/// 当两个指定的IO位均为TRUE时,条件为FALSE
	/// </summary>
	YKE_LOGIC_NAND = 2,

	/// <summary>
	/// 当两个指定的IO位中的任何一个为TRUE时,条件为FALSE
	/// </summary>
	YKE_LOGIC_NOR = 3,
}YKE_LOGIC_CONDITIONS;

/// <summary>
/// 事件状态
/// </summary>
typedef enum
{
	/// <summary>
	/// 空闲
	/// </summary>
	YKE_EVENT_STATUS_IDEL = 0,

	/// <summary>
	/// 等待事件发生
	/// </summary>
	YKE_EVENT_STATUS_WAIT = 5,

	/// <summary>
	/// 等待事件重新启动
	/// </summary>
	YKE_EVENT_STATUS_RESTART = 10,

	/// <summary>
	/// 延时中
	/// </summary>
	YKE_EVENT_STATUS_DELAY = 15,

	/// <summary>
	/// 事件已经发生
	/// </summary>
	YKE_EVENT_STATUS_FINISH = 20,
}YKE_EVENT_STATUS_TYTE;

/// <summary>
/// M/H辅助功能相对过渡段执行时间类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 平滑轮廓中(default)
	/// </summary>
	YKE_CNC_ACTION_INTER = 0,

	/// <summary>
	/// 平滑轮廓前
	/// </summary>
	YKE_CNC_ACTION_PRE = 1,

	/// <summary>
	/// 平滑轮廓后
	/// </summary>
	YKE_CNC_ACTION_POST = 2,
}YKE_CNC_ACTION_TYPE;

/// <summary>
/// Akima样条过渡切向类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 算法自动计算(default)
	/// </summary>
	YKE_CNC_ASPLINE_TRANS_AUTO = 0,

	/// <summary>
	/// 前后段切向自动
	/// </summary>
	YKE_CNC_ASPLINE_TRANS_TANGENTIAL = 1,

	/// <summary>
	/// 用户设置
	/// </summary>
	YKE_CNC_ASPLINE_TRANS_USER = 2,
}YKE_CNC_ASPLINE_TRANS_TYPE;

/// <summary>
/// HSC_Surface平滑变加速监控类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 不监控(default)
	/// </summary>
	YKE_CNC_CHECKJERK_NO = 0,

	/// <summary>
	/// 几何曲线监控
	/// </summary>
	YKE_CNC_CHECKJERK_GEOMERTRIC = 1,

	/// <summary>
	/// 非线性曲线监控
	/// </summary>
	YKE_CNC_CHECKJERK_NOLIEAR = 2,
}YKE_CNC_CHECK_JERK_TYPE;

/// <summary>
/// HSC_Serface平滑圆弧优化类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 圆弧轮廓平滑(default)
	/// </summary>
	YKE_HSC_CIR_MODE_CONTOUR = 0,

	/// <summary>
	/// 圆周运动无轮廓平滑
	/// </summary>
	YKE_HSC_CIR_MODE_NOCONTOUR = 1,

	/// <summary>
	/// 圆弧轮廓平滑+长路径圆优化
	/// </summary>
	YKE_HSC_CIR_MODE_CONTOUR_LONG = 2,
}YKE_HSC_CIR_MODE;

/// <summary>
/// CNC指令模式
/// </summary>
typedef enum
{
	/// <summary>
	/// API模式
	/// </summary>
	YKE_CNC_INS_API = 0,

	/// <summary>
	/// 文件模式
	/// </summary>
	YKE_CNC_INS_FILE = 1,

	/// <summary>
	/// 外部GUI控制
	/// </summary>
	YKE_CNC_EXTERN = 2,
}YKE_CNC_INS_MODE;

/// <summary>
/// 日志过滤选择
/// </summary>
typedef enum
{
	/// <summary>
	/// 采集所有指令
	/// </summary>
	YKE_LOGGER_FILTER_ALL = 0,

	/// <summary>
	/// 采集item中指定的指令
	/// </summary>
	YKE_LOGGER_FILTER_INCLUDE = 1,

	/// <summary>
	/// 采集item中未指定的指令
	/// </summary>
	YKE_LOGGER_FILTER_EXCLUDE = 2,
}YKE_LOGGER_FILTER_TYPE;

/// <summary>
/// 授权状态
/// </summary>
typedef enum
{
	/// <summary>
	/// 正常
	/// </summary>
	YKE_LICENSE_OK = 0,

	/// <summary>
	/// 轴授权数量不够
	/// </summary>
	YKE_LICENSE_AXIS = 1,

	/// <summary>
	/// 坐标系授权数量不够
	/// </summary>
	YKE_LICENSE_GROUP = 2,

	/// <summary>
	/// 无视觉授权
	/// </summary>
	YKE_LICENSE_VISION = 3,

	/// <summary>
	/// 电子凸轮授权数量不够
	/// </summary>
	YKE_LICENSE_ECAM = 4,

	/// <summary>
	/// 无PLC授权
	/// </summary>
	YKE_LICENSE_PLC = 5,

	/// <summary>
	/// 无可视化授权
	/// </summary>
	YKE_LICENSE_HMI = 6,

	/// <summary>
	/// 无实时通讯授权
	/// </summary>
	YKE_LICENSE_RT = 7,

	/// <summary>
	/// 无NTF授权
	/// </summary>
	YKE_LICENSE_NTF = 8,

	/// <summary>
	/// 250us及以下总线周期需要专用PC支持
	/// </summary>
	YKE_LICENSE_PC_250 = 9,

	/// <summary>
	/// 无API授权
	/// </summary>
	YKE_LICENSE_API = 10,

	/// <summary>
	/// 临时授权识别码不匹配
	/// </summary>
	YKE_LICENSE_SUID = 20,

	/// <summary>
	/// 临时授权已到期
	/// </summary>
	YKE_LICENSE_TEMP = 21,

	/// <summary>
	/// 授权解码失败
	/// </summary>
	YKE_LICENSE_SHELL = 30,
}YKE_LICENSE_STATUS;

/// <summary>
/// 工程配置数据掩码,按位定义
/// </summary>
typedef enum
{
	/// <summary>
	/// 全局配置
	/// </summary>
	YKE_PROJECT_GCONFIG = 0x01,

	/// <summary>
	/// 轴配置数据
	/// </summary>
	YKE_PROJECT_AXIS = 0x02,

	/// <summary>
	/// 本地高速卡数据
	/// </summary>
	YKE_PROJECT_CARD = 0x04,

	/// <summary>
	/// 总线配置数据
	/// </summary>
	YKE_PROJECT_ECAT = 0x08,
}YKE_PROJECT_MASK;

/// <summary>
/// 扫描内容
/// </summary>
typedef enum
{
	/// <summary>
	/// 无效
	/// </summary>
	YKE_SCAN_NONE = 0x00,

	/// <summary>
	/// 读制造商信息
	/// </summary>
	YKE_SCAN_VID = 0x01,

	/// <summary>
	/// 读槽位信息,网关使用
	/// </summary>
	YKE_SCAN_SLOT = 0x02,
}YKE_SCAN_INFO;

/// <summary>
/// 总线初始化状态
/// </summary>
typedef enum
{
	/// <summary>
	/// 空闲
	/// </summary>
	YKE_PDS_NONE = 0x00,

	/// <summary>
	/// 已加载配置文件
	/// </summary>
	YKE_PDS_LOAD = 10,

	/// <summary>
	/// 进入INIT模式
	/// </summary>
	YKE_PDS_ING = 20,

	/// <summary>
	/// EEP读取完成
	/// </summary>
	YKE_PDS_EEP = 21,

	/// <summary>
	/// 进入PREOP模式
	/// </summary>
	YKE_PDS_PREOP = 24,

	/// <summary>
	/// 进入SAFEOP模式
	/// </summary>
	YKE_PDS_SAFEOP = 25,

	/// <summary>
	/// PDO开始工作
	/// </summary>
	YKE_PDS_PDO = 30,

	/// <summary>
	/// 完全运行状态
	/// </summary>
	YKE_PDS_RUN = 40,
}YKE_PDS_PHASE;

/// <summary>
/// 加密狗类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 加密锁A
	/// </summary>
	YKE_DOGGLE_A = 0,

	/// <summary>
	/// 加密锁B
	/// </summary>
	YKE_DOGGLE_B = 1,
}YKE_DOGGLE_TYPE;

/// <summary>
/// PLC命令类型
/// </summary>
typedef enum
{
	/// <summary>
	/// 无效
	/// </summary>
	YKE_PLC_CMD_NONE = 0,

	/// <summary>
	/// 程序运行
	/// </summary>
	YKE_PLC_CMD_PRG_START = 1,

	/// <summary>
	/// 程序停止
	/// </summary>
	YKE_PLC_CMD_PRG_STOP = 2,

	/// <summary>
	/// PLC Runtime退出
	/// </summary>
	YKE_PLC_CMD_SYS_EXIT = 10,
}YKE_PLC_CMD_TYPE;

/// <summary>
/// 特性寄存器功能定义
/// </summary>
typedef enum
{
	/// <summary>
	/// 250usON 250usOFF
	/// </summary>
	YKE_500US_TICK = 0,

	/// <summary>
	/// 500usON 500usOFF
	/// </summary>
	YKE_1MS_TICK = 1,

	/// <summary>
	/// 2.5msON 2.5msOFF
	/// </summary>
	YKE_5MS_TICK = 2,

	/// <summary>
	/// 25msON 25msOFF
	/// </summary>
	YKE_50MS_TICK = 3,

	/// <summary>
	/// 250msON 250msOFF
	/// </summary>
	YKE_500MS_TICK = 4,

	/// <summary>
	/// 15sON 15sOFF
	/// </summary>
	YKE_30S_TICK = 5,

	/// <summary>
	/// 时钟秒
	/// </summary>
	YKE_TIME_SEC = 10,

	/// <summary>
	/// 时钟分
	/// </summary>
	YKE_TIME_MIN = 11,

	/// <summary>
	/// 时钟小时
	/// </summary>
	YKE_TIME_HOUR = 12,

	/// <summary>
	/// 时钟日
	/// </summary>
	YKE_TIME_DAY = 13,

	/// <summary>
	/// 时钟月
	/// </summary>
	YKE_TIME_MONTH = 14,

	/// <summary>
	/// 时钟年
	/// </summary>
	YKE_TIME_YEAR = 15,

	/// <summary>
	/// 星期
	/// </summary>
	YKE_TIME_WEEK = 16,

	/// <summary>
	/// 可视化当前页面,从1开始
	/// </summary>
	YKE_HMI_CURRENT_PAGE = 100,

	/// <summary>
	/// 切换可视化页面,从1开始
	/// </summary>
	YKE_HMI_CHANGE_PAGE = 101,

	/// <summary>
	/// 切换当前用户,0变1有效
	/// </summary>
	YKE_HMI_CHANGE_USER = 102,

	/// <summary>
	/// 切换当前配方,0变1有效
	/// </summary>
	YKE_HMI_CHANGE_RECIPE = 103,

	/// <summary>
	/// 重启可视化
	/// </summary>
	YKE_HMI_RESTART = 110,

	/// <summary>
	/// 关闭可视化
	/// </summary>
	YKE_HMI_CLOSE = 111,

	/// <summary>
	/// 待切换用户密码,占用2个寄存器
	/// </summary>
	YKE_HMI_CUR_USER_PW = 118,

	/// <summary>
	/// 待切换用户名称,占用20个寄存器
	/// </summary>
	YKE_HMI_CHANGE_USER_NAME = 120,

	/// <summary>
	/// 当前用户名称,占用20个寄存器
	/// </summary>
	YKE_HMI_CUR_USER_NAME = 140,

	/// <summary>
	/// 当前配方名称,占用20个寄存器
	/// </summary>
	YKE_HMI_CUR_RECIPE_NAME = 160,

	/// <summary>
	/// 待切换配方名称,占用20个寄存器
	/// </summary>
	YKE_HMI_CHANGE_RECIPE_NAME = 180,
}YKE_SPEC_REG;
#pragma endregion

#pragma region 结构体定义
/// <summary>
/// 3坐标值
/// </summary>
typedef struct _YKS_POINT3
{
	/// <summary>
	/// X坐标
	/// </summary>
	double x;

	/// <summary>
	/// Y坐标
	/// </summary>
	double y;

	/// <summary>
	/// Z坐标
	/// </summary>
	double z;
}YKS_POINT3;

/// <summary>
/// 输入信号配置
/// </summary>
typedef struct _YKS_AxisSwitchConfig
{
	/// <summary>
	/// 输入类型
	/// </summary>
	YKE_SWITCH_TYPE type;

	/// <summary>
	/// 探针配置:类型为YKE_SWITCH_COE_REG时:0=z相 1=ext
	/// 限位原点配置:类型为YKE_SWITCH_COE_REG表示60FD的bit序号,类型为YKE_SWITCH_GLOBAL_DIO表示DI字节序号
	/// </summary>
	UINT32 byte_offset;

	/// <summary>
	/// 类型为YKE_SWITCH_COE_REG时无效,类型为YKE_SWITCH_GLOBAL_DIO表示DI位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// 探针配置: FALSE=上升沿 TRUE=下降沿
	/// 对Z相无效
	/// 限位原点配置: TRUE=逻辑取反
	/// </summary>
	YKE_BOOL inv_or_edge;

	/// <summary>
	/// 位置偏差(0,DOUBLE_MAX](unit),YKE_SWITCH_MECHANICAL模式有效
	/// </summary>
	double position_error;

	/// <summary>
	/// 偏差保持时间[0,DOUBLE_MAX](ms),YKE_SWITCH_MECHANICAL模式有效
	/// </summary>
	double hold_time;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];
}YKS_AxisSwitchConfig;

/// <summary>
/// 系统配置
/// </summary>
typedef struct _YKS_SysProfile
{
	/// <summary>
	/// runtime启动路径
	/// </summary>
	char path[260];

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res6;

	/// <summary>
	/// 配置的轴数量
	/// </summary>
	UINT32 config_axis_num;

	/// <summary>
	/// 数字输入组数量
	/// </summary>
	UINT32 config_input_size;

	/// <summary>
	/// 数字输出组数量
	/// </summary>
	UINT32 config_output_size;

	/// <summary>
	/// 加密锁A序列号
	/// </summary>
	UINT32 dog_serial_numberA;

	/// <summary>
	/// 加密锁B序列号
	/// </summary>
	char dog_serial_numberB[64];

	/// <summary>
	/// 加密锁A内存空间,字节单位
	/// </summary>
	UINT32 dog_mem_sizeA;

	/// <summary>
	/// 加密锁B内存空间,字节单位
	/// </summary>
	UINT32 dog_mem_sizeB;

	/// <summary>
	/// 保留
	/// </summary>
	double res0;

	/// <summary>
	/// 轴授权数量
	/// </summary>
	UINT32 dog_axis_num;

	/// <summary>
	/// 轴使用数量
	/// </summary>
	UINT32 dog_axis_used;

	/// <summary>
	/// 凸轮授权数量
	/// </summary>
	UINT32 dog_ecam_num;

	/// <summary>
	/// 凸轮使用数量
	/// </summary>
	UINT32 dog_ecam_used;

	/// <summary>
	/// 视觉授权标记
	/// </summary>
	UINT32 dog_vision_num;

	/// <summary>
	/// 视觉使用标记
	/// </summary>
	UINT32 dog_vision_used;

	/// <summary>
	/// PLC授权标记
	/// </summary>
	UINT32 dog_plc_num;

	/// <summary>
	/// PLC使用标记
	/// </summary>
	UINT32 dog_plc_used;

	/// <summary>
	/// 可视化授权标记
	/// </summary>
	UINT32 dog_hmi_num;

	/// <summary>
	/// 可视化使用标记
	/// </summary>
	UINT32 dog_hmi_used;

	/// <summary>
	/// 实时通讯授权标记
	/// </summary>
	UINT32 dog_comm_num;

	/// <summary>
	/// 实时通讯使用标记
	/// </summary>
	UINT32 dog_comm_used;

	/// <summary>
	/// CAD授权标记
	/// </summary>
	UINT32 dog_cad_num;

	/// <summary>
	/// CAD使用标记
	/// </summary>
	UINT32 dog_cad_used;

	/// <summary>
	/// 坐标系授权数量
	/// </summary>
	UINT32 dog_group_num;

	/// <summary>
	/// 坐标系使用数量
	/// </summary>
	UINT32 dog_group_used;

	/// <summary>
	/// NTF授权标记
	/// </summary>
	UINT32 dog_dotNetRT_num;

	/// <summary>
	/// NTF使用标记
	/// </summary>
	UINT32 dog_dotNetRT_used;

	/// <summary>
	/// TRUE:使用临时授权
	/// </summary>
	YKE_BOOL dog_date_flag;

	/// <summary>
	/// 临时授权识别码
	/// </summary>
	UINT32 dog_date_uid;

	/// <summary>
	/// 临时授权到期时间:年
	/// </summary>
	UINT32 dog_date_year;

	/// <summary>
	/// 临时授权到期时间:月
	/// </summary>
	UINT32 dog_date_month;

	/// <summary>
	/// 临时授权到期时间:日
	/// </summary>
	UINT32 dog_date_day;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1;

	/// <summary>
	/// 专用PC授权标记
	/// </summary>
	UINT32 dog_pc_num;

	/// <summary>
	/// 专用PC使用标记
	/// </summary>
	UINT32 dog_pc_used;

	/// <summary>
	/// 授权状态
	/// </summary>
	YKE_LICENSE_STATUS lic_status;

	/// <summary>
	/// 授权错误标记
	/// TRUE=有错误 FALSE=无错误
	/// </summary>
	YKE_BOOL dog_err;

	/// <summary>
	/// 主站启用 TRUE=已启用 FALSE=未启用
	/// </summary>
	YKE_BOOL node_ena_0;
	YKE_BOOL node_ena_1;
	YKE_BOOL node_ena_2;
	YKE_BOOL node_ena_3;

	/// <summary>
	/// TRUE=已启用CNC FALSE=未启用CNC
	/// </summary>
	YKE_BOOL cnc_enable_0;
	YKE_BOOL cnc_enable_1;
	YKE_BOOL cnc_enable_2;
	YKE_BOOL cnc_enable_3;

	/// <summary>
	/// Runtime版本
	/// </summary>
	UINT32 runtime_ver;

	/// <summary>
	/// 内部库版本
	/// </summary>
	UINT32 plann_ver;

	/// <summary>
	/// TRUE=windows仿真模式 FALSE=实时模式
	/// </summary>
	YKE_BOOL sim_mode;

	/// <summary>
	/// 总线数据抓包节点
	/// </summary>
	YKE_NODE ecat_snap_node;

	/// <summary>
	/// 总线数据抓包区间
	/// </summary>
	UINT32 ecat_snap_span;

	/// <summary>
	/// PLC启用
	/// </summary>
	UINT32 plc_enable;

	/// <summary>
	/// PLC运行节点
	/// </summary>
	YKE_NODE plc_node;

	/// <summary>
	/// API授权标记
	/// </summary>
	UINT32 dog_api_num;

	/// <summary>
	/// API使用标记
	/// </summary>
	UINT32 dog_api_used;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res5[31];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[32];
}YKS_SysProfile;

/// <summary>
/// 数字输入输出配置
/// </summary>
typedef struct _YKS_DigitalIO
{
	/// <summary>
	/// 字节偏移
	/// </summary>
	UINT32 byte_offset;

	/// <summary>
	/// 位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// FALSE=不取反 TRUE=取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;
}YKS_DigitalIO;

/// <summary>
/// 数字输入配置
/// </summary>
typedef struct _YKS_DigitalInput
{
	/// <summary>
	/// FALSE=不启用 TRUE=启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 字节偏移[0,512)
	/// </summary>
	UINT32 byte_index;

	/// <summary>
	/// 位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// FALSE=不取反 TRUE=取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 滤波时间[0,1000](ms)
	/// </summary>
	double filter_tim;

	/// <summary>
	/// 当前状态 FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[7];
}YKS_DigitalInput;

/// <summary>
/// 数字输出配置
/// </summary>
typedef struct _YKS_DigitalOutput
{
	/// <summary>
	/// FALSE=不启用 TRUE=启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 字节偏移[0,512)
	/// </summary>
	UINT32 byte_index;

	/// <summary>
	/// 位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// 输出有效值 FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL valid;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_DigitalOutput;

/// <summary>
/// 同步数字输出配置
/// </summary>
typedef struct _YKS_DigitalOutputCycle
{
	/// <summary>
	/// 字节偏移[0,512)
	/// </summary>
	UINT32 byte_index;

	/// <summary>
	/// 位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// 输出有效值 FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL valid;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[4];
}YKS_DigitalOutputCycle;

/// <summary>
/// windows蓝屏后的行为
/// </summary>
typedef struct _YKS_BlueScreenConfig
{
	/// <summary>
	/// FALSE=不启用 TRUE=启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// FALSE=不处理 TRUE=停止所有轴
	/// </summary>
	YKE_BOOL stop_axis;

	/// <summary>
	/// FALSE=不处理 TRUE=关闭所有IO
	/// </summary>
	YKE_BOOL close_output;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];
}YKS_BlueScreenConfig;

/// <summary>
/// 硬件急停配置信息
/// </summary>
typedef struct _YKS_HardEmgProfile
{
	/// <summary>
	/// 急停输入
	/// </summary>
	YKS_DigitalInput emg_stop_input_0;
	YKS_DigitalInput emg_stop_input_1;
	YKS_DigitalInput emg_stop_input_2;
	YKS_DigitalInput emg_stop_input_3;
	YKS_DigitalInput emg_stop_input_4;
	YKS_DigitalInput emg_stop_input_5;
	YKS_DigitalInput emg_stop_input_6;
	YKS_DigitalInput emg_stop_input_7;

	/// <summary>
	/// 急停输出
	/// </summary>
	YKS_DigitalOutput emg_stop_output_0;
	YKS_DigitalOutput emg_stop_output_1;
	YKS_DigitalOutput emg_stop_output_2;
	YKS_DigitalOutput emg_stop_output_3;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_HardEmgProfile;

/// <summary>
/// 全局状态信息
/// </summary>
typedef struct _YKS_EmgStatus
{
	/// <summary>
	/// 软件急停信号状态 FALSE=无效 TRUE=有效
	/// </summary>
	YKE_BOOL emg_stop_soft;

	/// <summary>
	/// 急停输入状态 FALSE=无效 TRUE=有效
	/// </summary>
	YKE_BOOL emg_stop_input_0;
	YKE_BOOL emg_stop_input_1;
	YKE_BOOL emg_stop_input_2;
	YKE_BOOL emg_stop_input_3;
	YKE_BOOL emg_stop_input_4;
	YKE_BOOL emg_stop_input_5;
	YKE_BOOL emg_stop_input_6;
	YKE_BOOL emg_stop_input_7;

	/// <summary>
	/// 急停输入状态(按位定义8个急停输入结果)
	/// </summary>
	UINT32 emg_stop_input_all;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[4];
}YKS_EmgStatus;

/// <summary>
/// 总线实时信息
/// </summary>
typedef struct _YKS_BusStatus
{
	/// <summary>
	/// 配置的从站数量,包含未启用站点和移除站点
	/// </summary>
	UINT32 config_num;

	/// <summary>
	/// 配置中未移除的从站数量
	/// </summary>
	UINT32 useable_num;

	/// <summary>
	/// 实际检测到的从站数量
	/// </summary>
	UINT32 active_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 系统最小负载(ms)
	/// </summary>
	double min_payload;

	/// <summary>
	/// 系统最大负载(ms)
	/// </summary>
	double max_payload;

	/// <summary>
	/// 系统当前负载(ms)
	/// </summary>
	double cur_payload;

	/// <summary>
	/// 最小DC偏移(ms)
	/// </summary>
	double min_shift;

	/// <summary>
	/// 最大DC偏移(ms)
	/// </summary>
	double max_shift;

	/// <summary>
	/// 当前DC偏移(ms)
	/// </summary>
	double cur_shift;

	/// <summary>
	/// 总线周期(ms)
	/// </summary>
	double dc_cycle;

	/// <summary>
	/// 帧丢失计数
	/// </summary>
	UINT32 lost_frames;

	/// <summary>
	/// WKC丢失帧计数
	/// </summary>
	UINT32 lost_wkc;

	/// <summary>
	/// 主站激活标记 FALSE=未激活 TRUE=已激活
	/// </summary>
	YKE_BOOL master_active;

	/// <summary>
	/// 掉线的从站数量
	/// </summary>
	UINT32 offline_num;

	/// <summary>
	/// 每us中CPU的Tick数量
	/// </summary>
	UINT64 cpu_ticks;

	/// <summary>
	/// YKG最大负载(ms)
	/// </summary>
	double max_ykg_payload;

	/// <summary>
	/// YKG当前负载(ms)
	/// </summary>
	double cur_ykg_payload;

	/// <summary>
	/// NT最大负载(ms)
	/// </summary>
	double max_nt_payload;

	/// <summary>
	/// NT当前负载(ms)
	/// </summary>
	double cur_nt_payload;

	/// <summary>
	/// CNC最大负载(ms)
	/// </summary>
	double max_cnc_payload;

	/// <summary>
	/// CNC当前负载(ms)
	/// </summary>
	double cur_cnc_payload;

	/// <summary>
	/// 心跳计数,每个运动周期加1
	/// </summary>
	UINT64 heart_tick;

	/// <summary>
	/// 系统错误类型
	/// </summary>
	YKE_SYSTEM_ERROR sys_error_type;

	/// <summary>
	/// 系统层错误代码1
	/// </summary>
	UINT32 sys_error_code1;

	/// <summary>
	/// 系统层错误代码2
	/// </summary>
	UINT32 sys_error_code2;

	/// <summary>
	/// 链路层错误类型
	/// </summary>
	YKE_LINK_ERROR link_error_type;

	/// <summary>
	/// 链路层错误代码1
	/// </summary>
	UINT32 link_error_code1;

	/// <summary>
	/// 链路层错误代码2
	/// </summary>
	UINT32 link_error_code2;

	/// <summary>
	/// 总线状态
	/// </summary>
	YKE_BUS_STATUS bus_status;

	/// <summary>
	/// 系统SDO队列空闲数量
	/// </summary>
	UINT32 sys_sdo_idel;

	/// <summary>
	/// 用户SDO队列空闲数量
	/// </summary>
	UINT32 user_sdo_idel;

	/// <summary>
	/// 通讯帧长度(byte)
	/// </summary>
	UINT32 frame_length[16];

	/// <summary>
	/// 总线运行阶段
	/// </summary>
	YKE_PDS_PHASE pds_phase;

	/// <summary>
	/// 调试用1
	/// </summary>
	UINT32 debug1;

	/// <summary>
	/// 调试用2
	/// </summary>
	UINT32 debug2;

	/// <summary>
	/// 调试用3
	/// </summary>
	UINT32 debug3;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[9];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[32];
}YKS_BusStatus;

/// <summary>
/// 总线数据包的辅助信息
/// </summary>
typedef struct _YKS_BusPacketHeader
{
	/// <summary>
	/// 时间(毫秒单位)
	/// </summary>
	double time;

	/// <summary>
	/// TRUE=接收的数据 FALSE=发送的数据
	/// </summary>
	YKE_BOOL rev_flag;

	/// <summary>
	/// 源mac地址
	/// </summary>
	UINT8 source_mac[6];

	/// <summary>
	/// 目标mac地址
	/// </summary>
	UINT8 destion_mac[6];

	/// <summary>
	/// 数据包类型,EhterCAT为0x88A4
	/// </summary>
	UINT32 ethernet_type;

	/// <summary>
	/// 数据长度
	/// </summary>
	UINT32 length;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[4];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[4];
}YKS_BusPacketHeader;

/// <summary>
/// SDO命令状态
/// </summary>
typedef struct _YKS_SdoStatus
{
	/// <summary>
	/// FLASE=命令未完成 TRUE=命令已完成,数据有效
	/// </summary>
	YKE_BOOL valid;

	/// <summary>
	/// 返回数据
	/// </summary>
	UINT32 data;

	/// <summary>
	/// 时间开销(ms)
	/// </summary>
	double tim;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];
}YKS_SdoStatus;

/// <summary>
/// 总线从站状态
/// </summary>
typedef struct _YKS_SlaveStatus
{
	/// <summary>
	/// 0x130寄存器当前值
	/// </summary>
	UINT16 esc_status;

	/// <summary>
	/// 前面板ID
	/// </summary>
	UINT16 station_id;

	/// <summary>
	/// 时钟偏差(ns) 0x92C寄存器
	/// </summary>
	INT32 clock_offset;

	/// <summary>
	/// 错误类型
	/// </summary>
	YKE_SLAVE_ERROR slave_error_type;

	/// <summary>
	/// 错误代码
	/// </summary>
	UINT32 slave_error_code;

	/// <summary>
	/// COE访问错误的主索引(高16位)和子索引(低16位)
	/// </summary>
	UINT32 coe_type;

	/// <summary>
	/// COE标准错误代码
	/// </summary>
	UINT32 coe_code;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 al_res;

	/// <summary>
	/// AL寄存器的值(0x130)锁存值
	/// </summary>
	UINT32 al_code;

	/// <summary>
	/// FALSE=未掉线 TRUE=已掉线
	/// </summary>
	YKE_BOOL offline;

	/// <summary>
	/// PDO开始地址,字节单位
	/// </summary>
	UINT32 pdo_start;

	/// <summary>
	/// PDO数据数量,字节单位
	/// </summary>
	UINT32 pdo_length;

	/// <summary>
	/// 配置文件中的制造商ID
	/// </summary>
	UINT32 user_vid;

	/// <summary>
	/// 配置文件中的产品ID
	/// </summary>
	UINT32 user_pid;

	/// <summary>
	/// 配置文件中的修订号
	/// </summary>
	UINT32 user_revsion;

	/// <summary>
	/// 实际读回来的制造商ID
	/// </summary>
	UINT32 eep_vid;

	/// <summary>
	/// 际读回来的产品ID
	/// </summary>
	UINT32 eep_pid;

	/// <summary>
	/// 实际读回来的修订号
	/// </summary>
	UINT32 eep_revsion;

	/// <summary>
	/// ESC端口状态 FALSE=无链接 TRUE=有链接
	/// </summary>
	YKE_BOOL port_link_0;
	YKE_BOOL port_link_1;
	YKE_BOOL port_link_2;
	YKE_BOOL port_link_3;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[9];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[24];
}YKS_SlaveStatus;

/// <summary>
/// 从站PDO配置
/// </summary>
typedef struct _YKS_SlavePdoConfig
{
	/// <summary>
	/// 主索引
	/// </summary>
	UINT32 main_index;

	/// <summary>
	/// 子索引
	/// </summary>
	UINT32 sub_index;

	/// <summary>
	/// 位数量
	/// </summary>
	UINT32 bit_num;

	/// <summary>
	/// 位偏移
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// G索引
	/// </summary>
	UINT32 g_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_SlavePdoConfig;

/// <summary>
/// 模轴参数
/// </summary>
typedef struct _YKS_AxisProfileModulo
{
	/// <summary>
	/// FALSE=禁用模轴 TRUE=启用模轴
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 驱动器模轴状态 FALSE=否 TRUE=是
	/// </summary>
	YKE_BOOL drv_modulo_status;

	/// <summary>
	/// 单圈脉冲数量
	/// </summary>
	UINT32 single_encoder_count;

	/// <summary>
	/// 半圈模式(从最近的方向移动到目的地) FALSE=禁用 TRUE=启用
	/// </summary>
	YKE_BOOL half_turn;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProfileModulo;

/// <summary>
/// 单轴运动曲线参数
/// </summary>
typedef struct _YKS_AxisProfileMotion
{
	/// <summary>
	/// 加速曲线选择
	/// </summary>
	YKE_CURVE_TYPE curve_type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 启动速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double start_velocity;

	/// <summary>
	/// 停止速度[0,DOUBLE_MAX](unit/s)
	/// </summary>
	double stop_velocity;

	/// <summary>
	/// 运行速度[0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 加速时间[0,DOUBLE_MAX](ms)
	/// KE_CURVE_T7_TIME模式使用
	/// </summary>
	double acc_time;

	/// <summary>
	/// 减速时间[0,DOUBLE_MAX](ms)
	/// KE_CURVE_T7_TIME模式使用
	/// </summary>
	double dec_time;

	/// <summary>
	/// 加速段比率[0,1]
	/// YKE_CURVE_S7_RATE模式使用
	/// </summary>
	double acc_rate;

	/// <summary>
	/// 减速段比率[0,1]
	/// YKE_CURVE_S7_RATE模式使用
	/// </summary>
	double dec_rate;

	/// <summary>
	/// 加速段的变加速度[0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk_acc;

	/// <summary>
	/// 减速段的变加速度[0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk_dec;

	/// <summary>
	/// 匀速段最小时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double constant_velocity_time;

	/// <summary>
	/// 匀加速段最小时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double constant_acc_time;

	/// <summary>
	/// 匀减速度段最小时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double constant_dec_time;

	/// <summary>
	/// 平滑时间[0,DOUBLE_MAX](ms)
	/// YKE_CURVE_TS模式使用
	/// </summary>
	double smooth_time;

	/// <summary>
	/// 保留
	/// </summary>
	double res[28];
}YKS_AxisProfileMotion;

/// <summary>
/// 单轴基本运动参数配置
/// </summary>
typedef struct _YKS_AxisProfileBase
{
	/// <summary>
	/// 最高速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double max_velocity;

	/// <summary>
	/// 最大加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double max_acceleration;

	/// <summary>
	/// 最大变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double max_jerk;

	/// <summary>
	/// 急停时的减速度(0,DOUBLE_MAX](unit/s^2),如碰硬限位,急停stop指令
	/// </summary>
	double stop_dec_emg;

	/// <summary>
	/// 缓停时的减速度(0,DOUBLE_MAX](unit/s^2),如缓停stop指令
	/// </summary>
	double stop_dec_smooth;

	/// <summary>
	/// 软限位有效的减速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double stop_dec_limitsoft;

	/// <summary>
	/// 停止时的变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double stop_dec_jerk;

	/// <summary>
	/// CNC管理单轴运动
	/// FALSE=禁用 TRUE=启用
	/// </summary>
	YKE_BOOL enable_cnc;

	/// <summary>
	/// 急停信号有效后给轴的控制命令
	/// </summary>
	YKE_EMG_AXIS_BEGAVIOR emg_behavior;

	/// <summary>
	/// 关联的急停通道,按位定义
	/// </summary>
	UINT32 emg_mask;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 调试用
	/// </summary>
	double debug1;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[16];

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res2[16];
}YKS_AxisProfileBase;

/// <summary>
/// 单轴基本运动参数,到位相关
/// </summary>
typedef struct _YKS_AxisProfileInp
{
	/// <summary>
	/// 位置到位范围[0,DOUBLE_MAX](unit) 0=不启用
	/// </summary>
	double inp;

	/// <summary>
	/// 到位稳定时间[0,YKS_AxisProfileInp.inp_timout)(ms)
	/// </summary>
	double inp_tim;

	/// <summary>
	/// 到位超时时间[0,3000](ms)
	/// </summary>
	double inp_timout;

	/// <summary>
	/// 反馈位置到位范围1[0,DOUBLE_MAX](uint)
	/// </summary>
	double inp1_fb;

	/// <summary>
	/// 反馈位置到位范围2[0,DOUBLE_MAX](uint)
	/// </summary>
	double inp2_fb;

	/// <summary>
	/// 反馈位置到位范围3[0,DOUBLE_MAX](uint)
	/// </summary>
	double inp3_fb;

	/// <summary>
	/// 反馈位置到位范围4[0,DOUBLE_MAX](uint)
	/// </summary>
	double inp4_fb;

	/// <summary>
	/// 反馈位置到位范围5[0,DOUBLE_MAX](uint)
	/// </summary>
	double inp5_fb;

	/// <summary>
	/// 反馈位置到位范围6[0,DOUBLE_MAX](uint)
	/// </summary>
	double inp6_fb;

	/// <summary>
	/// 转矩到位范围(0.1%单位)
	/// </summary>
	double tq_inp;

	/// <summary>
	/// 转矩到位稳定时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double tq_tim;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProfileInp;

/// <summary>
/// 单轴基本运动参数, 跟随误差相关
/// </summary>
typedef struct _YKS_AxisProfilePositionLag
{
	/// <summary>
	/// 跟随误差检查时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double position_lag_tim;

	/// <summary>
	/// 最大跟随误差[0,DOUBLE_MAX](uint) 0=不启用
	/// </summary>
	double position_lag_limit;

	/// <summary>
	/// 跟随误差(YKS_AxisStatusPosition.position_lag_filter)滤波时间[0,100](ms)
	/// </summary>
	double position_lag_filter_time;

	/// <summary>
	/// 和主轴的最大位置偏差限制[0,DOUBLE_MAX](uint)
	/// </summary>
	double master_position_lag_limit;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProfilePositionLag;

/// <summary>
/// 清驱动器报警机制设置
/// </summary>
typedef struct _YKS_AxisProfileClearDrv
{
	/// <summary>
	/// 等待清除完成时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double wait_tim;

	/// <summary>
	/// 重试次数[0,100]
	/// </summary>
	UINT32 retry;

	/// <summary>
	/// 驱动器无报警情况下
	/// FALSE=不发命令到驱动器 TRUE=发命令到驱动器
	/// </summary>
	YKE_BOOL force;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProfileClearDrv;

/// <summary>
/// 轴使能机制设置
/// </summary>
typedef struct _YKS_AxisProfilePowerOn
{
	/// <summary>
	/// 等待使能完成时间[0,60000](ms)
	/// </summary>
	double wait_tim;

	/// <summary>
	/// YKS_AxisStatusBase.power_on信号有效后YKS_AxisStatusBase.active信号锁定时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double lock_tim;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProfilePowerOn;

/// <summary>
/// 轴前馈配置
/// </summary>
typedef struct _YKS_AxisProfileFeedforward
{
	/// <summary>
	/// 前馈启用 FALSE=未启用 TRUE=启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 速度权重
	/// </summary>
	double velocity_weighting;

	/// <summary>
	/// 速度延时输出
	/// </summary>
	double velocity_delay;

	/// <summary>
	/// 加速度权重
	/// </summary>
	double acceleration_weighting;

	/// <summary>
	/// 加速度延时输出
	/// </summary>
	double acceleration_delay;

	/// <summary>
	/// jerk权重
	/// </summary>
	double jerk_weighting;

	/// <summary>
	/// jerk延时输出
	/// </summary>
	double jerk_delay;

	/// <summary>
	/// 全局权重
	/// </summary>
	double global_weighting;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProfileFeedforward;

/// <summary>
/// 轴基本配置
/// </summary>
typedef struct _YKS_AxisConfigBase
{
	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 轴类型
	/// </summary>
	YKE_AXIS_PHY phy_type;

	/// <summary>
	/// 轴主序号
	/// </summary>
	UINT32 phy_main;

	/// <summary>
	/// 轴子序号
	/// </summary>
	UINT32 phy_sub;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[16];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[16];
}YKS_AxisConfigBase;

/// <summary>
/// 规划信息
/// </summary>
typedef struct _YKS_AxisStatusPlanner
{
	/// <summary>
	/// 规划器标记,内部使用
	/// </summary>
	UINT32 plann_flag;

	/// <summary>
	/// 规划完成 FALSE=未完成 TRUE=已完成
	/// </summary>
	YKE_BOOL command_done;

	/// <summary>
	/// 规划已完成时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double command_done_time;

	/// <summary>
	/// 规划器运行时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double command_run_time;

	/// <summary>
	/// 实际运行时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double actual_run_time;

	/// <summary>
	/// 规划的总运动时间[-1,DOUBLE_MAX](ms)
	/// </summary>
	double command_total_time;

	/// <summary>
	/// 剩余规划时间[-1,DOUBLE_MAX](ms)
	/// </summary>
	double command_remain_time;

	/// <summary>
	/// 变参数的时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double change_time;

	/// <summary>
	/// 算法耗时[0,DOUBLE_MAX](ms)
	/// </summary>
	double payload;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[16];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[16];
}YKS_AxisStatusPlanner;

/// <summary>
/// 轴位置相关状态
/// </summary>
typedef struct _YKS_AxisStatusPosition
{
	/// <summary>
	/// 原始位置(编码器反馈值)[INT32_MIN,INT32_MAX](pulse)
	/// </summary>
	INT32 encoder_raw_position;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 位置偏差(上位机位置减去驱动器位置)[INT32_MIN,INT32_MAX](pulse)
	/// </summary>
	INT64 position_offset;

	/// <summary>
	/// 位置跟随误差(无滤波)[DOUBLE_MIN,DOUBLE_MAX](uint)
	/// </summary>
	double position_lag;

	/// <summary>
	/// 滤波(YKS_AxisProfilePositionLag.position_lag_filter_time)后的位置跟随误差[DOUBLE_MIN,DOUBLE_MAX](uint)
	/// </summary>
	double position_lag_filter;

	/// <summary>
	/// 反馈位置1比较到位 FALSE=未到位 TRUE=已到位
	/// </summary>
	YKE_BOOL fb_inp1;

	/// <summary>
	/// 反馈位置2比较到位 FALSE=未到位 TRUE=已到位
	/// </summary>
	YKE_BOOL fb_inp2;

	/// <summary>
	/// 反馈位置3比较到位 FALSE=未到位 TRUE=已到位
	/// </summary>
	YKE_BOOL fb_inp3;

	/// <summary>
	/// 反馈位置4比较到位 FALSE=未到位 TRUE=已到位
	/// </summary>
	YKE_BOOL fb_inp4;

	/// <summary>
	/// 反馈位置5比较到位 FALSE=未到位 TRUE=已到位
	/// </summary>
	YKE_BOOL fb_inp5;

	/// <summary>
	/// 反馈位置6比较到位 FALSE=未到位 TRUE=已到位
	/// </summary>
	YKE_BOOL fb_inp6;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[16];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[16];
}YKS_AxisStatusPosition;

/// <summary>
/// 轴补偿状态
/// </summary>
typedef struct _YKS_AxisStatusCompensation
{
	/// <summary>
	/// 螺距补偿启用 FALSE=未启用 TRUE=启用
	/// </summary>
	YKE_BOOL pitch1d_active;

	/// <summary>
	/// 二维补偿启用 FALSE=未启用 TRUE=启用
	/// </summary>
	YKE_BOOL pitch2d_active;

	/// <summary>
	/// 间隙补偿启用 FALSE=未启用 TRUE=启用
	/// </summary>
	YKE_BOOL backlash_active;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 螺距补偿量 螺距补偿/二维补偿给定[DOUBLE_MIN,DOUBLE_MAX](uint)
	/// </summary>
	double pitch_value;

	/// <summary>
	/// 间隙补偿量
	/// </summary>
	double backlash_value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisStatusCompensation;

/// <summary>
/// 轴跟随状态
/// </summary>
typedef struct _YKS_AxisStatusFollow
{
	/// <summary>
	/// 软跟随运动的主轴  FALSE=否 TRUE=是
	/// </summary>
	YKE_BOOL follow_master;

	/// <summary>
	/// 硬跟随开启 FALSE=未开启 TRUE=已开启
	/// </summary>
	YKE_BOOL gantry_enable;

	/// <summary>
	/// 硬跟随主轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 gantry_master_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 与硬跟随主轴的实际位置偏差[DOUBLE_MIN,DOUBLE_MAX](uint)
	/// </summary>
	double gantry_actual_err;

	/// <summary>
	/// 与软件跟随主轴的实际位置偏差[DOUBLE_MIN,DOUBLE_MAX](uint)
	/// </summary>
	double follow_actual_err;

	/// <summary>
	/// 传送带同步状态
	/// </summary>
	YKE_CONVEYOR_SYNC_STATUS converyor_sync_status;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[7];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisStatusFollow;

/// <summary>
/// 轴基本状态
/// </summary>
typedef struct _YKS_AxisStatusBase
{
	/// <summary>
	/// 运动类型
	/// </summary>
	YKE_MOTION_TYPE motion_type;

	/// <summary>
	/// 停止类型
	/// </summary>
	YKE_AXIS_STOP_TYPE stop_type;

	/// <summary>
	/// 运动方向
	/// </summary>
	YKE_DIRECTION direction;

	/// <summary>
	/// 轴使能状态 FALSE=未使能  TRUE=已使能
	/// </summary>
	YKE_BOOL power_on;

	/// <summary>
	/// 回原状态  FALSE=未完成  TRUE=已完成
	/// </summary>
	YKE_BOOL is_homed;

	/// <summary>
	/// 轴运动状态 FALSE=空闲  TRUE=忙
	/// </summary>
	UINT32 active;

	/// <summary>
	/// 指令完成状态  FALSE=未完成  TRUE=已完成
	/// </summary>
	YKE_BOOL done;

	/// <summary>
	/// 锁存的Busy值
	/// </summary>
	UINT32 lock_busy;

	/// <summary>
	/// 轴报警状态 bit0:运动轴错误 bit1:驱动器错误
	/// 0=无错误 1=有错误
	/// </summary>
	UINT32 warnning;

	/// <summary>
	/// 运动轴错误代码
	/// </summary>
	YKE_MC_ERROR axis_warn_id;

	/// <summary>
	/// 驱动器报警代码, 等于603F寄存器内容
	/// </summary>
	UINT32 drv_error_id;

	/// <summary>
	/// TRUE=关联的总线站点已掉线 FLASE=未掉线
	/// </summary>
	YKE_BOOL offline;

	/// <summary>
	/// 原点信号状态  FALSE=信号无效  TRUE=信号有效
	/// </summary>
	YKE_BOOL home_switch;

	/// <summary>
	/// 硬件正限位状态 FALSE=信号无效  TRUE=信号有效
	/// </summary>
	YKE_BOOL limit_switch_pos;

	/// <summary>
	/// 硬件负限位状态 FALSE=信号无效  TRUE=信号有效
	/// </summary>
	YKE_BOOL limit_switch_neg;

	/// <summary>
	/// 正软限位到位状态 FALSE=信号无效  TRUE=信号有效
	/// </summary>
	YKE_BOOL limit_soft_pos;

	/// <summary>
	/// 负软限位到位状态 FALSE=信号无效  TRUE=信号有效
	/// </summary>
	YKE_BOOL limit_soft_neg;

	/// <summary>
	/// 软急停状态,按位定义
	/// </summary>
	UINT32 soft_emg;

	/// <summary>
	/// 硬急停状态,按位定义
	/// </summary>
	UINT32 hard_emg;

	/// <summary>
	/// 圆形区域保护,按位定义 0=不在限位区域内  1=在限位区域内
	/// </summary>
	UINT32 circle_zone;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[16];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[16];
}YKS_AxisStatusBase;

/// <summary>
/// 多轴运动状态
/// </summary>
typedef struct _YKS_MultiAxisStatus
{
	/// <summary>
	/// TRUE=运行中 FLASE=空闲
	/// </summary>
	YKE_BOOL active;

	/// <summary>
	/// TRUE=运行完成 FALSE=未完成
	/// </summary>
	YKE_BOOL done;

	/// <summary>
	/// 错误代码
	/// </summary>
	YKE_MC_ERROR error;

	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 规划总时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double total_tim;

	/// <summary>
	/// 运行距离
	/// </summary>
	double completed_dist;

	/// <summary>
	/// 剩余距离[0,DOUBLE_MAX](uint)
	/// </summary>
	double remain_dist;

	/// <summary>
	/// 运行时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double completed_tim;

	/// <summary>
	/// 剩余时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double remain_tim;

	/// <summary>
	/// 调试状态
	/// </summary>
	UINT32 debug1;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[9];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_MultiAxisStatus;

/// <summary>
/// 轴软件探针配置
/// </summary>
typedef struct _YKS_AxisProbeConfigSoft
{
	/// <summary>
	/// 触发输入
	/// </summary>
	YKS_DigitalIO input;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// FALSE=重复触发  TRUE=只触发一次
	/// </summary>
	YKE_BOOL trig_once;

	/// <summary>
	/// 触发内容
	/// </summary>
	YKE_AXIS_ITEM_TYPE item;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProbeConfigSoft;

/// <summary>
/// 软件探针状态
/// </summary>
typedef struct _YKS_AxisProbeStatusSoft
{
	/// <summary>
	/// 激活状态 FALSE=未激活 TRUE=已激活
	/// </summary>
	YKE_BOOL active;

	/// <summary>
	/// 触发次数
	/// </summary>
	UINT32 count;

	/// <summary>
	/// 触发值[DOUBLE_MIN,DOUBLE_MAX]
	/// </summary>
	double value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisProbeStatusSoft;

/// <summary>
/// 回原点参数
/// </summary>
typedef struct _YKS_AxisHomeConfig
{
	/// <summary>
	/// 速度曲线
	/// </summary>
	YKE_CURVE_TYPE curve_type;

	/// <summary>
	/// 回原点模式,参考CIA402规范
	/// </summary>
	YKE_HOME_MODE mode;

	/// <summary>
	/// 找到探针并减速停止后不回到探针位置
	/// FALSE=禁用  TRUE=启用
	/// </summary>
	YKE_BOOL out_of_probe;

	/// <summary>
	/// 提前开启探针
	/// FALSE=禁用  TRUE=启用
	/// </summary>
	YKE_BOOL pre_probe;

	/// <summary>
	/// 探针通道[0,1] 总线轴使用
	/// </summary>
	UINT32 index_probe;

	/// <summary>
	/// 回原完成后不修改当前位置,否则用logic_position设为当前位置
	/// FALSE=禁用  TRUE=启用
	/// </summary>
	YKE_BOOL keep_position;

	/// <summary>
	/// TRUE=驱动器编码器清零(调用驱动器35号模式回原)
	/// </summary>
	YKE_BOOL clear_encoder;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[7];

	/// <summary>
	/// 回原完成后的当前位置值[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double logic_position;

	/// <summary>
	/// 搜索速([0,DOUBLE_MAX](unit/s)
	/// </summary>
	double vel_high;

	/// <summary>
	/// 爬行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double vel_low;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 找限位/原点开关的最大移动量(0,DOUBLE_MAX](unit)
	/// 未设置时默认值5000
	/// </summary>
	double switch_move;

	/// <summary>
	/// 找探针的最大移动量(0,DOUBLE_MAX](unit)
	/// 未设置时默认值5000
	/// </summary>
	double probe_move;

	/// <summary>
	/// 参考探针/开关的移动距离(0,DOUBLE_MAX](unit)
	/// </summary>
	double offset;

	/// <summary>
	/// 转矩限制0.1/100单位 (0x6072:0) 设0时不做限制
	/// </summary>
	double torque_limit;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_AxisHomeConfig;

/// <summary>
/// 运动仿真规划信息
/// </summary>
typedef struct _YKS_MovePositionSimResult
{
	/// <summary>
	/// 加速段时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double acc_tim;

	/// <summary>
	/// 匀速段时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double constant_tim;

	/// <summary>
	/// 减速段时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double dec_tim;

	/// <summary>
	/// 总时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double total_tim;

	/// <summary>
	/// 速度峰值[DOUBLE_MIN,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 经过指定时间时的位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position_of_time;

	/// <summary>
	/// 经过指定时间时的速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity_of_time;

	/// <summary>
	/// 经过指定时间时的加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration_of_time;

	/// <summary>
	/// 经过指定时间时的变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk_of_time;

	/// <summary>
	/// 移动到指定位置时的时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double time_of_position;

	/// <summary>
	/// 移动到指定位置时的速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity_of_position;

	/// <summary>
	/// 移动到指定位置时的加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration_of_position;

	/// <summary>
	/// 移动到指定位置时的变加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk_of_position;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[16];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[16];
}YKS_MovePositionSimResult;

/// <summary>
/// 绝对运动配置
/// </summary>
typedef struct _YKS_MoveAbsoluteConfig
{
	/// <summary>
	/// 目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position;

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_MoveAbsoluteConfig;

/// <summary>
/// 仿真运动变参数配置
/// </summary>
typedef struct _YKS_MovePositionSimTrigger
{
	/// <summary>
	/// 启用变参数
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 触发模式
	/// FALSE=trigger_type和trigger_value指定的触发条件
	/// TRUE=在指定位置(at_position)变参数完成
	/// </summary>
	YKE_BOOL at_mode;

	/// <summary>
	/// 触发类型
	/// at_mode为FALSE有效
	/// </summary>
	YKE_TRIGGER_TYPE trigger_type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 时间或者距离
	/// at_mode为FALSE有效
	/// </summary>
	double trigger_value;

	/// <summary>
	/// 指定位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// at_mode为TRUE有效
	/// </summary>
	double at_position;

	/// <summary>
	/// 新的运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 新的目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double new_position;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_MovePositionSimTrigger;

/// <summary>
/// 仿真运动启动配置
/// </summary>
typedef struct _YKS_MovePositionSimConfig
{
	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position;

	/// <summary>
	/// 指定时间(at_time)的类型
	/// FALSE=经过的时间 TRUE=剩余的时间
	/// </summary>
	YKE_BOOL time_type;

	/// <summary>
	/// FALSE=轴当前位置为启动位置 TRUE=指定start_pos为启动位置
	/// </summary>
	YKE_BOOL set_start_pos;

	/// <summary>
	/// 开始位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double start_pos;

	/// <summary>
	/// 指定位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double at_position;

	/// <summary>
	/// 指定时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double at_time;

	/// <summary>
	/// FALSE=不返回指定时间或位置时的相关信息 TRUE=返回指定时间或位置时的相关信息
	/// </summary>
	YKE_BOOL at_calc;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[15];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[16];
}YKS_MovePositionSimConfig;

/// <summary>
/// 传送带运动配置
/// </summary>
typedef struct _YKS_MoveConveyorConfig
{
	/// <summary>
	/// 传送带移动方向
	/// </summary>
	YKE_DIRECTION direction;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 最远距离[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double distance;

	/// <summary>
	/// 传送带速度
	/// </summary>
	double velocity;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_MoveConveyorConfig;

/// <summary>
/// 相对运动配置
/// </summary>
typedef struct _YKS_MoveRelativeConfig
{
	/// <summary>
	/// 相对位移量[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double distance;

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_MoveRelativeConfig;

/// <summary>
/// 速度运动配置
/// </summary>
typedef struct _YKS_MoveVelocityConfig
{
	/// <summary>
	/// 运动方向
	/// </summary>
	YKE_DIRECTION direction;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_MoveVelocityConfig;

/// <summary>
/// 转矩运动配置
/// </summary>
typedef struct _YKS_MoveTorqueConfig
{
	/// <summary>
	/// 速度限制[0,DOUBLE_MAX](r/min)
	/// </summary>
	double velocity_max;

	/// <summary>
	/// 转矩值(0.1%单位)
	/// </summary>
	double torque;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_MoveTorqueConfig;

/// <summary>
/// 间隙补偿配置
/// </summary>
typedef struct _YKS_BacklashConfig
{
	/// <summary>
	/// 补偿方向
	/// </summary>
	YKE_DIRECTION dir;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 最大补偿量
	/// </summary>
	double backlash_high;

	/// <summary>
	/// 最小补偿量
	/// </summary>
	double backlash_low;

	/// <summary>
	/// 距参考位置的最远距离
	/// 大于此距离将施加最大间隙补偿量
	/// </summary>
	double distance_high;

	/// <summary>
	/// 距参考位置的最近距离
	/// 低于该距离将施加最小间隙补偿偏移量
	/// </summary>
	double distance_low;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_BacklashConfig;

/// <summary>
/// 一维螺距补偿配置
/// </summary>
typedef struct _YKS_PitchError1DConfig
{
	/// <summary>
	/// 补偿数量(0,YKE_PITCH1D_NUM]
	/// </summary>
	UINT32 count;

	/// <summary>
	/// 补偿原点[0,YKE_PITCH1D_NUM)
	/// </summary>
	UINT32 origin_index;

	/// <summary>
	/// 原始点的坐标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double origin_position;

	/// <summary>
	/// 补偿间隔[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double pitch_interval;

	/// <summary>
	/// 调整速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double catchup_velocity;

	/// <summary>
	/// 调整加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double catchup_acceleration;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_PitchError1DConfig;

/// <summary>
/// 二维螺距补偿配置
/// </summary>
typedef struct _YKS_PitchError2DConfig
{
	/// <summary>
	/// 生成补偿数据轴序号X[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index0;

	/// <summary>
	/// 生成补偿数据轴序号Y[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index1;

	/// <summary>
	/// X补偿原点[0,YKE_PITCH2D_NUM)
	/// </summary>
	UINT32 origin_index0;

	/// <summary>
	/// Y补偿原点[0,YKE_PITCH2D_NUM)
	/// </summary>
	UINT32 origin_index1;

	/// <summary>
	/// X补偿数量(0,YKE_PITCH2D_NUM]
	/// </summary>
	UINT32 count0;

	/// <summary>
	/// Y补偿数量(0,YKE_PITCH2D_NUM]
	/// </summary>
	UINT32 count1;

	/// <summary>
	/// 原始点的坐标位置X[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double origin_position0;

	/// <summary>
	/// 原始点的坐标位置Y[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double origin_position1;

	/// <summary>
	/// X方向间隔[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double pitch_interval0;

	/// <summary>
	/// Y方向间隔[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double pitch_interval1;

	/// <summary>
	/// 调整速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double catchup_velocity;

	/// <summary>
	/// 调整加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double catchup_acceleration;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_PitchError2DConfig;

/// <summary>
/// 单轴跟随配置
/// </summary>
typedef struct _YKS_FollowAxis1Config
{
	/// <summary>
	/// 跟随方式
	/// </summary>
	YKE_AXIS_FOLLOW_MODE mode;

	/// <summary>
	/// 主轴信息选择
	/// </summary>
	YKE_AXIS_FOLLOW_TYPE source;

	/// <summary>
	/// 主轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_master;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double numerator;

	/// <summary>
	/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double denominator;

	/// <summary>
	/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_FollowAxis1Config;

/// <summary>
/// 双轴跟随配置
/// </summary>
typedef struct _YKS_FollowAxis2Config
{
	/// <summary>
	/// 轴合成类型
	/// </summary>
	YKE_COMBINE_MODE combine_mode;

	/// <summary>
	/// 跟随方式
	/// </summary>
	YKE_AXIS_FOLLOW_MODE follow_mode;

	/// <summary>
	/// 主轴1信息选择
	/// </summary>
	YKE_AXIS_FOLLOW_TYPE source1;

	/// <summary>
	/// 主轴2信息选择
	/// </summary>
	YKE_AXIS_FOLLOW_TYPE source2;

	/// <summary>
	/// 主轴1序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_master1;

	/// <summary>
	/// 主轴2序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_master2;

	/// <summary>
	/// 分量分子1  合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double numerator1;

	/// <summary>
	/// 分量分母1 合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double denominator1;

	/// <summary>
	/// 分量分子2  合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double numerator2;

	/// <summary>
	/// 分量分母2 合成圆模式时固定为1[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double denominator2;

	/// <summary>
	/// 合成分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double numerator3;

	/// <summary>
	/// 合成分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double denominator3;

	/// <summary>
	/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_FollowAxis2Config;

/// <summary>
/// UG跟随配置
/// </summary>
typedef struct _YKS_FollowUgConfig
{
	/// <summary>
	/// 跟随曲线类型
	/// </summary>
	YKE_AXIS_FOLLOW_MODE mode;

	/// <summary>
	/// 主站选择
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// U序号
	/// </summary>
	UINT32 u_index;

	/// <summary>
	/// G序号
	/// </summary>
	UINT32 g_index;

	/// <summary>
	/// FALSE=16模式 TRUE=32模式
	/// </summary>
	YKE_BOOL bit32;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// UG信号滤波时间[0,1000](ms)
	/// </summary>
	double filter_tim;

	/// <summary>
	/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double numerator;

	/// <summary>
	/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double denominator;

	/// <summary>
	/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_FollowUgConfig;

/// <summary>
/// 坐标系跟随配置
/// </summary>
typedef struct _YKS_FollowGroupConfig
{
	/// <summary>
	/// 坐标系序号
	/// </summary>
	UINT32 group_index;

	/// <summary>
	/// 跟随模式
	/// </summary>
	YKE_AXIS_FOLLOW_MODE mode;

	/// <summary>
	/// 源数据
	/// </summary>
	YKE_FOLLOW_GROUP_TYPE source;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double numerator;

	/// <summary>
	/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double denominator;

	/// <summary>
	/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_FollowGroupConfig;

/// <summary>
/// 本地编码器跟随配置
/// </summary>
typedef struct _YKS_FollowEncoderConfig
{
	/// <summary>
	/// 跟随曲线类型
	/// </summary>
	YKE_AXIS_FOLLOW_MODE mode;

	/// <summary>
	/// 卡序号,默认为0
	/// </summary>
	UINT32 card_index;

	/// <summary>
	/// 编码器通道
	/// </summary>
	UINT32 encoder_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 编码器信号滤波时间[0,1000](ms)
	/// </summary>
	double filter_tim;

	/// <summary>
	/// 分子[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double numerator;

	/// <summary>
	/// 分母[DOUBLE_MIN,DOUBLE_MAX] 0除外
	/// </summary>
	double denominator;

	/// <summary>
	/// 加减速跟随:加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 加减速跟随:减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 加减速跟随:变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_FollowEncoderConfig;

/// <summary>
/// 凸轮配置
/// </summary>
typedef struct _YKS_CamInConfig
{
	/// <summary>
	/// 数据表行数
	/// </summary>
	UINT32 count;

	/// <summary>
	/// 曲线类型
	/// </summary>
	YKE_CAM_CURVE curve;

	/// <summary>
	/// 主轴序号
	/// </summary>
	UINT32 axis_master;

	/// <summary>
	/// FALSE=单次运行 TRUE=周期运行
	/// </summary>
	YKE_BOOL periodic;

	/// <summary>
	/// 保留,固定写FALSE=相对模式
	/// </summary>
	YKE_BOOL master_absolute;

	/// <summary>
	/// 保留,固定写FALSE=相对模式
	/// </summary>
	YKE_BOOL slave_absolute;

	/// <summary>
	/// 主轴缩放系数[DOUBLE_MIN,DOUBLE_MAX]
	/// </summary>
	double master_scale;

	/// <summary>
	/// 从轴缩放系数[DOUBLE_MIN,DOUBLE_MAX]
	/// </summary>
	double slave_scale;

	/// <summary>
	/// 保留,默认写0
	/// </summary>
	double master_offset;

	/// <summary>
	/// 保留,默认写0
	/// </summary>
	double slave_offset;

	/// <summary>
	/// 启动距离[0,DOUBLE_MAX](unit)
	/// </summary>
	double start_distance;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CamInConfig;

/// <summary>
/// 凸轮数据
/// </summary>
typedef struct _YKS_CamTable
{
	/// <summary>
	/// 主轴位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double master_position;

	/// <summary>
	/// 从轴位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double slave_position;

	/// <summary>
	/// 速度比例:多项式模式用[DOUBLE_MIN,DOUBLE_MAX]
	/// </summary>
	double vel_rate;

	/// <summary>
	/// 加速度比例:多项式模式用[DOUBLE_MIN,DOUBLE_MAX]
	/// </summary>
	double acc_rate;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CamTable;

/// <summary>
/// 坐标系设置,最大32轴
/// </summary>
typedef struct _YKS_GroupConfig
{
	/// <summary>
	/// 缓冲区深度[256,YKE_GROUP_DEPTH]
	/// </summary>
	UINT32 buffer_depth;

	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴序号列表,全局轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// CNC通道 FALSE=禁用  TRUE=启用
	/// </summary>
	YKE_BOOL cnc_enable;

	/// <summary>
	/// CNC运行模式
	/// </summary>
	YKE_CNC_INS_MODE cnc_mode;

	/// <summary>
	/// 闭环控制,CNC模式使用 FALSE=禁止  TRUE=开启
	/// </summary>
	YKE_BOOL close_loop_0;
	YKE_BOOL close_loop_1;
	YKE_BOOL close_loop_2;
	YKE_BOOL close_loop_3;
	YKE_BOOL close_loop_4;
	YKE_BOOL close_loop_5;
	YKE_BOOL close_loop_6;
	YKE_BOOL close_loop_7;
	YKE_BOOL close_loop_8;
	YKE_BOOL close_loop_9;
	YKE_BOOL close_loop_10;
	YKE_BOOL close_loop_11;
	YKE_BOOL close_loop_12;
	YKE_BOOL close_loop_13;
	YKE_BOOL close_loop_14;
	YKE_BOOL close_loop_15;
	YKE_BOOL close_loop_16;
	YKE_BOOL close_loop_17;
	YKE_BOOL close_loop_18;
	YKE_BOOL close_loop_19;
	YKE_BOOL close_loop_20;
	YKE_BOOL close_loop_21;
	YKE_BOOL close_loop_22;
	YKE_BOOL close_loop_23;
	YKE_BOOL close_loop_24;
	YKE_BOOL close_loop_25;
	YKE_BOOL close_loop_26;
	YKE_BOOL close_loop_27;
	YKE_BOOL close_loop_28;
	YKE_BOOL close_loop_29;
	YKE_BOOL close_loop_30;
	YKE_BOOL close_loop_31;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupConfig;

/// <summary>
/// 坐标系配置
/// </summary>
typedef struct _YKS_GroupProfile
{
	/// <summary>
	/// 最高速度[0,DOUBLE_MAX](unit/s)
	/// </summary>
	double max_velocity;

	/// <summary>
	/// 急停时的减速度[0,DOUBLE_MAX](unit/s^2),如碰限位,下使能等
	/// </summary>
	double stop_dec_emg;

	/// <summary>
	/// 缓停时的减速度[0,DOUBLE_MAX](unit/s^2),如stop指令
	/// </summary>
	double stop_dec_smooth;

	/// <summary>
	/// 停止时的变加速度[0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double stop_dec_jerk;

	/// <summary>
	/// 发生报警时,输出端口的行为
	/// </summary>
	YKE_GROUP_OUTPUT_IN_WARN output_in_warm;

	/// <summary>
	/// 关联的急停通道号 按位定义
	/// </summary>
	UINT32 emg_mask;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupProfile;

/// <summary>
/// 坐标系内CNC配置
/// </summary>
typedef struct _YKS_CncProfile
{
	/// <summary>
	/// 进给倍率(0, 1500]
	/// </summary>
	double feed_rate;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[16];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[16];
}YKS_CncProfile;

/// <summary>
/// MARK坐标系转换
/// </summary>
typedef struct _YKS_GroupTransMarkConfig
{
	/// <summary>
	/// 旋转中心x(以图纸坐标为参考)
	/// </summary>
	double rotate_x;

	/// <summary>
	/// 旋转中心y(以图纸坐标为参考)
	/// </summary>
	double rotate_y;

	/// <summary>
	/// 原点偏移x(以图纸坐标为参考)
	/// </summary>
	double offset_x;

	/// <summary>
	/// 原点偏移y(以图纸坐标为参考)
	/// </summary>
	double offset_y;

	/// <summary>
	/// X方向涨缩比例(以图纸坐标为参考)
	/// </summary>
	double scale_x;

	/// <summary>
	/// Y方向涨缩比例(以图纸坐标为参考)
	/// </summary>
	double scale_y;

	/// <summary>
	/// 旋转弧度(-PI~PI)
	/// </summary>
	double angle;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_GroupTransMarkConfig;

/// <summary>
/// 坐标系附加的XY输出
/// </summary>
typedef struct _YKS_GroupAddiXYConfig
{
	/// <summary>
	/// X轴序号
	/// </summary>
	UINT32 axis_x;

	/// <summary>
	/// Y轴序号
	/// </summary>
	UINT32 axis_y;

	/// <summary>
	/// 坐标转换
	/// </summary>
	YKS_GroupTransMarkConfig trans_config;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_GroupAddiXYConfig;

/// <summary>
/// 坐标系基本状态
/// </summary>
typedef struct _YKS_GroupStatusBase
{
	/// <summary>
	/// 运行主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 初始化状态  FALSE=未初始化 TRUE=已初始化
	/// </summary>
	YKE_BOOL inited;

	/// <summary>
	/// 运动状态   FALSE=未运动 TRUE=运动中
	/// </summary>
	YKE_BOOL active;

	/// <summary>
	/// 指令完成状态 FALSE=未完成 TRUE=已完成
	/// </summary>
	YKE_BOOL done;

	/// <summary>
	/// 报警标记 FALSE=无报警 TRUE=有报警
	/// </summary>
	YKE_BOOL warnning;

	/// <summary>
	/// 暂停状态 FALSE:不是 TRUE:是
	/// </summary>
	YKE_BOOL pause;

	/// <summary>
	/// 报警代码
	/// </summary>
	YKE_MC_ERROR warn_id;

	/// <summary>
	/// 规划器报警代码
	/// </summary>
	UINT32 plan_warn;

	/// <summary>
	/// 软急停状态,按位定义
	/// </summary>
	UINT32 soft_emg;

	/// <summary>
	/// 硬急停状态,按位定义
	/// </summary>
	UINT32 hard_emg;

	/// <summary>
	/// 运动缓冲区空闲数量[0,4096]
	/// </summary>
	UINT32 buffer_idel;

	/// <summary>
	/// 当前运动行,从1开始[0,UINT32_MAX]
	/// </summary>
	UINT32 running_line;

	/// <summary>
	/// 运动任务当前mark[0,UINT32_MAX]
	/// </summary>
	UINT32 running_mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// XY已经移动的距离[0,DOUBLE_MAX](unit)
	/// </summary>
	double distance_2d;

	/// <summary>
	/// XYZ已经移动的距离[0,DOUBLE_MAX](unit)
	/// </summary>
	double distance_3d;

	/// <summary>
	/// XY当前合成速度[0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity_2d;

	/// <summary>
	/// XYZ当前合成速度[0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity_3d;

	/// <summary>
	/// 规划速度[DOUBLE_MIN,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity_feed;

	/// <summary>
	/// 规划加速度[DOUBLE_MIN,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration_feed;

	/// <summary>
	/// 规划运行时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double command_time;

	/// <summary>
	/// 实际运行时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double actual_time;

	/// <summary>
	/// 规划器类型
	/// </summary>
	UINT32 plann_type;

	/// <summary>
	/// 调试2
	/// </summary>
	UINT32 debug_phase;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[24];
}YKS_GroupStatusBase;

/// <summary>
/// 坐标系CNC模块状态, 须开启CNC选项
/// </summary>
typedef struct _YKS_GroupStatusCnc
{
	/// <summary>
	/// 工件坐标系下的XYZABC方向位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double workpiece_pos[6];

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[24];
}YKS_GroupStatusCnc;

/// <summary>
/// 坐标系直线插补,绝对模式
/// </summary>
typedef struct _YKS_MoveLinearAbsoluteConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position[32];

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveLinearAbsoluteConfig;

/// <summary>
/// 坐标系直线插补,相对模式
/// </summary>
typedef struct _YKS_MoveLinearRelativeConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double distance[32];

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveLinearRelativeConfig;

/// <summary>
/// 坐标系螺旋插补,相对模式
/// </summary>
typedef struct _YKS_MoveHelixRelativeConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 方向选择
	/// </summary>
	YKE_CIRCULAR_PATH_CHOICE path_choice;

	/// <summary>
	/// 辅助点模式,仅圆心模式支持绽放/收敛螺旋线
	/// </summary>
	YKE_CIRCULAR_AUX_MODE aux_mode;

	/// <summary>
	/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 distance;

	/// <summary>
	/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 aux_point;

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 圈数[0,UINT32_MAX]
	/// </summary>
	UINT32 circle;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveHelixRelativeConfig;

/// <summary>
/// 坐标系螺旋插补,绝对模式
/// </summary>
typedef struct _YKS_MoveHelixAbsoluteConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 方向选择
	/// </summary>
	YKE_CIRCULAR_PATH_CHOICE path_choice;

	/// <summary>
	/// 辅助点模式,仅支持圆心模式,支持绽放/收敛螺旋线
	/// </summary>
	YKE_CIRCULAR_AUX_MODE aux_mode;

	/// <summary>
	/// 终点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 end_point;

	/// <summary>
	/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 aux_point;

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 圈数[0,UINT32_MAX]
	/// </summary>
	UINT32 circle;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveHelixAbsoluteConfig;

/// <summary>
/// 坐标系圆弧插补,绝对模式
/// </summary>
typedef struct _YKS_MoveCircularAbsoluteConfig
{
	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 轴数量[2,3]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 终点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position[32];

	/// <summary>
	/// 方向选择
	/// </summary>
	YKE_CIRCULAR_PATH_CHOICE path_choice;

	/// <summary>
	/// 辅助点模式
	/// </summary>
	YKE_CIRCULAR_AUX_MODE aux_mode;

	/// <summary>
	/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 aux_point;

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveCircularAbsoluteConfig;

/// <summary>
/// 坐标系圆弧插补,相对模式
/// </summary>
typedef struct _YKS_MoveCircularRelativeConfig
{
	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 轴数量[2,3]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double distance[32];

	/// <summary>
	/// 方向选择
	/// </summary>
	YKE_CIRCULAR_PATH_CHOICE path_choice;

	/// <summary>
	/// 辅助点模式
	/// </summary>
	YKE_CIRCULAR_AUX_MODE aux_mode;

	/// <summary>
	/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 aux_point;

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveCircularRelativeConfig;

/// <summary>
/// 坐标系Cardinal样条插补,相对模式
/// </summary>
typedef struct _YKS_MoveCardinalRelativeConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double distance[32];

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveCardinalRelativeConfig;

/// <summary>
/// 坐标系Cardinal样条插补,绝对模式
/// </summary>
typedef struct _YKS_MoveCardinalAbsoluteConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴列表,坐标系内轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position[32];

	/// <summary>
	/// 运行速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 加速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double acceleration;

	/// <summary>
	/// 减速度(0,DOUBLE_MAX](unit/s^2)
	/// </summary>
	double deceleration;

	/// <summary>
	/// 变加速度(0,DOUBLE_MAX](unit/s^3)
	/// </summary>
	double jerk;

	/// <summary>
	/// 缓冲模式
	/// </summary>
	YKE_BUFFER_MODE buffer_mode;

	/// <summary>
	/// 过渡模式
	/// </summary>
	YKE_TRANSITION_MODE trans_mode;

	/// <summary>
	/// 过度参数[0,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 trans_para;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_MoveCardinalAbsoluteConfig;

/// <summary>
/// 轴信号等待条件
/// </summary>
typedef struct _YKS_WaitAxis
{
	/// <summary>
	/// 轴数量[1, 32]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴列表
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 等待类型
	/// </summary>
	YKE_AXIS_WAIT_TYPE type;

	/// <summary>
	/// 超时时间(ms),负数表示一直等待
	/// </summary>
	double timeout;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_WaitAxis;

/// <summary>
/// 数字输入信号等待条件
/// </summary>
typedef struct _YKS_WaitDigitalInput
{
	/// <summary>
	/// 信号数量[1, 32]
	/// </summary>
	UINT32 di_num;

	/// <summary>
	/// 字节序号
	/// </summary>
	UINT32 byte_offset[32];

	/// <summary>
	/// 位偏移
	/// </summary>
	UINT32 bit_offset[32];

	/// <summary>
	/// 等待类型
	/// </summary>
	YKE_DIGITAL_INPUT_WAIT_TYPE type;

	/// <summary>
	/// 超时时间(ms),负数表示一直等待
	/// </summary>
	double timeout;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_WaitDigitalInput;

/// <summary>
/// 事件信号等待条件
/// </summary>
typedef struct _YKS_WaitEvent
{
	/// <summary>
	/// 事件数量[1,32]
	/// </summary>
	UINT32 event_num;

	/// <summary>
	/// 事件序号(0, YKE_EVENT_NUM]
	/// </summary>
	UINT32 event_index[32];

	/// <summary>
	/// 等待类型
	/// </summary>
	YKE_EVENT_WAIT_TYPE type;

	/// <summary>
	/// 超时时间(ms),负数表示一直等待
	/// </summary>
	double timeout;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_WaitEvent;

/// <summary>
/// 等待状态
/// </summary>
typedef struct _YKS_WaitStatus
{
	/// <summary>
	/// FALSE=空闲 TRUE=等待中
	/// </summary>
	YKE_BOOL active;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 已等待时间(ms)
	/// </summary>
	double time;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_WaitStatus;

/// <summary>
/// 圆形区域保护配置
/// </summary>
typedef struct _YKS_CircleZoneConfig
{
	/// <summary>
	/// 轴数量,固定为2
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴列表
	/// </summary>
	UINT32 axis_list[3];

	/// <summary>
	/// FALSE=使用规划位置 TRUE=使用反馈位置
	/// </summary>
	YKE_BOOL use_feedback;

	/// <summary>
	/// FALSE=圆内区域有效 TRUE=圆外区域有效
	/// </summary>
	YKE_BOOL outside;

	/// <summary>
	/// 停止减速度选择
	/// </summary>
	YKE_STOP_DEC stop_dec;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 圆心位置
	/// </summary>
	double center[3];

	/// <summary>
	/// 半径
	/// </summary>
	double radius;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_CircleZoneConfig;

/// <summary>
/// 圆形区域保护状态
/// </summary>
typedef struct _YKS_CircleZoneStatus
{
	/// <summary>
	/// FALSE=禁用 TRUE=启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// FALSE=有效区域 TRUE=无效区域
	/// </summary>
	YKE_BOOL invalid;
}YKS_CircleZoneStatus;

/// <summary>
/// 本地PCI卡配置信息
/// </summary>
typedef struct _YKS_CardConfigPCI
{
	/// <summary>
	/// 0:T serial
	/// </summary>
	UINT32 type;

	/// <summary>
	/// 硬件版本
	/// </summary>
	UINT32 hardware_ver;

	/// <summary>
	/// 固件版本
	/// </summary>
	UINT32 firmware_ver;

	/// <summary>
	/// 数字输入数量 (bit单位)
	/// </summary>
	UINT32 dinput_num;

	/// <summary>
	/// 数字输出数量 (bit单位)
	/// </summary>
	UINT32 doutput_num;

	/// <summary>
	/// 轴数量
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 编码器数量
	/// </summary>
	UINT32 encode_num;

	/// <summary>
	/// 位置比较器数量
	/// </summary>
	UINT32 compare_num;

	/// <summary>
	/// 位置锁存器数量
	/// </summary>
	UINT32 capture_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CardConfigPCI;

/// <summary>
/// 本地PCI卡脉冲轴IO信息
/// </summary>
typedef struct _YKS_AxisStausPCI
{
	/// <summary>
	/// 脉冲口序号
	/// </summary>
	UINT32 pls_pin;

	/// <summary>
	/// 方向口序号
	/// </summary>
	UINT32 dir_pin;

	/// <summary>
	/// 脉冲模式
	/// </summary>
	YKE_PULSE_MODE mode;

	/// <summary>
	/// 占空比 1~100
	/// </summary>
	UINT32 duty;

	/// <summary>
	/// 负限位状态  FALSE=无效 TRUE=有效
	/// </summary>
	YKE_BOOL switch_limit_negative;

	/// <summary>
	/// 正限位状态  FALSE=无效 TRUE=有效
	/// </summary>
	YKE_BOOL switch_limit_positive;

	/// <summary>
	/// 原点状态  FALSE=无效 TRUE=有效
	/// </summary>
	YKE_BOOL switch_home;

	/// <summary>
	/// 驱动状态  FALSE=未准备好 TRUE=已准备好
	/// </summary>
	YKE_BOOL drv_ready;

	/// <summary>
	/// 驱动报警 FALSE=无报警 TRUE=有报警
	/// </summary>
	YKE_BOOL drv_warn;

	/// <summary>
	/// 驱动到位状态  FALSE=未到位 TRUE=已到位
	/// </summary>
	YKE_BOOL drv_inp;

	/// <summary>
	/// 驱动使能状态 FALSE=未使能 TRUE=已使能
	/// </summary>
	YKE_BOOL drv_enable;

	/// <summary>
	/// 驱动报警清除信号状态 FALSE=无效 TRUE=有效
	/// </summary>
	YKE_BOOL drv_reset;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisStausPCI;

/// <summary>
/// 本地PCI高速卡编码器配置
/// </summary>
typedef struct _YKS_EncoderConfig
{
	/// <summary>
	/// 模式
	/// </summary>
	YKE_ENCODER_MODE mode;

	/// <summary>
	/// A输入极性  FALSE=正极性 TRUE=负极性
	/// </summary>
	YKE_BOOL polarity_a;

	/// <summary>
	/// B输入极性  FALSE=正极性 TRUE=负极性
	/// </summary>
	YKE_BOOL polarity_b;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_EncoderConfig;

/// <summary>
/// 本地PCI高速卡位置比较器配置
/// </summary>
typedef struct _YKS_CompareConfig
{
	/// <summary>
	/// 比较模式
	/// </summary>
	YKE_COMPARE_MODE mode;

	/// <summary>
	/// 启用二维模式
	/// 未实现
	/// </summary>
	YKE_BOOL enable_2d;

	/// <summary>
	/// 输出持续时间[0,10.23](ms); 最大10.23ms
	/// </summary>
	double keep_time;

	/// <summary>
	/// 比较数量,线性模式用[0,511]  0=无限多
	/// </summary>
	UINT32 number;

	/// <summary>
	/// X方向间距,线性模式用[INT32_MIN,INT32_MAX](pulse)
	/// </summary>
	INT32 spacing1;

	/// <summary>
	/// Y方向间距,线性模式用[INT32_MIN,INT32_MAX](pulse)
	/// </summary>
	INT32 spacing2;

	/// <summary>
	/// 输出0启用 FALSE=禁止输出 TRUE=允许输出
	/// </summary>
	YKE_BOOL ena_bit0;

	/// <summary>
	/// 输出1启用 FALSE=禁止输出 TRUE=允许输出
	/// </summary>
	YKE_BOOL ena_bit1;

	/// <summary>
	/// 输出2启用 FALSE=禁止输出 TRUE=允许输出
	/// </summary>
	YKE_BOOL ena_bit2;

	/// <summary>
	/// 输出3启用 FALSE=禁止输出 TRUE=允许输出
	/// </summary>
	YKE_BOOL ena_bit3;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[7];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CompareConfig;

/// <summary>
/// 监控对象：轴
/// </summary>
typedef struct _YKS_OscItemAxis
{
	/// <summary>
	/// 轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 轴数据选择
	/// </summary>
	YKE_AXIS_ITEM_TYPE type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemAxis;

/// <summary>
/// 监控对象：坐标系
/// </summary>
typedef struct _YKS_OscItemGroup
{
	/// <summary>
	/// 坐标系序号[0,YKE_GROUP_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 数据选择
	/// </summary>
	YKE_GROUP_ITEM_TYPE type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemGroup;

/// <summary>
/// 监控对象：对象字典
/// </summary>
typedef struct _YKS_OscItemSlaveObject
{
	/// <summary>
	/// 主站选择
	/// </summary>
	YKE_NODE node;

	/// <summary>
	/// 从站序号
	/// </summary>
	UINT32 slave_index;

	/// <summary>
	/// COE对象字典,主索引
	/// </summary>
	UINT32 main_index;

	/// <summary>
	/// COE对象字典,子索引
	/// </summary>
	UINT32 sub_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemSlaveObject;

/// <summary>
/// 监控对象：UG
/// </summary>
typedef struct _YKS_OscItemSlaveUG
{
	/// <summary>
	/// 主站选择
	/// </summary>
	YKE_NODE node;

	/// <summary>
	/// 从站序号
	/// </summary>
	UINT32 slave_index;

	/// <summary>
	/// G序号
	/// </summary>
	UINT32 g_index;

	/// <summary>
	/// FALSE=16bit模式 TRUE=32bit模式
	/// </summary>
	YKE_BOOL g_dword;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemSlaveUG;

/// <summary>
/// 监控对象：数字输入
/// </summary>
typedef struct _YKS_OscItemDI
{
	/// <summary>
	/// 字节序号[0,512)
	/// </summary>
	UINT32 byte_index;

	/// <summary>
	/// 位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemDI;

/// <summary>
/// 监控对象：数字输出
/// </summary>
typedef struct _YKS_OscItemDO
{
	/// <summary>
	/// 字节序号[0,512)
	/// </summary>
	UINT32 byte_index;

	/// <summary>
	/// 位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemDO;

/// <summary>
/// 监控对象：通用寄存器
/// </summary>
typedef struct _YKS_OscItemReg
{
	/// <summary>
	/// 序号[0,YKE_GENDATA_SIZE)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 数据类型
	/// </summary>
	YKE_DATA_TYPE data_type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemReg;

/// <summary>
/// 监控对象：系统信息
/// </summary>
typedef struct _YKS_OscItemSystem
{
	/// <summary>
	/// 主站选择
	/// </summary>
	YKE_NODE node;

	/// <summary>
	/// 系统信息
	/// </summary>
	YKE_SYSTEM_ITEM_TYPE type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemSystem;

/// <summary>
/// 监控对象：编码器
/// </summary>
typedef struct _YKS_OscItemEncoder
{
	/// <summary>
	/// 卡选择,默认0
	/// </summary>
	UINT32 card_index;

	/// <summary>
	/// 序号
	/// </summary>
	UINT32 encoder_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemEncoder;

/// <summary>
/// 监控对象：事件
/// </summary>
typedef struct _YKS_OscItemEvent
{
	/// <summary>
	/// 事件序号[0,YKE_EVENT_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 事件数据选择
	/// </summary>
	YKE_EVENT_ITEM_TYPE type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemEvent;

/// <summary>
/// 监控对象：多轴联动
/// </summary>
typedef struct _YKS_OscItemMultiAxis
{
	/// <summary>
	/// 通道号[0,YKE_MULTI_AXIS_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 数据选择
	/// </summary>
	YKE_MULTI_AXIS_ITEM_TYPE type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemMultiAxis;

/// <summary>
/// 监控对象：等待事件
/// </summary>
typedef struct _YKS_OscItemWait
{
	/// <summary>
	/// 通道号[0,YKE_WAIT_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 数据选择
	/// </summary>
	YKE_WAIT_ITEM_TYPE type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[2];
}YKS_OscItemWait;

/// <summary>
/// 监控对象
/// </summary>
typedef struct _YKS_OscItem
{
	/// <summary>
	/// FALSE=未启用 TRUE=启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 采集类型
	/// </summary>
	YKE_OSC_ITEM_TYPE type;

	/// <summary>
	/// 轴配置
	/// </summary>
	YKS_OscItemAxis axis;

	/// <summary>
	/// 坐标系配置
	/// </summary>
	YKS_OscItemGroup group;

	/// <summary>
	/// 对象字典配置
	/// </summary>
	YKS_OscItemSlaveObject coe_obj;

	/// <summary>
	/// UG配置
	/// </summary>
	YKS_OscItemSlaveUG ug;

	/// <summary>
	/// 数字输入配置
	/// </summary>
	YKS_OscItemDI digital_input;

	/// <summary>
	/// 数字输出配置
	/// </summary>
	YKS_OscItemDO digital_output;

	/// <summary>
	/// 通用数据寄存器
	/// </summary>
	YKS_OscItemReg gen_data_reg;

	/// <summary>
	/// 系统信息
	/// </summary>
	YKS_OscItemSystem sys_info;

	/// <summary>
	/// 编码器
	/// </summary>
	YKS_OscItemEncoder encoder;

	/// <summary>
	/// 事件
	/// </summary>
	YKS_OscItemEvent sys_event;

	/// <summary>
	/// 多轴联动
	/// </summary>
	YKS_OscItemMultiAxis multi_axis;

	/// <summary>
	/// 等待事件
	/// </summary>
	YKS_OscItemWait wait;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[24];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[24];
}YKS_OscItem;

/// <summary>
/// 打印日志其他配置
/// </summary>
typedef struct _YKS_LoggerItemConfig
{
	/// <summary>
	/// 单轴 TRUE=启用 FALSE=禁用
	/// </summary>
	YKE_BOOL axis_enable;

	/// <summary>
	/// 单轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 坐标系 TRUE=启用 FALSE=禁用
	/// </summary>
	YKE_BOOL group_enable;

	/// <summary>
	/// 坐标系序号[0,YKE_GROUP_NUM)
	/// </summary>
	UINT32 group_index;

	/// <summary>
	/// 硬件卡通道 TRUE=启用 FALSE=禁用
	/// </summary>
	YKE_BOOL card_enable;

	/// <summary>
	/// 硬件卡通道序号
	/// </summary>
	UINT32 card_index;

	/// <summary>
	/// ethercat从站 TRUE=启用 FALSE=禁用
	/// </summary>
	YKE_BOOL bus_enable;

	/// <summary>
	/// ethercat从站序号
	/// </summary>
	UINT32 slave_index;

	/// <summary>
	/// 事件 TRUE=启用 FALSE=禁用
	/// </summary>
	YKE_BOOL event_enable;

	/// <summary>
	/// 事件序号[0,YKE_EVENT_NUM)
	/// </summary>
	UINT32 event_index;

	/// <summary>
	/// 多轴联动  TRUE=启用 FALSE=禁用
	/// </summary>
	YKE_BOOL multi_axis_enable;

	/// <summary>
	/// 多轴联动通道号[0,YKE_MULTI_AXIS_NUM)
	/// </summary>
	UINT32 multi_axis_index;

	/// <summary>
	/// 等待功能  TRUE=启用 FALSE=禁用
	/// </summary>
	YKE_BOOL wait_enable;

	/// <summary>
	/// 等待通道号[0,YKE_WAIT_NUM)
	/// </summary>
	UINT32 wait_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res2[8];
}YKS_LoggerItemConfig;

/// <summary>
/// 日志配置
/// </summary>
typedef struct _YKS_LoggerConfig
{
	/// <summary>
	/// 文件路径
	/// </summary>
	char file_path[512];

	/// <summary>
	/// 文件名,不带扩展名
	/// 间隔指定时间生成新的文件
	/// </summary>
	char file_name[64];

	/// <summary>
	/// 生成新文件的间隔时间[0,DOUBLE_MAX](h)
	/// </summary>
	double interval;

	/// <summary>
	/// 数字输出指令 FALSE=不采集 TRUE=采集
	/// </summary>
	YKE_BOOL do_output;

	/// <summary>
	/// 用户数据 FALSE=不采集 TRUE=采集
	/// </summary>
	YKE_BOOL user_data;

	/// <summary>
	/// 返回值错误的指令 FALSE=不采集 TRUE=采集
	/// </summary>
	YKE_BOOL ret_ng;

	/// <summary>
	/// 返回值正常的指令 FALSE=不采集 TRUE=采集
	/// </summary>
	YKE_BOOL ret_ok;

	/// <summary>
	/// 为0的参数 FALSE=不采集 TRUE=采集
	/// </summary>
	YKE_BOOL zero_value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[10];

	/// <summary>
	/// 采集过滤类型
	/// </summary>
	YKE_LOGGER_FILTER_TYPE filter_type;

	/// <summary>
	/// 采集配置
	/// </summary>
	YKS_LoggerItemConfig item_config_0;
	YKS_LoggerItemConfig item_config_1;
	YKS_LoggerItemConfig item_config_2;
	YKS_LoggerItemConfig item_config_3;
	YKS_LoggerItemConfig item_config_4;
	YKS_LoggerItemConfig item_config_5;
	YKS_LoggerItemConfig item_config_6;
	YKS_LoggerItemConfig item_config_7;
	YKS_LoggerItemConfig item_config_8;
	YKS_LoggerItemConfig item_config_9;
	YKS_LoggerItemConfig item_config_10;
	YKS_LoggerItemConfig item_config_11;
	YKS_LoggerItemConfig item_config_12;
	YKS_LoggerItemConfig item_config_13;
	YKS_LoggerItemConfig item_config_14;
	YKS_LoggerItemConfig item_config_15;
	YKS_LoggerItemConfig item_config_16;
	YKS_LoggerItemConfig item_config_17;
	YKS_LoggerItemConfig item_config_18;
	YKS_LoggerItemConfig item_config_19;
	YKS_LoggerItemConfig item_config_20;
	YKS_LoggerItemConfig item_config_21;
	YKS_LoggerItemConfig item_config_22;
	YKS_LoggerItemConfig item_config_23;
	YKS_LoggerItemConfig item_config_24;
	YKS_LoggerItemConfig item_config_25;
	YKS_LoggerItemConfig item_config_26;
	YKS_LoggerItemConfig item_config_27;
	YKS_LoggerItemConfig item_config_28;
	YKS_LoggerItemConfig item_config_29;
	YKS_LoggerItemConfig item_config_30;
	YKS_LoggerItemConfig item_config_31;
}YKS_LoggerConfig;

/// <summary>
/// 保留
/// </summary>
typedef struct _YKS_ExcTrackItem
{
	/// <summary>
	/// 保留
	/// </summary>
	UINT32 type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 file;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 line;

	/// <summary>
	/// 保留
	/// </summary>
	INT32 value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 tick;
}YKS_ExcTrackItem;

/// <summary>
/// 保留
/// </summary>
typedef struct _YKS_ExcTrackConfig
{
	/// <summary>
	/// 缓存数量
	/// </summary>
	UINT32 item_number;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	YKS_LoggerItemConfig item_config_0;
	YKS_LoggerItemConfig item_config_1;
	YKS_LoggerItemConfig item_config_2;
	YKS_LoggerItemConfig item_config_3;
	YKS_LoggerItemConfig item_config_4;
	YKS_LoggerItemConfig item_config_5;
	YKS_LoggerItemConfig item_config_6;
	YKS_LoggerItemConfig item_config_7;
	YKS_LoggerItemConfig item_config_8;
	YKS_LoggerItemConfig item_config_9;
	YKS_LoggerItemConfig item_config_10;
	YKS_LoggerItemConfig item_config_11;
	YKS_LoggerItemConfig item_config_12;
	YKS_LoggerItemConfig item_config_13;
	YKS_LoggerItemConfig item_config_14;
	YKS_LoggerItemConfig item_config_15;
}YKS_ExcTrackConfig;

/// <summary>
/// 软模式位置比较器配置
/// </summary>
typedef struct _YKS_CompareConfigSoft
{
	/// <summary>
	/// 比较模式
	/// </summary>
	YKE_COMPARE_MODE mode;

	/// <summary>
	/// 启用二维模式,未实现
	/// </summary>
	YKE_BOOL enable_2d;

	/// <summary>
	/// 比较源
	/// </summary>
	YKS_OscItem source;

	/// <summary>
	/// 比较数量:线性模式用[0,511] 0=无限多
	/// </summary>
	UINT32 number;

	/// <summary>
	/// 未使用
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 输出0的值 FALSE=关 TRUE=开
	/// </summary>
	YKE_BOOL out0_enable;

	/// <summary>
	/// 输出0字节序号[0,512)
	/// </summary>
	UINT32 out0_byte;

	/// <summary>
	/// 输出0位偏移[0,7)
	/// </summary>
	UINT32 out0_offset;

	/// <summary>
	/// 输出1的值 FALSE=关 TRUE=开
	/// </summary>
	YKE_BOOL out1_enable;

	/// <summary>
	/// 输出1字节序号[0,512)
	/// </summary>
	UINT32 out1_byte;

	/// <summary>
	/// 输出1位偏移[0,7)
	/// </summary>
	UINT32 out1_offset;

	/// <summary>
	/// 输出2的值 FALSE=关 TRUE=开
	/// </summary>
	YKE_BOOL out2_enable;

	/// <summary>
	/// 输出2字节序号[0,512)
	/// </summary>
	UINT32 out2_byte;

	/// <summary>
	/// 输出2位偏移[0,7)
	/// </summary>
	UINT32 out2_offset;

	/// <summary>
	/// 输出3的值 FALSE=关 TRUE=开
	/// </summary>
	YKE_BOOL out3_enable;

	/// <summary>
	/// 输出3字节序号[0,512)
	/// </summary>
	UINT32 out3_byte;

	/// <summary>
	/// 输出3位偏移[0,7)
	/// </summary>
	UINT32 out3_offset;

	/// <summary>
	/// X方向间距,线性模式用[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double spacing1;

	/// <summary>
	/// Y方向间距,线性模式用 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double spacing2;

	/// <summary>
	/// 比较值门限, 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double threshold;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CompareConfigSoft;

/// <summary>
/// 本地PCI高速卡位置比较器比较数据
/// </summary>
typedef struct _YKS_CompareItemData
{
	/// <summary>
	/// 比较值1[INT32_MIN,INT_MAX](pulse)
	/// </summary>
	INT32 value1;

	/// <summary>
	/// 比较值2, 二维模式有效[INT32_MIN,INT_MAX](pulse)
	/// </summary>
	INT32 value2;

	/// <summary>
	/// 比较值门限(脉冲距离), 二维模式有效[INT32_MIN,INT_MAX](pulse)
	/// </summary>
	UINT32 threshold;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 输出值0, Xmen无效 Tseries有效
	/// FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out_bit0;

	/// <summary>
	/// 输出值1, Xmen无效 Tseries有效
	/// FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out_bit1;

	/// <summary>
	/// 输出值2, Xmen无效 Tseries有效
	/// FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out_bit2;

	/// <summary>
	/// 输出值3, Xmen无效 Tseries有效
	/// FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out_bit3;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CompareItemData;

/// <summary>
/// 软件模式位置比较器比较数据
/// </summary>
typedef struct _YKS_CompareItemDataSoft
{
	/// <summary>
	/// 比较值1[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double cmp_value1;

	/// <summary>
	/// 比较值2, 二维模式有效[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double cmp_value2;

	/// <summary>
	/// 输出值0 FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out0_value;

	/// <summary>
	/// 输出值1 FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out1_value;

	/// <summary>
	/// 输出值2 FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out2_value;

	/// <summary>
	/// 输出值3 FALSE=OFF TRUE=ON
	/// </summary>
	YKE_BOOL out3_value;

	/// <summary>
	/// 输出0保持时间[0,DOUBLE_MAX](ms)  0:一直保持
	/// </summary>
	double out0_time;

	/// <summary>
	/// 输出1保持时间[0,DOUBLE_MAX](ms)  0:一直保持
	/// </summary>
	double out1_time;

	/// <summary>
	/// 输出2保持时间[0,DOUBLE_MAX](ms)  0:一直保持
	/// </summary>
	double out2_time;

	/// <summary>
	/// 输出3保持时间[0,DOUBLE_MAX](ms)  0:一直保持
	/// </summary>
	double out3_time;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CompareItemDataSoft;

/// <summary>
/// 本地PCI高速卡位置比较器状态
/// </summary>
typedef struct _YKS_CompareStatus
{
	/// <summary>
	/// 数据队列头位置
	/// </summary>
	UINT32 que_head;

	/// <summary>
	/// 数据队列尾位置
	/// </summary>
	UINT32 que_tail;

	/// <summary>
	/// 硬件缓冲区空闲数量
	/// </summary>
	UINT32 hd_idel;

	/// <summary>
	/// 硬件缓冲区待比较数量
	/// </summary>
	UINT32 hd_active;

	/// <summary>
	/// 已经完成的比较数量
	/// </summary>
	UINT32 hd_finish;

	/// <summary>
	/// 软件缓冲区空闲数量 线性模式无效
	/// </summary>
	UINT32 soft_idel;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CompareStatus;

/// <summary>
/// 软件模式位置比较器状态
/// </summary>
typedef struct _YKS_CompareStatusSoft
{
	/// <summary>
	/// 数据队列头位置
	/// </summary>
	UINT32 que_head;

	/// <summary>
	/// 数据队列尾位置
	/// </summary>
	UINT32 que_tail;

	/// <summary>
	/// 全部比较完成 FALSE=未完成  TRUE=已完成
	/// </summary>
	YKE_BOOL finish;

	/// <summary>
	/// 比较成功的次数
	/// </summary>
	UINT32 success;

	/// <summary>
	/// 错误次数
	/// </summary>
	UINT32 error_count;

	/// <summary>
	/// FALSE=空闲  TRUE=运行中
	/// </summary>
	YKE_BOOL active;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CompareStatusSoft;

/// <summary>
/// 本地PCI高速卡位置锁存配置
/// </summary>
typedef struct _YKS_CaptureConfig
{
	/// <summary>
	/// 锁存源选择
	/// </summary>
	YKE_CAPTURE_SOURCE source_type;

	/// <summary>
	/// 沿选择 FALSE=上升沿 TRUE=下降沿
	/// </summary>
	YKE_BOOL edge;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_CaptureConfig;

/// <summary>
/// 本地PCI高速卡PWM输出配置
/// </summary>
typedef struct _YKS_PwmConfig
{
	/// <summary>
	/// 脉冲频率(Hz)
	/// </summary>
	double freq;

	/// <summary>
	/// 占空比, 0~1
	/// </summary>
	double duty;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_PwmConfig;

/// <summary>
/// 坐标系内数字输出配置
/// </summary>
typedef struct _YKS_GroupDoConfig
{
	/// <summary>
	/// 位置比较模式
	/// </summary>
	YKE_GROUP_COMPARE_MODE cmp_mode;

	/// <summary>
	/// 输出模式
	/// </summary>
	YKE_GROUP_DO_MODE out_mode;

	/// <summary>
	/// 数字输出字节序号[0,512)
	/// </summary>
	UINT32 byte_index;

	/// <summary>
	/// 数字输出位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// 输出值 FALSE=关 TRUE=开
	/// </summary>
	YKE_BOOL value;

	/// <summary>
	/// 参考线段数量
	/// </summary>
	UINT32 span;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 规划位置或实际位置选择
	/// </summary>
	YKE_AXIS_COMPARE_TYPE cmp_src;

	/// <summary>
	/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
	/// </summary>
	double time_dist_rate;

	/// <summary>
	/// 单脉冲输出单位 FALSE=距离(unit) TRUE=时间(ms)
	/// </summary>
	YKE_BOOL single_unit;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res2;

	/// <summary>
	/// 单脉冲模式下的持续距离(unit)或时间(ms)[0,DOUBLE_MAX]
	/// </summary>
	double single_time_dist;

	/// <summary>
	/// 交替输出模式下的打开次数 0=无限次数
	/// </summary>
	UINT32 number;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 交替输出模式下输出为ON状态的距离(unit)或时间(ms)
	/// </summary>
	double time_dist_on;

	/// <summary>
	/// 交替输出模式下输出为OFF的距离(unit)或时间(ms)
	/// </summary>
	double time_dist_off;

	/// <summary>
	/// 交替输出的单位 FALSE=距离(unit) TRUE=时间(ms)
	/// </summary>
	YKE_BOOL alter_unit;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res3[8];
}YKS_GroupDoConfig;

/// <summary>
/// 坐标系内PWM输出配置
/// </summary>
typedef struct _YKS_GroupPwmConfig
{
	/// <summary>
	/// 位置比较模式
	/// </summary>
	YKE_GROUP_COMPARE_MODE cmp_mode;

	/// <summary>
	/// 规划位置或实际位置选择
	/// </summary>
	YKE_AXIS_COMPARE_TYPE cmp_src;

	/// <summary>
	/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
	/// </summary>
	double time_dist_rate;

	/// <summary>
	/// 参考线段数量
	/// </summary>
	UINT32 span;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 跟随模式
	/// </summary>
	YKE_GROUP_PWM_MODE pwm_mode;

	/// <summary>
	/// 卡序号,固定为0
	/// </summary>
	UINT32 card_index;

	/// <summary>
	/// 脉冲序号
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 输出值 FLASE=关 TRUE=开
	/// </summary>
	YKE_BOOL value;

	/// <summary>
	/// 速度滤波时间(ms)
	/// </summary>
	double filter_tim;

	/// <summary>
	/// 频率(Hz)
	/// </summary>
	double freq_value;

	/// <summary>
	/// 占空比
	/// </summary>
	double duty_value;

	/// <summary>
	/// 跟随模式下频率和速度的比例
	/// </summary>
	double freq_scale;

	/// <summary>
	/// 跟随模式下占空比和速度的比例
	/// </summary>
	double duty_scale;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupPwmConfig;

/// <summary>
/// 坐标系内PDO写入配置
/// </summary>
typedef struct _YKS_GroupWritePdoConfig
{
	/// <summary>
	/// 比较模式
	/// </summary>
	YKE_GROUP_COMPARE_MODE cmp_mode;

	/// <summary>
	/// 规划位置或实际位置选择
	/// </summary>
	YKE_AXIS_COMPARE_TYPE cmp_src;

	/// <summary>
	/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
	/// </summary>
	double time_dist_rate;

	/// <summary>
	/// 参考线段数量
	/// </summary>
	UINT32 span;

	/// <summary>
	/// 识别码
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 主站选择
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 从站序号
	/// </summary>
	UINT32 slave_index;

	/// <summary>
	/// 主索引
	/// </summary>
	UINT32 main_index;

	/// <summary>
	/// 子索引
	/// </summary>
	UINT32 sub_index;

	/// <summary>
	/// 数据类型
	/// </summary>
	YKE_DATA_TYPE data_type;

	/// <summary>
	/// 写入值
	/// </summary>
	UINT32 value;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupWritePdoConfig;

/// <summary>
/// 坐标系内寄存器写入配置
/// </summary>
typedef struct _YKS_GroupWriteRegisterConfig
{
	/// <summary>
	/// 比较模式
	/// </summary>
	YKE_GROUP_COMPARE_MODE cmp_mode;

	/// <summary>
	/// 规划位置或实际位置选择
	/// </summary>
	YKE_AXIS_COMPARE_TYPE cmp_src;

	/// <summary>
	/// 寄存器序号[0,YKE_GENDATA_SIZE)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
	/// </summary>
	double time_dist_rate;

	/// <summary>
	/// 参考线段数量
	/// </summary>
	UINT32 span;

	/// <summary>
	/// 识别码
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 数据类型
	/// </summary>
	YKE_DATA_TYPE data_type;

	/// <summary>
	/// 写入值
	/// </summary>
	UINT32 value;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupWriteRegisterConfig;

/// <summary>
/// 坐标系内启动事件配置
/// </summary>
typedef struct _YKS_GroupWriteEventConfig
{
	/// <summary>
	/// 比较模式
	/// </summary>
	YKE_GROUP_COMPARE_MODE cmp_mode;

	/// <summary>
	/// 规划位置或实际位置选择
	/// </summary>
	YKE_AXIS_COMPARE_TYPE cmp_src;

	/// <summary>
	/// 时间(ms)或者距离(unit)或者比率 与输出模式相关
	/// </summary>
	double time_dist_rate;

	/// <summary>
	/// 参考线段数量
	/// </summary>
	UINT32 span;

	/// <summary>
	/// 识别码
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 事件序号[0,YKE_EVENT_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupWriteEventConfig;

/// <summary>
/// 坐标系外轴绝对运动配置
/// </summary>
typedef struct _YKS_GroupMoveAbsoluteConfig
{
	/// <summary>
	/// 位置比较模式
	/// </summary>
	YKE_GROUP_COMPARE_MODE cmp_mode;

	/// <summary>
	/// 规划位置或实际位置选择
	/// </summary>
	YKE_AXIS_COMPARE_TYPE cmp_src;

	/// <summary>
	/// 时间(毫秒单位)或者距离(用户单位)或者比率 与输出模式相关
	/// </summary>
	double time_dist_rate;

	/// <summary>
	/// 参考线段数量
	/// </summary>
	UINT32 span;

	/// <summary>
	/// 识别码
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 轴序号
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 运动配置
	/// </summary>
	YKS_MoveAbsoluteConfig movabs;

	/// <summary>
	/// 保留
	/// </summary>
	double res1[8];
}YKS_GroupMoveAbsoluteConfig;

/// <summary>
/// 坐标系外轴相对运动配置
/// </summary>
typedef struct _YKS_GroupMoveRelativeConfig
{
	/// <summary>
	/// 位置比较模式
	/// </summary>
	YKE_GROUP_COMPARE_MODE cmp_mode;

	/// <summary>
	/// 规划位置或实际位置选择
	/// </summary>
	YKE_AXIS_COMPARE_TYPE cmp_src;

	/// <summary>
	/// 时间(毫秒单位)或者距离(用户单位)或者比率 与输出模式相关
	/// </summary>
	double time_dist_rate;

	/// <summary>
	/// 参考线段数量
	/// </summary>
	UINT32 span;

	/// <summary>
	/// 识别码
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 轴序号
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 运动配置
	/// </summary>
	YKS_MoveRelativeConfig movinc;

	/// <summary>
	/// 保留
	/// </summary>
	double res1[8];
}YKS_GroupMoveRelativeConfig;

/// <summary>
/// 坐标系内延时配置
/// </summary>
typedef struct _YKS_GroupDelayConfig
{
	/// <summary>
	/// 延时时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double delay_ms;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupDelayConfig;

/// <summary>
/// 坐标系内等待数字输入配置
/// </summary>
typedef struct _YKS_GroupDigitalInputConfig
{
	/// <summary>
	/// 数字输入字节序号[0,512)
	/// </summary>
	UINT32 byte_index;

	/// <summary>
	/// 数字输入位偏移[0,7)
	/// </summary>
	UINT32 bit_offset;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// 标记[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupDigitalInputConfig;

/// <summary>
/// 坐标系内等待外轴运动完成
/// </summary>
typedef struct _YKS_GroupWaitAxisConfig
{
	/// <summary>
	/// 轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 等待信号
	/// </summary>
	YKE_AXIS_ITEM_TYPE item_type;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 触发值
	/// </summary>
	double trig_value;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupWaitAxisConfig;

/// <summary>
/// 坐标系内等待PDO值
/// </summary>
typedef struct _YKS_GroupWaitPdoConfig
{
	/// <summary>
	/// 主站选择
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 从站序号
	/// </summary>
	UINT32 slave_index;

	/// <summary>
	/// 主索引
	/// </summary>
	UINT32 main_index;

	/// <summary>
	/// 子索引
	/// </summary>
	UINT32 sub_index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// 数据类型
	/// </summary>
	YKE_DATA_TYPE data_type;

	/// <summary>
	/// 等待值
	/// </summary>
	UINT32 value;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupWaitPdoConfig;

/// <summary>
/// 坐标系内等待寄存器值
/// </summary>
typedef struct _YKS_GroupWaitRegisterConfig
{
	/// <summary>
	/// 寄存器序号[0,YKE_GENDATA_SIZE)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// 数据类型
	/// </summary>
	YKE_DATA_TYPE data_type;

	/// <summary>
	/// 等待值
	/// </summary>
	UINT32 value;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupWaitRegisterConfig;

/// <summary>
/// 坐标系内等待事件
/// </summary>
typedef struct _YKS_GroupWaitEventConfig
{
	/// <summary>
	/// 事件通道号[0,YKE_EVENT_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 等待信号
	/// </summary>
	YKE_EVENT_WAIT_TYPE type;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_GroupWaitEventConfig;

/// <summary>
/// Cardinal样条配置
/// </summary>
typedef struct _YKS_GroupCardinalConfig
{
	/// <summary>
	/// 张力系数(0,1)
	/// </summary>
	double tensive;

	/// <summary>
	/// 识别码[0,UINT32_MAX]
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_GroupCardinalConfig;

/// <summary>
/// 示波器监控数据配置
/// </summary>
typedef struct _YKS_OscConfig
{
	/// <summary>
	/// 采集点数(0,80000]
	/// </summary>
	UINT32 depth;

	/// <summary>
	/// 采样周期间隔(0,UINT32_MAX],以采样单位为基准
	/// </summary>
	UINT32 interval;

	/// <summary>
	/// 采样单位 FALSE=运动周期 TRUE=PLC周期
	/// </summary>
	YKE_BOOL unit;

	/// <summary>
	/// 触发通道[0,YKE_OSC_ITEM_NUM)
	/// </summary>
	UINT32 trig_ch;

	/// <summary>
	/// 触发阀值[DOUBLE_MIN,DOUBLE_MAX]
	/// </summary>
	double trig_val;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_OSC_TRIG_TYPE trig_mode;

	/// <summary>
	/// 触发位置[0,100]
	/// </summary>
	UINT32 trig_pos;

	/// <summary>
	/// 触发次数 FALSE=单次触发 TRUE=重复触发
	/// </summary>
	YKE_BOOL trig_once;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_OscConfig;

/// <summary>
/// 示波器采集状态
/// </summary>
typedef struct _YKS_OscStatus
{
	/// <summary>
	/// 触发状态 FALSE=未触发 TRUE=已经触发
	/// </summary>
	YKE_BOOL trig_flag;

	/// <summary>
	/// 触发位置
	/// </summary>
	UINT32 trig_index;

	/// <summary>
	/// 触发后的剩余采集次数
	/// </summary>
	UINT32 remain;

	/// <summary>
	/// 触发后数据采集状态 FALSE=未完成 TRUE=已完成
	/// </summary>
	YKE_BOOL finish;

	/// <summary>
	/// 采集环形缓冲区大小(double)
	/// </summary>
	UINT32 buff_size;

	/// <summary>
	/// 缓冲区有效数据数量(double)
	/// </summary>
	UINT32 buff_valid;

	/// <summary>
	/// FALSE=数据未溢出 TRUE=数据有溢出
	/// </summary>
	YKE_BOOL over_flow;

	/// <summary>
	/// 示波器内轴通道报警状态
	/// 按位定义 0=无报警 1=有报警
	/// </summary>
	YKE_BOOL axis_warn;

	/// <summary>
	/// 采集主站的总线周期(ms)
	/// </summary>
	double master_period;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_OscStatus;

/// <summary>
/// 数字IO关联的硬件信息
/// </summary>
typedef struct _YKS_DigitalIOHardInfo
{
	/// <summary>
	/// TRUE=有效序号 FALSE=不存在的序号
	/// </summary>
	YKE_BOOL valid;

	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// IO类型
	/// </summary>
	YKE_DIO_PHY type;

	/// <summary>
	/// 总线站号
	/// </summary>
	UINT32 index1;

	/// <summary>
	/// 网关内序号
	/// </summary>
	UINT32 index2;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_DigitalIOHardInfo;

/// <summary>
/// 软限位设置
/// </summary>
typedef struct _YKS_AxisSoftLimitConfig
{
	/// <summary>
	/// 正软限位位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double positive;

	/// <summary>
	/// 负软限位位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double negative;

	/// <summary>
	/// FALSE=禁用 TRUE=启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisSoftLimitConfig;

/// <summary>
/// 硬限位启用
/// </summary>
typedef struct _YKS_AxisHardLimitConfig
{
	/// <summary>
	/// 正向硬限位
	/// FALSE=禁用 TRUE=启用
	/// </summary>
	YKE_BOOL enable_positive;

	/// <summary>
	/// 负向硬限位
	/// FALSE=禁用 TRUE=启用
	/// </summary>
	YKE_BOOL enable_negative;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];
}YKS_AxisHardLimitConfig;

/// <summary>
/// 多轴直线插补运动,相对模式
/// </summary>
typedef struct _YKS_LinearInterpolationRelativeConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴序号列表[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double distance[32];

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 延时指定时间后(相对启动时刻)启动变参数 [0,DOUBLE_MAX](ms) 保留
	/// </summary>
	double change_tim;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_LinearInterpolationRelativeConfig;

/// <summary>
/// 多轴直线插补运动,绝对模式
/// </summary>
typedef struct _YKS_LinearInterpolationAbsoluteConfig
{
	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴序号列表[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position[32];

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 延时指定时间后(相对启动时刻)启动变参数
	/// </summary>
	double change_tim;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_LinearInterpolationAbsoluteConfig;

/// <summary>
/// 多轴直线同步运动,相对模式
/// </summary>
typedef struct _YKS_LinearSyncRelativeConfig
{
	/// <summary>
	/// 同步模式
	/// </summary>
	YKE_SYNC_AXIS_MODE sync_mode;

	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴序号列表[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double distance[32];

	/// <summary>
	/// 延时指定时间后(相对启动时刻)启动变参数
	/// </summary>
	double change_tim;

	/// <summary>
	/// 指定运行时间 YKE_SYNC_FIX_TIME使用
	/// </summary>
	double run_time;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_LinearSyncRelativeConfig;

/// <summary>
/// 多轴直线同步运动,绝对模式
/// </summary>
typedef struct _YKS_LinearSyncAbsoluteConfig
{
	/// <summary>
	/// 同步模式
	/// </summary>
	YKE_SYNC_AXIS_MODE sync_mode;

	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴序号列表[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position[32];

	/// <summary>
	/// 延时指定时间后(相对启动时刻)启动变参数
	/// </summary>
	double change_tim;

	/// <summary>
	/// 指定运行时间(ms) YKE_SYNC_FIX_TIME模式使用
	/// </summary>
	double run_time;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_LinearSyncAbsoluteConfig;

/// <summary>
/// 多轴同时启动
/// </summary>
typedef struct _YKS_SyncStartConfig
{
	/// <summary>
	/// 同步模式
	/// </summary>
	YKE_SYNC_AXIS_MODE sync_mode;

	/// <summary>
	/// 轴数量[2,YKE_MULTI_AXIS_NUM]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 轴序号列表[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 目标位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position[32];

	/// <summary>
	/// 延时指定时间后(相对启动时刻)启动变参数
	/// </summary>
	double change_tim;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_SyncStartConfig;

/// <summary>
/// 圆弧插补,相对模式
/// </summary>
typedef struct _YKS_CircularInterpolationRelativeConfig
{
	/// <summary>
	/// 轴数量[2,3]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴序号列表[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 相对距离[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 distance;

	/// <summary>
	/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 aux_point;

	/// <summary>
	/// 方向选择
	/// </summary>
	YKE_CIRCULAR_PATH_CHOICE path_choice;

	/// <summary>
	/// 辅助点模式
	/// </summary>
	YKE_CIRCULAR_AUX_MODE aux_mode;

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_CircularInterpolationRelativeConfig;

/// <summary>
/// 圆弧插补,绝对模式
/// </summary>
typedef struct _YKS_CircularInterpolationAbsoluteConfig
{
	/// <summary>
	/// 轴数量[2,3]
	/// </summary>
	UINT32 axis_num;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 轴序号列表[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_list[32];

	/// <summary>
	/// 终点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 end_point;

	/// <summary>
	/// 辅助点[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	YKS_POINT3 aux_point;

	/// <summary>
	/// 方向选择
	/// </summary>
	YKE_CIRCULAR_PATH_CHOICE path_choice;

	/// <summary>
	/// 辅助点模式
	/// </summary>
	YKE_CIRCULAR_AUX_MODE aux_mode;

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 保留
	/// </summary>
	double res[4];
}YKS_CircularInterpolationAbsoluteConfig;

/// <summary>
/// 探针配置
/// </summary>
typedef struct _YKS_ProbeConfigSoft
{
	/// <summary>
	/// 数字输入
	/// </summary>
	YKS_DigitalIO input;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 捕获对象
	/// </summary>
	YKS_OscItem item;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_ProbeConfigSoft;

/// <summary>
/// 探针状态
/// </summary>
typedef struct _YKS_ProbeStatusSoft
{
	/// <summary>
	/// 激活状态 FALSE=未激活  TRUE=已激活
	/// </summary>
	YKE_BOOL active;

	/// <summary>
	/// 探针值状态 FALSE=无效  TRUE=有效
	/// </summary>
	YKE_BOOL valid;

	/// <summary>
	/// 探针值
	/// </summary>
	double value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[4];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[4];
}YKS_ProbeStatusSoft;

/// <summary>
/// 触发配置
/// </summary>
typedef struct _YKS_AxisTrigger
{
	/// <summary>
	/// 触发条件参考的轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 触发类型
	/// </summary>
	YKE_TRIGGER_TYPE type;

	/// <summary>
	/// 触发值
	/// </summary>
	double value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_AxisTrigger;

/// <summary>
/// 轴触发状态
/// </summary>
typedef struct _YKS_AxisTriggerStatus
{
	/// <summary>
	/// FALSE=空闲 TRUE=等待触发
	/// </summary>
	YKE_BOOL active;

	/// <summary>
	/// 触发参考轴[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 触发类型
	/// </summary>
	YKE_TRIGGER_TYPE type;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 触发值
	/// </summary>
	double value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res2[8];
}YKS_AxisTriggerStatus;

/// <summary>
/// 单信号触发参数
/// </summary>
typedef struct _YKS_TriggerArgOneSignal
{
	/// <summary>
	/// 信号源选择
	/// </summary>
	YKE_SIGNAL_SOURCE_TYPE type;

	/// <summary>
	/// 事件或寄存器序号 YKE_SIGNAL_SOURCE_EVENT/YKE_SIGNAL_SOURCE_REG使用
	/// </summary>
	UINT32 index;

	/// <summary>
	/// IO序号 YKE_SIGNAL_SOURCE_INPUT/YKE_SIGNAL_SOURCE_OUTPUT使用
	/// </summary>
	YKS_DigitalIO inout;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgOneSignal;

/// <summary>
/// 双信号触发参数
/// </summary>
typedef struct _YKS_TriggerArgTwoSignal
{
	/// <summary>
	/// 号源1
	/// </summary>
	YKE_SIGNAL_SOURCE_TYPE type1;

	/// <summary>
	/// 信号源2
	/// </summary>
	YKE_SIGNAL_SOURCE_TYPE type2;

	/// <summary>
	/// IO1序号
	/// </summary>
	YKS_DigitalIO inout1;

	/// <summary>
	/// IO1序号
	/// </summary>
	YKS_DigitalIO inout2;

	/// <summary>
	/// 事件1或寄存器1序号
	/// </summary>
	UINT32 index1;

	/// <summary>
	/// 事件2或寄存器2序号
	/// </summary>
	UINT32 index2;

	/// <summary>
	/// 运算逻辑
	/// </summary>
	YKE_LOGIC_CONDITIONS op_logic;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgTwoSignal;

/// <summary>
/// 轴位置条件触发
/// </summary>
typedef struct _YKS_TriggerArgAxisPosition
{
	/// <summary>
	/// 轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// TRUE=当指定轴静止或正向运动时不会触发输出
	/// </summary>
	YKE_BOOL disable_positive_direction;

	/// <summary>
	/// TRUE=当指定轴静止或负向运动时不会触发输出
	/// </summary>
	YKE_BOOL disable_negative_direction;

	/// <summary>
	/// FALSE=监控规划位置 TRUE=监控实际位置
	/// </summary>
	YKE_BOOL use_feedback;

	/// <summary>
	/// TRUE=此输入功能逻辑取反 FALSE=不取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 触发时的位置
	/// </summary>
	double position;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgAxisPosition;

/// <summary>
/// 轴时间条件触发
/// </summary>
typedef struct _YKS_TriggerArgAxisTime
{
	/// <summary>
	/// 轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// FALSE=使用已运行时间 TRUE=使用剩余时间
	/// </summary>
	YKE_BOOL use_remain;

	/// <summary>
	/// TRUE=此输入功能逻辑取反 FALSE=不取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 参考时间
	/// </summary>
	double time;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgAxisTime;

/// <summary>
/// 轴速度条件触发
/// </summary>
typedef struct _YKS_TriggerArgAxisVelocity
{
	/// <summary>
	/// 轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// FALSE=监控规划速度 TRUE=监控实际速度
	/// </summary>
	YKE_BOOL use_feedback;

	/// <summary>
	/// TRUE=此输入功能逻辑取反 FALSE=不取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 触发时的速度(0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgAxisVelocity;

/// <summary>
/// 轴转矩条件触发
/// </summary>
typedef struct _YKS_TriggerArgAxisTorque
{
	/// <summary>
	/// 轴序号
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// FALSE=监控规划转矩 TRUE=监控实际转矩
	/// </summary>
	YKE_BOOL use_feedback;

	/// <summary>
	/// TRUE=此输入功能逻辑取反 FALSE=不取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 触发时的转矩(0.1%单位)
	/// </summary>
	double torque;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgAxisTorque;

/// <summary>
/// 从站PDO触发条件
/// </summary>
typedef struct _YKS_TriggerArgSlavePDO
{
	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 从站站号
	/// </summary>
	UINT32 slave_index;

	/// <summary>
	/// 对象字典主索引
	/// </summary>
	UINT32 main_index;

	/// <summary>
	/// 对象字典子索引
	/// </summary>
	UINT32 sub_index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// 数据类型
	/// </summary>
	YKE_DATA_TYPE data_type;

	/// <summary>
	/// TRUE=此输入功能逻辑取反 FALSE=不取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 触发值
	/// </summary>
	INT32 value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgSlavePDO;

/// <summary>
/// 编码器触发条件
/// </summary>
typedef struct _YKS_TriggerArgEncoder
{
	/// <summary>
	/// 通道号
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 触发模式
	/// </summary>
	YKE_TRIG_MODE trig_mode;

	/// <summary>
	/// TRUE=此输入功能逻辑取反 FALSE=不取反
	/// </summary>
	YKE_BOOL inv;

	/// <summary>
	/// 触发值
	/// </summary>
	INT32 value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerArgEncoder;

/// <summary>
/// 触发输出:位参数写入
/// </summary>
typedef struct _YKS_TriggerOutputOneBit
{
	/// <summary>
	/// 信号源
	/// </summary>
	YKE_SIGNAL_SOURCE_TYPE type;

	/// <summary>
	/// 事件或寄存器索引号
	/// YKE_SIGNAL_SOURCE_EVENT/YKE_SIGNAL_SOURCE_REG模式使用
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 数字输入输出选择
	/// YKE_SIGNAL_SOURCE_INPUT/YKE_SIGNAL_SOURCE_OUTPUT模式使用
	/// </summary>
	YKS_DigitalIO inout;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为低电平
	/// </summary>
	YKE_BOOL set_off_state;

	/// <summary>
	/// TRUE=启用延时翻转
	/// </summary>
	YKE_BOOL enable_reverse;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 延时时间
	/// </summary>
	double delay_ms;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputOneBit;

/// <summary>
/// 触发输出:轴停止
/// </summary>
typedef struct _YKS_TriggerOutputStopAxis
{
	/// <summary>
	/// 轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// 停止速度选择
	/// </summary>
	YKE_STOP_DEC stop_dec;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];
}YKS_TriggerOutputStopAxis;

/// <summary>
/// 触发输出:启动坐标系
/// </summary>
typedef struct _YKS_TriggerOutputStartGroup
{
	/// <summary>
	/// 坐标系序号[0,YKE_GROUP_NUM)
	/// </summary>
	UINT32 group_index;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputStartGroup;

/// <summary>
/// 触发输出:启动多轴联动
/// </summary>
typedef struct _YKS_TriggerOutputStartMultiAxis
{
	/// <summary>
	/// 多轴联动序号[0,YKE_MULTI_AXIS_NUM)
	/// </summary>
	UINT32 index;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputStartMultiAxis;

/// <summary>
/// 触发输出:启动轴
/// </summary>
typedef struct _YKS_TriggerOutputStartAxis
{
	/// <summary>
	/// 轴序号[0,YKE_AXIS_NUM)
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// 目标位置[DOUBLE_MIN,DOUBLEMAX](unit)
	/// </summary>
	double position;

	/// <summary>
	/// 运动参数
	/// </summary>
	YKS_AxisProfileMotion motion;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputStartAxis;

/// <summary>
/// 触发输出:触发软急停信号
/// </summary>
typedef struct _YKS_TriggerOutputSoftEmgStop
{
	/// <summary>
	/// 急停通道序号
	/// </summary>
	UINT32 channel;

	/// <summary>
	/// 单次触发 FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputSoftEmgStop;

/// <summary>
/// 触发输出:从站PDO写入
/// </summary>
typedef struct _YKS_TriggerOutputSlavePDO
{
	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 从站站号
	/// </summary>
	UINT32 slave_index;

	/// <summary>
	/// 对象字典主索引
	/// </summary>
	UINT32 main_index;

	/// <summary>
	/// 对象字典子索引
	/// </summary>
	UINT32 sub_index;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为低电平
	/// </summary>
	YKE_BOOL set_off_state;

	/// <summary>
	/// 数据类型
	/// </summary>
	YKE_DATA_TYPE data_type;

	/// <summary>
	/// 写入值
	/// </summary>
	UINT32 value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputSlavePDO;

/// <summary>
/// 触发输出:写入轴目标转矩
/// </summary>
typedef struct _YKS_TriggerOutputTargetTorque
{
	/// <summary>
	/// 轴序号
	/// </summary>
	UINT32 axis_index;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 转矩值
	/// </summary>
	double value;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为0
	/// </summary>
	YKE_BOOL set_off_state;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputTargetTorque;

/// <summary>
/// 触发输出:延时
/// </summary>
typedef struct _YKS_TriggerOutputDelayMs
{
	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 延时时间(ms)
	/// </summary>
	double value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputDelayMs;

/// <summary>
/// 触发输出:写数据寄存器
/// </summary>
typedef struct _YKS_TriggerOutputDataReg
{
	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// FALSE=多次触发 TRUE=单次触发
	/// </summary>
	YKE_BOOL single_shot;

	/// <summary>
	/// TRUE=当输入功能为FALSE时(即未触发事件时)输出位将设置为0
	/// </summary>
	YKE_BOOL set_off_state;

	/// <summary>
	/// 数据寄存器索引
	/// </summary>
	UINT32 index;

	/// <summary>
	/// 写入值
	/// </summary>
	UINT32 value;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_TriggerOutputDataReg;

/// <summary>
/// 事件状态
/// </summary>
typedef struct _YKS_EventStatus
{
	/// <summary>
	/// 主站
	/// </summary>
	YKE_NODE master;

	/// <summary>
	/// 事件状态
	/// </summary>
	YKE_EVENT_STATUS_TYTE status;

	/// <summary>
	/// 错误代码
	/// </summary>
	YKE_SYSTEM_ERROR error;

	/// <summary>
	/// 触发次数
	/// </summary>
	UINT32 triged;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res[8];
}YKS_EventStatus;

/// <summary>
/// PT数据
/// </summary>
typedef struct _YKS_PTData
{
	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position;

	/// <summary>
	/// 时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double tim;

	/// <summary>
	/// 加速度变化时间比[0,1]
	/// </summary>
	double acc_add_percent;
}YKS_PTData;

/// <summary>
/// PVT数据
/// </summary>
typedef struct _YKS_PVTData
{
	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position;

	/// <summary>
	/// 时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double tim;

	/// <summary>
	/// 速度[0,DOUBLE_MAX](unit/s)
	/// </summary>
	double velocity;
}YKS_PVTData;

/// <summary>
/// PVTS数据
/// </summary>
typedef struct _YKS_PVTSData
{
	/// <summary>
	/// 位置[DOUBLE_MIN,DOUBLE_MAX](unit)
	/// </summary>
	double position;

	/// <summary>
	/// 时间[0,DOUBLE_MAX](ms)
	/// </summary>
	double tim;

	/// <summary>
	/// 保留
	/// </summary>
	double res;
}YKS_PVTSData;

/// <summary>
/// PVT运动状态
/// </summary>
typedef struct _YKS_PVTStatus
{
	/// <summary>
	/// 缓冲区空闲数量[0,YKE_PVT_DEPTH]
	/// </summary>
	UINT32 idel;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[7];

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_PVTStatus;

/// <summary>
/// 看门狗状态
/// </summary>
typedef struct _YKS_WDTStatus
{
	/// <summary>
	/// 看门狗启用状态  FALSE=未启用 TRUE=已启用
	/// </summary>
	YKE_BOOL enable;

	/// <summary>
	/// 看门狗触发状态  FALSE=未触发 TRUE=已触发
	/// </summary>
	YKE_BOOL trigged;

	/// <summary>
	/// 超时时间
	/// </summary>
	double timeout;

	/// <summary>
	/// 剩余触发时间
	/// </summary>
	double remain_tim;

	/// <summary>
	/// 保留
	/// </summary>
	double res2[8];
}YKS_WDTStatus;

/// <summary>
/// CNC轴参数写入
/// </summary>
typedef struct _YKS_CncGCode
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// G代码
	/// </summary>
	char gcode[160];
}YKS_CncGCode;

/// <summary>
/// 基于控制点的AKIMA样条配置
/// </summary>
typedef struct _YKS_CncASplineConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 起始过渡切向
	/// Default(算法自动计算)
	/// </summary>
	YKE_CNC_ASPLINE_TRANS_TYPE start_trans_type;

	/// <summary>
	/// 终止过渡切向
	/// Default(算法自动计算)
	/// </summary>
	YKE_CNC_ASPLINE_TRANS_TYPE end_trans_type;

	/// <summary>
	/// 用户指定起始切向
	/// </summary>
	double start_Vector[3];

	/// <summary>
	/// 用户指定终止切向
	/// </summary>
	double end_Vector[3];

	/// <summary>
	/// 保留
	/// </summary>
	double res1[4];
}YKS_CncASplineConfig;

/// <summary>
/// CNC轮廓角偏差平滑配置
/// </summary>
typedef struct _YKS_CncContourDevConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 辅助功能(M/H)执行位置
	/// Default(平滑轮廓中)
	/// </summary>
	YKE_CNC_ACTION_TYPE action_time;

	/// <summary>
	/// 变加速监控
	/// Default(不监控)
	/// </summary>
	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	/// <summary>
	/// 轮廓过渡路径速度是否恒定
	/// Default(否)
	/// </summary>
	YKE_BOOL vel_const;

	/// <summary>
	/// 最大轮廓偏差
	/// </summary>
	double path_dev_max;

	/// <summary>
	/// 最大角度偏差
	/// </summary>
	double track_dev_max;

	/// <summary>
	/// 后续相关路径的最小长度
	/// </summary>
	double relevant_path_min;

	/// <summary>
	/// 后续相关路径的最小角度
	/// </summary>
	double relevant_track_min;

	/// <summary>
	/// 优化后路径长度相对原路径长度比例
	/// </summary>
	double remain_part;

	/// <summary>
	/// 轮廓过渡生效最大夹角
	/// </summary>
	double angle_max;
}YKS_CncContourDevConfig;

/// <summary>
/// CNC轮廓角距离平滑配置
/// </summary>
typedef struct _YKS_CncContourDistConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 辅助功能(M/H)执行位置
	/// Default(平滑轮廓中)
	/// </summary>
	YKE_CNC_ACTION_TYPE action_time;

	/// <summary>
	/// 变加速监控
	/// Default(不监控)
	/// </summary>
	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	/// <summary>
	/// 轮廓过渡路径速度是否恒定
	/// Default(否)
	/// </summary>
	YKE_BOOL vel_const;

	/// <summary>
	/// 最大角度偏差
	/// </summary>
	double track_dev_max;

	/// <summary>
	/// 过渡前段段拐角距离
	/// </summary>
	double pre_dist;

	/// <summary>
	/// 过渡后段拐角距离
	/// </summary>
	double post_dist;

	/// <summary>
	/// 后续相关路径的最小长度
	/// </summary>
	double relevant_path_min;

	/// <summary>
	/// 后续相关路径的最小角度
	/// </summary>
	double relevant_track_min;

	/// <summary>
	/// 优化后路径长度相对原路径长度比例
	/// </summary>
	double remain_part;

	/// <summary>
	/// 轮廓过渡生效最大夹角
	/// </summary>
	double angle_max;
}YKS_CncContourDistConfig;

/// <summary>
/// CNC动态轮廓优化平滑配置
/// </summary>
typedef struct _YKS_CncContourDistSoftConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 最大允许路径偏移角距离(对称)
	/// </summary>
	double path_dist;

	/// <summary>
	/// 路径偏离最大角度
	/// </summary>
	double track_dist;

	/// <summary>
	/// 最大加速度
	/// 轴最大加速度百分比[0%-100%]
	/// </summary>
	double acc_max;

	/// <summary>
	/// 最小加速度
	/// 轴最大加速度百分比[0%-100%]
	/// </summary>
	double acc_min;

	/// <summary>
	/// 变加速斜坡时间[0%-10000%]
	/// </summary>
	double ramp_time;

	/// <summary>
	/// 线性块分割百分比[0%-100%]
	/// </summary>
	double dist_weight;
}YKS_CncContourDistSoftConfig;

/// <summary>
/// CNC进给主轴动态轮廓优化平滑配置
/// </summary>
typedef struct _YKS_CncContourDistMasterConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 最大允许路径偏移角距离(对称)
	/// </summary>
	double path_dist;

	/// <summary>
	/// 最大加速度
	/// 轴最大加速度百分比[0%-100%]
	/// </summary>
	double acc_max;

	/// <summary>
	/// 最小加速度
	/// 轴最大加速度百分比[0%-100%]
	/// </summary>
	double acc_min;

	/// <summary>
	/// 变加速斜坡时间[0%-10000%]
	/// </summary>
	double ramp_time;

	/// <summary>
	/// 线性块分割百分比[0%-100%]
	/// </summary>
	double dist_weight;
}YKS_CncContourDistMasterConfig;

/// <summary>
/// CNC插入点平滑配置
/// </summary>
typedef struct _YKS_CncContourPosConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 辅助功能(M/H)执行位置
	/// Default(平滑轮廓中)
	/// </summary>
	YKE_CNC_ACTION_TYPE action_time;

	/// <summary>
	/// 变加速监控
	/// Default(不监控)
	/// </summary>
	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	/// <summary>
	/// 轮廓过渡路径速度是否恒定
	/// Default(否)
	/// </summary>
	YKE_BOOL vel_const;

	/// <summary>
	/// 过渡前段段拐角距离
	/// </summary>
	double pre_dist;

	/// <summary>
	/// 过渡后段拐角距离
	/// </summary>
	double post_dist;

	/// <summary>
	/// POS模式插入点坐标,三维[posX,posY,posZ]
	/// </summary>
	double pos_position[3];
}YKS_CncContourPosConfig;

/// <summary>
/// CNC完整轮廓动态优化平滑配置
/// </summary>
typedef struct _YKS_CncContourPtpConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 是否合并块
	/// Default(否)
	/// </summary>
	YKE_BOOL merge;

	/// <summary>
	/// 辅助功能(M/H)执行位置
	/// Default(平滑轮廓中)
	/// </summary>
	YKE_CNC_ACTION_TYPE action_time;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 最大轮廓偏差
	/// </summary>
	double path_dev_max;

	/// <summary>
	/// 最大允许路径偏移角距离(对称)
	/// </summary>
	double path_dist;
}YKS_CncContourPtpConfig;

/// <summary>
/// HSC_B样条平滑配置
/// </summary>
typedef struct _YKS_CncHscBConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 是否合并块
	/// Default(否)
	/// </summary>
	YKE_BOOL merge;

	/// <summary>
	/// 路径偏差超过path_dev_max,是否自动取消B样条平滑
	/// Default(否)
	/// </summary>
	YKE_BOOL auto_off_path;

	/// <summary>
	/// 角度偏差超过track_dev_max,是否自动取消B样条平滑
	/// Default(否)
	/// </summary>
	YKE_BOOL auto_off_track;

	/// <summary>
	/// 遇到快速移动(G00)指令,是否自动取消B样条平滑
	/// Default(否)
	/// </summary>
	YKE_BOOL auto_off_rapid;

	/// <summary>
	/// 遇到精确停止(G60/G360)指令,是否自动取消B样条平滑
	/// Default(否)
	/// </summary>
	YKE_BOOL auto_off_exactStop;

	/// <summary>
	/// 最大路径误差
	/// </summary>
	double path_dev_max;

	/// <summary>
	/// 最大角度误差
	/// </summary>
	double track_dev_max;

	/// <summary>
	/// B样条平滑生效的最大路径长度,大于指定值,则自动取消B样条平滑
	/// 0-不取消
	/// </summary>
	double path_len_max;

	/// <summary>
	/// B样条平滑生效的最大夹角。大于指定值,则自动取消B样条平滑
	/// 0-160°
	/// </summary>
	double angle_max;

	/// <summary>
	/// 保留
	/// </summary>
	double res1[4];
}YKS_CncHscBConfig;

/// <summary>
/// HSC_Surface平滑配置
/// </summary>
typedef struct _YKS_CncHscSConfig
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 圆周运动轮廓
	/// Default(圆弧轮廓平滑)
	/// </summary>
	YKE_HSC_CIR_MODE cir_mode;

	/// <summary>
	/// 变加速监控
	/// Default(不监控)
	/// </summary>
	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	/// <summary>
	/// 快速移动(G00)指令,是否自动取消平滑
	/// Default(否)
	/// </summary>
	YKE_BOOL auto_off_rapid;

	/// <summary>
	/// 是否合并块
	/// Default(否)
	/// </summary>
	YKE_BOOL merge;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res0;

	/// <summary>
	/// 最小圆角,小于指定角度,则使用样条曲线近似处理。
	/// </summary>
	double cir_min_angle;

	/// <summary>
	/// 快速移动最大角度误差
	/// </summary>
	double track_dev_rapid;

	/// <summary>
	/// 最大路径误差
	/// </summary>
	double path_dev_max;

	/// <summary>
	/// 快速移动过渡最大误差,默认path_dev_max
	/// </summary>
	double path_dev_rapid;

	/// <summary>
	/// 平滑生效的最大夹角,大于指定值,则自动取消B样条平滑
	/// 0-160°
	/// </summary>
	double angle_max;

	/// <summary>
	/// 最小半径,小于指定半径或小于path_dev,则使用样条曲线近似处理。
	/// </summary>
	double cir_min_radius;

	/// <summary>
	/// cir_mode=2时,长圆的最小长度。
	/// </summary>
	double cir_long_length;

	/// <summary>
	/// 最大角度误差
	/// </summary>
	double track_dev_max;

	/// <summary>
	/// 保留
	/// </summary>
	double res[8];
}YKS_CncHscSConfig;

/// <summary>
/// HSC_PCS1平滑参数
/// </summary>
typedef struct _YKS_CncHscPcs1Config
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 最大轮廓误差
	/// </summary>
	double contour_error_Max;
}YKS_CncHscPcs1Config;

/// <summary>
/// HSC_PCS2平滑参数
/// </summary>
typedef struct _YKS_CncHscPcs2Config
{
	/// <summary>
	/// 用户标记
	/// </summary>
	UINT32 mark;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 最大轮廓误差
	/// </summary>
	double contour_error_Max;
}YKS_CncHscPcs2Config;

/// <summary>
/// 写CNC参数状态
/// </summary>
typedef struct _YKS_CncParaStatus
{
	/// <summary>
	/// 命令状态 0:未完成 1:已完成
	/// </summary>
	YKE_BOOL done;

	/// <summary>
	/// 状态 1:完成 2:有错误
	/// </summary>
	UINT32 status;

	/// <summary>
	/// 读命令的返回值
	/// </summary>
	char value[128];

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res;

	/// <summary>
	/// 保留
	/// </summary>
	UINT32 res1[8];
}YKS_CncParaStatus;
#pragma endregion

#pragma region 系统
/// <summary>
/// 连接NT控制器
/// </summary>
/// <param name="ip_addr">ip地址</param>
/// <param name="ip_port">端口号，默认50001</param>
/// <param name="handle">返回的句柄</param>
/// <returns></returns>
YK_API YKM_SysConnect(char* ip_addr, UINT32 ip_port, INT32* handle);

/// <summary>
/// 断开NT控制器
/// </summary>
/// <param name="handle">通讯句柄</param>
/// <returns></returns>
YK_API YKM_SysClose(INT32 handle);

/// <summary>
/// 获取库文件(YKCAT2.dll)版本
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="version">当前版本号</param>
/// <returns></returns>
YK_API YKM_GetSysVersion(INT32 handle, UINT32* version);

/// <summary>
/// 获取Runtime版本
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="version">当前版本号</param>
/// <returns></returns>
YK_API YKM_GetRuntimeVersion(INT32 handle, UINT32* version);

/// <summary>
/// 获取线程ID
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="id">线程ID</param>
/// <returns></returns>
YK_API YKM_GetThreadID(INT32 handle, UINT32* id);

/// <summary>
/// 打开和Runtime(ProR)之间的通讯通道
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SysLoadLib(INT32 handle);

/// <summary>
/// 释放系统资源，程序退出时调用
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SysUnloadLib(INT32 handle);

/// <summary>
/// 设置应用程序看门狗超时时间
/// 可用于上位机异常关闭时自动停止轴运动及输出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="enable">FALSE:不启用 TRUE:启用</param>
/// <param name="tim">超时时间(ms)</param>
/// <returns></returns>
YK_API YKM_SetAppWDT(INT32 handle, YKE_BOOL enable, double tim);

/// <summary>
/// 重置应用程序看门狗
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_ClearAppWDT(INT32 handle);

/// <summary>
/// 获取应用程序看门狗状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAppWDT(INT32 handle, YKS_WDTStatus* status);

/// <summary>
/// 开始日志记录
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="process_id">进程ID</param>
/// <returns></returns>
YK_API YKM_StartLogger(INT32 handle, UINT32 process_id);

/// <summary>
/// 停止日志记录
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_StopLogger(INT32 handle);

/// <summary>
/// 获取开启日志的进程ID
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="process_id">进程ID</param>
/// <returns></returns>
YK_API YKM_GetLoggerProcessID(INT32 handle, UINT32 *process_id);

/// <summary>
/// 写日志配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetLoggerConfig(INT32 handle, YKS_LoggerConfig config);

/// <summary>
/// 读日志配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetLoggerConfig(INT32 handle, YKS_LoggerConfig* config);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="config">配饰</param>
/// <returns></returns>
YK_API YKM_InitExcData(INT32 handle, YKS_ExcTrackConfig config);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="item_data">保留</param>
/// <param name="ret_size">保留</param>
/// <returns></returns>
YK_API YKM_GetExcData(INT32 handle, YKS_ExcTrackItem* item_data, UINT32 *ret_size);

/// <summary>
/// 获取进程名称
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="process_id">进程ID</param>
/// <param name="name">进程名称</param>
/// <param name="size">缓冲区大小</param>
/// <returns></returns>
YK_API YKM_GetProcessName(INT32 handle, UINT32 process_id, char* name, UINT32 size);

/// <summary>
/// 获取调用运动库的进程列表
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="process_num">进程数量</param>
/// <param name="process_id">进程ID,至少16个元素空间</param>
/// <returns></returns>
YK_API YKM_GetProcessNumber(INT32 handle, UINT32* process_num, UINT32* process_id);

/// <summary>
/// 获取当前进程ID
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="process_id">进程ID</param>
/// <returns></returns>
YK_API YKM_GetProcessID(INT32 handle, UINT32* process_id);

/// <summary>
/// 获取本进程函数调用记录，每次最多返回1行
/// </summary>
/// <param name="handle">固定为0</param>
/// <param name="buff">缓冲区地址</param>
/// <param name="size">缓冲区大小</param>
/// <param name="count">返回的字符数量</param>
/// <returns></returns>
YK_API YKM_ReadFunLog(INT32 handle, char* buff, UINT32 size, UINT32* count);

/// <summary>
/// 获取系统配置信息
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="config"></param>
/// <returns></returns>
YK_API YKM_GetSysProfile(INT32 handle, YKS_SysProfile* config);

/// <summary>
/// 获取当前报警信息
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="buff">缓冲区，不小于2048字节</param>
/// <param name="size">缓冲区尺寸</param>
/// <param name="num">报警数量</param>
/// <returns></returns>
YK_API YKM_ReadSysWarn(INT32 handle, char* buff, UINT32 size, UINT32* num);

/// <summary>
/// 获取系统日志
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="buff">缓冲区，不小于2048字节</param>
/// <param name="size">缓冲区尺寸</param>
/// <param name="ret_size">实际返回数据大小</param>
/// <returns></returns>
YK_API YKM_ReadSysLog(INT32 handle, char* buff, UINT32 size, UINT32* ret_size);

/// <summary>
/// 清除缓存中的日志
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_ClearSysLog(INT32 handle);

/// <summary>
/// 向管理任务发送命令
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="run_stop">YKE_FALSE=停止(轴会停止，输出会关闭) YKE_TRUE=运行</param>
/// <returns></returns>
YK_API YKM_SendMgmtCmd(INT32 handle, YKE_NODE master, YKE_BOOL run_stop);

/// <summary>
/// 获取runtime运行状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="status">0=停止 1=运行 2=过渡状态</param>
/// <returns></returns>
YK_API YKM_ReadMgmtStatus(INT32 handle, YKE_NODE master, UINT32* status);

/// <summary>
/// 冷复位，此动作会重启实时系统和Runtime
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="delay">服务停止后延时指定时间后再开启服务(ms)</param>
/// <returns></returns>
YK_API YKM_SysColdReset(INT32 handle, double delay);

/// <summary>
/// 热复位。复位runtime，轴运动停止，关输出。复位A节点时,默认复位其他节点
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <returns></returns>
YK_API YKM_SysWarmReset(INT32 handle, YKE_NODE master);

/// <summary>
/// 启动Runtime服务
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SysStartService(INT32 handle);

/// <summary>
/// 停止Runtime服务
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SysStopService(INT32 handle);

/// <summary>
/// 检测Runtime服务是否处于运行状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="status">TRUE:已运行 FALSE:未运行</param>
/// <returns></returns>
YK_API YKM_SysCheckService(INT32 handle, YKE_BOOL *status);

/// <summary>
/// 注册runtime服务
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="path">runtime根目录</param>
/// <returns></returns>
YK_API YKM_SysRegisterService(INT32 handle, char* path);

/// <summary>
/// 注销runtime服务
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SysUnRegisterService(INT32 handle);

/// <summary>
/// 获取服务注册状态和服务文件路径
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="registered">TRUE:已注册 FALSE:未注册</param>
/// <param name="path">路径缓冲区</param>
/// <param name="size">路径缓冲区大小</param>
/// <returns></returns>
YK_API YKM_SysGetService(INT32 handle, YKE_BOOL* registered, char* path, UINT32 size);

/// <summary>
/// 设置硬急停配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_SetHardEmgProfile(INT32 handle, UINT32 channel, YKS_HardEmgProfile config);

/// <summary>
/// 获取硬急停配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
/// <param name="config"></param>
/// <returns></returns>
YK_API YKM_GetHardEmgProfile(INT32 handle, UINT32 channel, YKS_HardEmgProfile* config);

/// <summary>
/// 设置软急停信号有效
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
/// <returns></returns>
YK_API YKM_SetEmgStopSoft(INT32 handle, UINT32 channel);

/// <summary>
/// 清除软急停信号有效
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
/// <returns></returns>
YK_API YKM_ClearEmgStopSoft(INT32 handle, UINT32 channel);

/// <summary>
/// 获取急停状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号 [0,YKE_EMG_STOP_NUM)</param>
/// <param name="status">返回状态</param>
/// <returns></returns>
YK_API YKM_ReadEmgStatus(INT32 handle, UINT32 channel, YKS_EmgStatus* status);

/// <summary>
/// 设置Windows蓝屏后的行为
/// 未实现
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetBlueScreenConfig(INT32 handle, YKS_BlueScreenConfig config);

/// <summary>
/// 获取ProEN工程ID
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="prj_id">工程ID缓冲区</param>
/// <param name="size">缓冲区大小</param>
/// <returns></returns>
YK_API YKM_GetProjectID(INT32 handle, char* prj_id, UINT32 size);

/// <summary>
/// 加载由ProEn导出的工程配置数据(bprj扩展名)
/// 注意下载前会主动停止正在运动中的轴
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="filename">路径及文件名称</param>
/// <param name="mask">数据掩码按位定义(YKE_PROJECT_MASK),置位时下载对应的数据</param>
/// <returns></returns>
YK_API YKM_LoadProjectData(INT32 handle, char* filename, UINT32 mask);

/// <summary>
/// 获取给PLC模块的控制命令
/// 内部使用
/// </summary>
/// <param name="command">命令</param>
/// <returns></returns>
YK_API YKM_GetPLCCommand(YKE_PLC_CMD_TYPE* command);

/// <summary>
/// 写入PLC状态
/// 内部使用
/// </summary>
/// <param name="handle">保留</param>
/// <param name="status">命令</param>
/// <returns></returns>
YK_API YKM_SetPLCStatus(INT32 handle, UINT32 status);

/// <summary>
/// 向PLC发送控制命令
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="command">控制命令</param>
/// <returns></returns>
YK_API YKM_SendPLCCommand(INT32 handle, YKE_PLC_CMD_TYPE command);

/// <summary>
/// 清除系统报警
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <returns></returns>
YK_API YKM_ClearSysWarn(INT32 handle, YKE_NODE master);

/// <summary>
/// 设置总线事件间隔时间
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="tim">时间[0,](ms)</param>
/// <returns></returns>
YK_API YKM_SetBusEventTime(INT32 handle, YKE_NODE master, double tim);

/// <summary>
/// 获取总线事件间隔时间
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="tim">时间[0,](ms)</param>
/// <returns></returns>
YK_API YKM_GetBusEventTime(INT32 handle, YKE_NODE master, double *tim);

/// <summary>
/// 等待总线任务事件，指定时间触发一次
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <returns></returns>
YK_API YKM_WaitBusEvent(INT32 handle, YKE_NODE master);

/// <summary>
/// 读总线通讯数据帧
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="header">帧头信息</param>
/// <param name="buff">缓冲区地址</param>
/// <param name="size">缓冲区大小,大于1500</param>
/// <returns></returns>
YK_API YKM_ReadBusPacket(INT32 handle, YKS_BusPacketHeader *header, UINT8* buff, UINT32 size);

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
YK_API YKM_WriteDataRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

/// <summary>
/// 读通用寄存器,UIN32模式
/// YKE_GENDATA_SIZE个UINT32空间
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="offset">地址偏移</param>
/// <param name="data">数据指针</param>
/// <param name="size">数据数量 UINT32单位</param>
/// <returns></returns>
YK_API YKM_ReadDataRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

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
YK_API YKM_WriteDataRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

/// <summary>
/// 读通用寄存器,double模式
/// YKE_GENDATA_SIZE个UINT32空间
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="offset">地址偏移</param>
/// <param name="data">数据指针</param>
/// <param name="size">数据数量 double单位</param>
/// <returns></returns>
YK_API YKM_ReadDataRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

/// <summary>
/// 获取通用寄存器在内存中的首地址
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="hi_addr">内存地址(高32位)</param>
/// <param name="lo_addr">内存地址(低32位)</param>
/// <returns></returns>
YK_API YKM_GetDataRegAddress(INT32 handle, UINT32* hi_addr, UINT32 *lo_addr);

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
YK_API YKM_WriteSpecRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

/// <summary>
/// 读特殊功能寄存器,UIN32模式
/// YKE_SPDATA_SIZE个UINT32空间
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="offset">地址偏移</param>
/// <param name="data">数据指针</param>
/// <param name="size">数据数量 UINT32单位</param>
/// <returns></returns>
YK_API YKM_ReadSpecRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

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
YK_API YKM_WriteSpecRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

/// <summary>
/// 读特殊功能寄存器,double模式
/// YKE_SPDATA_SIZE个UINT32空间
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="offset">地址偏移</param>
/// <param name="data">数据指针</param>
/// <param name="size">数据数量 double单位</param>
/// <returns></returns>
YK_API YKM_ReadSpecRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

/// <summary>
/// 获取特殊寄存器在内存中的首地址
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="hi_addr">内存地址(高32位)</param>
/// <param name="lo_addr">内存地址(低32位)</param>
/// <returns></returns>
YK_API YKM_GetSpecRegAddress(INT32 handle, UINT32* hi_addr, UINT32* lo_addr);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="name">工程名称</param>
/// <returns></returns>
YK_API YKM_ProEnAddPrj(INT32 handle, char* name);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="name">工程名称</param>
/// <returns></returns>
YK_API YKM_ProEnDelPrj(INT32 handle, char* name);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="name">工程名称</param>
/// <returns></returns>
YK_API YKM_ProEnCheckPrj(INT32 handle, char* name);

/// <summary>
/// ProEn写配置数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="type">数量类型</param>
/// <param name="data">数据</param>
/// <param name="size">数据大小</param>
/// <returns></returns>
YK_API YKM_ProEnWriteData(INT32 handle, UINT32 type, UINT8* data, UINT32 size);

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
YK_API YKM_ReadDoggleData(INT32 handle, YKE_DOGGLE_TYPE type, UINT32 offset, char* data, UINT32 size, INT32* result);

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
YK_API YKM_WriteDoggleData(INT32 handle, YKE_DOGGLE_TYPE type, UINT32 offset, char* data, UINT32 size, INT32* result);
#pragma endregion

#pragma region 总线
/// <summary>
/// 断开总线连接，断开后再次调用复位命令可恢复总线运行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <returns></returns>
YK_API YKM_DisconnectBus(INT32 handle, YKE_NODE master);

/// <summary>
/// 热复位并扫描从站
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="info">扫描内容</param>
/// <returns></returns>
YK_API YKM_ScanBus(INT32 handle, YKE_NODE master, YKE_SCAN_INFO info);

/// <summary>
/// 获得总线信息
/// </summary>
/// <param name="master">主站选择</param>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="info"></param>
/// <returns></returns>
YK_API YKM_ReadBusStatus(INT32 handle, YKE_NODE master, YKS_BusStatus* info);

/// <summary>
/// 清除总线负载率/同步偏移/帧丢失数量
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <returns></returns>
YK_API YKM_ClearBusValue(INT32 handle, YKE_NODE master);

/// <summary>
/// 清除总线报警
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <returns></returns>
YK_API YKM_ClearBusWarn(INT32 handle, YKE_NODE master);

/// <summary>
/// 配置总线节点信息
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="slaveIndex">站点序号，从0开始</param>
/// <param name="item">配置内容，热复位后生效</param>
/// <param name="value">配置值</param>
/// <returns></returns>
YK_API YKM_SetBusConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, YKE_SLAVE_ITEM item, INT32 value);

/// <summary>
/// 获取总线节点信息
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="slaveIndex">站点序号，从0开始</param>
/// <param name="item">配置内容</param>
/// <param name="value">返回的配置值</param>
/// <returns></returns>
YK_API YKM_GetBusConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, YKE_SLAVE_ITEM item, INT32* value);

/// <summary>
/// 获得从站名称，名称在ProEn中设置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="slaveIndex">站点序号，从0开始</param>
/// <param name="name">返回名称，至少分配64字节</param>
/// <param name="size">name缓冲区尺寸</param>
/// <returns></returns>
YK_API YKM_GetSlaveAlias(INT32 handle, YKE_NODE master, UINT32 slaveIndex, char* name, UINT32 size);

/// <summary>
/// 获得总线各站点状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="slaveIndex">站点序号，从0开始</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadSlaveStatus(INT32 handle, YKE_NODE master, UINT32 slaveIndex, YKS_SlaveStatus* status);

/// <summary>
/// 读从站输出PDO数量
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标</param>
/// <param name="master">主站</param>
/// <param name="slaveIndex">从站序号</param>
/// <param name="number">返回数量</param>
/// <returns></returns>
YK_API YKM_GetSlaveTxPdoNumber(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32* number);

/// <summary>
/// 读从站输出PDO配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标</param>
/// <param name="master">主站</param>
/// <param name="slaveIndex">从站序号</param>
/// <param name="pdoIndex">PDO序号，从0开始</param>
/// <param name="config">返回数量</param>
/// <returns></returns>
YK_API YKM_GetSlaveTxPdoConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 pdoIndex, YKS_SlavePdoConfig* config);

/// <summary>
/// 读从站输入PDO数量
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标</param>
/// <param name="master">主站</param>
/// <param name="slaveIndex">从站序号</param>
/// <param name="number">返回数量</param>
/// <returns></returns>
YK_API YKM_GetSlaveRxPdoNumber(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32* number);

/// <summary>
/// 读从站输入PDO配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标</param>
/// <param name="master">主站</param>
/// <param name="slaveIndex">从站序号</param>
/// <param name="pdoIndex">PDO序号，从0开始</param>
/// <param name="config">返回配置</param>
/// <returns></returns>
YK_API YKM_GetSlaveRxPdoConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 pdoIndex, YKS_SlavePdoConfig* config);
#pragma endregion

#pragma region PDO/SDO
/// <summary>
/// 设置系统保留PDO保护标志
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="uIndex">站点序号</param>
/// <param name="check">TRUE=开启写入保护 FALSE=关闭写入保护</param>
/// <returns></returns>
YK_API YKM_SetPDOProtect(INT32 handle, YKE_NODE master, UINT32 uIndex, YKE_BOOL check);

/// <summary>
/// 获取系统保留PDO保护标志
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="uIndex">站点序号</param>
/// <param name="check">TRUE=开启写入保护 FALSE=关闭写入保护</param>
/// <returns></returns>
YK_API YKM_GetPDOProtect(INT32 handle, YKE_NODE master, UINT32 uIndex, YKE_BOOL* check);

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
YK_API YKM_WritePDOIndex(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 gIndex, UINT16 *ptr, UINT32 size);

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
YK_API YKM_ReadPDOIndex(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 gIndex, UINT16 *ptr, UINT32 size);

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
YK_API YKM_ReadPDOObject(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 mainIndex, UINT32 subIndex, UINT16 *ptr, UINT32 size);

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
YK_API YKM_WritePDOObject(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 mainIndex, UINT32 subIndex, UINT16 *ptr, UINT32 size);

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
YK_API YKM_WriteSDOCmd(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 mainIndex, UINT32 subIndex, UINT32 byteNum, UINT32 val, UINT32* sdoIndex);

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
YK_API YKM_ReadSDOCmd(INT32 handle, YKE_NODE master, UINT32 uIndex, UINT32 mainIndex, UINT32 subIndex, UINT32 byteNum, UINT32* sdoIndex);

/// <summary>
/// 读SDO队列状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="sdoIndex">SDO队列索引</param>
/// <param name="status">返回状态</param>
YK_API YKM_ReadSDOStatus(INT32 handle, YKE_NODE master, UINT32 sdoIndex, YKS_SdoStatus *status);

/// <summary>
/// 获得SDO队列空闲数量
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="num">返回的空闲数量</param>
/// <returns></returns>
YK_API YKM_GetSDOIdel(INT32 handle, YKE_NODE master, UINT32* num);
#pragma endregion

#pragma region 数字IO
/// <summary>
/// 按位读数字输出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
/// <returns></returns>
YK_API YKM_ReadDigitalOutputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value);

/// <summary>
/// 按位批量读数字输出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
/// <param name="size">读取数量</param>
/// <returns></returns>
YK_API YKM_ReadDigitalOutputBits(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value, UINT32 size);

/// <summary>
/// 按位写数字输出
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">写入值: FALSE=OFF  TRUE=ON</param>
/// <returns></returns>
YK_API YKM_WriteDigitalOutputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL value);

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
YK_API YKM_WriteDigitalOutputBits(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL *value, UINT32 size);

/// <summary>
/// 按字节读数字输出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)，每组8位</param>
/// <param name="value">输出值</param>
/// <returns></returns>
YK_API YKM_ReadDigitalOutputByte(INT32 handle, UINT32 byteIndex, UINT8* value);

/// <summary>
/// 按字节写数字输出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)，每组8位</param>
/// <param name="value">输出值</param>
/// <returns></returns>
YK_API YKM_WriteDigitalOutputByte(INT32 handle, UINT32 byteIndex, UINT8 value);

/// <summary>
/// 按字节写数字输出(带掩码)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="mask">按位定义，对应位为0时无效，为1时输出按value值输出</param>
/// <param name="value">按位定义，输出值</param>
/// <returns></returns>
YK_API YKM_WriteDigitalOutputMask(INT32 handle, UINT32 byteIndex, UINT8 mask, UINT8 value);

/// <summary>
/// 按位设置数字输出在热复位时的保持行为
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="hold">写入值: 0=不保持  1=保持</param>
/// <returns></returns>
YK_API YKM_SetDigitalOutputHold(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL hold);

/// <summary>
/// 读取数字输出在热复位时的保持行为
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="hold">FALSE=不保持  TRUE=保持</param>
/// <returns></returns>
YK_API YKM_GetDigitalOutputHold(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* hold);

/// <summary>
/// 写数字输入滤波时间(ms)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="filter">滤波时间[0,1000](ms)</param>
/// <returns></returns>
YK_API YKM_WriteDigitalInputFilter(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, double filter);

/// <summary>
/// 读数字输入滤波时间(ms)
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="filter">滤波时间[0,1000](ms)</param>
/// <returns></returns>
YK_API YKM_ReadDigitalInputFilter(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, double* filter);

/// <summary>
/// 按位读数字输入
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
/// <returns></returns>
YK_API YKM_ReadDigitalInputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value);

/// <summary>
/// 按位批量读数字输入
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">返回值: FALSE=OFF  TRUE=ON</param>
/// <param name="size">读取数量</param>
/// <returns></returns>
YK_API YKM_ReadDigitalInputBits(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value, UINT32 size);

/// <summary>
/// 按位写数字输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value"> FALSE=OFF  TRUE=ON</param>
/// <returns></returns>
YK_API YKM_WriteDigitalInputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL value);

/// <summary>
/// 按字节读数字输入
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">组序号[0,YKE_DIGITAL_INPUT_NUM/8)，每组8位</param>
/// <param name="value">输入值</param>
/// <returns></returns>
YK_API YKM_ReadDigitalInputByte(INT32 handle, UINT32 byteIndex, UINT8* value);

/// <summary>
/// 按字节写数字输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">组序号[0,YKE_DIGITAL_INPUT_NUM/8)，每组8位</param>
/// <param name="value">输入值</param>
/// <returns></returns>
YK_API YKM_WriteDigitalInputByte(INT32 handle, UINT32 byteIndex, UINT8 value);

/// <summary>
/// 读数字输入(软件滤波前)的上升沿计数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">返回值</param>
/// <returns></returns>
YK_API YKM_ReadInputEdgeCount1(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32* value);

/// <summary>
/// 写数字输入(软件滤波前)的上升沿计数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">写入值</param>
/// <returns></returns>
YK_API YKM_WriteInputEdgeCount1(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32 value);

/// <summary>
/// 读数字输入(软件滤波后)的上升沿计数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">返回值</param>
/// <returns></returns>
YK_API YKM_ReadInputEdgeCount2(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32* value);

/// <summary>
/// 写数字输入(软件滤波后)的上升沿计数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="value">写入值</param>
/// <returns></returns>
YK_API YKM_WriteInputEdgeCount2(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32 value);

/// <summary>
/// 读数字输入的硬件信息
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_INPUT_NUM/8)</param>
/// <param name="phy">物理位置</param>
/// <returns></returns>
YK_API YKM_ReadInputLocation(INT32 handle, UINT32 byteIndex, YKS_DigitalIOHardInfo* phy);

/// <summary>
/// 读数字输出的硬件信息
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="phy">物理位置</param>
/// <returns></returns>
YK_API YKM_ReadOutputLocation(INT32 handle, UINT32 byteIndex, YKS_DigitalIOHardInfo* phy);

/// <summary>
/// 延时翻转输出
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="byteIndex">字节序号[0,YKE_DIGITAL_OUTPUT_NUM/8)</param>
/// <param name="bitOffset">位偏移[0,7]</param>
/// <param name="time">延时时间(ms)</param>
/// <returns></returns>
YK_API YKM_ReverseDigitalOutputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, double time);

/// <summary>
/// 同步数字输出
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="output">输出列表</param>
/// <param name="size">输出数量(0, YKE_DIGITAL_OUTPUT_CYCLE_NUM]</param>
/// <returns></returns>
YK_API YKM_WriteDigitalOutputCycle(INT32 handle, YKS_DigitalOutputCycle* output, UINT32 size);
#pragma endregion

#pragma region 软件位置比较
/// <summary>
/// 软件模式比较器参数配置
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetCompareConfigSoft(INT32 handle, UINT32 channel, YKS_CompareConfigSoft config);

/// <summary>
/// 获取软件模式比较器参数配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetCompareConfigSoft(INT32 handle, UINT32 channel, YKS_CompareConfigSoft* config);

/// <summary>
/// 设置比较值
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
/// <param name="itemdata">比较配置，内部含有512个缓冲区</param>
/// <returns></returns>
YK_API YKM_SetCompareValueSoft(INT32 handle, UINT32 channel, YKS_CompareItemDataSoft itemdata);

/// <summary>
/// 获取软件模式比较器状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
/// <param name="status">返回值</param>
/// <returns></returns>
YK_API YKM_ReadCompareStatusSoft(INT32 handle, UINT32 channel, YKS_CompareStatusSoft* status);

/// <summary>
/// 软件模式比较器开始
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
/// <returns></returns>
YK_API YKM_StartCompareSoft(INT32 handle, UINT32 channel);

/// <summary>
/// 停止软件模式比较器
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_COMPARE_NUM)</param>
/// <returns></returns>
YK_API YKM_StopCompareSoft(INT32 handle, UINT32 channel);

/// <summary>
/// 写入软件探针配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetProbeConfigSoft(INT32 handle, UINT32 channel, YKS_ProbeConfigSoft config);

/// <summary>
/// 读取软件探针配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetProbeConfigSoft(INT32 handle, UINT32 channel, YKS_ProbeConfigSoft* config);

/// <summary>
/// 启动软件探针
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
/// <returns></returns>
YK_API YKM_StartProbeSoft(INT32 handle, UINT32 channel);

/// <summary>
/// 停止软件探针
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
/// <returns></returns>
YK_API YKM_StopProbeSoft(INT32 handle, UINT32 channel);

/// <summary>
/// 获取软件探针状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_SOFT_PROBE_NUM)</param>
/// <param name="status">返回状态</param>
/// <returns></returns>
YK_API YKM_ReadProbeStatusSoft(INT32 handle, UINT32 channel, YKS_ProbeStatusSoft* status);
#pragma endregion

#pragma region 轴设置/信息
/// <summary>
/// 设置规划方向的当量，初始化完成后先设置当量，再使用和当量有关的函数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="dist">位移当量，浮点格式</param>
/// <param name="pulse">脉冲当量，浮点格式</param>
/// <returns></returns>
YK_API YKM_SetCommandEquiv(INT32 handle, UINT32 axisIndex, double dist, double pulse);

/// <summary>
/// 获取规划方向的当量，初始化完成后先设置当量，再使用和当量有关的函数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="dist">位移当量，浮点格式</param>
/// <param name="pulse">脉冲当量，浮点格式</param>
/// <returns></returns>
YK_API YKM_GetCommandEquiv(INT32 handle, UINT32 axisIndex, double* dist, double* pulse);

/// <summary>
/// 获取反馈方向当量比例，以规划方向当量为参考，未实现
/// 总线轴有效
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="scale">比例</param>
/// <returns></returns>
YK_API YKM_GetFeedbackEquivScale(INT32 handle, UINT32 axisIndex, double* scale);

/// <summary>
/// 设置反馈方向当量比例，以规划方向当量为参考，未实现
/// 总线轴有效
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="scale">比例</param>
/// <returns></returns>
YK_API YKM_SetFeedbackEquivScale(INT32 handle, UINT32 axisIndex, double scale);

/// <summary>
/// 设置转动方向
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="rotate_dir">FALSE:和驱动器一致  TRUE:和驱动器相反</param>
/// <returns></returns>
YK_API YKM_SetRotateDir(INT32 handle, UINT32 axisIndex, YKE_BOOL rotate_dir);

/// <summary>
/// 获取转动方向
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="rotate_dir">FALSE:和驱动器一致  TRUE:和驱动器相反</param>
/// <returns></returns>
YK_API YKM_GetRotateDir(INT32 handle, UINT32 axisIndex, YKE_BOOL* rotate_dir);

/// <summary>
/// 设置模轴配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProfileModulo(INT32 handle, UINT32 axisIndex, YKS_AxisProfileModulo config);

/// <summary>
/// 获取模轴配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfileModulo(INT32 handle, UINT32 axisIndex, YKS_AxisProfileModulo* config);

/// <summary>
/// 获得单圈数量
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="counter">单圈数量</param>
/// <returns></returns>
YK_API YKM_ReadAxisModuloCounter(INT32 handle, UINT32 axisIndex, INT32* counter);

/// <summary>
/// 设置软限位
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">限位配置</param>
/// <returns></returns>
YK_API YKM_SetAxisSoftLimit(INT32 handle, UINT32 axisIndex, YKS_AxisSoftLimitConfig config);

/// <summary>
/// 获取软限位配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetAxisSoftLimit(INT32 handle, UINT32 axisIndex, YKS_AxisSoftLimitConfig* config);

/// <summary>
/// 写入硬限位启用配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetAxisHardLimitEnable(INT32 handle, UINT32 axisIndex, YKS_AxisHardLimitConfig config);

/// <summary>
/// 获取硬限位启用配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetAxisHardLimitEnable(INT32 handle, UINT32 axisIndex, YKS_AxisHardLimitConfig* config);

/// <summary>
/// 设置最大转矩值
/// 支持API缓冲区
/// 对象字典(0x6072:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">转矩值</param>
/// <returns></returns>
YK_API YKM_SetAxisMaxTorqueLimit(INT32 handle, UINT32 axisIndex, double value);

/// <summary>
/// 获取最大转矩值
/// 对象字典(0x6072:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">转矩值</param>
/// <returns></returns>
YK_API YKM_GetAxisMaxTorqueLimit(INT32 handle, UINT32 axisIndex, double* value);

/// <summary>
/// 设置正方向转矩限制值
/// 支持API缓冲区
/// 对象字典(0x60E0:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">转矩值</param>
/// <returns></returns>
YK_API YKM_SetAxisPositiveTorqueLimit(INT32 handle, UINT32 axisIndex, double value);

/// <summary>
/// 获取正方向转矩限制值
/// 对象字典(0x60E0:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">转矩值</param>
/// <returns></returns>
YK_API YKM_GetAxisPositiveTorqueLimit(INT32 handle, UINT32 axisIndex, double* value);

/// <summary>
/// 设置负方向转矩限制值
/// 支持API缓冲区
/// 对象字典(0x60E1:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">转矩值</param>
/// <returns></returns>
YK_API YKM_SetAxisNegativeTorqueLimit(INT32 handle, UINT32 axisIndex, double value);

/// <summary>
/// 获取负方向转矩限制值
/// 对象字典(0x60E1:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">转矩值</param>
/// <returns></returns>
YK_API YKM_GetAxisNegativeTorqueLimit(INT32 handle, UINT32 axisIndex, double* value);

/// <summary>
/// 设置最大电流限制值
/// 支持API缓冲区
/// 对象字典(0x6073:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">电流限制值</param>
/// <returns></returns>
YK_API YKM_SetAxisMaxCurrentLimit(INT32 handle, UINT32 axisIndex, double value);

/// <summary>
/// 获取最大电流限制值
/// 对象字典(0x6073:00)必须加到PDO中
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">电流限制值</param>
/// <returns></returns>
YK_API YKM_GetAxisMaxCurrentLimit(INT32 handle, UINT32 axisIndex, double* value);

/// <summary>
/// 获得规划位置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">位置</param>
/// <returns></returns>
YK_API YKM_ReadAxisCommandPosition(INT32 handle, UINT32 axisIndex, double* position);

/// <summary>
/// 获得实际位置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">位置</param>
/// <returns></returns>
YK_API YKM_ReadAxisActualPosition(INT32 handle, UINT32 axisIndex, double* position);

/// <summary>
/// 获得目标位置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">位置</param>
/// <returns></returns>
YK_API YKM_ReadAxisTargetPosition(INT32 handle, UINT32 axisIndex, double* position);

/// <summary>
/// 获取轴的原始位置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">位置</param>
/// <returns></returns>
YK_API YKM_ReadAxisRawPosition(INT32 handle, UINT32 axisIndex, INT32* position);

/// <summary>
/// 获得规划速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="velocity">速度</param>
/// <returns></returns>
YK_API YKM_ReadAxisCommandVelocity(INT32 handle, UINT32 axisIndex, double* velocity);

/// <summary>
/// 获得实际速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="velocity">速度</param>
/// <returns></returns>
YK_API YKM_ReadAxisActualVelocity(INT32 handle, UINT32 axisIndex, double* velocity);

/// <summary>
/// 获得规划加速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="acceleration">加速度</param>
/// <returns></returns>
YK_API YKM_ReadAxisCommandAcceleration(INT32 handle, UINT32 axisIndex, double* acceleration);

/// <summary>
/// 获得变加速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="jerk">变加速度</param>
/// <returns></returns>
YK_API YKM_ReadAxisCommandJerk(INT32 handle, UINT32 axisIndex, double* jerk);

/// <summary>
/// 获得给定转矩，需要在PDO中配置转矩对象字典
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="torque">转矩值</param>
/// <returns></returns>
YK_API YKM_ReadAxisCommandTorque(INT32 handle, UINT32 axisIndex, double* torque);

/// <summary>
/// 获得实际转矩，需要在PDO中配置转矩对象字典
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="torque">转矩值</param>
/// <returns></returns>
YK_API YKM_ReadAxisActualTorque(INT32 handle, UINT32 axisIndex, double* torque);

/// <summary>
/// 设置用户自定义数据
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="mask">掩码</param>
/// <param name="value">写入值</param>
/// <returns></returns>
YK_API YKM_SetAxisUserData(INT32 handle, UINT32 axisIndex, UINT32 mask, UINT32 value);

/// <summary>
/// 获取用户自定义数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="value">返回的值</param>
/// <returns></returns>
YK_API YKM_GetAxisUserData(INT32 handle, UINT32 axisIndex, UINT32* value);

/// <summary>
/// 读轴的基本配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_ReadAxisConfigBase(INT32 handle, UINT32 axisIndex, YKS_AxisConfigBase* config);

/// <summary>
/// 读轴规划状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisStatusPlanner(INT32 handle, UINT32 axisIndex, YKS_AxisStatusPlanner* status);

/// <summary>
/// 读轴位置相关状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisStatusPosition(INT32 handle, UINT32 axisIndex, YKS_AxisStatusPosition* status);

/// <summary>
/// 读轴机械补偿状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisStatusCompensation(INT32 handle, UINT32 axisIndex, YKS_AxisStatusCompensation* status);

/// <summary>
/// 读轴跟随状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisStatusFollow(INT32 handle, UINT32 axisIndex, YKS_AxisStatusFollow* status);

/// <summary>
/// 读轴基本状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisStatusBase(INT32 handle, UINT32 axisIndex, YKS_AxisStatusBase* status);

/// <summary>
/// 读轴触发状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisTriggerStatus(INT32 handle, UINT32 axisIndex, YKS_AxisTriggerStatus* status);

/// <summary>
/// 轴公共参数设置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">轴配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProfileBase(INT32 handle, UINT32 axisIndex, YKS_AxisProfileBase config);

/// <summary>
/// 获得轴公共参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">轴配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfileBase(INT32 handle, UINT32 axisIndex, YKS_AxisProfileBase* config);

/// <summary>
/// 运动参数设置
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProfileMotion(INT32 handle, UINT32 axisIndex, YKS_AxisProfileMotion config);

/// <summary>
/// 获得运动参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfileMotion(INT32 handle, UINT32 axisIndex, YKS_AxisProfileMotion* config);

/// <summary>
/// 设置轴到位配置
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">到位配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProfileInp(INT32 handle, UINT32 axisIndex, YKS_AxisProfileInp config);

/// <summary>
/// 获取轴到位配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">到位配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfileInp(INT32 handle, UINT32 axisIndex, YKS_AxisProfileInp* config);

/// <summary>
/// 设置轴跟随误差配置
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">跟随误差配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProfilePositionLag(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePositionLag config);

/// <summary>
/// 获取轴跟随配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">跟随误差配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfilePositionLag(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePositionLag* config);

/// <summary>
/// 获得轴使用列表
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisNum">返回值，轴数量</param>
/// <param name="axisList">轴序号列表</param>
/// <param name="size">axisList缓冲区大小</param>
/// <returns></returns>
YK_API YKM_GetAxisList(INT32 handle, UINT32* axisNum, UINT32 *axisList, UINT32 size);

/// <summary>
/// 设置驱动器控制模式，总线轴专用
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="mode">模式</param>
/// <returns></returns>
YK_API YKM_SetAxisDrvOpMode(INT32 handle, UINT32 axisIndex, YKE_DRV_OP_MODE mode);

/// <summary>
/// 获取驱动器控制模式，总线轴专用
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="mode">模式</param>
/// <returns></returns>
YK_API YKM_GetAxisDrvOpMode(INT32 handle, UINT32 axisIndex, YKE_DRV_OP_MODE* mode);

/// <summary>
/// 设置轴报警屏蔽配置
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="mask">屏蔽配置，按位定义 BIT0=硬限位 BIT1=保留 BIT2=软限位</param>
/// <returns></returns>
YK_API YKM_SetAxisWarnMask(INT32 handle, UINT32 axisIndex, UINT32 mask);

/// <summary>
/// 获取轴报警屏蔽配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="mask">屏蔽配置，按位定义 BIT0=硬限位  BIT1=保留 BIT2=软限位</param>
/// <returns></returns>
YK_API YKM_GetAxisWarnMask(INT32 handle, UINT32 axisIndex, UINT32* mask);

/// <summary>
/// 获取轴名称，名称在ProEn中设置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="name">返回名称，至少分配64字节</param>
/// <param name="size">name缓冲区尺寸</param>
/// <returns></returns>
YK_API YKM_GetAxisAlias(INT32 handle, UINT32 axisIndex, char* name, UINT32 size);

/// <summary>
/// 清除轴的回原完成状态(YKS_AxisStatusBase.is_homed)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_ClearAxisHomed(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 设置轴的回原完成状态(YKS_AxisStatusBase.is_homed)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_SetAxisHomed(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 将指编码器指定位置设为原点
/// 绝对值编码器工况下使用
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="encoder_value">设定值</param>
/// <returns></returns>
YK_API YKM_SetAxisHomeAbsEncoder(INT32 handle, UINT32 axisIndex, INT32 encoder_value);

/// <summary>
/// 获取原点对应的编码器值(由YKM_SetAxisHomeAbsEncoder写入)
/// 绝对值编码器工况下使用
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="encoder_value">返回值</param>
/// <returns></returns>
YK_API YKM_GetAxisHomeAbsEncoder(INT32 handle, UINT32 axisIndex, INT32* encoder_value);

/// <summary>
/// 写入正限位开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchLimitPositive(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

/// <summary>
/// 读取正限位开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchLimitPositive(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

/// <summary>
/// 写入负限位开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchLimitNegative(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

/// <summary>
/// 读取负限位开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchLimitNegative(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

/// <summary>
/// 写入原点开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchHome(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

/// <summary>
/// 读取原点开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchHome(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

/// <summary>
/// 写入探针开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号 (0~1)  0/1为硬件探针函数使用</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchProbe(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisSwitchConfig config);

/// <summary>
/// 读取探针开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号 (0~1)  0/1为硬件探针函数使用</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchProbe(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisSwitchConfig *config);

/// <summary>
/// 写入回原探针开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetHomeProbe(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

/// <summary>
/// 读取回原探针开关配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetHomeProbe(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

/// <summary>
/// 设置当前位置，将当前位置设置为指定值
/// 支持API缓冲区
/// 会清除IsHomed信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">指定位置</param>
/// <returns></returns>
YK_API YKM_SetAxisPosition(INT32 handle, UINT32 axisIndex, double position);

/// <summary>
/// 设置清除驱动器报警重试参数，总线轴有效
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="profile"></param>
/// <returns></returns>
YK_API YKM_SetAxisProfileClearDrv(INT32 handle, UINT32 axisIndex, YKS_AxisProfileClearDrv profile);

/// <summary>
/// 获取清除驱动器报警重试参数，总线轴有效
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="profile">返回配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfileClearDrv(INT32 handle, UINT32 axisIndex, YKS_AxisProfileClearDrv* profile);

/// <summary>
/// 清除驱动器报警
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_ClearDrvWarn(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 复位轴状态，清除报警
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_ClearAxisWarn(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 获取轴使能参数，总线轴有效
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="profile">配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfilePowerOn(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePowerOn* profile);

/// <summary>
/// 设置轴使能参数，总线轴有效
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="profile">配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProfilePowerOn(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePowerOn profile);

/// <summary>
/// 获取轴前馈参数，总线轴有效
/// 未实现
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="profile">配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProfileFeedforward(INT32 handle, UINT32 axisIndex, YKS_AxisProfileFeedforward* profile);

/// <summary>
/// 设置轴前馈参数，总线轴有效
/// 未实现
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="profile">配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProfileFeedforward(INT32 handle, UINT32 axisIndex, YKS_AxisProfileFeedforward profile);

/// <summary>
/// 轴使能
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_PowerOn(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 轴去使能
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_PowerOff(INT32 handle, UINT32 axisIndex);
#pragma endregion

#pragma region 单轴运动
/// <summary>
/// 单轴停止
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="dec_sel">减速度选择</param>
/// <returns></returns>
YK_API YKM_StopAxis(INT32 handle, UINT32 axisIndex, YKE_STOP_DEC dec_sel);

/// <summary>
/// 触发轴停止
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="dec_sel">减速度选择</param>
/// <param name="trigger">触发条件</param>
/// <returns></returns>
YK_API YKM_StopAxisTrigger(INT32 handle, UINT32 axisIndex, YKE_STOP_DEC dec_sel, YKS_AxisTrigger trigger);

/// <summary>
/// 启动回原点
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_StartHome(INT32 handle, UINT32 axisIndex, YKS_AxisHomeConfig config);

/// <summary>
/// 获取回原点配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetHomeConfig(INT32 handle, UINT32 axisIndex, YKS_AxisHomeConfig* config);

/// <summary>
/// 绝对运动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">目标位置</param>
/// <returns></returns>
YK_API YKM_MoveAbsolute(INT32 handle, UINT32 axisIndex, double position);

/// <summary>
/// 绝对运动(带运动参数)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_MoveAbsoluteEx(INT32 handle, UINT32 axisIndex, YKS_MoveAbsoluteConfig config);

/// <summary>
/// 绝对运动(条件触发)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <param name="trigger">触发条件</param>
/// <returns></returns>
YK_API YKM_MoveAbsoluteTrigger(INT32 handle, UINT32 axisIndex, YKS_MoveAbsoluteConfig config, YKS_AxisTrigger trigger);

/// <summary>
/// 绝对运动(事件触发)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <returns></returns>
YK_API YKM_MoveAbsoluteEvent(INT32 handle, UINT32 axisIndex, YKS_MoveAbsoluteConfig config);

/// <summary>
/// 相对运动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="distance">移动距离</param>
/// <returns></returns>
YK_API YKM_MoveRelative(INT32 handle, UINT32 axisIndex, double distance);

/// <summary>
/// 相对运动(带运动参数)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_MoveRelativeEx(INT32 handle, UINT32 axisIndex, YKS_MoveRelativeConfig config);

/// <summary>
/// 相对运动(条件触发)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <param name="trigger">触发条件</param>
/// <returns></returns>
YK_API YKM_MoveRelativeTrigger(INT32 handle, UINT32 axisIndex, YKS_MoveRelativeConfig config, YKS_AxisTrigger trigger);

/// <summary>
/// 相对运动(事件触发)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <returns></returns>
YK_API YKM_MoveRelativeEvent(INT32 handle, UINT32 axisIndex, YKS_MoveRelativeConfig config);

/// <summary>
/// 运动仿真
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <param name="result">规划结果</param>
/// <returns></returns>
YK_API YKM_MovePositionSim(INT32 handle, UINT32 axisIndex, YKS_MovePositionSimConfig config, YKS_MovePositionSimResult* result);

/// <summary>
/// 运动仿真，带变参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <param name="trigger">变参数配置</param>
/// <param name="result">规划结果</param>
/// <returns></returns>
YK_API YKM_MovePositionSimEx(INT32 handle, UINT32 axisIndex, YKS_MovePositionSimConfig config, YKS_MovePositionSimTrigger trigger, YKS_MovePositionSimResult* result);

/// <summary>
/// 速度运动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="velocity">新速度</param>
/// <param name="direction">运动方向</param>
/// <returns></returns>
YK_API YKM_MoveVelocity(INT32 handle, UINT32 axisIndex, double velocity, YKE_DIRECTION direction);

/// <summary>
/// 速度运动(带运动参数)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_MoveVelocityEx(INT32 handle, UINT32 axisIndex, YKS_MoveVelocityConfig config);

/// <summary>
/// 传送带运动
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_MoveConveyor(INT32 handle, UINT32 axisIndex, YKS_MoveConveyorConfig config);

/// <summary>
/// 写入单信号事件触发条件
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">保留，固定为0</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_WriteAxisEventOneSignal(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_TriggerArgOneSignal config);

/// <summary>
/// 写入双信号事件触发条件
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">保留，固定为0</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_WriteAxisEventTwoSignal(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_TriggerArgTwoSignal config);

/// <summary>
/// 速度运动(条件触发)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <param name="trigger">触发条件</param>
/// <returns></returns>
YK_API YKM_MoveVelocityTrigger(INT32 handle, UINT32 axisIndex, YKS_MoveVelocityConfig config, YKS_AxisTrigger trigger);

/// <summary>
/// 速度运动(事件触发)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">运动配置</param>
/// <returns></returns>
YK_API YKM_MoveVelocityEvent(INT32 handle, UINT32 axisIndex, YKS_MoveVelocityConfig config);

/// <summary>
/// 转矩运动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_MoveTorque(INT32 handle, UINT32 axisIndex, YKS_MoveTorqueConfig config);

/// <summary>
/// 修改目标位置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">新的位置</param>
/// <returns></returns>
YK_API YKM_OverridePosition(INT32 handle, UINT32 axisIndex, double position);

/// <summary>
/// 修改目标速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="velocity">新的速度</param>
/// <returns></returns>
YK_API YKM_OverrideVelocity(INT32 handle, UINT32 axisIndex, double velocity);

/// <summary>
/// 修改加速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="acc">新的加速度</param>
/// <returns></returns>
YK_API YKM_OverrideAcceleration(INT32 handle, UINT32 axisIndex, double acc);

/// <summary>
/// 修改减速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="dec">新的减速度</param>
/// <returns></returns>
YK_API YKM_OverrideDeceleration(INT32 handle, UINT32 axisIndex, double dec);

/// <summary>
/// 修改加速度过程的变加速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="jerk_acc">新的变加速度</param>
/// <returns></returns>
YK_API YKM_OverrideJerkAcc(INT32 handle, UINT32 axisIndex, double jerk_acc);

/// <summary>
/// 修改减速过程的变加速度
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="jerk_dec">新的变加速度</param>
/// <returns></returns>
YK_API YKM_OverrideJerkDec(INT32 handle, UINT32 axisIndex, double jerk_dec);

/// <summary>
/// 在指定位置生效新参数
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="motion">新的运动参数</param>
/// <param name="position">指定位置</param>
/// <returns></returns>
YK_API YKM_OverrideAtPosition(INT32 handle, UINT32 axisIndex, YKS_AxisProfileMotion motion, double position);
#pragma endregion

#pragma region PVT
/// <summary>
/// 写入PT数据，支持动态添加
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="data">配置</param>
/// <param name="size">数量</param>
/// <returns></returns>
YK_API YKM_WritePTData(INT32 handle, UINT32 axisIndex, YKS_PTData* data, UINT32 size);

/// <summary>
/// 写入PVT数据，支持动态添加
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="data">配置</param>
/// <param name="size">数量</param>
/// <returns></returns>
YK_API YKM_WritePVTData(INT32 handle, UINT32 axisIndex, YKS_PVTData* data, UINT32 size);

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
YK_API YKM_WritePVTSData(INT32 handle, UINT32 axisIndex, double start_velocity, double end_velocity, YKS_PVTSData* data, UINT32 size);

/// <summary>
/// 启动PT运动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_MovePVTStart(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 同时启动多轴的PT运动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisNum">轴数量, 最大32轴</param>
/// <param name="axisList">轴序号列表</param>
/// <returns></returns>
YK_API YKM_MoveMultiPVTStart(INT32 handle, UINT32 axisNum, UINT32 *axisList);

/// <summary>
/// 获取PVT缓冲区状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">返回状态</param>
/// <returns></returns>
YK_API YKM_ReadPVTStatus(INT32 handle, UINT32 axisIndex, YKS_PVTStatus* status);

/// <summary>
/// 清除PVT数据
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_ClearPVTData(INT32 handle, UINT32 axisIndex);
#pragma endregion

#pragma region 跟随运动
/// <summary>
/// 轴跟随其他单轴
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_FollowAxis1(INT32 handle, UINT32 axisIndex, YKS_FollowAxis1Config config);

/// <summary>
/// 轴跟随其他2轴
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_FollowAxis2(INT32 handle, UINT32 axisIndex, YKS_FollowAxis2Config config);

/// <summary>
/// 轴跟随UG数据
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_FollowUG(INT32 handle, UINT32 axisIndex, YKS_FollowUgConfig config);

/// <summary>
/// 轴跟随本地编码器
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_FollowEncoderPCI(INT32 handle, UINT32 axisIndex, YKS_FollowEncoderConfig config);

/// <summary>
///	轴跟随坐标系数据
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_FollowGroup(INT32 handle, UINT32 axisIndex, YKS_FollowGroupConfig config);
#pragma endregion

#pragma region 电子凸轮
/// <summary>
/// 写入凸轮配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">写入配置</param>
/// <returns></returns>
YK_API YKM_SetCamInConfig(INT32 handle, UINT32 axisIndex, YKS_CamInConfig config);

/// <summary>
/// 读取凸轮配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">返回配置</param>
/// <returns></returns>
YK_API YKM_GetCamInConfig(INT32 handle, UINT32 axisIndex, YKS_CamInConfig* config);

/// <summary>
/// 设置凸轮表数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="rowIndex">表行数</param>
/// <param name="data">数据</param>
/// <returns></returns>
YK_API YKM_SetCamTable(INT32 handle, UINT32 axisIndex, UINT32 rowIndex, YKS_CamTable data);

/// <summary>
/// 获取凸轮表的一行数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="rowIndex">表行号，从0开始</param>
/// <param name="data">行数据</param>
/// <returns></returns>
YK_API YKM_GetCamTable(INT32 handle, UINT32 axisIndex, UINT32 rowIndex, YKS_CamTable* data);

/// <summary>
/// 启动凸轮
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_StartCamIn(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 凸轮表求解，厂家使用
/// </summary>
/// <param name="table">输入数据</param>
/// <param name="size">数据数量</param>
/// <param name="result">解析结果</param>
/// <param name="type">曲线类型</param>
/// <returns></returns>
YK_API YKM_CalcCam(YKS_CamTable *table, UINT32 size, double *result, YKE_CAM_CURVE type);

/// <summary>
/// 获取凸轮表插值，厂家使用
/// </summary>
/// <param name="result">解析结果</param>
/// <param name="size">数据数量</param>
/// <param name="key">输入值</param>
/// <param name="value">输出值</param>
/// <param name="type">曲线类型</param>
/// <returns></returns>
YK_API YKM_GetCam(double *result, UINT32 size, double key, double* value, YKE_CAM_CURVE type);
#pragma endregion

#pragma region 多轴同步运动
/// <summary>
/// 直线插补，相对模式
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="config">参数</param>
/// <returns></returns>
YK_API YKM_LinearInterpolationRelative(INT32 handle, UINT32 channel, YKS_LinearInterpolationRelativeConfig config);

/// <summary>
/// 直线插补，绝对模式
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="config">参数</param>
/// <returns></returns>
YK_API YKM_LinearInterpolationAbsolute(INT32 handle, UINT32 channel, YKS_LinearInterpolationAbsoluteConfig config);

/// <summary>
/// 多轴直线同步运动，绝对模式
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="config">参数</param>
/// <returns></returns>
YK_API YKM_LinearSyncAbsolute(INT32 handle, UINT32 channel, YKS_LinearSyncAbsoluteConfig config);

/// <summary>
/// 多轴直线同步运动，相对模式
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="config">参数</param>
/// <returns></returns>
YK_API YKM_LinearSyncRelative(INT32 handle, UINT32 channel, YKS_LinearSyncRelativeConfig config);

/// <summary>
/// 圆弧运动，相对模式
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="config">参数</param>
/// <returns></returns>
YK_API YKM_CircularInterpolationRelative(INT32 handle, UINT32 channel, YKS_CircularInterpolationRelativeConfig config);

/// <summary>
/// 圆弧运动，绝对模式
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="config">参数</param>
/// <returns></returns>
YK_API YKM_CircularInterpolationAbsolute(INT32 handle, UINT32 channel, YKS_CircularInterpolationAbsoluteConfig config);

/// <summary>
/// 停止多轴联动
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="dec_sel">保留</param>
/// <returns></returns>
YK_API YKM_StopMultiAxis(INT32 handle, UINT32 channel, YKE_STOP_DEC dec_sel);

/// <summary>
/// 获取多轴联动状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道序号 0~127</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadMultiAxisStatus(INT32 handle, UINT32 channel, YKS_MultiAxisStatus* status);

/// <summary>
/// 多轴同时启动，绝对模式
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_MoveSyncAbsolute(INT32 handle, YKS_SyncStartConfig config);
#pragma endregion

#pragma region 坐标系运动
/// <summary>
/// 设置坐标系参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetGroupProfile(INT32 handle, UINT32 groupIndex, YKS_GroupProfile config);

/// <summary>
/// 获取坐标系参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetGroupProfile(INT32 handle, UINT32 groupIndex, YKS_GroupProfile* config);

/// <summary>
/// 坐标系轴绑定,2到32轴
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_InitGroup(INT32 handle, UINT32 groupIndex, YKS_GroupConfig config);

/// <summary>
/// 获取坐标系绑定配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetGroupConfig(INT32 handle, UINT32 groupIndex, YKS_GroupConfig* config);

/// <summary>
/// 将轴从坐标系移出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <returns></returns>
YK_API YKM_DeInitGroup(INT32 handle, UINT32 groupIndex);

/// <summary>
/// 写CNC通道配置，在坐标系初始化前调用生效
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">CNC通道配置</param>
/// <returns></returns>
YK_API YKM_SetCncProfile(INT32 handle, UINT32 groupIndex, YKS_CncProfile config);

/// <summary>
/// 读CNC通道配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">CNC通道配置</param>
/// <returns></returns>
YK_API YKM_GetCncProfile(INT32 handle, UINT32 groupIndex, YKS_CncProfile* config);

/// <summary>
/// 获取坐标系基础状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="status">状态值</param>
/// <returns></returns>
YK_API YKM_ReadGroupStatusBase(INT32 handle, UINT32 groupIndex, YKS_GroupStatusBase* status);

/// <summary>
/// 获取坐标系CNC状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="status">状态值</param>
/// <returns></returns>
YK_API YKM_ReadGroupStatusCnc(INT32 handle, UINT32 groupIndex, YKS_GroupStatusCnc* status);

/// <summary>
/// 清除坐标系报警
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <returns></returns>
YK_API YKM_ClearGroupWarn(INT32 handle, UINT32 groupIndex);

/// <summary>
/// 停止坐标系运动
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="dec_sel">停止减速度选择</param>
/// <returns></returns>
YK_API YKM_StopGroup(INT32 handle, UINT32 groupIndex, YKE_STOP_DEC dec_sel);

/// <summary>
/// 启动坐标系运动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <returns></returns>
YK_API YKM_StartGroup(INT32 handle, UINT32 groupIndex);

/// <summary>
/// 暂停坐标系运行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <returns></returns>
YK_API YKM_PauseGroup(INT32 handle, UINT32 groupIndex);

/// <summary>
/// 坐标系内直线插补，绝对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveLinearAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveLinearAbsoluteConfig config);

/// <summary>
/// 坐标系内直线插补，相对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveLinearRelative(INT32 handle, UINT32 groupIndex, YKS_MoveLinearRelativeConfig config);

/// <summary>
/// 坐标系内螺旋插补，绝对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveHelixAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveHelixAbsoluteConfig config);

/// <summary>
/// 坐标系内螺旋插补，相对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveHelixRelative(INT32 handle, UINT32 groupIndex, YKS_MoveHelixRelativeConfig config);

/// <summary>
/// 坐标系内圆弧插补，绝对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveCircularAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveCircularAbsoluteConfig config);

/// <summary>
/// 坐标系内圆弧插补，相对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveCircularRelative(INT32 handle, UINT32 groupIndex, YKS_MoveCircularRelativeConfig config);

/// <summary>
/// Cardinal样条插补，相对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveCardinalRelative(INT32 handle, UINT32 groupIndex, YKS_MoveCardinalRelativeConfig config);

/// <summary>
/// Cardinal样条插补，绝对模式
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置参数</param>
/// <returns></returns>
YK_API YKM_MoveCardinalAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveCardinalAbsoluteConfig config);

/// <summary>
/// 坐标系内数字输出，参考下一段运动行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">输出配置</param>
/// <returns></returns>
YK_API YKM_GroupDigitalOutput(INT32 handle, UINT32 groupIndex, YKS_GroupDoConfig config);

/// <summary>
/// 坐标系内PWM输出，参考下一段运动行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">PWM输出配置</param>
/// <returns></returns>
YK_API YKM_GroupPwmOutput(INT32 handle, UINT32 groupIndex, YKS_GroupPwmConfig config);

/// <summary>
/// 坐标系内写入PDO，参考下一段运动行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">PDO配置</param>
/// <returns></returns>
YK_API YKM_GroupWritePDO(INT32 handle, UINT32 groupIndex, YKS_GroupWritePdoConfig config);

/// <summary>
/// 坐标系内写入通用数据寄存器，参考下一段运动行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">VD配置</param>
/// <returns></returns>
YK_API YKM_GroupWriteRegister(INT32 handle, UINT32 groupIndex, YKS_GroupWriteRegisterConfig config);

/// <summary>
/// 坐标系内启动事件，参考下一段运动行
/// </summary>
/// <param name="handle"></param>
/// <param name="groupIndex"></param>
/// <param name="config"></param>
/// <returns></returns>
YK_API YKM_GroupWriteEvent(INT32 handle, UINT32 groupIndex, YKS_GroupWriteEventConfig config);

/// <summary>
/// Cardinal样条插补参数设置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupWriteTensive(INT32 handle, UINT32 groupIndex, YKS_GroupCardinalConfig config);

/// <summary>
/// 坐标系外轴相对运动配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupMoveRelative(INT32 handle, UINT32 groupIndex, YKS_GroupMoveRelativeConfig config);

/// <summary>
/// 坐标系外轴绝对运动配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupMoveAbsolute(INT32 handle, UINT32 groupIndex, YKS_GroupMoveAbsoluteConfig config);

/// <summary>
/// 坐标系内延时
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">延时配置</param>
/// <returns></returns>
YK_API YKM_GroupDelay(INT32 handle, UINT32 groupIndex, YKS_GroupDelayConfig config);

/// <summary>
/// 坐标系内等待数字输入
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">数字输入配置</param>
/// <returns></returns>
YK_API YKM_GroupWaitDigitalInput(INT32 handle, UINT32 groupIndex, YKS_GroupDigitalInputConfig config);

/// <summary>
/// 坐标系内等待外轴完成
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">外轴配置</param>
/// <returns></returns>
YK_API YKM_GroupWaitAxis(INT32 handle, UINT32 groupIndex, YKS_GroupWaitAxisConfig config);

/// <summary>
/// 坐标系内等待PDO数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">PDO配置</param>
/// <returns></returns>
YK_API YKM_GroupWaitPdo(INT32 handle, UINT32 groupIndex, YKS_GroupWaitPdoConfig config);

/// <summary>
/// 坐标系内等待通用数据寄存器
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">寄存器配置</param>
/// <returns></returns>
YK_API YKM_GroupWaitRegister(INT32 handle, UINT32 groupIndex, YKS_GroupWaitRegisterConfig config);

/// <summary>
/// 坐标系内等待事件信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">事件配置</param>
/// <returns></returns>
YK_API YKM_GroupWaitEvent(INT32 handle, UINT32 groupIndex, YKS_GroupWaitEventConfig config);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">Mark配置</param>
/// <returns></returns>
YK_API YKM_GroupTransMarkOn(INT32 handle, UINT32 groupIndex, YKS_GroupTransMarkConfig config);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <returns></returns>
YK_API YKM_GroupTransMarkOff(INT32 handle, UINT32 groupIndex);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系编号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupAddiXYOn(INT32 handle, UINT32 groupIndex, YKS_GroupAddiXYConfig config);

/// <summary>
/// 保留
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系编号</param>
/// <returns></returns>
YK_API YKM_GroupAddiXYOff(INT32 handle, UINT32 groupIndex);

/// <summary>
/// 视觉Mark转换
/// </summary>
/// <param name="ptRef">图纸坐标</param>
/// <param name="ptReal">实际坐标</param>
/// <param name="config">转换结果</param>
/// <returns></returns>
YK_API YKM_CalcMark(double* ptRef, double* ptReal, YKS_GroupTransMarkConfig* config);
#pragma endregion

#pragma region CNC控制
/// <summary>
/// 写G代码命令
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">G代码</param>
/// <returns></returns>
YK_API YKM_GroupWriteGCode(INT32 handle, UINT32 groupIndex, YKS_CncGCode config);

/// <summary>
/// 加载NC文件进行加工
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="filename">文件全路径</param>
/// <returns></returns>
YK_API YKM_GroupLoadFile(INT32 handle, UINT32 groupIndex, char* filename);

/// <summary>
/// 基于控制点的AKIMA样条配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncASpline(INT32 handle, UINT32 groupIndex, YKS_CncASplineConfig config);

/// <summary>
/// 关闭样条平滑
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="mark">用户标记</param>
/// <returns></returns>
YK_API YKM_GroupCncSplineClose(INT32 handle, UINT32 groupIndex, UINT32 mark);

/// <summary>
/// CNC轮廓角偏差平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncContourDev(INT32 handle, UINT32 groupIndex, YKS_CncContourDevConfig config);

/// <summary>
/// CNC轮廓角距离平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncContourDist(INT32 handle, UINT32 groupIndex, YKS_CncContourDistConfig config);

/// <summary>
/// CNC动态轮廓优化平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncContourDistSoft(INT32 handle, UINT32 groupIndex, YKS_CncContourDistSoftConfig config);

/// <summary>
/// CNC进给主轴动态轮廓优化平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config"></param>
/// <returns></returns>
YK_API YKM_GroupCncContourDistMaster(INT32 handle, UINT32 groupIndex, YKS_CncContourDistMasterConfig config);

/// <summary>
/// CNC插入点平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncContourPos(INT32 handle, UINT32 groupIndex, YKS_CncContourPosConfig config);

/// <summary>
/// CNC完整轮廓动态优化平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncContourPtp(INT32 handle, UINT32 groupIndex, YKS_CncContourPtpConfig config);

/// <summary>
/// 关闭轮廓平滑
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="mark">用户标记</param>
/// <returns></returns>
YK_API YKM_GroupCncContourClose(INT32 handle, UINT32 groupIndex, UINT32 mark);

/// <summary>
/// HSC_B样条平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncHscB(INT32 handle, UINT32 groupIndex, YKS_CncHscBConfig config);

/// <summary>
/// HSC_Surface平滑配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncHscS(INT32 handle, UINT32 groupIndex, YKS_CncHscSConfig config);

/// <summary>
/// HSC_PCS1平滑参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncHscPcs1(INT32 handle, UINT32 groupIndex, YKS_CncHscPcs1Config config);

/// <summary>
/// HSC_PCS2平滑参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GroupCncHscPcs2(INT32 handle, UINT32 groupIndex, YKS_CncHscPcs2Config config);

/// <summary>
/// 关闭HSC平滑
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="groupIndex">坐标系序号</param>
/// <param name="mark">用户标记</param>
/// <returns></returns>
YK_API YKM_GroupCncHscClose(INT32 handle, UINT32 groupIndex, UINT32 mark);

/// <summary>
/// 读CNC的轴参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="para_name">参数名称</param>
/// <param name="size_name">参数数据缓冲区大小</param>
/// <returns></returns>
YK_API YKM_ReadCncParaCmd(INT32 handle, UINT32 axisIndex, char* para_name, UINT32 size_name);

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
YK_API YKM_WriteCncParaCmd(INT32 handle, UINT32 axisIndex, char* para_name, UINT32 size_name, char* para_value, UINT32 size_value);

/// <summary>
/// 读CNC参数操作状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="status">返回状态</param>
/// <returns></returns>
YK_API YKM_ReadCncParaStatus(INT32 handle, UINT32 axisIndex, YKS_CncParaStatus* status);
#pragma endregion

#pragma region 探针
/// <summary>
/// 启动硬件探针
/// 总线轴探针参数在总线节点中设置
/// 脉冲轴探针参数在脉冲节点中设置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号 (0~1)</param>
/// <returns></returns>
YK_API YKM_StartProbeHard(INT32 handle, UINT32 axisIndex, UINT32 channel);

/// <summary>
/// 停止硬件探针
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号 (0~1)</param>
/// <returns></returns>
YK_API YKM_StopProbeHard(INT32 handle, UINT32 axisIndex, UINT32 channel);

/// <summary>
/// 获取硬件探针状态及值
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号 (0~1)</param>
/// <param name="status">返回状态 0=未完成 1=完成</param>
/// <param name="position">返回的探针位置</param>
/// <returns></returns>
YK_API YKM_ReadProbeStatusHard(INT32 handle, UINT32 axisIndex, UINT32 channel, UINT32* status, double* position);

/// <summary>
/// 获取轴软件探针配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号(0~3)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetAxisProbeConfigSoft(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisProbeConfigSoft* config);

/// <summary>
/// 设置轴软件探针配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号(0~3)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetAxisProbeConfigSoft(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisProbeConfigSoft config);

/// <summary>
/// 轴软件探针状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号(0~3)</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisProbeStatusSoft(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisProbeStatusSoft* status);

/// <summary>
/// 轴软件探针启动
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号(0~3)</param>
/// <returns></returns>
YK_API YKM_StartAxisProbeSoft(INT32 handle, UINT32 axisIndex, UINT32 channel);

/// <summary>
/// 轴软件探针停止
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="channel">通道号(0~3)</param>
/// <returns></returns>
YK_API YKM_StopAxisProbeSoft(INT32 handle, UINT32 axisIndex, UINT32 channel);
#pragma endregion

#pragma region 控制事件
/// <summary>
/// 单IO触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">信号源</param>
/// <returns></returns>
YK_API YKM_WriteEventInputOneSignal(INT32 handle, UINT32 channel, YKS_TriggerArgOneSignal input);

/// <summary>
/// 双IO触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">信号源</param>
/// <returns></returns>
YK_API YKM_WriteEventInputTwoSignal(INT32 handle, UINT32 channel, YKS_TriggerArgTwoSignal input);

/// <summary>
/// 轴位置触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">配置</param>
/// <returns></returns>
YK_API YKM_WriteEventInputAxisPosition(INT32 handle, UINT32 channel, YKS_TriggerArgAxisPosition input);

/// <summary>
/// 轴时间触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">配置</param>
/// <returns></returns>
YK_API YKM_WriteEventInputAxisTime(INT32 handle, UINT32 channel, YKS_TriggerArgAxisTime input);

/// <summary>
/// 轴速度触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">信号源</param>
/// <returns></returns>
YK_API YKM_WriteEventInputAxisVelocity(INT32 handle, UINT32 channel, YKS_TriggerArgAxisVelocity input);

/// <summary>
/// 轴转矩触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">信号源</param>
/// <returns></returns>
YK_API YKM_WriteEventInputAxisTorque(INT32 handle, UINT32 channel, YKS_TriggerArgAxisTorque input);

/// <summary>
/// 从站PDO触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">信号源</param>
/// <returns></returns>
YK_API YKM_WriteEventInputSlavePDO(INT32 handle, UINT32 channel, YKS_TriggerArgSlavePDO input);

/// <summary>
/// 编码器触发输入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_EVENT_NUM)</param>
/// <param name="input">信号源</param>
/// <returns></returns>
YK_API YKM_WriteEventInputEncoder(INT32 handle, UINT32 channel, YKS_TriggerArgEncoder input);

/// <summary>
/// 触发输出:位参数写入
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputOneSignal(INT32 handle, UINT32 channel, YKS_TriggerOutputOneBit output);

/// <summary>
/// 触发输出:停止轴
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputStopAxis(INT32 handle, UINT32 channel, YKS_TriggerOutputStopAxis output);

/// <summary>
/// 触发输出:启动坐标系
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputStartGroup(INT32 handle, UINT32 channel, YKS_TriggerOutputStartGroup output);

/// <summary>
/// 触发输出:启动单轴
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputStartAxis(INT32 handle, UINT32 channel, YKS_TriggerOutputStartAxis output);

/// <summary>
/// 触发输出:软急停
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputSoftEmgStop(INT32 handle, UINT32 channel, YKS_TriggerOutputSoftEmgStop output);

/// <summary>
/// 触发输出:写PDO
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">通道号</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputSlavePDO(INT32 handle, UINT32 channel, YKS_TriggerOutputSlavePDO output);

/// <summary>
/// 触发输出:启动多轴联动
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <param name="motion">运动配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputMultiAxis(INT32 handle, UINT32 channel, YKS_TriggerOutputStartMultiAxis output, YKS_LinearSyncAbsoluteConfig motion);

/// <summary>
/// 触发输出:写目标转矩
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputTargetTorque(INT32 handle, UINT32 channel, YKS_TriggerOutputTargetTorque output);

/// <summary>
/// 触发输出:延时
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputDelayMs(INT32 handle, UINT32 channel, YKS_TriggerOutputDelayMs output);

/// <summary>
/// 触发输出:写通用数据寄存器
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_EVENT_NUM)</param>
/// <param name="output">输出配置</param>
/// <returns></returns>
YK_API YKM_WriteEventOutputDataReg(INT32 handle, UINT32 channel, YKS_TriggerOutputDataReg output);

/// <summary>
/// 启动事件
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,1023)</param>
/// <returns></returns>
YK_API YKM_EnableEvent(INT32 handle, UINT32 channel);

/// <summary>
/// 禁用事件
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,1023)</param>
/// <returns></returns>
YK_API YKM_DisableEvent(INT32 handle, UINT32 channel);

/// <summary>
/// 获取事件状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="status">返回的状态</param>
/// <param name="channel">通道[0,1023)</param>
/// <returns></returns>
YK_API YKM_ReadEventStatus(INT32 handle, UINT32 channel, YKS_EventStatus* status);
#pragma endregion

#pragma region PCI硬件卡
/// <summary>
/// 获取PCI控制数量
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="num">返回数量</param>
/// <returns></returns>
YK_API YKM_GetCardNumPCI(INT32 handle, UINT32* num);

/// <summary>
/// 获取PCI控制卡信息
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetCardConfigPCI(INT32 handle, UINT32 card_index, YKS_CardConfigPCI* config);

/// <summary>
/// 获取脉冲轴的IO状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="status">IO状态</param>
/// <returns></returns>
YK_API YKM_ReadAxisStatusPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisStausPCI* status);

/// <summary>
/// 设置脉冲轴的驱动Ready信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchDrvReadyPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

/// <summary>
/// 获取脉冲轴的驱动Ready信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchDrvReadyPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

/// <summary>
/// 设置脉冲轴的驱动报警信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchDrvWarnPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

/// <summary>
/// 获取脉冲轴的驱动报警信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchDrvWarnPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

/// <summary>
/// 设置脉冲轴的驱动到位信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchDrvInpPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

/// <summary>
/// 获取脉冲轴的驱动到位信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchDrvInpPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

/// <summary>
/// 设置脉冲轴的驱动使能信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchDrvEnablePCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

/// <summary>
/// 获取脉冲轴的驱动使能信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchDrvEnablePCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

/// <summary>
/// 设置脉冲轴的驱动复位信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetSwitchDrvResetPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

/// <summary>
/// 获取脉冲轴的驱动复位信号
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetSwitchDrvResetPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

/// <summary>
/// 参数配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">编码器序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetEncoderConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_EncoderConfig config);

/// <summary>
/// 获取配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">编码器序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetEncoderConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_EncoderConfig* config);

/// <summary>
/// 设置编码器的当前值
/// Xmen:只能设0
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">编码器序号</param>
/// <param name="value">当前值</param>
/// <returns></returns>
YK_API YKM_WriteEncoderValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, INT32 value);

/// <summary>
/// 获取编码器的当前值
/// Xmen:只能设0
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">编码器序号</param>
/// <param name="value">当前值</param>
/// <returns></returns>
YK_API YKM_ReadEncoderValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, INT32* value);

/// <summary>
/// 编码器开始计数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">编码器序号</param>
/// <returns></returns>
YK_API YKM_StartEncoderPCI(INT32 handle, UINT32 card_index, UINT32 channel);

/// <summary>
/// 编码器停止计数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">编码器序号</param>
/// <returns></returns>
YK_API YKM_StopEncoderPCI(INT32 handle, UINT32 card_index, UINT32 channel);

/// <summary>
/// 比较器参数配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">比较器序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetCompareConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareConfig config);

/// <summary>
/// 获取比较器参数配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">比较器序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetCompareConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareConfig* config);

/// <summary>
/// 设置比较值
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">比较器序号</param>
/// <param name="itemdata">比较配置，内部含有512个缓冲区</param>
/// <returns></returns>
YK_API YKM_SetCompareValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareItemData itemdata);

/// <summary>
/// 获取比较器状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">比较器序号</param>
/// <param name="status">返回值</param>
/// <returns></returns>
YK_API YKM_ReadCompareStatusPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareStatus* status);

/// <summary>
/// 比较器开始
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">比较器序号</param>
/// <returns></returns>
YK_API YKM_StartComparePCI(INT32 handle, UINT32 card_index, UINT32 channel);

/// <summary>
/// 停止比较器
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">比较器序号</param>
/// <returns></returns>
YK_API YKM_StopComparePCI(INT32 handle, UINT32 card_index, UINT32 channel);

/// <summary>
/// 锁存器参数配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">锁存器序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetCaptureConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CaptureConfig config);

/// <summary>
/// 获取锁存器参数配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">锁存器序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetCaptureConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CaptureConfig* config);

/// <summary>
/// 获取锁存器的状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">锁存器序号</param>
/// <param name="status">0:无数据 1:有数据</param>
/// <returns></returns>
YK_API YKM_ReadCaptureStatusPCI(INT32 handle, UINT32 card_index, UINT32 channel, UINT32* status);

/// <summary>
/// 获取锁存器的当前值
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">锁存器序号</param>
/// <param name="value">锁存值</param>
/// <returns></returns>
YK_API YKM_ReadCaptureValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, INT32* value);

/// <summary>
/// 锁存器开始
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">锁存器序号</param>
/// <returns></returns>
YK_API YKM_StartCapturePCI(INT32 handle, UINT32 card_index, UINT32 channel);

/// <summary>
/// 停止锁存器
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">锁存器序号</param>
/// <returns></returns>
YK_API YKM_StopCapturePCI(INT32 handle, UINT32 card_index, UINT32 channel);

/// <summary>
/// 启动PWM输出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">通道号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_StartPwmPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_PwmConfig config);

/// <summary>
/// 停止PWM输出
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="card_index">卡序号</param>
/// <param name="channel">通道号</param>
/// <returns></returns>
YK_API YKM_StopPwmPCI(INT32 handle, UINT32 card_index, UINT32 channel);
#pragma endregion

#pragma region 机械补偿
/// <summary>
/// 设置间隙补偿参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetBacklashConfig(INT32 handle, UINT32 axisIndex, YKS_BacklashConfig config);

/// <summary>
/// 获取间隙补偿参数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetBacklashConfig(INT32 handle, UINT32 axisIndex, YKS_BacklashConfig* config);

/// <summary>
/// 启用间隙补偿
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_EnableBacklash(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 禁用间隙补偿
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_DisableBacklash(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 设置螺距补偿配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetPitchError1DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError1DConfig config);

/// <summary>
/// 获取螺距补偿配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetPitchError1DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError1DConfig* config);

/// <summary>
/// 设置螺距补偿数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="pos_data">正向补偿数据</param>
/// <param name="neg_data">负向补偿数据</param>
/// <param name="size">单方向数据数量</param>
/// <returns></returns>
YK_API YKM_SetPitchError1DData(INT32 handle, UINT32 axisIndex, double *pos_data, double *neg_data, UINT32 size);

/// <summary>
/// 获取螺距补偿数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="pos_data">正向补偿数据</param>
/// <param name="neg_data">负向补偿数据</param>
/// <param name="size">单方向数据数量</param>
/// <returns></returns>
YK_API YKM_GetPitchError1DData(INT32 handle, UINT32 axisIndex, double *pos_data, double *neg_data, UINT32 size);

/// <summary>
/// 启用螺距补偿
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_EnablePitchError1D(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 禁用螺距补偿
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_DisablePitchError1D(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 设置二维补偿配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetPitchError2DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError2DConfig config);

/// <summary>
/// 获取二维补偿配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetPitchError2DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError2DConfig* config);

/// <summary>
/// 设置二维补偿数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="data">数据,先X后Y的排列方式</param>
/// <param name="size">缓冲区大小</param>
/// <returns></returns>
YK_API YKM_SetPitchError2DData(INT32 handle, UINT32 axisIndex, double *data, UINT32 size);

/// <summary>
/// 获取二维补偿数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="data">数据</param>
/// <param name="size">缓冲区大小</param>
/// <returns></returns>
YK_API YKM_GetPitchError2DData(INT32 handle, UINT32 axisIndex, double *data, UINT32 size);

/// <summary>
/// 启用二维补偿
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_EnablePitchError2D(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 禁用二维补偿
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="axisIndex">轴序号</param>
/// <returns></returns>
YK_API YKM_DisablePitchError2D(INT32 handle, UINT32 axisIndex);

/// <summary>
/// 设置圆形区域配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetCircleZoneConfig(INT32 handle, UINT32 channel, YKS_CircleZoneConfig config);

/// <summary>
/// 获取圆形区域配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetCircleZoneConfig(INT32 handle, UINT32 channel, YKS_CircleZoneConfig* config);

/// <summary>
/// 启用圆形区域保护
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
/// <returns></returns>
YK_API YKM_EnableCircleZone(INT32 handle, UINT32 channel);

/// <summary>
/// 禁用用圆形区域保护
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
/// <returns></returns>
YK_API YKM_DisableCircleZone(INT32 handle, UINT32 channel);

/// <summary>
/// 读取圆形区域状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_CIRCLE_ZONE_NUM)</param>
/// <param name="status">状态</param>
/// <returns></returns>
YK_API YKM_ReadCircleZoneStatus(INT32 handle, UINT32 channel, YKS_CircleZoneStatus* status);
#pragma endregion

#pragma region 调试用
/// <summary>
/// 设置示波器配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_SetOscConfig(INT32 handle, UINT32 oscIndex, YKS_OscConfig config);

/// <summary>
/// 获取示波器配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_GetOscConfig(INT32 handle, UINT32 oscIndex, YKS_OscConfig* config);

/// <summary>
/// 设置示波器采集内容
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <param name="itemIndex">采集对象序号[0,YKE_OSC_ITEM_NUM)</param>
/// <param name="item">采集配置</param>
/// <returns></returns>
YK_API YKM_SetOscItem(INT32 handle, UINT32 oscIndex, UINT32 itemIndex, YKS_OscItem item);

/// <summary>
/// 获取示波器采集内容
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM</param>
/// <param name="itemIndex">采集对象序号[0,YKE_OSC_ITEM_NUM)</param>
/// <param name="item">采集配置</param>
/// <returns></returns>
YK_API YKM_GetOscItem(INT32 handle, UINT32 oscIndex, UINT32 itemIndex, YKS_OscItem* item);

/// <summary>
/// 清除示波器所有通道配置
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <returns></returns>
YK_API YKM_ClearOscItem(INT32 handle, UINT32 oscIndex);

/// <summary>
/// 读示波器状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM))</param>
/// <param name="status">返回的状态</param>
/// <returns></returns>
YK_API YKM_ReadOscStatus(INT32 handle, UINT32 oscIndex, YKS_OscStatus* status);

/// <summary>
/// 读示波器采集数据
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <param name="buffer">缓冲区地址</param>
/// <param name="size">缓冲区尺寸</param>
/// <param name="ret_size">返回的数据个数</param>
/// <returns></returns>
YK_API YKM_ReadOscData(INT32 handle, UINT32 oscIndex, double *buffer, UINT32 size, UINT32* ret_size);

/// <summary>
/// 启动示波器采集
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <returns></returns>
YK_API YKM_StartOsc(INT32 handle, UINT32 oscIndex);

/// <summary>
/// 停止示波器采集
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <returns></returns>
YK_API YKM_StopOsc(INT32 handle, UINT32 oscIndex);

/// <summary>
/// 示波器手动触发
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="oscIndex">示波器序号[0,YKE_OSC_NUM)</param>
/// <returns></returns>
YK_API YKM_TrigOsc(INT32 handle, UINT32 oscIndex);

/// <summary>
/// 写轴规划位置，厂家调试用
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="magic"></param>
/// <param name="axisIndex">轴序号</param>
/// <param name="position">位置</param>
/// <returns></returns>
YK_API YKM_WriteCommandPosition(INT32 handle, UINT32 magic, UINT32 axisIndex, double position);
#pragma endregion

#pragma region NTF
/// <summary>
/// 加载控制台类型的.NET应用程序到实时系统中运行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="exe_name">文件名及路径</param>
/// <returns></returns>
YK_API YKM_LoadNTFDotNet(INT32 handle, YKE_NODE master, char* exe_name);

/// <summary>
/// 检查NTF(C#)程序状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="exe_name">文件名，不包含路径</param>
/// <param name="status">返回状态 FALSE=未启动 TRUE=已启动</param>
/// <returns></returns>
YK_API YKM_CheckNTFDotNet(INT32 handle, YKE_NODE master, char* exe_name, YKE_BOOL* status);

/// <summary>
/// 加载控制台类型的.rta应用程序到实时系统中运行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="file_name">路径及文件名</param>
/// <param name="para">程序参数</param>
/// <returns></returns>
YK_API YKM_LoadRtaApp(INT32 handle, YKE_NODE master, char* file_name, char* para);

/// <summary>
/// 检查RTA程序状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="rta_name">程序名称</param>
/// <param name="status">返回状态 FALSE=未启动 TRUE=已启动</param>
/// <returns></returns>
YK_API YKM_CheckRtaApp(INT32 handle, YKE_NODE master, char* rta_name, YKE_BOOL* status);

/// <summary>
/// 强制关闭RTA程序
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="master">主站选择</param>
/// <param name="rta_name">程序名称</param>
/// <param name="status">返回状态 FALSE=未关闭 TRUE=已关闭</param>
/// <returns></returns>
YK_API YKM_KillRtaApp(INT32 handle, YKE_NODE master, char* rta_name, YKE_BOOL* status);

/// <summary>
/// 获取NTF打印日志，每次最多返回1行
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="node">节点</param>
/// <param name="buff">缓冲区地址</param>
/// <param name="size">缓冲区大小</param>
/// <param name="count">返回的字符数量</param>
/// <returns></returns>
YK_API YKM_ReadNTFLog(INT32 handle, YKE_NODE node, char* buff, UINT32 size, UINT32* count);

/// <summary>
/// 设置API缓冲区回调函数
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="callback">回调函数句柄</param>
/// <param name="size"></param>
/// <returns></returns>
YK_API YKM_SetApiBufferCallBack(INT32 handle, UINT64* callback, UINT32 size);

/// <summary>
/// API缓冲区开始记录
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号[0,YKE_API_BUFFER_NUM)</param>
/// <returns></returns>
YK_API YKM_StartApiBufferRecord(INT32 handle, UINT32 channel);

/// <summary>
/// API缓冲区停止记录
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号通道号[0,YKE_API_BUFFER_NUM)</param>
/// <returns></returns>
YK_API YKM_EndApiBufferRecord(INT32 handle, UINT32 channel);

/// <summary>
/// 设置API缓冲区Mark标记
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道号通道号[0,YKE_API_BUFFER_NUM)</param>
/// <param name="mark">用户标记</param>
/// <returns></returns>
YK_API YKM_SetApiBufferMark(INT32 handle, UINT32 channel, UINT32 mark);
#pragma endregion

#pragma region CoppeliaSim接口
/// <summary>
/// 连接Coppelia服务器
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="ipAddress">IP地址</param>
/// <param name="port">端口</param>
/// <returns></returns>
YK_API YKM_SimConnect(INT32 handle, char* ipAddress, UINT32 port);

/// <summary>
/// 设置关节
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="jointIndex">关节序号</param>
/// <param name="jointName">关节名称</param>
/// <param name="axisIndex">轴序号</param>
/// <param name="axisType">轴类型</param>
/// <returns></returns>
YK_API YKM_SimJointConfig(INT32 handle, UINT32 jointIndex, char* jointName, UINT32 axisIndex, YKE_AXIS_SIM_TYPE axisType);

/// <summary>
/// 仿真启动
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SimStart(INT32 handle);

/// <summary>
/// 仿真停止
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SimStop(INT32 handle);

/// <summary>
/// 断开连接
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <returns></returns>
YK_API YKM_SimDisconnect(INT32 handle);
#pragma endregion

#pragma region 等待事件
/// <summary>
/// 等待轴信号(阻塞式)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_WaitAxis(INT32 handle, UINT32 channel, YKS_WaitAxis config);

/// <summary>
/// 等待数字输入(阻塞式)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_WaitDigitalInput(INT32 handle, UINT32 channel, YKS_WaitDigitalInput config);

/// <summary>
/// 等待事件信号(阻塞式)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
/// <param name="config">配置</param>
/// <returns></returns>
YK_API YKM_WaitEvent(INT32 handle, UINT32 channel, YKS_WaitEvent config);

/// <summary>
/// 延时等待(阻塞式)
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
/// <param name="time">延时时间(ms)</param>
/// <returns></returns>
YK_API YKM_WaitSleepMs(INT32 handle, UINT32 channel, double time);

/// <summary>
/// 复位等待事件
/// 支持API缓冲区
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
/// <returns></returns>
YK_API YKM_WaitReset(INT32 handle, UINT32 channel);

/// <summary>
/// 获取等待状态
/// </summary>
/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
/// <param name="channel">通道[0,YKE_WAIT_NUM)</param>
/// <param name="status">返回状态</param>
/// <returns></returns>
YK_API YKM_ReadWaitStatus(INT32 handle, UINT32 channel, YKS_WaitStatus *status);
#pragma endregion


#endif
