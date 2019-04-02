#pragma once

#include "../resource.h"

class XInputSignal;
class XInputSignalPane;


class XDelegateStreamAddr;


class XStreamAddr : public CDialogEx
{
	DECLARE_DYNAMIC(XStreamAddr)

public:
	XStreamAddr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XStreamAddr();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_IPSTREAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBnClickedOk();
		afx_msg void OnBtnRead();
		afx_msg void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateStreamAddr* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	void InitData();

	//���������ź�����
	void SetInputSignalName(CString s);

	//������Ƶ����ַ
	void SetStreamAddr(CString szStream);

	void ResetStream();

	void UpdateText();

	void ReRead();

private:

	//���ؽ���
	void ReloadInterface();

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

private:

	//ί��
	XDelegateStreamAddr* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;

	//��Ƶ����ַ
	CString m_szStreamAddr;

	//����
	CString m_Text;

	//����
	int m_Index;

	int m_nReadIndex;

	//��ʼ��ȡʱ��
	DWORD m_dBeginTime;

	CString m_szReadIndex;

};