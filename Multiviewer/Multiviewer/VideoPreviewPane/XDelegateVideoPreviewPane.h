#pragma once

#include "XConstantIM.h"

class XRTSPInfo;
class XRTSPInfoDragWnd;
class XMultiVideoWindow;


class XDelegateVideoPreviewPane
{
public:
	XDelegateVideoPreviewPane(void);
	~XDelegateVideoPreviewPane(void);

	//��ȡCWnd
	virtual CWnd* GetCWND() = 0;

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//���RTSP
	virtual void AddRTSP(CString szRTSPAddr) = 0;

	//���RTSP
	virtual void AddRTSP(CString szRTSPAddr,int nCount)=0;

	//RTSP��������
	virtual void SetRTSPCountPlus(CString szRTSPAddr)=0;

	virtual void SetRTSPCountLess(CString szRTSPAddr)=0;

	//���RTSP HWND
	virtual void AddRTSPHWND(HWND h) = 0;

	//����RTSP HWND RTSP��ַ
	virtual void SetRTSPHWNDRTSPAddr(HWND h, CString szRSTPAddr) = 0;

	//�����Ƶǽ
	virtual XMultiVideoWindow* AddMultiVideoWindow(HWND h)=0;

	//ɾ��RTSP
	virtual void DeleteRTSP(CString szRTSPAddr) = 0;

	//��������
	virtual BOOL SendData(char* pData, int nDataLen) = 0;

	//��ȡ����״̬
	virtual BOOL GetNetState() = 0;

	//��ȡ�������
	virtual int GetInputCount() = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;

	//�Ƿ��¼
	virtual BOOL IsLogin() = 0;

	//��ȡ�û��ڵ�Ȩ��
	virtual BOOL GetUserNodePower(int nInputIndex, int nOutputIndex) = 0;

	//����RTSP HWND�����С
	virtual void AdjustRTSPHWNDSize(HWND h, int nWidth, int nHeight) = 0;

	//��ȡ���뼯��
	virtual VEC_INPUTSIGNAL& GetVecInputSignal()=0;

	//��ȡ��Ļ����
	virtual VEC_SCREEN& GetVecScreen()=0;

	//������Ż�ȡ��������
	virtual CString GetInputNameByIndex(int nIndex)=0;

	//������Ż�ȡInput
	virtual XInputSignal* GetInputByIndex(int nIndex)=0;
	
	//������ק����
	virtual XRTSPInfoDragWnd* CreatePreviewDragWnd(XRTSPInfo* pInfo)=0;

	//�϶���Ϣ
	virtual void DragInfo(CRect rc,XRTSPInfo* pInfo)=0;

	//��ȡ�Ƿ�Ϊ4K
	virtual void IsUltra(int nIndex)=0;

	//�ж������Ƿ����ź�
	virtual BOOL IsHaveSignal(int nIndex)=0;

	//�ж��Ƿ��а忨
	virtual BOOL IsHavePane(int nIndex)=0;

	//�������źŻ�ȡRTSP����
	virtual int GetRTSPCountBySignal(CString szRTSP)=0;

	//�����ź�������������ź�RTSP
	virtual void SetInputRTSPAddrByIndex(int nIndex,CString szRTSP)=0;

	virtual void SetScreenSignalRTSPAddrByIndex(int nInputIndex,CString szRTSP)=0;

	//�����ź�������������ź�IP
	virtual void SetInputParaByIndex(int nIndex,CString szIP,CString szUseName,CString szPassWd)=0;

	//����Ԥ��ǽ��С
	virtual void AdjustMultiVideoWindowHWNDSize(XMultiVideoWindow* p,int nWidth,int nHight)=0;

	virtual void SetRTSPAddrCount(CString szRTSPAddr,int nCount)=0;

	virtual MAP_TABLABLE& GetMapBottomTabLable()=0;

};

