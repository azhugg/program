#include "stdafx.h"
#include "XScreenMoveChangeDlg.h"
#include "afxdialogex.h"
#include "XDelegateScreenMoveChangeDlg.h"
#include "XScreen.h"
#include "XScreenManage.h"



// CAddExpandDlg �Ի���

IMPLEMENT_DYNAMIC(XChangeMoveScreenDlg, CDialogEx)

	XChangeMoveScreenDlg::XChangeMoveScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(XChangeMoveScreenDlg::IDD, pParent)
{
	m_pDelegate = NULL;

}

XChangeMoveScreenDlg::~XChangeMoveScreenDlg()
{

}

void XChangeMoveScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FCOLOR_CHANGE, m_FColor_Change);
	DDX_Control(pDX, IDC_BCOLOR_CHANGE, m_BColor_Change);
	DDX_Control(pDX, IDC_COMBO_BEGINX, m_ComboBox_BeginX);
	DDX_Control(pDX, IDC_COMBO_BEGINY, m_ComboBox_BeginY);
	DDX_Control(pDX, IDC_COMBO_STYLE, m_ComboBox_Type);
}


BEGIN_MESSAGE_MAP(XChangeMoveScreenDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &XChangeMoveScreenDlg::OnBtnSet)
END_MESSAGE_MAP()


// CAddExpandDlg ��Ϣ�������

void XChangeMoveScreenDlg::SetDelegate(XDelegateScreenMoveChangeDlg* p)
{
	m_pDelegate = p;
}

void XChangeMoveScreenDlg::SetInputSignalName(CString s)
{
	m_InputSignalName=s;
}

void XChangeMoveScreenDlg::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XChangeMoveScreenDlg::SetScreen(XScreen* p)
{
	m_pScreen=p;
}

BOOL XChangeMoveScreenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	

	InitCombo();

	InitData();

	return FALSE;  
}

void XChangeMoveScreenDlg::ReloadInterface()
{
	SetWindowText(m_pDelegate->GetTranslationString(_T("527"),_T("����ƴ�ӹ�������")));

	GetDlgItem(IDOK)->SetWindowText(m_pDelegate->GetTranslationString(_T("268"), _T("����")));
	GetDlgItem(IDCANCEL)->SetWindowText(m_pDelegate->GetTranslationString(_T("215"), _T("ȡ��")));

	GetDlgItem(IDC_STATIC_STYLE)->SetWindowText(m_pDelegate->GetTranslationString(_T("396"), _T("��ʽ"))+ _T(":"));
	GetDlgItem(IDC_STATIC_FCOLOR)->SetWindowText(m_pDelegate->GetTranslationString(_T("260"), _T("������ɫ")) + _T(":"));
	GetDlgItem(IDC_STATIC_BCOLOR)->SetWindowText(m_pDelegate->GetTranslationString(_T("397"), _T("������ɫ")) + _T(":"));
	GetDlgItem(IDC_STATIC_SPEED)->SetWindowText(m_pDelegate->GetTranslationString(_T("448"), _T("�����ٶ�")) + _T(":"));
	GetDlgItem(IDC_STATIC_SPACE)->SetWindowText(m_pDelegate->GetTranslationString(_T("482"), _T("�������")) + _T(":"));

	GetDlgItem(IDC_STATIC_BEGINX)->SetWindowText(m_pDelegate->GetTranslationString(_T("470"), _T("��ʼ����X"))+ _T(":"));
	GetDlgItem(IDC_STATIC_BEGINY)->SetWindowText(m_pDelegate->GetTranslationString(_T("471"), _T("��ʼ����Y")) + _T(":"));
	GetDlgItem(IDC_STATIC_BEGINH)->SetWindowText(m_pDelegate->GetTranslationString(_T("534"), _T("��ʼ�߶�")) + _T(":"));

	GetDlgItem(IDC_STATIC_TIPS)->SetWindowText(m_pDelegate->GetTranslationString(_T("478"), _T("��ʾ:��������Ӻ���ڼ�����Ļ��ʼ")));
	GetDlgItem(IDC_STATIC_TIPS2)->SetWindowText(m_pDelegate->GetTranslationString(_T("479"), _T("��ʾ:�������Ļ�����ĸ߶�")));
	GetDlgItem(IDC_STATIC_TIPS5)->SetWindowText(m_pDelegate->GetTranslationString(_T("485"), _T("��ʾ:�������������ڼ�����Ļ��ʼ")));

}

void XChangeMoveScreenDlg::InitData()
{
	XScreenMoveInfo* pChangeInfo=m_pScreenManage->GetScreenMoveInfo();

	CString szTemp=_T("");

	szTemp.Format(_T("%d"), pChangeInfo->GetSpeed());
	GetDlgItem(IDC_EDIT_SPEED)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pChangeInfo->GetSpace());
	GetDlgItem(IDC_EDIT_SPACE)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pChangeInfo->GetBeginH());
	GetDlgItem(IDC_EDIT_BEGINH)->SetWindowText(szTemp);

	m_FColor_Change.SetColor(pChangeInfo->GetColor());
	m_BColor_Change.SetColor(pChangeInfo->GetBkColor());

	//m_ComboBox_Type.SetCurSel(pMoveInfo->GetType());
	m_ComboBox_BeginX.SetCurSel(pChangeInfo->GetComboShowBeginX());
	m_ComboBox_BeginY.SetCurSel(pChangeInfo->GetComboShowBeginY());
	m_ComboBox_Type.SetCurSel(pChangeInfo->GetType());

}

void XChangeMoveScreenDlg::InitCombo()
{
	XScreenMoveInfo* pChangeInfo=m_pScreenManage->GetScreenMoveInfo();
	int nScreenCountH=m_pScreenManage->GetScreenCountH();
	int nScreenCountV=m_pScreenManage->GetScreenCountV();
	//������
	int nComboLong=pChangeInfo->GetComboLong();
	int nComboWidth=pChangeInfo->GetComboWidth();
	int nComboBeginY=pChangeInfo->GetComboBeginY();
	int nComboBeginX=pChangeInfo->GetComboBeginX();
	int nBeginH=pChangeInfo->GetBeginH();
	int nHight=pChangeInfo->GetHight();
	int nScreenResulationH=pChangeInfo->GetScreenResulationH();
	int nScreenResulationV=pChangeInfo->GetScreenResulationV();

	CString str;
	for(int i=1;i<=nScreenCountH-nComboLong+1;i++)
	{
		str.Format(_T("%d"),i);
		m_ComboBox_BeginX.AddString(str);
		//m_ComboBox_Long.AddString(str);
	}

	if(nScreenCountH-nComboLong==0)
	{
		m_ComboBox_BeginX.EnableWindow(FALSE);
	}

	m_ComboBox_BeginX.SetCurSel(0);
	//*****************************************
	int nBeginYRange=0;

	int nCountV=(nHight+nBeginH)/nScreenResulationV;
	int nCountV2=(nHight+nBeginH)%nScreenResulationV;

	if(nCountV>=1&&nCountV2==0)
	{
		nBeginYRange=nScreenCountV-nCountV+1;

	}
	else if(nCountV==0||nCountV2!=0)
	{
		nBeginYRange=nScreenCountV-nCountV;
	}

	for(int j=1;j<=nBeginYRange;j++)
	{
		str.Format(_T("%d"),j);
		m_ComboBox_BeginY.AddString(str);
	}

	m_ComboBox_BeginY.SetCurSel(0);
	
	//*****************************************

	m_ComboBox_Type.AddString(m_pDelegate->GetTranslationString(_T("242"), _T("2")));
	m_ComboBox_Type.AddString(m_pDelegate->GetTranslationString(_T("398"), _T("3")));
	m_ComboBox_Type.SetCurSel(0);

}

void XChangeMoveScreenDlg::OnBtnSet()
{
	
	CMFCColorButton* pBtnColor=(CMFCColorButton*)GetDlgItem(IDC_FCOLOR_CHANGE);

	COLORREF cFcolor=pBtnColor->GetColor();

	CMFCColorButton* pBtnBkColor=(CMFCColorButton*)GetDlgItem(IDC_BCOLOR_CHANGE);

	COLORREF cBcolor=pBtnBkColor->GetColor();

	//*****************************************
	CString szSPeed=_T("");
	GetDlgItem(IDC_EDIT_SPEED)->GetWindowText(szSPeed);
	szSPeed.Trim();
	if (_T("")==szSPeed)
	{
		m_pDelegate->MessageBoxFromKey(_T("474"), _T("�����ٶȲ���Ϊ��,�����룡"), MB_OK);
		GetDlgItem(IDC_EDIT_SPEED)->SetFocus();
		return;
	}
	int nSpeed=_ttoi(szSPeed);
	//*****************************************
	CString szSPace=_T("");
	GetDlgItem(IDC_EDIT_SPACE)->GetWindowText(szSPace);
	szSPace.Trim();
	if (_T("")==szSPace)
	{
		m_pDelegate->MessageBoxFromKey(_T("475"), _T("�����������Ϊ��,�����룡"), MB_OK);
		GetDlgItem(IDC_EDIT_SPACE)->SetFocus();
		return;
	}
	int nSpace=_ttoi(szSPace);
	//***************************
	CString szBeginH=_T("");
	GetDlgItem(IDC_EDIT_BEGINH)->GetWindowText(szBeginH);
	szBeginH.Trim();
	if (_T("")==szBeginH)
	{
		m_pDelegate->MessageBoxFromKey(_T("487"), _T("��ʼ�߶Ȳ���Ϊ��,�����룡"), MB_OK);
		GetDlgItem(IDC_EDIT_BEGINH)->SetFocus();
		return;
	}
	int nBeginH=_ttoi(szBeginH);
	if(nBeginH<0||nBeginH>1080)
	{
		m_pDelegate->MessageBoxFromKey(_T("488"), _T("��ʼ�߶Ȳ��ܹ������򳬹���ռ��Ļ�ֱ��ʣ�"), MB_OK);
		GetDlgItem(IDC_EDIT_BEGINH)->SetFocus();
		return;
	}
	//***************************
	CString nSelectStr;

	int nComboBeginX=m_ComboBox_BeginX.GetCurSel();
	int nComboBeginY=m_ComboBox_BeginY.GetCurSel();

	m_ComboBox_BeginX.GetLBText(nComboBeginX,nSelectStr);
	int nComboBoxBeginX=_ttoi(nSelectStr);

	m_ComboBox_BeginY.GetLBText(nComboBeginY,nSelectStr);
	int nComboBoxBeginY=_ttoi(nSelectStr);


	int nType=m_ComboBox_Type.GetCurSel();
	//***************************
	XScreenMoveInfo* pChangeInfo=m_pScreenManage->GetScreenMoveInfo();
	pChangeInfo->SetColor(cFcolor);
	pChangeInfo->SetBkColor(cBcolor);
	pChangeInfo->SetSpeed(nSpeed);
	pChangeInfo->SetSpace(nSpace);
	
	pChangeInfo->SetType(nType);
	pChangeInfo->SetComboBeginX(nComboBoxBeginX);
	pChangeInfo->SetComboBeginY(nComboBoxBeginY);
	pChangeInfo->SetComboShowBeginX(nComboBeginX);
	pChangeInfo->SetComboShowBeginY(nComboBeginY);
	pChangeInfo->SetBeginH(nBeginH);

	::SendMessage(gHandle,MSG_UPDATESHOW,0,0);

	CDialogEx::OnOK();
}