#include "stdafx.h"
#include "XGroupName2.h"
#include "afxdialogex.h"
#include "XInputSignal.h"
#include "XInputSignalPane.h"



// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XGroupName2, CDialogEx)

	XGroupName2::XGroupName2(CWnd* pParent /*=NULL*/)
	: CDialogEx(XGroupName2::IDD, pParent)
{

	m_InputSignal=NULL;

	m_InputSignalPane=NULL;
}

XGroupName2::~XGroupName2()
{

}

void XGroupName2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(XGroupName2, CDialogEx)
	ON_BN_CLICKED(IDOK, &XGroupName2::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

//void XGroupName2::SetDelegate(XDelegateSetAnotherNameDlg* p)
//{
//	m_pDelegate = p;
//}

void XGroupName2::SetInputSignal(XInputSignal* p)
{
	m_InputSignal = p;
}

void XGroupName2::SetInputSignalPane(XInputSignalPane* p)
{
	m_InputSignalPane = p;
}

void XGroupName2::SetInputSignalName(CString s)
{
	m_InputSignalName=s;
}

BOOL XGroupName2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitData();

	GetDlgItem(IDC_EDIT_GROUPNAME2)->SetFocus();

	return FALSE;  
}

void XGroupName2::ReloadInterface()
{
	SetWindowText(m_InputSignalPane->GetTranslationString(_T("673"), _T("�޸ķ�������")));
	GetDlgItem(IDOK)->SetWindowText(m_InputSignalPane->GetTranslationString(_T("240"), _T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_InputSignalPane->GetTranslationString(_T("241"), _T("ȡ��")));
	GetDlgItem(IDC_STATIC_GROUPNAME2)->SetWindowText(m_InputSignalPane->GetTranslationString(_T("671"),_T("��������"))+_T(":"));
}

void XGroupName2::InitData()
{
	//GetDlgItem(IDC_EDIT_ANOTHERNAME)->SetWindowText(m_InputSignal->GetAnotherName());
}

CString XGroupName2::GetAnotherName()
{
	return m_AnotherName;
}

void XGroupName2::OnBnClickedOk()
{
	CString szName = _T("");
	GetDlgItem(IDC_EDIT_GROUPNAME2)->GetWindowText(szName);
	szName.Trim();
	if (_T("") == szName)
	{
		m_InputSignalPane->MessageBoxFromKey(_T("217"), _T("���Ʋ���Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_GROUPNAME2)->SetFocus();

		return;
	}

	m_AnotherName=szName;

	if(m_InputSignalPane->IsNameHas(szName))
	{
		m_InputSignalPane->MessageBoxFromKey(_T("672"),_T("�������Ѵ��ڣ�"),MB_OK);

		return;
	}

	CDialogEx::OnOK();
}