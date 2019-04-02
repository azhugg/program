#pragma once

#include "../resource.h"
#include "XExpandInfo.h"

class XDelegateAddExpandDlg;
class XInputSignal;
class XInputSignalPane;

// CAddExpandDlg �Ի���

class CAddExpandDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddExpandDlg)

public:
	CAddExpandDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddExpandDlg();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DLG_ADDEXPAND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateAddExpandDlg* p);

	//���������ź�
	void SetInputSignal(XInputSignal* p);

	void SetInputSignalPan(XInputSignalPane* p);

	//���������ź�����
	void SetInputSignalName(CString s);

	CString GetName();

	XExpandInfo* GetExpandInfo();

private:

	//���ؽ���
	void ReloadInterface();

	void InitData();

private:

	//ί��
	XDelegateAddExpandDlg* m_pDelegate;

	//�����ź�
	XInputSignal* m_InputSignal;

	XInputSignalPane* m_InputSIgnalPan;

	CString m_szName;

	XExpandInfo m_ExpandInfo;

	//�����ź�����
	CString m_InputSignalName;
};
