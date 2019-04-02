#pragma once

#include "XConstantIM.h"
#include "XVideoPreviewContain.h"
#include "ViewPreviewDlg.h"
#include "VideoPlayerConstant.h"

#define VIDEOPREVIEW_TEXTHEIGHT 20//���ִ�С

class XDelegateVideoPreviewPane;
class XRTSPInfo;
class XVideoPreviewInfo;
class XRTSPInfoDragWnd;
class XSelectInputDlg;
class XDragInfo;

// XVideoPreviewPane
class XVideoPreviewPane : public CDockablePane
{
	DECLARE_DYNAMIC(XVideoPreviewPane)
public:

	XVideoPreviewPane();
	virtual ~XVideoPreviewPane();

	virtual BOOL OnBeforeFloat(CRect& rectFloat, AFX_DOCK_METHOD dockMethod){return FALSE;}
	virtual BOOL CanFloat() const {return FALSE;}  
	virtual BOOL FloatPane(CRect rectFloat, AFX_DOCK_METHOD dockMethod = DM_UNKNOWN, bool bShow = true) { return FALSE; }
	
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	DECLARE_MESSAGE_MAP()

public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate(XDelegateVideoPreviewPane* pDelegate);

	//���ؽ���
	void ReloadInterface();

	//��������
	void ResetData();

	//��ȡ����״̬
	BOOL GetNetState();

	//��������
	BOOL SendData(char* pData, int nDataLen);

	//��ȡ����
	void GetData(CArchive& arch);

	//��������
	void SaveData(CArchive& arch);

	//����
	void Operate(OPERATETYPE type, void* pData);

	//�����϶�����
	XRTSPInfoDragWnd* CreatePreviewDragWnd(XRTSPInfo* pInfo);

	//�϶���Ϣ
	void DragInfo(CRect rc,XRTSPInfo* pInfo);

	//��ק
	BOOL DragInfoToFrame(CPoint point,XDragInfo* pInfo);

	//����Ԥ��ǽ��С
	void AdjustMultiVideoWindowSize();

	//������Ԥ��ǽ�Լ�����Ԥ��ǽ
	void AdjustMultiVideoWindowsSize();

	CString GetRTSPAddrFromPreviewPane(int nSignalIndex);
 
public:

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault);

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType);

private:

	BOOL CheckSumNum(char* pData,int nLen);

	unsigned short CheckNum(char *pData,int nLen);

public:

	//��ȡ���������߶�
	int GetContainScrollHeight();

	//��ȡ�������
	int GetContainScrollMax();

	//��ȡ�������
	int GetFrameLeft();

	//��ȡ�����Ҳ�
	int GetFrameRight();

	//��ȡ����
	CFont* GetFont();

	//��ȡί��
	XDelegateVideoPreviewPane* GetDelegate();

	//���ü�����
	void SetRTSPAddrCountPlus(CString szRTSPAddr);

	//���ü�����
	void SetRTSPAddrCountLess(CString szRTSPAddr);

	//���ü���
	void SetRTSPAddrCountReset(CString szRTSPAddr);

	//ɾ��RTSP
	void DeleteRTSP(CString szRTSPAddr);

	//��ʾ��ƵԤ���Ի���
	void ShowViewPreviewDlg(CString szIP,CString szRTSPAddr,int nInputIndex,CString szUseName,CString szPassWd);

	//����Ԥ�����ڱ���
	void SetPreviewNameByAnotherName(int& nInputIndx,CString szAnotherName);

	//����Ԥ���忨���缯��
	void SetMapBoardNetInfo();

	//��ȡ��Ļ�ź�RTSP��ַ����
	int GetRTSPCountBySignal(CString szRTSP);

	//��������RTSP��ַ
	void SetInputRTSPAddrByIndex(int nIndex,CString szRTSP=_T(""));

	//������Ļ�ź�RTSP��ַ
	void SetScreenSignalRTSPAddrByIndex(int nInputIndex,CString szRTSP=_T(""));

	//��������IP
	void SetInputParaByIndex(int nInputIndex,CString szIP=_T(""),CString szUseName=_T(""),CString szPassWd=_T(""));

	//���RTSP
	void AddRTSPAddr(CString szRTSP);

	//�ж������ź�״̬��4K,�����źţ����ް忨��
	void AdjustInputStatus(int nIndex,BOOL& bIsUltra,BOOL& bIsHaveSignal,BOOL& bIsHavePane);

	//�����ķ֣�����4K��
	void SetRectToFoure(RECTF rect,VEC_RECTF& VecRect);

	//����IP����RTSP
	void CreateRTSPAddr(CString szIP,CString szUseName,CString szPassWd,VEC_CSTRING& VecRTSPAddr);

	//����������ַ��ȡ������ַ
	CString GetMainRTSPBySubRTSP(CString szRTSPAddr);

	//�����������FrameRTSP����
	void SetFrameRTSPCountByIndex(int nInputIndex);

public:

	//��ȡԤ���򼯺�
	VEC_VIDEOPREVIEWFRAME& GetVecFrame();

	//��ȡԤ����Ϣ����
	VEC_DEVICEINFO& GetVecDeviceInfo();

	//��ȡ���뼯��
	VEC_INPUTSIGNAL& GetVecInputSignal();

private:

	//����Pane
	void CreatePane();

	//����Ԥ������
	void CreateContain();

	//��ʼ������
	void InitFont();

	//��������
	void AdjustLayout1();

	//����������
	void AdjustScroll();

	//��ʼ��Ԥ���򼯺�
	void InitVecFrame();

	//��ʼ����ƵԤ���Ի���
	void InitViewPreviewDlg();

	//ɾ������
	void DeleteFont();

	//�ָ��ַ���
	void SpiltCString(CString szSrc,CString ch,VEC_CSTRING& VecStr);

	//������Ż�ȡ��������
	CString GetInputNameByIndex(int& nIndex);

	//���ó�ʼRTSP����
	void InitMapRTSPAddrCount(CString szRTSPAddr,int n);

	//����Frame
	void AdjustVecFrame(CRect rect);

	//����
	void ResetInitVecFrame();

	//����IP����RTSP
	void CreateRTSPAddr();

	//���RTSP������
	void AddVecRTSP(CString szSubRTSP);

	BOOL JudgeOldIndexIsExist(int nIndex);

private:

	//���Ԥ���򼯺�
	void ClearVecFrame();

	//���Ԥ����Ϣ����
	void ClearDeviceInfo();

	//���Ԥ���Ի���
	void ClearPreviewDlg();

	//���RTSP����
	void ClearVecRTSP();

public:

	inline int GetBoardIndex(){return m_nBoardIndex;}

	inline void SetBoardIndex(int n){m_nBoardIndex=n;}

	inline CString GetUserName(){return m_szUserName;}

	inline void SetUserName(CString szName){m_szUserName=szName;}

	inline CString GetPassWd(){return m_szPassWd;}

	inline void SetPassWd(CString szPassWd){m_szPassWd=szPassWd;}

	inline CString GetszIP(){return m_szIP;}

	inline void SetIP(CString szIP){m_szIP=szIP;}

public:

	CString GetTitle();

	void SetFrameParamater();

	void SetframeRTSPAddr();

	void ResetRTSPInfo();

	void UpdateInputAnotherNameByPreview();

	void SetInputRTSPAddr();

	void DeleteCurPaneRTSP();

private:

	//ί��
	XDelegateVideoPreviewPane* m_pDelegate;

	//Ԥ������
	XVideoPreviewContain m_Contain;

	//�Ƿ񴴽�Ԥ������
	BOOL m_CreateContain;

	//����
	CFont m_Font;

	//Ԥ���Ի���
	CViewPreviewDlg* m_ViewPreviewDlg;

	//������򻺴�
	CRect m_InterRect;

	//���ڻ���
	XVideoPreviewFrame* m_pTempFrame;

	//˫���鿴������Ƶ������ʾǽ��
	XMultiVideoWindow* m_pMultiVideoWindow;

private:

	//Ԥ���򼯺�
	VEC_VIDEOPREVIEWFRAME m_VecFrame;

	//Ԥ����Ϣ����
	VEC_DEVICEINFO m_VecDeviceInfo;

	//RTSP��ַ
	VEC_RTSP m_VecRTSPAddr;

private:

	int m_nBoardIndex;

	CString m_szUserName;

	CString m_szPassWd;

	CString m_szIP;
};


