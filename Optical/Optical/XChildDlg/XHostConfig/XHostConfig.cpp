// AboutDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XHostConfig.h"
#include "afxdialogex.h"
#include "XHandlePath.h"
#include "XTranslationManage.h"

// XHostConfig �Ի���

IMPLEMENT_DYNAMIC(XHostConfig, XChildDialog)

	XHostConfig::XHostConfig(CWnd* pParent)
	: XChildDialog(XHostConfig::IDD, pParent),
	m_pDelegate(NULL)
{
}

XHostConfig::~XHostConfig()
{

}

void XHostConfig::DoDataExchange(CDataExchange* pDX)
{
	XChildDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(XHostConfig, XChildDialog)
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// XHostConfig ��Ϣ�������

void XHostConfig::SetDelegate(XDelegateHostConfig* p)
{
	m_pDelegate=p;
}

BOOL XHostConfig::OnInitDialog()
{
	XChildDialog::OnInitDialog();

	SetWindowText(XTranslationManage::GetInstance()->GetTranslationString(_T("14"), _T("��������")));

	return TRUE;
}
