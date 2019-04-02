#include "stdafx.h"
#include "XReName.h"
#include "afxdialogex.h"
#include "XDelegateReName.h"

// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XReName, CDialogEx)

	XReName::XReName(CWnd* pParent /*=NULL*/)
	: CDialogEx(XReName::IDD, pParent)
{
	m_pDelegate = NULL;

	m_szScreenName=_T("");

	m_szTitle=_T("");

	m_szName=_T("");
}

XReName::~XReName()
{

}

void XReName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(XReName, CDialogEx)
	ON_BN_CLICKED(IDOK, &XReName::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XReName::SetDelegate(XDelegateReName* p)
{
	m_pDelegate = p;
}

BOOL XReName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitData();

	return FALSE;  
}

void XReName::SetTitle(CString szTitle)
{
	m_szTitle=szTitle;
}

void XReName::SetName(CString szName)
{
	m_szName=szName;
}

void XReName::ReloadInterface()
{
	SetWindowText(m_szTitle);
	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("268"), _T("����")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("215"), _T("ȡ��")));
	GetDlgItem(IDC_STATIC_ANOTHERNAME)->SetWindowText(m_pDelegate->GetTranslationString(_T("390"), _T("����"))+ _T(":"));
	//GetDlgItem(IDC_STATIC_TIPS49)->SetWindowText(m_pDelegate->GetTranslationString(_T("660"),_T("��ʾ:��עΪ��ʱȡ����ע")));
}

void XReName::InitData()
{
	//GetDlgItem(IDC_EDIT_ANOTHERNAME)->SetWindowText(m_InputSignal->GetAnotherName());

	GetDlgItem(IDC_EDIT_ANOTHERNAME)->SetWindowText(m_szName);
}

CString XReName::GetScreenName()
{
	return m_szScreenName;
}

void XReName::OnBnClickedOk()
{
	CString szName = _T("");
	GetDlgItem(IDC_EDIT_ANOTHERNAME)->GetWindowText(szName);
	szName.Trim();

	m_szScreenName=szName;

	CDialogEx::OnOK();
}