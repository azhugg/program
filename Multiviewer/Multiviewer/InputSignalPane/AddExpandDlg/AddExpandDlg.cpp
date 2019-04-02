// AddExpandDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AddExpandDlg.h"
#include "afxdialogex.h"
#include "XDelegateAddExpandDlg.h"
#include "XInputSignal.h"
#include "XInputSignalPane.h"

// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(CAddExpandDlg, CDialogEx)

CAddExpandDlg::CAddExpandDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddExpandDlg::IDD, pParent)
{
	m_pDelegate = NULL;

	m_InputSignal = NULL;
}

CAddExpandDlg::~CAddExpandDlg()
{
}

void CAddExpandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddExpandDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddExpandDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void CAddExpandDlg::SetDelegate(XDelegateAddExpandDlg* p)
{
	m_pDelegate = p;
}

void CAddExpandDlg::SetInputSignal(XInputSignal* p)
{
	m_InputSignal = p;
}

void CAddExpandDlg::SetInputSignalPan(XInputSignalPane* p)
{
	m_InputSIgnalPan=p;
}

void CAddExpandDlg::SetInputSignalName(CString s)
{
	m_InputSignalName = s;
}

CString CAddExpandDlg::GetName()
{
	return m_szName;
}

XExpandInfo* CAddExpandDlg::GetExpandInfo()
{
	return &m_ExpandInfo;
}

BOOL CAddExpandDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	((CEdit*)GetDlgItem(IDC_EDIT_NAME))->SetLimitText(5);

	InitData();

	return FALSE;  
}

void CAddExpandDlg::InitData()
{
	VEC_INPUTSIGNAL& VecInputSignal=m_InputSIgnalPan->GetVecInputSignal();

	int nIndex=m_InputSignal->GetInputIndex();

	for(VEC_INPUTSIGNAL::iterator iter=VecInputSignal.begin();iter!=VecInputSignal.end();++iter)
	{
		XInputSignal* pInputSignal=*iter;

		if(nIndex==pInputSignal->GetInputIndex())
		{
			CString szTemp=_T("");

			szTemp.Format(_T("%d"), pInputSignal->GetReResulationH());
			GetDlgItem(IDC_EDIT_H)->SetWindowText(szTemp);

			szTemp.Format(_T("%d"), pInputSignal->GetReResulationV());
			GetDlgItem(IDC_EDIT_V)->SetWindowText(szTemp);
		}
	}
}

void CAddExpandDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("205"), _T("��Ӿֲ��Ŵ�")) + _T(" - ") + m_InputSignalName);

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("214"), _T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("215"), _T("ȡ��")));

	GetDlgItem(IDC_STATIC_NAME)->SetWindowText(m_pDelegate->GetTranslationString(_T("216"), _T("����")) + _T(":"));
	GetDlgItem(IDC_STATIC_LEFT)->SetWindowText(m_pDelegate->GetTranslationString(_T("210"), _T("���Ͻ�X")) + _T(":"));
	GetDlgItem(IDC_STATIC_TOP)->SetWindowText(m_pDelegate->GetTranslationString(_T("211"), _T("���Ͻ�Y")) + _T(":"));
	GetDlgItem(IDC_STATIC_RIGHT)->SetWindowText(m_pDelegate->GetTranslationString(_T("212"), _T("���½�X")) + _T(":"));
	GetDlgItem(IDC_STATIC_BOTTOM)->SetWindowText(m_pDelegate->GetTranslationString(_T("213"), _T("���½�Y")) + _T(":"));
	
	GetDlgItem(IDC_STATIC_NOTICE)->SetWindowText(m_pDelegate->GetTranslationString(_T("321"), _T("(��ʾ:ȫ��������ֵȫΪ0;����������ֵ��1��ʼ)")));

	GetDlgItem(IDC_STATIC_RESH)->SetWindowText(m_pDelegate->GetTranslationString(_T("402"), _T("ˮƽ�ֱ���")) + _T(":"));
	GetDlgItem(IDC_STATIC_RESV)->SetWindowText(m_pDelegate->GetTranslationString(_T("403"), _T("��ֱ�ֱ���")) + _T(":"));
}

void CAddExpandDlg::OnBnClickedOk()
{
	int nHdpi=m_InputSignal->GetReResulationH();
	CString szHdpi;
	szHdpi.Format(_T("%d"),nHdpi);

	int nVdpi=m_InputSignal->GetReResulationV();
	CString szVdpi;
	szVdpi.Format(_T("%d"),nVdpi);

	//////////////////////////////////////////////////////////////////////////
	CString szName = _T("");
	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(szName);
	szName.Trim();
	if (_T("") == szName)
	{
		m_pDelegate->MessageBoxFromKey(_T("217"), _T("���Ʋ���Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_NAME)->SetFocus();

		return;
	}

	if (m_InputSignal->DecideExpandNameExist(NULL, szName))
	{
		m_pDelegate->MessageBoxFromKey(_T("222"), _T("�����Ѵ���,����������!"), MB_OK);

		return;
	}
	////////////////////////////////////////////////////////////
	CString szLeft = _T("");
	GetDlgItem(IDC_EDIT_LEFT)->GetWindowText(szLeft);
	szLeft.Trim();
	if (_T("") == szLeft)
	{
		m_pDelegate->MessageBoxFromKey(_T("218"), _T("���Ͻ�X����Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_LEFT)->SetFocus();

		return;
	}

	int nLeft = _ttoi(szLeft);
	if(nLeft < 0 || nLeft > nHdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("432"),_T("���Ͻ�X���ܳ�������ˮƽ�ֱ���")+szHdpi+_T("!"), MB_OK);

		GetDlgItem(IDC_EDIT_LEFT)->SetFocus();

		return;
	}
	////////////////////////////////////////////////////////////
	CString szTop = _T("");
	GetDlgItem(IDC_EDIT_TOP)->GetWindowText(szTop);
	szTop.Trim();
	if (_T("") == szTop)
	{
		m_pDelegate->MessageBoxFromKey(_T("219"), _T("���Ͻ�Y����Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_TOP)->SetFocus();

		return;
	}

	int nTop = _ttoi(szTop);
	if(nTop < 0 || nTop > nVdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("433"),_T("���Ͻ�Y���ܳ������봹ֱ�ֱ���")+szVdpi+_T("!"), MB_OK);

		GetDlgItem(IDC_EDIT_TOP)->SetFocus();

		return;
	}
	////////////////////////////////////////////////////////////
	CString szRight = _T("");
	GetDlgItem(IDC_EDIT_RIGHT)->GetWindowText(szRight);
	szRight.Trim();
	if (_T("") == szRight)
	{
		m_pDelegate->MessageBoxFromKey(_T("220"), _T("���½�X����Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_RIGHT)->SetFocus();

		return;
	}

	int nRight = _ttoi(szRight);
	if(nRight < 0 || nRight > nHdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("434"),_T("���Ͻ�X���ܳ�������ˮƽ�ֱ���")+szHdpi+_T("!"), MB_OK);

		GetDlgItem(IDC_EDIT_RIGHT)->SetFocus();

		return;
	}
	////////////////////////////////////////////////////////////
	CString szBottom = _T("");
	GetDlgItem(IDC_EDIT_BOTTOM)->GetWindowText(szBottom);
	szBottom.Trim();
	if (_T("") == szBottom)
	{
		m_pDelegate->MessageBoxFromKey(_T("221"), _T("���½�Y����Ϊ��,������!"), MB_OK);

		GetDlgItem(IDC_EDIT_BOTTOM)->SetFocus();

		return;
	}

	int nBottom = _ttoi(szBottom);
	if(nBottom < 0 || nBottom > nVdpi)
	{
		m_pDelegate->MessageBoxFromKey(_T("435"),_T("���Ͻ�Y���ܳ������봹ֱ�ֱ���")+szVdpi+_T("!"), MB_OK);

		GetDlgItem(IDC_EDIT_BOTTOM)->SetFocus();

		return;
	}
	////////////////////////////////////////////////////////////
	if ((nLeft != 0) 
		|| (nTop != 0)
		|| (nRight != 0)
		|| (nBottom != 0))
	{
		if ((nLeft <= 0)
			|| (nTop <= 0)
			|| (nRight <= 0)
			|| (nBottom <= 0)
			|| (nLeft >= nRight)
			|| (nTop >= nBottom))
		{
			m_pDelegate->MessageBoxFromKey(_T("225"), _T("��������ȷ����ֵ!ȫ��������ֵȫΪ0;����������ֵ��1��ʼ��"), MB_OK);

			return;
		}
	}

	m_szName = szName;

	m_ExpandInfo.SetExpand(nLeft, nTop, nRight, nBottom);

	CDialogEx::OnOK();
}