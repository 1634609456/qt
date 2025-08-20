#ifndef _YKCAT_
#define _YKCAT_

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

typedef enum
{
	YKE_MAGIC_FLAG = 0x13575A5A,

	YKE_PROCON_VER = 1531,

	YKE_DIGITAL_INPUT_NUM = 4096,

	YKE_DIGITAL_OUTPUT_NUM = 4096,

	YKE_DIGITAL_OUTPUT_CYCLE_NUM = 1024,

	YKE_MASTER_NUM = 4,

	YKE_OSC_NUM = 8,

	YKE_OSC_ITEM_NUM = 64,

	YKE_INTER_AXIS_NUM = 32,

	YKE_SOFT_COMPARE_NUM = 128,

	YKE_SOFT_COMPARE_DEPTH = 512,

	YKE_SOFT_PROBE_NUM = 128,

	YKE_SOFT_PROBE_DEPTH = 512,

	YKE_HARD_PROBE_DEPTH = 512,

	YKE_AXIS_SOFT_PROBE_NUM = 4,

	YKE_PITCH1D_NUM = 2048,

	YKE_PITCH2D_NUM = 512,

	YKE_EVENT_NUM = 1024,

	YKE_WAIT_NUM = 1024,

	YKE_GROUP_NUM = 32,

	YKE_GROUP_DEPTH = 4096,

	YKE_GROUP_OUTPUT_NUM = 32,

	YKE_AXIS_NUM = 1024,

	YKE_LOGGER_ITEM = 32,

	YKE_EXC_CONDI = 16,

	YKE_GENDATA_SIZE = 0x100000,

	YKE_SPDATA_SIZE = 0x10000,

	YKE_EMG_STOP_INPUT_NUM = 8,

	YKE_EMG_STOP_OUTPUT_NUM = 4,

	YKE_EMG_STOP_NUM = 32,

	YKE_PVT_DEPTH = 4096,

	YKE_FILE_PATH_SIZE = 512,

	YKE_FILE_NAME_SIZE = 64,

	YKE_LOGGER_PROCCESS = 32,

	YKE_MULTI_AXIS_NUM = 128,

	YKE_CIRCLE_ZONE_NUM = 32,

	YKE_API_BUFFER_NUM = 512,
}YKE_SYSTEM_DEFINE;

typedef enum
{
	YKE_RET_OK = 0,

	YKE_RET_SYS_LOAD_RTA = 0x0100,

	YKE_RET_SYS_OPEN_GW = 0x0101,

	YKE_RET_SYS_CONNECT_GW = 0x0102,

	YKE_RET_SYS_OPEN_MEM = 0x0103,

	YKE_RET_SYS_GW_TIMOUT = 0x0104,

	YKE_RET_SYS_LIC = 0x0105,

	YKE_RET_SYS_RTOS = 0x0106,

	YKE_RET_SYS_EXIT = 0x0107,

	YKE_RET_SYS_COLD = 0x0108,

	YKE_RET_SYS_ACCESS = 0x0109,

	YKE_RET_SYS_MISMATCH = 0x010a,

	YKE_RET_SYS_LANG_TEXT = 0x010b,

	YKE_RET_SYS_CHN = 0x010c,

	YKE_RET_SYS_FUN = 0x010d,

	YKE_RET_SYS_DYNC_MEM = 0x010e,

	YKE_RET_SYS_COLD_ERR = 0x010f,

	YKE_RET_SYS_NODEA_ENA = 0x0110,

	YKE_RET_SYS_NODEO = 0x0111,

	YKE_RET_SYS_NODEB_ENA = 0x0112,

	YKE_RET_SYS_NODEB_RUN = 0x0113,

	YKE_RET_SYS_NODEC_ENA = 0x0114,

	YKE_RET_SYS_NODEC_RUN = 0x0115,

	YKE_RET_SYS_NODED_ENA = 0x0116,

	YKE_RET_SYS_NODED_RUN = 0x0117,

	YKE_RET_SYS_RUNTIME_STOP = 0x0118,

	YKE_RET_SYS_INTIME_MEM = 0x0119,

	YKE_RET_SYS_NODE_ENA = 0x011E,

	YKE_RET_SYS_NODE_IDX = 0x011F,

	YKE_RET_SYS_CREATE_DIR = 0x0120,

	YKE_RET_SYS_SIM_CONNECT = 0x0121,

	YKE_RET_SYS_NULL = 0x0122,

	YKE_RET_YKSRV_NOT_INSTALL = 0x0123,

	YKE_RET_SYS_YKSRV_NOT_START = 0x0124,

	YKE_RET_YKSRV_OP_FAIL = 0x0125,

	YKE_RET_YKSRV_ACCESS = 0x0126,

	YKE_RET_SYS_API_VER = 0x012F,

	YKE_RET_SYS_LOG_NULL = 0x0130,

	YKE_RET_API_BUFFER_N = 0x141,

	YKE_RET_SYS_YKCATN_CONNECT = 0x0180,

	YKE_RET_SYS_YKCATN_TIMEOUT = 0x0181,

	YKE_RET_SYS_YKCATN_HANDLE = 0x0182,

	YKE_RET_SYS_YKCATN_SIZE = 0x0183,

	YKE_RET_SYS_YKCATN_LEN = 0x0184,

	YKE_RET_SYS_YKCATN_NAME = 0x0185,

	YKE_RET_SYS_YKCATN_PARA = 0x0186,

	YKE_RET_INS_PARA = 0x0200,

	YKE_RET_INS_NEG = 0x0201,

	YKE_RET_INS_DOUBLE = 0x0202,

	YKE_RET_INS_ENUM = 0x0203,

	YKE_RET_INS_PTR = 0x0204,

	YKE_RET_EMG_HARD = 0x0220,

	YKE_RET_EMG_SOFT = 0x0221,

	YKE_RET_LIMIT_H = 0x0230,

	YKE_RET_LIMIT_S = 0x0231,

	YKE_RET_CIRCLE_ZONE = 0x0232,

	YKE_RET_IO_REVERSE_BUFFER_OV = 0x0240,

	YKE_RET_AXIS_SIM_POS = 0x0300,

	YKE_RET_AXIS_SIM_TIM = 0x0301,

	YKE_RET_AXIS_SIM_TIMOUT = 0x0302,

	YKE_RET_AXIS_SIM_INP = 0x0303,

	YKE_RET_AXIS_OVERRIDE_INVALID = 0x0313,

	YKE_RET_AXIS_BUSY = 0x0314,

	YKE_RET_AXIS_READY = 0x0315,

	YKE_RET_AXIS_INDEX = 0x0316,

	YKE_RET_AXIS_MOTION_TYPE = 0x0317,

	YKE_RET_AXIS_CSP = 0x0318,

	YKE_RET_AXIS_CURVE = 0x0319,

	YKE_RET_FOLLOW_MASTER = 0x0400,

	YKE_RET_FOLLOW_CAM_MPOS = 0x0401,

	YKE_RET_MULTI_AXIS_ACITVE = 0x0420,

	YKE_RET_MULTI_AXIS_NUM = 0x0421,

	YKE_RET_MULTI_AXIS_NODE = 0x0430,

	YKE_RET_PVT_BUFFER_OV = 0x0500,

	YKE_RET_PVT_FIRST = 0x0501,

	YKE_RET_PVTS_NUM = 0x0502,

	YKE_RET_PVTS_DYNC = 0x0503,

	YKE_RET_PVTS_TIM = 0x0504,

	YKE_RET_PT_ACC = 0x0505,

	YKE_RET_PVTS_SVEL = 0x0506,

	YKE_RET_GROUP_INIT = 0x0600,

	YKE_RET_GROUP_DEINIT = 0x0601,

	YKE_RET_GROUP_AXIS_INDEX_REPEAT = 0x0602,

	YKE_RET_GROUP_ACTIVE = 0x0603,

	YKE_RET_GROUP_BUFFER_FULL = 0x0604,

	YKE_RET_GROUP_AXIS_WARN = 0x0605,

	YKE_RET_GROUP_WARN = 0x0606,

	YKE_RET_GROUP_AXIS_SINGLE = 0x0607,

	YKE_RET_GROUP_AXIS_CSP = 0x0608,

	YKE_RET_GROUP_AXIS_INDEX_REPEAT2 = 0x0609,

	YKE_RET_GROUP_PAUSE = 0x0610,

	YKE_RET_GROUP_INC = 0x0611,

	YKE_RET_GROUP_STOPPING = 0x0612,

	YKE_RET_GROUP_AXIS_GANTRY = 0x0613,

	YKE_RET_GROUP_AXIS_NODE = 0x0614,

	YKE_RET_PITCH_ENA = 0x0700,

	YKE_RET_PITCH_REPEAT = 0x0701,

	YKE_RET_PITCH_DATA = 0x0702,

	YKE_RET_PITCH_DRV = 0x0703,

	YKE_RET_PITCH_USED = 0x0704,

	YKE_RET_BUS_INIT = 0x0800,

	YKE_RET_BUS_SDO_OV = 0x0801,

	YKE_RET_BUS_SDO_U = 0x0802,

	YKE_RET_BUS_SDO_OD = 0x0803,

	YKE_RET_BUS_SDO_TIMOUT = 0x0804,

	YKE_RET_BUS_OD_PDO = 0x0805,

	YKE_RET_BUS_OD_SDO = 0x0806,

	YKE_RET_BUS_OD_RD = 0x0807,

	YKE_RET_BUS_SIM_SCAN = 0x0808,

	YKE_RET_BUS_SNAP_UNUSED = 0x0809,

	YKE_RET_BUS_SNAP_IDEL = 0x0810,

	YKE_RET_ERROR_DRV_WARN = 0x0820,

	YKE_RET_PROBE_ACTIVE = 0x0900,

	YKE_RET_SOFT_COMPARE_ACTIVE = 0x0a00,

	YKE_RET_COMPARE_BUFFER_OV = 0x0a01,

	YKE_RET_COMPARE_BUFFER_FIX = 0x0a02,

	YKE_RET_NTF_LOAD = 0x0B00,

	YKE_RET_NTF_EXIST = 0x0B01,

	YKE_RET_WAIT_INIT = 0x0B60,

	YKE_RET_WAIT_DEL = 0x0B61,

	YKE_RET_WAIT_TIMEOUT = 0x0B62,

	YKE_RET_WAIT_FAIL = 0x0B63,

	YKE_RET_WAIT_BUSY = 0x0B64,

	YKE_RET_WAIT_OPEN = 0x0B65,

	YKE_RET_WAIT_SYS_RESET = 0x0B66,

	YKE_RET_WAIT_INS_RESET = 0x0B67,

	YKE_RET_WAIT_EXIT = 0x0B68,

	YKE_RET_PROEN_SHAREM = 0x0C00,

	YKE_RET_PROEN_OV = 0x0C01,

	YKE_RET_PROEN_EXIST = 0x0C02,

	YKE_RET_PROEN_OPEN_FAIL = 0x0C10,

	YKE_RET_PROEN_MAGIC_FAIL = 0x0C11,

	YKE_RET_PROEN_TIMEOUT = 0x0C12,

	YKE_RET_PROEN_FILENAME = 0x0C13,

	YKE_RET_PROEN_FILE_EXT = 0x0C14,

	YKE_RET_EVENT_NODE = 0x0d00,

	YKE_RET_EVENT_BUSY = 0x0d01,

	YKE_RET_EVENT_ENCODER = 0x0d02,

	YKE_RET_CIRCLE_ZONE_INIT = 0x0d40,

	YKE_RET_CIRCLE_ZONE_INDEX = 0x0d41,

	YKE_RET_DOGGLE_TIMEOUT = 0x0d80,

	YKE_RET_NTF_INIT = 0x0da0,

	YKE_RET_NTF_API_BUFFER_INIT = 0x0da1,

	YKE_RET_NTF_API_BUFFER_CH_INIT = 0x0da2,

	YKE_RET_NTF_API_BUFFER_CH_OV = 0x0da3,

	YKE_RET_NTF_API_BUFFER_INS = 0x0da4,

	YKE_RET_NTF_API_BUFFER_ACTIVE = 0x0da5,

	YKE_RET_OSC_ZERO_ENA = 0x0e00,

	YKE_RET_OSC_ACTIVE = 0x0e01,

	YKE_RET_PCI_ENCODER_AXIS = 0x0e20,
}YKE_RESULT_CODE;

typedef enum
{
	YKE_ERR_MC_OK = 0x0000,

	YKE_ERR_MC_SOFT_EMG = 0x0001,

	YKE_ERR_MC_HARD_EMG = 0x0002,

	YKE_ERR_MC_SYS_STOP = 0x0003,

	YKE_ERR_MC_AXIS_READY = 0x0101,

	YKE_ERR_MC_LIMIT_HARDP = 0x0102,

	YKE_ERR_MC_LIMIT_HARDN = 0x0103,

	YKE_ERR_MC_LIMIT_SOFTP = 0x0104,

	YKE_ERR_MC_LIMIT_SOFTN = 0x0105,

	YKE_ERR_MC_POSITION_LAG = 0x0106,

	YKE_ERR_MC_INP = 0x0107,

	YKE_ERR_MC_DRV_OP_MODE = 0x0108,

	YKE_ERR_MC_DRV_OP_MODE_ACTIVE = 0x0109,

	YKE_ERR_MC_AXIS_SLAVE_STOP = 0x010a,

	YKE_ERR_MC_DRV_INP = 0x010b,

	YKE_ERR_MC_GANTRY_LAG = 0x0120,

	YKE_ERR_MC_HOME_LIMIT = 0x0150,

	YKE_ERR_MC_HOME_HOME = 0x0151,

	YKE_ERR_MC_HOME_PROBE = 0x0152,

	YKE_ERR_MC_HOME_3537 = 0x0153,

	YKE_ERR_MC_HOME_STOP1 = 0x0154,

	YKE_ERR_MC_HOME_TOUCH = 0x0155,

	YKE_ERR_MC_HOME_OFFLINE = 0x0156,

	YKE_ERR_MC_PLS_PROBE_CONFIG = 0x160,

	YKE_ERR_MC_PITCH2D_VEL = 0x170,

	YKE_ERR_MC_DRV_WARN = 0x0200,

	YKE_ERR_MC_DRV_PP = 0x0201,

	YKE_ERR_MC_DRV_HM = 0x0202,

	YKE_ERR_MC_PV_SDO = 0x0203,

	YKE_ERR_MC_PP_SDO = 0x0204,

	YKE_ERR_MC_TORQUE_PDO = 0x0208,

	YKE_ERR_MC_POWER_ON = 0x0210,

	YKE_ERR_MC_CLR_DRV = 0x0211,

	YKE_ERR_MC_GROUP_PATH = 0x0250,

	YKE_ERR_MC_GROUP_CIR = 0x0251,

	YKE_ERR_MC_GROUP_AXIS = 0x0252,

	YKE_ERR_MC_GROUP_AXIS_INDEX = 0x0253,

	YKE_ERR_MC_GROUP_AXIS_ACTIVE1 = 0x0254,

	YKE_ERR_MC_GROUP_AXIS_INPOS = 0x0255,

	YKE_ERR_MC_GROUP_AXIS_ACTIVE2 = 0x0256,

	YKE_ERR_MC_GROUP_AXIS_READY = 0x0257,

	YKE_ERR_MC_GROUP_AXIS_LIMIT = 0x0258,

	YKE_ERR_MC_GROUP_HARD_EMG = 0x0259,

	YKE_ERR_MC_GROUP_SOFT_EMG = 0x025a,

	YKE_ERR_MC_GROUP_CNC_EXT = 0x0260,

	YKE_ERR_MC_GROUP_CNC_NUM = 0x0261,

	YKE_ERR_MC_GROUP_CNC_LINE = 0x0262,

	YKE_ERR_MC_GROUP_CNC_CIR = 0x0263,

	YKE_ERR_MC_GROUP_CNC_GCODE = 0x0264,

	YKE_ERR_MC_GROUP_CNC_FILE = 0x0265,

	YKE_ERR_MC_END = 0x0300,
}YKE_MC_ERROR;

typedef enum
{
	YKE_ERR_SYS_APP_NONE = 0x0000,

	YKE_ERR_SYS_FILE_VER = 0x0001,

	YKE_ERR_SYS_FILE_CFG = 0x0002,

	YKE_ERR_SYS_FILE_EXIST = 0x0003,

	YKE_ERR_SYS_FILE_READ = 0x0004,

	YKE_ERR_SYS_CARD_VER1 = 0x0005,

	YKE_ERR_SYS_CARD_VER2 = 0x0006,

	YKE_ERR_SYS_BRD_VER = 0x0007,

	YKE_ERR_SYS_CLK_BASE = 0x0008,

	YKE_ERR_SYS_DC_125US = 0x0009,

	YKE_ERR_SYS_YKGROUP_VER = 0x000A,

	YKE_ERR_SYS_CARD_UNKNOWN = 0x000B,

	YKE_ERR_SYS_250us_PC = 0x000C,

	YKE_ERR_SYS_APP_INIT_I = 0x0010,

	YKE_ERR_SYS_NTF_LOAD = 0x0011,

	YKE_ERR_SYS_NTF_INIT = 0x0012,

	YKE_ERR_SYS_NODEB_ENA = 0x0013,

	YKE_ERR_SYS_NODEC_ENA = 0x0014,

	YKE_ERR_SYS_NODED_ENA = 0x0015,

	YKE_ERR_SYS_NODEB_FAIL = 0x0016,

	YKE_ERR_SYS_NODEC_FAIL = 0x0017,

	YKE_ERR_SYS_NODED_FAIL = 0x0018,

	YKE_ERR_SYS_NTF_PAYLOAD = 0x0019,

	YKE_ERR_SYS_BRD_INIT = 0x0020,

	YKE_ERR_SYS_APP_WTD = 0x0030,

	YKE_ERR_SYS_LIC = 0x0031,

	YKE_ERR_SYS_DYNC_MEM = 0x0032,

	YKE_ERR_SYS_APP_CHK_NIC = 0x0040,

	YKE_ERR_SYS_SLAVE_CHKNUM = 0x0041,

	YKE_ERR_SYS_LINK_ECAT = 0x0042,

	YKE_ERR_SYS_DC_SHIFT = 0x0043,

	YKE_ERR_SYS_DISCONNECT = 0x0044,

	YKE_ERR_SYS_PDO1_WKC = 0x0045,

	YKE_ERR_SYS_PDO2_WKC = 0x0046,

	YKE_ERR_SYS_PDO3_WKC = 0x0047,

	YKE_ERR_SYS_PDO4_WKC = 0x0048,

	YKE_ERR_SYS_DATA_TYPE = 0x004a,

	YKE_ERR_SYS_NIC_SWAP = 0x004b,

	YKE_ERR_SYS_APP_HDCHANGE = 0x0051,

	YKE_ERR_SYS_DC_CYCLE = 0x0052,

	YKE_ERR_SYS_PLS_OVERFLOW = 0x0060,

	YKE_ERR_SYS_PLS_MAX = 0x0061,

	YKE_ERR_SYS_APP_BRDCHANGE = 0x0062,

	YKE_ERR_SYS_EMG_OFFLINE = 0x070,

	YKE_ERR_SYS_EMG_SOFT = 0x071,

	YKE_ERR_SYS_EMG_HARD = 0x072,

	YKE_ERR_EVENT_START_AXIS = 0x080,

	YKE_ERR_EVENT_START_GROUP = 0x081,

	YKE_ERR_EVENT_READ_PDO = 0x082,

	YKE_ERR_EVENT_WRITE_PDO = 0x083,
}YKE_SYSTEM_ERROR;

typedef enum
{
	YKE_ERR_SLAVE_PDO_NONE = 0x0000,

	YKE_ERR_SLAVE_PDO_DTYPE = 0x0100,

	YKE_ERR_SLAVE_PDO = 0x0101,

	YKE_ERR_SLAVE_VID = 0x0102,

	YKE_ERR_SLAVE_PID = 0x0103,

	YKE_ERR_SLAVE_TO_INIT = 0x0104,

	YKE_ERR_SLAVE_TO_PREOP = 0x0105,

	YKE_ERR_SLAVE_TO_SAFEOP = 0x0106,

	YKE_ERR_SLAVE_TO_OP = 0x0107,

	YKE_ERR_SLAVE_SDO_WRITE = 0x0108,

	YKE_ERR_SLAVE_SDO_READ = 0x0109,

	YKE_ERR_SLAVE_SDO = 0x010a,

	YKE_ERR_SLAVE_SDO_OVER = 0x010b,

	YKE_ERR_SLAVE_INDEX = 0x010c,

	YKE_ERR_SLAVE_OFFLINE = 0x010d,

	YKE_ERR_SLAVE_RST = 0x010e,

	YKE_ERR_SLAVE_DRVW = 0x010f,

	YKE_ERR_SLAVE_SM_TIMEOUT = 0x0110,
}YKE_SLAVE_ERROR;

typedef enum
{
	YKE_ECAT_A = 0,

	YKE_ECAT_B = 1,

	YKE_ECAT_C = 2,

	YKE_ECAT_D = 3,

	YKE_NODE_E = 4,

	YKE_NODE_F = 5,

	YKE_NODE_G = 6,

	YKE_NODE_H = 7,
}YKE_NODE;

typedef enum
{
	YKE_AXIS_PHY_VIRTUAL = 0,

	YKE_AXIS_PHY_ETHERCAT = 1,

	YKE_AXIS_PHY_PULSE = 2,
}YKE_AXIS_PHY;

typedef enum
{
	YKE_DIO_PHY_PCI = 0,

	YKE_DIO_PHY_EBUS_DIO = 1,

	YKE_DIO_PHY_EBUS_GW = 2,

	YKE_DIO_PHY_EBUS_DRV = 3,
}YKE_DIO_PHY;

typedef enum
{
	YKE_AXIS_STOP_NONE = 0,

	YKE_AXIS_STOP_EMG = 1,

	YKE_AXIS_STOP_INS = 2,

	YKE_AXIS_STOP_HARD_LIMIT = 3,

	YKE_AXIS_STOP_SOFT_LIMIT = 4,

	YKE_AXIS_STOP_DRIVER = 5,

	YKE_AXIS_STOP_MASTER = 6,

	YKE_AXIS_STOP_SLAVE = 7,

	YKE_AXIS_STOP_FOLLOW = 8,

	YKE_AXIS_STOP_TRIGGER = 9,

	YKE_AXIS_STOP_EVENT = 10,

	YKE_AXIS_STOP_CIRCLE_ZONE = 11,

	YKE_AXIS_STOP_RUNTIME = 20,
}YKE_AXIS_STOP_TYPE;

typedef enum
{
	YKE_AXIS_WAIT_ACITVE_OFF = 0,

	YKE_AXIS_WAIT_ACITVE_ON = 1,
}YKE_AXIS_WAIT_TYPE;

typedef enum
{
	YKE_DIGITAL_INPUT_WAIT_OFF = 0,

	YKE_DIGITAL_INPUT_WAIT_ON = 1,
}YKE_DIGITAL_INPUT_WAIT_TYPE;

typedef enum
{
	YKE_EVENT_WAIT_FINISH = 0,

	YKE_EVENT_WAIT_START = 1,
}YKE_EVENT_WAIT_TYPE;

typedef enum
{
	YKE_CURVE_S7 = 0,

	YKE_CURVE_T7 = 1,

	YKE_CURVE_TS = 2,

	YKE_CURVE_T7_TIME = 3,

	YKE_CURVE_S7_RATE = 4,
}YKE_CURVE_TYPE;

typedef enum
{
	YKE_SWITCH_NONE = 0,

	YKE_SWITCH_COE_REG = 1,

	YKE_SWITCH_GLOBAL_DIO = 2,

	YKE_SWITCH_LOCAL_DIO = 3,

	YKE_SWITCH_MECHANICAL = 4,
}YKE_SWITCH_TYPE;

typedef enum
{
	YKE_LNG_CHN = 0,
}YKE_LANGUAGE;

typedef enum
{
	YKE_BUFFER_NONE = 0x0000,

	YKE_BUFFERED = 0x0001,

	YKE_BLENDING_LOW = 0x0002,

	YKE_BLENDING_PREV = 0x0003,

	YKE_BLENDING_NEXT = 0x0004,

	YKE_BLENDING_HIGH = 0x0005,
}YKE_BUFFER_MODE;

typedef enum
{
	YKE_TRANS_NONE = 0x0000,

	YKE_CORNER_DISTANCE = 0x0003,

	YKE_MAX_CORNER_DEVIATION = 0x0004,
}YKE_TRANSITION_MODE;

typedef enum
{
	YKE_CIRCULAR_BORDER = 0x0000,

	YKE_CIRCULAR_CENTER = 0x0001,
}YKE_CIRCULAR_AUX_MODE;

typedef enum
{
	YKE_CIRCULAR_CLOCKWISE = 0x0000,

	YKE_CIRCULAR_COUNTERCLOCKWISE = 0x0001,

	YKE_CIRCULAR_DEFINED_BY_AUX_POINT = 0x0002,
}YKE_CIRCULAR_PATH_CHOICE;

typedef enum
{
	YKE_DIRECTION_POSITIVE = 0,

	YKE_DIRECTION_NEGATIVE = 1,

	YKE_DIRECTION_NONE = 2,
}YKE_DIRECTION;

typedef enum
{
	YKE_HOME_MODE_00 = 0,

	YKE_HOME_MODE_01 = 1,

	YKE_HOME_MODE_02 = 2,

	YKE_HOME_MODE_03 = 3,

	YKE_HOME_MODE_04 = 4,

	YKE_HOME_MODE_05 = 5,

	YKE_HOME_MODE_06 = 6,

	YKE_HOME_MODE_07 = 7,

	YKE_HOME_MODE_08 = 8,

	YKE_HOME_MODE_09 = 9,

	YKE_HOME_MODE_10 = 10,

	YKE_HOME_MODE_11 = 11,

	YKE_HOME_MODE_12 = 12,

	YKE_HOME_MODE_13 = 13,

	YKE_HOME_MODE_14 = 14,

	YKE_HOME_MODE_15 = 15,

	YKE_HOME_MODE_16 = 16,

	YKE_HOME_MODE_17 = 17,

	YKE_HOME_MODE_18 = 18,

	YKE_HOME_MODE_19 = 19,

	YKE_HOME_MODE_20 = 20,

	YKE_HOME_MODE_21 = 21,

	YKE_HOME_MODE_22 = 22,

	YKE_HOME_MODE_23 = 23,

	YKE_HOME_MODE_24 = 24,

	YKE_HOME_MODE_25 = 25,

	YKE_HOME_MODE_26 = 26,

	YKE_HOME_MODE_27 = 27,

	YKE_HOME_MODE_28 = 28,

	YKE_HOME_MODE_29 = 29,

	YKE_HOME_MODE_30 = 30,

	YKE_HOME_MODE_31 = 31,

	YKE_HOME_MODE_32 = 32,

	YKE_HOME_MODE_33 = 33,

	YKE_HOME_MODE_34 = 34,

	YKE_HOME_MODE_35 = 35,

	YKE_HOME_MODE_36 = 36,

	YKE_HOME_MODE_37 = 37,

	YKE_HOME_MODE_ABS = 38,
}YKE_HOME_MODE;

typedef enum
{
	YKE_STOP_SEL_SMOOTH = 0,

	YKE_STOP_SEL_EMG = 1,

	YKE_STOP_SEL_INS = 2,
}YKE_STOP_DEC;

typedef enum
{
	YKE_ENCODER_MODE_PD = 0,

	YKE_ENCODER_MODE_PN = 1,

	YKE_ENCODER_MODE_AB4 = 2,
}YKE_ENCODER_MODE;

typedef enum
{
	YKE_COMPARE_MODE_FIX = 0,

	YKE_COMPARE_MODE_LINE = 1,

	YKE_COMPARE_MODE_FIFO = 2,
}YKE_COMPARE_MODE;

typedef enum
{
	YKE_TRIG_MODE_UPEDGE = 0,

	YKE_TRIG_MODE_DOWNEDGE = 1,

	YKE_TRIG_MODE_HGIHLEVEL = 2,

	YKE_TRIG_MODE_LOWLEVEL = 3,

	YKE_TRIG_MODE_EDGE = 4,
}YKE_TRIG_MODE;

typedef enum
{
	YKE_OSC_TRIG_FREE = 0,

	YKE_OSC_TRIG_MANUAL = 1,

	YKE_OSC_TRIG_UPEDGE = 2,

	YKE_OSC_TRIG_DOWNEDGE = 3,

	YKE_OSC_TRIG_HIGHLEVEL = 4,

	YKE_OSC_TRIG_LOWLEVEL = 5,

	YKE_OSC_TRIG_UPDOWN = 6,
}YKE_OSC_TRIG_TYPE;

typedef enum
{
	YKE_OSC_ITEM_AXIS = 0,

	YKE_OSC_ITEM_OD = 1,

	YKE_OSC_ITEM_UG = 2,

	YKE_OSC_ITEM_DI = 3,

	YKE_OSC_ITEM_DO = 4,

	YKE_OSC_ITEM_DATA_REG = 5,

	YKE_OSC_ITEM_SYS = 6,

	YKE_OSC_ITEM_GROUP = 7,

	YKE_OSC_ITEM_ENCODER = 8,

	YKE_OSC_ITEM_EVENT = 9,

	YKE_OSC_ITEM_MULTI_AXIS = 10,

	YKE_OSC_ITEM_WAIT = 11,
}YKE_OSC_ITEM_TYPE;

typedef enum
{
	YKE_AXIS_ITEM_CMD_VEL = 0,

	YKE_AXIS_ITEM_ACT_VEL = 1,

	YKE_AXIS_ITEM_CMD_POS = 2,

	YKE_AXIS_ITEM_ACT_POS = 3,

	YKE_AXIS_ITEM_CMD_TQ = 4,

	YKE_AXIS_ITEM_ACT_TQ = 5,

	YKE_AXIS_ITEM_CMD_ACC = 6,

	YKE_AXIS_ITEM_CMD_JERK = 7,

	YKE_AXIS_ITEM_TARGET_POS = 11,

	YKE_AXIS_ITEM_COE_MODE = 12,

	YKE_AXIS_ITEM_ENCODER = 13,

	YKE_AXIS_ITEM_WARN_ID = 14,

	YKE_AXIS_ITEM_PITCH = 15,

	YKE_AXIS_ITEM_BACKLASH = 16,

	YKE_AXIS_ITEM_CMD_DONE = 20,

	YKE_AXIS_ITEM_ACTIVE1 = 21,

	YKE_AXIS_ITEM_ACTIVE2 = 22,

	YKE_AXIS_ITEM_DONE = 23,

	YKE_AXIS_ITEM_POWER_ON = 24,

	YKE_AXIS_ITEM_CHANGE = 25,

	YKE_AXIS_ITEM_REMAIN_TIM = 30,

	YKE_AXIS_ITEM_TOTAL_TIM = 31,

	YKE_AXIS_ITEM_COMPLETE_TIM = 32,

	YKE_AXIS_ITEM_POS_LAG = 40,

	YKE_AXIS_ITEM_POS_LAG_FILTER = 41,

	YKE_AXIS_ITEM_GANTRY_CMDERR = 42,

	YKE_AXIS_ITEM_GANTRY_ACTERR = 43,

	YKE_AXIS_ITEM_HOME = 50,

	YKE_AXIS_ITEM_HD_POSITIVE = 51,

	YKE_AXIS_ITEM_HD_NEGATIVE = 52,

	YKE_AXIS_ITEM_SOFT_POSITIVE = 53,

	YKE_AXIS_ITEM_SOFT_NEGATIVE = 54,

	YKE_AXIS_ITEM_INPOS1 = 60,

	YKE_AXIS_ITEM_INPOS2 = 61,

	YKE_AXIS_ITEM_INPOS3 = 62,

	YKE_AXIS_ITEM_INPOS4 = 63,

	YKE_AXIS_ITEM_INPOS5 = 64,

	YKE_AXIS_ITEM_INPOS6 = 65,

	YKE_AXIS_ITEM_USER_TEST = 100,
}YKE_AXIS_ITEM_TYPE;

typedef enum
{
	YKE_EVENT_ITEM_START = 0,

	YKE_EVENT_ITEM_STATUS = 1,
}YKE_EVENT_ITEM_TYPE;

typedef enum
{
	YKE_MULTI_AXIS_ITEM_ACTIVE = 0,

	YKE_MULTI_AXIS_ITEM_DONE = 1,

	YKE_MULTI_AXIS_ITEM_REMAIN_TIM = 10,

	YKE_MULTI_AXIS_ITEM_TOTAL_TIM = 11,

	YKE_MULTI_AXIS_ITEM_ACCELERATION = 21,
}YKE_MULTI_AXIS_ITEM_TYPE;

typedef enum
{
	YKE_WAIT_ITEM_ACTIVE = 0,
}YKE_WAIT_ITEM_TYPE;

typedef enum
{
	YKE_AXIS_FOLLOW_CMD_POS = 0,

	YKE_AXIS_FOLLOW_ACT_POS = 1,
}YKE_AXIS_FOLLOW_TYPE;

typedef enum
{
	YKE_AXIS_COMPARE_CMD_POS = 0,

	YKE_AXIS_COMPARE_ACT_POS = 1,
}YKE_AXIS_COMPARE_TYPE;

typedef enum
{
	YKE_FOLLOW_GROUP_DIST_2D = 10,

	YKE_FOLLOW_GROUP_DIST_3D = 11,
}YKE_FOLLOW_GROUP_TYPE;

typedef enum
{
	YKE_SYS_ITEM_MOTICK = 0,

	YKE_SYS_ITEM_DC_JITTER = 1,

	YKE_SYS_ITEM_DC_ADJUST = 2,

	YKE_SYS_ITEM_CPU_FREQ = 3,

	YKE_SYS_ITEM_PAYLOAD_YKG = 4,

	YKE_SYS_ITEM_PAYLOAD_NTF = 5,

	YKE_SYS_ITEM_PAYLOAD_CNC = 6,

	YKE_SYS_ITEM_PAYLOAD_ALL = 7,

	YKE_SYS_ITEM_TEST1 = 31,

	YKE_SYS_ITEM_TEST2 = 32,

	YKE_SYS_ITEM_TEST3 = 33,

	YKE_SYS_ITEM_TEST4 = 34,

	YKE_SYS_ITEM_TEST5 = 35,
}YKE_SYSTEM_ITEM_TYPE;

typedef enum
{
	YKE_DRV_OP_MODE_NONE = 0,

	YKE_DRV_OP_MODE_PP = 1,

	YKE_DRV_OP_MODE_PV = 3,

	YKE_DRV_OP_MODE_TQ = 4,

	YKE_DRV_OP_MODE_HM = 6,

	YKE_DRV_OP_MODE_CSP = 8,

	YKE_DRV_OP_MODE_CSV = 9,

	YKE_DRV_OP_MODE_CST = 10,
}YKE_DRV_OP_MODE;

typedef enum
{
	YKE_AXIS_FOLLOW_SCALE = 0,

	YKE_AXIS_FOLLOW_ACC = 1,
}YKE_AXIS_FOLLOW_MODE;

typedef enum
{
	YKE_CONVEYOR_SYNC_SYNC_ACTIVE = 0,

	YKE_CONVEYOR_SYNC_FAIL = 1,

	YKE_CONVEYOR_SYNC_DONE = 2,
}YKE_CONVEYOR_SYNC_STATUS;

typedef enum
{
	YKE_PULSE_DIR = 0,

	YKE_PULSE_PN = 1,
}YKE_PULSE_MODE;

typedef enum
{
	YKE_CAPTURE_ENCODER = 0,

	YKE_CAPTURE_CMD_PULSE = 1,
}YKE_CAPTURE_SOURCE;

typedef enum
{
	YKE_CAM_CURVE_POLY = 0,

	YKE_CAM_CURVE_SPLINE = 1,
}YKE_CAM_CURVE;

typedef enum
{
	YKE_COMBINE_ADD = 0,

	YKE_COMBINE_SUB = 1,

	YKE_COMBINE_DIST = 10,
}YKE_COMBINE_MODE;

typedef enum
{
	YKE_SLAVE_ITEM_REMOVE = 1,

	YKE_SLAVE_ITEM_ENABLE = 2,
}YKE_SLAVE_ITEM;

typedef enum
{
	YKE_INT8 = 0,

	YKE_UINT8 = 1,

	YKE_INT16 = 2,

	YKE_UINT16 = 3,

	YKE_INT32 = 4,

	YKE_UINT32 = 5,
}YKE_DATA_TYPE;

typedef enum
{
	YKE_FALSE = 0,

	YKE_TRUE = 1,
}YKE_BOOL;

typedef enum
{
	YKE_MOTION_NONE = 0,

	YKE_MOTION_POSITION = 1,

	YKE_MOTION_VELOCITY = 2,

	YKE_MOTION_TORQUE = 3,

	YKE_MOTION_HOME = 4,

	YKE_MOTION_SOFT_FOLLOW = 5,

	YKE_MOTION_HARD_FOLLOW = 6,

	YKE_MOTION_GROUP = 7,

	YKE_MOTION_MULTI_AXIS = 8,

	YKE_MOTION_PVT = 9,
}YKE_MOTION_TYPE;

typedef enum
{
	YKE_ERR_LINK_NONE = 0,

	YKE_ERR_LINK_WKC = 1,

	YKE_ERR_LINK_SEND = 2,

	YKE_ERR_LINK_REV = 3,

	YKE_ERR_LINK_READREG = 4,

	YKE_ERR_LINK_SEND_SIZE = 13,

	YKE_ERR_LINK_SEND_QUENE = 14,

	YKE_ERR_LINK_REV_QUENE = 15,

	YKE_ERR_LINK_ALLOC_REV = 22,

	YKE_ERR_LINK_ALLOC_SEND = 23,

	YKE_ERR_LINK_DC_ADJUST = 27,

	YKE_ERR_LINK_REDUNDANCY = 31,
}YKE_LINK_ERROR;

typedef enum
{
	YKE_BUS_STATUS_IDEL = 0,

	YKE_BUS_STATUS_INITING = 1,

	YKE_BUS_STATUS_ERR = 2,

	YKE_BUS_STATUS_RUNNING = 10,
}YKE_BUS_STATUS;

typedef enum
{
	YKE_SYNC_AXIS_LIMIT = 0,

	YKE_SYNC_AXIS_SLOWEST = 1,

	YKE_SYNC_AXIS_FARTHESET = 2,

	YKE_SYNC_FIX_TIME = 3,
}YKE_SYNC_AXIS_MODE;

typedef enum
{
	YKE_GROUP_OUTPUT_IN_WARN_KEEP = 0,

	YKE_GROUP_OUTPUT_IN_WARN_HIGH = 1,

	YKE_GROUP_OUTPUT_IN_WARN_LOW = 2,
}YKE_GROUP_OUTPUT_IN_WARN;

typedef enum
{
	YKE_EMG_AXIS_KEEP = 0,

	YKE_EMG_AXIS_STOP = 1,

	YKE_EMG_AXIS_POWEROFF = 2,
}YKE_EMG_AXIS_BEGAVIOR;

typedef enum
{
	YKE_GROUP_ITEM_ACTIVE = 0,

	YKE_GROUP_ITEM_DONE = 1,

	YKE_GROUP_ITEM_CUR_LINE = 10,

	YKE_GROUP_ITEM_CURMARK = 11,

	YKE_GROUP_ITEM_VEL = 12,

	YKE_GROUP_ITEM_ACC = 13,

	YKE_GROUP_ITEM_JERK = 14,

	YKE_GROUP_ITEM_WARN1 = 15,

	YKE_GROUP_ITEM_WARN2 = 16,

	YKE_GROUP_ITEM_VEL_2D = 20,

	YKE_GROUP_ITEM_VEL_3D = 21,

	YKE_GROUP_ITEM_DIST_2D = 22,

	YKE_GROUP_ITEM_DIST_3D = 23,

	YKE_GROUP_ITEM_WORKPIECE_X = 30,

	YKE_GROUP_ITEM_WORKPIECE_Y = 31,

	YKE_GROUP_ITEM_WORKPIECE_Z = 32,

	YKE_GROUP_ITEM_WORKPIECE_A = 33,

	YKE_GROUP_ITEM_WORKPIECE_B = 34,

	YKE_GROUP_ITEM_WORKPIECE_C = 35,

	YKE_GROUP_ITEM_DEBUG1 = 100,

	YKE_GROUP_ITEM_DEBUG2 = 101,

	YKE_GROUP_ITEM_DEBUG3 = 102,

	YKE_GROUP_ITEM_DEBUG4 = 103,

	YKE_GROUP_ITEM_DEBUG5 = 104,
}YKE_GROUP_ITEM_TYPE;

typedef enum
{
	YKE_GROUP_COMPARE_START_IMMEDIATELY = 0,

	YKE_GROUP_COMPARE_END_IMMEDIATELY = 1,

	YKE_GROUP_COMPARE_COMPLETED_TIME = 2,

	YKE_GROUP_COMPARE_COMPLETED_DIST = 3,

	YKE_GROUP_COMPARE_REMAINING_TIME = 4,

	YKE_GROUP_COMPARE_REMAINING_DIST = 5,

	YKE_GROUP_COMPARE_COMPLETED_RATE = 6,
}YKE_GROUP_COMPARE_MODE;

typedef enum
{
	YKE_GROUP_DO_SINGLE = 0,

	YKE_GROUP_DO_ALTERNATE = 1,

	YKE_GROUP_DO_PULSE = 2,
}YKE_GROUP_DO_MODE;

typedef enum
{
	YKE_GROUP_PWM_FIX = 0,

	YKE_GROUP_PWM_DUTY = 1,

	YKE_GROUP_PWM_FREQ = 2,
}YKE_GROUP_PWM_MODE;

typedef enum
{
	YKE_AXIS_SIM_LINEAR = 0,

	YKE_AXIS_SIM_ROTARY = 1,
}YKE_AXIS_SIM_TYPE;

typedef enum
{
	YKE_TRIGGER_REMAINING_TIME = 0,

	YKE_TRIGGER_REMAINGING_DISTANCE = 1,

	YKE_TRIGGER_SAMETIME_COMPLETION = 2,

	YKE_TRIGGER_COMPLETED_TIME = 3,

	YKE_TRIGGER_COMPLETED_DISTANCE = 4,

	YKE_TRIGGER_STAGGERED_TIME_COMPLETION = 5,

	YKE_TRIGGER_STAGGERED_DISTANCE_COMPLETION = 6,
}YKE_TRIGGER_TYPE;

typedef enum
{
	YKE_SIGNAL_SOURCE_INPUT = 0,

	YKE_SIGNAL_SOURCE_OUTPUT = 1,

	YKE_SIGNAL_SOURCE_EVENT = 2,

	YKE_SIGNAL_SOURCE_REG = 3,
}YKE_SIGNAL_SOURCE_TYPE;

typedef enum
{
	YKE_LOGIC_AND = 0,

	YKE_LOGIC_OR = 1,

	YKE_LOGIC_NAND = 2,

	YKE_LOGIC_NOR = 3,
}YKE_LOGIC_CONDITIONS;

typedef enum
{
	YKE_EVENT_STATUS_IDEL = 0,

	YKE_EVENT_STATUS_WAIT = 5,

	YKE_EVENT_STATUS_RESTART = 10,

	YKE_EVENT_STATUS_DELAY = 15,

	YKE_EVENT_STATUS_FINISH = 20,
}YKE_EVENT_STATUS_TYTE;

typedef enum
{
	YKE_CNC_ACTION_INTER = 0,

	YKE_CNC_ACTION_PRE = 1,

	YKE_CNC_ACTION_POST = 2,
}YKE_CNC_ACTION_TYPE;

typedef enum
{
	YKE_CNC_ASPLINE_TRANS_AUTO = 0,

	YKE_CNC_ASPLINE_TRANS_TANGENTIAL = 1,

	YKE_CNC_ASPLINE_TRANS_USER = 2,
}YKE_CNC_ASPLINE_TRANS_TYPE;

typedef enum
{
	YKE_CNC_CHECKJERK_NO = 0,

	YKE_CNC_CHECKJERK_GEOMERTRIC = 1,

	YKE_CNC_CHECKJERK_NOLIEAR = 2,
}YKE_CNC_CHECK_JERK_TYPE;

typedef enum
{
	YKE_HSC_CIR_MODE_CONTOUR = 0,

	YKE_HSC_CIR_MODE_NOCONTOUR = 1,

	YKE_HSC_CIR_MODE_CONTOUR_LONG = 2,
}YKE_HSC_CIR_MODE;

typedef enum
{
	YKE_CNC_INS_API = 0,

	YKE_CNC_INS_FILE = 1,

	YKE_CNC_EXTERN = 2,
}YKE_CNC_INS_MODE;

typedef enum
{
	YKE_LOGGER_FILTER_ALL = 0,

	YKE_LOGGER_FILTER_INCLUDE = 1,

	YKE_LOGGER_FILTER_EXCLUDE = 2,
}YKE_LOGGER_FILTER_TYPE;

typedef enum
{
	YKE_LICENSE_OK = 0,

	YKE_LICENSE_AXIS = 1,

	YKE_LICENSE_GROUP = 2,

	YKE_LICENSE_VISION = 3,

	YKE_LICENSE_ECAM = 4,

	YKE_LICENSE_PLC = 5,

	YKE_LICENSE_HMI = 6,

	YKE_LICENSE_RT = 7,

	YKE_LICENSE_NTF = 8,

	YKE_LICENSE_PC_250 = 9,

	YKE_LICENSE_API = 10,

	YKE_LICENSE_SUID = 20,

	YKE_LICENSE_TEMP = 21,

	YKE_LICENSE_SHELL = 30,
}YKE_LICENSE_STATUS;

typedef enum
{
	YKE_PROJECT_GCONFIG = 0x01,

	YKE_PROJECT_AXIS = 0x02,

	YKE_PROJECT_CARD = 0x04,

	YKE_PROJECT_ECAT = 0x08,
}YKE_PROJECT_MASK;

typedef enum
{
	YKE_SCAN_NONE = 0x00,

	YKE_SCAN_VID = 0x01,

	YKE_SCAN_SLOT = 0x02,
}YKE_SCAN_INFO;

typedef enum
{
	YKE_PDS_NONE = 0x00,

	YKE_PDS_LOAD = 10,

	YKE_PDS_ING = 20,

	YKE_PDS_EEP = 21,

	YKE_PDS_PREOP = 24,

	YKE_PDS_SAFEOP = 25,

	YKE_PDS_PDO = 30,

	YKE_PDS_RUN = 40,
}YKE_PDS_PHASE;

typedef enum
{
	YKE_DOGGLE_A = 0,

	YKE_DOGGLE_B = 1,
}YKE_DOGGLE_TYPE;

typedef enum
{
	YKE_PLC_CMD_NONE = 0,

	YKE_PLC_CMD_PRG_START = 1,

	YKE_PLC_CMD_PRG_STOP = 2,

	YKE_PLC_CMD_SYS_EXIT = 10,
}YKE_PLC_CMD_TYPE;

typedef enum
{
	YKE_500US_TICK = 0,

	YKE_1MS_TICK = 1,

	YKE_5MS_TICK = 2,

	YKE_50MS_TICK = 3,

	YKE_500MS_TICK = 4,

	YKE_30S_TICK = 5,

	YKE_TIME_SEC = 10,

	YKE_TIME_MIN = 11,

	YKE_TIME_HOUR = 12,

	YKE_TIME_DAY = 13,

	YKE_TIME_MONTH = 14,

	YKE_TIME_YEAR = 15,

	YKE_TIME_WEEK = 16,

	YKE_HMI_CURRENT_PAGE = 100,

	YKE_HMI_CHANGE_PAGE = 101,

	YKE_HMI_CHANGE_USER = 102,

	YKE_HMI_CHANGE_RECIPE = 103,

	YKE_HMI_RESTART = 110,

	YKE_HMI_CLOSE = 111,

	YKE_HMI_CUR_USER_PW = 118,

	YKE_HMI_CHANGE_USER_NAME = 120,

	YKE_HMI_CUR_USER_NAME = 140,

	YKE_HMI_CUR_RECIPE_NAME = 160,

	YKE_HMI_CHANGE_RECIPE_NAME = 180,
}YKE_SPEC_REG;

typedef struct _YKS_POINT3
{
	double x;

	double y;

	double z;
}YKS_POINT3;

typedef struct _YKS_AxisSwitchConfig
{
	YKE_SWITCH_TYPE type;

	UINT32 byte_offset;

	UINT32 bit_offset;

	YKE_BOOL inv_or_edge;

	double position_error;

	double hold_time;

	UINT32 res1[8];
}YKS_AxisSwitchConfig;

typedef struct _YKS_SysProfile
{
	char path[260];

	UINT32 res6;

	UINT32 config_axis_num;

	UINT32 config_input_size;

	UINT32 config_output_size;

	UINT32 dog_serial_numberA;

	char dog_serial_numberB[64];

	UINT32 dog_mem_sizeA;

	UINT32 dog_mem_sizeB;

	double res0;

	UINT32 dog_axis_num;

	UINT32 dog_axis_used;

	UINT32 dog_ecam_num;

	UINT32 dog_ecam_used;

	UINT32 dog_vision_num;

	UINT32 dog_vision_used;

	UINT32 dog_plc_num;

	UINT32 dog_plc_used;

	UINT32 dog_hmi_num;

	UINT32 dog_hmi_used;

	UINT32 dog_comm_num;

	UINT32 dog_comm_used;

	UINT32 dog_cad_num;

	UINT32 dog_cad_used;

	UINT32 dog_group_num;

	UINT32 dog_group_used;

	UINT32 dog_dotNetRT_num;

	UINT32 dog_dotNetRT_used;

	YKE_BOOL dog_date_flag;

	UINT32 dog_date_uid;

	UINT32 dog_date_year;

	UINT32 dog_date_month;

	UINT32 dog_date_day;

	UINT32 res1;

	UINT32 dog_pc_num;

	UINT32 dog_pc_used;

	YKE_LICENSE_STATUS lic_status;

	YKE_BOOL dog_err;

	YKE_BOOL node_ena[4];

	YKE_BOOL cnc_enable[4];

	UINT32 runtime_ver;

	UINT32 plann_ver;

	YKE_BOOL sim_mode;

	YKE_NODE ecat_snap_node;

	UINT32 ecat_snap_span;

	UINT32 plc_enable;

	YKE_NODE plc_node;

	UINT32 dog_api_num;

	UINT32 dog_api_used;

	UINT32 res5[31];

	double res2[32];
}YKS_SysProfile;

typedef struct _YKS_DigitalIO
{
	UINT32 byte_offset;

	UINT32 bit_offset;

	YKE_BOOL inv;

	UINT32 res;
}YKS_DigitalIO;

typedef struct _YKS_DigitalInput
{
	YKE_BOOL enable;

	UINT32 byte_index;

	UINT32 bit_offset;

	YKE_BOOL inv;

	double filter_tim;

	YKE_BOOL value;

	UINT32 res1[7];
}YKS_DigitalInput;

typedef struct _YKS_DigitalOutput
{
	YKE_BOOL enable;

	UINT32 byte_index;

	UINT32 bit_offset;

	YKE_BOOL valid;

	UINT32 res[8];
}YKS_DigitalOutput;

typedef struct _YKS_DigitalOutputCycle
{
	UINT32 byte_index;

	UINT32 bit_offset;

	YKE_BOOL valid;

	UINT32 res[4];
}YKS_DigitalOutputCycle;

typedef struct _YKS_BlueScreenConfig
{
	YKE_BOOL enable;

	YKE_BOOL stop_axis;

	YKE_BOOL close_output;

	UINT32 res;

	UINT32 res1[8];
}YKS_BlueScreenConfig;

typedef struct _YKS_HardEmgProfile
{
	YKS_DigitalInput emg_stop_input[8];

	YKS_DigitalOutput emg_stop_output[4];

	UINT32 res1[8];

	double res2[8];
}YKS_HardEmgProfile;

typedef struct _YKS_EmgStatus
{
	YKE_BOOL emg_stop_soft;

	YKE_BOOL emg_stop_input[8];

	UINT32 emg_stop_input_all;

	UINT32 res1[8];

	double res2[4];
}YKS_EmgStatus;

typedef struct _YKS_BusStatus
{
	UINT32 config_num;

	UINT32 useable_num;

	UINT32 active_num;

	UINT32 res0;

	double min_payload;

	double max_payload;

	double cur_payload;

	double min_shift;

	double max_shift;

	double cur_shift;

	double dc_cycle;

	UINT32 lost_frames;

	UINT32 lost_wkc;

	YKE_BOOL master_active;

	UINT32 offline_num;

	UINT32 cpu_ticks_vel;
	UINT32 cpu_ticks_low;

	double max_ykg_payload;

	double cur_ykg_payload;

	double max_nt_payload;

	double cur_nt_payload;

	double max_cnc_payload;

	double cur_cnc_payload;

	UINT32 heart_tick_vel;
	UINT32 heart_tick_low;

	YKE_SYSTEM_ERROR sys_error_type;

	UINT32 sys_error_code1;

	UINT32 sys_error_code2;

	YKE_LINK_ERROR link_error_type;

	UINT32 link_error_code1;

	UINT32 link_error_code2;

	YKE_BUS_STATUS bus_status;

	UINT32 sys_sdo_idel;

	UINT32 user_sdo_idel;

	UINT32 frame_length[16];

	YKE_PDS_PHASE pds_phase;

	UINT32 debug1;

	UINT32 debug2;

	UINT32 debug3;

	UINT32 res1[9];

	double res2[32];
}YKS_BusStatus;

typedef struct _YKS_BusPacketHeader
{
	double time;

	YKE_BOOL rev_flag;

	UINT8 source_mac[6];

	UINT8 destion_mac[6];

	UINT32 ethernet_type;

	UINT32 length;

	UINT32 res1[4];

	double res2[4];
}YKS_BusPacketHeader;

typedef struct _YKS_SdoStatus
{
	YKE_BOOL valid;

	UINT32 data;

	double tim;

	UINT32 res1[8];
}YKS_SdoStatus;

typedef struct _YKS_SlaveStatus
{
	UINT16 esc_status;

	UINT16 station_id;

	INT32 clock_offset;

	YKE_SLAVE_ERROR slave_error_type;

	UINT32 slave_error_code;

	UINT32 coe_type;

	UINT32 coe_code;

	UINT32 al_res;

	UINT32 al_code;

	YKE_BOOL offline;

	UINT32 pdo_start;

	UINT32 pdo_length;

	UINT32 user_vid;

	UINT32 user_pid;

	UINT32 user_revsion;

	UINT32 eep_vid;

	UINT32 eep_pid;

	UINT32 eep_revsion;

	YKE_BOOL port_link[4];

	UINT32 res1[9];

	double res2[24];
}YKS_SlaveStatus;

typedef struct _YKS_SlavePdoConfig
{
	UINT32 main_index;

	UINT32 sub_index;

	UINT32 bit_num;

	UINT32 bit_offset;

	UINT32 g_index;

	UINT32 res[8];
}YKS_SlavePdoConfig;

typedef struct _YKS_AxisProfileModulo
{
	YKE_BOOL enable;

	YKE_BOOL drv_modulo_status;

	UINT32 single_encoder_count;

	YKE_BOOL half_turn;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProfileModulo;

typedef struct _YKS_AxisProfileMotion
{
	YKE_CURVE_TYPE curve_type;

	UINT32 res0;

	double start_velocity;

	double stop_velocity;

	double velocity;

	double acceleration;

	double deceleration;

	double acc_time;

	double dec_time;

	double acc_rate;

	double dec_rate;

	double jerk_acc;

	double jerk_dec;

	double constant_velocity_time;

	double constant_acc_time;

	double constant_dec_time;

	double smooth_time;

	double res[28];
}YKS_AxisProfileMotion;

typedef struct _YKS_AxisProfileBase
{
	double max_velocity;

	double max_acceleration;

	double max_jerk;

	double stop_dec_emg;

	double stop_dec_smooth;

	double stop_dec_limitsoft;

	double stop_dec_jerk;

	YKE_BOOL enable_cnc;

	YKE_EMG_AXIS_BEGAVIOR emg_behavior;

	UINT32 emg_mask;

	UINT32 res0;

	double debug1;

	UINT32 res1[16];

	UINT32 res2[16];
}YKS_AxisProfileBase;

typedef struct _YKS_AxisProfileInp
{
	double inp;

	double inp_tim;

	double inp_timout;

	double inp1_fb;

	double inp2_fb;

	double inp3_fb;

	double inp4_fb;

	double inp5_fb;

	double inp6_fb;

	double tq_inp;

	double tq_tim;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProfileInp;

typedef struct _YKS_AxisProfilePositionLag
{
	double position_lag_tim;

	double position_lag_limit;

	double position_lag_filter_time;

	double master_position_lag_limit;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProfilePositionLag;

typedef struct _YKS_AxisProfileClearDrv
{
	double wait_tim;

	UINT32 retry;

	YKE_BOOL force;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProfileClearDrv;

typedef struct _YKS_AxisProfilePowerOn
{
	double wait_tim;

	double lock_tim;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProfilePowerOn;

typedef struct _YKS_AxisProfileFeedforward
{
	YKE_BOOL enable;

	UINT32 res;

	double velocity_weighting;

	double velocity_delay;

	double acceleration_weighting;

	double acceleration_delay;

	double jerk_weighting;

	double jerk_delay;

	double global_weighting;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProfileFeedforward;

typedef struct _YKS_AxisConfigBase
{
	YKE_NODE master;

	YKE_AXIS_PHY phy_type;

	UINT32 phy_main;

	UINT32 phy_sub;

	UINT32 res1[16];

	double res2[16];
}YKS_AxisConfigBase;

typedef struct _YKS_AxisStatusPlanner
{
	UINT32 plann_flag;

	YKE_BOOL command_done;

	double command_done_time;

	double command_run_time;

	double actual_run_time;

	double command_total_time;

	double command_remain_time;

	double change_time;

	double payload;

	UINT32 res1[16];

	double res2[16];
}YKS_AxisStatusPlanner;

typedef struct _YKS_AxisStatusPosition
{
	INT32 encoder_raw_position;

	UINT32 res;

	INT32 position_offset_vel;
	INT32 position_offset_low;

	double position_lag;

	double position_lag_filter;

	YKE_BOOL fb_inp1;

	YKE_BOOL fb_inp2;

	YKE_BOOL fb_inp3;

	YKE_BOOL fb_inp4;

	YKE_BOOL fb_inp5;

	YKE_BOOL fb_inp6;

	UINT32 res1[16];

	double res2[16];
}YKS_AxisStatusPosition;

typedef struct _YKS_AxisStatusCompensation
{
	YKE_BOOL pitch1d_active;

	YKE_BOOL pitch2d_active;

	YKE_BOOL backlash_active;

	UINT32 res;

	double pitch_value;

	double backlash_value;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisStatusCompensation;

typedef struct _YKS_AxisStatusFollow
{
	YKE_BOOL follow_master;

	YKE_BOOL gantry_enable;

	UINT32 gantry_master_index;

	UINT32 res;

	double gantry_actual_err;

	double follow_actual_err;

	YKE_CONVEYOR_SYNC_STATUS converyor_sync_status;

	UINT32 res1[7];

	double res2[8];
}YKS_AxisStatusFollow;

typedef struct _YKS_AxisStatusBase
{
	YKE_MOTION_TYPE motion_type;

	YKE_AXIS_STOP_TYPE stop_type;

	YKE_DIRECTION direction;

	YKE_BOOL power_on;

	YKE_BOOL is_homed;

	UINT32 active;

	YKE_BOOL done;

	UINT32 lock_busy;

	UINT32 warnning;

	YKE_MC_ERROR axis_warn_id;

	UINT32 drv_error_id;

	YKE_BOOL offline;

	YKE_BOOL home_switch;

	YKE_BOOL limit_switch_pos;

	YKE_BOOL limit_switch_neg;

	YKE_BOOL limit_soft_pos;

	YKE_BOOL limit_soft_neg;

	UINT32 soft_emg;

	UINT32 hard_emg;

	UINT32 circle_zone;

	UINT32 res1[16];

	double res2[16];
}YKS_AxisStatusBase;

typedef struct _YKS_MultiAxisStatus
{
	YKE_BOOL active;

	YKE_BOOL done;

	YKE_MC_ERROR error;

	YKE_NODE master;

	double total_tim;

	double completed_dist;

	double remain_dist;

	double completed_tim;

	double remain_tim;

	UINT32 debug1;

	UINT32 res1[9];

	double res2[8];
}YKS_MultiAxisStatus;

typedef struct _YKS_AxisProbeConfigSoft
{
	YKS_DigitalIO input;

	YKE_TRIG_MODE trig_mode;

	YKE_BOOL trig_once;

	YKE_AXIS_ITEM_TYPE item;

	UINT32 res;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProbeConfigSoft;

typedef struct _YKS_AxisProbeStatusSoft
{
	YKE_BOOL active;

	UINT32 count;

	double value;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisProbeStatusSoft;

typedef struct _YKS_AxisHomeConfig
{
	YKE_CURVE_TYPE curve_type;

	YKE_HOME_MODE mode;

	YKE_BOOL out_of_probe;

	YKE_BOOL pre_probe;

	UINT32 index_probe;

	YKE_BOOL keep_position;

	YKE_BOOL clear_encoder;

	UINT32 res1[7];

	double logic_position;

	double vel_high;

	double vel_low;

	double acceleration;

	double jerk;

	double switch_move;

	double probe_move;

	double offset;

	double torque_limit;

	double res[8];
}YKS_AxisHomeConfig;

typedef struct _YKS_MovePositionSimResult
{
	double acc_tim;

	double constant_tim;

	double dec_tim;

	double total_tim;

	double velocity;

	double position_of_time;

	double velocity_of_time;

	double acceleration_of_time;

	double jerk_of_time;

	double time_of_position;

	double velocity_of_position;

	double acceleration_of_position;

	double jerk_of_position;

	UINT32 res1[16];

	double res2[16];
}YKS_MovePositionSimResult;

typedef struct _YKS_MoveAbsoluteConfig
{
	double position;

	YKS_AxisProfileMotion motion;

	double res[4];
}YKS_MoveAbsoluteConfig;

typedef struct _YKS_MovePositionSimTrigger
{
	YKE_BOOL enable;

	YKE_BOOL at_mode;

	YKE_TRIGGER_TYPE trigger_type;

	UINT32 res;

	double trigger_value;

	double at_position;

	YKS_AxisProfileMotion motion;

	double new_position;

	UINT32 res1[8];

	double res2[8];
}YKS_MovePositionSimTrigger;

typedef struct _YKS_MovePositionSimConfig
{
	YKS_AxisProfileMotion motion;

	double position;

	YKE_BOOL time_type;

	YKE_BOOL set_start_pos;

	double start_pos;

	double at_position;

	double at_time;

	YKE_BOOL at_calc;

	UINT32 res1[15];

	double res2[16];
}YKS_MovePositionSimConfig;

typedef struct _YKS_MoveConveyorConfig
{
	YKE_DIRECTION direction;

	UINT32 res;

	double distance;

	double velocity;

	UINT32 res1[8];

	double res2[8];
}YKS_MoveConveyorConfig;

typedef struct _YKS_MoveRelativeConfig
{
	double distance;

	YKS_AxisProfileMotion motion;

	double res[4];
}YKS_MoveRelativeConfig;

typedef struct _YKS_MoveVelocityConfig
{
	YKE_DIRECTION direction;

	UINT32 res0;

	YKS_AxisProfileMotion motion;

	double res[4];
}YKS_MoveVelocityConfig;

typedef struct _YKS_MoveTorqueConfig
{
	double velocity_max;

	double torque;

	UINT32 res1[8];

	double res2[8];
}YKS_MoveTorqueConfig;

typedef struct _YKS_BacklashConfig
{
	YKE_DIRECTION dir;

	UINT32 res0;

	double backlash_high;

	double backlash_low;

	double distance_high;

	double distance_low;

	double res[4];
}YKS_BacklashConfig;

typedef struct _YKS_PitchError1DConfig
{
	UINT32 count;

	UINT32 origin_index;

	double origin_position;

	double pitch_interval;

	double catchup_velocity;

	double catchup_acceleration;

	double res[4];
}YKS_PitchError1DConfig;

typedef struct _YKS_PitchError2DConfig
{
	UINT32 axis_index0;

	UINT32 axis_index1;

	UINT32 origin_index0;

	UINT32 origin_index1;

	UINT32 count0;

	UINT32 count1;

	double origin_position0;

	double origin_position1;

	double pitch_interval0;

	double pitch_interval1;

	double catchup_velocity;

	double catchup_acceleration;

	double res[4];
}YKS_PitchError2DConfig;

typedef struct _YKS_FollowAxis1Config
{
	YKE_AXIS_FOLLOW_MODE mode;

	YKE_AXIS_FOLLOW_TYPE source;

	UINT32 axis_master;

	UINT32 res;

	double numerator;

	double denominator;

	double acceleration;

	double deceleration;

	double jerk;

	UINT32 res1[8];

	double res2[8];
}YKS_FollowAxis1Config;

typedef struct _YKS_FollowAxis2Config
{
	YKE_COMBINE_MODE combine_mode;

	YKE_AXIS_FOLLOW_MODE follow_mode;

	YKE_AXIS_FOLLOW_TYPE source1;

	YKE_AXIS_FOLLOW_TYPE source2;

	UINT32 axis_master1;

	UINT32 axis_master2;

	double numerator1;

	double denominator1;

	double numerator2;

	double denominator2;

	double numerator3;

	double denominator3;

	double acceleration;

	double deceleration;

	double jerk;

	UINT32 res1[8];

	double res2[8];
}YKS_FollowAxis2Config;

typedef struct _YKS_FollowUgConfig
{
	YKE_AXIS_FOLLOW_MODE mode;

	YKE_NODE master;

	UINT32 u_index;

	UINT32 g_index;

	YKE_BOOL bit32;

	UINT32 res;

	double filter_tim;

	double numerator;

	double denominator;

	double acceleration;

	double deceleration;

	double jerk;

	UINT32 res1[8];

	double res2[8];
}YKS_FollowUgConfig;

typedef struct _YKS_FollowGroupConfig
{
	UINT32 group_index;

	YKE_AXIS_FOLLOW_MODE mode;

	YKE_FOLLOW_GROUP_TYPE source;

	UINT32 res0;

	double numerator;

	double denominator;

	double acceleration;

	double deceleration;

	double jerk;

	UINT32 res1[8];

	double res2[8];
}YKS_FollowGroupConfig;

typedef struct _YKS_FollowEncoderConfig
{
	YKE_AXIS_FOLLOW_MODE mode;

	UINT32 card_index;

	UINT32 encoder_index;

	UINT32 res;

	double filter_tim;

	double numerator;

	double denominator;

	double acceleration;

	double deceleration;

	double jerk;

	UINT32 res1[8];

	double res2[8];
}YKS_FollowEncoderConfig;

typedef struct _YKS_CamInConfig
{
	UINT32 count;

	YKE_CAM_CURVE curve;

	UINT32 axis_master;

	YKE_BOOL periodic;

	YKE_BOOL master_absolute;

	YKE_BOOL slave_absolute;

	double master_scale;

	double slave_scale;

	double master_offset;

	double slave_offset;

	double start_distance;

	UINT32 res1[8];

	double res2[8];
}YKS_CamInConfig;

typedef struct _YKS_CamTable
{
	double master_position;

	double slave_position;

	double vel_rate;

	double acc_rate;

	UINT32 res1[8];

	double res2[8];
}YKS_CamTable;

typedef struct _YKS_GroupConfig
{
	UINT32 buffer_depth;

	UINT32 axis_num;

	UINT32 axis_list[32];

	YKE_BOOL cnc_enable;

	YKE_CNC_INS_MODE cnc_mode;

	YKE_BOOL close_loop[32];

	UINT32 res1[8];

	double res2[8];
}YKS_GroupConfig;

typedef struct _YKS_GroupProfile
{
	double max_velocity;

	double stop_dec_emg;

	double stop_dec_smooth;

	double stop_dec_jerk;

	YKE_GROUP_OUTPUT_IN_WARN output_in_warm;

	UINT32 emg_mask;

	UINT32 res1[8];

	double res2[8];
}YKS_GroupProfile;

typedef struct _YKS_CncProfile
{
	double feed_rate;

	UINT32 res1[16];

	double res2[16];
}YKS_CncProfile;

typedef struct _YKS_GroupTransMarkConfig
{
	double rotate_x;

	double rotate_y;

	double offset_x;

	double offset_y;

	double scale_x;

	double scale_y;

	double angle;

	double res[4];
}YKS_GroupTransMarkConfig;

typedef struct _YKS_GroupAddiXYConfig
{
	UINT32 axis_x;

	UINT32 axis_y;

	YKS_GroupTransMarkConfig trans_config;

	double res[4];
}YKS_GroupAddiXYConfig;

typedef struct _YKS_GroupStatusBase
{
	YKE_NODE master;

	YKE_BOOL inited;

	YKE_BOOL active;

	YKE_BOOL done;

	YKE_BOOL warnning;

	YKE_BOOL pause;

	YKE_MC_ERROR warn_id;

	UINT32 plan_warn;

	UINT32 soft_emg;

	UINT32 hard_emg;

	UINT32 buffer_idel;

	UINT32 running_line;

	UINT32 running_mark;

	UINT32 res;

	double distance_2d;

	double distance_3d;

	double velocity_2d;

	double velocity_3d;

	double velocity_feed;

	double acceleration_feed;

	double command_time;

	double actual_time;

	UINT32 plann_type;

	UINT32 debug_phase;

	UINT32 res1[8];

	double res2[24];
}YKS_GroupStatusBase;

typedef struct _YKS_GroupStatusCnc
{
	double workpiece_pos[6];

	UINT32 res1[8];

	double res2[24];
}YKS_GroupStatusCnc;

typedef struct _YKS_MoveLinearAbsoluteConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	double position[32];

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	UINT32 mark;

	UINT32 res1;

	double res[8];
}YKS_MoveLinearAbsoluteConfig;

typedef struct _YKS_MoveLinearRelativeConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	double distance[32];

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	UINT32 mark;

	UINT32 res1;

	double res[8];
}YKS_MoveLinearRelativeConfig;

typedef struct _YKS_MoveHelixRelativeConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	YKE_CIRCULAR_PATH_CHOICE path_choice;

	YKE_CIRCULAR_AUX_MODE aux_mode;

	YKS_POINT3 distance;

	YKS_POINT3 aux_point;

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	UINT32 mark;

	UINT32 circle;

	double res[8];
}YKS_MoveHelixRelativeConfig;

typedef struct _YKS_MoveHelixAbsoluteConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	YKE_CIRCULAR_PATH_CHOICE path_choice;

	YKE_CIRCULAR_AUX_MODE aux_mode;

	YKS_POINT3 end_point;

	YKS_POINT3 aux_point;

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	UINT32 mark;

	UINT32 circle;

	double res[8];
}YKS_MoveHelixAbsoluteConfig;

typedef struct _YKS_MoveCircularAbsoluteConfig
{
	UINT32 mark;

	UINT32 axis_num;

	UINT32 axis_list[32];

	double position[32];

	YKE_CIRCULAR_PATH_CHOICE path_choice;

	YKE_CIRCULAR_AUX_MODE aux_mode;

	YKS_POINT3 aux_point;

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	double res[8];
}YKS_MoveCircularAbsoluteConfig;

typedef struct _YKS_MoveCircularRelativeConfig
{
	UINT32 mark;

	UINT32 axis_num;

	UINT32 axis_list[32];

	double distance[32];

	YKE_CIRCULAR_PATH_CHOICE path_choice;

	YKE_CIRCULAR_AUX_MODE aux_mode;

	YKS_POINT3 aux_point;

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	double res[8];
}YKS_MoveCircularRelativeConfig;

typedef struct _YKS_MoveCardinalRelativeConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	double distance[32];

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	UINT32 mark;

	UINT32 res1;

	double res[8];
}YKS_MoveCardinalRelativeConfig;

typedef struct _YKS_MoveCardinalAbsoluteConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	double position[32];

	double velocity;

	double acceleration;

	double deceleration;

	double jerk;

	YKE_BUFFER_MODE buffer_mode;

	YKE_TRANSITION_MODE trans_mode;

	YKS_POINT3 trans_para;

	UINT32 mark;

	UINT32 res1;

	double res[8];
}YKS_MoveCardinalAbsoluteConfig;

typedef struct _YKS_WaitAxis
{
	UINT32 axis_num;

	UINT32 axis_list[32];

	YKE_AXIS_WAIT_TYPE type;

	double timeout;

	double res[4];
}YKS_WaitAxis;

typedef struct _YKS_WaitDigitalInput
{
	UINT32 di_num;

	UINT32 byte_offset[32];

	UINT32 bit_offset[32];

	YKE_DIGITAL_INPUT_WAIT_TYPE type;

	double timeout;

	double res[4];
}YKS_WaitDigitalInput;

typedef struct _YKS_WaitEvent
{
	UINT32 event_num;

	UINT32 event_index[32];

	YKE_EVENT_WAIT_TYPE type;

	double timeout;

	double res[4];
}YKS_WaitEvent;

typedef struct _YKS_WaitStatus
{
	YKE_BOOL active;

	UINT32 res0;

	double time;

	double res[4];
}YKS_WaitStatus;

typedef struct _YKS_CircleZoneConfig
{
	UINT32 axis_num;

	UINT32 axis_list[3];

	YKE_BOOL use_feedback;

	YKE_BOOL outside;

	YKE_STOP_DEC stop_dec;

	UINT32 res0;

	double center[3];

	double radius;

	double res[8];
}YKS_CircleZoneConfig;

typedef struct _YKS_CircleZoneStatus
{
	YKE_BOOL enable;

	YKE_BOOL invalid;
}YKS_CircleZoneStatus;

typedef struct _YKS_CardConfigPCI
{
	UINT32 type;

	UINT32 hardware_ver;

	UINT32 firmware_ver;

	UINT32 dinput_num;

	UINT32 doutput_num;

	UINT32 axis_num;

	UINT32 encode_num;

	UINT32 compare_num;

	UINT32 capture_num;

	UINT32 res;

	UINT32 res1[8];

	double res2[8];
}YKS_CardConfigPCI;

typedef struct _YKS_AxisStausPCI
{
	UINT32 pls_pin;

	UINT32 dir_pin;

	YKE_PULSE_MODE mode;

	UINT32 duty;

	YKE_BOOL switch_limit_negative;

	YKE_BOOL switch_limit_positive;

	YKE_BOOL switch_home;

	YKE_BOOL drv_ready;

	YKE_BOOL drv_warn;

	YKE_BOOL drv_inp;

	YKE_BOOL drv_enable;

	YKE_BOOL drv_reset;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisStausPCI;

typedef struct _YKS_EncoderConfig
{
	YKE_ENCODER_MODE mode;

	YKE_BOOL polarity_a;

	YKE_BOOL polarity_b;

	UINT32 res;

	UINT32 res1[8];

	double res2[8];
}YKS_EncoderConfig;

typedef struct _YKS_CompareConfig
{
	YKE_COMPARE_MODE mode;

	YKE_BOOL enable_2d;

	double keep_time;

	UINT32 number;

	INT32 spacing1;

	INT32 spacing2;

	YKE_BOOL ena_bit0;

	YKE_BOOL ena_bit1;

	YKE_BOOL ena_bit2;

	YKE_BOOL ena_bit3;

	UINT32 res1[7];

	double res2[8];
}YKS_CompareConfig;

typedef struct _YKS_OscItemAxis
{
	UINT32 index;

	YKE_AXIS_ITEM_TYPE type;

	UINT32 res[2];
}YKS_OscItemAxis;

typedef struct _YKS_OscItemGroup
{
	UINT32 index;

	YKE_GROUP_ITEM_TYPE type;

	UINT32 res[2];
}YKS_OscItemGroup;

typedef struct _YKS_OscItemSlaveObject
{
	YKE_NODE node;

	UINT32 slave_index;

	UINT32 main_index;

	UINT32 sub_index;

	UINT32 res[2];
}YKS_OscItemSlaveObject;

typedef struct _YKS_OscItemSlaveUG
{
	YKE_NODE node;

	UINT32 slave_index;

	UINT32 g_index;

	YKE_BOOL g_dword;

	UINT32 res[2];
}YKS_OscItemSlaveUG;

typedef struct _YKS_OscItemDI
{
	UINT32 byte_index;

	UINT32 bit_offset;

	UINT32 res[2];
}YKS_OscItemDI;

typedef struct _YKS_OscItemDO
{
	UINT32 byte_index;

	UINT32 bit_offset;

	UINT32 res[2];
}YKS_OscItemDO;

typedef struct _YKS_OscItemReg
{
	UINT32 index;

	YKE_DATA_TYPE data_type;

	UINT32 res[2];
}YKS_OscItemReg;

typedef struct _YKS_OscItemSystem
{
	YKE_NODE node;

	YKE_SYSTEM_ITEM_TYPE type;

	UINT32 res[2];
}YKS_OscItemSystem;

typedef struct _YKS_OscItemEncoder
{
	UINT32 card_index;

	UINT32 encoder_index;

	UINT32 res[2];
}YKS_OscItemEncoder;

typedef struct _YKS_OscItemEvent
{
	UINT32 index;

	YKE_EVENT_ITEM_TYPE type;

	UINT32 res[2];
}YKS_OscItemEvent;

typedef struct _YKS_OscItemMultiAxis
{
	UINT32 index;

	YKE_MULTI_AXIS_ITEM_TYPE type;

	UINT32 res[2];
}YKS_OscItemMultiAxis;

typedef struct _YKS_OscItemWait
{
	UINT32 index;

	YKE_WAIT_ITEM_TYPE type;

	UINT32 res[2];
}YKS_OscItemWait;

typedef struct _YKS_OscItem
{
	YKE_BOOL enable;

	YKE_OSC_ITEM_TYPE type;

	YKS_OscItemAxis axis;

	YKS_OscItemGroup group;

	YKS_OscItemSlaveObject coe_obj;

	YKS_OscItemSlaveUG ug;

	YKS_OscItemDI digital_input;

	YKS_OscItemDO digital_output;

	YKS_OscItemReg gen_data_reg;

	YKS_OscItemSystem sys_info;

	YKS_OscItemEncoder encoder;

	YKS_OscItemEvent sys_event;

	YKS_OscItemMultiAxis multi_axis;

	YKS_OscItemWait wait;

	UINT32 res1[24];

	double res2[24];
}YKS_OscItem;

typedef struct _YKS_LoggerItemConfig
{
	YKE_BOOL axis_enable;

	UINT32 axis_index;

	YKE_BOOL group_enable;

	UINT32 group_index;

	YKE_BOOL card_enable;

	UINT32 card_index;

	YKE_BOOL bus_enable;

	UINT32 slave_index;

	YKE_BOOL event_enable;

	UINT32 event_index;

	YKE_BOOL multi_axis_enable;

	UINT32 multi_axis_index;

	YKE_BOOL wait_enable;

	UINT32 wait_index;

	UINT32 res1[8];

	UINT32 res2[8];
}YKS_LoggerItemConfig;

typedef struct _YKS_LoggerConfig
{
	char file_path[512];

	char file_name[64];

	double interval;

	YKE_BOOL do_output;

	YKE_BOOL user_data;

	YKE_BOOL ret_ng;

	YKE_BOOL ret_ok;

	YKE_BOOL zero_value;

	UINT32 res[10];

	YKE_LOGGER_FILTER_TYPE filter_type;

	YKS_LoggerItemConfig item_config[32];
}YKS_LoggerConfig;

typedef struct _YKS_ExcTrackItem
{
	UINT32 type;

	UINT32 index;

	UINT32 file;

	UINT32 line;

	INT32 value;

	UINT32 tick;
}YKS_ExcTrackItem;

typedef struct _YKS_ExcTrackConfig
{
	UINT32 item_number;

	UINT32 res;

	YKS_LoggerItemConfig item_config[16];
}YKS_ExcTrackConfig;

typedef struct _YKS_CompareConfigSoft
{
	YKE_COMPARE_MODE mode;

	YKE_BOOL enable_2d;

	YKS_OscItem source;

	UINT32 number;

	UINT32 res;

	YKE_BOOL out0_enable;

	UINT32 out0_byte;

	UINT32 out0_offset;

	YKE_BOOL out1_enable;

	UINT32 out1_byte;

	UINT32 out1_offset;

	YKE_BOOL out2_enable;

	UINT32 out2_byte;

	UINT32 out2_offset;

	YKE_BOOL out3_enable;

	UINT32 out3_byte;

	UINT32 out3_offset;

	double spacing1;

	double spacing2;

	double threshold;

	UINT32 res1[8];

	double res2[8];
}YKS_CompareConfigSoft;

typedef struct _YKS_CompareItemData
{
	INT32 value1;

	INT32 value2;

	UINT32 threshold;

	UINT32 res;

	YKE_BOOL out_bit0;

	YKE_BOOL out_bit1;

	YKE_BOOL out_bit2;

	YKE_BOOL out_bit3;

	UINT32 res1[8];

	double res2[8];
}YKS_CompareItemData;

typedef struct _YKS_CompareItemDataSoft
{
	double cmp_value1;

	double cmp_value2;

	YKE_BOOL out0_value;

	YKE_BOOL out1_value;

	YKE_BOOL out2_value;

	YKE_BOOL out3_value;

	double out0_time;

	double out1_time;

	double out2_time;

	double out3_time;

	UINT32 res1[8];

	double res2[8];
}YKS_CompareItemDataSoft;

typedef struct _YKS_CompareStatus
{
	UINT32 que_head;

	UINT32 que_tail;

	UINT32 hd_idel;

	UINT32 hd_active;

	UINT32 hd_finish;

	UINT32 soft_idel;

	UINT32 res1[8];

	double res2[8];
}YKS_CompareStatus;

typedef struct _YKS_CompareStatusSoft
{
	UINT32 que_head;

	UINT32 que_tail;

	YKE_BOOL finish;

	UINT32 success;

	UINT32 error_count;

	YKE_BOOL active;

	UINT32 res1[8];

	double res2[8];
}YKS_CompareStatusSoft;

typedef struct _YKS_CaptureConfig
{
	YKE_CAPTURE_SOURCE source_type;

	YKE_BOOL edge;

	UINT32 res1[8];

	double res2[8];
}YKS_CaptureConfig;

typedef struct _YKS_PwmConfig
{
	double freq;

	double duty;

	double res2[8];
}YKS_PwmConfig;

typedef struct _YKS_GroupDoConfig
{
	YKE_GROUP_COMPARE_MODE cmp_mode;

	YKE_GROUP_DO_MODE out_mode;

	UINT32 byte_index;

	UINT32 bit_offset;

	YKE_BOOL value;

	UINT32 span;

	UINT32 mark;

	YKE_AXIS_COMPARE_TYPE cmp_src;

	double time_dist_rate;

	YKE_BOOL single_unit;

	UINT32 res2;

	double single_time_dist;

	UINT32 number;

	UINT32 res;

	double time_dist_on;

	double time_dist_off;

	YKE_BOOL alter_unit;

	UINT32 res0;

	UINT32 res1[8];

	double res3[8];
}YKS_GroupDoConfig;

typedef struct _YKS_GroupPwmConfig
{
	YKE_GROUP_COMPARE_MODE cmp_mode;

	YKE_AXIS_COMPARE_TYPE cmp_src;

	double time_dist_rate;

	UINT32 span;

	UINT32 mark;

	YKE_GROUP_PWM_MODE pwm_mode;

	UINT32 card_index;

	UINT32 index;

	YKE_BOOL value;

	double filter_tim;

	double freq_value;

	double duty_value;

	double freq_scale;

	double duty_scale;

	double res2[8];
}YKS_GroupPwmConfig;

typedef struct _YKS_GroupWritePdoConfig
{
	YKE_GROUP_COMPARE_MODE cmp_mode;

	YKE_AXIS_COMPARE_TYPE cmp_src;

	double time_dist_rate;

	UINT32 span;

	UINT32 mark;

	YKE_NODE master;

	UINT32 slave_index;

	UINT32 main_index;

	UINT32 sub_index;

	YKE_DATA_TYPE data_type;

	UINT32 value;

	double res2[8];
}YKS_GroupWritePdoConfig;

typedef struct _YKS_GroupWriteRegisterConfig
{
	YKE_GROUP_COMPARE_MODE cmp_mode;

	YKE_AXIS_COMPARE_TYPE cmp_src;

	UINT32 index;

	UINT32 res;

	double time_dist_rate;

	UINT32 span;

	UINT32 mark;

	YKE_DATA_TYPE data_type;

	UINT32 value;

	double res2[8];
}YKS_GroupWriteRegisterConfig;

typedef struct _YKS_GroupWriteEventConfig
{
	YKE_GROUP_COMPARE_MODE cmp_mode;

	YKE_AXIS_COMPARE_TYPE cmp_src;

	double time_dist_rate;

	UINT32 span;

	UINT32 mark;

	UINT32 index;

	UINT32 res;

	double res2[8];
}YKS_GroupWriteEventConfig;

typedef struct _YKS_GroupMoveAbsoluteConfig
{
	YKE_GROUP_COMPARE_MODE cmp_mode;

	YKE_AXIS_COMPARE_TYPE cmp_src;

	double time_dist_rate;

	UINT32 span;

	UINT32 mark;

	UINT32 axis_index;

	UINT32 res;

	YKS_MoveAbsoluteConfig movabs;

	double res1[8];
}YKS_GroupMoveAbsoluteConfig;

typedef struct _YKS_GroupMoveRelativeConfig
{
	YKE_GROUP_COMPARE_MODE cmp_mode;

	YKE_AXIS_COMPARE_TYPE cmp_src;

	double time_dist_rate;

	UINT32 span;

	UINT32 mark;

	UINT32 axis_index;

	UINT32 res;

	YKS_MoveRelativeConfig movinc;

	double res1[8];
}YKS_GroupMoveRelativeConfig;

typedef struct _YKS_GroupDelayConfig
{
	double delay_ms;

	UINT32 mark;

	UINT32 res;

	double res2[8];
}YKS_GroupDelayConfig;

typedef struct _YKS_GroupDigitalInputConfig
{
	UINT32 byte_index;

	UINT32 bit_offset;

	YKE_TRIG_MODE trig_mode;

	UINT32 mark;

	double res2[8];
}YKS_GroupDigitalInputConfig;

typedef struct _YKS_GroupWaitAxisConfig
{
	UINT32 axis_index;

	YKE_AXIS_ITEM_TYPE item_type;

	YKE_TRIG_MODE trig_mode;

	UINT32 mark;

	double trig_value;

	double res2[8];
}YKS_GroupWaitAxisConfig;

typedef struct _YKS_GroupWaitPdoConfig
{
	YKE_NODE master;

	UINT32 slave_index;

	UINT32 main_index;

	UINT32 sub_index;

	YKE_TRIG_MODE trig_mode;

	YKE_DATA_TYPE data_type;

	UINT32 value;

	UINT32 mark;

	double res2[8];
}YKS_GroupWaitPdoConfig;

typedef struct _YKS_GroupWaitRegisterConfig
{
	UINT32 index;

	YKE_TRIG_MODE trig_mode;

	YKE_DATA_TYPE data_type;

	UINT32 value;

	UINT32 mark;

	UINT32 res;

	double res2[8];
}YKS_GroupWaitRegisterConfig;

typedef struct _YKS_GroupWaitEventConfig
{
	UINT32 index;

	YKE_EVENT_WAIT_TYPE type;

	YKE_TRIG_MODE trig_mode;

	UINT32 mark;

	double res[8];
}YKS_GroupWaitEventConfig;

typedef struct _YKS_GroupCardinalConfig
{
	double tensive;

	UINT32 mark;

	UINT32 res;

	double res2[8];
}YKS_GroupCardinalConfig;

typedef struct _YKS_OscConfig
{
	UINT32 depth;

	UINT32 interval;

	YKE_BOOL unit;

	UINT32 trig_ch;

	double trig_val;

	YKE_OSC_TRIG_TYPE trig_mode;

	UINT32 trig_pos;

	YKE_BOOL trig_once;

	UINT32 res0;

	UINT32 res1[8];

	double res2[8];
}YKS_OscConfig;

typedef struct _YKS_OscStatus
{
	YKE_BOOL trig_flag;

	UINT32 trig_index;

	UINT32 remain;

	YKE_BOOL finish;

	UINT32 buff_size;

	UINT32 buff_valid;

	YKE_BOOL over_flow;

	YKE_BOOL axis_warn;

	double master_period;

	UINT32 res1[8];

	double res2[8];
}YKS_OscStatus;

typedef struct _YKS_DigitalIOHardInfo
{
	YKE_BOOL valid;

	YKE_NODE master;

	YKE_DIO_PHY type;

	UINT32 index1;

	UINT32 index2;

	UINT32 res0;

	UINT32 res1[8];

	double res2[8];
}YKS_DigitalIOHardInfo;

typedef struct _YKS_AxisSoftLimitConfig
{
	double positive;

	double negative;

	YKE_BOOL enable;

	UINT32 res;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisSoftLimitConfig;

typedef struct _YKS_AxisHardLimitConfig
{
	YKE_BOOL enable_positive;

	YKE_BOOL enable_negative;

	UINT32 res1[8];
}YKS_AxisHardLimitConfig;

typedef struct _YKS_LinearInterpolationRelativeConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	double distance[32];

	YKS_AxisProfileMotion motion;

	double change_tim;

	double res[4];
}YKS_LinearInterpolationRelativeConfig;

typedef struct _YKS_LinearInterpolationAbsoluteConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	double position[32];

	YKS_AxisProfileMotion motion;

	double change_tim;

	double res[4];
}YKS_LinearInterpolationAbsoluteConfig;

typedef struct _YKS_LinearSyncRelativeConfig
{
	YKE_SYNC_AXIS_MODE sync_mode;

	UINT32 axis_num;

	UINT32 axis_list[32];

	double distance[32];

	double change_tim;

	double run_time;

	UINT32 res1[8];

	double res2[8];
}YKS_LinearSyncRelativeConfig;

typedef struct _YKS_LinearSyncAbsoluteConfig
{
	YKE_SYNC_AXIS_MODE sync_mode;

	UINT32 axis_num;

	UINT32 axis_list[32];

	double position[32];

	double change_tim;

	double run_time;

	UINT32 res1[8];

	double res2[8];
}YKS_LinearSyncAbsoluteConfig;

typedef struct _YKS_SyncStartConfig
{
	YKE_SYNC_AXIS_MODE sync_mode;

	UINT32 axis_num;

	UINT32 axis_list[32];

	double position[32];

	double change_tim;

	UINT32 res1[8];

	double res2[8];
}YKS_SyncStartConfig;

typedef struct _YKS_CircularInterpolationRelativeConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	YKS_POINT3 distance;

	YKS_POINT3 aux_point;

	YKE_CIRCULAR_PATH_CHOICE path_choice;

	YKE_CIRCULAR_AUX_MODE aux_mode;

	YKS_AxisProfileMotion motion;

	double res[8];
}YKS_CircularInterpolationRelativeConfig;

typedef struct _YKS_CircularInterpolationAbsoluteConfig
{
	UINT32 axis_num;

	UINT32 res0;

	UINT32 axis_list[32];

	YKS_POINT3 end_point;

	YKS_POINT3 aux_point;

	YKE_CIRCULAR_PATH_CHOICE path_choice;

	YKE_CIRCULAR_AUX_MODE aux_mode;

	YKS_AxisProfileMotion motion;

	double res[4];
}YKS_CircularInterpolationAbsoluteConfig;

typedef struct _YKS_ProbeConfigSoft
{
	YKS_DigitalIO input;

	YKE_TRIG_MODE trig_mode;

	UINT32 res0;

	YKS_OscItem item;

	UINT32 res1[8];

	double res2[8];
}YKS_ProbeConfigSoft;

typedef struct _YKS_ProbeStatusSoft
{
	YKE_BOOL active;

	YKE_BOOL valid;

	double value;

	UINT32 res1[4];

	double res2[4];
}YKS_ProbeStatusSoft;

typedef struct _YKS_AxisTrigger
{
	UINT32 axis_index;

	YKE_TRIGGER_TYPE type;

	double value;

	UINT32 res1[8];

	double res2[8];
}YKS_AxisTrigger;

typedef struct _YKS_AxisTriggerStatus
{
	YKE_BOOL active;

	UINT32 axis_index;

	YKE_TRIGGER_TYPE type;

	UINT32 res;

	double value;

	UINT32 res1[8];

	UINT32 res2[8];
}YKS_AxisTriggerStatus;

typedef struct _YKS_TriggerArgOneSignal
{
	YKE_SIGNAL_SOURCE_TYPE type;

	UINT32 index;

	YKS_DigitalIO inout;

	UINT32 res[8];
}YKS_TriggerArgOneSignal;

typedef struct _YKS_TriggerArgTwoSignal
{
	YKE_SIGNAL_SOURCE_TYPE type1;

	YKE_SIGNAL_SOURCE_TYPE type2;

	YKS_DigitalIO inout1;

	YKS_DigitalIO inout2;

	UINT32 index1;

	UINT32 index2;

	YKE_LOGIC_CONDITIONS op_logic;

	UINT32 res[8];
}YKS_TriggerArgTwoSignal;

typedef struct _YKS_TriggerArgAxisPosition
{
	UINT32 axis_index;

	YKE_TRIG_MODE trig_mode;

	YKE_BOOL disable_positive_direction;

	YKE_BOOL disable_negative_direction;

	YKE_BOOL use_feedback;

	YKE_BOOL inv;

	double position;

	UINT32 res[8];
}YKS_TriggerArgAxisPosition;

typedef struct _YKS_TriggerArgAxisTime
{
	UINT32 axis_index;

	YKE_TRIG_MODE trig_mode;

	YKE_BOOL use_remain;

	YKE_BOOL inv;

	double time;

	UINT32 res[8];
}YKS_TriggerArgAxisTime;

typedef struct _YKS_TriggerArgAxisVelocity
{
	UINT32 axis_index;

	YKE_TRIG_MODE trig_mode;

	YKE_BOOL use_feedback;

	YKE_BOOL inv;

	double velocity;

	UINT32 res[8];
}YKS_TriggerArgAxisVelocity;

typedef struct _YKS_TriggerArgAxisTorque
{
	UINT32 axis_index;

	YKE_TRIG_MODE trig_mode;

	YKE_BOOL use_feedback;

	YKE_BOOL inv;

	double torque;

	UINT32 res[8];
}YKS_TriggerArgAxisTorque;

typedef struct _YKS_TriggerArgSlavePDO
{
	YKE_NODE master;

	UINT32 slave_index;

	UINT32 main_index;

	UINT32 sub_index;

	YKE_TRIG_MODE trig_mode;

	YKE_DATA_TYPE data_type;

	YKE_BOOL inv;

	INT32 value;

	UINT32 res[8];
}YKS_TriggerArgSlavePDO;

typedef struct _YKS_TriggerArgEncoder
{
	UINT32 index;

	YKE_TRIG_MODE trig_mode;

	YKE_BOOL inv;

	INT32 value;

	UINT32 res[8];
}YKS_TriggerArgEncoder;

typedef struct _YKS_TriggerOutputOneBit
{
	YKE_SIGNAL_SOURCE_TYPE type;

	UINT32 index;

	YKS_DigitalIO inout;

	YKE_BOOL single_shot;

	YKE_BOOL set_off_state;

	YKE_BOOL enable_reverse;

	UINT32 res0;

	double delay_ms;

	UINT32 res[8];
}YKS_TriggerOutputOneBit;

typedef struct _YKS_TriggerOutputStopAxis
{
	UINT32 axis_index;

	YKE_BOOL single_shot;

	YKE_STOP_DEC stop_dec;

	UINT32 res;

	UINT32 res1[8];
}YKS_TriggerOutputStopAxis;

typedef struct _YKS_TriggerOutputStartGroup
{
	UINT32 group_index;

	YKE_BOOL single_shot;

	UINT32 res[8];
}YKS_TriggerOutputStartGroup;

typedef struct _YKS_TriggerOutputStartMultiAxis
{
	UINT32 index;

	YKE_BOOL single_shot;

	UINT32 res[8];
}YKS_TriggerOutputStartMultiAxis;

typedef struct _YKS_TriggerOutputStartAxis
{
	UINT32 axis_index;

	YKE_BOOL single_shot;

	double position;

	YKS_AxisProfileMotion motion;

	UINT32 res[8];
}YKS_TriggerOutputStartAxis;

typedef struct _YKS_TriggerOutputSoftEmgStop
{
	UINT32 channel;

	YKE_BOOL single_shot;

	UINT32 res[8];
}YKS_TriggerOutputSoftEmgStop;

typedef struct _YKS_TriggerOutputSlavePDO
{
	YKE_NODE master;

	UINT32 slave_index;

	UINT32 main_index;

	UINT32 sub_index;

	YKE_BOOL single_shot;

	YKE_BOOL set_off_state;

	YKE_DATA_TYPE data_type;

	UINT32 value;

	UINT32 res[8];
}YKS_TriggerOutputSlavePDO;

typedef struct _YKS_TriggerOutputTargetTorque
{
	UINT32 axis_index;

	UINT32 res0;

	double value;

	YKE_BOOL single_shot;

	YKE_BOOL set_off_state;

	UINT32 res[8];
}YKS_TriggerOutputTargetTorque;

typedef struct _YKS_TriggerOutputDelayMs
{
	YKE_NODE master;

	UINT32 res0;

	double value;

	UINT32 res[8];
}YKS_TriggerOutputDelayMs;

typedef struct _YKS_TriggerOutputDataReg
{
	YKE_NODE master;

	YKE_BOOL single_shot;

	YKE_BOOL set_off_state;

	UINT32 index;

	UINT32 value;

	UINT32 res0;

	UINT32 res[8];
}YKS_TriggerOutputDataReg;

typedef struct _YKS_EventStatus
{
	YKE_NODE master;

	YKE_EVENT_STATUS_TYTE status;

	YKE_SYSTEM_ERROR error;

	UINT32 triged;

	UINT32 res[8];
}YKS_EventStatus;

typedef struct _YKS_PTData
{
	double position;

	double tim;

	double acc_add_percent;
}YKS_PTData;

typedef struct _YKS_PVTData
{
	double position;

	double tim;

	double velocity;
}YKS_PVTData;

typedef struct _YKS_PVTSData
{
	double position;

	double tim;

	double res;
}YKS_PVTSData;

typedef struct _YKS_PVTStatus
{
	UINT32 idel;

	UINT32 res1[7];

	double res2[8];
}YKS_PVTStatus;

typedef struct _YKS_WDTStatus
{
	YKE_BOOL enable;

	YKE_BOOL trigged;

	double timeout;

	double remain_tim;

	double res2[8];
}YKS_WDTStatus;

typedef struct _YKS_CncGCode
{
	UINT32 mark;

	char gcode[160];
}YKS_CncGCode;

typedef struct _YKS_CncASplineConfig
{
	UINT32 mark;

	UINT32 res;

	YKE_CNC_ASPLINE_TRANS_TYPE start_trans_type;

	YKE_CNC_ASPLINE_TRANS_TYPE end_trans_type;

	double start_Vector[3];

	double end_Vector[3];

	double res1[4];
}YKS_CncASplineConfig;

typedef struct _YKS_CncContourDevConfig
{
	UINT32 mark;

	YKE_CNC_ACTION_TYPE action_time;

	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	YKE_BOOL vel_const;

	double path_dev_max;

	double track_dev_max;

	double relevant_path_min;

	double relevant_track_min;

	double remain_part;

	double angle_max;
}YKS_CncContourDevConfig;

typedef struct _YKS_CncContourDistConfig
{
	UINT32 mark;

	YKE_CNC_ACTION_TYPE action_time;

	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	YKE_BOOL vel_const;

	double track_dev_max;

	double pre_dist;

	double post_dist;

	double relevant_path_min;

	double relevant_track_min;

	double remain_part;

	double angle_max;
}YKS_CncContourDistConfig;

typedef struct _YKS_CncContourDistSoftConfig
{
	UINT32 mark;

	UINT32 res;

	double path_dist;

	double track_dist;

	double acc_max;

	double acc_min;

	double ramp_time;

	double dist_weight;
}YKS_CncContourDistSoftConfig;

typedef struct _YKS_CncContourDistMasterConfig
{
	UINT32 mark;

	UINT32 res;

	double path_dist;

	double acc_max;

	double acc_min;

	double ramp_time;

	double dist_weight;
}YKS_CncContourDistMasterConfig;

typedef struct _YKS_CncContourPosConfig
{
	UINT32 mark;

	YKE_CNC_ACTION_TYPE action_time;

	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	YKE_BOOL vel_const;

	double pre_dist;

	double post_dist;

	double pos_position[3];
}YKS_CncContourPosConfig;

typedef struct _YKS_CncContourPtpConfig
{
	UINT32 mark;

	YKE_BOOL merge;

	YKE_CNC_ACTION_TYPE action_time;

	UINT32 res;

	double path_dev_max;

	double path_dist;
}YKS_CncContourPtpConfig;

typedef struct _YKS_CncHscBConfig
{
	UINT32 mark;

	YKE_BOOL merge;

	YKE_BOOL auto_off_path;

	YKE_BOOL auto_off_track;

	YKE_BOOL auto_off_rapid;

	YKE_BOOL auto_off_exactStop;

	double path_dev_max;

	double track_dev_max;

	double path_len_max;

	double angle_max;

	double res1[4];
}YKS_CncHscBConfig;

typedef struct _YKS_CncHscSConfig
{
	UINT32 mark;

	YKE_HSC_CIR_MODE cir_mode;

	YKE_CNC_CHECK_JERK_TYPE check_jerk;

	YKE_BOOL auto_off_rapid;

	YKE_BOOL merge;

	UINT32 res0;

	double cir_min_angle;

	double track_dev_rapid;

	double path_dev_max;

	double path_dev_rapid;

	double angle_max;

	double cir_min_radius;

	double cir_long_length;

	double track_dev_max;

	double res[8];
}YKS_CncHscSConfig;

typedef struct _YKS_CncHscPcs1Config
{
	UINT32 mark;

	UINT32 res;

	double contour_error_Max;
}YKS_CncHscPcs1Config;

typedef struct _YKS_CncHscPcs2Config
{
	UINT32 mark;

	UINT32 res;

	double contour_error_Max;
}YKS_CncHscPcs2Config;

typedef struct _YKS_CncParaStatus
{
	YKE_BOOL done;

	UINT32 status;

	char value[128];

	UINT32 res;

	UINT32 res1[8];
}YKS_CncParaStatus;

YK_API YKM_SysConnect(char* ip_addr, UINT32 ip_port, INT32* handle);

YK_API YKM_SysClose(INT32 handle);

YK_API YKM_GetSysVersion(INT32 handle, UINT32* version);

YK_API YKM_GetRuntimeVersion(INT32 handle, UINT32* version);

YK_API YKM_GetThreadID(INT32 handle, UINT32* id);

YK_API YKM_SysLoadLib(INT32 handle);

YK_API YKM_SysUnloadLib(INT32 handle);

YK_API YKM_SetAppWDT(INT32 handle, YKE_BOOL enable, double tim);

YK_API YKM_ClearAppWDT(INT32 handle);

YK_API YKM_ReadAppWDT(INT32 handle, YKS_WDTStatus* status);

YK_API YKM_StartLogger(INT32 handle, UINT32 process_id);

YK_API YKM_StopLogger(INT32 handle);

YK_API YKM_GetLoggerProcessID(INT32 handle, UINT32 *process_id);

YK_API YKM_SetLoggerConfig(INT32 handle, YKS_LoggerConfig config);

YK_API YKM_InitExcData(INT32 handle, YKS_ExcTrackConfig config);

YK_API YKM_GetExcData(INT32 handle, YKS_ExcTrackItem* item_data, UINT32 *ret_size);

YK_API YKM_GetProcessName(INT32 handle, UINT32 process_id, char* name, UINT32 size);

YK_API YKM_GetProcessNumber(INT32 handle, UINT32* process_num, UINT32* process_id);

YK_API YKM_GetProcessID(INT32 handle, UINT32* process_id);

YK_API YKM_ReadFunLog(INT32 handle, char* buff, UINT32 size, UINT32* count);

YK_API YKM_GetSysProfile(INT32 handle, YKS_SysProfile* config);

YK_API YKM_ReadSysWarn(INT32 handle, char* buff, UINT32 size, UINT32* num);

YK_API YKM_ReadSysLog(INT32 handle, char* buff, UINT32 size, UINT32* ret_size);

YK_API YKM_ClearSysLog(INT32 handle);

YK_API YKM_SendMgmtCmd(INT32 handle, YKE_NODE master, YKE_BOOL run_stop);

YK_API YKM_ReadMgmtStatus(INT32 handle, YKE_NODE master, UINT32* status);

YK_API YKM_SysColdReset(INT32 handle, double delay);

YK_API YKM_SysWarmReset(INT32 handle, YKE_NODE master);

YK_API YKM_SysStartService(INT32 handle);

YK_API YKM_SysStopService(INT32 handle);

YK_API YKM_SysCheckService(INT32 handle, YKE_BOOL *status);

YK_API YKM_SysRegisterService(INT32 handle, char* path);

YK_API YKM_SysUnRegisterService(INT32 handle);

YK_API YKM_SysGetService(INT32 handle, YKE_BOOL* registered, char* path, UINT32 size);

YK_API YKM_SetHardEmgProfile(INT32 handle, UINT32 channel, YKS_HardEmgProfile config);

YK_API YKM_GetHardEmgProfile(INT32 handle, UINT32 channel, YKS_HardEmgProfile* config);

YK_API YKM_SetEmgStopSoft(INT32 handle, UINT32 channel);

YK_API YKM_ClearEmgStopSoft(INT32 handle, UINT32 channel);

YK_API YKM_ReadEmgStatus(INT32 handle, UINT32 channel, YKS_EmgStatus* status);

YK_API YKM_SetBlueScreenConfig(INT32 handle, YKS_BlueScreenConfig config);

YK_API YKM_GetProjectID(INT32 handle, char* prj_id, UINT32 size);

YK_API YKM_LoadProjectData(INT32 handle, char* filename, UINT32 mask);

YK_API YKM_GetPLCCommand(YKE_PLC_CMD_TYPE* command);

YK_API YKM_SetPLCStatus(INT32 handle, UINT32 status);

YK_API YKM_SendPLCCommand(INT32 handle, YKE_PLC_CMD_TYPE command);

YK_API YKM_ClearSysWarn(INT32 handle, YKE_NODE master);

YK_API YKM_SetBusEventTime(INT32 handle, YKE_NODE master, double tim);

YK_API YKM_GetBusEventTime(INT32 handle, YKE_NODE master, double *tim);

YK_API YKM_WaitBusEvent(INT32 handle, YKE_NODE master);

YK_API YKM_ReadBusPacket(INT32 handle, YKS_BusPacketHeader *header, UINT8* buff, UINT32 size);

YK_API YKM_WriteDataRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

YK_API YKM_ReadDataRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

YK_API YKM_WriteDataRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

YK_API YKM_ReadDataRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

YK_API YKM_GetDataRegAddress(INT32 handle, UINT32* hi_addr, UINT32 *lo_addr);

YK_API YKM_WriteSpecRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

YK_API YKM_ReadSpecRegU32(INT32 handle, UINT32 offset, UINT32* data, UINT32 size);

YK_API YKM_WriteSpecRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

YK_API YKM_ReadSpecRegDouble(INT32 handle, UINT32 offset, double* data, UINT32 size);

YK_API YKM_GetSpecRegAddress(INT32 handle, UINT32* hi_addr, UINT32* lo_addr);

YK_API YKM_ProEnAddPrj(INT32 handle, char* name);

YK_API YKM_ProEnDelPrj(INT32 handle, char* name);

YK_API YKM_ProEnCheckPrj(INT32 handle, char* name);

YK_API YKM_ProEnWriteData(INT32 handle, UINT32 type, UINT8* data, UINT32 size);

YK_API YKM_ReadDoggleData(INT32 handle, YKE_DOGGLE_TYPE type, UINT32 offset, char* data, UINT32 size, INT32* result);

YK_API YKM_WriteDoggleData(INT32 handle, YKE_DOGGLE_TYPE type, UINT32 offset, char* data, UINT32 size, INT32* result);


YK_API YKM_DisconnectBus(INT32 handle, YKE_NODE master);

YK_API YKM_ScanBus(INT32 handle, YKE_NODE master, YKE_SCAN_INFO info);

YK_API YKM_ReadBusStatus(INT32 handle, YKE_NODE master, YKS_BusStatus* info);

YK_API YKM_ClearBusValue(INT32 handle, YKE_NODE master);

YK_API YKM_ClearBusWarn(INT32 handle, YKE_NODE master);

YK_API YKM_SetBusConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, YKE_SLAVE_ITEM item, INT32 value);

YK_API YKM_GetBusConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, YKE_SLAVE_ITEM item, INT32* value);

YK_API YKM_GetSlaveAlias(INT32 handle, YKE_NODE master, UINT32 slaveIndex, char* name, UINT32 size);

YK_API YKM_ReadSlaveStatus(INT32 handle, YKE_NODE master, UINT32 slaveIndex, YKS_SlaveStatus* status);

YK_API YKM_GetSlaveTxPdoNumber(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32* number);

YK_API YKM_GetSlaveTxPdoConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 pdoIndex, YKS_SlavePdoConfig* config);

YK_API YKM_GetSlaveRxPdoNumber(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32* number);

YK_API YKM_GetSlaveRxPdoConfig(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 pdoIndex, YKS_SlavePdoConfig* config);

YK_API YKM_SetPDOProtect(INT32 handle, YKE_NODE master, UINT32 uIndex, YKE_BOOL check);

YK_API YKM_GetPDOProtect(INT32 handle, YKE_NODE master, UINT32 uIndex, YKE_BOOL* check);

YK_API YKM_WritePDOIndex(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 gIndex, UINT16 *ptr, UINT32 size);

YK_API YKM_ReadPDOIndex(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 gIndex, UINT16 *ptr, UINT32 size);

YK_API YKM_ReadPDOObject(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 mainIndex, UINT32 subIndex, UINT16 *ptr, UINT32 size);

YK_API YKM_WritePDOObject(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 mainIndex, UINT32 subIndex, UINT16 *ptr, UINT32 size);

YK_API YKM_WriteSDOCmd(INT32 handle, YKE_NODE master, UINT32 slaveIndex, UINT32 mainIndex, UINT32 subIndex, UINT32 byteNum, UINT32 val, UINT32* sdoIndex);

YK_API YKM_ReadSDOCmd(INT32 handle, YKE_NODE master, UINT32 uIndex, UINT32 mainIndex, UINT32 subIndex, UINT32 byteNum, UINT32* sdoIndex);

YK_API YKM_ReadSDOStatus(INT32 handle, YKE_NODE master, UINT32 sdoIndex, YKS_SdoStatus *status);

YK_API YKM_GetSDOIdel(INT32 handle, YKE_NODE master, UINT32* num);

YK_API YKM_ReadDigitalOutputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value);

YK_API YKM_ReadDigitalOutputBits(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value, UINT32 size);

YK_API YKM_WriteDigitalOutputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL value);

YK_API YKM_WriteDigitalOutputBits(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL *value, UINT32 size);

YK_API YKM_ReadDigitalOutputByte(INT32 handle, UINT32 byteIndex, UINT8* value);

YK_API YKM_WriteDigitalOutputByte(INT32 handle, UINT32 byteIndex, UINT8 value);

YK_API YKM_WriteDigitalOutputMask(INT32 handle, UINT32 byteIndex, UINT8 mask, UINT8 value);

YK_API YKM_SetDigitalOutputHold(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL hold);

YK_API YKM_GetDigitalOutputHold(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* hold);

YK_API YKM_WriteDigitalInputFilter(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, double filter);

YK_API YKM_ReadDigitalInputFilter(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, double* filter);

YK_API YKM_ReadDigitalInputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value);

YK_API YKM_ReadDigitalInputBits(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL* value, UINT32 size);

YK_API YKM_WriteDigitalInputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, YKE_BOOL value);

YK_API YKM_ReadDigitalInputByte(INT32 handle, UINT32 byteIndex, UINT8* value);

YK_API YKM_WriteDigitalInputByte(INT32 handle, UINT32 byteIndex, UINT8 value);

YK_API YKM_ReadInputEdgeCount1(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32* value);

YK_API YKM_WriteInputEdgeCount1(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32 value);

YK_API YKM_ReadInputEdgeCount2(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32* value);

YK_API YKM_WriteInputEdgeCount2(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, UINT32 value);

YK_API YKM_ReadInputLocation(INT32 handle, UINT32 byteIndex, YKS_DigitalIOHardInfo* phy);

YK_API YKM_ReadOutputLocation(INT32 handle, UINT32 byteIndex, YKS_DigitalIOHardInfo* phy);

YK_API YKM_ReverseDigitalOutputBit(INT32 handle, UINT32 byteIndex, UINT32 bitOffset, double time);

YK_API YKM_WriteDigitalOutputCycle(INT32 handle, YKS_DigitalOutputCycle* output, UINT32 size);

YK_API YKM_SetCompareConfigSoft(INT32 handle, UINT32 channel, YKS_CompareConfigSoft config);

YK_API YKM_GetCompareConfigSoft(INT32 handle, UINT32 channel, YKS_CompareConfigSoft* config);

YK_API YKM_SetCompareValueSoft(INT32 handle, UINT32 channel, YKS_CompareItemDataSoft itemdata);

YK_API YKM_ReadCompareStatusSoft(INT32 handle, UINT32 channel, YKS_CompareStatusSoft* status);

YK_API YKM_StartCompareSoft(INT32 handle, UINT32 channel);

YK_API YKM_StopCompareSoft(INT32 handle, UINT32 channel);

YK_API YKM_SetProbeConfigSoft(INT32 handle, UINT32 channel, YKS_ProbeConfigSoft config);

YK_API YKM_GetProbeConfigSoft(INT32 handle, UINT32 channel, YKS_ProbeConfigSoft* config);

YK_API YKM_StartProbeSoft(INT32 handle, UINT32 channel);

YK_API YKM_StopProbeSoft(INT32 handle, UINT32 channel);

YK_API YKM_ReadProbeStatusSoft(INT32 handle, UINT32 channel, YKS_ProbeStatusSoft* status);

YK_API YKM_SetCommandEquiv(INT32 handle, UINT32 axisIndex, double dist, double pulse);

YK_API YKM_GetCommandEquiv(INT32 handle, UINT32 axisIndex, double* dist, double* pulse);

YK_API YKM_GetFeedbackEquivScale(INT32 handle, UINT32 axisIndex, double* scale);

YK_API YKM_SetFeedbackEquivScale(INT32 handle, UINT32 axisIndex, double scale);

YK_API YKM_SetRotateDir(INT32 handle, UINT32 axisIndex, YKE_BOOL rotate_dir);

YK_API YKM_GetRotateDir(INT32 handle, UINT32 axisIndex, YKE_BOOL* rotate_dir);

YK_API YKM_SetAxisProfileModulo(INT32 handle, UINT32 axisIndex, YKS_AxisProfileModulo config);

YK_API YKM_GetAxisProfileModulo(INT32 handle, UINT32 axisIndex, YKS_AxisProfileModulo* config);

YK_API YKM_ReadAxisModuloCounter(INT32 handle, UINT32 axisIndex, INT32* counter);

YK_API YKM_SetAxisSoftLimit(INT32 handle, UINT32 axisIndex, YKS_AxisSoftLimitConfig config);

YK_API YKM_GetAxisSoftLimit(INT32 handle, UINT32 axisIndex, YKS_AxisSoftLimitConfig* config);

YK_API YKM_SetAxisHardLimitEnable(INT32 handle, UINT32 axisIndex, YKS_AxisHardLimitConfig config);

YK_API YKM_GetAxisHardLimitEnable(INT32 handle, UINT32 axisIndex, YKS_AxisHardLimitConfig* config);

YK_API YKM_SetAxisMaxTorqueLimit(INT32 handle, UINT32 axisIndex, double value);

YK_API YKM_GetAxisMaxTorqueLimit(INT32 handle, UINT32 axisIndex, double* value);

YK_API YKM_SetAxisPositiveTorqueLimit(INT32 handle, UINT32 axisIndex, double value);

YK_API YKM_GetAxisPositiveTorqueLimit(INT32 handle, UINT32 axisIndex, double* value);

YK_API YKM_SetAxisNegativeTorqueLimit(INT32 handle, UINT32 axisIndex, double value);

YK_API YKM_GetAxisNegativeTorqueLimit(INT32 handle, UINT32 axisIndex, double* value);

YK_API YKM_SetAxisMaxCurrentLimit(INT32 handle, UINT32 axisIndex, double value);

YK_API YKM_GetAxisMaxCurrentLimit(INT32 handle, UINT32 axisIndex, double* value);

YK_API YKM_ReadAxisCommandPosition(INT32 handle, UINT32 axisIndex, double* position);

YK_API YKM_ReadAxisActualPosition(INT32 handle, UINT32 axisIndex, double* position);

YK_API YKM_ReadAxisTargetPosition(INT32 handle, UINT32 axisIndex, double* position);

YK_API YKM_ReadAxisRawPosition(INT32 handle, UINT32 axisIndex, INT32* position);

YK_API YKM_ReadAxisCommandVelocity(INT32 handle, UINT32 axisIndex, double* velocity);

YK_API YKM_ReadAxisActualVelocity(INT32 handle, UINT32 axisIndex, double* velocity);

YK_API YKM_ReadAxisCommandAcceleration(INT32 handle, UINT32 axisIndex, double* acceleration);

YK_API YKM_ReadAxisCommandJerk(INT32 handle, UINT32 axisIndex, double* jerk);

YK_API YKM_ReadAxisCommandTorque(INT32 handle, UINT32 axisIndex, double* torque);

YK_API YKM_ReadAxisActualTorque(INT32 handle, UINT32 axisIndex, double* torque);

YK_API YKM_SetAxisUserData(INT32 handle, UINT32 axisIndex, UINT32 mask, UINT32 value);

YK_API YKM_GetAxisUserData(INT32 handle, UINT32 axisIndex, UINT32* value);

YK_API YKM_ReadAxisConfigBase(INT32 handle, UINT32 axisIndex, YKS_AxisConfigBase* config);

YK_API YKM_ReadAxisStatusPlanner(INT32 handle, UINT32 axisIndex, YKS_AxisStatusPlanner* status);

YK_API YKM_ReadAxisStatusPosition(INT32 handle, UINT32 axisIndex, YKS_AxisStatusPosition* status);

YK_API YKM_ReadAxisStatusCompensation(INT32 handle, UINT32 axisIndex, YKS_AxisStatusCompensation* status);

YK_API YKM_ReadAxisStatusFollow(INT32 handle, UINT32 axisIndex, YKS_AxisStatusFollow* status);

YK_API YKM_ReadAxisStatusBase(INT32 handle, UINT32 axisIndex, YKS_AxisStatusBase* status);

YK_API YKM_ReadAxisTriggerStatus(INT32 handle, UINT32 axisIndex, YKS_AxisTriggerStatus* status);

YK_API YKM_SetAxisProfileBase(INT32 handle, UINT32 axisIndex, YKS_AxisProfileBase config);

YK_API YKM_GetAxisProfileBase(INT32 handle, UINT32 axisIndex, YKS_AxisProfileBase* config);

YK_API YKM_SetAxisProfileMotion(INT32 handle, UINT32 axisIndex, YKS_AxisProfileMotion config);

YK_API YKM_GetAxisProfileMotion(INT32 handle, UINT32 axisIndex, YKS_AxisProfileMotion* config);

YK_API YKM_SetAxisProfileInp(INT32 handle, UINT32 axisIndex, YKS_AxisProfileInp config);

YK_API YKM_GetAxisProfileInp(INT32 handle, UINT32 axisIndex, YKS_AxisProfileInp* config);

YK_API YKM_SetAxisProfilePositionLag(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePositionLag config);

YK_API YKM_GetAxisProfilePositionLag(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePositionLag* config);

YK_API YKM_GetAxisList(INT32 handle, UINT32* axisNum, UINT32 *axisList, UINT32 size);

YK_API YKM_SetAxisDrvOpMode(INT32 handle, UINT32 axisIndex, YKE_DRV_OP_MODE mode);

YK_API YKM_GetAxisDrvOpMode(INT32 handle, UINT32 axisIndex, YKE_DRV_OP_MODE* mode);

YK_API YKM_SetAxisWarnMask(INT32 handle, UINT32 axisIndex, UINT32 mask);

YK_API YKM_GetAxisWarnMask(INT32 handle, UINT32 axisIndex, UINT32* mask);

YK_API YKM_GetAxisAlias(INT32 handle, UINT32 axisIndex, char* name, UINT32 size);

YK_API YKM_ClearAxisHomed(INT32 handle, UINT32 axisIndex);

YK_API YKM_SetAxisHomed(INT32 handle, UINT32 axisIndex);

YK_API YKM_SetAxisHomeAbsEncoder(INT32 handle, UINT32 axisIndex, INT32 encoder_value);

YK_API YKM_GetAxisHomeAbsEncoder(INT32 handle, UINT32 axisIndex, INT32* encoder_value);

YK_API YKM_SetSwitchLimitPositive(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchLimitPositive(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

YK_API YKM_SetSwitchLimitNegative(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchLimitNegative(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

YK_API YKM_SetSwitchHome(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchHome(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

YK_API YKM_SetSwitchProbe(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchProbe(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisSwitchConfig *config);

YK_API YKM_SetHomeProbe(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig config);

YK_API YKM_GetHomeProbe(INT32 handle, UINT32 axisIndex, YKS_AxisSwitchConfig* config);

YK_API YKM_SetAxisPosition(INT32 handle, UINT32 axisIndex, double position);

YK_API YKM_SetAxisProfileClearDrv(INT32 handle, UINT32 axisIndex, YKS_AxisProfileClearDrv profile);

YK_API YKM_GetAxisProfileClearDrv(INT32 handle, UINT32 axisIndex, YKS_AxisProfileClearDrv* profile);

YK_API YKM_ClearDrvWarn(INT32 handle, UINT32 axisIndex);

YK_API YKM_ClearAxisWarn(INT32 handle, UINT32 axisIndex);

YK_API YKM_GetAxisProfilePowerOn(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePowerOn* profile);

YK_API YKM_SetAxisProfilePowerOn(INT32 handle, UINT32 axisIndex, YKS_AxisProfilePowerOn profile);

YK_API YKM_GetAxisProfileFeedforward(INT32 handle, UINT32 axisIndex, YKS_AxisProfileFeedforward* profile);

YK_API YKM_SetAxisProfileFeedforward(INT32 handle, UINT32 axisIndex, YKS_AxisProfileFeedforward profile);

YK_API YKM_PowerOn(INT32 handle, UINT32 axisIndex);

YK_API YKM_PowerOff(INT32 handle, UINT32 axisIndex);

YK_API YKM_StopAxis(INT32 handle, UINT32 axisIndex, YKE_STOP_DEC dec_sel);

YK_API YKM_StopAxisTrigger(INT32 handle, UINT32 axisIndex, YKE_STOP_DEC dec_sel, YKS_AxisTrigger trigger);

YK_API YKM_StartHome(INT32 handle, UINT32 axisIndex, YKS_AxisHomeConfig config);

YK_API YKM_GetHomeConfig(INT32 handle, UINT32 axisIndex, YKS_AxisHomeConfig* config);

YK_API YKM_MoveAbsolute(INT32 handle, UINT32 axisIndex, double position);

YK_API YKM_MoveAbsoluteEx(INT32 handle, UINT32 axisIndex, YKS_MoveAbsoluteConfig config);

YK_API YKM_MoveAbsoluteTrigger(INT32 handle, UINT32 axisIndex, YKS_MoveAbsoluteConfig config, YKS_AxisTrigger trigger);

YK_API YKM_MoveAbsoluteEvent(INT32 handle, UINT32 axisIndex, YKS_MoveAbsoluteConfig config);

YK_API YKM_MoveRelative(INT32 handle, UINT32 axisIndex, double distance);

YK_API YKM_MoveRelativeEx(INT32 handle, UINT32 axisIndex, YKS_MoveRelativeConfig config);

YK_API YKM_MoveRelativeTrigger(INT32 handle, UINT32 axisIndex, YKS_MoveRelativeConfig config, YKS_AxisTrigger trigger);

YK_API YKM_MoveRelativeEvent(INT32 handle, UINT32 axisIndex, YKS_MoveRelativeConfig config);

YK_API YKM_MovePositionSim(INT32 handle, UINT32 axisIndex, YKS_MovePositionSimConfig config, YKS_MovePositionSimResult* result);

YK_API YKM_MovePositionSimEx(INT32 handle, UINT32 axisIndex, YKS_MovePositionSimConfig config, YKS_MovePositionSimTrigger trigger, YKS_MovePositionSimResult* result);

YK_API YKM_MoveVelocity(INT32 handle, UINT32 axisIndex, double velocity, YKE_DIRECTION direction);

YK_API YKM_MoveVelocityEx(INT32 handle, UINT32 axisIndex, YKS_MoveVelocityConfig config);

YK_API YKM_MoveConveyor(INT32 handle, UINT32 axisIndex, YKS_MoveConveyorConfig config);

YK_API YKM_WriteAxisEventOneSignal(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_TriggerArgOneSignal config);

YK_API YKM_WriteAxisEventTwoSignal(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_TriggerArgTwoSignal config);

YK_API YKM_MoveVelocityTrigger(INT32 handle, UINT32 axisIndex, YKS_MoveVelocityConfig config, YKS_AxisTrigger trigger);

YK_API YKM_MoveVelocityEvent(INT32 handle, UINT32 axisIndex, YKS_MoveVelocityConfig config);

YK_API YKM_MoveTorque(INT32 handle, UINT32 axisIndex, YKS_MoveTorqueConfig config);

YK_API YKM_OverridePosition(INT32 handle, UINT32 axisIndex, double position);

YK_API YKM_OverrideVelocity(INT32 handle, UINT32 axisIndex, double velocity);

YK_API YKM_OverrideAcceleration(INT32 handle, UINT32 axisIndex, double acc);

YK_API YKM_OverrideDeceleration(INT32 handle, UINT32 axisIndex, double dec);

YK_API YKM_OverrideJerkAcc(INT32 handle, UINT32 axisIndex, double jerk_acc);

YK_API YKM_OverrideJerkDec(INT32 handle, UINT32 axisIndex, double jerk_dec);

YK_API YKM_OverrideAtPosition(INT32 handle, UINT32 axisIndex, YKS_AxisProfileMotion motion, double position);

YK_API YKM_WritePTData(INT32 handle, UINT32 axisIndex, YKS_PTData* data, UINT32 size);

YK_API YKM_WritePVTData(INT32 handle, UINT32 axisIndex, YKS_PVTData* data, UINT32 size);

YK_API YKM_WritePVTSData(INT32 handle, UINT32 axisIndex, double start_velocity, double end_velocity, YKS_PVTSData* data, UINT32 size);

YK_API YKM_MovePVTStart(INT32 handle, UINT32 axisIndex);

YK_API YKM_MoveMultiPVTStart(INT32 handle, UINT32 axisNum, UINT32 *axisList);

YK_API YKM_ReadPVTStatus(INT32 handle, UINT32 axisIndex, YKS_PVTStatus* status);

YK_API YKM_ClearPVTData(INT32 handle, UINT32 axisIndex);

YK_API YKM_FollowAxis1(INT32 handle, UINT32 axisIndex, YKS_FollowAxis1Config config);

YK_API YKM_FollowAxis2(INT32 handle, UINT32 axisIndex, YKS_FollowAxis2Config config);

YK_API YKM_FollowUG(INT32 handle, UINT32 axisIndex, YKS_FollowUgConfig config);

YK_API YKM_FollowEncoderPCI(INT32 handle, UINT32 axisIndex, YKS_FollowEncoderConfig config);

YK_API YKM_FollowGroup(INT32 handle, UINT32 axisIndex, YKS_FollowGroupConfig config);

YK_API YKM_SetCamInConfig(INT32 handle, UINT32 axisIndex, YKS_CamInConfig config);

YK_API YKM_GetCamInConfig(INT32 handle, UINT32 axisIndex, YKS_CamInConfig* config);

YK_API YKM_SetCamTable(INT32 handle, UINT32 axisIndex, UINT32 rowIndex, YKS_CamTable data);

YK_API YKM_GetCamTable(INT32 handle, UINT32 axisIndex, UINT32 rowIndex, YKS_CamTable* data);

YK_API YKM_StartCamIn(INT32 handle, UINT32 axisIndex);

YK_API YKM_CalcCam(YKS_CamTable *table, UINT32 size, double *result, YKE_CAM_CURVE type);

YK_API YKM_GetCam(double *result, UINT32 size, double key, double* value, YKE_CAM_CURVE type);

YK_API YKM_LinearInterpolationRelative(INT32 handle, UINT32 channel, YKS_LinearInterpolationRelativeConfig config);

YK_API YKM_LinearInterpolationAbsolute(INT32 handle, UINT32 channel, YKS_LinearInterpolationAbsoluteConfig config);

YK_API YKM_LinearSyncAbsolute(INT32 handle, UINT32 channel, YKS_LinearSyncAbsoluteConfig config);

YK_API YKM_LinearSyncRelative(INT32 handle, UINT32 channel, YKS_LinearSyncRelativeConfig config);

YK_API YKM_CircularInterpolationRelative(INT32 handle, UINT32 channel, YKS_CircularInterpolationRelativeConfig config);

YK_API YKM_CircularInterpolationAbsolute(INT32 handle, UINT32 channel, YKS_CircularInterpolationAbsoluteConfig config);

YK_API YKM_StopMultiAxis(INT32 handle, UINT32 channel, YKE_STOP_DEC dec_sel);

YK_API YKM_ReadMultiAxisStatus(INT32 handle, UINT32 channel, YKS_MultiAxisStatus* status);

YK_API YKM_MoveSyncAbsolute(INT32 handle, YKS_SyncStartConfig config);

YK_API YKM_SetGroupProfile(INT32 handle, UINT32 groupIndex, YKS_GroupProfile config);

YK_API YKM_GetGroupProfile(INT32 handle, UINT32 groupIndex, YKS_GroupProfile* config);

YK_API YKM_InitGroup(INT32 handle, UINT32 groupIndex, YKS_GroupConfig config);

YK_API YKM_GetGroupConfig(INT32 handle, UINT32 groupIndex, YKS_GroupConfig* config);

YK_API YKM_DeInitGroup(INT32 handle, UINT32 groupIndex);

YK_API YKM_SetCncProfile(INT32 handle, UINT32 groupIndex, YKS_CncProfile config);

YK_API YKM_GetCncProfile(INT32 handle, UINT32 groupIndex, YKS_CncProfile* config);

YK_API YKM_ReadGroupStatusBase(INT32 handle, UINT32 groupIndex, YKS_GroupStatusBase* status);

YK_API YKM_ReadGroupStatusCnc(INT32 handle, UINT32 groupIndex, YKS_GroupStatusCnc* status);

YK_API YKM_ClearGroupWarn(INT32 handle, UINT32 groupIndex);

YK_API YKM_StopGroup(INT32 handle, UINT32 groupIndex, YKE_STOP_DEC dec_sel);

YK_API YKM_StartGroup(INT32 handle, UINT32 groupIndex);

YK_API YKM_PauseGroup(INT32 handle, UINT32 groupIndex);

YK_API YKM_MoveLinearAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveLinearAbsoluteConfig config);

YK_API YKM_MoveLinearRelative(INT32 handle, UINT32 groupIndex, YKS_MoveLinearRelativeConfig config);

YK_API YKM_MoveHelixAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveHelixAbsoluteConfig config);

YK_API YKM_MoveHelixRelative(INT32 handle, UINT32 groupIndex, YKS_MoveHelixRelativeConfig config);

YK_API YKM_MoveCircularAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveCircularAbsoluteConfig config);

YK_API YKM_MoveCircularRelative(INT32 handle, UINT32 groupIndex, YKS_MoveCircularRelativeConfig config);

YK_API YKM_MoveCardinalRelative(INT32 handle, UINT32 groupIndex, YKS_MoveCardinalRelativeConfig config);

YK_API YKM_MoveCardinalAbsolute(INT32 handle, UINT32 groupIndex, YKS_MoveCardinalAbsoluteConfig config);

YK_API YKM_GroupDigitalOutput(INT32 handle, UINT32 groupIndex, YKS_GroupDoConfig config);

YK_API YKM_GroupPwmOutput(INT32 handle, UINT32 groupIndex, YKS_GroupPwmConfig config);

YK_API YKM_GroupWritePDO(INT32 handle, UINT32 groupIndex, YKS_GroupWritePdoConfig config);

YK_API YKM_GroupWriteRegister(INT32 handle, UINT32 groupIndex, YKS_GroupWriteRegisterConfig config);

YK_API YKM_GroupWriteEvent(INT32 handle, UINT32 groupIndex, YKS_GroupWriteEventConfig config);

YK_API YKM_GroupWriteTensive(INT32 handle, UINT32 groupIndex, YKS_GroupCardinalConfig config);

YK_API YKM_GroupMoveRelative(INT32 handle, UINT32 groupIndex, YKS_GroupMoveRelativeConfig config);

YK_API YKM_GroupMoveAbsolute(INT32 handle, UINT32 groupIndex, YKS_GroupMoveAbsoluteConfig config);

YK_API YKM_GroupDelay(INT32 handle, UINT32 groupIndex, YKS_GroupDelayConfig config);

YK_API YKM_GroupWaitDigitalInput(INT32 handle, UINT32 groupIndex, YKS_GroupDigitalInputConfig config);

YK_API YKM_GroupWaitAxis(INT32 handle, UINT32 groupIndex, YKS_GroupWaitAxisConfig config);

YK_API YKM_GroupWaitPdo(INT32 handle, UINT32 groupIndex, YKS_GroupWaitPdoConfig config);

YK_API YKM_GroupWaitRegister(INT32 handle, UINT32 groupIndex, YKS_GroupWaitRegisterConfig config);

YK_API YKM_GroupWaitEvent(INT32 handle, UINT32 groupIndex, YKS_GroupWaitEventConfig config);

YK_API YKM_GroupTransMarkOn(INT32 handle, UINT32 groupIndex, YKS_GroupTransMarkConfig config);

YK_API YKM_GroupTransMarkOff(INT32 handle, UINT32 groupIndex);

YK_API YKM_GroupAddiXYOn(INT32 handle, UINT32 groupIndex, YKS_GroupAddiXYConfig config);

YK_API YKM_GroupAddiXYOff(INT32 handle, UINT32 groupIndex);

YK_API YKM_CalcMark(double* ptRef, double* ptReal, YKS_GroupTransMarkConfig* config);

YK_API YKM_GroupWriteGCode(INT32 handle, UINT32 groupIndex, YKS_CncGCode config);

YK_API YKM_GroupLoadFile(INT32 handle, UINT32 groupIndex, char* filename);

YK_API YKM_GroupCncASpline(INT32 handle, UINT32 groupIndex, YKS_CncASplineConfig config);

YK_API YKM_GroupCncSplineClose(INT32 handle, UINT32 groupIndex, UINT32 mark);

YK_API YKM_GroupCncContourDev(INT32 handle, UINT32 groupIndex, YKS_CncContourDevConfig config);

YK_API YKM_GroupCncContourDist(INT32 handle, UINT32 groupIndex, YKS_CncContourDistConfig config);

YK_API YKM_GroupCncContourDistSoft(INT32 handle, UINT32 groupIndex, YKS_CncContourDistSoftConfig config);

YK_API YKM_GroupCncContourDistMaster(INT32 handle, UINT32 groupIndex, YKS_CncContourDistMasterConfig config);

YK_API YKM_GroupCncContourPos(INT32 handle, UINT32 groupIndex, YKS_CncContourPosConfig config);

YK_API YKM_GroupCncContourPtp(INT32 handle, UINT32 groupIndex, YKS_CncContourPtpConfig config);

YK_API YKM_GroupCncContourClose(INT32 handle, UINT32 groupIndex, UINT32 mark);

YK_API YKM_GroupCncHscB(INT32 handle, UINT32 groupIndex, YKS_CncHscBConfig config);

YK_API YKM_GroupCncHscS(INT32 handle, UINT32 groupIndex, YKS_CncHscSConfig config);

YK_API YKM_GroupCncHscPcs1(INT32 handle, UINT32 groupIndex, YKS_CncHscPcs1Config config);

YK_API YKM_GroupCncHscPcs2(INT32 handle, UINT32 groupIndex, YKS_CncHscPcs2Config config);

YK_API YKM_GroupCncHscClose(INT32 handle, UINT32 groupIndex, UINT32 mark);

YK_API YKM_ReadCncParaCmd(INT32 handle, UINT32 axisIndex, char* para_name, UINT32 size_name);

YK_API YKM_WriteCncParaCmd(INT32 handle, UINT32 axisIndex, char* para_name, UINT32 size_name, char* para_value, UINT32 size_value);

YK_API YKM_ReadCncParaStatus(INT32 handle, UINT32 axisIndex, YKS_CncParaStatus* status);

YK_API YKM_StartProbeHard(INT32 handle, UINT32 axisIndex, UINT32 channel);

YK_API YKM_StopProbeHard(INT32 handle, UINT32 axisIndex, UINT32 channel);

YK_API YKM_ReadProbeStatusHard(INT32 handle, UINT32 axisIndex, UINT32 channel, UINT32* status, double* position);

YK_API YKM_GetAxisProbeConfigSoft(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisProbeConfigSoft* config);

YK_API YKM_SetAxisProbeConfigSoft(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisProbeConfigSoft config);

YK_API YKM_ReadAxisProbeStatusSoft(INT32 handle, UINT32 axisIndex, UINT32 channel, YKS_AxisProbeStatusSoft* status);

YK_API YKM_StartAxisProbeSoft(INT32 handle, UINT32 axisIndex, UINT32 channel);

YK_API YKM_StopAxisProbeSoft(INT32 handle, UINT32 axisIndex, UINT32 channel);

YK_API YKM_WriteEventInputOneSignal(INT32 handle, UINT32 channel, YKS_TriggerArgOneSignal input);

YK_API YKM_WriteEventInputTwoSignal(INT32 handle, UINT32 channel, YKS_TriggerArgTwoSignal input);

YK_API YKM_WriteEventInputAxisPosition(INT32 handle, UINT32 channel, YKS_TriggerArgAxisPosition input);

YK_API YKM_WriteEventInputAxisTime(INT32 handle, UINT32 channel, YKS_TriggerArgAxisTime input);

YK_API YKM_WriteEventInputAxisVelocity(INT32 handle, UINT32 channel, YKS_TriggerArgAxisVelocity input);

YK_API YKM_WriteEventInputAxisTorque(INT32 handle, UINT32 channel, YKS_TriggerArgAxisTorque input);

YK_API YKM_WriteEventInputSlavePDO(INT32 handle, UINT32 channel, YKS_TriggerArgSlavePDO input);

YK_API YKM_WriteEventInputEncoder(INT32 handle, UINT32 channel, YKS_TriggerArgEncoder input);

YK_API YKM_WriteEventOutputOneSignal(INT32 handle, UINT32 channel, YKS_TriggerOutputOneBit output);

YK_API YKM_WriteEventOutputStopAxis(INT32 handle, UINT32 channel, YKS_TriggerOutputStopAxis output);

YK_API YKM_WriteEventOutputStartGroup(INT32 handle, UINT32 channel, YKS_TriggerOutputStartGroup output);

YK_API YKM_WriteEventOutputStartAxis(INT32 handle, UINT32 channel, YKS_TriggerOutputStartAxis output);

YK_API YKM_WriteEventOutputSoftEmgStop(INT32 handle, UINT32 channel, YKS_TriggerOutputSoftEmgStop output);

YK_API YKM_WriteEventOutputSlavePDO(INT32 handle, UINT32 channel, YKS_TriggerOutputSlavePDO output);

YK_API YKM_WriteEventOutputMultiAxis(INT32 handle, UINT32 channel, YKS_TriggerOutputStartMultiAxis output, YKS_LinearSyncAbsoluteConfig motion);

YK_API YKM_WriteEventOutputTargetTorque(INT32 handle, UINT32 channel, YKS_TriggerOutputTargetTorque output);

YK_API YKM_WriteEventOutputDelayMs(INT32 handle, UINT32 channel, YKS_TriggerOutputDelayMs output);

YK_API YKM_WriteEventOutputDataReg(INT32 handle, UINT32 channel, YKS_TriggerOutputDataReg output);

YK_API YKM_EnableEvent(INT32 handle, UINT32 channel);

YK_API YKM_DisableEvent(INT32 handle, UINT32 channel);

YK_API YKM_ReadEventStatus(INT32 handle, UINT32 channel, YKS_EventStatus* status);

YK_API YKM_GetCardNumPCI(INT32 handle, UINT32* num);

YK_API YKM_GetCardConfigPCI(INT32 handle, UINT32 card_index, YKS_CardConfigPCI* config);

YK_API YKM_ReadAxisStatusPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisStausPCI* status);

YK_API YKM_SetSwitchDrvReadyPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchDrvReadyPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

YK_API YKM_SetSwitchDrvWarnPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchDrvWarnPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

YK_API YKM_SetSwitchDrvInpPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchDrvInpPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

YK_API YKM_SetSwitchDrvEnablePCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchDrvEnablePCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

YK_API YKM_SetSwitchDrvResetPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig config);

YK_API YKM_GetSwitchDrvResetPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_AxisSwitchConfig* config);

YK_API YKM_SetEncoderConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_EncoderConfig config);

YK_API YKM_GetEncoderConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_EncoderConfig* config);

YK_API YKM_WriteEncoderValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, INT32 value);

YK_API YKM_ReadEncoderValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, INT32* value);

YK_API YKM_StartEncoderPCI(INT32 handle, UINT32 card_index, UINT32 channel);

YK_API YKM_StopEncoderPCI(INT32 handle, UINT32 card_index, UINT32 channel);

YK_API YKM_SetCompareConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareConfig config);

YK_API YKM_GetCompareConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareConfig* config);

YK_API YKM_SetCompareValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareItemData itemdata);

YK_API YKM_ReadCompareStatusPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CompareStatus* status);

YK_API YKM_StartComparePCI(INT32 handle, UINT32 card_index, UINT32 channel);

YK_API YKM_StopComparePCI(INT32 handle, UINT32 card_index, UINT32 channel);

YK_API YKM_SetCaptureConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CaptureConfig config);

YK_API YKM_GetCaptureConfigPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_CaptureConfig* config);

YK_API YKM_ReadCaptureStatusPCI(INT32 handle, UINT32 card_index, UINT32 channel, UINT32* status);

YK_API YKM_ReadCaptureValuePCI(INT32 handle, UINT32 card_index, UINT32 channel, INT32* value);

YK_API YKM_StartCapturePCI(INT32 handle, UINT32 card_index, UINT32 channel);

YK_API YKM_StopCapturePCI(INT32 handle, UINT32 card_index, UINT32 channel);

YK_API YKM_StartPwmPCI(INT32 handle, UINT32 card_index, UINT32 channel, YKS_PwmConfig config);

YK_API YKM_StopPwmPCI(INT32 handle, UINT32 card_index, UINT32 channel);

YK_API YKM_SetBacklashConfig(INT32 handle, UINT32 axisIndex, YKS_BacklashConfig config);

YK_API YKM_GetBacklashConfig(INT32 handle, UINT32 axisIndex, YKS_BacklashConfig* config);

YK_API YKM_EnableBacklash(INT32 handle, UINT32 axisIndex);

YK_API YKM_DisableBacklash(INT32 handle, UINT32 axisIndex);

YK_API YKM_SetPitchError1DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError1DConfig config);

YK_API YKM_GetPitchError1DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError1DConfig* config);

YK_API YKM_SetPitchError1DData(INT32 handle, UINT32 axisIndex, double *pos_data, double *neg_data, UINT32 size);

YK_API YKM_GetPitchError1DData(INT32 handle, UINT32 axisIndex, double *pos_data, double *neg_data, UINT32 size);

YK_API YKM_EnablePitchError1D(INT32 handle, UINT32 axisIndex);

YK_API YKM_DisablePitchError1D(INT32 handle, UINT32 axisIndex);

YK_API YKM_SetPitchError2DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError2DConfig config);

YK_API YKM_GetPitchError2DConfig(INT32 handle, UINT32 axisIndex, YKS_PitchError2DConfig* config);

YK_API YKM_SetPitchError2DData(INT32 handle, UINT32 axisIndex, double *data, UINT32 size);

YK_API YKM_GetPitchError2DData(INT32 handle, UINT32 axisIndex, double *data, UINT32 size);

YK_API YKM_EnablePitchError2D(INT32 handle, UINT32 axisIndex);

YK_API YKM_DisablePitchError2D(INT32 handle, UINT32 axisIndex);

YK_API YKM_SetCircleZoneConfig(INT32 handle, UINT32 channel, YKS_CircleZoneConfig config);

YK_API YKM_GetCircleZoneConfig(INT32 handle, UINT32 channel, YKS_CircleZoneConfig* config);

YK_API YKM_EnableCircleZone(INT32 handle, UINT32 channel);

YK_API YKM_DisableCircleZone(INT32 handle, UINT32 channel);

YK_API YKM_ReadCircleZoneStatus(INT32 handle, UINT32 channel, YKS_CircleZoneStatus* status);

YK_API YKM_SetOscConfig(INT32 handle, UINT32 oscIndex, YKS_OscConfig config);

YK_API YKM_GetOscConfig(INT32 handle, UINT32 oscIndex, YKS_OscConfig* config);

YK_API YKM_SetOscItem(INT32 handle, UINT32 oscIndex, UINT32 itemIndex, YKS_OscItem item);

YK_API YKM_GetOscItem(INT32 handle, UINT32 oscIndex, UINT32 itemIndex, YKS_OscItem* item);

YK_API YKM_ClearOscItem(INT32 handle, UINT32 oscIndex);

YK_API YKM_ReadOscStatus(INT32 handle, UINT32 oscIndex, YKS_OscStatus* status);

YK_API YKM_ReadOscData(INT32 handle, UINT32 oscIndex, double *buffer, UINT32 size, UINT32* ret_size);

YK_API YKM_StartOsc(INT32 handle, UINT32 oscIndex);

YK_API YKM_StopOsc(INT32 handle, UINT32 oscIndex);

YK_API YKM_TrigOsc(INT32 handle, UINT32 oscIndex);

YK_API YKM_WriteCommandPosition(INT32 handle, UINT32 magic, UINT32 axisIndex, double position);

YK_API YKM_LoadNTFDotNet(INT32 handle, YKE_NODE master, char* exe_name);

YK_API YKM_CheckNTFDotNet(INT32 handle, YKE_NODE master, char* exe_name, YKE_BOOL* status);

YK_API YKM_LoadRtaApp(INT32 handle, YKE_NODE master, char* file_name, char* para);

YK_API YKM_CheckRtaApp(INT32 handle, YKE_NODE master, char* rta_name, YKE_BOOL* status);

YK_API YKM_KillRtaApp(INT32 handle, YKE_NODE master, char* rta_name, YKE_BOOL* status);

YK_API YKM_ReadNTFLog(INT32 handle, YKE_NODE node, char* buff, UINT32 size, UINT32* count);

YK_API YKM_SetApiBufferCallBack(INT32 handle, UINT64* callback, UINT32 size);

YK_API YKM_StartApiBufferRecord(INT32 handle, UINT32 channel);

YK_API YKM_EndApiBufferRecord(INT32 handle, UINT32 channel);

YK_API YKM_SetApiBufferMark(INT32 handle, UINT32 channel, UINT32 mark);

YK_API YKM_SimConnect(INT32 handle, char* ipAddress, UINT32 port);

YK_API YKM_SimJointConfig(INT32 handle, UINT32 jointIndex, char* jointName, UINT32 axisIndex, YKE_AXIS_SIM_TYPE axisType);

YK_API YKM_SimStart(INT32 handle);

YK_API YKM_SimStop(INT32 handle);

YK_API YKM_SimDisconnect(INT32 handle);

YK_API YKM_WaitAxis(INT32 handle, UINT32 channel, YKS_WaitAxis config);

YK_API YKM_WaitDigitalInput(INT32 handle, UINT32 channel, YKS_WaitDigitalInput config);

YK_API YKM_WaitEvent(INT32 handle, UINT32 channel, YKS_WaitEvent config);

YK_API YKM_WaitSleepMs(INT32 handle, UINT32 channel, double time);

YK_API YKM_WaitReset(INT32 handle, UINT32 channel);

YK_API YKM_ReadWaitStatus(INT32 handle, UINT32 channel, YKS_WaitStatus *status);


#endif
