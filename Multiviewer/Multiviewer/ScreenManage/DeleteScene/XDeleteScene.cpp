#include "stdafx.h"
#include "XDeleteScene.h"
#include "afxdialogex.h"
#include "XDelegateDeleteScene.h"
#include "XScreen.h"
#include "XScreenManage.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XDeleteSceneDlg, CDialogEx)

	XDeleteSceneDlg::XDeleteSceneDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(XDeleteSceneDlg::IDD, pParent)
{
	m_pDelegate = NULL;
}

XDeleteSceneDlg::~XDeleteSceneDlg()
{

}

void XDeleteSceneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_DELINDEX, m_ComboBox_DelIndex);
}


BEGIN_MESSAGE_MAP(XDeleteSceneDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &XDeleteSceneDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XDeleteSceneDlg::SetDelegate(XDelegateDeleteSceneDlg* p)
{
	m_pDelegate = p;
}

void XDeleteSceneDlg::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XDeleteSceneDlg::SetScreen(XScreen* p)
{
	m_pScreen=p;
}

void XDeleteSceneDlg::SetData(char* pData)
{
	int nIndex=0;
	memcpy(&nIndex,pData+8,4);

	for(int i=0;i<32;i++)
	{
		if(nIndex&(1<<i))
		{
			m_Index[i]=1;
		}
		else
		{
			m_Index[i]=0;
		}
	}
}

BOOL XDeleteSceneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitCombo();

	return FALSE;  
}

void XDeleteSceneDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("495"),_T("ɾ������")));

	GetDlgItem(IDC_STATIC_SCENEINDEX)->SetWindowText(m_pDelegate->GetTranslationString(_T("389"), _T("���")) + _T(":"));
	GetDlgItem(IDC_STATIC_TIPS)->SetWindowText(m_pDelegate->GetTranslationString(_T("496"), _T("��ʾ:ɾ���ĳ���ΪFPGA���泡�������������ļ���ֱ�Ӹ��ǣ�Ϊ�մ���û�б��泡����")));
}

void XDeleteSceneDlg::InitCombo()
{
	int nComboIndex=0;

	for(int i=0;i<32;i++)
	{
		nComboIndex++;

		if(m_Index[i]==1)
		{
			CString szIndex;

			szIndex.Format(_T("%d"),nComboIndex);

			m_ComboBox_DelIndex.AddString(szIndex);
		}
	}

	m_ComboBox_DelIndex.SetCurSel(0);
}

void XDeleteSceneDlg::SetDelIndex(int n)
{
	m_DelIndex=n;
}

int XDeleteSceneDlg::GetDelIndex()
{
	return m_DelIndex;
}

void XDeleteSceneDlg::OnBnClickedOk()
{
	CString szIndex;

	m_ComboBox_DelIndex.GetLBText(m_ComboBox_DelIndex.GetCurSel(),szIndex);

	m_DelIndex=_ttoi(szIndex);

	CDialogEx::OnOK();
}