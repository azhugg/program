// ChangeRTSPAddrDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChangeRTSPAddrDlg.h"
#include "afxdialogex.h"
#include "ChangeRTSPAddrDlg.h"
#include "HandleCalculate.h"
#include "XVideoPreviewFrame.h"
#include "XVideoPreviewPane.h"
#include "XDelegateVideoPreviewPane.h"

// CChangeRTSPAddrDlg �Ի���

IMPLEMENT_DYNAMIC(CChangeRTSPAddrDlg, CDialogEx)

CChangeRTSPAddrDlg::CChangeRTSPAddrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangeRTSPAddrDlg::IDD, pParent)
{
	m_RTSPAddr = _T("");
}

CChangeRTSPAddrDlg::~CChangeRTSPAddrDlg()
{
}

void CChangeRTSPAddrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChangeRTSPAddrDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChangeRTSPAddrDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CChangeRTSPAddrDlg ��Ϣ�������

BOOL CChangeRTSPAddrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetWindowText(m_Frame->GetPane()->GetDelegate()->GetTranslationString(_T("332"), _T("�޸�RTSP��ַ")));

	GetDlgItem(IDOK)->SetWindowText(m_Frame->GetPane()->GetDelegate()->GetTranslationString(_T("214"), _T("ȷ��")));

	GetDlgItem(IDCANCEL)->SetWindowText(m_Frame->GetPane()->GetDelegate()->GetTranslationString(_T("215"), _T("ȡ��")));

	GetDlgItem(IDC_EDIT_RTSPADDR)->SetWindowText(m_RTSPAddr);

	GetDlgItem(IDC_STATIC_RTSPADDR)->SetWindowText(m_Frame->GetPane()->GetDelegate()->GetTranslationString(_T("335"), _T("RTSP��ַ")) + _T(":"));

	return FALSE;  
}

void CChangeRTSPAddrDlg::SetRTSPAddr(CString s)
{
	m_RTSPAddr = s;
}

CString CChangeRTSPAddrDlg::GetRTSPAddr()
{
	return m_RTSPAddr;
}

void CChangeRTSPAddrDlg::SetFrame(XVideoPreviewFrame* p)
{
	m_Frame = p;
}

void CChangeRTSPAddrDlg::OnBnClickedOk()
{
	CString szRTSPAddr = _T("");

	GetDlgItem(IDC_EDIT_RTSPADDR)->GetWindowText(szRTSPAddr);

	szRTSPAddr.Trim();

	if (_T("") != szRTSPAddr)
	{
		if (!HandleCalculate::DecideRTSPAddr(szRTSPAddr))
		{
			m_Frame->GetPane()->GetDelegate()->MessageBoxFromKey(_T("333"), _T("��������ȷ��RTSP��ַ!"), MB_OK);

			return;
		}
	}

	m_RTSPAddr = szRTSPAddr;

	CDialogEx::OnOK();
}
