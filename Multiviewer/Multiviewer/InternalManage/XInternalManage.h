 #pragma once

#include "XBaseInternalManage.h"
#include "XDelegateRibbonBarManage.h"
#include "XDelegateTranslationManage.h"
#include "XDelegateMessageBoxDlg.h"
#include "XDelegateScreenManage.h"
#include "XDelegateInputSignalPane.h"
#include "XDelegateNetManage.h"
#include "XDelegateIniManage.h"
#include "XDelegateDataManage.h"
#include "XDelegateAboutDlg.h"
#include "XDelegateUDPWatchPane.h"
#include "XDelegateVideoPreviewPane.h"
#include "XDelegateUserManage.h"
#include "XDelegateNewViewDlg.h"
#include "XVideoPlayer.h"
#include "XDelegateScenePane.h"
#include "XDelegatePreviewChild.h"
#include "XDelegateSetPreviewBoard.h"
#include "XBoardNetInfo.h"
#include "XBitRateInfo.h"
#include "XSaveAllScence.h"


class XBaseRibbonBarManage;
class XBaseTranslationManage;
class XBaseScreenManage;
class XBasePathManage;
class XBaseNetManage;
class XInputSignalPane;
class XBaseChildManage;
class XIniManage;
class XDataManage;
class XUDPWatchPane;
class XVideoPreviewPane;
class XUserManage;
class XRTSPInfoDragWnd;
class XScenePane;
class CMultiviewerView;
class XMultiVideoWindow;
class XSetPreviewBoard;
class XMyTabCtrl;


class XInternalManage : public XBaseInternalManage, 
	XDelegateRibbonBarManage, 
	XDelegateTranslationManage, 
	XDelegateMessageBoxDlg,
	XDelegateScreenManage,
	XDelegateInputSignalPane,
	XDelegateNetManage,
	XDelegateIniManage,
	XDelegateDataManage,
	XDelegateAboutDlg,
	XDelegateUDPWatchPane,
	XDelegateVideoPreviewPane,
	XDelegateUserManage,
	XDelegateNewViewDlg,
	XDelegateScenePane,
	XDelegatePreviewChild,
	XDelegateSetPreviewBoard
{
public:
	XInternalManage(void);
	~XInternalManage(void);

	//��ʼ��
	virtual void Init();

	virtual BOOL AppClose();

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault);

	//���¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type, void* pControl);

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type);

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type, void* pControl);

	//���ؽ���
	virtual void ReloadInterface();

	//Ribbon��ʾ�����
	virtual void RibbonBarShowCategory(CString szName);

	//��ʾ��Ϣ�Ի���
	virtual int MessageBox(CString szText, CString szCaption, UINT uType);

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType);

	//��ȡ�����ļ�·��
	virtual CString GetSceneFilePath(int nSceneIndex, CString szSceneName);

	virtual CString GetAllSceneFilePath(int nSceneIndex, CString szSceneName,int nIndex);

	//��ȡ�����ļ���·��
	virtual CString GetSceneFolderPath();

	//������ͼ��С
	virtual void ResetViewSize();

	//ˢ����ͼ
	virtual void InvalidateView();

	//��ȡ���ھ��
	virtual HWND GetHWND();

	//����
	virtual void Operate(OPERATETYPE type, void* pData);

	//���¿ؼ�UI
	virtual void UpdateControlUI(CMDUITYPE type, CCmdUI* pCmdUI);

	//�����������͸��¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type);

	//��ȡCWnd
	virtual CWnd* GetCWND();

	//��ȡ���ű���
	virtual float GetScale();

	//�������ű���
	virtual void SetScale(float f);

	//��ȡ�豸IP
	virtual CString GetDeviceIP();

	//��ȡ�豸�˿�
	virtual int GetDevicePort();

	//�����豸IP
	virtual void SetDeviceIP(CString str);

	//�����豸�˿ں�
	virtual void SetDevicePort(int n);

	//��ȡ��������
	virtual CString GetLanguagetype();

	//������������
	virtual void SetLanguagetype(CString type);

	//��ͼ����
	virtual void ViewDraw(CDC* pDC, CRect rect, int noffsetX, int noffsetY);

	//��ͼ��ȡ��С
	virtual CSize ViewGetSize();

	//��ͼ�������
	virtual void ViewLButtonDown(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ�������
	virtual void ViewLButtonUp(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ����ƶ�
	virtual void ViewMouseMove(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ����뿪
	virtual void ViewMouseLeave();

	//��ͼ��������
	virtual void ViewKeyUp(UINT nChar);

	//��ͼ�Ҽ�����
	virtual void ViewRButtonUp(CWnd* pWnd, UINT& nFlags, CPoint& point, 
		CRect& rect, int noffsetX, int noffsetY);

	//��ͼ���˫��
	virtual void ViewLBDClick(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��������
	virtual BOOL SendData(char* pData, int nDataLen);

	//�����϶�����
	virtual XDragWnd* CreateDragWnd(XDragInfo* pInfo);

	//����Ԥ���϶�����
	virtual XRTSPInfoDragWnd* CreatePreviewDragWnd(XRTSPInfo* pInfo);

	//�϶���Ϣ-�����ź�
	virtual void DragInfo(CRect rc,CPoint point,XDragInfo* pInfo);

	//Ԥ���϶���Ϣ-�����ź�
	virtual void DragInfo(CRect rc,XRTSPInfo* pInfo);

	//��ȡ��ͼ
	virtual CView* GetView();

	//����UDP��Ϣ
	virtual void HandleUDPMsg(WPARAM wParam, LPARAM lParam);

	//����UDP����
	virtual void HandleUDPData(unsigned char* pData, int nDataLen, SOCKADDR_IN addr);

	//��ȡ����״̬
	virtual BOOL GetNetState();

	//��ʼ��Pane
	virtual void InitPane();

	//���RTSP
	virtual void AddRTSP(CString szRTSPAddr);

	//���RTSP
	virtual void AddRTSP(CString szRTSPAddr,int nCount);

	//��������
	virtual void SetRTSPCountPlus(CString szRTSPAddr);

	//RTSP��������
	virtual void SetRTSPCountLess(CString szRTSPAddr);

	//���RTSP HWND
	virtual void AddRTSPHWND(HWND h);

	//����RTSP HWND RTSP��ַ
	virtual void SetRTSPHWNDRTSPAddr(HWND h, CString szRSTPAddr);

	//����RTSP HWND�����С
	virtual void AdjustRTSPHWNDSize(HWND h, int nWidth, int nHeight);

	//�����Ƶǽ
	virtual XMultiVideoWindow* AddMultiVideoWindow(HWND h);

	//ɾ��RTSP
	virtual void DeleteRTSP(CString szRTSPAddr);

	//��ȡ�������
	virtual int GetOutputCount();

	//��ȡ�������
	virtual int GetInputCount();

	//���������źŸ���
	virtual void SetInputCount(int n);

	//�Ƿ��¼
	virtual BOOL IsLogin();

	//��ȡ�û��ڵ�Ȩ��
	virtual BOOL GetUserNodePower(int nInputIndex, int nOutputIndex);

	//�Ƿ����Ա�û�
	virtual BOOL IsAdminUser();

	//�����������ݣ��򿪳�����
	virtual void ReSetInputData();

	//��ӳ�������
	virtual HTREEITEM AddSceneToTree(int nSceneIndex,CString szSceneName,int nType,CString szSceneGroup);

	virtual void AddViewNameToScene(HTREEITEM item,CString szSceneName,int nIndex,CString szViewName);

	//��ȡ�����źż���
	virtual VEC_INPUTSIGNAL& GetVecInputSignal();

	//��ȡ��Ļ����
	virtual VEC_SCREEN& GetVecScreen();

	//������Ż�ȡ��������
	virtual CString GetInputNameByIndex(int nIndex);

	//������Ż�ȡinput
	virtual XInputSignal* GetInputByIndex(int nIndex);

	//����Ԥ������
	virtual void SetPreviewNameByAnotherName(int& nInputIndex,CString szAnotherName);

	//�򿪳���
	virtual void OpenScene(CString szSceneName,int nSceneIndex,CString szViewName);

	//ɾ������
	virtual void DeleteScene(int nSceneIndex);

	//����osd
	virtual void SetOSD(XInputSignal* pInputSignal);

	//�������루scene��
	virtual void ResetDataBySceneInputCountChange();

	//��ȡ�Ƿ�Ϊ4K
	virtual void IsUltra(int nIndex);

	//�O���Ƿ񠑵�һ�Ά���
	virtual void SetIsFirstTime(BOOL IsFirstTime);

	//��ȡ�Ƿ�Ϊ��һ������
	virtual BOOL GetIsFirstTime();

	//��ȡ��������
	virtual XMenuScreenSetInfo* GetMenuScreenSetInfo();

	//�ж�changjingmingc
	virtual BOOL JudgeSceneName(CString szName);
	
	//��ʾ�˵�����ǩҳ�Ҽ���
	virtual void ShowMenu(CPoint& point);

	//����Ԥ��ǽ��С
	virtual void AdjustMultiVideoWindowHWNDSize(XMultiVideoWindow* p,int nWidth,int nHight);

	//�ж������Ƿ�Ϊ4K
	virtual void JudgetInputIsultra(int nInputIndex);

	//����RTSP��
	virtual void SetRTSPAddrCountPlus(CString szRTSPAddr);

	//����RTSP��
	virtual void SetRTSPAddrCountLess(CString szRTSPAddr);

	//����RTSP����
	virtual void SetRTSPAddrCountReset(CString szRTSPAddr);

	//ֱ������RTSP����
	virtual void SetRTSPAddrCount(CString szRTSPAddr,int nCount);

	//����RTSP��ȡ��Ļ�źŵ�RTSP����
	virtual int GetRTSPCountBySignal(CString szRTSP);

	//���������źŵ�RTSP��ַ����ק
	virtual void SetInputRTSPAddrByIndex(int nIndex,CString szRTSP);

	//������Ļ���ź�RTSP
	virtual void SetScreenSignalRTSPAddrByIndex(int nInputIndex,CString szRTSP);

	//���������ź���Ϣ
	virtual void SetInputParaByIndex(int nIndex,CString szIP,CString szUseName,CString szPassWd);

	//�����Ƿ����ź�
	virtual BOOL IsHaveSignal(int nIndex);

	//�����Ƿ��а忨
	virtual BOOL IsHavePane(int nIndex);

	//����Ԥ��ǽ����
	virtual void SetMultiScale(float f);

	//�ı�Ԥ��ǽ�źű���
	virtual void ChangeMultiVideoWindowsAnotherName(int nInputIndex,CString szAnotherName);

	//�����Ԥ�����
	virtual void SetActiveDockPane();

	//�ر�Ԥ�����
	virtual void CloseActivePane();

	//��ȡ��������
	virtual MAP_SCENEGROUP& GetMapSceneGroup();

	//��ȫ������
	virtual void OpenAllScene(CString szSceneName,int nSceneIndex);

	//��ȫ�������е�һ��
	virtual void OpenOneSceneOfAll(CString szSceneName,int nSceneIndex,CString szViewName);

	//����ָ��
	virtual void CopyOrderToShare(CString szSceneName,int nSceneIndex,CString szViewName);

	virtual void CopySingleOrderToShare(CString szSceneName,int nSceneIndex,CString szViewName);

	//��ȡ��Ļ�������
	virtual int GetVecBaseManageSize();

	//�����������Ԥ������RTSP����Ϊ1
	virtual void SetFrameRTSPCountByIndex(int nInputIndex);

	//��ȡȨ����ʾ��
	virtual CString GetNotice();

	//˫���ײ�Tab��ǩ
	virtual BOOL SetTabCtrlDbCLick(POINT point);

	//˫��ͬ��Tab��ǩ
	virtual BOOL SetViewTabBarDbClick(POINT point);

	//�����ײ�Tab��ǩ
	virtual void SetTabCtrlCLick(POINT point);

	//��ǩ��ע
	virtual MAP_TABLABLE& GetMapBottomTabLable();

	//��ȡ��Ļ������
	virtual VEC_BASESCREENMANAGE& GetVecBaseScreenManage();

	//����ѡ���ź���Ϣ
	virtual BOOL SetSelInputDataInfo();

	//��ȡ��ק��Ϣ
	virtual XDragInfo& GetDragInfo();

	virtual CString GetRTSPAddrFromPreviewPane(int nSignalIndex);

private:

	//��ʼ������
	void InitManage();

	//��ʼ����������
	void InitAppData();

	//��ʼ�������ź�
	void InitInputSignal();

	//��ʼ����Ƶ����
	void InitVideoPlayer();

	//��ȡӦ������
	BOOL GetAppData();

	//��ȡӦ������
	void GetAppData(CArchive& arch);

	//����Ӧ������
	BOOL SaveAppData();

	//����Ӧ������
	void SaveAppData(CArchive& arch);

	//����Ӧ������
	void ResetAppData();

	//��ȡ��������
	CString GetTitle(CString szStr);

	//�������ƻ�ȡ������
	XBaseChildManage* GetChildManage(CString szName);

	//�����϶�����
	void CreateDragWnd();

	//����Ԥ���϶�����
	void CreatePreviewDragWnd();

	//��ʾ���ڶԻ���
	void ShowAboutDlg();

	//���Ԥ����Ļ
	void AddFrames(XBaseScreenManage* pManage);

	//����Ԥ����Ļ����
	CString SetText(XScreen* pScreen);

	BOOL CheckSumNum(char* pData,int& nLen);

	unsigned short CheckNum(char *pData,int nLen);

	XBaseScreenManage* GetBaseScreenManageByViewName(CString szViewName);

	void GetAnotherNameByTabLable(CString szTabLable,CString& szName,CString& szAnotherName);

	CString GetLabelByTab(CString szLable);

	//������������RTSP��Ϣ
	void SetInputSignalPara();

public:

	//���
	void Clear();

	//�����Ļ������
	void ClearVecBaseScreenManage();

	//�ͷŹرյ���Ļ������
	void ClearTempBase();

	//���Ԥ�����
	void ClearVecPreviewPane();

	//���Ԥ����建��
	void ClearVecPreviewPaneTemp();

	void ClearMapSelectBoard();

	void ClearPreviewTemp();

	void ClearMapBottomTabLable();

public:

	VEC_BASESCREENMANAGE& GetBaseManage();

	MAP_SELECTBOARD& GetMapSelectBoard();

	VEC_VIDEOPREVIEWPANE& GetVecPreviewPane();

	MAP_PREVIEWTEMP& GetMapPreviewTemp();

	MAP_BOARDTYPE& GetMapBoardType();

	void SetNowScreenManage(XBaseScreenManage* p);

	void OperateOfNewView();

	void AddDocument(); 

	void AddDocument(XBaseScreenManage* pManage);

	CView* GetDocumentFrontView(CDocument* p);

	void CloseMDI(XBaseScreenManage* pManage);

	XUserManage* GetUserManage();

	XBoardNetInfo* GetBoardInfo();

	XBitRateInfo* GetBitRateInfo();

	void SetShowScreenManage();

	void CopySelectedBoardInfo(VEC_PREVIEWBOARD& VecBoard);

	void SetPreviewPane();

	void InitPreviewPane();

	void SetBaseTabCtr();

	void AddPreviewPane(XVideoPreviewPane* pPane);

	void PreviewPaneReloadInterface();

	void ScreenReloadInterface();

	void SaveSceneByCloseView();

	int GetScreenType();

public:

	void OperateOfSetPreviewBoard();

	void OperateOfSplitNetSet();

	void OpersteOdSplitBitRate();

	void OperateOfSaveAllScene();

	void OperateOfFirstView();

	void OperateOfReadPreviewNet(char *pData);

	void OperateOfReadPreviewBitRate(char* pData);

	void OperateOfReadSceneIndex(char* pData);


private:

	//RibbonBar����
	XBaseRibbonBarManage* m_pRibbonBarManage;

	//�������
	XBaseTranslationManage* m_pTranslationManage;

	//��Ļ����
	XBaseScreenManage* m_pNowScreenManage;

	//·������
	XBasePathManage* m_pPathManage;

	//�����ź����
	XInputSignalPane* m_pInputSignalPane;

	//UDP�������
	XUDPWatchPane* m_pUDPWatchPane;

	//�������
	XBaseNetManage* m_pNetManage;

	//��Ļ�������
	XBaseChildManage* m_pChildManage;

	//Ini������
	XIniManage* m_pIniManage;

	//���ݹ���
	XDataManage* m_pDataManage;

	//��ƵԤ�����
	XVideoPreviewPane* m_VideoPreviewPane;

	//��Ƶ����
	XVideoPlayer m_VideoPlayer;

	//�û�����
	XUserManage* m_pUserManage;

	//�������
	XScenePane* m_pScenePane;

private:
	
	//�϶�����
	XDragWnd* m_DragWnd;

	//Ԥ���϶�����
	XRTSPInfoDragWnd* m_PreviewDragWnd;

	//Ԥ��������
	XSetPreviewBoard* m_SetPreviewBoardDlg;

	//Ԥ����������Ϣ
	XBoardNetInfo m_BoardInfo;

private:

	//ѡ����ͼ����
	CString m_SelectViewName;

	//��Ƶǽ
	XMultiVideoWindow* m_pMultiVideoWindow;
	
	XMultiVideoWindow* m_pDragInputMultiVideoWindow;

	XMultiVideoWindow* m_pDragPreviewMultiVideoWindow;

	BOOL m_bIsFirstTime;

private:

	//Ԥ�����
	CTabbedPane* m_pTabbedBar;

	//Ԥ������ǩҳ
	XMyTabCtrl* m_pTabCtrl;

	//CMFCTabCtrl* m_pTabCtrl;

	//��ͼTabbar
	XMyTabCtrl* m_pViewTabCtrl;

	//Ԥ�������
	XVideoPreviewPane* m_pTemp;

	//Ԥ����������Ϣ
	XBitRateInfo m_BitRateInfo;

	//����������
	XSaveAllScence m_SaveAllSceneDlg;

private:

	//��ͼ����
	VEC_BASESCREENMANAGE m_VecBaseScreenManage;

	VEC_BASETEMP m_VecTemp;

	//Ԥ�����
	VEC_VIDEOPREVIEWPANE m_VecVideoPreviewPane;

	//Ԥ����建��
	VEC_VIDEOPREVIEWPANETEMP m_VecVideoPreviewPaneTemp;

	//����Ԥ������Ϣ
	MAP_SELECTBOARD m_MapSelectBoard;

	//Ԥ������λ���ϣ���ֹ�ظ���
	MAP_PREVIEWTEMP m_MapPreviewTemp;

	//�ײ���ǩ��ע
	MAP_TABLABLE m_MapBottomTabCtrLable;

};

