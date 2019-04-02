#include "stdafx.h"
#include "XNewViewDlg.h"
#include "afxdialogex.h"
#include "XDelegateNewViewDlg.h"
#include "XInternalManage.h"
#include "XBaseScreenManage.h"
#include "XMenuScreenSetInfo.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XNewViewDlg, CDialogEx)

	XNewViewDlg::XNewViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(XNewViewDlg::IDD, pParent)
{
	m_pDelegate = NULL;

	m_BeginIndex=1;

	m_nScreenModel=0;
}

XNewViewDlg::~XNewViewDlg()
{

}

void XNewViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SCREENMODEL, m_Combox_Model);
}


BEGIN_MESSAGE_MAP(XNewViewDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &XNewViewDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XNewViewDlg::SetDelegate(XDelegateNewViewDlg* p)
{
	m_pDelegate = p;
}

void XNewViewDlg::SetBaseManage(XInternalManage* p)
{
	m_pBaseManage=p;
}

void XNewViewDlg::SetViewName(CString s)
{
	m_ViewName=s;
}

CString XNewViewDlg::GetViewName()
{
	return m_ViewName;
}

int XNewViewDlg::GetBeginIndex()
{
	return m_BeginIndex;
}

int XNewViewDlg::GetScreenModel()
{
	return m_nScreenModel;
}

BOOL XNewViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitCombo();

	InitData();

	return FALSE;  
}

void XNewViewDlg::InitData()
{
	CString szIndex;
	szIndex.Format(_T("%d"),1);
	GetDlgItem(IDC_EDIT_SCREENINDEX)->SetWindowText(szIndex);
}

void XNewViewDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("498"), _T("�½�ƴ����")));

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("268"), _T("����")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("215"), _T("ȡ��")));
	GetDlgItem(IDC_STATIC_SCREENINDEX)->SetWindowText(m_pDelegate->GetTranslationString(_T("539"), _T("��Ļ��ʼ���")) + _T(":"));
	GetDlgItem(IDC_STATIC_VIEWNAME)->SetWindowText(m_pDelegate->GetTranslationString(_T("390"), _T("����")) + _T(":"));
}

void XNewViewDlg::InitCombo()
{
	m_Combox_Model.AddString(m_pBaseManage->GetTranslationString(_T("697"),_T("ƴ��ģʽ")));
	m_Combox_Model.AddString(m_pBaseManage->GetTranslationString(_T("696"),_T("����ģʽ")));
	
	m_Combox_Model.SetCurSel(0);
}

void XNewViewDlg::OnBnClickedOk()
{
	int nSelect=m_Combox_Model.GetCurSel();

	if(nSelect==0)
	{	
		m_nScreenModel=SCREENMODEL_SPLIC;
	}
	else if(nSelect==1)
	{
		m_nScreenModel=SCREENMODEL_MATRIX;
	}

	//������Ļģʽ
	XMenuScreenSetInfo* pInfo=m_pDelegate->GetMenuScreenSetInfo();
	pInfo->SetScreenModel(m_nScreenModel);
	//*******************
	CString szName = _T("");
	GetDlgItem(IDC_EDIT_VIEWNAME)->GetWindowText(szName);
	szName.Trim();
	if (_T("")==szName)
	{
		m_pDelegate->MessageBoxFromKey(_T("521"), _T("��ͼ���Ʋ���Ϊ��,������!"), MB_OK);
		GetDlgItem(IDC_EDIT_VIEWNAME)->SetFocus();
		return;
	}

	VEC_BASESCREENMANAGE& VecBaseManage=m_pBaseManage->GetBaseManage();

	for(VEC_BASESCREENMANAGE::iterator iter=VecBaseManage.begin();iter!=VecBaseManage.end();iter++)
	{
		XBaseScreenManage* pBase=*iter;

		if(szName==pBase->GetViewName())
		{
			m_pDelegate->MessageBoxFromKey(_T("526"), _T("��ͼ���Ʋ����ظ�,����������!"), MB_OK);
			GetDlgItem(IDC_EDIT_VIEWNAME)->SetFocus();
			return;
		}
	}

	m_ViewName=szName;
	//*******************
	CString szIndex;
	GetDlgItem(IDC_EDIT_SCREENINDEX)->GetWindowText(szIndex);
	szIndex.Trim();
	if (_T("")==szIndex)
	{
		m_pDelegate->MessageBoxFromKey(_T("523"), _T("��Ļ��ʼ��Ų���Ϊ�գ������룡"), MB_OK);
		GetDlgItem(IDC_EDIT_SCREENINDEX)->SetFocus();
		return;
	}
	m_BeginIndex=_ttoi(szIndex);

	CDialogEx::OnOK();
}