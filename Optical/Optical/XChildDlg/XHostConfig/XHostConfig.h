#pragma once

#include "..\resource.h"
#include "XChildDialog.h"
#include "XBtn.h"

class XDelegateHostConfig;

// CAboutDlg �Ի���

class XHostConfig : public XChildDialog
{
	DECLARE_DYNAMIC(XHostConfig)

public:
	XHostConfig(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XHostConfig();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_HOSTCONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateHostConfig* p);

private:

	XDelegateHostConfig* m_pDelegate;

};
