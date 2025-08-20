using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;
using YKCat2;

namespace YKCat2
{
	#region 数据类型
	#endregion

	#region 枚举定义
	/// <summary>
	/// 函数返回值定义
	/// </summary>
	public enum NEE_RESULT_CODE
	{
		/// <summary>
		/// 正常
		/// </summary>
		[Description("正常")]
		NEE_RET_OK = 0,

		/// <summary>
		/// 未成功调用NEM_SysLoadLib函数
		/// </summary>
		[Description("未成功调用NEM_SysLoadLib函数")]
		NEE_RET_LOAD = 10000,

		/// <summary>
		/// 打开共享内存失败
		/// </summary>
		[Description("打开共享内存失败")]
		NEE_RET_OPEN_MEM = 10010,

		/// <summary>
		/// 内存接口定义不匹配
		/// </summary>
		[Description("内存接口定义不匹配")]
		NEE_RET_MATCH = 10011,

		/// <summary>
		/// 不支持的功能
		/// </summary>
		[Description("不支持的功能")]
		NEE_RET_FUN = 10012,

		/// <summary>
		/// 无效的指令参数
		/// </summary>
		[Description("无效的指令参数")]
		NEE_RET_INS_PARA = 10020,

		/// <summary>
		/// 打开事件失败
		/// </summary>
		[Description("打开事件失败")]
		NEE_RET_OPEN_EVENT = 10100,

		/// <summary>
		/// 当前运动已在运动
		/// </summary>
		[Description("当前运动已在运动")]
		NEE_RET_ACTIVE = 10200,

		/// <summary>
		/// 动态内存分配失败
		/// </summary>
		[Description("动态内存分配失败")]
		NEE_RET_DYNC_MEM_OV = 10300,

		/// <summary>
		/// API缓冲区通道未初始化
		/// </summary>
		[Description("API缓冲区通道未初始化")]
		NEE_RET_API_BUFFER_INIT = 10400,

		/// <summary>
		/// API缓冲区尺寸不能修改
		/// </summary>
		[Description("API缓冲区尺寸不能修改")]
		NEE_RET_API_BUFFER_SIZE = 10401,

		/// <summary>
		/// 坐标系弧度跟随坐标系已初始化
		/// </summary>
		[Description("坐标系弧度跟随坐标系已初始化")]
		NEE_RET_ARCFOLLOW_GROUP_INIT = 10500,

		/// <summary>
		/// 坐标系弧度跟随坐标系未初始化
		/// </summary>
		[Description("坐标系弧度跟随坐标系未初始化")]
		NEE_RET_ARCFOLLOW_GROUP_DEINIT = 10501,
	};

	/// <summary>
	/// 运行错误代码
	/// </summary>
	public enum NEE_MC_ERROR
	{
		/// <summary>
		/// 无错误
		/// </summary>
		[Description("无错误")]
		NEX_ERR_OK = 0x0000,

		/// <summary>
		/// 定义结束
		/// </summary>
		[Description("定义结束")]
		NEX_ERR_END = 0x0300,
	};

	/// <summary>
	/// 布尔数据
	/// </summary>
	public enum NEE_BOOL
	{
		/// <summary>
		/// 否
		/// </summary>
		[Description("否")]
		NEE_FALSE = 0,

		/// <summary>
		/// 是
		/// </summary>
		[Description("是")]
		NEE_TRUE = 1,
	};

	/// <summary>
	/// 传送带跟随同步状态
	/// </summary>
	public enum NEE_CONVEYOR_SYNC_STATUS
	{
		/// <summary>
		/// 同步中
		/// </summary>
		[Description("同步中")]
		NEE_CONVEYOR_SYNC_NOTCOMPLETED = 0,

		/// <summary>
		/// 同步失败
		/// </summary>
		[Description("同步失败")]
		NEE_CONVEYOR_SYNC_FIALED = 1,

		/// <summary>
		/// 同步成功
		/// </summary>
		[Description("同步成功")]
		NEE_CONVEYOR_SYNC_SUCCESSFUL = 2,
	};

	/// <summary>
	/// 运动方向
	/// </summary>
	public enum NEE_DIRECTION
	{
		/// <summary>
		/// 正方向运动
		/// </summary>
		[Description("正方向运动")]
		NEX_DIRECTION_POSITIVE = 0,

		/// <summary>
		/// 负方向运动
		/// </summary>
		[Description("负方向运动")]
		NEX_DIRECTION_NEGATIVE = 1,

		/// <summary>
		/// 无效
		/// </summary>
		[Description("无效")]
		NEX_DIRECTION_NONE = 2,
	};

	/// <summary>
	/// 测试demo
	/// </summary>
	public enum NEE_TEST_DEMO
	{
		/// <summary>
		/// 每周期更新规划位置(自加0.001)
		/// </summary>
		[Description("每周期更新规划位置(自加0.001)")]
		NEE_DEMO_WCMDPOS = 2,
	};

	/// <summary>
	/// API缓冲区指令执行错误时的处理方式
	/// </summary>
	public enum NEE_API_BUFFER_WARN
	{
		/// <summary>
		/// 继续运行
		/// </summary>
		[Description("继续运行")]
		NEE_API_BUFFER_CONTINUE = 0,

		/// <summary>
		/// 停止
		/// </summary>
		[Description("停止")]
		NEE_API_BUFFER_STOP = 1,
	};

	/// <summary>
	/// 圆弧辅助点模式
	/// </summary>
	public enum NEE_CIRCULAR_AUX_MODE
	{
		/// <summary>
		/// 指定圆弧上一点
		/// </summary>
		[Description("指定圆弧上一点")]
		NEE_CIRCULAR_BORDER = 0x0000,

		/// <summary>
		/// 指定圆心
		/// </summary>
		[Description("指定圆心")]
		NEE_CIRCULAR_CENTER = 0x0001,
	};

	/// <summary>
	/// 圆弧路径选择
	/// </summary>
	public enum NEE_CIRCULAR_PATH_CHOICE
	{
		/// <summary>
		/// 顺时针,圆心模式使用
		/// </summary>
		[Description("顺时针,圆心模式使用")]
		NEE_CIRCULAR_CLOCKWISE = 0x0000,

		/// <summary>
		/// 逆时针,圆心模式使用
		/// </summary>
		[Description("逆时针,圆心模式使用")]
		NEE_CIRCULAR_COUNTERCLOCKWISE = 0x0001,
	};
	#endregion

	#region 结构体定义
	/// <summary>
	/// NTF错误状态
	/// </summary>
	public struct NES_NTFErrorStatus
	{
		/// <summary>
		/// 错误类型 二进制 第一位：轴错误 第二位：坐标系错误 第三位：总线错误 第四位：系统错误 第五位：API错误
		/// </summary>
		[Description("错误类型 二进制 第一位：轴错误 第二位：坐标系错误 第三位：总线错误 第四位：系统错误 第五位：API错误")]
		public UInt32 err_type;

		/// <summary>
		/// 错误代码
		/// </summary>
		[Description("错误代码")]
		public YKE_RESULT_CODE err_code;
	}

	/// <summary>
	/// 3坐标值
	/// </summary>
	public struct NES_POINT3
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
	/// 数字输出配置
	/// </summary>
	public struct NES_DigitalIO
	{
		/// <summary>
		/// 是否启用IO输出
		/// </summary>
		[Description("是否启用IO输出")]
		public NEE_BOOL enable;

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
		public NEE_BOOL inv;

		/// <summary>
		/// 是否启用延时输出时间
		/// </summary>
		[Description("是否启用延时输出时间")]
		public NEE_BOOL enable_delay;

		/// <summary>
		/// 输出延时时间
		/// </summary>
		[Description("输出延时时间")]
		public double delay_ms;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 res;
	}

	/// <summary>
	/// 门形运动配置
	/// </summary>
	public struct NES_MoveGateConfig
	{
		/// <summary>
		/// 抬升轴
		/// </summary>
		[Description("抬升轴")]
		public UInt32 lift_axis;

		/// <summary>
		/// 下降轴
		/// </summary>
		[Description("下降轴")]
		public UInt32 drop_axis;

		/// <summary>
		/// 平移轴数量,最多支持为32轴
		/// </summary>
		[Description("平移轴数量,最多支持为32轴")]
		public UInt32 line_axis_num;

		/// <summary>
		/// 事件通道号,门形运动需要占用连续的六个通道,event_channel为连续通道号中的起始通道号
		/// </summary>
		[Description("事件通道号,门形运动需要占用连续的六个通道,event_channel为连续通道号中的起始通道号")]
		public UInt32 event_channel;

		/// <summary>
		/// 平移轴,支持32轴
		/// </summary>
		[Description("平移轴,支持32轴")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 32, ArraySubType = UnmanagedType.I1)]
		public UInt32[] line_axis_list;

		/// <summary>
		/// 下降轴停止位置,绝对位置
		/// </summary>
		[Description("下降轴停止位置,绝对位置")]
		public double drop_stop_pos;

		/// <summary>
		/// 门形运动抬升总高度,绝对位置
		/// </summary>
		[Description("门形运动抬升总高度,绝对位置")]
		public double lift_pos;

		/// <summary>
		/// 门形运动软启动高度,绝对位置
		/// </summary>
		[Description("门形运动软启动高度,绝对位置")]
		public double soft_start_pos;

		/// <summary>
		/// 门形运动软着陆高度,绝对位置
		/// </summary>
		[Description("门形运动软着陆高度,绝对位置")]
		public double soft_stop_pos;

		/// <summary>
		/// 上升安全位高度,绝对位置
		/// </summary>
		[Description("上升安全位高度,绝对位置")]
		public double lift_safe_pos;

		/// <summary>
		/// 下降安全位高度,绝对位置
		/// </summary>
		[Description("下降安全位高度,绝对位置")]
		public double drop_safe_pos;

		/// <summary>
		/// 平移轴运动距离,绝对位置
		/// </summary>
		[Description("平移轴运动距离,绝对位置")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 32, ArraySubType = UnmanagedType.I1)]
		public double[] line_pos;

		/// <summary>
		/// 软启动目标速度
		/// </summary>
		[Description("软启动目标速度")]
		public double soft_start_vel;

		/// <summary>
		/// 软着陆目标速度
		/// </summary>
		[Description("软着陆目标速度")]
		public double soft_stop_vel;

		/// <summary>
		/// 上升速度
		/// </summary>
		[Description("上升速度")]
		public double lift_vel;

		/// <summary>
		/// 下降速度
		/// </summary>
		[Description("下降速度")]
		public double drop_vel;

		/// <summary>
		/// 上升轴IO配置
		/// </summary>
		[Description("上升轴IO配置")]
		public NES_DigitalIO liftDigitalIO;

		/// <summary>
		/// 下降轴IO配置
		/// </summary>
		[Description("下降轴IO配置")]
		public NES_DigitalIO dropDigitalIO;

		/// <summary>
		/// 平移轴IO配置
		/// </summary>
		[Description("平移轴IO配置")]
		public NES_DigitalIO lineDigitalIO;

		/// <summary>
		/// 上升轴io输出位置
		/// </summary>
		[Description("上升轴io输出位置")]
		public double io_lift_pos;

		/// <summary>
		/// 下降轴io输出位置
		/// </summary>
		[Description("下降轴io输出位置")]
		public double io_drop_pos;

		/// <summary>
		/// 平移轴io输出位置
		/// </summary>
		[Description("平移轴io输出位置")]
		public double io_line_pos;

		/// <summary>
		/// 触发输出的平移轴号
		/// </summary>
		[Description("触发输出的平移轴号")]
		public UInt32 io_line_axis;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 8, ArraySubType = UnmanagedType.I1)]
		public double[] res;
	}

	/// <summary>
	/// 门形运动状态
	/// </summary>
	public struct NES_MoveGateStatus
	{
		/// <summary>
		/// 运动状态
		/// </summary>
		[Description("运动状态")]
		public NEE_BOOL active;

		/// <summary>
		/// 运动完成状态
		/// </summary>
		[Description("运动完成状态")]
		public NEE_BOOL done;

		/// <summary>
		/// 报警状态
		/// </summary>
		[Description("报警状态")]
		public NES_NTFErrorStatus ntfErrorStatus;
	}

	/// <summary>
	/// 传送带跟随配置
	/// </summary>
	public struct NES_MoveConveyorConfig
	{
		/// <summary>
		/// 传送带跟随编码器锁存值
		/// </summary>
		[Description("传送带跟随编码器锁存值")]
		public double start_position;

		/// <summary>
		/// 传送带跟随绑定的轴号
		/// </summary>
		[Description("传送带跟随绑定的轴号")]
		public UInt32 conveyor_axis;

		/// <summary>
		/// 传送带移动方向
		/// </summary>
		[Description("传送带移动方向")]
		public NEE_DIRECTION direction;

		/// <summary>
		/// 传送带投影至xOy平面与x轴的夹角,使用弧度制表示
		/// </summary>
		[Description("传送带投影至xOy平面与x轴的夹角,使用弧度制表示")]
		public double angle_xy;

		/// <summary>
		/// 传送带与xOy平面之间的夹角,使用弧度制表示
		/// </summary>
		[Description("传送带与xOy平面之间的夹角,使用弧度制表示")]
		public double angle_xyz;

		/// <summary>
		/// 传送带跟随同步过程,允许同步的最远距离[DOUBLE_MIN,DOUBLE_MAX](unit)
		/// </summary>
		[Description("传送带跟随同步过程,允许同步的最远距离[DOUBLE_MIN,DOUBLE_MAX](unit)")]
		public double distance;

		/// <summary>
		/// 跟随轴数量,轴数量为1时,x轴直线模式；轴数量为2时,xy平面模式,轴数量为3时xyz空间模式
		/// </summary>
		[Description("跟随轴数量,轴数量为1时,x轴直线模式；轴数量为2时,xy平面模式,轴数量为3时xyz空间模式")]
		public UInt32 follow_axis_num;

		/// <summary>
		/// 跟随机械手同步虚拟轴轴组,用于跟随传送带实现同步,传入参数前需要先绑定机械手加工虚拟轴,最终实物轴通过跟随同步虚拟轴和加工虚拟轴实现运动
		/// </summary>
		[Description("跟随机械手同步虚拟轴轴组,用于跟随传送带实现同步,传入参数前需要先绑定机械手加工虚拟轴,最终实物轴通过跟随同步虚拟轴和加工虚拟轴实现运动")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = UnmanagedType.I1)]
		public UInt32[] follow_axis_list;

		/// <summary>
		/// 机械手实际轴组
		/// </summary>
		[Description("机械手实际轴组")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = UnmanagedType.I1)]
		public UInt32[] act_axis_list;

		/// <summary>
		/// 用于计算使用虚拟轴,用于实现传送带同步
		/// </summary>
		[Description("用于计算使用虚拟轴,用于实现传送带同步")]
		public UInt32 virtual_axis;

		/// <summary>
		/// 机械手相对于传送带锁存起点的偏置量,此时机械手必须置于传送带上方
		/// </summary>
		[Description("机械手相对于传送带锁存起点的偏置量,此时机械手必须置于传送带上方")]
		public double follow_axis_offset;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 8, ArraySubType = UnmanagedType.I1)]
		public UInt32[] res;
	}

	/// <summary>
	/// 传送带跟随状态
	/// </summary>
	public struct NES_MoveConveyorStatus
	{
		/// <summary>
		/// 传送带跟随同步状态
		/// </summary>
		[Description("传送带跟随同步状态")]
		public NEE_CONVEYOR_SYNC_STATUS conveyor_sync_status;

		/// <summary>
		/// 报警状态
		/// </summary>
		[Description("报警状态")]
		public NES_NTFErrorStatus ntfErrorStatus;
	}

	/// <summary>
	/// 往复运动+IO翻转配置
	/// </summary>
	public struct NES_MoveReciprocatingConfig
	{
		/// <summary>
		/// 是否在rtos下运行
		/// </summary>
		[Description("是否在rtos下运行")]
		public NEE_BOOL run_rtos;

		/// <summary>
		/// 轴号
		/// </summary>
		[Description("轴号")]
		public UInt32 axis_index;

		/// <summary>
		/// 翻转输出byte
		/// </summary>
		[Description("翻转输出byte")]
		public UInt32 output_byte_index;

		/// <summary>
		/// 翻转输出bit
		/// </summary>
		[Description("翻转输出bit")]
		public UInt32 output_bit_index;

		/// <summary>
		/// 翻转输入byte
		/// </summary>
		[Description("翻转输入byte")]
		public UInt32 input_byte_index;

		/// <summary>
		/// 翻转输入bit
		/// </summary>
		[Description("翻转输入bit")]
		public UInt32 input_bit_index;

		/// <summary>
		/// 循环次数
		/// </summary>
		[Description("循环次数")]
		public UInt32 loop_count;

		/// <summary>
		/// IO翻转次数
		/// </summary>
		[Description("IO翻转次数")]
		public UInt32 io_inversion_count;

		/// <summary>
		/// 位置A
		/// </summary>
		[Description("位置A")]
		public double position_a;

		/// <summary>
		/// 位置B
		/// </summary>
		[Description("位置B")]
		public double position_b;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 8, ArraySubType = UnmanagedType.I1)]
		public UInt32[] res;
	}

	/// <summary>
	/// 往复运动+IO翻转状态
	/// </summary>
	public struct NES_MoveReciprocatingStatus
	{
		/// <summary>
		/// 轴号
		/// </summary>
		[Description("轴号")]
		public UInt32 axis_index;

		/// <summary>
		/// 已循环次数
		/// </summary>
		[Description("已循环次数")]
		public UInt32 loop_index;

		/// <summary>
		/// 总共已循环次数
		/// </summary>
		[Description("总共已循环次数")]
		public UInt32 total_loop_index;

		/// <summary>
		/// IO已翻转次数
		/// </summary>
		[Description("IO已翻转次数")]
		public UInt32 io_inversion_index;

		/// <summary>
		/// 流程状态
		/// </summary>
		[Description("流程状态")]
		public UInt32 function_phase;

		/// <summary>
		/// 单次往复耗时
		/// </summary>
		[Description("单次往复耗时")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 1024, ArraySubType = UnmanagedType.I1)]
		public double[] function_path_time;

		/// <summary>
		/// Sleep 1ms 耗时
		/// </summary>
		[Description("Sleep 1ms 耗时")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 1024, ArraySubType = UnmanagedType.I1)]
		public double[] sleep_cost_time;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 8, ArraySubType = UnmanagedType.I1)]
		public UInt32[] res;
	}

	/// <summary>
	/// API缓冲区配置
	/// </summary>
	public struct NES_ApiBufferConfig
	{
		/// <summary>
		/// 运行节点
		/// </summary>
		[Description("运行节点")]
		public YKE_NODE node;

		/// <summary>
		/// 缓冲区大小,字节单位
		/// </summary>
		[Description("缓冲区大小,字节单位")]
		public UInt32 buff_size;

		/// <summary>
		/// 指令错误时的处理方式
		/// </summary>
		[Description("指令错误时的处理方式")]
		public NEE_API_BUFFER_WARN warn_do;
	}

	/// <summary>
	/// API缓冲区状态
	/// </summary>
	public struct NES_ApiBufferStatus
	{
		/// <summary>
		/// 运行中
		/// </summary>
		[Description("运行中")]
		public NEE_BOOL active;

		/// <summary>
		/// 已暂停
		/// </summary>
		[Description("已暂停")]
		public NEE_BOOL pause;

		/// <summary>
		/// 写入端指令索引
		/// </summary>
		[Description("写入端指令索引")]
		public UInt32 write_index;

		/// <summary>
		/// 执行端指令索引
		/// </summary>
		[Description("执行端指令索引")]
		public UInt32 exec_index;

		/// <summary>
		/// 当前执行这里的Mark
		/// </summary>
		[Description("当前执行这里的Mark")]
		public UInt32 current_mask;

		/// <summary>
		/// 错误代码
		/// </summary>
		[Description("错误代码")]
		public YKE_RESULT_CODE error_code;

		/// <summary>
		/// 发生错误的指令索引
		/// </summary>
		[Description("发生错误的指令索引")]
		public UInt32 error_index;

		/// <summary>
		/// 保留
		/// </summary>
		[Description("保留")]
		public UInt32 done;
	}

	/// <summary>
	/// 坐标系弧度跟随圆弧运动指令配置
	/// </summary>
	public struct NES_MoveArcFollowConfig
	{
		/// <summary>
		/// 被加工工件圆弧起点坐标
		/// </summary>
		[Description("被加工工件圆弧起点坐标")]
		public NES_POINT3 workpieceStartPosPoint3;

		/// <summary>
		/// 相对圆弧起点坐标水平方向旋转角度,单位为度,范围大于0
		/// </summary>
		[Description("相对圆弧起点坐标水平方向旋转角度,单位为度,范围大于0")]
		public double rotate_angle;

		/// <summary>
		/// 圆弧圆心坐标
		/// </summary>
		[Description("圆弧圆心坐标")]
		public NES_POINT3 cirCenterPosPoint3;

		/// <summary>
		/// 被加工工件圆弧运动方向选择
		/// </summary>
		[Description("被加工工件圆弧运动方向选择")]
		public NEE_CIRCULAR_PATH_CHOICE circular_path_choice;

		/// <summary>
		/// 加工头运动目标速度
		/// </summary>
		[Description("加工头运动目标速度")]
		public double max_velocity;

		/// <summary>
		/// 加工头运动目标加速度
		/// </summary>
		[Description("加工头运动目标加速度")]
		public double max_acceleration;

		/// <summary>
		/// 加工头运动目标加加速度
		/// </summary>
		[Description("加工头运动目标加加速度")]
		public double max_jerk;

		/// <summary>
		/// 位置输出开io配置
		/// </summary>
		[Description("位置输出开io配置")]
		public NES_DigitalIO onDigitalIO;

		/// <summary>
		/// 加工旋转指定角度开启io输出
		/// </summary>
		[Description("加工旋转指定角度开启io输出")]
		public double io_on_output_angle;

		/// <summary>
		/// 位置输出关io配置
		/// </summary>
		[Description("位置输出关io配置")]
		public NES_DigitalIO offDigitalIO;

		/// <summary>
		/// 加工剩余指定弧度关闭io输出
		/// </summary>
		[Description("加工剩余指定弧度关闭io输出")]
		public double io_off_output_angle;
	}

	/// <summary>
	/// ArcFollow坐标系机器配置
	/// </summary>
	public struct NES_ArcFollowGroupConfig
	{
		/// <summary>
		/// 坐标系号
		/// </summary>
		[Description("坐标系号")]
		public UInt32 group_index;

		/// <summary>
		/// 用于加工的四个轴,axis_list[0]:X轴轴号,axis_list[1]:Y轴轴号,axis_list[2]:Z轴轴号,axis_list[3]:R轴轴号
		/// </summary>
		[Description("用于加工的四个轴,axis_list[0]:X轴轴号,axis_list[1]:Y轴轴号,axis_list[2]:Z轴轴号,axis_list[3]:R轴轴号")]
		[MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 4, ArraySubType = UnmanagedType.I1)]
		public UInt32[] axis_list;

		/// <summary>
		/// 刀头与R轴中心连线投影于xy平面的长度
		/// </summary>
		[Description("刀头与R轴中心连线投影于xy平面的长度")]
		public double tool_length;

		/// <summary>
		/// 起始位置刀头与R轴中心连线投影于xy平面的方向与y轴方向夹角,范围为[-180,180]
		/// </summary>
		[Description("起始位置刀头与R轴中心连线投影于xy平面的方向与y轴方向夹角,范围为[-180,180]")]
		public double start_angle;
	}

	/// <summary>
	/// 坐标系弧度跟随坐标系状态
	/// </summary>
	public struct NES_ArcFollowGroupStatus
	{
		/// <summary>
		/// 初始化状态 false:未初始化 true:已初始化
		/// </summary>
		[Description("初始化状态 false:未初始化 true:已初始化")]
		public NEE_BOOL inited;

		/// <summary>
		/// 运动状态 false:未运动 true:正在运动
		/// </summary>
		[Description("运动状态 false:未运动 true:正在运动")]
		public NEE_BOOL active;

		/// <summary>
		/// 完成状态 false:运动未完成 true:运动已完成
		/// </summary>
		[Description("完成状态 false:运动未完成 true:运动已完成")]
		public NEE_BOOL done;

		/// <summary>
		/// 报警状态
		/// </summary>
		[Description("报警状态")]
		public NES_NTFErrorStatus ntfErrorStatus;
	}
#endregion

	/// <summary>
	/// NoExt
	/// </summary>
	public class NoExt
	{
		#region 系统
		/// <summary>
		/// 获取当前库版本
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="version">当前版本号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_GetSysVersion(Int32 handle, out UInt32 version);

		/// <summary>
		/// 打开和Runtime(ProR)之间的通讯通道
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_SysLoadLib(Int32 handle);

		/// <summary>
		/// 释放系统资源，程序退出时调用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_SysUnloadLib(Int32 handle);

		/// <summary>
		/// 读取runtime日志
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="msg">缓冲区</param>
		/// <param name="buff_size">缓冲区大小，字节单位</param>
		/// <param name="revd_size">读回数据大小，字节单位</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_ReadLogger(Int32 handle, Byte[] msg, UInt32 buff_size, out UInt32 revd_size);

		/// <summary>
		/// 获取系统 Sleep 1ms所花费的时间
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="time">系统 Sleep 1ms所花费的时间</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_GetSleep1CostTime(Int32 handle, out double time);
		#endregion

		#region 往复运动+IO翻转
		/// <summary>
		/// 配置往复运动+IO翻转参数
		/// 功能演示使用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config">往复运动+IO翻转配置参数</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_SetMoveReciprocatingConfig(Int32 handle, NES_MoveReciprocatingConfig config);

		/// <summary>
		/// 获取往复运动+IO翻转状态
		/// 功能演示使用
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="config">往复运动+IO翻转状态信息</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_ReadMoveReciprocatingStatus(Int32 handle, out NES_MoveReciprocatingStatus config);
		#endregion

		#region 门形运动
		/// <summary>
		/// 配置门形运动参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="config">门形运动配置</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_SetMoveGateConfig(Int32 handle, UInt32 channel, NES_MoveGateConfig config);

		/// <summary>
		/// 获取门形运动参数
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="config">门形运动配置</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_GetMoveGateConfig(Int32 handle, UInt32 channel, out NES_MoveGateConfig config);

		/// <summary>
		/// 启动门形运动
		/// </summary>
		/// <param name="handle">标识0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StartMoveGate(Int32 handle, UInt32 channel);

		/// <summary>
		/// 停止门形运动
		/// </summary>
		/// <param name="handle">标识0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StopMoveGate(Int32 handle, UInt32 channel);

		/// <summary>
		/// 获取门形运动状态
		/// </summary>
		/// <param name="handle">标识0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="status">门形运动状态</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_ReadMoveGateStatus(Int32 handle, UInt32 channel, out NES_MoveGateStatus status);

		/// <summary>
		/// 清除门形运动状态
		/// </summary>
		/// <param name="handle">标识0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_ClearMoveGateStatus(Int32 handle, UInt32 channel);
		#endregion

		#region 传送带跟随
		/// <summary>
		/// 设置传送带跟随配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="config">传送带跟随配置</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_SetMoveConveyorConfig(Int32 handle, UInt32 channel, NES_MoveConveyorConfig config);

		/// <summary>
		/// 获取传送带跟随配置
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="config">传送带跟随配置</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_GetMoveConveyorConfig(Int32 handle, UInt32 channel, out NES_MoveConveyorConfig config);

		/// <summary>
		/// 启动传送带跟随
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StartMoveConveyor(Int32 handle, UInt32 channel);

		/// <summary>
		/// 停止传送带跟随
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StopMoveConveyor(Int32 handle, UInt32 channel);

		/// <summary>
		/// 获取传送带跟随状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="status">传送带跟随状态</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_ReadMoveConveyorStatus(Int32 handle, UInt32 channel, out NES_MoveConveyorStatus status);
		#endregion

		#region API缓冲区
		/// <summary>
		/// API缓冲区初始化
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">缓冲区通道</param>
		/// <param name="config">缓冲区大小，字节单位</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_InitApiBuffer(Int32 handle, UInt32 channel, NES_ApiBufferConfig config);

		/// <summary>
		/// 启动API缓冲区运行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">缓冲区通道</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StartApiBuffer(Int32 handle, UInt32 channel);

		/// <summary>
		/// 停止API缓冲区运行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">缓冲区通道</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StopApiBuffer(Int32 handle, UInt32 channel);

		/// <summary>
		/// 暂停API缓冲区运行
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">缓冲区通道</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_PauseApiBuffer(Int32 handle, UInt32 channel);

		/// <summary>
		/// 获取API缓冲区状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接</param>
		/// <param name="channel">缓冲区通道</param>
		/// <param name="status"></param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_ReadApiBufferStatus(Int32 handle, UInt32 channel, out NES_ApiBufferStatus status);
		#endregion

		#region 坐标系弧度跟随
		/// <summary>
		/// 坐标系弧度跟随圆弧插补
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="config">坐标系弧度跟随圆弧指令配置</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_MoveArcFollow(Int32 handle, UInt32 channel, NES_MoveArcFollowConfig config);

		/// <summary>
		///  坐标系弧度跟随坐标系初始化
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="config">坐标系弧度跟随坐标系配置</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_InitGroupArcFollow(Int32 handle, UInt32 channel, NES_ArcFollowGroupConfig config);

		/// <summary>
		///  坐标系弧度跟随坐标系解绑
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_DeinitGroupArcFollow(Int32 handle, UInt32 channel);

		/// <summary>
		/// 启动坐标系弧度跟随运动
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StartMoveArcFollow(Int32 handle, UInt32 channel);

		/// <summary>
		/// 停止坐标系弧度跟随运动
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StopMoveArcFollow(Int32 handle, UInt32 channel);

		/// <summary>
		/// 读取坐标系弧度跟随坐标系状态状态
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="channel">通道号 支持[0,GATE_MOVEMENT_NUM)通道号</param>
		/// <param name="status">坐标系弧度跟随坐标系状态</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_ReadMoveArcFollowStatus(Int32 handle, UInt32 channel, out NES_ArcFollowGroupStatus status);
		#endregion

		#region 测试demo
		/// <summary>
		/// 启动demo
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="opt">类型</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StartDemo(Int32 handle, NEE_TEST_DEMO opt);

		/// <summary>
		/// 停止demo
		/// </summary>
		/// <param name="handle">0:共享内存 其他:通讯链接标识</param>
		/// <param name="opt">类型</param>
		/// <returns></returns>
		[DllImport("NoExt.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern NEE_RESULT_CODE NEM_StopDemo(Int32 handle, NEE_TEST_DEMO opt);
		#endregion

	}
}




