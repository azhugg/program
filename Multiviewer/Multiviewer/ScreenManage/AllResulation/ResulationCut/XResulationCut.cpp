#include "stdafx.h"
#include "XResulationCut.h"
#include "..\resource.h"
#include "XScreenManage.h"
#include "XScreen.h"
#include "XAllResulation.h"
#include "XResulationHCutInfo.h"


IMPLEMENT_DYNAMIC(XResulationCut, CDialogEx)

	XResulationCut::XResulationCut(CWnd* pParent /*=NULL*/)
	: CDialogEx(XResulationCut::IDD, pParent)
{
	m_pAllResulation=NULL;
	m_pScreen=NULL;
	m_pScreenManage=NULL;
	m_nResulationIndex=0;
}

XResulationCut::~XResulationCut()
{

}

void XResulationCut::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(XResulationCut, CDialogEx)
	ON_BN_CLICKED(IDOK,&XResulationCut::OnBtnOK)
	ON_BN_CLICKED(IDCANCEL,&XResulationCut::OnBtnCancel)
	ON_EN_CHANGE(IDC_EDIT_RCUT,&XResulationCut::OnSelRightCut)

END_MESSAGE_MAP()



void XResulationCut::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XResulationCut::SetScreen(XScreen*& p)
{
	m_pScreen=p;
}

void XResulationCut::SetParent(XAllResulution* p)
{
	m_pAllResulation=p;
}

void XResulationCut::SetResulationIndex(int n)
{
	m_nResulationIndex=n;
}

BOOL XResulationCut::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	Init();

	InitDate();

	return FALSE; 
}

void XResulationCut::Init()
{

}

void XResulationCut::InitDate()
{
	XResulationHCutInfo* pInfo=m_pScreenManage->GetResulationHCutInfo();
	int nResulationIndex=pInfo->GetResulationIndex();

	XResulationHCutInfo* pInfoOther=m_pAllResulation->GetResulationHCutInfo();

	CString szTemp;

	if(nResulationIndex!=-1
		&&nResulationIndex==m_nResulationIndex)
	{
		szTemp.Format(_T("%d"), pInfo->GetResulationH());
		GetDlgItem(IDC_EDIT_CUR)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfo->GetResulationCut());
		GetDlgItem(IDC_EDIT_RCUT)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfo->GetHFront());
		GetDlgItem(IDC_EDIT_FRONT)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfo->GetHActive());
		GetDlgItem(IDC_EDIT_ACTIVE)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfo->GetHBack());
		GetDlgItem(IDC_EDIT_BACK)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfo->GetHSyn());
		GetDlgItem(IDC_EDIT_SYN)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfo->GetHPolarity());
		GetDlgItem(IDC_EDIT_POLARITY)->SetWindowText(szTemp);
	}
	else
	{
		szTemp.Format(_T("%d"), pInfoOther->GetResulationH());
		GetDlgItem(IDC_EDIT_CUR)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), 0);
		GetDlgItem(IDC_EDIT_RCUT)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfoOther->GetHFront());
		GetDlgItem(IDC_EDIT_FRONT)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfoOther->GetHActive());
		GetDlgItem(IDC_EDIT_ACTIVE)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfoOther->GetHBack());
		GetDlgItem(IDC_EDIT_BACK)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfoOther->GetHSyn());
		GetDlgItem(IDC_EDIT_SYN)->SetWindowText(szTemp);

		szTemp.Format(_T("%d"), pInfoOther->GetHPolarity());
		GetDlgItem(IDC_EDIT_POLARITY)->SetWindowText(szTemp);
	}
}

void XResulationCut::ReloadInterface()
{
	SetWindowText(m_pScreenManage->GetTranslationString(_T("747"), _T("�Ҳ����")));

	GetDlgItem(IDC_STATIC_CURH)->SetWindowText(m_pScreenManage->GetTranslationString(_T("402"),_T("ˮƽ�ֱ���"))+_T(":"));
	GetDlgItem(IDC_STATIC_RCUT)->SetWindowText(m_pScreenManage->GetTranslationString(_T("749"),_T("���зֱ���"))+_T(":"));
	GetDlgItem(IDC_STATIC_FRONT)->SetWindowText(m_pScreenManage->GetTranslationString(_T("405"),_T("ˮƽǰ��"))+_T(":"));
	GetDlgItem(IDC_STATIC_ACTIVE)->SetWindowText(m_pScreenManage->GetTranslationString(_T("406"),_T("ˮƽ�����"))+_T(":"));
	GetDlgItem(IDC_STATIC_BACK)->SetWindowText(m_pScreenManage->GetTranslationString(_T("407"),_T("ˮƽ����"))+_T(":"));
	GetDlgItem(IDC_STATIC_SYN)->SetWindowText(m_pScreenManage->GetTranslationString(_T("408"),_T("ˮƽͬ�����"))+_T(":"));
	GetDlgItem(IDC_STATIC_POLARITY)->SetWindowText(m_pScreenManage->GetTranslationString(_T("409"),_T("ˮƽͬ������"))+_T(":"));
	GetDlgItem(IDC_STATIC_TIPS102)->SetWindowText(m_pScreenManage->GetTranslationString(_T("750"),_T("��ʾ:���зֱ���Ϊ�Ҳ���Ļˮƽ�ֱ���С��������Ļ�ֱ���ʱ�����ķֱ���")));
	
	
	GetDlgItem(IDOK)->SetWindowText(m_pScreenManage->GetTranslationString(_T("208"),_T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pScreenManage->GetTranslationString(_T("209"),_T("ȡ��")));  
}

void XResulationCut::OnSelRightCut()
{
	XResulationHCutInfo* pInfo=m_pAllResulation->GetResulationHCutInfo();	
	int nCur=pInfo->GetResulationH();
	int nFront=pInfo->GetHFront();
	int nBack=pInfo->GetHBack();
	int nActive=pInfo->GetHActive();

	CString szCut;
	GetDlgItem(IDC_EDIT_RCUT)->GetWindowText(szCut);
	int nCut=_ttoi(szCut);

	int nTempResulation=nCur-nCut;
	int nTemp=nCut/2;

	CString szActive;
	szActive.Format(_T("%d"),nTempResulation);
	GetDlgItem(IDC_EDIT_ACTIVE)->SetWindowText(szActive);

	CString szChange;
	szChange.Format(_T("%d"),nTempResulation);
	GetDlgItem(IDC_EDIT_CUR)->SetWindowText(szChange);

	CString szChangeFront;
	szChangeFront.Format(_T("%d"),nFront+nTemp);
	GetDlgItem(IDC_EDIT_FRONT)->SetWindowText(szChangeFront);

	CString szChangeBack;
	szChangeBack.Format(_T("%d"),nBack+nTemp);
	GetDlgItem(IDC_EDIT_BACK)->SetWindowText(szChangeBack);
}

void XResulationCut::OnBtnOK()
{
	CString szHResulation;
	GetDlgItem(IDC_EDIT_CUR)->GetWindowText(szHResulation);
	szHResulation.Trim();
	if(szHResulation==_T(""))
	{
		m_pScreenManage->MessageBoxFromKey(_T("417"),_T("ˮƽ�ֱ��ʲ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_CUR)->SetFocus();
		return;
	}
	int nResolutionH=_ttoi(szHResulation);
	//////////////////////////////////////////////////////////////////////////
	CString szResulationCut;
	GetDlgItem(IDC_EDIT_RCUT)->GetWindowText(szResulationCut);
	szResulationCut.Trim();
	//if(szHResulation==_T(""))
	//{
	//	m_pScreenManage->MessageBoxFromKey(_T("417"),_T("ˮƽ�ֱ��ʲ���Ϊ�գ�"),MB_OK);
	//	GetDlgItem(IDC_EDIT_CUR)->SetFocus();
	//	return;
	//}
	int nResulationCut=_ttoi(szResulationCut);
	//////////////////////////////////////////////////////////////////////////
	CString szHFProch;
	GetDlgItem(IDC_EDIT_FRONT)->GetWindowText(szHFProch);
	if(szHFProch==_T(""))
	{
		m_pScreenManage->MessageBoxFromKey(_T("420"),_T("ˮƽǰ�ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_FRONT)->SetFocus();
		return;
	}
	int nHFPorch=_ttoi(szHFProch);
	//////////////////////////////////////////////////////////////////////////
	CString szHpixel;
	GetDlgItem(IDC_EDIT_ACTIVE)->GetWindowText(szHpixel);
	if(szHpixel==_T(""))
	{
		m_pScreenManage->MessageBoxFromKey(_T("422"),_T("ˮƽ����ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_ACTIVE)->SetFocus();
		return;
	}
	int nHpixel=_ttoi(szHpixel);
	//////////////////////////////////////////////////////////////////////////
	CString szHBForch;
	GetDlgItem(IDC_EDIT_BACK)->GetWindowText(szHBForch);
	if(szHBForch==_T(""))
	{
		m_pScreenManage->MessageBoxFromKey(_T("424"),_T("ˮƽ���ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_BACK)->SetFocus();
		return;
	}
	int nHBPorch=_ttoi(szHBForch);
	//////////////////////////////////////////////////////////////////////////
	CString szHSyncTime;
	GetDlgItem(IDC_EDIT_SYN)->GetWindowText(szHSyncTime);
	if(szHSyncTime==_T(""))
	{
		m_pScreenManage->MessageBoxFromKey(_T("426"),_T("ˮƽͬ����Ȳ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_SYN)->SetFocus();
		return;
	}
	int nHSyncTime=_ttoi(szHSyncTime);
	//////////////////////////////////////////////////////////////////////////
	CString szHSyncPolarity;
	GetDlgItem(IDC_EDIT_POLARITY)->GetWindowText(szHSyncPolarity);
	if(szHSyncPolarity==_T(""))
	{
		m_pScreenManage->MessageBoxFromKey(_T("428"),_T("ˮƽͬ�����Բ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_POLARITY)->SetFocus();
		return;
	}
	int nHSyncPolarity=_ttoi(szHSyncPolarity);

	//////////////////////////////////////////////////////////////////////////
	XResulationHCutInfo* pInfo=m_pScreenManage->GetResulationHCutInfo();
	pInfo->SetResulationH(nResolutionH);
	pInfo->SetResulationCut(nResulationCut);
	pInfo->SetHFront(nHFPorch);
	pInfo->SetHActive(nHpixel);
	pInfo->SetHBack(nHBPorch);
	pInfo->SetHSyn(nHSyncTime);
	pInfo->SetHPolarity(nHSyncPolarity);
	pInfo->SetResulationIndex(m_nResulationIndex);
	//////////////////////////////////////////////////////////////////////////
	CString szRCut;
	GetDlgItem(IDC_EDIT_RCUT)->GetWindowText(szRCut);
	int nRCut=_ttoi(szRCut);

	if(nRCut==0)
		m_pAllResulation->SetRCutStatus(FALSE);
	else
		m_pAllResulation->SetRCutStatus(TRUE);

	CDialogEx::OnOK();
}

void XResulationCut::OnBtnCancel()
{
	m_pAllResulation->SetRCutStatus(FALSE);

	CDialogEx::OnCancel();
}
