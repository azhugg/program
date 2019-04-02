#pragma once

#include "..\resource.h"
#include "XDialog.h"
#include "XBtn.h"

// CAboutDlg �Ի���

class XLoginLoad : public XDialog
{
	DECLARE_DYNAMIC(XLoginLoad)

public:
	XLoginLoad(CWnd* pParent = NULL,CString szPhotoPath=_T(""));   // ��׼���캯��
	virtual ~XLoginLoad();

	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();

	// �Ի�������
	enum { IDD = IDD_DIALOG_LOGINLOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

private:

	void Init();

	void UpdateText();

private:

	CString m_szText;

	int m_nIndex;
};
