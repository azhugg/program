#include "StdAfx.h"
#include "XRibbonBarManage.h"
#include "XDelegateRibbonBarManage.h"
#include "../resource.h"

XRibbonBarManage::XRibbonBarManage(void)
{
	m_pCategoryMain = nullptr;
	m_pPanelMainSet = nullptr;
	m_pComboBoxLanguage = nullptr;
	m_pComboBoxScale = nullptr;
	m_pPanelMainOperator = nullptr;
	m_pPanelMainNet = nullptr;
	m_pBtnOpenNet = nullptr;
	m_pBtnCloseNet = nullptr;
	m_pEditDeviceIP = nullptr;
	m_pEditDevicePort = nullptr;
	m_pBtnDeleteAllSignal = nullptr;
	m_pBtnTemperature = nullptr;
	m_pEditInputCount = nullptr;
	m_pEditOutputCountH = nullptr;
	m_pEditOutputCountV = nullptr;
	m_pPanelMainUser = nullptr;
	m_pBtnLogin = nullptr;
	m_pBtnLogout = nullptr;
	m_pBtnUserManage = nullptr;
	m_pBtnPowerManage = nullptr;
	m_pPanelMainScene=NULL;
	m_pBtnSaveScence=NULL;
	m_pBtnOpenScence=NULL;
	m_pBtnScreenMove=NULL;
	m_pBtnTimedPolling=NULL;
	m_pBtnScreenMove=NULL;
	m_pPanelMainStatus=NULL;
	m_pBtnPan=NULL;
	m_pBtnChip=NULL;
	m_pBtnScreenResulation=NULL;
	m_pBtnOldOrder=NULL;
	m_pPaneModel=NULL;
	m_pBtnNamal=NULL;
	m_pBtnFull=NULL;
	m_pBtnFoure=NULL;
	m_pBtnInter=NULL;
	m_pPaneDrag=NULL;
	m_pBtnTip=NULL;
	m_pBtnUp=NULL;
	m_pBtnDown=NULL;
	m_pBtnInterScene=NULL;
	m_pBtnCopy=NULL;
	m_pSingleScene=NULL;
}

XRibbonBarManage::~XRibbonBarManage(void)
{

}

void XRibbonBarManage::Init()
{
	InitRibbonBar();

	//InitStatusBar();
}

void XRibbonBarManage::InitRibbonBar()
{
	m_wndRibbonBar.Create(GetCWND());

	m_wndRibbonBar.SetDelegate(this);

	InitRibbonBar(&m_wndRibbonBar);
}

void XRibbonBarManage::InitStatusBar()
{
	m_wndStatusBar.Create(GetCWND());
}

void XRibbonBarManage::InitRibbonBar(CMFCRibbonBar* pRibbonBar)
{
	//�Ƴ����пؼ�
	pRibbonBar->RemoveAllCategories();
	pRibbonBar->RemoveAllFromTabs();

	//tab bar
	m_pBtnAbout = new CMFCRibbonButton(ID_BTN_ABOUT, _T(""), AfxGetApp()->LoadIcon(IDI_ICON_ABOUT));
	pRibbonBar->AddToTabs(m_pBtnAbout);

	//main
	m_pCategoryMain = pRibbonBar->AddCategory(GetTranslationString(_T("226"), _T("��ҳ")), 0, 0);

	//main main set
	m_pPanelMainSet = m_pCategoryMain->AddPanel(GetTranslationString(_T("227"), _T("����")));

	m_pPanelMainSet->SetJustifyColumns(TRUE);

	m_pBtnNewView=new CMFCRibbonButton(ID_BTN_NEWVIEW,GetTranslationString(_T("498"), _T("�½�ƴ����")),AfxGetApp()->LoadIcon(IDI_ICON_NEW));
	m_pPanelMainSet->Add(m_pBtnNewView);

	//m_pBtnCloseView=new CMFCRibbonButton(ID_BTN_CLOSEVIEW,GetTranslationString(_T("522"), _T("�ر���ͼ")));
	//m_pPanelMainSet->Add(m_pBtnCloseView); 

	m_pPanelMainSet->AddSeparator();

	m_pComboBoxLanguage = new CMFCRibbonComboBox(ID_COMBO_LANGUAGE, FALSE, 70, GetTranslationString(_T("228"), _T("����")) + _T(":"));
	m_pPanelMainSet->Add(m_pComboBoxLanguage);

	m_pComboBoxScale = new CMFCRibbonComboBox(ID_COMBO_SCALE, FALSE, 70, GetTranslationString(_T("229"), _T("����")) + _T(":"));
	m_pPanelMainSet->Add(m_pComboBoxScale);

	//m_pComboBoxView=new CMFCRibbonComboBox(ID_COMBO_VIEW,FALSE,70,GetTranslationString(_T("497"), _T("��ͼ")) + _T(":"));
	//m_pPanelMainSet->Add(m_pComboBoxView);

	//�û�
	m_pPanelMainUser = m_pCategoryMain->AddPanel(GetTranslationString(_T("343"), _T("�û�")));

	m_pPanelMainUser->SetJustifyColumns(TRUE);

	m_pBtnLogin = new CMFCRibbonButton(ID_BTN_LOGIN, GetTranslationString(_T("344"), _T("��½")));
	m_pPanelMainUser->Add(m_pBtnLogin);

	m_pBtnLogout = new CMFCRibbonButton(ID_BTN_LOGOUT, GetTranslationString(_T("345"), _T("ע��")));
	m_pPanelMainUser->Add(m_pBtnLogout);

	m_pPanelMainUser->AddSeparator();

	m_pBtnUserManage = new CMFCRibbonButton(ID_BTN_USERMANAGE, GetTranslationString(_T("346"), _T("�û�����")));
	m_pPanelMainUser->Add(m_pBtnUserManage);

	//m_pBtnPowerManage = new CMFCRibbonButton(ID_BTN_POWERMANAGE, GetTranslationString(_T("347"), _T("Ȩ�޹���")));
	//m_pPanelMainUser->Add(m_pBtnPowerManage);

	//main multiviewer
	m_pPanelMainMultiviewer = m_pCategoryMain->AddPanel(GetTranslationString(_T("336"), _T("����")));

	m_pPanelMainMultiviewer->SetJustifyColumns(TRUE);

	m_pEditInputCount = new CMFCRibbonEdit(ID_EDIT_INPUTCOUNT, 60, GetTranslationString(_T("337"), _T("�������"))+ _T(":"));
	m_pPanelMainMultiviewer->Add(m_pEditInputCount);

	m_pEditOutputCountH = new CMFCRibbonEdit(ID_EDIT_OUTPUTCOUNTH, 60, GetTranslationString(_T("341"), _T("ˮƽ�������"))+ _T(":"));
	m_pPanelMainMultiviewer->Add(m_pEditOutputCountH);

	m_pEditOutputCountV = new CMFCRibbonEdit(ID_EDIT_OUTPUTCOUNTV, 60, GetTranslationString(_T("340"), _T("��ֱ�������"))+ _T(":"));
	m_pPanelMainMultiviewer->Add(m_pEditOutputCountV);

	//main device
	m_pPanelMainDevice = m_pCategoryMain->AddPanel(GetTranslationString(_T("248"), _T("�豸����")));

	m_pPanelMainDevice->SetJustifyColumns(TRUE);

	m_pEditDeviceIP = new CMFCRibbonEdit(ID_EDIT_DEVICEIP, 100, GetTranslationString(_T("249"), _T("�豸IP")));
	m_pPanelMainDevice->Add(m_pEditDeviceIP);

	m_pEditDevicePort = new CMFCRibbonEdit(ID_EDIT_DEVICEPORT, 100, GetTranslationString(_T("252"), _T("�豸�˿�")));
	m_pPanelMainDevice->Add(m_pEditDevicePort);

	m_pPanelMainDevice->AddSeparator();

	m_pBtnOpenNet = new CMFCRibbonButton(ID_BTN_OPENNET, GetTranslationString(_T("234"), _T("��")));
	m_pPanelMainDevice->Add(m_pBtnOpenNet);

	m_pBtnCloseNet = new CMFCRibbonButton(ID_BTN_CLOSENET, GetTranslationString(_T("235"), _T("�ر�")));
	m_pPanelMainDevice->Add(m_pBtnCloseNet);

	////����
	//m_pPanelMainScene=m_pCategoryMain->AddPanel(GetTranslationString(_T("388"), _T("����")));

	//m_pPanelMainScene->SetJustifyColumns(TRUE);

	//m_pBtnSaveScence=new CMFCRibbonButton(ID_BTN_SAVESCENCE,GetTranslationString(_T("386"), _T("���泡��")));
	//m_pPanelMainScene->Add(m_pBtnSaveScence);

	//m_pBtnOpenScence=new CMFCRibbonButton(ID_BTN_OPENSCENCE,GetTranslationString(_T("387"), _T("�򿪳���")));
	//m_pPanelMainScene->Add(m_pBtnOpenScence);

	//m_pBtnDeleteScence=new CMFCRibbonButton(ID_BTN_DELETESCENE,GetTranslationString(_T("495"), _T("ɾ������")));
	//m_pPanelMainScene->Add(m_pBtnDeleteScence);

	//����
	m_pPanelMainOperator = m_pCategoryMain->AddPanel(GetTranslationString(_T("236"), _T("����")));
	
	m_pPanelMainOperator->SetJustifyColumns(TRUE);

	m_pBtnScreenMove=new CMFCRibbonButton(ID_BTN_SETMOVEPARAMATER,GetTranslationString(_T("446"),_T("���ù�������")));
	m_pPanelMainOperator->Add(m_pBtnScreenMove);

	//m_pPanelMainOperator->AddSeparator();

	m_pBtnScreenResulation=new CMFCRibbonButton(ID_BTN_SETSCREENRESULATION, GetTranslationString(_T("501"), _T("��Ļ�ֱ���")));
	m_pPanelMainOperator->Add(m_pBtnScreenResulation);

	m_pBtnOldOrder=new CMFCRibbonButton(ID_BTN_OLDORDER, GetTranslationString(_T("500"), _T("ִ�о���ָ��")));
	m_pPanelMainOperator->Add(m_pBtnOldOrder);

	m_pPanelMainOperator->AddSeparator();

	m_pBtnTimedPolling=new CMFCRibbonButton(ID_TIMEDPOLLING,GetTranslationString(_T("464"),_T("��ʱ��ѯ���")));
	m_pPanelMainOperator->Add(m_pBtnTimedPolling);

	m_pBtnDeleteAllSignal = new CMFCRibbonButton(ID_BTN_DELETEALLSIGNAL, GetTranslationString(_T("270"), _T("ɾ�������ź�")));
	m_pPanelMainOperator->Add(m_pBtnDeleteAllSignal);

	//ƴ��
	m_pPaneModel=m_pCategoryMain->AddPanel(GetTranslationString(_T("735"), _T("ƴ��")));

	m_pPaneModel->SetJustifyColumns(TRUE);

	m_pBtnNamal=new CMFCRibbonButton(ID_BTN_NAMAL,GetTranslationString(_T("705"), _T("Ĭ��ģʽ")));

	m_pPaneModel->Add(m_pBtnNamal);

	m_pBtnFoure=new CMFCRibbonButton(ID_BTN_FOUR,GetTranslationString(_T("706"),_T("�ȷ�ģʽ")));

	m_pPaneModel->Add(m_pBtnFoure);

	m_pBtnFull=new CMFCRibbonButton(ID_BTN_FULL,GetTranslationString(_T("707"),_T("ȫ��ģʽ")));

	m_pPaneModel->Add(m_pBtnFull);

	m_pPaneModel->AddSeparator();

	m_pBtnInter=new CMFCRibbonButton(ID_BTN_INTER,GetTranslationString(_T("734"),_T("����ģʽ")));

	m_pPaneModel->Add(m_pBtnInter);

	m_pBtnCopy=new CMFCRibbonButton(ID_BTN_COPY,GetTranslationString(_T("741"),_T("����ģʽ")));

	m_pPaneModel->Add(m_pBtnCopy);

	//��קģʽ
	m_pPaneModel=m_pCategoryMain->AddPanel(GetTranslationString(_T("736"), _T("��קģʽ")));

	m_pPaneModel->SetJustifyColumns(TRUE);

	m_pBtnNamal=new CMFCRibbonButton(ID_BTN_TIPMODEL,GetTranslationString(_T("737"), _T("����ģʽ")));

	m_pPaneModel->Add(m_pBtnNamal);

	m_pBtnUp=new CMFCRibbonButton(ID_BTN_UPMODEL,GetTranslationString(_T("738"), _T("ɾ������")));

	m_pPaneModel->Add(m_pBtnUp);

	m_pBtnDown=new CMFCRibbonButton(ID_BTN_DOWNMODEL,GetTranslationString(_T("739"), _T("ɾ���ײ�")));

	m_pPaneModel->Add(m_pBtnDown);

	//Ԥ��
	m_pPanelMainPreview=m_pCategoryMain->AddPanel(GetTranslationString(_T("334"), _T("Ԥ��")));

	m_pPanelMainPreview->SetJustifyColumns(TRUE);

	m_pBtnPreview=new CMFCRibbonButton(ID_BTN_PREVIEW,GetTranslationString(_T("329"),_T("���Ԥ����")));

	m_pPanelMainPreview->Add(m_pBtnPreview);


	//����
	m_pPanelMainScene = m_pCategoryMain->AddPanel(GetTranslationString(_T("760"), _T("��������")));

	m_pPanelMainScene->SetJustifyColumns(TRUE);

	m_pSingleScene=new CMFCRibbonButton(ID_SIGNLESCENE,GetTranslationString(_T("745"),_T("��ҳ�泡��")));
	m_pPanelMainScene->Add(m_pSingleScene);

	m_pBtnInterScene=new CMFCRibbonButton(ID_BTN_ALLSCENE,GetTranslationString(_T("740"),_T("��ҳ�泡��")));
	m_pPanelMainScene->Add(m_pBtnInterScene);

	//״̬
	m_pPanelMainStatus=m_pCategoryMain->AddPanel(GetTranslationString(_T("679"), _T("�豸״̬")));

	m_pPanelMainStatus->SetJustifyColumns(TRUE);

	m_pBtnChip=new CMFCRibbonButton(ID_BTN_CHIP,_T(""),AfxGetApp()->LoadIcon(IDI_ICON_CHIP));

	m_pPanelMainStatus->Add(m_pBtnChip);

	m_pBtnPan=new CMFCRibbonButton(ID_BTN_PAN,_T(""),AfxGetApp()->LoadIcon(IDI_ICON_PAN));

	m_pPanelMainStatus->Add(m_pBtnPan);

	//�¶�
	m_pPanelMainTemperature = m_pCategoryMain->AddPanel(GetTranslationString(_T("274"), _T("�¶�")));

	m_pPanelMainTemperature->SetJustifyColumns(TRUE);

	m_pBtnTemperature = new CMFCRibbonButton(ID_BTN_TEMPERATURE, _T(""), AfxGetApp()->LoadIcon(IDI_ICON_TEMPERATURE));
	m_pPanelMainTemperature->Add(m_pBtnTemperature);

	//��������
	pRibbonBar->ForceRecalcLayout();
}

CWnd* XRibbonBarManage::GetCWND()
{
	return m_pDelegate->GetCWND();
}

CString XRibbonBarManage::GetTranslationString(CString szKey, CString szDefault)
{
	return m_pDelegate->GetTranslationString(szKey, szDefault);
}

void XRibbonBarManage::UpdateControlDataShowOfAll()
{
	UpdateControlDataShow(XDATATYPE_LANGUAGENAME);

	UpdateControlDataShow(XDATATYPE_SCALE);

	UpdateControlDataShow(XDATATYPE_DEVICEIP);

	UpdateControlDataShow(XDATATYPE_DEVICEPORT);

	UpdateControlDataShow(XDATATYPE_INPUTCOUNT);

	UpdateControlDataShow(XDATATYPE_OUTPUTCOUNTH);

	UpdateControlDataShow(XDATATYPE_OUTPUTCOUNTV);

	//UpdateControlDataShow(XDATATYPE_VIEW);
}

void XRibbonBarManage::ReloadInterface()
{
	InitRibbonBar(&m_wndRibbonBar);

	UpdateControlDataShowOfAll();
}

void XRibbonBarManage::RibbonBarShowCategory(CString szName)
{
	m_pDelegate->RibbonBarShowCategory(szName);
}

void XRibbonBarManage::SetTemperatureInfo(CString s)
{
	m_pBtnTemperature->SetText(s);

	m_pBtnTemperature->Redraw();
}

void XRibbonBarManage::SetPanInfo(CString s)
{
	int nPanStatus=_ttoi(s);

	if(nPanStatus==0)
	{
		m_pBtnPan->SetText(GetTranslationString(_T("515"),_T("����")));

		m_pBtnPan->Redraw();
	}
	else
	{
		m_pBtnPan->SetText(GetTranslationString(_T("516"),_T("�쳣")));

		m_pBtnPan->Redraw();
	}
}

void XRibbonBarManage::SetChipInfo(CString s)
{
	int nChipStatus=_ttoi(s);

	if(nChipStatus==0)
	{
		m_pBtnChip->SetText(GetTranslationString(_T("515"),_T("����")));

		m_pBtnChip->Redraw();
	}
	else
	{
		m_pBtnChip->SetText(GetTranslationString(_T("516"),_T("�쳣")));

		m_pBtnChip->Redraw();
	}
}

//////////////////////////////////////////////////////////////////////////////////
void XRibbonBarManage::UpdateControlDataShow(XDATATYPE type)
{
	switch(type)
	{
	case XDATATYPE_ALL:
		{
			UpdateControlDataShowOfAll();
		}
		break;
	case XDATATYPE_LANGUAGENAME:
		{
			m_pDelegate->UpdateControlDataShow(type, m_pComboBoxLanguage);
		}
		break;
	case XDATATYPE_SCALE:
		{
			m_pDelegate->UpdateControlDataShow(type, m_pComboBoxScale);
		}
		break;
	case XDATATYPE_DEVICEIP:
		{
			m_pDelegate->UpdateControlDataShow(type, m_pEditDeviceIP);
		}
		break;
	case XDATATYPE_DEVICEPORT:
		{
			m_pDelegate->UpdateControlDataShow(type, m_pEditDevicePort);
		}
		break;
	case XDATATYPE_INPUTCOUNT:
		{
			m_pDelegate->UpdateControlDataShow(type, m_pEditInputCount);
		}
		break;
	case XDATATYPE_OUTPUTCOUNTH:
		{
			m_pDelegate->UpdateControlDataShow(type, m_pEditOutputCountH);
		}
		break;
	case XDATATYPE_OUTPUTCOUNTV:
		{
			m_pDelegate->UpdateControlDataShow(type, m_pEditOutputCountV);
		}
		break;
	//case XDATATYPE_VIEW:
	//	{
	//		m_pDelegate->UpdateControlDataShow(type, m_pComboBoxView);
	//	}
	//	break;
	default:
		break;
	}
}

void XRibbonBarManage::ControlDataChange(XDATATYPE type)
{
	switch(type)
	{
	case XDATATYPE_LANGUAGENAME:
		{
			m_pDelegate->ControlDataChange(type, m_pComboBoxLanguage);
		}
		break;
	case XDATATYPE_SCALE:
		{
			m_pDelegate->ControlDataChange(type, m_pComboBoxScale);
		}
		break;
	case XDATATYPE_DEVICEIP:
		{
			m_pDelegate->ControlDataChange(type, m_pEditDeviceIP);
		}
		break;
	case XDATATYPE_DEVICEPORT:
		{
			m_pDelegate->ControlDataChange(type, m_pEditDevicePort);
		}
		break;
	case XDATATYPE_INPUTCOUNT:
		{
			m_pDelegate->ControlDataChange(type, m_pEditInputCount);
		}
		break;
	case XDATATYPE_OUTPUTCOUNTH:
		{
			m_pDelegate->ControlDataChange(type, m_pEditOutputCountH);
		}
		break;
	case XDATATYPE_OUTPUTCOUNTV:
		{
			m_pDelegate->ControlDataChange(type, m_pEditOutputCountV);
		}
		break;
	default:
		break;
	}
}

void XRibbonBarManage::Operate(OPERATETYPE type, void* pData)
{
	switch(type)
	{
	case OPERATETYPE_SETTEMPERATURE:
		{
			SetTemperatureInfo(*((CString*)pData));
		}
		break;
	case OPERATETYPE_REFRESHPAN:
		{
			SetPanInfo(*((CString*)pData));
		}
		break;
	case OPERATETYPE_REFRESHCHIP:
		{
			SetChipInfo(*((CString*)pData));
		}
		break;
	default:
		break;
	}
}