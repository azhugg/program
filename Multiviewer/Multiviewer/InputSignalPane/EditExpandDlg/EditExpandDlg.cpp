// EditExpandDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EditExpandDlg.h"
#include "afxdialogex.h"
#include "XDelegateEditExpandDlg.h"
#include "XInputSignal.h"
#include "XInputSignalExpand.h"
#include "XInputSignalPane.h"

// CEditExpandDlg �Ի���

IMPLEMENT_DYNAMIC(CEditExpandDlg, CDialogEx)

CEditExpandDlg::CEditExpandDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditExpandDlg::IDD, pParent)
{
	m_pDelegate = NULL;

	m_InputSignalExpand = NULL;
}

CEditExpandDlg::~CEditExpandDlg()
{
}

void CEditExpandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditExpandDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CEditExpandDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CEditExpandDlg ��Ϣ�������

void CEditExpandDlg::SetDelegate(XDelegateEditExpandDlg* p)
{
	m_pDelegate = p;
}

void CEditExpandDlg::SetInputSignalExpand(XInputSignalExpand* p)
{
	m_InputSignalExpand = p;
}

void CEditExpandDlg::SetInputSignalPan(XInputSignalPane* p)
{
	m_InputSignalPan=p;
}

BOOL CEditExpandDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitShowData();

	ReloadInterface();

	((CEdit*)GetDlgItem(IDC_EDIT_NAME))->SetLimitText(5);

	return FALSE;  
}

void CEditExpandDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("223"), _T("�༭�ֲ��Ŵ�")));

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

void CEditExpandDlg::InitShowData()
{
	VEC_INPUTSIGNAL& VecInputSignal=m_InputSignalPan->GetVecInputSignal();

	int nIndex=m_InputSignalExpand->GetInputSignal()->GetInputIndex();

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

	CString szTemp = _T("");

	GetDlgItem(IDC_EDIT_NAME)->SetWindowText(m_InputSignalExpand->GetName());

	XExpandInfo* pExpandInfo = m_InputSignalExpand->GetExpandInfo();

	szTemp.Format(_T("%d"), pExpandInfo->GetExpandX1());
	GetDlgItem(IDC_EDIT_LEFT)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pExpandInfo->GetExpandY1());
	GetDlgItem(IDC_EDIT_TOP)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pExpandInfo->GetExpandX2());
	GetDlgItem(IDC_EDIT_RIGHT)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pExpandInfo->GetExpandY2());
	GetDlgItem(IDC_EDIT_BOTTOM)->SetWindowText(szTemp);
}

void CEditExpandDlg::OnBnClickedOk()
{
	int nHdpi=m_InputSignalExpand->GetInputSignal()->GetReResulationH();
	CString szHdpi;
	szHdpi.Format(_T("%d"),nHdpi);

	int nVdpi=m_InputSignalExpand->GetInputSignal()->GetReResulationV();
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

	if (m_InputSignalExpand->GetInputSignal()->DecideExpandNameExist(m_InputSignalExpand, szName))
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

	m_InputSignalExpand->GetExpandInfo()->SetExpand(nLeft, nTop, nRight, nBottom);

	m_InputSignalExpand->SetName(szName);

	CDialogEx::OnOK();
}