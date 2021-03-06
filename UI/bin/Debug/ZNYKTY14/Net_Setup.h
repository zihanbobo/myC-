/**************************************************************************
* 版    权： 	Copyright (c) 2015 
* 文件名称：	Net_Setup.h
* 文件标识： 
* 内容摘要：    摄像机网络开发SDK,处理配置消息
* 其它说明： 
* 当前版本：	V1.0
* 作    者	
* 完成日期：	2013年08月28日
**************************************************************************/
#ifndef __DCNETSETUP_H
#define __DCNETSETUP_H

#ifdef     NET_API
#else
   #define NET_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

typedef int DCHANDLE;

#define HANDLE_INVALID -1

/**************************************************************************
 *                         数据类型                                    *
 **************************************************************************/

#define VERSION_NAME_LEN	 	64
#define MAX_SERVER_NAME_LEN		64
#define MAX_USER_PWD_LEN		32
#define MAX_FILE_NAME_LEN		256
#define MAX_TIMEBUCKET			4
#define MAX_HOST_LEN			16
#define ONE_DIRECTION_LANES		(5)
#define EVENT_CAP_TIMEBUCEKT_CNT 4
#define MAX_PARTITION_COUNT     10
#define MSG_PARAM_LEN			1424
#define MAX_LED_COUNT           5
#define MAX_LED_CONTENT         64
#define LPR_FILE 	   "lpr.ini"
#define  AVE_REG_NUM       8       //设置区域数目
/* 状态码常量定义*/
typedef enum
{
	DC_NO_ERROR			      = 0,   //正常
	DC_HANDLE_INVALID		  = 1,   //无效的句柄
	DC_CONN_FAIL			  = 2,   //连接失败
	DC_OBJ_BUSY				  = 3,   //对象忙
	DC_OBJ_UNEXIST			  = 4,   //对象不存在
	DC_CMD_INVALID			  = 5,   //命令无效
	DC_PARA_INVALID			  = 6,   //参数无效
	DC_REQ_TIMEOUT			  = 7,   //请求超时
	DC_MEMORY_LACK 			  = 8,   //内存申请失败
	DC_SEND_FAIL 			  = 9,   //数据发送失败
	DC_RECV_FAIL			  = 10,  //数据接收失败
	DC_OPT_FAIL				  = 11,  //操作失败
	DC_NOT_CONN 			  = 12,  //没有触发连接
	DC_BEYOND_MAX_CLIENT      = 13, //超出相机最大连接数量
	DC_CONNECT_AUTH           = 18,  /*连接鉴权*/
	DC_USER_NOT_EXIST		  = 19, /*用户不存在*/
	DC_PASSWD_ERROR			  = 20, /*密码错误*/
	DC_UNDEFINED_ERROR		  = -1
}E_ReturnCode;


typedef struct 
{
	unsigned short usFileType;
	unsigned short usServerPort;
	char aucServerIp[32];
	char aucFileName[128];
	unsigned int  uiFileSize;
}T_FileUpdateSetup;

typedef struct 
{

	UINT8 ucLprMode;  /* 0：黑名单；1：白名单*/
	UINT8 ucReseved;
	UINT16 usServerPort;
	INT8 aucServerIp[32];
}T_ExportBlackWhiteList;

typedef enum 
{
	WHITE_LIST_NEW_SEND,//重新发送
	WHITE_LIST_ADD_SEND,//续传
	WHITE_LIST_DEL_SEND,//删除
	WHITE_LIST_MAX
}E_WhiteListSendMode;
typedef enum
{
	BLACK_LIST,//白名单
	WHITE_LIST//黑名单
}E_ListMode;
typedef enum
{
	CODE_IN_UTF8,//UTF-8编码
	CODE_IN_GB2312//GB2312编码
}E_CodeMode;

typedef struct 
{
	UINT8 ucLprMode;  /* E_ListMode*/
	UINT8 ucLprCode;      /* E_CodeMode*/
	UINT16 usServerPort;
	UINT8 ucLprnew; /*E_WhiteListSendMode；*/
	UINT8 aucReseved[3];
	INT8 aucServerIp[32];
	INT8 aucFileName[128];
	UINT32  uiFileSize;
}T_ImportBlackWhiteList;


/* 磁盘分区显示*/
typedef struct
{
	unsigned int	uiSizeM;							/* 分区大小，以MByte为单位*/
	unsigned int	uiUsedM;							/* 已使用大小，以MByte为单位*/
}T_PartitionInfo;

typedef struct
{
	unsigned char		ucPartitionCnt;
	unsigned char		aucReserved[3];
	T_PartitionInfo atPartition[MAX_PARTITION_COUNT];
}T_HardDiskInfo;

typedef enum
{
	LED_SCREEN_I = 0,
	LED_SCREEN_II,
	LED_SCREEN_OFFLINE_I,      
	LED_SCREEN_OFFLINE_II,   
	LED_SCREEN_III,             
	LED_SCREEN_OFFLINE_III,
	LED_SCREEN_IV,
	LED_SCREEN_V,
	LED_SCREEN_VI,
	LED_SCREEN_VII,
	LED_SCREEN_VIII,
	LED_SCREEN_IX,
	LED_SCREEN_X,
	LED_SCREEN_XI,
	LED_SCREEN_XII,
	LED_SCREEN_MAX
}E_LedScreenType;
typedef enum 
{ 
	LS_MODE_UNKNOW = 0, 
	LS_MODE_OFFLINE,	 /*脱机使能*/ 
	LS_MODE_ENABLE,	 /*使能，不分区联机、脱机*/ 
	LS_MODE_DISABLE,	 /*不使能*/ 
	LS_MODE_MAX 
}E_LedScreenMode; 
typedef struct
{
	UINT32	uiInterval;//抬闸脉冲时长ms	
	UINT8   ucLed;//E_LedScreenType
	UINT8   ucLedScreenMode;//E_LedScreenMode
	UINT16	usDownInterval;//落闸脉冲时长ms
}T_ParkSetup;
typedef struct
{
	unsigned char		ucPartitionNum;
}T_HardDiskNum;/*格式化硬盘选择分区*/

typedef struct
{
	unsigned char ucTransProt;	/* E_TransmitProtocol*/
	unsigned char szReserved[3];
}T_TransProt;

/*日志级别*/
typedef enum
{
	LOG_LEVEL_INFO_MAX = 0,
	LOG_LEVEL_INFO_MID,
	LOG_LEVEL_INFO_MIN,
}E_LogLevelInfo;

/*定时重启*/
typedef struct
{
	unsigned char  ucLogLevel;  /*E_LogLevelInfo*/
	unsigned char  ucAutoRebootEn;
	unsigned char  aucReserved[2];
	unsigned int uiAutoRebootTime;
}T_TimeReboot;

typedef struct
{
	unsigned short usFileType;//业务是0；内核是2；文件系统是3；详见E_UpgradeType
	char aucFilePath[128];
}T_UpdateSetup;

typedef struct
{
	char aucFilePath[256];
}T_ImportConfigSetup;

typedef struct
{
	char aucFilePath[256];
}T_ExportConfigSetup;

typedef struct 
{
	char  szFileName[256];
}T_FileName;

/* 软件升级类型*/
typedef enum
{
	UPGRADE_TYPE_APP	= 0,
	UPGRADE_TYPE_KERNEL = 2,
	UPGRADE_TYPE_FS		= 3,
	UPGRADE_TYPE_WEB	= 4,
	UPGRADE_TYPE_DSP	= 5,
	UPGRADE_TYPE_LOGO	= 6,
	UPGRADE_TYPE_ALL
}E_UpgradeType;

#ifndef _T_NetSetup
#define _T_NetSetup
typedef struct
{
	unsigned char	ucEth;				/* 以太网口编号,目前只支持0*/
	unsigned char	aucReserved[3];
	unsigned int	uiIPAddress;		
	unsigned int	uiMaskAddress;
	unsigned int	uiGatewayAddress;
	unsigned int	uiDNS1;
	unsigned int	uiDNS2;
	char	szHostName[MAX_HOST_LEN];
}T_NetSetup;
#endif	
/* 组播配置*/
typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	aucReserved;
	unsigned short	usOfflinePort;
	unsigned int	uiIP;
	unsigned short	usMainVidPort;
	unsigned short	usViceVidPort;
	unsigned short	usMainAudPort;
	unsigned short	usViceAudPort;
}T_MulticastSetup;

/* MAC地址配置*/
#ifndef _T_MACSETUP
#define _T_MACSETUP
typedef struct
{
	unsigned char	ucEth;				/* 以太网口编号,目前只支持0*/
	unsigned char	aucReserved[3];
	unsigned char	aucMACAddresss[6];
}T_MACSetup;
#endif

typedef struct
{
	 unsigned char   ucEnable;
	 unsigned char   ucReserved;  
	 unsigned short  usPort;
	 char			 szIpAddr[16];
}T_AssistantIpnc;  /*辅助相机配置*/

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucCharCode;
	unsigned short 	usPort;
	char			szIpAddr[16];
}T_Messenger;

typedef struct 
{ 
	unsigned char ucCusNo; /*客户编号，0表示未知*/ 
	unsigned char aucReserved[3]; 
}T_CustomerNo;

typedef struct
{
	unsigned char	ucEnable;      /*定时使能*/
	unsigned char	ucTimeLen;   /*执行时长，单位:秒*/
	unsigned char	aucReserved[2];
	unsigned int	uiAutoStartTime; /*雨刷定时启动时间0x00HHMMSS 低字节为秒*/
}T_WiperTiming;

typedef  struct  
{
	unsigned short x1;                         //矩形左上角x坐标
	unsigned short y1;                         //矩形左上角y坐标
	unsigned short x2;			       //矩形右下角x坐标
	unsigned short y2;                         //矩形右下角y坐标
}T_Ave_Rect;

//标示物形状，距离
typedef  struct  
{
	unsigned short	uwDist;                  //预设标示物距离摄像机水平距离
	unsigned short	uwResrved;
	T_Ave_Rect		tAveRect;                //预设标示物矩形坐标
}T_Ave_Par;

//能见度配置信息
typedef  struct  
{
	unsigned char   ucBlureTh;             //模糊度阈值范围【0,100】,越大越模糊
	unsigned char	ucRegNum;		  //预设标示物数目-最多8个
	unsigned short	uwResrved;
	T_Ave_Par      tAvePar[AVE_REG_NUM];  //预设标示物矩形坐标
}T_Ave_Config;

typedef struct
{
	UINT16	   uwDistVmet;
	UINT16	   uwResrved;
}T_Ave_Result;

typedef enum
{
	PARK_OFFLINE_STATE,//脱机状态
	PARK_ONLINE_STATE,//联机状态
	PARK_MAX_STATE
}E_ParkState;
typedef struct
{
	UINT8	ucState;
	UINT8	aucReserved[3];
}T_ParkRealTimeState;//相机与岗亭连接的实时状态，是联机还是脱机

typedef struct 
{
	UINT8  	ucState; /*0:关1:开*/
	UINT8	aucReserved[3]; 
}T_WiperManual;  /*雨刷手动控制*/

typedef struct
{
	unsigned short usSigCtrlSerPort;
	unsigned char  aucReserved[2];
}T_SigControlPort;

 /* 服务端口配置 */
typedef struct
{
	unsigned short	usHttpPort;
	unsigned short	usRtspPort;
}T_ServicePortSetup;

 /* 图像编码参数 */
typedef struct
{
	unsigned char	ucMode;			/* 编码模式，目前仅支持JPEG；*/
	unsigned char	ucFmt;			/* 编码格式，分辨率相关*/
	unsigned char	ucQuality;		/* 编码质量*/
	unsigned char	ucPeriod;		/* 编码周期，1～7秒/张*/
}T_ImageCodec;

/* 操作模式*/
typedef enum
{
	OPERATE_MODE_MANUAL = 1, 				/* 手动模式*/
	OPERATE_MODE_AUTO,	            /* 自动模式*/
	OPERATE_MODE_ALL
}E_OperateMode;


/* 视频编码参数*/
typedef struct
{
	unsigned char	ucMode;			/* 编码模式，目前仅支持H264；*/
	unsigned char	ucFmt;			/* 编码格式，分辨率相关*/
	unsigned char	ucFps;			/* 帧频， PAL制1～25可选；NTSC制，当分辨率为1080P时，1～25可选，其它情况1～30可选；*/
	unsigned char	ucRateControl; 	/* 码率控制，0->VBR(可变码率)，1->CBR(固定码率)*/
	unsigned int	uiRate;			/* 码率，384000～16000000 bps*/
	unsigned char	ucIFPeriod;		/* I帧间隔，1～5 秒；*/
	unsigned char	ucEnabled;		/*编码是否启动，辅视频生效*/
	unsigned char   ucIncSnapFrame; /*包含抓拍帧使能*/      
	unsigned char	ucReserved;
}T_VideoCodec;

typedef enum
{
	BAUD_RATE_1200,
	BAUD_RATE_2400,
	BAUD_RATE_4800,
	BAUD_RATE_9600,
	BAUD_RATE_19200,
	BAUD_RATE_38400,
	BAUD_RATE_57600,
	BAUD_RATE_115200,
	BAUD_RATE_ALL
}E_BaudRate;

typedef enum
{
	RS485_FUNCTION_PASS = 0,
	RS485_FUNCTION_SCREEN,
	RS485_FUNCTION_MAX,
}E_RS485Function;
typedef enum
{
	CHECK_TYPE_NONE,	/* 无校验*/
	CHECK_TYPE_ODD,		/* 奇校验*/
	CHECK_TYPE_EVEN,	/* 偶校验*/
	CHECK_TYPE_FLAG,	/* 标志校验*/
	CHECK_TYPE_EMPTY,	/* 空校验*/
	CHECK_TYPE_ALL
}E_CheckType;
/* RS485配置*/
typedef struct
{
	UINT8   ucIndex;
	UINT8   ucFunction;         /*E_RS485Function*/
	UINT8	ucBaudRate;			/* E_BaudRate*/
	UINT8	ucDataBits;			/* 数据位，5～8；*/
	UINT8	ucStopBits;			/* 停止位，0～2；*/
	UINT8	ucCheckOut;			/* E_CheckType*/
	UINT8   ucReserved[2];
}T_RS485Setup;

 /*背光补偿*/
typedef struct
{
	unsigned char ucEnable;
	unsigned char aucReservel[3];
}T_ImageEv; 

 /*宽动态*/
typedef struct
{
	unsigned char ucEnable;
	unsigned char ucExposalTime1; /*0<  <15*/
	unsigned char ucInducePressure1;/*64<   <127*/
	unsigned char ucExposalTime2;
	unsigned char ucInducePressure2;
	unsigned char aucReserved[3];
}T_ImageWDR;

typedef enum
{
	KAKOU = 0,          /*卡口*/
	RUN_REDLIGHT,   	/*闯红灯*/
	OVER_SPEED,     	/*超速*/
	REVERSE,        	/*逆行*/
	TRAFFIC_BAN,    	/*禁行，卡口使用*/
	CROSS_LINE,     	/*越线*/
	ILLEGAL_STOP,    	/*违停*/
	ILLEGAL_OCCUP,   	/*专用道*/
	ILLEGAL_PRESS_LINE, /*压线*/
	ILLEGAL_NOLANE_RUN, /*不按导向行驶*/
	SNAPSHOT_TYPE_ALL,  /*有效类型*/
	ILLEGAL_PREDICT,  	/*违法预言*/
	NET_SNAP = 0xFF,
}E_SnapshotType;

/* 事件抓拍参数*/
typedef struct
{
	unsigned char	ucEventCaptureType;   /* 事件抓拍类型 E_SnapshotType 0(卡口抓拍)1（闯红灯抓拍）3(逆行)4（禁行抓拍）5（越线抓拍）6（违停抓拍）8（压线抓拍）9(不按导向行驶抓拍)*/
	unsigned char	ucPicSnapshotNum;     /*抓拍张数*/
	unsigned char	szReserver[2];
	/* -1：进线圈1，-2：进线圈2：-3：出线圈1，-4：出线圈2，
		-5：进检测线 对于视频检测，表示车头碰到检测线了；若为雷达检测，车辆进入雷达检测域，被雷达设备发现
		-6：出检测线 对于视频检测，表示车尾离开检测线了；若为雷达检测，这个选项无效，
		其它大于0的值，表示延时抓拍，该值表示延时时间， 0～300ms
	*/
	int	aiGetPicPosition[3];
	unsigned char	ucPicMergeType;				/* 图片合成类型，0：不合成，1：横向合成，2：纵向合成，3：视频+数码（上下布局），4：视频+数码（左右布局），5：田字风格*/
	unsigned char	ucMainPicItem;				/* 大图序号，当图片类型为3、4时有效；*/
	unsigned char	ucRecordEnable;				/* 是否支持违法录像*/
	unsigned char	ucRecordTime;				/* 录像时长，4～7秒*/
	unsigned char 	ucPreRecordTime;			/*预录时长，0～3秒，默认为2s*/
	unsigned char 	ucReserved;					/*保留字段*/
	unsigned short  usIllegalCode;				/*国标违章代码*/
}T_EventCapturePara;

/*时段*/
typedef struct
{
	unsigned char ucStartHour;
	unsigned char ucStartMinute;
	unsigned char ucEndHour;
	unsigned char ucEndMinute; 	
}T_TimeBucket;

typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	aucReserved[3];
	T_TimeBucket	tTimeBucket;
}T_EnableTimeBucket;


/* 闪光灯配置参数*/
typedef struct
{
	unsigned char		ucFlashLightMode;		/* 单灯、多灯模式，0:单灯*/
	unsigned char		ucNormalWorkMode;		/*正常工作模式E_LightWorkMode*/
	unsigned char		ucIllegalWorkMode;		/*违法工作模式E_LightWorkMode*/
	unsigned char		ucOpenBrightnessTH;		/* 自动模式下，闪光灯开启的亮度阈值；*/
	T_EnableTimeBucket	atFourceFlashTime[2];	/*强制闪光时段*/
}T_FlashLightSetup;

/* 频闪灯配置参数*/
typedef struct
{
	unsigned char	ucNormalWorkMode;			/* 正常补光模式E_LightWorkMode*/
	unsigned char	ucCombinationalWorkMode;	/* 组合补光模式，是指在闪光灯开启的情况下的补光模式E_LightWorkMode*/
	unsigned char	ucOpenBrightnessTH;			/* 自动模式下，频闪灯开启的亮度阈值；*/
	unsigned char	ucReserved;
}T_LedLightBasicSetup;


typedef enum
{
	STRAIGHT_LANE = 0,
	LEFT_TURN_LANE,
	RIGHT_TURN_LANE,
	LEFT_STRAIGHT_LANE,
	RIGHT_STRAIGHT_LANE,
	LEFT_RIGHT_LANE,
	LEFT_STRAIGHT_RIGHT_LANE,  /*20140311 add by zhuby*/
	LANE_TYPE_ALL,
}E_LaneType;

typedef enum
{
	FT_PICTURE_KK = 0,   /*卡口图片*/
	FT_PICTURE_CHD,      /*闯红灯*/
	FT_PICTURE_CS,       /*超速*/
	FT_PICTURE_NX,       /*逆行*/
	FT_PICTURE_JX,       /*禁行*/
	FT_PICTURE_YX,       /*越线*/
	FT_PICTURE_WT,       /*违停*/
	FT_PICTURE_ZD,       /*占道*/
	FT_PICTURE_PL,       /*压线*/
	FT_PICTURE_NRW,      /*不按车道行驶*/
	FT_EVENT_STAT,       /*交通事件统计*/
	FT_LOG_FILE,		 /*报警*/
	FT_AUTO_UPGRADE,     /*自动升级*/
	FT_ALL,
}E_FileType;

typedef struct
{	
	unsigned char	ucEnabled;   		/*时间分段启用*/
	unsigned char	ucWorkDayEnable;	/*工作日启用*/
	unsigned char	ucWeekEndEnable;	/*周末启用*/
	unsigned char	ucReserved1;
	T_TimeBucket	tTimeBucket;
	unsigned char	ucRunRedLightSnap;  /*闯红灯抓拍*/
	unsigned char	ucKaKouSnap;        /*卡口抓拍*/    
	unsigned char	ucReverseSnap;      /*逆行抓拍*/
	unsigned char	ucCrossLineSnap;    /*越线抓拍*/
	unsigned char	ucOverSpeedSnap;	/* 超速抓拍启用*/
	unsigned char	aucReserved2[3];
}T_EventCapTimeBasicSetup;

typedef enum
{
	PLATE_DIRECTION_TAIL = 0,  /*车尾车牌*/
	PLATE_DIRECTION_HEAD,      /*车头车牌*/
	PLATE_DIRECTION_ALL,
}E_PlateDirection;

typedef struct
{
	unsigned char ucEnabled;			/**/
	unsigned char ucLaneNo;				/*车道号*/
	unsigned char ucLaneIndex;
	unsigned char ucLaneType;			/*车道类型E_LaneType*/
	unsigned char ucRedLightSnapTestEn;	/*闯红灯抓拍测试启用*/
	unsigned char ucTimeSegEnable;  	/*分时段*/
	
	unsigned char ucLaneDir; 			/*E_PlateDirection*/
	
	/*最高限速*/
	unsigned char ucMaxSpeed;			/*单位：KM/H 电子警察内部使用，与web交互作为保留字段*/
	
	T_EventCapTimeBasicSetup atCaptureTime[MAX_TIMEBUCKET];/*抓拍时段*/
}T_RoadLaneBasicSetup;

typedef struct
{	
	unsigned char ucEnabled;   		  /*时间分段启用*/
    unsigned char ucWorkDayEnable;    /*工作日启用*/
	unsigned char ucWeekEndEnable;	  /*周末启用*/
	unsigned char uacReserved1;
	T_TimeBucket  tTimeBucket;
	unsigned char ucPressLineSnap;    /*压线抓拍*/
	unsigned char ucNoAccordRoadWay;  /*不按车道行驶*/
	unsigned char ucTrafficBanSnap;   /*禁行抓拍*/ 
	unsigned char ucIllegeStopSnap;   /*违停抓拍*/ 
	unsigned char ucSpecialRoadSnap;  /*专用道抓拍*/
	unsigned char aucReserved[3];
}T_EventCapTimeExtendSetup;

/* 车道扩展参数配置*/
typedef struct
{
	unsigned char	ucLaneIndex;
	unsigned char	ucTrafficStaEn;			/*是否启用交通事件统计*/
	unsigned char	ucOccupRatioEventEn;	/*是否启用占有率报警*/
	unsigned char	ucVehicleStopEventEn;	/*是否启用停驶报警*/
	unsigned char	ucTrafficJamEventEn;	/*是否启用交通拥堵报警*/
	unsigned char	ucSpecialRoadType;
	unsigned char	ucTimeSegEnable;
	unsigned char	ucVehStatTime;			/*交通流量统计周期，单位为分钟*/
	T_EventCapTimeExtendSetup  atCaptureTime[EVENT_CAP_TIMEBUCEKT_CNT];/*抓拍时段*/
}T_RoadLaneExtendSetup;

/* 限速参数配置*/
typedef struct
{
	unsigned char	ucLaneIndex;
	char			cLoopDefaultSpeedRatio;		/*线圈默认速度校正*/
	char			cLoopHightSpeedRatio;		/*线圈高速速度校正*/
	unsigned char	ucLoopHightSpeedCaliLimit;	/*线圈高速校正速度值*/
	char			cRadarDefaultSpeedRatio;	/*雷达默认速度校正*/
	char			cRadarHightSpeedRatio;		/*雷达高速速度校正*/
	unsigned char	ucRadarHightSpeedCaliLimit;	/*雷达高速校正速度值*/
	char			cVideoDefaultSpeedRatio;	/*视频默认速度校正*/
	char			cVideoHightSpeedRatio;		/*视频高速速度校正*/
	unsigned char	ucVideoHightSpeedCaliLimit;	/*视频高速校正速度值*/
	unsigned char	ucHighSpeedLimit;			/*限制最高速度*/
	unsigned char	ucLowSpeedLimit;			/*限制最低速度*/
	unsigned char	ucSpeedLimitClassifyEn;		/*按车型限速启用*/
	unsigned char	ucCarHighSpeedLimit;		/*小型车最高速度*/
	unsigned char	ucCarLowSpeedLimit;			/*小型车最低速度*/
	unsigned char	ucTruckHighSpeedLimit;		/*大型车最高速度*/
	unsigned char	ucTruckLowSpeedLimit;		/*大型车最低速度*/
	unsigned char	szReserved[3];
}T_SpeedCorrAndLimitSetup;

typedef struct 
{
	unsigned char	ucPlateRecogEn;				/* 车牌识别使能*/
	unsigned char	ucVehicleSizeRecogEn;		/* 车型识别使能*/
	unsigned char	ucVehicleColorRecogEn;		/* 车身颜色识别使能*/
	unsigned char	ucVehicleBrandRecogEn;		/* 车标识别使能*/
	unsigned char	ucVehicleSizeClassify;		/* 同一辆车抓拍间隔时间高字节*/
	unsigned char	ucLocalCity; 				/*车牌的第二个字符，'A'~'Z'的数字编码*/
	unsigned char   ucPlateDirection;           /*车牌方向E_PlateDirection*/
	unsigned char	ucCpTimeInterval; //同一辆车抓拍间隔时间低字节
	unsigned int	uiPlateDefaultWord;			/* 默认省份，采用UTF-8编码*/
	
	unsigned short	usMinPlateW;				/*车牌识别最小宽度,单位:像素*/
	unsigned short	usMaxPlateW;				/*车牌识别最大宽度，单位:像素*/
	unsigned char	ucDoubleYellowPlate;		/*双层黄牌识别，1：识别 0：不知别*/
	unsigned char	ucDoubleArmyPlate;			/*双层军牌识别，1：识别 0：不知别*/
	unsigned char	ucPolicePlate;				/*武警车牌识别，1：识别 0：不知别*/
	unsigned char	ucPlateFeature;	 /*车牌特写*/ 
}T_VehicleVAFunSetup;


typedef struct
{
	unsigned char ucTime;
	unsigned char ucAddress;
	unsigned char ucDevNo;
	unsigned char ucRecordNo;		/*备案号*/
	unsigned char ucIllegalCode;
	unsigned char ucPicType;
	unsigned char ucRoadNo;
	unsigned char ucVehiclePlate;
	unsigned char ucVehicleSize;
	unsigned char ucVehicleSpeed;
	unsigned char ucVehicleFace;
	unsigned char ucWaterMark;
	unsigned char ucOverlayType;	/* 图片的字幕叠加风格，0：单行叠加，1：多行叠加*/
	unsigned char ucVehicleColor;
	unsigned char aucReserved[2];
}T_PicOsdSetup;

typedef enum
{
	DIR_STRUCT_DEV_DATE,			/* 按设备编号+日期+时间组织目录*/
	DIR_STRUCT_DEV_DIR_LANE_DATE,	/* 按设备编号+方向+车道号+日期+时间组织目录*/
	DIR_STRUCT_ALL
}E_DirStruct;

/* SD卡存储策略配置*/
typedef enum
{
	SD_WRITE_TYPE_ROLL,
	SD_WRITE_TYPE_STOP,
	SD_WRITE_TYPE_ALL
}E_FULL_WRITE_TYPE;

/* 存储配置*/
typedef struct
{
	unsigned char	ucEnable;					/* 本地存储使能*/
	unsigned char	ucDirStuct;					/* 目录结构，E_DirStruct*/
	unsigned char	ucWritePolicy;				/* 磁盘满时的处理策略，E_FULL_WRITE_TYPE*/
	unsigned char	ucBackupPolicyNormal;		/* 卡口图片的备份策略，0：不备份，1：备份*/
	unsigned char	ucBackupPolicyIllegal;		/* 违法图片的备份策略，0：不备份，1：备份*/
	unsigned char	ucBackupPolicyIRecord;		/* 违法录像是否保存0:不备份，1:备份*/
	unsigned char	ucIllegalRecordEn;			/* 违法录像使能标志*/
	unsigned char	ucIllegalRecordTime;		/* 违法录像录制时长*/
	unsigned char	ucIllegalRecordReadyTime; 	/* 预录时长*/

	unsigned char	ucRealTimeRecordEn;			/* 实时录像是否启动*/
	unsigned char	ucRealTimeRecordDuration;	/* 实时录像时长,分钟(1~120)*/
	unsigned char	ucReserved;
}T_StorageSetup;

typedef struct
{
	unsigned char	ucEnable;
	unsigned char	ucMode;			/* 演示模式，0: 流媒体演示, 1:本地文件演示*/
	unsigned char	aucReserved[2];
	char			szUrl[256];
}T_DemoSetup;
 

typedef enum
{
	SUBDIR_TYPE_ROOT,   					/*使用跟目录*/
	SUBDIR_TYPE_DATE,						/*使用日期分目录*/
	SUBDIR_TYPE_DEVNUM,						/*设备编号分目录*/
	SUBDIR_TYPE_DEVNUM_DATE,				/*设备编号+ 日期目录*/
	SUBDIR_TYPE_DEVNUM_DATE_HOUR,			/*设备编号+ 日期+ 小时目录*/
	SUBDIR_TYPE_DEVNUM_ROAD_DATE_HOUR,		/*设备编号+车道+日期+小时目录*/
	SUBDIR_TYPE_DEVNUM_DIR_ROAD_DATE_HOUR,	/*设备编号+ 方向+ 车道+ 日期+小时目录*/
	SUBDIR_TYPE_ALL
}E_SubDirType;

/* FTP配置*/
typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	ucSubDirCreateType;   /* 子目录创建方式E_SubDirType*/
	unsigned short	usServerPort;
	char			szServerName[MAX_SERVER_NAME_LEN];
	char			szUser[MAX_USER_PWD_LEN];
	char			szPwd[MAX_USER_PWD_LEN]; 
	unsigned char	ucTransMode; 		/* passive or not 0:passive 1:active*/
	unsigned char	ucTransFileType; 	/*  whick kind of file we want to transfer. E_FileType*/
	unsigned char	ucKeepBackup; 		/*  whether to keep the file in local after it has been upload.*/
	unsigned char	ucTransPeriod;		/*  unit is minute*/
	unsigned char	ucCharacterSet; 	/*E_CharSet*/
	unsigned char	ucReserved;
	char			szFTPRootPath[MAX_FILE_NAME_LEN];
}T_FTPSetup;

/* 设备信息配置*/
typedef struct
{
	char			szDistrictNumber[16];	/* 地区编号*/
	char			szProjectName[64];		/* 项目名称*/
	char			szDevNumber[16];		/* 设备号，用户定义；*/
	char			szRoadName[64];			/* 路段名称*/
	char			szRoadNumber[16];		/* 路段编号*/
	unsigned char	ucDirection;			/* 方向*/
	unsigned char	aucReserved[3];		  	/* 保留字段*/
	char			szLicenseNum[64];  		/* license号*/
	char			szRecordNum[32];        /*备案号*/
}T_DevSetup;

typedef enum
{
	SIMPLE_LIGHT,
	LANE_LIGHT,
	COMPLEX_LIGHT
}E_SignalLightType;

typedef enum
{
	NONE_MODE,
	ALL_RED_MODE,
	LEFT_WAIT_MODE
}E_SignalLightMode;

/*信号灯检测源*/
typedef enum
{
	CHECK_MODE_RS485 = 0,
	CHECK_MODE_VIDEO,
}E_SignalLightCheckMode;

/*信号灯参数配置*/
typedef struct 
{
	unsigned char ucCheckSrc;   /*信号灯检测源 E_SignalLightCheckMode*/
	unsigned char ucRedShine;	/*是否红灯闪烁*/
	unsigned char ucMode;		/*0-无/1-全红模式/2-左转待停*/
	unsigned char ucBanRt;		/*红灯是否禁止右转*/

	unsigned char ucType;		/*信号灯类型E_SignalLightType*/
	unsigned char ucLeftDelay;	/*左转延时*/
	unsigned char ucRightDelay;	/*右转延时*/
	unsigned char ucGoStraightDelay;/*直行延时*/
	T_EnableTimeBucket atInvalidTimeBucket[MAX_TIMEBUCKET];/*失效时段*/	
}T_SignalLightSetup;

typedef struct
{
	UINT16	uwIndex;//小灯序号
	UINT16	uwX;//
	UINT16	uwY;//
	UINT16	uwReserved;
	UINT8	ucRed;//红
	UINT8	ucYellow;//黄
	UINT8	ucGreen;//绿
	UINT8	ucCountdown;//倒计时
	UINT8	ucLeft;//左
	UINT8	ucStraight;//直
	UINT8	ucRight;//右
	UINT8	ucSwing;//掉头
} T_LightParm;

typedef struct 
{
	UINT8	ucRadius;//半径				  单位：像素；		
	UINT8	ucTrack;//是否跟踪			  1是/0否
	UINT8	ucBanRight;//是否禁右         1是/0否
	UINT8	ucBanYellow;//是否抓拍闯黄灯  1是/0否
	UINT16	uwLightNum;//小灯个数
	UINT16	uwReserved;
	T_LightParm	tLightParm[9];//小灯信息
}T_SigLightParm;

typedef struct
{
	unsigned short	usYear;
	unsigned char	ucMonth;
	unsigned char	ucDay;
	unsigned char	ucHour;
	unsigned char	ucMinute;
	unsigned char	ucSecond;
	unsigned char	ucDayFmt;
	unsigned char	ucTimeFmt;
	unsigned char	ucTimeZone;
	unsigned char	aucReserved[2];
}T_DCTimeSetup;

/* SNTP配置*/
typedef struct
{
	unsigned char	ucEnabled;
	unsigned char	ucReserved[3];
	 char	szSNTPServer[64];
	unsigned short	usPort;
}T_SNTPSetup;

typedef struct
{
	unsigned char ucEnable;
	unsigned char ucOffset;
	unsigned char szReserved[2];
}T_ACSyncSetup;

/*交流电同步*/
typedef struct
{
	unsigned char ucEnable;
	unsigned char ucOffset;
	unsigned char szReserved[2];
}T_DCAcSyncSetup;

typedef struct
{
	unsigned char	ucIndex;	/* 字幕序号（0-4）；第0路为时间字幕，只需设置是否叠加； */                      
	unsigned char	ucEnabled;		/* 使能标志；*/                                                                 
	unsigned char	ucFontSize;		/* 字体大小；*/                                             
	unsigned char	ucWeekEnabled;	/*星期显示*/                                             
	unsigned int	uiForeColor;		/* 前景色，格式为0x00RRGGBB，*/                             
	unsigned int	uiBackColor;		/* 背景色，格式为0xXXRRGGBB，如果XX不为0，表示不需要背景色；*/
	unsigned short	usPosX;			/* X坐标  */                                                                    
	unsigned short	usPosY;			/* Y坐标  */                                                                    
	unsigned short	ausContent[33];   /* 字幕内容，UNICODE16格式，以0结尾；    */
	unsigned char   aucReserved[2];
}T_Subtitle;

typedef struct
{ 
	unsigned char	ucGroupId;                   /* 组ID */
	unsigned char	ucShutterMode;               /* 快门模式 */
	unsigned char	ucGainMode;                  /* 增益模式 */
	unsigned char	ucReserved;					 /*保留字段*/
	unsigned int	uiShutterValue;              /* 快门值 */
	unsigned short	usGainValue;                 /* 增益 */
	unsigned short	usBrightnessTH;              /* 亮度阀值*/
}T_DCSnapParaSetup;

typedef struct 
{
	unsigned char	ucLaneNo;			/*车道编号*/
	unsigned char	ucReserved[3];
	unsigned int	uiDate;
	unsigned int	uiTime;
	unsigned int	uiVehicleNum;		/*车流量*/
	unsigned int	uiAveSpeed;			/*平均车速*/
	unsigned int	uiTimeOccupyRate;	/*时间占有率*/
}T_DCTraStatReport;


typedef struct
{ 
	unsigned char ucShutterMode;                /* 快门模式 */
	unsigned char ucGainMode;                   /* 增益模式 */
	unsigned char szReserved[2]; 				/*保留字段*/
	unsigned int uiShutterValue;				/* 快门值 */
	unsigned short usGainValue;                 /* 增益 */
	unsigned short usBrightnessTH;              /* 亮度的标准参考值 */
}T_VideoParaSetup;

typedef struct
{
	unsigned char	ucMode;			/* 编码模式，目前仅支持H264；*/
	unsigned char	ucFmt;			/* 编码格式，分辨率相关*/
	unsigned char	ucFps;			/* 帧频1<<25*/
	unsigned char	ucRateControl; 	/* 码率控制，0->VBR(可变码率)，1->CBR(固定码率)*/
	unsigned int	uiRate;			/* 码率，384000～16000000 bps*/
	unsigned char	ucIFPeriod;		/* I帧间隔，1～5 秒；*/
	unsigned char	ucEnabled;		/*编码是否启动，辅视频生效*/
	unsigned char   ucIncSnapFrame; /*包含抓拍帧使能*/      
	unsigned char	ucReserved;
}T_VideoCodeSetup;

/*动态视频编码结构体*/
typedef struct
{
	unsigned char   ucEnabled;
	unsigned char   ucReserved;
	unsigned short  usTime;
	unsigned int	uiRate;
}T_DynamicCode;

typedef struct
{
	unsigned short  usHigh;
    unsigned short  usWidth;
	unsigned int	uiVideoFormat;//视频支持的格式，用位值来表示，不同位的值表示如下：0->无效，1->CIF，2->4CIF，3->SXGA，4->720P，5->UXGA，6->1080P，7～30保留，31->全分辨率，根据最大宽度和高度的值得出；
	float   ucMaxFs;
}T_DCSpec;

typedef enum
{
	FILE_DOWNLOAD_TFTP = 0,
	FILE_DOWNLOAD_FTP,
	FILE_DOWNLOAD_ALL,
}E_FileDownloadType;


/*上报版本号*/
typedef struct
{
	char		szKernelVersion[VERSION_NAME_LEN];
	char		szFileSystemVersion[VERSION_NAME_LEN];
	char		szAppVersion[VERSION_NAME_LEN];
	char		szWebVersion[VERSION_NAME_LEN];
	char		szHardwareVersion[VERSION_NAME_LEN];
	char		szDevType[64];		/* 设备类型描述，出厂时设定；*/
	char		szSerialNum[64];    	/*产品序列号*/
	unsigned int	uiDateOfExpiry;		/*产品有效期*/
	char		szDSPVersion[VERSION_NAME_LEN];
}T_QueVersionRsp;

/* 系统状态上报*/
typedef struct
{
	unsigned char	ucLoopStatus;		/* 线圈检测器状态，0：正常，其它异常*/
	unsigned char	ucRadarStatus;		/* 雷达检测器状态，0：正常，其它异常*/
	unsigned char	ucVAStatus;			/* 智能分析模块状态，0：正常，其它异常*/
	unsigned char	ucSSDStatus;		/* 硬盘状态，0：正常，其它异常*/
	unsigned int	uiSSDSize;			/* 硬盘容量，单位GB*/
	unsigned int	uiSSDReserved;		/* 剩余容量，单位GB*/
}T_SysState;

typedef enum
{
	LOOP_DETECT = 0,	/*线圈检测*/
	RADAR_DETECT,		/*雷达检测*/
	VIDEO_DETECT,		/*视频检测*/
	LOOP_VIDEO_DETECT,	/*线圈+视频检测*/
	RADAR_VIDEO_DETECT, /*雷达+视频检测*/
	ALL_DETECT_METHOD
}E_DetectMethod;

/* 检测模式设置*/
typedef struct
{
	unsigned char ucDetectMode;	   /*检测模式E_DetectMethod*/
	unsigned char szReserved[3];   /*保留字段*/
}T_DetectModeSetup;

/* 线圈检测输出信息*/
typedef enum
{
	LEAVE_LOOP, /*出线圈*/
	ENTER_LOOP, /*进线圈*/
}E_LoopInfo;

/*线圈参数配置*/
typedef struct
{
	UINT8	ucLaneIndex;     /* 该组线圈对应的车道索引号 */
	UINT8  ucLoopLaneIndex; /*车检器上对应的车道索引，从0开始编号*/
	UINT8   ucMode;
	UINT8   szReserved;
	//UINT8  szReserved[2];    /*保留字段*/
	UINT16	usLoopWidth;     /*线圈宽度*/
	UINT16	usLoopInterval;  /*线圈间隔*/
}T_LoopParamSetup;


/*雷达参数配置*/
typedef struct
{
	unsigned char	ucLaneIndex;		/*该组线圈对应的车道索引号*/
    unsigned char  ucRadarLaneIndex;	/*雷达车道索引,从0开始编号*/
	unsigned char  szReserved[2];       /*保留字段*/
	unsigned short	usPoleHeight;    /* 立杆高度 */
	unsigned short	usPoleToCenter;  /* 立杆到雷达照射中心区距离 */
}T_RadarParamSetup;

/* 点*/
typedef struct
{
	short sX;
	short sY;
}T_Point;

/* 线*/
typedef struct
{
	T_Point tStartPoint;
	T_Point tEndPoint;
}T_Line;

/* 区域*/
typedef struct
{
	T_Point tLefTop;
	T_Point tRightBottom;
}T_Rect;

typedef struct
{
	unsigned char ucDashedLine;
	unsigned char ucReserved;
	T_Line tLine;
}T_DivisionLine;

/*视频检测区域参数配置*/
typedef struct 
{
	unsigned char		ucLanes;		/*车道数  */
	unsigned char		ucSnapAutoBike; /*摩托车抓拍1:抓拍0:不抓拍*/
	unsigned short		usBanTime;		/*违停时长阀值，单位:秒*/
	unsigned char		ucVirLoopNum;	/*虚拟线圈，抓拍摩托车使用*/
	unsigned char		aucReserved[3];

	T_Point				atPlateRegion[4];		/*车牌识别区域*/
	T_Line				aStopLine;              /*卡口:触发线 电子警察:停止线*/
	T_Point				atSpeedRegion[4];		/*测速区域  */
	T_Line				atOccupCheckLine[2];	/*占有率检测线   */
	T_DivisionLine		atDivisionLine[ONE_DIRECTION_LANES+1];/*车道分割线*/
	T_Line				tPrefixLine;		/*电警前置线*/
	T_Line				tLeftBorderLine;	/*电警左边界线*/
	T_Line				tRightBorderLine;	/*电警右边界线*/
	T_Point				atVirLoop[ONE_DIRECTION_LANES][4]; /*虚拟线圈*/
	
	/*非法停车区*/
	T_Point		atBanRegion[4];   /*非法禁停区*/
	
	unsigned short		usCameraHeight;        /*相机安装高度*/
	unsigned short		usRectLength;          /*路面矩形长度(厘米)*/
	unsigned short		usRectWidth;           /*路面矩形宽度(厘米)*/
	unsigned short		usTotalDis;            /*矩形坐上角到摄像机垂直投影的距离(厘米)*/
}T_VideoDetectParamSetup;

typedef struct 
{
	UINT8		ucLanes;		/*车道数  */
	UINT8		ucSnapAutoBike; /*摩托车抓拍1:抓拍0:不抓拍*/
	UINT16		usBanTime;   /*违停时长阀值，单位:秒*/
	UINT8		ucVirLoopNum; /*虚拟线圈，抓拍摩托车使用*/
	/*违法灵敏度配置*/
	UINT8 		ucRunRedLight;   /*闯红灯E_IllegalSensitive*/
	UINT8             ucNobyLane;        /*不按车道*/
	UINT8             ucCrossLine;        /*压线*/
	T_Point		atPlateRegion[4];      /*车牌识别区域*/
	T_Line		aStopLine;              /*卡口:触发线 电子警察:停止线*/
	T_Point		atSpeedRegion[4];/*测速区域  */
	T_Line		atOccupCheckLine[2];/*占有率检测线   */
	T_DivisionLine	atDivisionLine[ONE_DIRECTION_LANES+1];/*车道分割线*/
	T_Line		tPrefixLine;  /*电警前置线*/
	T_Line		tLeftBorderLine;  /*电警左边界线*/
	T_Line		tRightBorderLine;  /*电警右边界线*/
	T_Point		atVirLoop[ONE_DIRECTION_LANES][4]; /*虚拟线圈*/

	/*非法停车区*/
	T_Point		atBanRegion[4];   /*非法禁停区*/

	UINT16		usCameraHeight;        /* 相机安装高度 */
	UINT16		usRectLength;          /*路面矩形长度(厘米)*/
	UINT16		usRectWidth;           /*路面矩形宽度(厘米)*/
	UINT16		usTotalDis;              /*矩形坐上角到摄像机垂直投影的距离(厘米)*/
	UINT8 	       ucReverseRun;        /*逆行*/
	UINT8   	       ucIllegalStop;         /*违停*/
	UINT8		aucReserved[2];
}T_DJVideoDetectParamSetup;

typedef  struct
{
	unsigned  char		ucIndex;
	unsigned  char		ucFunction;
	unsigned  char		ucBaudRate;
	unsigned  char		ucDataBits;
	unsigned  char		ucStopBits;
	unsigned  char		ucCheckOut;
	unsigned  char		ucReserved[2];
}T_ParkRS485Setup;

/*文件类型定义*/
typedef enum
{
	FILE_TYPE_LOG = 0,
	FILE_TYPE_RECORD,
	FILE_TYPE_IMAGE,
	FILE_TYPE_ALL,
}E_FILE_TYPE;

/* 文件数目查询结构*/
typedef struct 
{
	unsigned  char  ucType;   //E_FILE_TYPE
	unsigned  char  aucReserved[3];
	unsigned  int	uiStartDate; 		/*0～7表示日，8～15表示月，16～31位表示年*/
	unsigned  int	uiStartTime; 		/*0～7位表示秒，8～15位表示分，16～23位表示时*/
	unsigned  int	uiEndDate;		
	unsigned  int	uiEndTime;		
}T_QueryFileBase;

/* 文件信息查询结构*/
typedef struct
{
	T_QueryFileBase tBase;
	unsigned  int uiItem;
}T_QueryFileItem;

/* 文件数目上报*/
typedef struct
{
	T_QueryFileBase tQueFileInfo;
	unsigned  int uiCount;
}T_FileCountRsp;

 /* 文件信息上报*/
typedef struct
{
	T_QueryFileItem tQueryItem;
	unsigned  char   szFileName[256];
	unsigned  int uiCreateDate;
	unsigned  int uiCreateTime;
	unsigned  int uiDuration;
}T_FileInfoRsp;

typedef struct
{
	unsigned  char	ucState; // 1:短按,2:长按
	unsigned  char	aucReserved[3];
}T_ResetKeyPressState;//相机复位键按下的状态，短按或长按

typedef struct
{
	unsigned  char 	ucEnable;    /*是否使能*/
	unsigned  char 	ucLevel;      /*LED亮度等级1~7*/ 
	unsigned  char  	aucReserved[2];
	unsigned  short  usStartTime;  /*开始时间单位:分钟*/
	unsigned  short  usEndTime;   /*结束时间单位:分钟*/
}T_ParkLedManualItem;

typedef struct
{
	T_ParkLedManualItem atParkLedMan[3];
}T_ParkLedManual; /*LED强制开控制*/

typedef struct 
{ 
	unsigned  char	ucEnable;
	unsigned  char	aucReserved[3]; 
}T_3GSetup;

typedef struct
{
	unsigned  char  ucEnable;
	unsigned  char	aucReserved[3]; 
	char			ssid[64]; 
	char			pwd[64]; 
	unsigned  int	uiIPAddress; 
	unsigned  int	uiMaskAddress; 
	unsigned  int	uiGatewayAddress; 
}T_WirelessSetup; 

/**********************************************************************
* 函数名称：Net_RebootCamera
* 功能描述：重启相机，断开与相机之间的连接
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RebootCamera(DCHANDLE tHandle);


/**********************************************************************
* 函数名称：Net_TimeSetup
* 功能描述：设置相机的时间
* 输入参数：tHandle 相机句柄
*			ptTimeSetup 时间配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_TimeSetup(DCHANDLE tHandle,  T_DCTimeSetup *ptTimeSetup);

/**********************************************************************
* 函数名称：Net_QueryTimeSetup
* 功能描述：查询相机时间
* 输入参数：tHandle 相机句柄
* 输出参数：ptTimeSetup 时间配置结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryTimeSetup(DCHANDLE tHandle,  T_DCTimeSetup *ptTimeSetup);

/**********************************************************************
* 函数名称：Net_SntpSetup
* 功能描述：设置指定相机的sntp信息
* 输入参数：tHandle 相机句柄
*           ptSntpSetup sntp配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SntpSetup(DCHANDLE tHandle,  T_SNTPSetup *ptSntpSetup);

/**********************************************************************
* 函数名称：Net_QuerySntpSetup
* 功能描述：查询相机的sntp信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptSntpSetup sntp配置结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySntpSetup(DCHANDLE tHandle,  T_SNTPSetup *ptSntpSetup);

/**********************************************************************
* 函数名称：Net_NETSetup
* 功能描述：设置相机的网络信息
* 输入参数：tHandle 相机句柄
*			ptNetSetup 设备信息配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_NETSetup(DCHANDLE tHandle,  T_NetSetup *ptNetSetup);

/**********************************************************************
* 函数名称：Net_QueryNETSetup
* 功能描述：查询相机的网络信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptNetSetup 设备信息结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryNETSetup(DCHANDLE tHandle,  T_NetSetup *ptNetSetup);



/**********************************************************************
* 函数名称：Net_QueryMACSetup
* 功能描述：查询相机MAC地址
* 输入参数：tHandle 相机句柄
* 输出参数：ptMacSetup 设备信息配置结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryMACSetup(DCHANDLE tHandle,  T_MACSetup *ptMacSetup);

/**********************************************************************
* 函数名称：Net_AcSyncSetup
* 功能描述：设置指定相机的交流同步信息
* 输入参数：tHandle 相机句柄
*           ptAcSyncSetup 交流电同步配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AcSyncSetup(DCHANDLE tHandle,  T_DCAcSyncSetup *ptAcSyncSetup);

/**********************************************************************
* 函数名称：Net_QueryAcSyncSetup
* 功能描述：查询相机的交流同步信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptAcSyncSetup 交流电同步配置指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAcSyncSetup(DCHANDLE tHandle, T_DCAcSyncSetup *ptAcSyncSetup);

/**********************************************************************
* 函数名称：Net_ImageQualitySetup
* 功能描述：设置指定相机的图像质量信息
* 输入参数：tHandle 相机句柄
*           ptImageCodec 图像质量，1～100
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageQualitySetup(DCHANDLE tHandle,T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_QueryImageQualitySetup
* 功能描述：查询相机的图像质量信息
* 输入参数：tHandle 相机句柄   
* 输出参数：ptImageCodec  图像质量结果
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageQualitySetup(DCHANDLE tHandle, T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_VideoSubtitleSetup
* 功能描述：设置指定相机的视频字幕信息
* 输入参数：tHandle 相机句柄
*           ptSubtitle 视频字幕信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoSubtitleSetup(DCHANDLE tHandle, T_Subtitle *ptSubtitle);

/**********************************************************************
* 函数名称：Net_QueryVideoSubtitleSetup
* 功能描述：查询相机的视频字幕信息
* 输入参数：tHandle 相机句柄
*			ptSubtitle->ucIndex 视频字幕索引编号
* 输出参数：ptSubtitle 视频字幕信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoSubtitleSetup(DCHANDLE tHandle, T_Subtitle *ptSubtitle);

/**********************************************************************
* 函数名称：Net_SnapParaSetup
* 功能描述：设置指定相机的抓拍参数
* 输入参数：tHandle 相机句柄
*           ptSnapParaSetup 抓拍参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SnapParaSetup(DCHANDLE tHandle, T_DCSnapParaSetup *ptSnapParaSetup);

/**********************************************************************
* 函数名称：Net_QuerySnapParaSetup
* 功能描述：查询相机的抓拍参数
* 输入参数：tHandle 相机句柄
*           ptSnapParaSetup->ucGroupId 指定组ID
* 输出参数：ptSnapParaSetup 抓拍参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySnapParaSetup(DCHANDLE tHandle,T_DCSnapParaSetup *ptSnapParaSetup);

/**********************************************************************
* 函数名称：Net_VideoParaSetup
* 功能描述：设置指定相机的视频参数
* 输入参数：tHandle 相机句柄
*           ptVideoParaSetup视频参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoParaSetup
* 功能描述：查询指定相机的抓拍参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoParaSetup 视频参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoParaSetup(DCHANDLE tHandle, T_VideoParaSetup *ptVideoParaSetup);


/**********************************************************************
* 函数名称：Net_ViceVideoCodeSetup
* 功能描述：设置相机辅视频编码参数
* 输入参数：tHandle 相机句柄
*           ptVideoCodeSetup 视频编码指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ViceVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_QueryViceVideoCodeSetup
* 功能描述：查询相机辅视频编码参数
* 输入参数： tHandle 相机句柄
* 输出参数： ptVideoCodeSetup 视频编码指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryViceVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_DynamicCodeSetup
* 功能描述：设置指定相机的动态视频编码
* 输入参数：tHandle 相机句柄
*           ptDynamicCode 动态视频编码指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DynamicCodeSetup(DCHANDLE tHandle, T_DynamicCode *ptDynamicCode);

/**********************************************************************
* 函数名称：Net_QueryDynamicCodeSetup
* 功能描述：查询指定相机的动态视频编码
* 输入参数： tHandle 相机句柄
* 输出参数： ptDynamicCode 动态视频编码指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDynamicCodeSetup(DCHANDLE tHandle, T_DynamicCode *ptDynamicCode);

/**********************************************************************
* 函数名称：Net_QueryCameraSpec
* 功能描述：查询相机规格
* 输入参数：tHandle 相机句柄
* 输出参数：ptSpec 相机规格配置指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryCameraSpec(DCHANDLE tHandle, T_DCSpec  *ptSpec);

/**********************************************************************
* 函数名称：Net_DevInfoSetup
* 功能描述：设置相机设备信息
* 输入参数：tHandle 相机句柄
*           ptDevSetup 相机设备信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DevInfoSetup(DCHANDLE tHandle,  T_DevSetup *ptDevSetup);

/**********************************************************************
* 函数名称：Net_QueryDevSetup
* 功能描述：查询相机设备信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptDevSetup 相机设备信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDevSetup(DCHANDLE tHandle, T_DevSetup *ptDevSetup);

/**********************************************************************
* 函数名称：Net_FTPSetup
* 功能描述：设置相机FTP信息
* 输入参数：tHandle 相机句柄
*           ptFtpSetup 相机FTP信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FTPSetup(DCHANDLE tHandle,  T_FTPSetup *ptFtpSetup);

/**********************************************************************
* 函数名称：Net_QueryFTPSetup
* 功能描述：查询相机FTP信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptFtpSetup 相机FTP信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API  E_ReturnCode _stdcall Net_QueryFTPSetup(DCHANDLE tHandle,T_FTPSetup *ptFtpSetup);

/**********************************************************************
* 函数名称：Net_AssistantIpncSetup
* 功能描述：设置辅助相机配置信息
* 输入参数：tHandle 相机句柄
*           ptAssistantIpnc 辅助相机配置信息指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_AssistantIpncSetup(DCHANDLE tHandle,  T_AssistantIpnc *ptAssistantIpnc);

/**********************************************************************
* 函数名称：Net_QueryAssistantIpncSetup
* 功能描述：查询辅助相机配置信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptAssistantIpnc 辅助相机配置信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryAssistantIpncSetup(DCHANDLE tHandle,  T_AssistantIpnc *ptAssistantIpnc);

/**********************************************************************
* 函数名称：Net_MessegerSetup
* 功能描述：设置后台通讯配置参数
* 输入参数：tHandle 相机句柄
*           ptMessenger 后台通信配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_MessegerSetup(DCHANDLE tHandle,  T_Messenger *ptMessenger);

/**********************************************************************
* 函数名称：Net_QueryMessegerSetup
* 功能描述：查询后台通讯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptMessenger 后台通信配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryMessegerSetup(DCHANDLE tHandle,  T_Messenger *ptMessenger);

/**********************************************************************
* 函数名称：Net_SigControlPortSetup
* 功能描述：设置信号控制通信端口参数
* 输入参数：tHandle 相机句柄
*           ptSigControlPort 信号机控制端口参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SigControlPortSetup(DCHANDLE tHandle,  T_SigControlPort *ptSigControlPort);

/**********************************************************************
* 函数名称：Net_QuerySigControlPortSetup
* 功能描述：查询信号控制通信端口参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSigControlPort 信号机控制端口参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySigControlPortSetup(DCHANDLE tHandle,  T_SigControlPort *ptSigControlPort);

/**********************************************************************
* 函数名称：Net_CaptureSetup
* 功能描述：设置事件抓拍参数
* 输入参数：tHandle 相机句柄
*           ptEventCapturePara 抓拍位置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_CaptureSetup(DCHANDLE tHandle,  T_EventCapturePara *ptEventCapturePara);

/**********************************************************************
* 函数名称：Net_QueryCaptureSetup
* 功能描述：查询事件抓拍参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptEventCapturePara 抓拍位置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryCaptureSetup(DCHANDLE tHandle,T_EventCapturePara *ptEventCapturePara);

/**********************************************************************
* 函数名称：Net_RoadLaneBasicSetup
* 功能描述：设置基本车道配置参数
* 输入参数：tHandle 相机句柄
*           ptRoadLaneBasicSetup 车道配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RoadLaneBasicSetup(DCHANDLE tHandle,  T_RoadLaneBasicSetup *ptRoadLaneBasicSetup);

/**********************************************************************
* 函数名称：Net_QueryRoadLaneBasicSetup
* 功能描述：查询基本车道配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRoadLaneBasicSetup 车道配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRoadLaneBasicSetup(DCHANDLE tHandle,T_RoadLaneBasicSetup *ptRoadLaneBasicSetup);

/**********************************************************************
* 函数名称：Net_RoadLaneExternSetup
* 功能描述：设置扩展车道配置参数
* 输入参数：tHandle 相机句柄
*           ptRoadLaneExtendSetup 扩展车道配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RoadLaneExternSetup(DCHANDLE tHandle,  T_RoadLaneExtendSetup *ptRoadLaneExtendSetup);

/**********************************************************************
* 函数名称：Net_QueryRoadLaneExternSetup
* 功能描述：查询扩展车道配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRoadLaneExtendSetup 扩展车道配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRoadLaneExternSetup(DCHANDLE tHandle, T_RoadLaneExtendSetup *ptRoadLaneExtendSetup);

/**********************************************************************
* 函数名称：Net_VideoCodeSetup
* 功能描述：设置视频编码参数
* 输入参数：tHandle 相机句柄
*           ptVideoCodec 视频编码参数指针
* 输出参数：无 
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoCodeSetup
* 功能描述：查询视频编码参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoCodec 视频编码参数指针 
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoCodeSetup(DCHANDLE tHandle, T_VideoCodeSetup *ptVideoCodeSetup);

/**********************************************************************
* 函数名称：Net_QueryRS485Setup
* 功能描述：设置RS485配置参数
* 输入参数：tHandle 相机句柄
*           ptRs485Setup RS485配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RS485Setup(DCHANDLE tHandle,  T_RS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_QueryRS485Setup
* 功能描述：查询RS485配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRs485Setup RS485配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRS485Setup(DCHANDLE tHandle,  T_RS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_ParkRS485Setup
* 功能描述：设置停车场RS485配置参数
* 输入参数：tHandle 相机句柄
*           ptRs485Setup 停车场RS485配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkRS485Setup(DCHANDLE tHandle,  T_ParkRS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_QueryParkRS485Setup
* 功能描述：查询停车场RS485配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRs485Setup 停车场RS485配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryParkRS485Setup(DCHANDLE tHandle,  T_ParkRS485Setup *ptRs485Setup);

/**********************************************************************
* 函数名称：Net_VehicleVAFunSetup
* 功能描述：设置车牌识别配置参数
* 输入参数：tHandle 相机句柄
*           ptVehicleVAFunSetup	车牌识别配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VehicleVAFunSetup(DCHANDLE tHandle,  T_VehicleVAFunSetup *ptVehicleVAFunSetup);

/**********************************************************************
* 函数名称：Net_QueryVehicleVAFunSetup
* 功能描述：查询车牌识别配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVehicleVAFunSetup	车牌识别配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVehicleVAFunSetup(DCHANDLE tHandle,  T_VehicleVAFunSetup *ptVehicleVAFunSetup);

/**********************************************************************
* 函数名称：Net_PicOsdSetup
* 功能描述：设置车图片字幕配置参数
* 输入参数：tHandle 相机句柄
*           ptPicOsdSetup 车图片字幕配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_PicOsdSetup(DCHANDLE tHandle,  T_PicOsdSetup *ptPicOsdSetup);

/**********************************************************************
* 函数名称：Net_QueryPicOsdSetup
* 功能描述：查询车图片字幕配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptPicOsdSetup 车图片字幕配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryPicOsdSetup(DCHANDLE tHandle,  T_PicOsdSetup *ptPicOsdSetup);

/**********************************************************************
* 函数名称：Net_StorageSetup
* 功能描述：设置储存信息配置参数
* 输入参数：tHandle 相机句柄
*           ptStorageSetup 储存信息配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode  _stdcall Net_StorageSetup(DCHANDLE tHandle,  T_StorageSetup *ptStorageSetup);

/**********************************************************************
* 函数名称：Net_QueryStorageSetup
* 功能描述：查询储存信息配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptStorageSetup 储存信息配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryStorageSetup(DCHANDLE tHandle,  T_StorageSetup *ptStorageSetup);
/**********************************************************************
* 函数名称：Net_DemoSetup
* 功能描述：演示模式配置参数
* 输入参数：tHandle 相机句柄
*           ptDemoSetup	   演示模式配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DemoSetup(DCHANDLE tHandle,  T_DemoSetup *ptDemoSetup);

/**********************************************************************
* 函数名称：Net_QueryDemoSetup
* 功能描述：查询演示模式配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSetup  演示模式配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDemoSetup(DCHANDLE tHandle,  T_DemoSetup *ptSetup);

/**********************************************************************
* 函数名称：Net_ImageEvSetup
* 功能描述：设置顺光逆光配置参数
* 输入参数：tHandle 相机句柄
*           ptImageEv 宽动态配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageEvSetup(DCHANDLE tHandle,  T_ImageEv *ptImageEv);

/**********************************************************************
* 函数名称：Net_QueryImageEvSetup
* 功能描述：查询顺光逆光配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptImageEv 宽动态配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageEvSetup(DCHANDLE tHandle,  T_ImageEv *ptImageEv);

/**********************************************************************
* 函数名称：Net_ImageWDRSetup
* 功能描述：设置抓拍位置参数
* 输入参数：tHandle 相机句柄
*           ptImageWDR 抓拍位置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageWDRSetup(DCHANDLE tHandle,  T_ImageWDR *ptImageWDR);

/**********************************************************************
* 函数名称：Net_QueryImageWDRSetup
* 功能描述：查询抓拍位置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptImageWDR 抓拍位置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageWDRSetup(DCHANDLE tHandle,  T_ImageWDR *ptImageWDR);

/**********************************************************************
* 函数名称：Net_ServicePortSetup
* 功能描述：设置RTSP/HTTP服务端口参数
* 输入参数：tHandle 相机句柄
*           ptServicePortSetup	服务端口参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ServicePortSetup(DCHANDLE tHandle,  T_ServicePortSetup *ptServicePortSetup);

/**********************************************************************
* 函数名称：Net_QueryServicePortSetup
* 功能描述：设置RTSP/HTTP服务端口参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptServicePortSetup	服务端口参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode  _stdcall Net_QueryServicePortSetup(DCHANDLE tHandle,  T_ServicePortSetup *ptServicePortSetup);

/**********************************************************************
* 函数名称：Net_ImageCodecSetup
* 功能描述：设置图像编码参数
* 输入参数：tHandle 相机句柄
*           ptImageCodec 图像编码参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImageCodecSetup(DCHANDLE tHandle,  T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_QueryImageCodecSetup
* 功能描述：查询图像编码参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptImageCodec 图像编码参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryImageCodecSetup(DCHANDLE tHandle,  T_ImageCodec *ptImageCodec);

/**********************************************************************
* 函数名称：Net_FlashLightSetup
* 功能描述：设置闪光灯配置参数
* 输入参数：tHandle 相机句柄
*           ptFlashLightSetup 闪光灯配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FlashLightSetup(DCHANDLE tHandle,  T_FlashLightSetup *ptFlashLightSetup);

/**********************************************************************
* 函数名称：Net_QueryFlashLightSetup
* 功能描述：查询闪光灯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptFlashLightSetup 闪光灯配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryFlashLightSetup(DCHANDLE tHandle,  T_FlashLightSetup *ptFlashLightSetup);

/**********************************************************************
* 函数名称：Net_SignalLightSetup
* 功能描述：设置信号灯配置参数
* 输入参数：tHandle 相机句柄
*           ptSignalLightSetup 信号灯配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SignalLightSetup(DCHANDLE tHandle,  T_SignalLightSetup *ptSignalLightSetup);

/**********************************************************************
* 函数名称：Net_QuerySignalLightSetup
* 功能描述：查询信号灯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSignalLightSetup 信号灯配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySignalLightSetup(DCHANDLE tHandle,  T_SignalLightSetup *ptSignalLightSetup);

/**********************************************************************
* 函数名称：Net_SetSigLightParm
* 功能描述：设置信号灯配置
* 输入参数：tHandle 相机句柄
			ptSigLightParm  指向信号灯设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SigLightParmSetup(DCHANDLE tHandle,T_SigLightParm *ptSigLightParm);

/**********************************************************************
* 函数名称：Net_QuerySigLightParm
* 功能描述：查询信号灯配置
* 输入参数：tHandle 相机句柄
			ptSigLightParm  指向信号灯设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QuerySigLightParmSetup(DCHANDLE tHandle,T_SigLightParm *ptSigLightParm);

/**********************************************************************
* 函数名称：Net_LedLightBasicSetup
* 功能描述：设置信号灯配置参数
* 输入参数：tHandle 相机句柄
*           ptLedLightBasicSetup 信号灯配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_LedLightBasicSetup(DCHANDLE tHandle,  T_LedLightBasicSetup *ptLedLightBasicSetup);

/**********************************************************************
* 函数名称：Net_QueryLedLightBasicSetup
* 功能描述：查询信号灯配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptLedLightBasicSetup 信号灯配置参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryLedLightBasicSetup(DCHANDLE tHandle,  T_LedLightBasicSetup *ptLedLightBasicSetup);

/**********************************************************************
* 函数名称：Net_FileUpdate
* 功能描述：系统升级
* 输入参数：tHandle 相机句柄
*			ptUpdateSetup 系统升级参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_FileUpdate(DCHANDLE tHandle,  T_UpdateSetup *ptUpdateSetup);

/**********************************************************************
* 函数名称：Net_DetectModeSetup
* 功能描述：设置相机的检测模式
* 输入参数：tHandle 相机句柄
*			ptDetectModeSetup 相机检测模式参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DetectModeSetup(DCHANDLE tHandle,  T_DetectModeSetup *ptDetectModeSetup);

/**********************************************************************
* 函数名称：Net_QueryDetectModeSetup
* 功能描述：查询相机的检测模式
* 输入参数：tHandle 相机句柄
* 输出参数：ptDetectModeSetup 相机检测模式参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDetectModeSetup(DCHANDLE tHandle,  T_DetectModeSetup *ptDetectModeSetup);

/**********************************************************************
* 函数名称：Net_LoopDetectSetup
* 功能描述：设置线圈检测模式参数
* 输入参数：tHandle 相机句柄
*			ptLoopParamSetup 线圈检测模式参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_LoopDetectSetup(DCHANDLE tHandle,  T_LoopParamSetup *ptLoopParamSetup);

/**********************************************************************
* 函数名称：Net_QueryLoopDetectSetup
* 功能描述：查询线圈检测模式参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptLoopParamSetup 线圈检测模式参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryLoopDetectSetup(DCHANDLE tHandle,  T_LoopParamSetup *ptLoopParamSetup);

/**********************************************************************
* 函数名称：Net_VideoDetectSetup
* 功能描述：设置视频检测区域参数
* 输入参数：tHandle 相机句柄
*			ptVideoDetectParamSetup 视频检测区域参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_VideoDetectSetup(DCHANDLE tHandle,  T_VideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoDetectSetup
* 功能描述：查询视频检测区域参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoDetectParamSetup 视频检测区域参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryVideoDetectSetup(DCHANDLE tHandle,  T_VideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* 函数名称：Net_VideoDetectSetup
* 功能描述：设置视频检测区域参数
* 输入参数：tHandle 相机句柄
*			ptVideoDetectParamSetup 视频检测区域参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_DJVideoDetectSetup(DCHANDLE tHandle,  T_DJVideoDetectParamSetup *ptVideoDetectParamSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoDetectSetup
* 功能描述：查询视频检测区域参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptVideoDetectParamSetup 视频检测区域参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryDJVideoDetectSetup(DCHANDLE tHandle,  T_DJVideoDetectParamSetup *ptVideoDetectParamSetup);


/**********************************************************************
* 函数名称：Net_RadarParamSetup
* 功能描述：设置雷达检测参数
* 输入参数：tHandle 相机句柄
*			ptRadarParamSetup 雷达检测参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RadarParamSetup(DCHANDLE tHandle,  T_RadarParamSetup *ptRadarParamSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoDetectSetup
* 功能描述：查询雷达检测参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptRadarParamSetup 雷达检测参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRadarParamSetup(DCHANDLE tHandle,  T_RadarParamSetup *ptRadarParamSetup);

/**********************************************************************
* 函数名称：Net_SetupRestore
* 功能描述：恢复出厂设置
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SetupRestore(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_StoreConfig
* 功能描述：保存当前设置
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_StoreConfig(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_ReStoreConfig
* 功能描述：恢复相机最后一次设置
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ReStoreConfig(DCHANDLE tHandle);

/**********************************************************************
* 函数名称：Net_GetSysState
* 功能描述：查询系统状态参数
* 输入参数：tHandle 相机句柄
*			ptSysState 系统状态参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_GetSysState(DCHANDLE tHandle, T_SysState *ptSysState);

/**********************************************************************
* 函数名称：Net_ImportConfig
* 功能描述：导入配置
* 输入参数：tHandle 相机句柄
*			ptImportConfigSetup 配置导入参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ImportConfig(DCHANDLE tHandle, T_ImportConfigSetup *ptImportConfigSetup);

/**********************************************************************
* 函数名称：Net_ExportConfig
* 功能描述：导出配置
* 输入参数：tHandle 相机句柄
*			ptExportConfigSetup 配置导出参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ExportConfig(DCHANDLE tHandle, T_ExportConfigSetup *ptExportConfigSetup);

/**********************************************************************
* 函数名称：Net_RebootTimeSetup
* 功能描述：设置定时重启系统参数
* 输入参数：tHandle 相机句柄
*			ptTimeReboot 定时重启系统参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_RebootTimeSetup(DCHANDLE tHandle, T_TimeReboot *ptTimeReboot);

/**********************************************************************
* 函数名称：Net_QueryRebootTimeSetup
* 功能描述：查询定时重启系统参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptTimeReboot 定时重启系统参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryRebootTimeSetup(DCHANDLE tHandle, T_TimeReboot *ptTimeReboot);

/**********************************************************************
* 函数名称：Net_QuerySysVersion
* 功能描述：查询相机系统版本
* 输入参数：tHandle 相机句柄	
* 输出参数：ptQueVersionRsp 系统版本参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySysVersion(DCHANDLE tHandle, T_QueVersionRsp *ptQueVersionRsp);

/**********************************************************************
* 函数名称：Net_SpeedLimitSetup
* 功能描述：设置车道限速参数
* 输入参数：tHandle 相机句柄
*			ptSpeedCorrAndLimitSetup 限速参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_SpeedLimitSetup(DCHANDLE tHandle,  T_SpeedCorrAndLimitSetup *ptSpeedCorrAndLimitSetup);

/**********************************************************************
* 函数名称：Net_QuerySpeedLimitSetup
* 功能描述：查询车道限速参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptSpeedCorrAndLimitSetup 限速参数指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QuerySpeedLimitSetup(DCHANDLE tHandle,  T_SpeedCorrAndLimitSetup *ptSpeedCorrAndLimitSetup);

/**********************************************************************
* 函数名称：Net_PicTransPortSetup
* 功能描述：设置图片传输协议
* 输入参数：tHandle 相机句柄
*           ptTransPort 图片传输协议参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_PicTransPortSetup(DCHANDLE tHandle, T_TransProt *ptTransPort);

/**********************************************************************
* 函数名称：Net_QueryPicTransPortSetup
* 功能描述：查询图片传输协议
* 输入参数：tHandle 相机句柄
* 输出参数：ptTransPort 图片传输协议参数指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryPicTransPortSetup(DCHANDLE tHandle, T_TransProt *ptTransPort);

/**********************************************************************
* 函数名称：Net_MulticastSetup
* 功能描述：设置组播配置参数
* 输入参数：tHandle 相机句柄
*           ptMulticastSetup 组播配置参数指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_MulticastSetup(DCHANDLE tHandle, T_MulticastSetup *ptMulticastSetup);

/**********************************************************************
* 函数名称：Net_QueryMulticastSetup
* 功能描述：查询组播配置参数
* 输入参数：tHandle 相机句柄
* 输出参数：ptMulticastSetup 组播配置参数指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryMulticastSetup(DCHANDLE tHandle, T_MulticastSetup *ptMulticastSetup);

/**********************************************************************
* 函数名称：Net_QueryHardInfo
* 功能描述：查询相机硬盘信息
* 输入参数：tHandle 相机句柄
* 输出参数：ptHardDiskInfo 相机硬盘信息指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryHardInfo(DCHANDLE tHandle, T_HardDiskInfo *ptHardDiskInfo);

/**********************************************************************
* 函数名称：Net_DiskFomat
* 功能描述：格式化SSD
* 输入参数：tHandle 相机句柄
			ptHardDiskNum 分区选择
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_DiskFomat(DCHANDLE tHandle, T_HardDiskNum *ptHardDiskNum);

/**********************************************************************
* 函数名称：Net_QueryLogCount
* 功能描述：查询日志文件数量
* 输入参数：tHandle 相机句柄
			ptLogCount 日志文件数目查询结构指针
* 输出参数：ptLogCountRsp 日志文件数量指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLogCount(DCHANDLE tHandle, T_QueryFileBase *ptLogCount,T_FileCountRsp *ptLogCountRsp);

/**********************************************************************
* 函数名称：Net_QueryLogInfo
* 功能描述：查询日志文件信息
* 输入参数：tHandle 相机句柄
			ptLogInfo 日志文件信息查询结构指针
* 输出参数：ptLogInfoRsp 日志文件信息指针
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryLogInfo(DCHANDLE tHandle, T_QueryFileItem *ptLogInfo,T_FileInfoRsp *ptLogInfoRsp);

/**********************************************************************
* 函数名称：Net_ParkGatePulseSetup
* 功能描述：设置停车场闸机脉冲时长
* 输入参数：tHandle 相机句柄
*			ptGatePulse 相机闸机脉冲时长指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_ParkGatePulseSetup(DCHANDLE tHandle, T_ParkSetup *ptGatePulse);

/**********************************************************************
* 函数名称：Net_QueryParkGatePulse
* 功能描述：查询停车场闸机脉冲时长
* 输入参数：tHandle 相机句柄
* 输出参数：ptGatePulse 相机闸机脉冲时长指针
* 返 回 值：状态码
***********************************************************************/
NET_API E_ReturnCode _stdcall Net_QueryParkGatePulse(DCHANDLE tHandle, T_ParkSetup *ptGatePulse);

/**********************************************************************
* 函数名称：Net_BackMessagerSetup
* 功能描述：设置备用服务器的端口配置
* 输入参数：tHandle 相机句柄
*			ptMessenger 备用服务器端口配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_BackMessagerSetup(DCHANDLE tHandle,T_Messenger *ptMessenger);

/**********************************************************************
* 函数名称：Net_BackMessagerSetup
* 功能描述：设置备用服务器的端口配置
* 输入参数：tHandle 相机句柄
*			ptMessenger 备用服务器端口配置指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryBackMessagerSetup(DCHANDLE tHandle,T_Messenger *ptMessenger);
/**********************************************************************
* 函数名称：Net_SetCustomerNo
* 功能描述：设置当前厂家的编号
* 输入参数：tHandle 相机句柄
			ptCustomerNo  指向厂家编号的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetCustomerNo(DCHANDLE tHandle,T_CustomerNo *ptCustomerNo);

/**********************************************************************
* 函数名称：Net_QueryCustomerNo
* 功能描述：查询当前厂家的编号
* 输入参数：tHandle 相机句柄
			ptCustomerNo  指向厂家编号的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryCustomerNo(DCHANDLE tHandle,T_CustomerNo *ptCustomerNo);

/**********************************************************************
* 函数名称：Net_SetWiperTime
* 功能描述：设置雨刷定时时间
* 输入参数：tHandle 相机句柄
			ptWiperTimeing  指向定时雨刷设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWiperTime(DCHANDLE tHandle,T_WiperTiming *ptWiperTimeing);

/**********************************************************************
* 函数名称：Net_QueryWiperTime
* 功能描述：查询雨刷定时时间
* 输入参数：tHandle 相机句柄
			ptWiperTimeing  指向定时雨刷设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWiperTime(DCHANDLE tHandle,T_WiperTiming *ptWiperTimeing);

/**********************************************************************
* 函数名称：Net_SetVideoAve
* 功能描述：设置能见度配置
* 输入参数：tHandle 相机句柄
			ptAveConfig  指向能见度设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetVideoAve(DCHANDLE tHandle,T_Ave_Config *ptAveConfig);

/**********************************************************************
* 函数名称：Net_QueryVideoAve
* 功能描述：查询能见度配置
* 输入参数：tHandle 相机句柄
			ptAveConfig  指向能见度设置的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryVideoAve(DCHANDLE tHandle,T_Ave_Config *ptAveConfig);

/**********************************************************************
* 函数名称：Net_SetParkLedManual
* 功能描述：设置LED强制开控制参数
* 输入参数：tHandle 相机句柄
			ptParkLedManual  指向LED强制开控制参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetParkLedManual(DCHANDLE tHandle,T_ParkLedManual *ptParkLedManual);

/**********************************************************************
* 函数名称：Net_QueryParkLedManual
* 功能描述：查询LED强制开控制参数
* 输入参数：tHandle 相机句柄
			ptParkLedManual  指向LED强制开控制参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkLedManual(DCHANDLE tHandle,T_ParkLedManual *ptParkLedManual);


/**********************************************************************
* 函数名称：Net_SetWirelessSetup
* 功能描述：设置热点配置参数
* 输入参数：tHandle 相机句柄
			ptWirelessSetup  指向热点配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_SetWirelessSetup(DCHANDLE tHandle,T_WirelessSetup *ptWirelessSetup);

/**********************************************************************
* 函数名称：Net_QueryWirelessSetup
* 功能描述：查询热点配置参数
* 输入参数：tHandle 相机句柄
			ptWirelessSetup  指向热点配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryWirelessSetup(DCHANDLE tHandle,T_WirelessSetup *ptWirelessSetup);

/**********************************************************************
* 函数名称：Net_Set3GSetup
* 功能描述：设置3G配置参数
* 输入参数：tHandle 相机句柄
			pt3GSetup  指向3G配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_Set3GSetup(DCHANDLE tHandle,T_3GSetup *pt3GSetup);

/**********************************************************************
* 函数名称：Net_Query3GSetup
* 功能描述：查询3G配置参数
* 输入参数：tHandle 相机句柄
			pt3GSetup  指向3G配置参数的指针
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_Query3GSetup(DCHANDLE tHandle,T_3GSetup *pt3GSetup);

/**********************************************************************
* 函数名称：Net_QueryVideoAve
* 功能描述：主动查询当前相机与岗亭连接状态，消息通过NET_ParkStateCallBack回调上报
* 输入参数：tHandle 相机句柄
* 输出参数：无
* 返 回 值：状态码
***********************************************************************/ 
NET_API E_ReturnCode _stdcall Net_QueryParkState(DCHANDLE tHandle);

#ifdef __cplusplus
}
#endif
#endif

