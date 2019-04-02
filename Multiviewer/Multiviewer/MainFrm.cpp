// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Multiviewer.h"

#include "MainFrm.h"
#include "XInternalManage.h"
#include "MultiviewerView.h"
#include "XConstantIM.h"
#include "HandleIni.h"
#include "HandlePath.h"
#include "MultiviewerDoc.h"
#include "XBaseScreenManage.h"

//��ʱ��
#define TIMERID_DEVICESTATUS				1//��ȡ�豸״̬
#define TIMERELAPSE_DEVICESTATUS			2000

//////////////////////////////////////////////////////////////////////////
#define TIMERID_GETSIGNALPAREMATER          2//��ȡ��������
#define TIMERELAPSE_GETSIGNALPAREMATER      2000
//////////////////////////////////////////////////////////////////////////
#define TIMERID_GETWINDOWPARAMATER          3//��ȡ��������
#define TIMERELAPSE_GETWINDOWPARAMATER      4000

#define TIMERID_GETOUTPUTPARAMATER          4//��ȡ�������
#define TIMERELAPSE_GETOUTPUTPARAMATER      3000
//////////////////////////////////////////////////////////////////////////
#define TIMERID_GETSCENEINDEX               5
#define TIMERELAPSE_GETSCENEINDEX           4000
//////////////////////////////////////////////////////////////////////////
#define TIMERID_SETINPUTICON                6//ˢ������ͼ��
#define TIMERELAPSE_SETINPUTICON            2000

//////////////////////////////////////////////////////////////////////////
#define TIMERID_GETINPUTNUM                 7//��ȡ��Ļ���
#define TIMERSPACE_GETINPUTNUM              500

//////////////////////////////////////////////////////////////////////////
#define TIMERID_MATRIXOUTPUT                9//��ȡ������Ļ״̬
#define TIMERSPACE_MATRIXOUTPUT             3000

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CMDIFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_REGISTERED_MESSAGE(AFX_WM_TOOLBARMENU, OnToolbarContextMenu)
	ON_MESSAGE(MSG_ADDDOCUMENT,&CMainFrame::OnAddDocument)
	ON_MESSAGE(MSG_NEWSCENE,&CMainFrame::OnNewScene)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_MESSAGE(MSG_UDP, OnUDP)
	ON_COMMAND(ID_COMBO_LANGUAGE, &CMainFrame::OnComboLanguage)
	ON_COMMAND(ID_COMBO_SCALE, &CMainFrame::OnComboScale)
	ON_COMMAND(ID_COMBO_VIEW,&CMainFrame::OnComboView)
	ON_COMMAND(ID_BTN_ABOUT, &CMainFrame::OnBtnAbout)
	ON_COMMAND(ID_BTN_OPENNET, &CMainFrame::OnBtnOpenNet)
	ON_COMMAND(ID_BTN_CLOSENET, &CMainFrame::OnBtnCloseNet)
	ON_COMMAND(ID_BTN_SAVESCENCE, &CMainFrame::OnBtnSaveScence)
	ON_COMMAND(ID_BTN_OPENSCENCE, &CMainFrame::OnBtnOpenScence)
	ON_COMMAND(ID_BTN_DELETESCENE, &CMainFrame::OnBtnDeleteScence)
	ON_COMMAND(ID_BTN_OLDORDER, &CMainFrame::OnBtnRunOldOrder)
	ON_COMMAND(ID_BTN_SETMOVEPARAMATER,&CMainFrame::OnBtnScreenMove)
	ON_COMMAND(ID_TIMEDPOLLING,&CMainFrame::OnBtnTimedPolling)
	ON_COMMAND(ID_BTN_SETSCREENRESULATION,&CMainFrame::OnBtnSetScreenResulation)
	ON_COMMAND(ID_BTN_PAN,&CMainFrame::OnBtnPan)
	ON_COMMAND(ID_BTN_CHIP,&CMainFrame::OnBtnChip)
	ON_COMMAND(ID_BTN_NEWVIEW,&CMainFrame::OnBtnNewView)
	ON_COMMAND(ID_BTN_PREVIEW,&CMainFrame::OnBtnPreview)
	ON_COMMAND(ID_BTN_DELETEALLSIGNAL, &CMainFrame::OnBtnDeleteAllSignal)
	ON_COMMAND(ID_BTN_TEMPERATURE, &CMainFrame::OnBtnTemperature)
	ON_COMMAND(ID_BTN_LOGIN, &CMainFrame::OnBtnLogin)
	ON_COMMAND(ID_BTN_LOGOUT, &CMainFrame::OnBtnLogout)
	ON_COMMAND(ID_BTN_USERMANAGE, &CMainFrame::OnBtnUserManage)
	ON_COMMAND(ID_EDIT_DEVICEIP, &CMainFrame::OnEditDeviceIP)
	ON_COMMAND(ID_EDIT_DEVICEPORT, &CMainFrame::OnEditDevicePort)
	ON_COMMAND(ID_SCREEN_CLOSESIGNAL, &CMainFrame::OnScreenCloseSignal)
	ON_COMMAND(ID_SCREEN_SEPARATE, &CMainFrame::OnScreenSeparate)
	ON_COMMAND(ID_SCREEN_NOSEPARATE, &CMainFrame::OnScreenNoSeparate)
	ON_COMMAND(ID_ATTRIBUTE_SCREEN, &CMainFrame::OnScreenAttribute)
	ON_UPDATE_COMMAND_UI(ID_BTN_OPENNET, &CMainFrame::OnUpdateBtnOpenNet)
	ON_UPDATE_COMMAND_UI(ID_BTN_CLOSENET, &CMainFrame::OnUpdateBtnCloseNet)
	ON_UPDATE_COMMAND_UI(ID_BTN_LOGIN, &CMainFrame::OnUpdateBtnLogin)
	ON_UPDATE_COMMAND_UI(ID_BTN_LOGOUT, &CMainFrame::OnUpdateBtnLogout)
	ON_UPDATE_COMMAND_UI(ID_BTN_USERMANAGE, &CMainFrame::OnUpdateBtnUserManage)
	ON_UPDATE_COMMAND_UI(ID_BTN_SAVESCENCE, &CMainFrame::OnUpdateBtnSaveScence)
	ON_UPDATE_COMMAND_UI(ID_BTN_OPENSCENCE, &CMainFrame::OnUpdateBtnOpenScence)
	ON_UPDATE_COMMAND_UI(ID_BTN_DELETESCENE, &CMainFrame::OnUpdateBtnDeleteScence)
	ON_UPDATE_COMMAND_UI(ID_BTN_OLDORDER, &CMainFrame::OnUpdateBtnRunOldOrder)
	ON_UPDATE_COMMAND_UI(ID_BTN_SETMOVEPARAMATER, &CMainFrame::OnUpdateBtnScreenMove)
	ON_UPDATE_COMMAND_UI(ID_TIMEDPOLLING,&CMainFrame::OnUpdateBtnTimedPolling)
	ON_UPDATE_COMMAND_UI(ID_BTN_SETSCREENRESULATION,&CMainFrame::OnUpdateBtnSetScreenResulation)
	ON_UPDATE_COMMAND_UI(ID_BTN_DELETEALLSIGNAL, &CMainFrame::OnUpdateBtnDeleteAllSignal)
	ON_UPDATE_COMMAND_UI(ID_BTN_PAN, &CMainFrame::OnUpdateBtnPan)
	ON_UPDATE_COMMAND_UI(ID_BTN_CHIP, &CMainFrame::OnUpdateBtnChip)
	ON_UPDATE_COMMAND_UI(ID_BTN_NEWVIEW,&CMainFrame::OnUpdataBtnNewView)
	ON_UPDATE_COMMAND_UI(ID_BTN_PREVIEW,&CMainFrame::OnUpdataBtnPreview)
	ON_COMMAND(ID_EDIT_INPUTCOUNT, &CMainFrame::OnEditInputCount)
	ON_COMMAND(ID_EDIT_OUTPUTCOUNTH, &CMainFrame::OnEditOutputCountH)
	ON_COMMAND(ID_EDIT_OUTPUTCOUNTV, &CMainFrame::OnEditOutputCountV)
	ON_UPDATE_COMMAND_UI(ID_EDIT_INPUTCOUNT, &CMainFrame::OnUpdateEditInputCount)
	ON_UPDATE_COMMAND_UI(ID_EDIT_OUTPUTCOUNTH, &CMainFrame::OnUpdateEditOutputCountH)
	ON_UPDATE_COMMAND_UI(ID_EDIT_OUTPUTCOUNTV, &CMainFrame::OnUpdateEditOutputCountV)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DEVICEIP, &CMainFrame::OnUpdateEditDeviceIP)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DEVICEPORT, &CMainFrame::OnUpdateEditDevicePort)
	ON_COMMAND(ID_BTN_SETSIGNALTOP, &CMainFrame::OnBtnSetSignalTop)
	ON_COMMAND(ID_BTN_SETSIGNALBOTTOM, &CMainFrame::OnBtnSetSignalBottom)
	ON_COMMAND(ID_BTN_SETSIGNALSHIFTUP, &CMainFrame::OnBtnSetSignalShiftUp)
	ON_COMMAND(ID_BTN_SETSIGNALSHIFTDOWN, &CMainFrame::OnBtnSetSignalShiftDown)
	ON_COMMAND(ID_CHANGEINPUT, &CMainFrame::OnBtnChangeInput)
	ON_COMMAND(ID_BTN_SETSIGNALEXPAND,&CMainFrame::OnBtnExpandSignal)
	ON_COMMAND(ID_SCREENCHANGE,&CMainFrame::OnBtnChangeScreen)
	ON_COMMAND(ID_SETSCREENMENU,&CMainFrame::OnBtnMenuScreenSet)
	ON_COMMAND(ID_SAVESCENEMENU,&CMainFrame::OnBtnMenuSaveScence)
	ON_COMMAND(ID_NETSET,&CMainFrame::OnSplitNetSet)
	ON_COMMAND(ID_BITRATE,&CMainFrame::OnSplitBitRate)
	ON_COMMAND(ID_BTN_NAMAL,&CMainFrame::OnBtnNormal)
	ON_COMMAND(ID_BTN_FULL,&CMainFrame::OnBtnFull)
	ON_COMMAND(ID_BTN_FOUR,&CMainFrame::OnBtnFour)
	ON_COMMAND(ID_BTN_INTER,&CMainFrame::OnBtnInter)
	ON_UPDATE_COMMAND_UI(ID_BTN_NAMAL,&CMainFrame::OnUpDateBtnNormal)
	ON_UPDATE_COMMAND_UI(ID_BTN_FULL,&CMainFrame::OnUpDateBtnFull)
	ON_UPDATE_COMMAND_UI(ID_BTN_FOUR,&CMainFrame::OnUpDateBtnFour)
	ON_UPDATE_COMMAND_UI(ID_BTN_INTER,&CMainFrame::OnUpDateBtnInter)
	ON_COMMAND(ID_BTN_TIPMODEL,&CMainFrame::OnBtnTipModel)
	ON_UPDATE_COMMAND_UI(ID_BTN_TIPMODEL,&CMainFrame::OnUpDateBtnTipModel)
	ON_COMMAND(ID_BTN_UPMODEL,&CMainFrame::OnBtnUpModel)
	ON_UPDATE_COMMAND_UI(ID_BTN_UPMODEL,&CMainFrame::OnUpDateBtnUpModel)
	ON_COMMAND(ID_BTN_DOWNMODEL,&CMainFrame::OnBtnDownModel)
	ON_UPDATE_COMMAND_UI(ID_BTN_DOWNMODEL,&CMainFrame::OnUpDateBtnDownModel)
	ON_COMMAND(ID_BTN_COPY,&CMainFrame::OnBtnCopyModal)
	ON_UPDATE_COMMAND_UI(ID_BTN_COPY,&CMainFrame::OnUpDateBtnCopy)
	ON_COMMAND(ID_BTN_ALLSCENE,&CMainFrame::OnBtnSaveAllScene)
	ON_UPDATE_COMMAND_UI(ID_BTN_ALLSCENE,&CMainFrame::OnUpDateBtnSaveAllScene)

	ON_COMMAND(ID_SIGNLESCENE,&CMainFrame::OnBtnSaveSingleScene)
	ON_UPDATE_COMMAND_UI(ID_SIGNLESCENE,&CMainFrame::OnUpDateSaveSingleScene)


	ON_COMMAND(ID_SCREEN_RESULATIONOFMATRIX,&CMainFrame::OnScreenResulationOfMatrix)
	ON_REGISTERED_MESSAGE(AFX_WM_CHANGE_ACTIVE_TAB, &CMainFrame::OnAfxWmOnchangeActiveTab)

	ON_COMMAND(ID_SETROWDPI,&CMainFrame::OnSetRowDpi)
	ON_COMMAND(ID_SETCOLDPI,&CMainFrame::OnSetColDpi)



END_MESSAGE_MAP()

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	m_pInternalManage=NULL;
	m_pTabCtrl=NULL;
	theApp.m_nAppLook=theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_OFF_2007_SILVER);	
}

CMainFrame::~CMainFrame()
{
	Clear();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//BOOL bNameValid;
	// ���ڳ־�ֵ�����Ӿ�����������ʽ
	OnApplicationLook(theApp.m_nAppLook);

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_SCROLLED; // ����������ʽ...
	mdiTabParams.m_bActiveTabCloseButton = TRUE;      // ����Ϊ FALSE �Ὣ�رհ�ť������ѡ�������Ҳ�
	mdiTabParams.m_bTabIcons = TRUE;    // ����Ϊ TRUE ���� MDI ѡ��������ĵ�ͼ��
	mdiTabParams.m_bAutoColor = TRUE;    // ����Ϊ FALSE ������ MDI ѡ����Զ���ɫ
	mdiTabParams.m_bDocumentMenu = TRUE; // ��ѡ�������ұ�Ե�����ĵ��˵�
	mdiTabParams.m_bTabCloseButton=TRUE;
	mdiTabParams.m_bTabCustomTooltips=TRUE;
	mdiTabParams.m_bEnableTabSwap=FALSE;
	mdiTabParams.m_bFlatFrame=FALSE;

	EnableMDITabbedGroups(TRUE, mdiTabParams);

	
	// Prevent the menu bar from taking the focus on activation
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	//CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);

	//CMFCVisualManagerWindows7::SetStyle(CMFCVisualManagerWindows7)
	//�������ڻ��������û�����Ԫ�ص��Ӿ�������
	//CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));

	srand((unsigned)time(NULL));

	InitManage();

	// ���� Visual Studio 2005 ��ʽͣ��������Ϊ
	CDockingManager::SetDockingMode(DT_SMART);
	// ���� Visual Studio 2005 ��ʽͣ�������Զ�������Ϊ
	EnableAutoHidePanes(CBRS_ALIGN_RIGHT);

	//��ʼ����������������Ϊ��ҪRibbonBar��ͣ��Ȼ��ִ�����������ͣ����壬��Ȼ��Ϊ���Ӵ������Ĭ�����أ�����λ�û���ʾ�����ϽǶ���������ͼ������
	InitPane();

	BeginTimer();



	return 0;
}

BOOL CMainFrame::OnShowPopupMenu (CMFCPopupMenu* pMenuPopup)
{
	//��������û��׼���ò˵�������TRUEΪ׼������
	CMDIFrameWndEx::OnShowPopupMenu (pMenuPopup);

	if(pMenuPopup==NULL)
		return FALSE;

	CMFCPopupMenuBar* pMenuBar=pMenuPopup->GetMenuBar();
	ASSERT_VALID(pMenuBar);
	const CObList& List=pMenuBar->GetAllButtons();

	if(List.GetSize()==0)
		return TRUE;

	//��ʼ���˵����Ȳ���Button�У�Ȼ����ʾ����
	//��ʼ�����жϼ����еĲ˵��ǲ�����Ҫ�ģ�ѡ������ʾ
	POSITION pos=List.GetHeadPosition();
	CMFCToolBarButton* pButton=(CMFCToolBarButton*)List.GetNext(pos);

	if(pButton->m_strText==_T("����(&F)"))
		return FALSE;
	else
		return TRUE;
}

BOOL CMainFrame::OnShowMDITabContextMenu (CPoint point, DWORD dwAllowedItems, BOOL bDrop)
{
	if (bDrop || !theApp.m_Options.m_bMDITabsContextMenu)
		return FALSE;

	ShowMenu(point);

	return TRUE;
}

void CMainFrame::ShowMenu(CPoint& point)
{
	m_pInternalManage->ShowMenu(point);
}

LRESULT CMainFrame::OnToolbarContextMenu(WPARAM,LPARAM lp)
{
	return 0;
}

LRESULT CMainFrame::OnAddDocument(WPARAM wParam,LPARAM lParam)
{
	m_pInternalManage->AddDocument();
	return 0;
}

LRESULT CMainFrame::OnNewScene(WPARAM wParam,LPARAM lParam)
{
	if(!m_pInternalManage->GetIsFirstTime())
		m_pInternalManage->Operate(OPERATETYPE_NEWSCENE,NULL);
	
	return 0;	
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;

	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	m_strTitle=_T("ƴ�Ӿ������ƽ̨");
	//m_strPathName=_T("");

	return TRUE;
}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	//�ػ�˫���ź�
	if(pMsg->message==WM_LBUTTONDBLCLK)
	{	
		//ģ̬�Ի���Ӱ����Ϣ�Ĵ���˳��
		//�����ģ̬�Ի���ֱ�ӷ���TRUE��������TRUE ������⣬���ٰ�˳���ִ��
		//ֱ�ӷ���TRUE ��Ӱ����������
		if(m_pInternalManage->SetTabCtrlDbCLick(pMsg->pt))
			return TRUE;
		else if(m_pInternalManage->SetViewTabBarDbClick(pMsg->pt))
			return TRUE;
		else
			return __super::PreTranslateMessage(pMsg);
	}
	//else if(pMsg->message==WM_LBUTTONDOWN)
	//{
	//	m_pInternalManage->SetTabCtrlCLick(pMsg->pt);

	//	TRACE(_T("WM_LBUTTONDOWN\n"));
	//}
	
	return __super::PreTranslateMessage(pMsg);
}
 
void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}
// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������

void CMainFrame::InitManage()
{
	m_pInternalManage = new XInternalManage;
	m_pInternalManage->SetDelegate(this);
	m_pInternalManage->Init();
}

XBaseInternalManage* CMainFrame::GetInterManage()
{
	return m_pInternalManage;
}

CWnd* CMainFrame::GetCWND()
{
	return this;
}

void CMainFrame::Clear()
{
	if (nullptr != m_pInternalManage)
	{
		delete m_pInternalManage;

		m_pInternalManage = nullptr;
	}
}

void CMainFrame::InvalidateView()
{
	//Invalidate(FALSE);

	//UpdateData(TRUE);
}

void CMainFrame::ResetViewSize()
{
	
}

CView* CMainFrame::GetView()
{
	CView* pView = GetActiveView();

	return pView;
}

void CMainFrame::OnClose()
{
	if ((nullptr == m_pInternalManage) || m_pInternalManage->AppClose())
	{
		__super::OnClose();
	}
}

HWND CMainFrame::GetHWND()
{
	return this->GetSafeHwnd();
}

int CMainFrame::MessageBox(CString szText, CString szCaption, UINT uType)
{
	return ::MessageBox(this->GetSafeHwnd(), szText, szCaption, uType);
}

void CMainFrame::ViewDraw(CDC* pDC, CRect rect, int noffsetX, 
	int noffsetY)
{
	m_pInternalManage->ViewDraw(pDC, rect, noffsetX, noffsetY);
}

CSize CMainFrame::ViewGetSize()
{
	return m_pInternalManage->ViewGetSize();
}

void CMainFrame::ViewLButtonDown(UINT& nFlags, CPoint& point, CRect& rect, 
	int noffsetX, int noffsetY)
{
	m_pInternalManage->ViewLButtonDown(nFlags, point, rect, noffsetX, noffsetY);
}

void CMainFrame::ViewLButtonUp(UINT& nFlags, CPoint& point, CRect& rect, 
	int noffsetX, int noffsetY)
{
	m_pInternalManage->ViewLButtonUp(nFlags, point, rect, noffsetX, noffsetY);
}

void CMainFrame::ViewMouseMove(UINT& nFlags, CPoint& point, CRect& rect, 
	int noffsetX, int noffsetY)
{
	m_pInternalManage->ViewMouseMove(nFlags, point, rect, noffsetX, noffsetY);
}

void CMainFrame::ViewMouseLeave()
{
	m_pInternalManage->ViewMouseLeave();
}

void CMainFrame::ViewKeyUp(UINT nChar)
{
	m_pInternalManage->ViewKeyUp(nChar);
}

void CMainFrame::ViewRButtonUp(CWnd* pWnd, UINT& nFlags, CPoint& point, 
	CRect& rect, int noffsetX, int noffsetY)
{
	m_pInternalManage->ViewRButtonUp(pWnd, nFlags, point, rect, noffsetX, noffsetY);
}

void CMainFrame::ViewLBDClick(UINT& nFlags, CPoint& point, CRect& rect, 
	int noffsetX, int noffsetY)
{
	m_pInternalManage->ViewLBDClick(nFlags, point, rect, noffsetX, noffsetY);
}

void CMainFrame::OnComboLanguage()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_LANGUAGENAME);
}

void CMainFrame::OnComboScale()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_SCALE);
}

void CMainFrame::OnComboView()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_VIEW);
}

void CMainFrame::OnBtnOpenNet()
{
	m_pInternalManage->Operate(OPERATETYPE_OPENNET, NULL);
}

void CMainFrame::OnBtnCloseNet()
{
	m_pInternalManage->Operate(OPERATETYPE_CLOSENET, NULL);
}

void CMainFrame::OnUpdateBtnOpenNet(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_OPENNET, pCmdUI);
}

void CMainFrame::OnUpdateBtnCloseNet(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_CLOSENET, pCmdUI);
}

void CMainFrame::OnEditDeviceIP()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_DEVICEIP);
}

void CMainFrame::OnEditDevicePort()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_DEVICEPORT);
}

void CMainFrame::OnScreenCloseSignal()
{
	m_pInternalManage->Operate(OPERATETYPE_SCREENCLOSESIGNAL, NULL);
}

void CMainFrame::OnBtnSaveScence()
{
	m_pInternalManage->Operate(OPERATETYPE_SAVESCENCE, NULL);
}

void CMainFrame::OnBtnOpenScence()
{
	m_pInternalManage->Operate(OPERATETYPE_OPENSCENCE, NULL);
}

void CMainFrame::OnBtnDeleteScence()
{
	m_pInternalManage->Operate(OPERATETYPE_DELETESCENCE, NULL);
}

void CMainFrame::OnBtnScreenMove()
{
	m_pInternalManage->Operate(OPERATETYPE_SCREENMOVE, NULL);
}

void CMainFrame::OnBtnTimedPolling()
{
	m_pInternalManage->Operate(OPERATETYPE_TIMEDPOLLING, NULL);
}

void CMainFrame::OnBtnDeleteAllSignal()
{
	m_pInternalManage->Operate(OPERATETYPE_DELETEALLSIGNAL, NULL);
}

void CMainFrame::OnBtnSetScreenResulation()
{
	m_pInternalManage->Operate(OPERATETYPE_SETSCREENRESULATION, NULL);
}

void CMainFrame::OnBtnPan()
{
	
}
void CMainFrame::OnBtnChip()
{

}

void CMainFrame::OnBtnNewView()
{
	m_pInternalManage->Operate(OPERATETYPE_NEWVIEW, NULL);
}

void CMainFrame::OnBtnPreview()
{
	m_pInternalManage->Operate(OPERATETYPE_PREVIEW,NULL);
}

void CMainFrame::OnBtnRunOldOrder()
{
	m_pInternalManage->Operate(OPERATETYPE_RUNOLDORDER, NULL);
}

void CMainFrame::OnScreenSeparate()
{
	m_pInternalManage->Operate(OPERATETYPE_SCREENSEPARATE, NULL);
}

void CMainFrame::OnScreenNoSeparate()
{
	m_pInternalManage->Operate(OPERATETYPE_SCREENRESULATION, NULL);
}

void CMainFrame::OnBtnChangeScreen()
{
	m_pInternalManage->Operate(OPERATETYPE_CHANGESCREEN, NULL);
}

void CMainFrame::OnBtnMenuScreenSet()
{
	m_pInternalManage->Operate(OPERATETYPE_MENUSCREENSET, NULL);
}

void CMainFrame::OnBtnMenuSaveScence()
{
	m_pInternalManage->Operate(OPERATETYPE_MENUSAVESCENE, NULL);
}

void CMainFrame::OnScreenAttribute()
{
	m_pInternalManage->Operate(OPERATETYPE_SCREENATTRIBUTE, NULL);
}

void CMainFrame::OnBtnSetSignalTop()
{
	m_pInternalManage->Operate(OPERATETYPE_SETSIGNALTOP, NULL);
}

void CMainFrame::OnBtnSetSignalBottom()
{
	m_pInternalManage->Operate(OPERATETYPE_SETSIGNALBOTTOM, NULL);
}

void CMainFrame::OnBtnSetSignalShiftUp()
{
	m_pInternalManage->Operate(OPERATETYPE_SETSIGNALSHIFTUP, NULL);
}

void CMainFrame::OnBtnSetSignalShiftDown()
{
	m_pInternalManage->Operate(OPERATETYPE_SETSIGNALSHIFTDOWN, NULL);
}

void CMainFrame::OnBtnChangeInput()
{
	m_pInternalManage->Operate(OPERATETYPE_CHANGEINPUT, NULL);
}

void CMainFrame::OnBtnExpandSignal()
{
	m_pInternalManage->Operate(OPERATETYPE_SETSIGNALEXPAND, NULL);
}

LRESULT CMainFrame::OnUDP(WPARAM wParam, LPARAM lParam)
{
	m_pInternalManage->HandleUDPMsg(wParam, lParam);

	return 0;
}

void CMainFrame::OnBtnTemperature()
{

}

void CMainFrame::InitPane()
{
	m_pInternalManage->InitPane();
}

void CMainFrame::OnBtnAbout()
{
	m_pInternalManage->Operate(OPERATETYPE_ABOUT, NULL);
}

void CMainFrame::OnEditInputCount()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_INPUTCOUNT);
}

void CMainFrame::OnEditOutputCountH()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_OUTPUTCOUNTH);
}

void CMainFrame::OnEditOutputCountV()
{
	m_pInternalManage->ControlDataChange(XDATATYPE_OUTPUTCOUNTV);
}

void CMainFrame::OnBtnLogin()
{
	m_pInternalManage->Operate(OPERATETYPE_LOGIN, NULL);
}

void CMainFrame::OnBtnLogout()
{
	m_pInternalManage->Operate(OPERATETYPE_LOGOUT, NULL);
}

void CMainFrame::OnBtnUserManage()
{
	m_pInternalManage->Operate(OPERATETYPE_USERMANAGE, NULL);
}

//void CMainFrame::OnBtnPowerManage()
//{
//	m_pInternalManage->Operate(OPERATETYPE_POWERMANAGE, NULL);
//}

void CMainFrame::OnUpdateBtnLogin(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_LOGIN, pCmdUI);
}

void CMainFrame::OnUpdateBtnLogout(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_LOGOUT, pCmdUI);
}

void CMainFrame::OnUpdateBtnUserManage(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_USERMANAGE, pCmdUI);
}
//
//void CMainFrame::OnUpdateBtnPowerManage(CCmdUI *pCmdUI)
//{
//	m_pInternalManage->UpdateControlUI(CMDUITYPE_POWERMANAGE, pCmdUI);
//}

void CMainFrame::OnUpdateEditInputCount(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_INPUTCOUNT, pCmdUI);
}

void CMainFrame::OnUpdateEditOutputCountH(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_OUTPUTCOUNTH, pCmdUI);
}

void CMainFrame::OnUpdateEditOutputCountV(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_OUTPUTCOUNTV, pCmdUI);
}

void CMainFrame::OnUpdateEditDeviceIP(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_DEVICEIP, pCmdUI);
}

void CMainFrame::OnUpdateEditDevicePort(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_DEVICEPORT, pCmdUI);
}

void CMainFrame::OnUpdateBtnRunOldOrder(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_RUNOLDORDER, pCmdUI);
}

void CMainFrame::OnUpdateBtnSaveScence(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_SAVESCENCE, pCmdUI);
}

void CMainFrame::OnUpdateBtnPan(CCmdUI *pCmdUI)
{

}

void CMainFrame::OnUpdateBtnChip(CCmdUI *pCmdUI)
{

}

void CMainFrame::OnUpdataBtnNewView(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_NEWVIEW, pCmdUI);
}


void CMainFrame::OnUpdataBtnPreview(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_PREVIEW, pCmdUI);
}

void CMainFrame::OnUpdateBtnOpenScence(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_OPENSCENCE, pCmdUI);
}

void CMainFrame::OnUpdateBtnDeleteScence(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_DELETESCENCE, pCmdUI);
}

void CMainFrame::OnUpdateBtnScreenMove(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_SCREENMOVE, pCmdUI);
}

void CMainFrame::OnUpdateBtnTimedPolling(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_TIMEDPOLLING, pCmdUI);
}
void CMainFrame::OnUpdateBtnSetScreenResulation(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_SETSCREENRESULATION, pCmdUI);
}

void CMainFrame::OnUpdateBtnDeleteAllSignal(CCmdUI *pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_DELETEALLSIGNAL, pCmdUI);
}

void CMainFrame::OnSplitNetSet()
{
	m_pInternalManage->Operate(	OPERATETYPE_SPLITNETSET,NULL);	
}

void CMainFrame::OnSplitBitRate()
{
	m_pInternalManage->Operate(	OPERATETYPE_SPLITBITRATE,NULL);
}

void CMainFrame::OnBtnNormal()
{
	m_pInternalManage->Operate(OPERATETYPE_NORMAL,NULL);
}

void CMainFrame::OnBtnFull()
{
	m_pInternalManage->Operate(OPERATETYPE_FULL,NULL);
}

void CMainFrame::OnBtnFour()
{
	m_pInternalManage->Operate(OPERATETYPE_FOUR,NULL);
}

void CMainFrame::OnBtnInter()
{
	m_pInternalManage->Operate(OPERATETYPE_INTER,NULL);
}

void CMainFrame::OnUpDateBtnInter(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_INTER,pCmdUI);
}

void CMainFrame::OnUpDateBtnNormal(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_NORMAL, pCmdUI);
}

void CMainFrame::OnUpDateBtnFull(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_FULL, pCmdUI);
}

void CMainFrame::OnUpDateBtnFour(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_FOUR, pCmdUI);
}

void CMainFrame::OnBtnCopyModal()
{
	m_pInternalManage->Operate(OPERATETYPE_COPYMODEL, NULL);
}

void CMainFrame::OnUpDateBtnCopy(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_COPYMODEL, pCmdUI);
}


void CMainFrame::OnScreenResulationOfMatrix()
{
	m_pInternalManage->Operate(OPERATETYPE_SCREENRESULATIONOFMATRIX, NULL);
}


void CMainFrame::OnBtnTipModel()
{
	m_pInternalManage->Operate(OPERATETYPE_TIPMODEL, NULL);
}

void CMainFrame::OnBtnUpModel()
{
	m_pInternalManage->Operate(OPERATETYPE_UPMODEL, NULL);
}

void CMainFrame::OnBtnDownModel()
{
	m_pInternalManage->Operate(OPERATETYPE_DOWNMODEL, NULL);
}

void CMainFrame::OnUpDateBtnTipModel(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_TIPMODEL, pCmdUI);
}

void CMainFrame::OnUpDateBtnUpModel(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_UPMODEL, pCmdUI);
}

void CMainFrame::OnUpDateBtnDownModel(CCmdUI* pCmdUI)
{
	m_pInternalManage->UpdateControlUI(CMDUITYPE_DOWNMODEL, pCmdUI);
}


void CMainFrame::OnBtnSaveAllScene()
{
	m_pInternalManage->Operate(OPERATETYPE_SAVEALLSECNE, NULL);
}

void CMainFrame::OnUpDateBtnSaveAllScene(CCmdUI* pCmdUI)
{
	//m_pInternalManage->UpdateControlUI(CMDUITYPE_SAVEALLSCENE, pCmdUI);
}

void CMainFrame::OnBtnSaveSingleScene()
{
	m_pInternalManage->Operate(OPERATETYPE_SINGLESCENE, NULL);
}

void CMainFrame::OnUpDateSaveSingleScene(CCmdUI* pCmdUI)
{
	//m_pInternalManage->UpdateControlUI(CMDUITYPE_SAVEALLSCENE, pCmdUI);
}


void CMainFrame::OnSetRowDpi()
{
	m_pInternalManage->Operate(OPERATETYPE_SETROWDPI, NULL);
}

void CMainFrame::OnSetColDpi()
{
	m_pInternalManage->Operate(OPERATETYPE_SETCOLDPI, NULL);
}


//////////////////////////////////////////////////////////////////////////
BOOL CMainFrame::OnCloseDockingPane(CDockablePane* pPane)
{
	//��û��׼���ã��ر����
	if(m_pInternalManage==NULL)
	{
		return FALSE;
	}

	m_pInternalManage->CloseActivePane();

	return TRUE;
}

//֮ǰ�����ײ�TabCtrl��������PreTranslateMessage�н�ȡ
LRESULT CMainFrame::OnAfxWmOnchangeActiveTab(WPARAM wParam, LPARAM lParam)
{
	int iTabInDEX=(int)wParam;

	if(iTabInDEX==-1)
	{
		return -1;
	}

	m_pInternalManage->SetActiveDockPane();

	return 0;
}

//////////////////////////////////////////////////////////////////////////
void CMainFrame::BeginTimer()
{
	////�豸״̬
	m_pInternalManage->Operate(OPERATETYPE_DEVICESTATUS, NULL);
	SetTimer(TIMERID_DEVICESTATUS, TIMERELAPSE_DEVICESTATUS, NULL);

	//����״̬
	m_pInternalManage->Operate(OPERATETYPE_GETSIGNALPARAMATER,NULL);
	SetTimer(TIMERID_GETSIGNALPAREMATER,TIMERELAPSE_GETSIGNALPAREMATER,NULL);

	//���״̬
	m_pInternalManage->Operate(OPERATETYPE_GETSCREENPARAMATER,NULL);
	SetTimer(TIMERID_GETOUTPUTPARAMATER,TIMERELAPSE_GETOUTPUTPARAMATER,NULL);

	//��ȡ��������
	m_pInternalManage->Operate(OPERATETYPE_GETWINDOWPARAMATER,NULL);
	SetTimer(TIMERID_GETWINDOWPARAMATER,TIMERELAPSE_GETWINDOWPARAMATER,NULL);

	//ˢ�³������
	m_pInternalManage->Operate(OPERATETYPE_GETSCENEINDEX,NULL);
	SetTimer(TIMERID_GETSCENEINDEX,TIMERELAPSE_GETSCENEINDEX,NULL);

	//ˢ������״̬ͼ��
	m_pInternalManage->Operate(OPERATETYPE_SETSIGNALICON,NULL);
	SetTimer(TIMERID_SETINPUTICON,TIMERELAPSE_SETINPUTICON,NULL);

	//��ȡ�ź����
	m_pInternalManage->Operate(OPERATETYPE_GETINPUTNUM,NULL);
	SetTimer(TIMERID_GETINPUTNUM,TIMERSPACE_GETINPUTNUM,NULL);

	//��ȡ���󴰿�����
	m_pInternalManage->Operate(OPERATETYPE_MATRIXOUTPUT,NULL);
	SetTimer(TIMERID_MATRIXOUTPUT,TIMERSPACE_MATRIXOUTPUT,NULL);
}

void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	switch(nIDEvent)
	{
	case TIMERID_DEVICESTATUS:
		{
			m_pInternalManage->Operate(OPERATETYPE_DEVICESTATUS, NULL);
		}
		break;
	case TIMERID_GETSIGNALPAREMATER:
		{
			m_pInternalManage->Operate(OPERATETYPE_GETSIGNALPARAMATER,NULL);
		}
		break;
	case TIMERID_GETOUTPUTPARAMATER:
		{
			m_pInternalManage->Operate(OPERATETYPE_GETSCREENPARAMATER,NULL);
		}
		break;
	case TIMERID_GETWINDOWPARAMATER:
		{
			m_pInternalManage->Operate(OPERATETYPE_GETWINDOWPARAMATER,NULL);
		}
		break;
	case TIMERID_GETSCENEINDEX:
		{
			m_pInternalManage->Operate(OPERATETYPE_GETSCENEINDEX,NULL);
		}
		break;
	case TIMERID_SETINPUTICON:
		{
			m_pInternalManage->Operate(OPERATETYPE_SETSIGNALICON,NULL);
		}
		break;
	case TIMERID_GETINPUTNUM:
		{
			m_pInternalManage->Operate(OPERATETYPE_GETINPUTNUM,NULL);
		}
		break;
	case TIMERID_MATRIXOUTPUT:
		{
			m_pInternalManage->Operate(OPERATETYPE_MATRIXOUTPUT,NULL);
		}
		break;
	default:
		break;
	}

	__super::OnTimer(nIDEvent);
}




