// ChangeRTSPAddrDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "XUserManage.h"
#include "XDelegateUserManage.h"
#include "..\XConstant.h"
#include "HandlePath.h"
#include "HandleIni.h"

// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
{
	m_UserManage = NULL;
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������

BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	((CEdit*)GetDlgItem(IDC_EDIT_ACCOUNT))->SetLimitText(18);
	((CEdit*)GetDlgItem(IDC_EDIT_PSW))->SetLimitText(18);

	CString szIniPath = HandlePath::GetIniPath(APP_ININAME);
	CString szAccount = HandleIni::GetString(_T("Info"), _T("Account"), _T(""), szIniPath);
	GetDlgItem(IDC_EDIT_ACCOUNT)->SetWindowText(szAccount);

	return FALSE;  
}

void CLoginDlg::ReloadInterface()
{
	XDelegateUserManage* pDelegate = m_UserManage->GetDelegate();

	SetWindowText(pDelegate->GetTranslationString(_T("344"), _T("��½")));

	GetDlgItem(IDOK)->SetWindowText(pDelegate->GetTranslationString(_T("214"), _T("ȷ��")));

	GetDlgItem(IDCANCEL)->SetWindowText(pDelegate->GetTranslationString(_T("215"), _T("ȡ��")));

	GetDlgItem(IDC_STATIC_ACCOUNT)->SetWindowText(pDelegate->GetTranslationString(_T("348"), _T("�ʺ�")) + _T(":"));

	GetDlgItem(IDC_STATIC_PSW)->SetWindowText(pDelegate->GetTranslationString(_T("349"), _T("����")) + _T(":"));
}

void CLoginDlg::SetUserManage(XUserManage* p)
{
	m_UserManage = p;
}

void CLoginDlg::OnBnClickedOk()
{
	CString szAccount = _T("");
	GetDlgItem(IDC_EDIT_ACCOUNT)->GetWindowText(szAccount);
	szAccount.Trim();
	if (_T("") == szAccount)
	{
		m_UserManage->GetDelegate()->MessageBoxFromKey(_T("350"), _T("�ʺŲ���Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_ACCOUNT)->SetFocus();

		return;
	}

	CString szPSW = _T("");
	GetDlgItem(IDC_EDIT_PSW)->GetWindowText(szPSW);
	szPSW.Trim();
	if (_T("") == szPSW)
	{
		m_UserManage->GetDelegate()->MessageBoxFromKey(_T("21"), _T("���벻��Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_PSW)->SetFocus();

		return;
	}

	//���浽INI
	CString szIniPath = HandlePath::GetIniPath(APP_ININAME);
	HandleIni::WriteData(_T("Info"), _T("Account"), szAccount, szIniPath);

	XUserInfo* pUserInfo = m_UserManage->DecideAccountAndPsw(szAccount, szPSW);

	if (NULL == pUserInfo)
	{
		m_UserManage->GetDelegate()->MessageBoxFromKey(_T("352"), _T("�ʺŻ������������������!"), MB_OK);
	}
	else
	{
		m_UserManage->SetCurUserInfo(pUserInfo);

		CDialogEx::OnOK();
	}
}
