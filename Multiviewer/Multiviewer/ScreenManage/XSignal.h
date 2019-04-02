#pragma once

#include "XConstantIM.h"
#include "XExpandInfo.h"
#include "XSignalCutInfo.h"

class XScreen;
class XMultiVideoWindowFrame;

class XSignal
{
public:
	XSignal(void);
	~XSignal(void);

	void SetInputIndex(int n);

	void SetExpand(XExpandInfo* pInfo);

	void SetCutInfo(XSignalCutInfo* pCutInfo);

	void SetRect(RECTF r);

	void SetScreen(XScreen* p);

	XExpandInfo* GetExpandInfo();

	XSignalCutInfo* GetCutInfo();

	int GetInputIndex();

	RECTF GetRect();

	XScreen* GetScreen();

	unsigned int GetSignalID();

	void SetSignalID(unsigned int ID);

	unsigned int GetSignalGroupID();

	void SetSignalGroupID(unsigned int ID);

	void SetSignalLevel(int n);

	int GetSignalLevel();

	BOOL GetSignalHide();

	void SetSignalHide(BOOL b);

	int GetSignalHdpi();

	int GetSignalVdpi();

	void SetSignalHdpi(int n);

	void SetSignalVdpi(int n);

	void SetAnotherName(CString szName);

	CString GetAnotherName();

	BOOL GetIsUltra();

	void SetIsUltra(BOOL b);

	CString GetIPAddr();

	void SetIPAddr(CString szIP);

	CString GetUseName();

	void SetUseName(CString szUseName);

	CString GetPassWd();

	void SetPassWd(CString szPassWd);

	CString GetRTSPAddr();

	void SetRTSPAddr(CString szRTSPAddr);

	XMultiVideoWindowFrame* GetPreviewFrame();

	void SetPreviewFrame(XMultiVideoWindowFrame* p);

	BOOL GetIs4kTo2k();

	void SetIs4kTo2k(BOOL b);

	int GetSignalNum();

	void SetSignalNum(int n);

public:

	inline void SetSelected(BOOL b){m_bIsSelected=b;}

	inline BOOL GetSelected(){return m_bIsSelected;}

	inline void SetInteRect(RECTF rect){m_InteRect=rect;}

	inline RECTF GetInteRect(){return m_InteRect;}

public:

	//�ֲ��Ŵ���Ϣ
	XExpandInfo m_ExpandInfo;

private:

	//��Ļ
	XScreen* m_Screen;

	//����
	RECTF m_Rect;

	//�������
	int m_InputIndex;

	//�źŲü�
	XSignalCutInfo m_CutInfo;

	//��Ļˮƽ�ֱ���
	int m_SignalHdpi;

	//��Ļ��ֱ�ֱ���
	int m_SignalVdpi;

	//�źŲ��
	int m_SignalLevel;

	//�ź�ID
	unsigned int m_nSignalID;

	//�ź���ID
	unsigned int m_nSingalGroupID;

	//����
	BOOL m_IsHide;

	//����
	CString m_szAnotherName;

	//�ź����
	int m_nSignalNum;

	//�Ƿ�Ϊ4K
	BOOL m_IsUltra;

	//�Ƿ�Ϊ4k��2K
	BOOL m_bIs4kTo2k;

	//IP��ַ(����4K����RTSP��ַ)
	CString m_szIPAddr;

	//RTSP��ַ
	CString m_szRTSPAddr;

	CString m_szUseName;

	CString m_szPassWd;

	//�ź�ǽFrame
	XMultiVideoWindowFrame* m_pFrame;

	BOOL m_bIsSelected;

	//�źŵ����������������÷ֱ��ʺ����¿�����
	RECTF m_InteRect;
	
};

