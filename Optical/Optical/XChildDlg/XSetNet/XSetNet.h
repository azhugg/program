#pragma once

#include "..\resource.h"
#include "XDialog.h"
#include "XBtn.h"

class XDelegateSetNet;

// CAboutDlg �Ի���

class XSetNet : public XDialog
{
	DECLARE_DYNAMIC(XSetNet)

public:
	XSetNet(CWnd* pParent = NULL,CString szPhotoPath=_T(""));   // ��׼���캯��
	virtual ~XSetNet();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_NET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnBTNLClick(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateSetNet* p);

private:

	void Init();

	void InitBtn();

	void InitShowData();

	void ReloadInterface();

	void OnBtnClickedOk();

private:

	XDelegateSetNet* m_pDelegate;
		
	XBtn m_Btn_Close;

	XBtn m_Btn_OK;

	XBtn m_Btn_Cancel;
};
