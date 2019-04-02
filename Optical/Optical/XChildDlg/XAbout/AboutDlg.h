#pragma once

#include "..\resource.h"
#include "XDialog.h"
#include "XBtn.h"

class XDelegateAboutDlg;

// CAboutDlg �Ի���

class CAboutDlg : public XDialog
{
	DECLARE_DYNAMIC(CAboutDlg)

public:
	CAboutDlg(CWnd* pParent = NULL,CString szPhotoPath=_T(""));   // ��׼���캯��
	virtual ~CAboutDlg();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnBTNLClick(WPARAM wParam, LPARAM lParam);
	afx_msg void OnStnDblclickStatic4();
	DECLARE_MESSAGE_MAP()

private:

	//������ť
	void CreateBtn();

private:

	//�رհ�ť
	XBtn m_Btn_Close;
};
