#pragma once

#include "../resource.h"
#include "XExpandInfo.h"
#include "XInputSignalPane.h"

class XDelegateInputSignalCutDlg;
class XInputSignal;


// CAddExpandDlg �Ի���

class XInputSignalCutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XInputSignalCutDlg)

public:
	XInputSignalCutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XInputSignalCutDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_INPUTSIGNALCUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateInputSignalCutDlg* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	//���������ź�����
	void SetInputSignalName(CString s);

	void InitData();

	int GetCutLTX();

	int GetCutLTY();

	int GetCutRBX();

	int GetCutRBY();

private:

	//���ؽ���
	void ReloadInterface();

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź�����
	CString m_InputSignalName;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

private:

	//ί��
	XDelegateInputSignalCutDlg* m_pDelegate;

	int m_LTX;

	int m_LTY;

	int m_RBX;

	int m_RBY;
};