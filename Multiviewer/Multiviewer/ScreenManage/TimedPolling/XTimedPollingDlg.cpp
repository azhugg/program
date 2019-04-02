#include "stdafx.h"
#include "XTimedPollingDlg.h"
#include "afxdialogex.h"
#include "XDelegateTimedPollingDlg.h"
#include "XScreen.h"
#include "XScreenManage.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XTimedPollingDlg, CDialogEx)

	XTimedPollingDlg::XTimedPollingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(XTimedPollingDlg::IDD, pParent)
{
	m_pDelegate = NULL;

}

XTimedPollingDlg::~XTimedPollingDlg()
{

}

void XTimedPollingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(XTimedPollingDlg, CDialogEx)
	ON_BN_CLICKED( IDOK, &XTimedPollingDlg::OnBtnOK)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XTimedPollingDlg::SetDelegate(XDelegateTimedPollingDlg* p)
{
	m_pDelegate = p;
}

void XTimedPollingDlg::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XTimedPollingDlg::SetScreen(XScreen* p)
{
	m_pScreen=p;
}

BOOL XTimedPollingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitData();

	return FALSE;  
}

void XTimedPollingDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("464"),_T("��ʱ��ѯ���")));

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("208"),_T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("209"),_T("ȡ��")));

	GetDlgItem(IDC_STATIC_TIMEDPOLLING)->SetWindowText(m_pDelegate->GetTranslationString(_T("465"),_T("ʱ����"))+_T(":"));
	GetDlgItem(IDC_STATIC_TIMEDTIPS)->SetWindowText(m_pDelegate->GetTranslationString(_T("466"),_T("��ʾ:��λΪ���룬��Сʱ����Ϊ50���룡")));
}

void XTimedPollingDlg::InitData()
{
	XTimedPollingInfo* pPollingInfo=m_pScreenManage->GetTimedPollingInfo();

	CString szTemp;

	szTemp.Format(_T("%d"), pPollingInfo->GetTimedPolling());
	GetDlgItem(IDC_EDIT_TIMEDPOLLING)->SetWindowText(szTemp);
}

void XTimedPollingDlg::OnBtnOK()
{
	CString szTimedPolling;
	GetDlgItem(IDC_EDIT_TIMEDPOLLING)->GetWindowText(szTimedPolling);
	szTimedPolling.Trim();
	if(szTimedPolling==_T(""))
	{
		m_pDelegate->MessageBoxFromKey(_T("417"),_T("ˮƽ�ֱ��ʲ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_TIMEDPOLLING)->SetFocus();
		return;
	}
	int nTimedPolling=_ttoi(szTimedPolling);

	if(nTimedPolling<50)
	{
		m_pDelegate->MessageBoxFromKey(_T("467"),_T("��ʱ��ѯʱ��������С��50���룡"),MB_OK);
		return;
	}

	XTimedPollingInfo* pPollingInfo=m_pScreenManage->GetTimedPollingInfo();
	pPollingInfo->SetTimePolling(nTimedPolling);

	CDialogEx::OnOK();
}