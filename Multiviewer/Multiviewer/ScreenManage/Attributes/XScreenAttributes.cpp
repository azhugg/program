#include "stdafx.h"
#include "XScreenAttributes.h"
#include "afxdialogex.h"
#include "XDelegateScreenAttributes.h"
#include "XScreen.h"
#include "XScreenManage.h"


// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XScreenAttributesDlg, CDialogEx)

	XScreenAttributesDlg::XScreenAttributesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(XScreenAttributesDlg::IDD, pParent)
{
	m_pDelegate = NULL;
}

XScreenAttributesDlg::~XScreenAttributesDlg()
{

}

void XScreenAttributesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(XScreenAttributesDlg, CDialogEx)

END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XScreenAttributesDlg::SetDelegate(XDelegateScreenAttributesDlg* p)
{
	m_pDelegate = p;
}

void XScreenAttributesDlg::SetInputSignalName(CString s)
{
	m_InputSignalName=s;
}

void XScreenAttributesDlg::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XScreenAttributesDlg::SetScreen(XScreen* p)
{
	m_pScreen=p;
}

BOOL XScreenAttributesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	InitData();

	return FALSE;  
}

void XScreenAttributesDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("456"),_T("����")));

	GetDlgItem(IDC_STATIC_DEVICE)->SetWindowText(m_pDelegate->GetTranslationString(_T("459"), _T("�豸����")) + _T(":"));
	GetDlgItem(IDC_STATIC_EQUIPMENT)->SetWindowText(m_pDelegate->GetTranslationString(_T("504"), _T("��Ļ״̬")) + _T(":"));
	GetDlgItem(IDC_STATIC_RESH)->SetWindowText(m_pDelegate->GetTranslationString(_T("402"), _T("ˮƽ�ֱ���")) + _T(":"));
	GetDlgItem(IDC_STATIC_RESV)->SetWindowText(m_pDelegate->GetTranslationString(_T("403"), _T("��ֱ�ֱ���")) + _T(":"));
	GetDlgItem(IDC_STATIC_REFRESH)->SetWindowText(m_pDelegate->GetTranslationString(_T("416"), _T("ˢ��Ƶ��")) + _T(":"));
	GetDlgItem(IDC_STATIC_DINDEX)->SetWindowText(m_pDelegate->GetTranslationString(_T("460"), _T("�ֱ������")) + _T(":"));
}

void XScreenAttributesDlg::InitData()
{
	int nIndex=m_pScreen->GetBoardIndex();

	CString szTemp = _T("");

	if(nIndex==0)
	{
		GetDlgItem(IDC_STATIC_DEVSTYLE)->SetWindowText(m_pDelegate->GetTranslationString(_T("541"),_T("���豸")));

		GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("541"),_T("���豸")));

		int i=0;
		szTemp.Format(_T("%d"),i);
		GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
		GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
		GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);
		GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
	}
	else
	{
		int nStatus=m_pScreen->GetReStatus();
		int nHdpi=m_pScreen->GetReScreenHdpi();
		int nVdpi=m_pScreen->GetReScreenVdpi();
		int nDpiIndex=m_pScreen->GetReDpiIndex();
		int nRefreash=m_pScreen->GetReRefresh();

		if(nStatus==0
			&&nHdpi==0
			&&nVdpi==0
			&&nDpiIndex==0
			&&nRefreash==0)
		{
			GetDlgItem(IDC_STATIC_DEVSTYLE)->SetWindowText(m_pDelegate->GetTranslationString(_T("551"),_T("��")));
			GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("541"),_T("���豸")));

			int i=0;
			szTemp.Format(_T("%d"),i);
			GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
			GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
			GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);
			GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
		}
		else
		{
			int nType=m_pScreenManage->GetBoardTypeByReStatus(nStatus);

			switch(nType)
			{
			case BOARDTYPE_SIGNALSPLICE:
				{
					GetDlgItem(IDC_STATIC_DEVSTYLE)->SetWindowText(m_pDelegate->GetTranslationString(_T("649"),_T("��·ƴ�ӿ�")));

					if(nStatus==0x00)
					{
						GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("541"),_T("���豸")));

						int i=0;
						szTemp.Format(_T("%d"),i);
						GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
					}
					else if(m_pScreen->GetReStatus()==0x01)
					{
						GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("651"),_T("���豸")));

						szTemp.Format(_T("%d"), m_pScreen->GetReScreenHdpi());
						GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
						szTemp.Format(_T("%d"), m_pScreen->GetReScreenVdpi());
						GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
						szTemp.Format(_T("%d"), m_pScreen->GetReDpiIndex());
						GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);

						szTemp.Format(_T("%d"), m_pScreen->GetReRefresh());
						GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
					}
				}
				break;
			case BOARDTYPE_MULTISPLICE:
				{
					GetDlgItem(IDC_STATIC_DEVSTYLE)->SetWindowText(m_pDelegate->GetTranslationString(_T("650"),_T("��·ƴ�ӿ�")));

					if(m_pScreen->GetReStatus()==0x10)
					{
						GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("541"),_T("���豸")));

						int i=0;
						szTemp.Format(_T("%d"),i);
						GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
					}
					else
					{
						GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("651"),_T("���豸")));

						szTemp.Format(_T("%d"), m_pScreen->GetReScreenHdpi());
						GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
						szTemp.Format(_T("%d"), m_pScreen->GetReScreenVdpi());
						GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
						szTemp.Format(_T("%d"), m_pScreen->GetReDpiIndex());
						GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);
						szTemp.Format(_T("%d"), m_pScreen->GetReRefresh());
						GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
					}
				}
				break;
			case BOARDTYPE_PREVIEW:
				{
					GetDlgItem(IDC_STATIC_DEVSTYLE)->SetWindowText(m_pDelegate->GetTranslationString(_T("682"),_T("Ԥ����")));

					if(nStatus==0x20)
					{
						GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("541"),_T("���豸")));

						int i=0;
						szTemp.Format(_T("%d"),i);
						GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);
						GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
					}
					else
					{
						GetDlgItem(IDC_STATIC_DEV)->SetWindowText(m_pDelegate->GetTranslationString(_T("651"),_T("���豸")));

						szTemp.Format(_T("%d"), m_pScreen->GetReScreenHdpi());
						GetDlgItem(IDC_STATIC_H)->SetWindowText(szTemp);
						szTemp.Format(_T("%d"), m_pScreen->GetReScreenVdpi());
						GetDlgItem(IDC_STATIC_V)->SetWindowText(szTemp);
						szTemp.Format(_T("%d"), m_pScreen->GetReDpiIndex());
						GetDlgItem(IDC_STATIC_DPIINDEX)->SetWindowText(szTemp);

						szTemp.Format(_T("%d"), m_pScreen->GetReRefresh());
						GetDlgItem(IDC_STATIC_FRESH)->SetWindowText(szTemp);
					}
				}
				break;
			default:
				break;
			}
		}
	}
}


