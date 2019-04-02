#pragma once

#include "XOSDInfo.h"
#include "XExpandInfo.h"
#include "XConstantIM.h"
#include "XSignalCutInfo.h"
#include "XBorderOverlay.h"
#include "XEDIDInfo.h"
#include "XStreamAddrInfo.h"
#include "XPaneIPAddrInfo.h"



class XInputSignal
{
public:
	XInputSignal(void);
	~XInputSignal(void);

	//�����������
	void SetInputIndex(int n);

	//��ȡ�������
	int GetInputIndex();

	//�������οؼ�������
	void SetTreeItem(HTREEITEM h);

	//��ȡ���οؼ�������
	HTREEITEM GetTreeItem();

	//��Ӿֲ��Ŵ�
	void AddExpand(XInputSignalExpand* p);

	//ɾ���ֲ��Ŵ�
	void DeleteExpand(XInputSignalExpand* p);

	//��ȡ�ֲ��Ŵ󼯺�
	VEC_INPUTSIGNALEXPAND& GetVecExpand();

	//�ж������Ƿ����
	BOOL DecideExpandNameExist(XInputSignalExpand* pExpand, CString szName);

	//��ȡ�¾ֲ��Ŵ�ID
	int GetNewExpandID();

	//����Ĭ�Ͼֲ��Ŵ�ID
	void SetDefaultExpandID(int nID);

	//��ȡĬ�Ͼֲ��Ŵ�ID
	int GetDefaultExpandID();

	//����Ĭ�Ͼֲ��Ŵ�ID
	void ResetDefaultExpandID();

	//���ñ���
	void SetAnotherName(CString szName);

	//��ȡ����
	CString GetAnotherName();

	//�Ƿ�Ϊ4K
	BOOL GetIsUltra();

	void SetIsUltra(BOOL b);

	CString GetRTSPAddr();

	void SetRTSPAddr(CString szRTSP);

	CString GetIPAddr();

	void SetIPAddr(CString szIP);

	CString GetUseName();

	void SetUseName(CString szUseName);

	CString GetPassWd();

	void SetPassWd(CString szPassWd);

	//����������
	void SetGroupName(CString szName);

	//��ȡ������
	CString GetGroupName();

	//�����Ƿ�������
	void SetIsInGroup(BOOL b);

	BOOL GetIsInGroup();

public:
	//�����ź���Ϣ
	void SetChanel(int n);

	void SetReStatus(int n);

	void SetReResulationH(int n);

	void SetReResulationV(int n);

	void SetReRefresh(int n);

	void SetReVideoSelect(int n);

	void SetReDataLen(int n);

	int GetReSignalIndex();

	int GetReSignalChenal();

	int GetChanel();

	int GetReStatus();

	int GetReResulationH();

	int GetReResulationV();

	int GetReRefresh();

	int GetReVideoSelect();

	int GetReDataLen();

public:

	//��ȡOSD��Ϣ
	XOSDInfo* GetOSDInfo();

	//��ȡĬ�Ͼֲ��Ŵ�
	XInputSignalExpand* GetDefaultExpand();

	//��ȡ�߿����
	XBorderOverlay* GetBorderOverLay();

	//��ȡ������Ϣ
	XSignalCutInfo* GetDefaultCutInfo();

	//EDID����
	XEDIDInfo* GetEDIDInfo();

	//��Ƶ����ַ
	XStreamAddrInfo* GetStreamInfo();

	//�忨IP��ַ
	XPaneIPAddrInfo* GetPaneIPAddrInfo();

	//��ȡ�ֲ��Ŵ�
	XInputSignalExpand* GetExpandByID(int nID);

private:

	//����ֲ��Ŵ󼯺�
	void ClearVecExpand();

private:

	//�ֲ��Ŵ󼯺�
	VEC_INPUTSIGNALEXPAND m_VecExpand;

private:

	//���οؼ�������
	HTREEITEM m_TreeItem;

	//�������
	int m_InputIndex;

	//Ĭ�Ͼֲ��Ŵ�ID
	int m_DefaultExpandID;

	CString m_AnotherName;

	//�Ƿ�Ϊ4K
	BOOL m_IsUltra;

	//RTSP��ַ
	CString m_szRTSPAddr;

	//IP��ַ����4K��ק�������RTSP
	CString m_szIPAddr;
	CString m_szRTSPName;
	CString m_szRTSPPassWd;

	//������
	CString m_szGroupName;

	//�Ƿ�������
	BOOL m_bIsInGroup;


private:

	XOSDInfo m_OSDInfo;

	XBorderOverlay m_Border;

	XSignalCutInfo m_CutInfo;

	XEDIDInfo m_EDIDInfo;

	XStreamAddrInfo m_StreamInfo;

	XPaneIPAddrInfo m_PaneIPInfo;

private:
	//��������״̬
	int m_Chenal;

	int m_ReSignalIndex;

	int m_ReSignalChenal;

	int m_ReStatus;

	int m_ReResulationH;

	int m_ReResulationV;

	int m_ReRefresh;

	int m_ReVideoSelect;

	int m_ReDataLen;

};

