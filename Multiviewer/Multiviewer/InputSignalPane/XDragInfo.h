#pragma once

#include "XExpandInfo.h"
#include "XConstantIM.h"
#include "XSignalCutInfo.h"


class XMultiVideoWindow;
class XMultiVideoWindowFrame;

class XDragInfo
{
public:
	XDragInfo(void);
	~XDragInfo(void);

	//��ȡ�������
	int GetInputIndex();

	//��ȡ����
	CString GetText();

	//�ֲ��Ŵ�ƫ��
	XExpandInfo* GetExpandInfo();
	void SetExpand(XExpandInfo* pInfo);

	//�����������
	void SetInputIndex(int n);

	//��������
	void SetText(CString s);

	//�ź�ID
	unsigned int GetSignalID();
	void SetSignalID(unsigned int ID);

	//�ź���ID
	unsigned int GetSignalGroupID();
	void SetSignalGroupID(unsigned int ID);

	//��ק�ź�ID
	unsigned int GetDragSignalID();
	void SetDragSignalID(unsigned int SignalID);

	//��ק�ź���ID
	unsigned int GetDragSignalGroupID();
	void SetDragSignalGroupID(unsigned int SignalID);

	//�źŷֱ���
	void SetSignalResulationH(int n);
	int GetSignalResulationH();
	void SetSignalResulationV(int n);
	int GetSignalResulationV();

	//���ñ���
	void SetAnotherName(CString szName);
	CString GetAnotherName();

	//�Ƿ�Ϊ4K
	BOOL GetIsUltra();
	void SetIsUltra(BOOL b);

	//�ź�ID����
	VEC_UNINT& GetVecSignalID();
	void SetVecSignalID(VEC_UNINT& VecInt);

	//�ź���ż���
	HYVEC_NUM& GetVecSignalIndex();
	void SetVecSignalIndex(HYVEC_NUM& VecIndex);

	//�ź�ID����(������ק)
	VEC_UNINT& GetVecDragSignalID();
	void SetVecDragSignalID(VEC_UNINT& VecInt);

	//�ź���ż���(������ק)
	HYVEC_NUM& GetVecDragSignalIndex();
	void SetVecDragSignalIndex(HYVEC_NUM& VecIndex);

	//�ź�ID����(������չ)
	VEC_UNINT& GetVecExpandSignalID();
	void SetVecExpandSignalID(VEC_UNINT& VecInt);

	//�ź���ż���(������չ)
	HYVEC_NUM& GetVecExpandSignalIndex();
	void SetVecExpandSignalIndex(HYVEC_NUM& VecIndex);

	//�ź�ID���ϣ������л����룩
	VEC_UNINT& GetVecChangeInputID();
	void SetVecChangeInputID(VEC_UNINT& VecInt);

	//*********************************
	//��ƵԤ��
	CString GetRTSPAddr();
	void SetRTSPAddr(CString s);
	void ClearRTSPData();

	//IP��ַ
	CString GetScreenIP();
	void SetScreenIP(CString szIP);

	//Ԥ��Frame
	XMultiVideoWindowFrame* GetPreviewFrame();
	void SetPreviewFrame(XMultiVideoWindowFrame* p);

	//�������
	int GetInputNum();
	void SetInputNum(int n);

	//4��RTSP��ַ
	VEC_CSTRING& GetVecRTSPAddr();
	void SetVecRTSPAddr(VEC_CSTRING& VecStr);

	//Ԥ��ǽ
	XMultiVideoWindow* GetMultiVideoWindow();
	void SetMultiVideoWindow(XMultiVideoWindow* p);

	//IP��ַ
	CString GetIPAddr();
	void SetIPAddr(CString szIP);

	//�Ƿ����ź�
	BOOL GetIsHaveSignal();
	void SetIsHaveSignal(BOOL b);

	//�Ƿ��а忨
	BOOL GetIsHavePane();
	void SetIsHavePane(BOOL b);

	//�û���
	CString GetUseName();
	void SetUseName(CString szUseName);

	//����
	CString GetPassWd();
	void SetPassWd(CString szPassWd);

private:

	//�������
	unsigned short m_InputIndex;

	//�ֲ��Ŵ���Ϣ
	XExpandInfo m_ExpandInfo;

	//����
	CString m_Text;

	//�ź�ID�����϶�
	unsigned int m_nDragSignalID;

	//�ź���ID
	unsigned int m_nDragSignalGroupID;

	//�źŷֱ���
	int m_SignalresulationH;

	int m_SignalresulationV;

	//����
	CString m_AnotherName;

	//�Ƿ�Ϊ4K
	BOOL m_IsUltra;

	//RTSP��ַ
	CString m_szRTSPAddr;

	//�û���
	CString m_szUseName;

	//����
	CString m_szPassWd;

	//IP��ַ(��ĻIP)
	CString m_szScreenIP;

	//�ź�ID����
	VEC_UNINT m_VecSignalID;

	//�ź���ż���
	HYVEC_NUM m_VecSignalIndex;

	//�ź�ID����(������ק)
	VEC_UNINT m_VecDragSignalID;

	//�ź���ż���(������ק)
	HYVEC_NUM m_VecDragSignalIndex;

	//�ź�ID����(������չ)
	VEC_UNINT m_VecExpandSignalID;

	//�ź���ż���(������չ)
	HYVEC_NUM m_VecExpandSignalIndex;

	//�ź�ID���ϣ������л�����Դ��
	VEC_UNINT m_VecChangeInputID;

	XMultiVideoWindowFrame* m_pFrame;

	//�����ź���ţ��п��л���
	int m_nInputNum;

	//4��RTSP��ַ
	VEC_CSTRING m_VecRTSPAddr;

	//Ԥ��ǽ
	XMultiVideoWindow* m_pMultiVideoWindow;

	//4K�ź�IP(��������RTSP��ַ)
	CString m_szIPAddr;

	//�Ƿ����ź�
	BOOL m_bIsHaveSignal;

	//�Ƿ��а忨
	BOOL m_bIsHavePane;


};

