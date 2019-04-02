#include "stdafx.h"
#include "XSetOSD.h"
#include "afxdialogex.h"
#include "XScreenManage.h"
#include "XDelegateSelectEquipment.h"
#include "XInputSignal.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XSetOSD, CDialogEx)

	XSetOSD::XSetOSD(CWnd* pParent /*=NULL*/)
	: CDialogEx(XSetOSD::IDD, pParent)
{
	m_pScreenManage=NULL;

	m_nInputIndex=0;
}

XSetOSD::~XSetOSD()
{

}

void XSetOSD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_SCREENINDEX, m_Combo_ScreenIndex);
}


BEGIN_MESSAGE_MAP(XSetOSD, CDialogEx)
	ON_BN_CLICKED( IDOK, &XSetOSD::OnBtnOK)
END_MESSAGE_MAP()


void XSetOSD::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

// CAddExpandDlg ��Ϣ�������

BOOL XSetOSD::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitCombo();

	return FALSE;  
}

void XSetOSD::ReloadInterface()
{
	SetWindowText(m_pScreenManage->GetTranslationString(_T("567"),_T("����OSD")));

	GetDlgItem(IDOK)->SetWindowText(m_pScreenManage->GetTranslationString(_T("208"),_T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pScreenManage->GetTranslationString(_T("209"),_T("ȡ��")));

	GetDlgItem(IDC_STATIC_SCREENNUM)->SetWindowText(m_pScreenManage->GetTranslationString(_T("590"),_T("�������"))+_T(":"));
	//GetDlgItem(IDC_STATIC_TIMEDTIPS)->SetWindowText(m_pDelegate->GetTranslationString(_T("466"),_T("��ʾ:��λΪ���룬��Сʱ����Ϊ50���룡")));
}

void XSetOSD::InitCombo()
{
	int nInputIndex=m_nInputIndex;

	VEC_INPUTSIGNAL& VecInput=m_pScreenManage->GetVecInputSignal();

	for(VEC_INPUTSIGNAL::iterator iter=VecInput.begin();iter!=VecInput.end();++iter)
	{
		XInputSignal* pInput=*iter;

		int nInput=pInput->GetInputIndex();

		int nIndex=(nInput-1)/4;
		int nIndex2=(nInput-1)%4;

		BOOL bIsUltra=pInput->GetIsUltra();

		if(bIsUltra)
		{
			if(nInputIndex-1==nIndex
				&&nIndex2==0)
			{
				CString szStr;
				szStr.Format(_T("%d"),nInput);
				m_Combo_ScreenIndex.AddString(szStr);	
			}
		}
		else
		{
			if(nInputIndex-1==nIndex)
			{
				CString szStr;
				szStr.Format(_T("%d"),nInput);
				m_Combo_ScreenIndex.AddString(szStr);	
			}
		}
	}

	m_Combo_ScreenIndex.SetCurSel(0);
}

int XSetOSD::GetOSDIndex()
{
	return m_nOSDIndex;
}

void XSetOSD::SetInputIndex(int n)
{
	m_nInputIndex=n;
}

int XSetOSD::GetInputIndex()
{
	return m_nInputIndex;
}

void XSetOSD::OnBtnOK()
{
	int nScreenNum=m_Combo_ScreenIndex.GetCurSel();

	CString szStr;

	m_Combo_ScreenIndex.GetLBText(nScreenNum,szStr);

	m_nOSDIndex=_ttoi(szStr);

	CDialogEx::OnOK();
}