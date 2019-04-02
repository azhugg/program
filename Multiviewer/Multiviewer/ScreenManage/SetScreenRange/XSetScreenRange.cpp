#include "stdafx.h"
#include "XSetScreenRange.h"
#include "afxdialogex.h"
#include "XDelegateTimedPollingDlg.h"
#include "XScreen.h"
#include "XScreenManage.h"
#include "XDelegateScreenManage.h"
#include "XMenuScreenSetInfo.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XSetScreenRange, CDialogEx)

	XSetScreenRange::XSetScreenRange(CWnd* pParent /*=NULL*/)
	: CDialogEx(XSetScreenRange::IDD, pParent)
{
	m_pDelegate = NULL;

	m_nEquipmentNum=0;

	m_nScreenNumH=0;

	m_nScreenNumV=0;

	m_bIsMenuSet=FALSE;
}

XSetScreenRange::~XSetScreenRange()
{

}

void XSetScreenRange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(XSetScreenRange, CDialogEx)
	ON_BN_CLICKED( IDOK, &XSetScreenRange::OnBtnOK)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XSetScreenRange::SetDelegate(XDelegateSetScreenRange* p)
{
	m_pDelegate = p;
}

void XSetScreenRange::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XSetScreenRange::SetScreen(XScreen* p)
{
	m_pScreen=p;
}

void XSetScreenRange::SetIsMenuSet(BOOL b)
{
	m_bIsMenuSet=b;
}

BOOL XSetScreenRange::GetIsMenuSet()
{
	return m_bIsMenuSet;
}

BOOL XSetScreenRange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitData();

	return FALSE;  
}

void XSetScreenRange::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("592"),_T("������-��Ļ����")));

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("208"),_T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("209"),_T("ȡ��")));

	GetDlgItem(IDC_STATIC_OUTNUMH)->SetWindowText(m_pDelegate->GetTranslationString(_T("341"),_T("ˮƽ�������"))+_T(":"));
	GetDlgItem(IDC_STATIC_OUTNUMV)->SetWindowText(m_pDelegate->GetTranslationString(_T("340"),_T("��ֱ�������"))+_T(":"));
}

void XSetScreenRange::InitData()
{
	if(m_bIsMenuSet)
	{
		XMenuScreenSetInfo* pInfo=m_pScreenManage->GetMenuScreenSetInfo();

		int nScreenH=pInfo->GetScreenCountH();

		CString szScreenH=_T("");
		szScreenH.Format(_T("%d"),nScreenH);
		GetDlgItem(IDC_EDIT_OUTNUMH)->SetWindowText(szScreenH);

		int nScreenV=pInfo->GetScreenCountV();

		CString szScreenV=_T("");
		szScreenV.Format(_T("%d"),nScreenV);
		GetDlgItem(IDC_EDIT_OUTNUMV)->SetWindowText(szScreenV);
	}
}

void XSetScreenRange::OnBtnOK()
{
	CString szStr;
	GetDlgItem(IDC_EDIT_OUTNUMH)->GetWindowText(szStr);
	szStr.Trim();
	if(szStr==_T(""))
	{
		m_pDelegate->MessageBoxFromKey(_T("584"),_T("ˮƽ��Ļ��������Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_OUTNUMH)->SetFocus();
		return;
	}
	m_nScreenNumH=_ttoi(szStr);

	GetDlgItem(IDC_EDIT_OUTNUMV)->GetWindowText(szStr);
	szStr.Trim();
	if(szStr==_T(""))
	{
		m_pDelegate->MessageBoxFromKey(_T("585"),_T("��ֱ��Ļ��������Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_OUTNUMV)->SetFocus();
		return;
	}
	m_nScreenNumV=_ttoi(szStr);

	//////////////////////////////////////////////////////////////////////////

	XMenuScreenSetInfo* pInfo=m_pScreenManage->GetMenuScreenSetInfo();

	pInfo->SetScreenCountH(m_nScreenNumH);
	pInfo->SetScreenCountV(m_nScreenNumV);

	CDialogEx::OnOK();
}

//////////////////////////////////////////////////////////////////////////

void XSetScreenRange::SetEquipmentNum(int n)
{
	m_nEquipmentNum=n;
}

int XSetScreenRange::GetEquipmentNum()
{
	return m_nEquipmentNum;
}

void XSetScreenRange::SetScreenNumH(int n)
{
	m_nScreenNumH=n;
}

int XSetScreenRange::GetScreenNumH()
{
	return m_nScreenNumH;
}

void XSetScreenRange::SetScreenNumV(int n)
{
	m_nScreenNumV=n;
}

int XSetScreenRange::GetScreenNumV()
{
	return m_nScreenNumV;
}