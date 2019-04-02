#include "stdafx.h"
#include "XCorrespondScreen.h"
#include "afxdialogex.h"
#include "XEquipmentOutput.h"
#include "XDelegateSelectEquipment.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XCorrespondScreen, CDialogEx)

	XCorrespondScreen::XCorrespondScreen(CWnd* pParent /*=NULL*/)
	: CDialogEx(XCorrespondScreen::IDD, pParent)
{
	m_pEquipmentOutput=NULL;

	m_nScreenIndex1=0;

	m_nScreenIndex2=0;
}

XCorrespondScreen::~XCorrespondScreen()
{

}

void XCorrespondScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_CORRSCREEN, m_Combo_Correspond);
}


BEGIN_MESSAGE_MAP(XCorrespondScreen, CDialogEx)
	ON_BN_CLICKED( IDOK, &XCorrespondScreen::OnBtnOK)
	ON_CBN_SELCHANGE(IDC_COMBO_CORRSCREEN, &XCorrespondScreen::OnSelchange)
END_MESSAGE_MAP()


void XCorrespondScreen::SetEquipmentOutputWnd(XEquipmentOutput* p)
{
	m_pEquipmentOutput=p;
}

// CAddExpandDlg ��Ϣ�������

BOOL XCorrespondScreen::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	GetDlgItem(IDC_EDIT_CORRSCREEN2)->EnableWindow(FALSE);

	InitCombo();

	return FALSE;  
}

void XCorrespondScreen::ReloadInterface()
{
	SetWindowText(m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->GetTranslationString(_T("570"),_T("ƥ����Ļ")));

	GetDlgItem(IDOK)->SetWindowText(m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->GetTranslationString(_T("208"),_T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->GetTranslationString(_T("209"),_T("ȡ��")));

	GetDlgItem(IDC_STATIC_SCREENNUM)->SetWindowText(m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->GetTranslationString(_T("569"),_T("ƥ����Ļ����"))+_T(":"));
	//GetDlgItem(IDC_STATIC_TIMEDTIPS)->SetWindowText(m_pDelegate->GetTranslationString(_T("466"),_T("��ʾ:��λΪ���룬��Сʱ����Ϊ50���룡")));
}

void XCorrespondScreen::InitCombo()
{
	CString szStr;

	for(int i=1;i<3;i++)
	{
		szStr.Format(_T("%d"),i);

		m_Combo_Correspond.AddString(szStr);
	}

	m_Combo_Correspond.SetCurSel(0);
}

void XCorrespondScreen::OnSelchange()
{
	int nScreenNum=m_Combo_Correspond.GetCurSel();

	if(nScreenNum==0)
	{
		GetDlgItem(IDC_EDIT_CORRSCREEN2)->EnableWindow(FALSE);
	}

	if(nScreenNum==1)
	{
		GetDlgItem(IDC_EDIT_CORRSCREEN2)->EnableWindow(TRUE);
	}
}

int XCorrespondScreen::GetScreenNum()
{
	return m_nScreenNum;
}

int XCorrespondScreen::GetScreenIndex1()
{
	return m_nScreenIndex1;
}

int XCorrespondScreen::GetScreenIndex2()
{
	return m_nScreenIndex2;
}

void XCorrespondScreen::OnBtnOK()
{
	int nScreenNum=m_Combo_Correspond.GetCurSel();

	m_nScreenNum=nScreenNum+1;

	CString szStr;
	GetDlgItem(IDC_EDIT_CORRSCREEN)->GetWindowText(szStr);
	if(szStr==_T(""))
	{
		m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->MessageBoxFromKey(_T("573"),_T("��Ļ1��Ų���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_CORRSCREEN)->SetFocus();
		return;
	}
	m_nScreenIndex1=_ttoi(szStr);

	if(m_nScreenIndex1<=0)
	{
		m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->MessageBoxFromKey(_T("582"),_T("��Ļ���ӦΪ������"),MB_OK);

		return;
	}

	if(CheckIndex(m_nScreenIndex1))
	{
		m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->MessageBoxFromKey(_T("575"),_T("��Ļ1����ظ������������룡"),MB_OK);

		return;
	}
	
	if(nScreenNum==1)
	{
		GetDlgItem(IDC_EDIT_CORRSCREEN2)->GetWindowText(szStr);
		if(szStr==_T(""))
		{
			m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->MessageBoxFromKey(_T("574"),_T("��Ļ2��Ų���Ϊ�գ�"),MB_OK);
			GetDlgItem(IDC_EDIT_CORRSCREEN2)->SetFocus();
			return;
		}
		m_nScreenIndex2=_ttoi(szStr);

		if(m_nScreenIndex2<=0)
		{
			m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->MessageBoxFromKey(_T("582"),_T("��Ļ���ӦΪ������"),MB_OK);

			return;
		}

		if(CheckIndex(m_nScreenIndex2))
		{
			m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->MessageBoxFromKey(_T("576"),_T("��Ļ2����ظ������������룡"),MB_OK);

			return;
		}
	}

	if(m_nScreenIndex1==m_nScreenIndex2)
	{
		m_pEquipmentOutput->GetOutputBoardChild()->GetDelegate()->MessageBoxFromKey(_T("577"),_T("��Ļ����ظ������������룡"),MB_OK);

		return;
	}


	CDialogEx::OnOK();
}

BOOL XCorrespondScreen::CheckIndex(int nIndex)
{
	VEC_EQUIPMENTOUTPUT& VecOptput=m_pEquipmentOutput->GetOutputBoardChild()->GetVecEquipmentOutput();

	for(VEC_EQUIPMENTOUTPUT::iterator iter=VecOptput.begin();iter!=VecOptput.end();++iter)
	{
		XEquipmentOutput* pOutput=*iter;

		int nIndex1=pOutput->GetScreenIndex();
		int nIndex2=pOutput->GetScreenIndex2();

		if(nIndex==nIndex1
			||nIndex==nIndex2)
		{
			return TRUE;
		}
	}

	return FALSE;
}