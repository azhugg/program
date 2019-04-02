#include "stdafx.h"
#include "XSelectEquipment.h"
#include "afxdialogex.h"
#include "XDelegateSelectEquipment.h"
#include "XScreen.h"
#include "XScreenManage.h"
#include "HandlePath.h"
#include "XMenuScreenSetInfo.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XSelectEquipment, CDialogEx)

	XSelectEquipment::XSelectEquipment(CWnd* pParent /*=NULL*/)
	: CDialogEx(XSelectEquipment::IDD, pParent)
{
	m_pDelegate = NULL;

	m_bIsMenuSet=FALSE;
}

XSelectEquipment::~XSelectEquipment()
{

}

void XSelectEquipment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_EQUIPMENT, m_Combo_Equipment);

}


BEGIN_MESSAGE_MAP(XSelectEquipment, CDialogEx)
	ON_BN_CLICKED( IDOK, &XSelectEquipment::OnBtnOK)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XSelectEquipment::SetDelegate(XDelegateSelectEquipment* p)
{
	m_pDelegate = p;
}

void XSelectEquipment::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XSelectEquipment::SetScreen(XScreen* p)
{
	m_pScreen=p;
}

BOOL XSelectEquipment::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitComoboBox();

	InitData();

	return FALSE;  
}

void XSelectEquipment::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("556"),_T("������-ѡ���豸����")));

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("208"),_T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("209"),_T("ȡ��")));

	GetDlgItem(IDC_STATIC_EQUIPMENT)->SetWindowText(m_pDelegate->GetTranslationString(_T("557"),_T("�豸����"))+_T(":"));
	//GetDlgItem(IDC_STATIC_TIMEDTIPS)->SetWindowText(m_pDelegate->GetTranslationString(_T("466"),_T("��ʾ:��λΪ���룬��Сʱ����Ϊ50���룡")));
}

void XSelectEquipment::InitComoboBox()
{
	m_Combo_Equipment.AddString(m_pDelegate->GetTranslationString(_T("558"),_T("16��")));
	m_Combo_Equipment.AddString(m_pDelegate->GetTranslationString(_T("559"),_T("32��")));
	m_Combo_Equipment.AddString(m_pDelegate->GetTranslationString(_T("560"),_T("64��")));
	m_Combo_Equipment.AddString(m_pDelegate->GetTranslationString(_T("561"),_T("72��")));
	m_Combo_Equipment.AddString(m_pDelegate->GetTranslationString(_T("562"),_T("144��")));

	m_Combo_Equipment.SetCurSel(0);
}

int XSelectEquipment::GetEquipment()
{
	return m_nEquipment;
}

void XSelectEquipment::SetEquipment(int n)
{
	m_nEquipment=n;
}

void XSelectEquipment::SetIsMenuSet(BOOL b)
{
	m_bIsMenuSet=b;
}

void XSelectEquipment::InitData()
{
	if(m_bIsMenuSet)
	{
		XMenuScreenSetInfo* pScreenSetInfo=m_pScreenManage->GetMenuScreenSetInfo();

		m_Combo_Equipment.SetCurSel(pScreenSetInfo->GetCheck());
	}
}


void XSelectEquipment::OnBtnOK()
{
	XMenuScreenSetInfo* pScreenSetInfo=m_pScreenManage->GetMenuScreenSetInfo();

	int n=m_Combo_Equipment.GetCurSel();

	pScreenSetInfo->SetCheck(n);

	if(n==0)
	{
		m_nEquipment=16;
	}
	else if(n==1)
	{
		m_nEquipment=32;
	}
	else if(n==2)
	{
		m_nEquipment=64;
	}
	else if(n==3)
	{
		m_nEquipment=72;
	}
	else if(n==4)
	{
		m_nEquipment=144;
	}

	CDialogEx::OnOK();
}