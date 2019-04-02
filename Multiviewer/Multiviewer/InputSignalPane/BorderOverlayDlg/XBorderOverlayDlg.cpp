#include "stdafx.h"
#include "XBorderOverlayDlg.h"
#include "afxdialogex.h"
#include "XDelegateBorderOverlayDlg.h"
#include "XBorderOverlay.h"
#include "XInputSignal.h"

// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XBorderOverlayDlg, CDialogEx)

	XBorderOverlayDlg::XBorderOverlayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(XBorderOverlayDlg::IDD, pParent)
{
	m_pDelegate = NULL;

	m_InputSignal=NULL;

	m_InputSignalPane=NULL;

}

XBorderOverlayDlg::~XBorderOverlayDlg()
{

}

void XBorderOverlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COLOR_BORDER, m_BorderColor);
}


BEGIN_MESSAGE_MAP(XBorderOverlayDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &XBorderOverlayDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XBorderOverlayDlg::SetDelegate(XDelegateBorderOverlayDlg* p)
{
	m_pDelegate = p;
}

void XBorderOverlayDlg::SetInputSignal(XInputSignal* p)
{
	m_InputSignal = p;
}

void XBorderOverlayDlg::SetInputSignalPane(XInputSignalPane* p)
{
	m_InputSignalPane = p;
}

void XBorderOverlayDlg::SetInputSignalName(CString s)
{
	m_InputSignalName = s;
}

BOOL XBorderOverlayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitData();

	return FALSE;  
}

void XBorderOverlayDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("440"),_T("���ñ߿���Ӳ���")) + _T(" - ") + m_InputSignalName);

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("214"), _T("ȷ��")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("215"), _T("ȡ��")));

	GetDlgItem(IDC_STATIC_WITH)->SetWindowText(m_pDelegate->GetTranslationString(_T("441"), _T("���")) + _T(":"));
	GetDlgItem(IDC_STATIC_COLOR)->SetWindowText(m_pDelegate->GetTranslationString(_T("442"), _T("��ɫ")) + _T(":"));

	GetDlgItem(IDC_STATIC_NOTICE)->SetWindowText(m_pDelegate->GetTranslationString(_T("443"), _T("(��ʾ:���Ϊ0ʱ����ʹ�ñ߿���ӣ�)")));
}

void XBorderOverlayDlg::InitData()
{
	CString szTemp = _T("");

	XBorderOverlay* pBorder=m_InputSignal->GetBorderOverLay();

	szTemp.Format(_T("%d"), pBorder->GetBorderWith());
	GetDlgItem(IDC_EDIT_WITH)->SetWindowText(szTemp);

	m_BorderColor.SetColor(pBorder->GetBorderColor());
}


void XBorderOverlayDlg::OnBnClickedOk()
{
	CMFCColorButton* pBtnColor = (CMFCColorButton*)GetDlgItem(IDC_COLOR_BORDER);

	COLORREF Color = pBtnColor->GetColor();

	CString szWith = _T("");
	GetDlgItem(IDC_EDIT_WITH)->GetWindowText(szWith);
	szWith.Trim();
	if (_T("") == szWith)
	{
		m_pDelegate->MessageBoxFromKey(_T("288"), _T("��Ȳ���Ϊ��,������!"), MB_OK);
		GetDlgItem(IDC_EDIT_WITH)->SetFocus();
		return;
	}
	int nBorderWith=_ttoi(szWith);
	//************************************

	XBorderOverlay* pBorder=m_InputSignal->GetBorderOverLay();

	pBorder->SetBorderWith(nBorderWith);
	pBorder->SetBorderColor(Color);

	CDialogEx::OnOK();
}