#pragma once
#include "XConstantIM.h"


class XVideoPreviewPane;
class XVideoPreviewVideoWnd;
class XVideoPreviewTextWnd;
class XVideoPreviewContain;
class XMultiVideoWindow;

class XVideoPreviewFrame
{
public:
	XVideoPreviewFrame(void);
	~XVideoPreviewFrame(void);

	//��ʼ��
	void Init();

	//�����Ƶǽ
	void AddMultiVideoWindow();

	//�������
	void SetPane(XVideoPreviewPane* p);

	//��������
	void SetContain(XVideoPreviewContain* p);

	//�������
	void SetFrameIndex(int n);

	//����RTSP��ַ
	void SetRTSPAddr(CString s);

	//��������
	void SetRect(CRect r);

	//�������
	void SetIndex(int n);

	//��ȡ���
	int GetFrameIndex();

	//��ȡ����
	CRect GetRect();

	//��ȡRTSP��ַ
	CString GetRTSPAddr();

	//��ȡ���
	int GetIndex();

	//����IP
	void SetIP(CString szIP);

	//��ȡIP
	CString GetIP();

	//�����û���
	void SetUseName(CString szName);
	CString GetUseName();

	//��������
	void SetPassWd(CString szPassWd);
	CString getPassWd();

	//�����ǲ���4K
	void SetIsUltra(BOOL bIsUltra);
	BOOL GetIsUltra();

	//�Ƿ����ź�
	void SetIsHaveSignal(BOOL b);
	BOOL GetIsHaveSignal();

	//�Ƿ��а忨
	void SetIsHavePane(BOOL b);
	BOOL GetIsHavePane();

	//���ؽ���
	void ReloadInterface();

	//��ȡ��Ƶ����
	CRect GetVideoRect();

	//���������ź�����
	void SetAnotherName(CString szAnotherName);

	//��ȡ�����ź�����
	CString GetAnotherName();

	//�������Ƶ����
	void ClearVideoWnd();

	//������ִ���
	void ClearTextWnd();

	//����Ԥ�������
	void SetPreviewBoardIndex(int n);
	int GetPreviewBoardIndex();

	//��ӻ���
	void AddUltraFrame();
	void AddCommFrame();

	//���֮ǰFrame
	void ClearFrame();

	//���Frame
	void SetPreviewFrame();

	//ִ���л�ָ��
	void RunOrder();

	//���������Լ���Ļ�ź���Ϣ
	void SetSignalRTSPAddr();

public:

	XVideoPreviewPane* GetPane();

	//��������
	void UpdateText();

	//��ȡ�豸��Ϣ
	XDeviceInfo* GetDeviceInfo();

	//�����豸��Ϣ
	void SetDeviceInfo(XDeviceInfo* pInfo);

	//����4��RTSP��ַ(4k)
	void CreateRTSPAddr();

	//��ȡRTSP��ַ����
	VEC_CSTRING& GetVecRTSPAddr();

	//������Ƶǽ��С
	void AdjustMultiVideoWindowSize();

	//��ʼ��Frame
	void InitFrame();

	//����λ�õ���Frame����λ��
	void AdjustRect();

private:

	//������Ƶ����
	void CreateVideoWnd();

	//�������ִ���
	void CreateTextWnd();

	//���RTSPjihe
	void ClearRTSPAddr();

	//���RTSP
	void AddRTSP();

private:

	XVideoPreviewPane* m_Pane;

	XVideoPreviewContain* m_Contain;

	XDeviceInfo* m_DeviceInfo;

	//��Ƶ����
	XVideoPreviewVideoWnd* m_VideoWnd;

	//���ִ���
	XVideoPreviewTextWnd* m_TextWnd;

	//��Ƶǽ
	XMultiVideoWindow* m_pMultiVideoWindow;

private:

	//����
	CRect m_Rect;

	//��Ƶ����
	CRect m_VideoRect;

	//�������
	int m_nFrameIndex;

	//Ԥ�������
	int m_nBoardIndex;

	//RTSP��ַ
	CString m_RTSPAddr;

	//����4kʱ��ͬ������RTSP
	CString m_szIP;

	//�û���
	CString m_szUseName;

	//����
	CString m_szPassWd;

private:

	//����Դ���
	int m_Index;

	//�Ƿ�Ϊ4K
	BOOL m_bIsUltra;

	//RTSP����
	VEC_CSTRING m_VecRTSPAddr;

	//������û���ź�
	BOOL m_bIsHaveSignal;

	//������û�а忨
	BOOL m_bIsHavePane;

	//�����ź�
	CString m_szAnotherName;
};

