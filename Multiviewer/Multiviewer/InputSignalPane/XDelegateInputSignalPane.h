#pragma once

#include "XConstantIM.h"

class XDragInfo;
class XDragWnd;
class XMultiVideoWindow;

class XDelegateInputSignalPane
{
public:
	XDelegateInputSignalPane(void);
	~XDelegateInputSignalPane(void);

	//��ȡCWnd
	virtual CWnd* GetCWND() = 0;

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//�����϶�����
	virtual XDragWnd* CreateDragWnd(XDragInfo* pInfo) = 0;

	//�϶���Ϣ
	virtual void DragInfo(CRect rc,CPoint point,XDragInfo* pInfo) = 0;

	//��������
	virtual BOOL SendData(char* pData, int nDataLen) = 0;

	//��ȡ����״̬
	virtual BOOL GetNetState() = 0;

	//�Ƿ��¼
	virtual BOOL IsLogin() = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;

	//����Ԥ������
	virtual void SetPreviewNameByAnotherName(int& nInputIndex,CString szAnotherName)=0;

	//���RTSP
	virtual void AddRTSP(CString szRTSPAddr) = 0;

	//���RTSP HWND
	virtual void AddRTSPHWND(HWND h) = 0;

	//����RTSP HWND RTSP��ַ
	virtual void SetRTSPHWNDRTSPAddr(HWND h, CString szRSTPAddr) = 0;

	//ɾ��RTSP
	virtual void DeleteRTSP(CString szRTSPAddr) = 0;

	virtual void ChangeMultiVideoWindowsAnotherName(int nInputIndex,CString szAnotherName)=0;

	//��ȡ��ק��Ϣ
	virtual XDragInfo& GetDragInfo()=0;
};

