#include "stdafx.h"
#include "XInputSignalCutDlg.h"
#include "afxdialogex.h"
#include "XDelegateInputSignalCutDlg.h"
#include "XInputSignal.h"
#include "XSendDataInputSignal.h"
#include "XInputSignalExpand.h"

// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XInputSignalCutDlg, CDialogEx)

	XInputSignalCutDlg::XInputSignalCutDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(XInputSignalCutDlg::IDD, pParent)
{
	m_pDelegate = NULL;

	m_InputSignal=NULL;

	m_InputSignalPane=NULL;

	m_LTX=0;

	m_LTY=0;

	m_RBX=0;

	m_RBY=0;
}

XInputSignalCutDlg::~XInputSignalCutDlg()
{

}

void XInputSignalCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(XInputSignalCutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &XInputSignalCutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XInputSignalCutDlg::SetDelegate(XDelegateInputSignalCutDlg* p)
{
	m_pDelegate = p;
}

void XInputSignalCutDlg::SetInputSignal(XInputSignal* p)
{
	m_InputSignal = p;
}

void XInputSignalCutDlg::SetInputSignalPane(XInputSignalPane* p)
{
	m_InputSignalPane = p;
}

void XInputSignalCutDlg::SetInputSignalName(CString s)
{
	m_InputSignalName = s;
}

BOOL XInputSignalCutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitData();

	return FALSE;  
}

void XInputSignalCutDlg::InitData()
{
	CString szTemp=_T("");

	XSignalCutInfo* pInfo=m_InputSignal->GetDefaultCutInfo();

	szTemp.Format(_T("%d"), pInfo->GetSignalCutX1());
	GetDlgItem(IDC_EDIT_LTX)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetSignalCutY1());
	GetDlgItem(IDC_EDIT_LTY)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetSignalCutX2());
	GetDlgItem(IDC_EDIT_RBX)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetSignalCutY2());
	GetDlgItem(IDC_EDIT_RBY)->SetWindowText(szTemp);

	VEC_INPUTSIGNAL& VecInputSignal=m_InputSignalPane->GetVecInputSignal();
	int nIndex=m_InputSignal->GetInputIndex();
	for(VEC_INPUTSIGNAL::iterator iter=VecInputSignal.begin();iter!=VecInputSignal.end();++iter)
	{
		XInputSignal* pInputSignal=*iter;
		if(nIndex==pInputSignal->GetInputIndex())
		{
			int m=pInputSignal->GetReResulationH()+pInfo->GetSignalCutX1()+pInfo->GetSignalCutY1();

			CString Temp=_T("");
			Temp.Format(_T("%d"), m);
			GetDlgItem(IDC_EDIT_H)->SetWindowText(Temp);

			int n=pInputSignal->GetReResulationV()+pInfo->GetSignalCutX2()+pInfo->GetSignalCutY2();
			Temp.Format(_T("%d"), n);
			GetDlgItem(IDC_EDIT_V)->SetWindowText(Temp);
		}
	}
}

void XInputSignalCutDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("431"), _T("��������ü�����"))+ _T(" - ") + m_InputSignalName);

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("214"), _T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("215"), _T("ȡ��")));

	GetDlgItem(IDC_STATIC_LTX)->SetWindowText(m_pDelegate->GetTranslationString(_T("450"), _T("���ü�")) + _T(":"));
	GetDlgItem(IDC_STATIC_LTY)->SetWindowText(m_pDelegate->GetTranslationString(_T("451"), _T("�Ҳ�ü�")) + _T(":"));
	GetDlgItem(IDC_STATIC_RBX)->SetWindowText(m_pDelegate->GetTranslationString(_T("452"), _T("�ϲ�ü�")) + _T(":"));
	GetDlgItem(IDC_STATIC_RBY)->SetWindowText(m_pDelegate->GetTranslationString(_T("453"), _T("�²�ü�")) + _T(":"));
	GetDlgItem(IDC_STATIC_RESH)->SetWindowText(m_pDelegate->GetTranslationString(_T("402"), _T("ˮƽ�ֱ���")) + _T(":"));
	GetDlgItem(IDC_STATIC_RESV)->SetWindowText(m_pDelegate->GetTranslationString(_T("403"), _T("��ֱ�ֱ���")) + _T(":"));

	GetDlgItem(IDC_STATIC_NOTICE)->SetWindowText(m_pDelegate->GetTranslationString(_T("454"), _T("��ʾ:�������Ϊ�ü����Ĳ��֣�ȫ��������ֵȫΪ0��")));
}

void XInputSignalCutDlg::OnBnClickedOk()
{
	int nHdpi=m_InputSignal->GetReResulationH();
	CString szHdpi;
	szHdpi.Format(_T("%d"),nHdpi);

	int nVdpi=m_InputSignal->GetReResulationV();
	CString szVdpi;
	szVdpi.Format(_T("%d"),nVdpi);
	//////////////////////////////////////////////////////////////////////////
	CString szLTX;
	GetDlgItem(IDC_EDIT_LTX)->GetWindowText(szLTX);
	szLTX.Trim();
	if (_T("") == szLTX)
	{
		m_pDelegate->MessageBoxFromKey(_T("218"), _T("���Ͻ�X����Ϊ��,������!"), MB_OK);
		GetDlgItem(IDC_EDIT_LTX)->SetFocus();
		return;
	}
	m_LTX=_ttoi(szLTX);

	if(m_LTX<0||m_LTX>nHdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("432"),_T("���Ͻ�X���ܳ�������ˮƽ�ֱ���")+szHdpi+_T("!"),MB_OK);
		GetDlgItem(IDC_EDIT_LTX)->SetFocus();
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	CString szLTY;
	GetDlgItem(IDC_EDIT_LTY)->GetWindowText(szLTY);
	szLTY.Trim();
	if (_T("") == szLTY)
	{
		m_pDelegate->MessageBoxFromKey(_T("219"), _T("���Ͻ�Y����Ϊ��,������!"), MB_OK);
		GetDlgItem(IDC_EDIT_LTY)->SetFocus();
		return;
	}
	m_LTY=_ttoi(szLTY);

	if(m_LTY<0||m_LTY>nVdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("433"),_T("���Ͻ�Y���ܳ������봹ֱ�ֱ���")+szVdpi+_T("!"),MB_OK);
		GetDlgItem(IDC_EDIT_LTY)->SetFocus();
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	CString szRBX;
	GetDlgItem(IDC_EDIT_RBX)->GetWindowText(szRBX);
	szRBX.Trim();
	if (_T("") == szRBX)
	{
		m_pDelegate->MessageBoxFromKey(_T("220"), _T("���½�X����Ϊ��,������!"), MB_OK);
		GetDlgItem(IDC_EDIT_RBX)->SetFocus();
		return;
	}
	m_RBX=_ttoi(szRBX);

	if(m_RBX<0||m_RBX>nHdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("434"),_T("���½�X���ܳ�������ˮƽ�ֱ���")+szHdpi+_T("!"),MB_OK);
		GetDlgItem(IDC_EDIT_RBX)->SetFocus();
		return;
	}
	//////////////////////////////////////////////////////////////////////////

	CString szRBY;
	GetDlgItem(IDC_EDIT_RBY)->GetWindowText(szRBY);
	szRBY.Trim();
	if (_T("") == szRBY)
	{
		m_pDelegate->MessageBoxFromKey(_T("221"), _T("���½�Y����Ϊ��,������!"), MB_OK);
		GetDlgItem(IDC_EDIT_RBY)->SetFocus();
		return;
	}
	m_RBY=_ttoi(szRBY);

	if(m_RBY<0||m_RBY>nHdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("435"),_T("���½�Y���ܳ������봹ֱ�ֱ���")+szVdpi+_T("!"),MB_OK);
		GetDlgItem(IDC_EDIT_RBY)->SetFocus();
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	XSignalCutInfo* pInfo=m_InputSignal->GetDefaultCutInfo();
	pInfo->SetSignalCut(m_LTX,m_LTY,m_RBX,m_RBY);

	CDialogEx::OnOK();
}

int XInputSignalCutDlg::GetCutLTX()
{
	return m_LTX;
}

int XInputSignalCutDlg::GetCutLTY()
{
	return m_LTY;
}

int XInputSignalCutDlg::GetCutRBX()
{
	return m_RBX;
}

int XInputSignalCutDlg::GetCutRBY()
{
	return m_RBY;
}