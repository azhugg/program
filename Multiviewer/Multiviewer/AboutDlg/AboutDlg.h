#pragma once

#include "..\resource.h"

class XDelegateAboutDlg;

// CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAboutDlg)

public:
	CAboutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAboutDlg();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_ABOUT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnDblclickStatic4();
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateAboutDlg* p);

private:

	XDelegateAboutDlg* m_Delegate;
};
