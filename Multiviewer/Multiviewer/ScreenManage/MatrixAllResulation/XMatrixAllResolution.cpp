#include "stdafx.h"
#include "XMatrixAllResolution.h"
#include "..\resource.h"
#include "XAllResulationInfo.h"
#include "XScreenManage.h"


IMPLEMENT_DYNAMIC(XMatrixAllResolution, CDialogEx)

XMatrixAllResolution::XMatrixAllResolution(CWnd* pParent /*=NULL*/)
	: CDialogEx(XMatrixAllResolution::IDD, pParent)
{
	
}

XMatrixAllResolution::~XMatrixAllResolution()
{
}

void XMatrixAllResolution::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_INDEX, m_Combo_Index);
	DDX_Control(pDX, IDC_COMBO_REFRESH, m_Combo_Refresh);
	DDX_Control(pDX, IDC_COMBO_MATRIXMODEL, m_Combo_Model);
}

BEGIN_MESSAGE_MAP(XMatrixAllResolution, CDialogEx)
	ON_BN_CLICKED( IDC_BUTTON_OK, &XMatrixAllResolution::OnBtnOK)
	ON_BN_CLICKED(IDC_BUTTON_CENCLE, &XMatrixAllResolution::OnBtnCancle)
	ON_STN_CLICKED(IDC_STATIC_EXPAND, &XMatrixAllResolution::OnClickedExpand)
	ON_CBN_SELCHANGE(IDC_COMBO_INDEX, &XMatrixAllResolution::OnSelchangeIndex)
	ON_CBN_SELCHANGE(IDC_COMBO_REFRESH, &XMatrixAllResolution::OnSelchangeRefresh)
END_MESSAGE_MAP()

void XMatrixAllResolution::SetDelegate(XDelegateAllMatrixResolution* p)
{
	m_Delegate=p;
}

void XMatrixAllResolution::SetScreenManage(XScreenManage* p)
{
	m_pScreenManage=p;
}

void XMatrixAllResolution::SetScreen(XScreen*& p)
{
	m_pScreen=p;
}

BOOL XMatrixAllResolution::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ReloadInterface();

	GetWindowRect(&m_Rect);

	GetDlgItem(IDC_STATIC_EXPAND)->GetWindowRect(&m_ExpaneRect);

	SetDialog();

	Init();

	return FALSE; 
}

void XMatrixAllResolution::SetDialog()
{
	CRect rtSmall;
	rtSmall.SetRectEmpty();
	if (rtSmall.IsRectEmpty())
	{
		rtSmall.left = m_Rect.left;
		rtSmall.top = m_Rect.top;
		rtSmall.right = m_Rect.right;
		rtSmall.bottom = m_ExpaneRect.bottom+10;
	}
	SetWindowPos(NULL, 0, 0, rtSmall.Width(), rtSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
}

void XMatrixAllResolution::Init()
{
	InitCombo();

	InitShowData();
}

void XMatrixAllResolution::InitCombo()
{
	m_Combo_Index.AddString(_T("800*600"));
	m_Combo_Index.AddString(_T("1024*768"));
	m_Combo_Index.AddString(_T("1280*720"));
	m_Combo_Index.AddString(_T("1280*768"));
	m_Combo_Index.AddString(_T("1280*800"));
	m_Combo_Index.AddString(_T("1280*1024"));
	m_Combo_Index.AddString(_T("1360*768"));
	m_Combo_Index.AddString(_T("1366*768"));
	m_Combo_Index.AddString(_T("1440*900"));
	m_Combo_Index.AddString(_T("1440*1050"));
	m_Combo_Index.AddString(_T("1600*900"));
	m_Combo_Index.AddString(_T("1680*1050"));
	m_Combo_Index.AddString(_T("1920*1080"));
	m_Combo_Index.AddString(_T("1920*1200"));
	m_Combo_Index.SetCurSel(0);
	//////////////////////////////////////////////////////////////////////////
	m_Combo_Refresh.AddString(_T("60"));
	//////////////////////////////////////////////////////////////////////////
	m_Combo_Model.AddString(m_Delegate->GetTranslationString(_T("711"),_T("����ɨ��")));
	m_Combo_Model.AddString(m_Delegate->GetTranslationString(_T("710"),_T("����ɨ��")));
	m_Combo_Model.AddString(m_Delegate->GetTranslationString(_T("712"),_T("��׼�ֱ���")));
	m_Combo_Model.SetCurSel(0);
}

void XMatrixAllResolution::InitShowData()
{
	XAllResulationInfo* pInfo=m_pScreenManage->GetAllResulationInfo();

	CString szTemp;

	szTemp.Format(_T("%d"), pInfo->GetResolutionH());
	GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetResolutionV());
	GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetHFPorch());
	GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetVFPorch());
	GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetHpixel());
	GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetVPixel());
	GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetHBPorch());
	GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetVBProch());
	GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetHSyncTime());
	GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetVSyncTime());
	GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetHSyncPolarity());
	GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(szTemp);

	szTemp.Format(_T("%d"), pInfo->GetVSyncPolarity());
	GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(szTemp);

	m_Combo_Index.SetCurSel(pInfo->GetComboIndex());
	//////////////////////////////////////////////////////////////////////////
	if(pInfo->GetComboIndex()==2)
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.AddString(_T("50"));
	}
	else if(pInfo->GetComboIndex()==12)
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.AddString(_T("50"));
		m_Combo_Refresh.AddString(_T("30"));
		m_Combo_Refresh.AddString(_T("25"));
	}

	m_Combo_Refresh.SetCurSel(pInfo->GetComboRefresh());

	//////////////////////////////////////////////////////////////////////////
	m_Combo_Model.SetCurSel(pInfo->GetComboModel());
	
}

void XMatrixAllResolution::ReloadInterface()
{
	SetWindowText(m_Delegate->GetTranslationString(_T("400"), _T("������Ļ�ֱ���")));

	GetDlgItem(IDC_STATIC_SCREENINDEX)->SetWindowText(m_Delegate->GetTranslationString(_T("401"),_T("�ֱ������"))+_T(":"));
	GetDlgItem(IDC_STATIC_RESULATIONX)->SetWindowText(m_Delegate->GetTranslationString(_T("402"),_T("ˮƽ�ֱ���"))+_T(":"));
	GetDlgItem(IDC_STATIC_RESULATIONY)->SetWindowText(m_Delegate->GetTranslationString(_T("403"),_T("��ֱ�ֱ���"))+_T(":"));
	GetDlgItem(IDC_STATIC_EXPAND)->SetWindowText(m_Delegate->GetTranslationString(_T("404"),_T("�߼�����"))+_T(">>"));
	GetDlgItem(IDC_STATIC_HPORCH)->SetWindowText(m_Delegate->GetTranslationString(_T("405"),_T("ˮƽǰ��"))+_T(":"));
	GetDlgItem(IDC_STATIC_HPOLARITY)->SetWindowText(m_Delegate->GetTranslationString(_T("406"),_T("ˮƽ�����"))+_T(":"));
	GetDlgItem(IDC_STATIC_HZONG)->SetWindowText(m_Delegate->GetTranslationString(_T("407"),_T("ˮƽ����"))+_T(":"));
	GetDlgItem(IDC_STATIC_HWITH)->SetWindowText(m_Delegate->GetTranslationString(_T("408"),_T("ˮƽͬ�����"))+_T(":"));
	GetDlgItem(IDC_STATIC_HSYNC)->SetWindowText(m_Delegate->GetTranslationString(_T("409"),_T("ˮƽͬ������"))+_T(":"));
	GetDlgItem(IDC_STATIC_VPORCH)->SetWindowText(m_Delegate->GetTranslationString(_T("410"),_T("��ֱǰ��"))+_T(":"));
	GetDlgItem(IDC_STATIC_VPOLARIT)->SetWindowText(m_Delegate->GetTranslationString(_T("411"),_T("��ֱ�����"))+_T(":"));
	GetDlgItem(IDC_STATIC_VZONG)->SetWindowText(m_Delegate->GetTranslationString(_T("412"),_T("��ֱ����"))+_T(":"));
	GetDlgItem(IDC_STATIC_VWITH)->SetWindowText(m_Delegate->GetTranslationString(_T("413"),_T("��ֱͬ�����"))+_T(":"));
	GetDlgItem(IDC_STATIC_VSYNC)->SetWindowText(m_Delegate->GetTranslationString(_T("414"),_T("��ֱͬ������"))+_T(":"));
	GetDlgItem(IDC_STATIC_REFRESH)->SetWindowText(m_Delegate->GetTranslationString(_T("416"),_T("ˢ��Ƶ��"))+_T(":"));
	GetDlgItem(IDC_BUTTON_OK)->SetWindowText(m_Delegate->GetTranslationString(_T("208"),_T("ȷ��")));
	GetDlgItem(IDC_BUTTON_CENCLE)->SetWindowText(m_Delegate->GetTranslationString(_T("209"),_T("ȡ��")));
	GetDlgItem(IDC_STATIC_MATRIXMODEL)->SetWindowText(m_Delegate->GetTranslationString(_T("709"),_T("ģʽ"))+_T(":"));
}

void XMatrixAllResolution::OnBtnOK()
{
	int nComboIndex=m_Combo_Index.GetCurSel();

	int nComboRefresh=m_Combo_Refresh.GetCurSel();
	CString szRefreash=_T("");
	m_Combo_Refresh.GetLBText(nComboRefresh,szRefreash);
	int nRefreash=_ttoi(szRefreash);

	int nComboModel=m_Combo_Model.GetCurSel();
	//////////////////////////////////////////////////////////////////////////
	CString szHResulation;
	GetDlgItem(IDC_EDIT_HRESULATION)->GetWindowText(szHResulation);
	szHResulation.Trim();
	if(szHResulation==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("417"),_T("ˮƽ�ֱ��ʲ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_HRESULATION)->SetFocus();
		return;
	}
	int nResolutionH=_ttoi(szHResulation);
	//////////////////////////////////////////////////////////////////////////
	CString szVResulation;
	GetDlgItem(IDC_EDIT_VRESULATION)->GetWindowText(szVResulation);
	szVResulation.Trim();
	if(szVResulation==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("419"),_T("��ֱ�ֱ��ʲ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_VRESULATION)->SetFocus();
		return;
	}
	int nResolutionV=_ttoi(szVResulation);
	//////////////////////////////////////////////////////////////////////////
	CString szHFProch;
	GetDlgItem(IDC_EDIT_HPORCH)->GetWindowText(szHFProch);
	if(szHFProch==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("420"),_T("ˮƽǰ�ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_HPORCH)->SetFocus();
		return;
	}
	int nHFPorch=_ttoi(szHFProch);
	//////////////////////////////////////////////////////////////////////////
	CString szVFPorch;
	GetDlgItem(IDC_EDIT_VPORCH)->GetWindowText(szVFPorch);
	if(szVFPorch==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("421"),_T("��ֱǰ�ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_VPORCH)->SetFocus();
		return;
	}
	int nVFPorch=_ttoi(szVFPorch);
	//////////////////////////////////////////////////////////////////////////
	CString szHpixel;
	GetDlgItem(IDC_EDIT_HPOLARITY)->GetWindowText(szHpixel);
	if(szHpixel==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("422"),_T("ˮƽ����ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetFocus();
		return;
	}
	int nHpixel=_ttoi(szHpixel);
	//////////////////////////////////////////////////////////////////////////
	CString szVpixel;
	GetDlgItem(IDC_EDIT_VPOLARITY)->GetWindowText(szVpixel);
	if(szVpixel==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("423"),_T("��ֱ����ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetFocus();
		return;
	}
	int nVPixel=_ttoi(szVpixel);
	//////////////////////////////////////////////////////////////////////////
	CString szHBForch;
	GetDlgItem(IDC_EDIT_HTOTAL)->GetWindowText(szHBForch);
	if(szHBForch==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("424"),_T("ˮƽ���ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_HTOTAL)->SetFocus();
		return;
	}
	int nHBPorch=_ttoi(szHBForch);
	//////////////////////////////////////////////////////////////////////////
	CString szVBForch;
	GetDlgItem(IDC_EDIT_VTOTAL)->GetWindowText(szVBForch);
	if(szVBForch==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("425"),_T("��ֱ���ز���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_VTOTAL)->SetFocus();
		return;
	}
	int nVBProch=_ttoi(szVBForch);
	//////////////////////////////////////////////////////////////////////////
	CString szHSyncTime;
	GetDlgItem(IDC_EDIT_HWITH)->GetWindowText(szHSyncTime);
	if(szHSyncTime==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("426"),_T("ˮƽͬ����Ȳ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_HWITH)->SetFocus();
		return;
	}
	int nHSyncTime=_ttoi(szHSyncTime);
	//////////////////////////////////////////////////////////////////////////
	CString szVSyncTime;
	GetDlgItem(IDC_EDIT_VWITH)->GetWindowText(szVSyncTime);
	if(szVSyncTime==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("427"),_T("��ֱͬ����Ȳ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_VWITH)->SetFocus();
		return;
	}
	int nVSyncTime=_ttoi(szVSyncTime);
	//////////////////////////////////////////////////////////////////////////
	CString szHSyncPolarity;
	GetDlgItem(IDC_EDIT_HSYNC)->GetWindowText(szHSyncPolarity);
	if(szHSyncPolarity==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("428"),_T("ˮƽͬ�����Բ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_HSYNC)->SetFocus();
		return;
	}
	int nHSyncPolarity=_ttoi(szHSyncPolarity);
	//////////////////////////////////////////////////////////////////////////
	CString szVSyncPolarity;
	GetDlgItem(IDC_EDIT_VSYNC)->GetWindowText(szVSyncPolarity);
	if(szVSyncPolarity==_T(""))
	{
		m_Delegate->MessageBoxFromKey(_T("429"),_T("��ֱͬ�����Բ���Ϊ�գ�"),MB_OK);
		GetDlgItem(IDC_EDIT_VSYNC)->SetFocus();
		return;
	}
	int nVSyncPolarity=_ttoi(szVSyncPolarity);
	//////////////////////////////////////////////////////////////////////////
	if(m_Combo_Index.GetCurSel()==0)
	{
		if(nResolutionH!=800&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("ˮƽ�ֱ��ʲ��ܳ����߼�ѡ���е�ˮƽ����أ����������ã�"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==1)
	{
		if(nResolutionH!=1024&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("ˮƽ�ֱ��ʲ��ܳ����߼�ѡ���е�ˮƽ����أ����������ã�"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==2||m_Combo_Index.GetCurSel()==3
		||m_Combo_Index.GetCurSel()==4||m_Combo_Index.GetCurSel()==5)
	{
		if(nResolutionH!=1280&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("�����ø߼�ѡ���е�ˮƽ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==6)
	{
		if(nResolutionH!=1360&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("�����ø߼�ѡ���е�ˮƽ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==7)
	{
		if(nResolutionH!=1366&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("�����ø߼�ѡ���е�ˮƽ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==8||m_Combo_Index.GetCurSel()==9)
	{
		if(nResolutionH!=1440&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("�����ø߼�ѡ���е�ˮƽ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==10)
	{
		if(nResolutionH!=1400&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("�����ø߼�ѡ���е�ˮƽ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==11)
	{
		if(nResolutionH!=1680&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("�����ø߼�ѡ���е�ˮƽ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==12||m_Combo_Index.GetCurSel()==13)
	{
		if(nResolutionH!=1920&&nResolutionH>nHpixel)
		{
			m_Delegate->MessageBoxFromKey(_T("418"),_T("�����ø߼�ѡ���е�ˮƽ������Լ�����������"),MB_OK);
			return;
		}
	}
	////////////////////////////////////////////////////////////////////////
	if(m_Combo_Index.GetCurSel()==0)
	{
		if(nResolutionV!=600&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==1||m_Combo_Index.GetCurSel()==3
		||m_Combo_Index.GetCurSel()==6||m_Combo_Index.GetCurSel()==7)
	{
		if(nResolutionV!=768&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==2)
	{
		if(nResolutionV!=720&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==4)
	{
		if(nResolutionV!=800&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==5)
	{
		if(nResolutionV!=1024&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==8||m_Combo_Index.GetCurSel()==10)
	{
		if(nResolutionV!=900&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==9||m_Combo_Index.GetCurSel()==11)
	{
		if(nResolutionV!=1050&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==12)
	{
		if(nResolutionV!=1080&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	else if(m_Combo_Index.GetCurSel()==13)
	{
		if(nResolutionV!=1200&&nResolutionV>nVPixel)
		{
			m_Delegate->MessageBoxFromKey(_T("430"),_T("�����ø߼�ѡ���еĴ�ֱ������Լ�����������"),MB_OK);
			return;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	XAllResulationInfo* pResulation=m_pScreenManage->GetAllResulationInfo();
	pResulation->SetResolutionH(nResolutionH);
	pResulation->SetResolutionV(nResolutionV);
	pResulation->SetHFPorch(nHFPorch);
	pResulation->SetVFPorch(nVFPorch);
	pResulation->SetHSyncTime(nHSyncTime);
	pResulation->SetVSyncTime(nVSyncTime);
	pResulation->SetHBPorch(nHBPorch);
	pResulation->SetVBProch(nVBProch);
	pResulation->SetHSyncPolarity(nHSyncPolarity);
	pResulation->SetVSyncPolarity(nVSyncPolarity);
	pResulation->SetHpixel(nHpixel);
	pResulation->SetVPixel(nVPixel);
	pResulation->SetComboIndex(nComboIndex);
	pResulation->SetComboRefresh(nComboRefresh);
	pResulation->SetComboModel(nComboModel);
	pResulation->SetRefreash(nRefreash);

	CDialogEx::OnOK();
}

void XMatrixAllResolution::OnBtnCancle()
{
	CDialogEx::OnCancel();
}

void XMatrixAllResolution::OnClickedExpand()
{
	CString str;

	GetDlgItemText(IDC_STATIC_EXPAND,str);

	if(str==_T("�߼�ѡ��>>"))
	{
		SetDlgItemText(IDC_STATIC_EXPAND,_T("�߼�ѡ��<<"));
	}
	else if(str==_T("�߼�ѡ��<<"))
	{
		SetDlgItemText(IDC_STATIC_EXPAND,_T("�߼�ѡ��>>"));
	}
	if(str==(_T("Advanced settings>>")))
	{
		SetDlgItemText(IDC_STATIC_EXPAND,_T("Advanced settings<<"));
	}
	else if(str==(_T("Advanced settings<<")))
	{
		SetDlgItemText(IDC_STATIC_EXPAND,_T("Advanced settings>>"));
	}
	if(str==(_T("�߼��x�>>")))
	{
		SetDlgItemText(IDC_STATIC_EXPAND,_T("�߼��x�<<"));
	}
	else if(str==(_T("�߼��x�<<")))
	{
		SetDlgItemText(IDC_STATIC_EXPAND,_T("�߼��x�>>"));
	}

	CRect rtSmall;
	rtSmall.SetRectEmpty();
	if (rtSmall.IsRectEmpty())
	{
		rtSmall.left = m_Rect.left;
		rtSmall.top = m_Rect.top;
		rtSmall.right = m_Rect.right;
		rtSmall.bottom = m_ExpaneRect.bottom+10;
	}

	if(str==_T("�߼�ѡ��<<"))
	{
		SetWindowPos(NULL, 0, 0, rtSmall.Width(), rtSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	if(str==_T("�߼�ѡ��>>"))
	{
		SetWindowPos(NULL, 0, 0, m_Rect.Width(), m_Rect.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	if(str==_T("Advanced settings<<"))
	{
		SetWindowPos(NULL, 0, 0, rtSmall.Width(), rtSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	if(str==_T("Advanced settings>>"))
	{
		SetWindowPos(NULL, 0, 0, m_Rect.Width(), m_Rect.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	if(str==_T("�߼��x�<<"))
	{
		SetWindowPos(NULL, 0, 0, rtSmall.Width(), rtSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	if(str==_T("�߼��x�>>"))
	{
		SetWindowPos(NULL, 0, 0, m_Rect.Width(), m_Rect.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
}

void XMatrixAllResolution::OnSelchangeIndex()
{
	CString nSelectStr=_T("");
	m_Combo_Index.GetLBText(m_Combo_Index.GetCurSel(),nSelectStr);

	int nResulationIndex=m_Combo_Index.GetCurSel();

	if(nResulationIndex==0)//800 600
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("800"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("600"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("40"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("800"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("600"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("88"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("23"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("128"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("4"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==1)//1024 768
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1024"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("24"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1024"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("160"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("29"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("136"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("6"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("0"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("0"));
	}
	else if(nResulationIndex==2)//1280 720
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.AddString(_T("50"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("720"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("110"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("5"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("720"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("220"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("20"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("40"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==3)//1280 768
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("64"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("192"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("20"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("112"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("6"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("0"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==4)//1280 800
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("800"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("72"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("800"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("200"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("22"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("128"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("6"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("0"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==5)//1280 1024
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("1024"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("48"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1280"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1024"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("248"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("38"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("112"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==6)//1360 768
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1360"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("64"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1360"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("256"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("18"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("112"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("6"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==7)//1366 768
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1366"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("70"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1366"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("768"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("213"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("24"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("143"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("13"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==8)//1440 900
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1440"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("900"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("80"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1440"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("900"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("232"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("25"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("152"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("6"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("0"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==9)//1440 1050
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1440"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("1050"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("80"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1440"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1050"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("232"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("32"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("144"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("4"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("0"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==10)//1600 900
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1600"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("900"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("48"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1600"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("900"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("80"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("18"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("32"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("0"));
	}
	else if(nResulationIndex==11)//1680 1050
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1680"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("1050"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("104"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1680"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1050"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("280"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("30"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("176"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("6"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("0"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==12)//1920 1080
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.AddString(_T("50"));
		m_Combo_Refresh.AddString(_T("30"));
		m_Combo_Refresh.AddString(_T("25"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1920"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("1080"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("88"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("4"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1920"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1080"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("148"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("36"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("44"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
	}
	else if(nResulationIndex==13)//1920 1200
	{
		m_Combo_Refresh.ResetContent();
		m_Combo_Refresh.AddString(_T("60"));
		m_Combo_Refresh.SetCurSel(0);
		//////////////////////////////////////////////////////////////////////////
		GetDlgItem(IDC_EDIT_HRESULATION)->SetWindowText(_T("1920"));
		GetDlgItem(IDC_EDIT_VRESULATION)->SetWindowText(_T("1200"));
		GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("48"));
		GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("3"));
		GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1920"));
		GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1200"));
		GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("80"));
		GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("26"));
		GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("32"));
		GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("6"));
		GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
		GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("0"));
	}
}

void XMatrixAllResolution::OnSelchangeRefresh()
{
	CString nSelectStr=_T("");
	m_Combo_Refresh.GetLBText(m_Combo_Refresh.GetCurSel(),nSelectStr);

	if(m_Combo_Index.GetCurSel()==2)
	{
		if(nSelectStr==_T("60"))
		{
			GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("110"));
			GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1080"));
			GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("720"));
			GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("220"));
			GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("20"));
			GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("40"));
			GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
			GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
		}
		else if(nSelectStr==_T("50"))
		{
			GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("440"));
			GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1080"));
			GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("720"));
			GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("220"));
			GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("20"));
			GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("40"));
			GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
			GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
		}
	}

	if(m_Combo_Index.GetCurSel()==12)
	{
		if(nSelectStr==_T("60"))
		{
			GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("88"));
			GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("4"));
			GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1920"));
			GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1080"));
			GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("148"));
			GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("36"));
			GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("44"));
			GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
			GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
		}
		else if(nSelectStr==_T("50"))
		{
			GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("528"));
			GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("4"));
			GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1920"));
			GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1080"));
			GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("148"));
			GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("36"));
			GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("44"));
			GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
			GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
		}
		else if(nSelectStr==_T("30"))
		{
			GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("88"));
			GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("4"));
			GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1920"));
			GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1080"));
			GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("148"));
			GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("36"));
			GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("44"));
			GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
			GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
		}
		else if (nSelectStr==_T("25"))
		{
			GetDlgItem(IDC_EDIT_HPORCH)->SetWindowText(_T("528"));
			GetDlgItem(IDC_EDIT_VPORCH)->SetWindowText(_T("4"));
			GetDlgItem(IDC_EDIT_HPOLARITY)->SetWindowText(_T("1920"));
			GetDlgItem(IDC_EDIT_VPOLARITY)->SetWindowText(_T("1080"));
			GetDlgItem(IDC_EDIT_HTOTAL)->SetWindowText(_T("148"));
			GetDlgItem(IDC_EDIT_VTOTAL)->SetWindowText(_T("36"));
			GetDlgItem(IDC_EDIT_HWITH)->SetWindowText(_T("44"));
			GetDlgItem(IDC_EDIT_VWITH)->SetWindowText(_T("5"));
			GetDlgItem(IDC_EDIT_HSYNC)->SetWindowText(_T("1"));
			GetDlgItem(IDC_EDIT_VSYNC)->SetWindowText(_T("1"));
		}
	}
}
