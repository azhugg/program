#pragma once
#include "..\XConstantIM.h"
#include "XExpandInfo.h"

class XMultiVideoWindow;


class XRTSPInfo
{
public:
	XRTSPInfo(void);
	~XRTSPInfo(void);

public:

	//��ʼ��
	void Init(CString szRTSPAddr, CString szRTSPHDAddr, CString szAnotherName);

	//��ȡRTSP��ַ
	CString GetRTSPAddr();
	
	//��ȡRTSP��ַ
	CString GetRTSPHDAddr();

	//����RTSP��ַ
	void SetRTSPAddr(CString s);

	//��ȡRTSP��ַ
	void SetRTSPHDAddr(CString s);

	//��ȡ����
	CString GetAnotherName();

	//���ñ���
	void SetAnotherName(CString s);

	//��ȡԤ���ź����
	int GetPreviewIndex();

	//�����ź����
	void SetPreviewIndex(int n);

	//��ȡԤ��ID
	unsigned int GetPreviewID();

	//����Ԥ��ID
	void SetPreviewID(unsigned int nID);

	//��ȡ�ź���ID
	unsigned int GetPreviewGroupID();

	//�����ź���ID
	void SetPreviewGroupID(unsigned int nGroupID);

	//��ȡ�Ƿ�Ϊ4K
	BOOL GetIsUltra();

	//�����Ƿ�Ϊ4k
	void SetIsUltra(BOOL IsUltra);

	//�������
	void ClearData();

	//��ȡ�ֲ��Ŵ���Ϣ
	XExpandInfo* GetExpandInfo();

	//���þֲ��Ŵ���Ϣ
	void SetExpandInfo(XExpandInfo* p);

	//�ź�ID����
	VEC_UNINT& GetVecPreviewID();

	//�����ź�ID����
	void SetVecPreviewID(VEC_UNINT& VecInt);

	//�ź���ż���
	HYVEC_NUM& GetVecPreviewIndex();

	//�����ź���ż���
	void SetVecPreviewIndex(HYVEC_NUM& VecIndex);

	//4kRTSP����
	VEC_CSTRING& GetVecRTSPAddr();
	void SetVecRTSPAddr(VEC_CSTRING& VecStr);

	//����Ԥ��ǽ
	void SetMultiVideoWindow(XMultiVideoWindow* p);
	XMultiVideoWindow* GetMultiVideoWindow();

	//IP��ַ������4K��ק����RTSP��
	void SetIPAddr(CString szIP);
	CString GetIPAddr();

	//�Ƿ����ź�
	void SetIsHaveSignal(BOOL b);
	BOOL GetIsHaveSignal();

	//�Ƿ��а忨
	void SetIsHavePane(BOOL b);
	BOOL GetIsHavePane();

	//�û���
	void SetUseName(CString szUseName);
	CString GetUseName();
	//����

	void SetPassWd(CString szPssWd);
	CString GetPassWd();


public:

	//RTSP��ַ
	CString m_RTSPAddr;

	//RTSP HD��ַ
	CString m_RTSPHDAddr;

	//����
	CString m_szAnotherName;

	//���
	int m_nPreviewIndex;

	//�ź�ID
	unsigned int m_nPreviewID;

	//�ź���ID
	unsigned int m_nPreviewGroupID;

	//�ֲ��Ŵ���Ϣ
	XExpandInfo m_ExpandInfo;

	//�Ƿ�Ϊ4K
	BOOL m_bIsUltra;

	BOOL m_bIsHaveSignal;

	BOOL m_bIsHavePane;

	//�ź�ID����
	VEC_UNINT m_VecPreviewID;

	//�ź���ż���
	HYVEC_NUM m_VecPreviewIndex;

	XMultiVideoWindow* m_pMultiVideoWindow;

	VEC_CSTRING m_VecRTSPAddr;

	CString m_szIPAddr;

	CString m_szUseName;

	CString m_szPassWd;

};
