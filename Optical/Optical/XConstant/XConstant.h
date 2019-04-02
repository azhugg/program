#pragma once


extern const CString COMPANYNAME;
extern const CString APP_NAME;
extern const CString APP_VERSION;
extern const CString APP_REGISTRYKEY;
extern const CString APP_FONT;
extern const int FONT_SIZE;
extern const CString APP_ININAME;


extern const int MAIN_TOPHEIGHT; //����ͼƬ�߶�
extern const int MAIN_STATUSBARHEIGHT; //״̬���߶�
extern const int TITLEBAR_HEIGHT; //�������߶�

extern const int DLG_MINWIDTH; //�����Ի�����
extern const int DLG_MINHIGHT; //�����Ի���߶�

extern const int DIS_WIDTH; //�ײ�ͼ����
extern const int DIS_HIGHT; //�ײ�ͼ����




//��ԴID
extern const UINT ID_BEGIN;
extern const UINT ID_STATUSBAR;
extern const UINT ID_BTN_CLOSE;
extern const UINT ID_BTN_SET;
extern const UINT ID_BTN_MIN;
extern const UINT ID_LANGUAGE_ZH_CN;
extern const UINT ID_LANGUAGE_ZH_TW;
extern const UINT ID_LANGUAGE_EN;
extern const UINT ID_ABOUT;
extern const UINT ID_BTN_MESSAGEBOXDLG_1;
extern const UINT ID_BTN_MESSAGEBOXDLG_2;
extern const UINT ID_BTN_MESSAGEBOXDLG_3;
extern const UINT ID_STATIC_MESSAGEBOXDLG_TEXT;
extern const UINT ID_TOOLBAR;
extern const UINT ID_SETNET;




//��ϢID
extern const UINT MSG_BTN_LCLICK;
extern const UINT MSG_UDP;
extern const UINT MSG_TOOBAR_ITEMLCLICK;


//��ʱ��
#define TIMERID_WELCOMETEXT				1 //���½��滶ӭ����
#define TIMERELAPSE_WELCOMETEXT			60000

#define TIMERID_HEART                   2
#define TIMESPACE_HEART                 3000

#define TIMERID_LOAD					3
#define TIMERSPACE_LOAD					1000


//�ͷ�
#define RELEASE(X) if(NULL!=X){delete X;X=NULL;}

//��������
enum LANGUAGETYPE
{
	LANGUAGETYPE_ZH_CN,
	LANGUAGETYPE_EN,
	LANGUAGETYPE_ZH_TW,

	LANGUAGETYPE_NULL
};

//��������
enum OPERATETYPE
{
	OPERATETYPE_WELCOMETEXT,
	OPERATETYPE_LOGIN,
	OPERATETYPE_LOGINOUT,
	OPERATETYPE_HEART,


	OPERATETYPE_NULL

};


//�Ի�������
enum DLGTYPE
{
	DLGTYPE_POWERMANAGE=1,
	DLGTYPE_HOSTCONFIG,

	DLGTYPE_NULL
};

//�ӶԻ�������
enum SUBBTNTYPE
{
	//
	SUBBTNTYPE_USERMANAGE=1,
	SUBBTNTYPE_NODEMANAGE,
	SUBBTNTYPE_LOGIN,


	SUBBTNTYPE_NULL
};

//�û�Ȩ��
enum USERPOWER
{
	USERPOWER_ADMIN=0,
	USERPOWER_NORMAL=1,

	USERPOWER_NULL=-1
};

//�û��������
enum USEROPERATE
{
	USEROPERATE_ADD,
	USEROPERATE_DEL,
	USEROPERATE_ALTER,

	USEROPERATE_NULL
	
};

//��ͷ
typedef enum
{
	PACKETHEAD_FULL,
	PACKETHEAD_PART,

	PACKETHEAD_NULL
}PACKERHEAD;

//Э������
typedef enum
{
	PROTOCOLTYPE_USERLIST,
	PROTOCOLTYPE_LOGIN,
	PROTOCOLTYPE_LOGINOUT,
	PACKERHEAD_HEART,




	PROTOCOLTYPE_NULL

}PROTOCOLTYPE;

//���ݽṹ

class XPowerManageItem;
#define VEC_POWERMANAGEITEM std::vector<XPowerManageItem*>