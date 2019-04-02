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

// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

#include "XRibbonBar.h"
#include "XDelegateView.h"
#include "XDelegateInternalManage.h"

class XBaseInternalManage;

class CMainFrame : public CMDIFrameWndEx, XDelegateView, XDelegateInternalManage
{
	
public: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	virtual BOOL OnShowPopupMenu (CMFCPopupMenu* pMenuPopup);

	virtual BOOL OnShowMDITabContextMenu (CPoint point, DWORD dwAllowedItems, BOOL bDrop);

	virtual BOOL OnCloseDockingPane(CDockablePane* );

	virtual BOOL PreTranslateMessage(MSG* pMsg);


// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg LRESULT OnToolbarContextMenu(WPARAM,LPARAM);
	afx_msg LRESULT OnAddDocument(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnNewScene(WPARAM wParam,LPARAM lParam);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnUDP(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClose();
	afx_msg void OnComboLanguage();
	afx_msg void OnComboScale();
	afx_msg void OnComboView();
	afx_msg void OnBtnAbout();
	afx_msg void OnBtnOpenNet();
	afx_msg void OnBtnCloseNet();
	afx_msg void OnBtnSaveScence();
	afx_msg void OnBtnOpenScence();
	afx_msg void OnBtnDeleteScence();
	afx_msg void OnBtnScreenMove();
	afx_msg void OnBtnTimedPolling();
	afx_msg void OnBtnDeleteAllSignal();
	afx_msg void OnBtnSetScreenResulation();
	afx_msg void OnBtnPan();
	afx_msg void OnBtnChip();
	afx_msg void OnBtnNewView();
	afx_msg void OnBtnPreview();
	afx_msg void OnBtnRunOldOrder();
	afx_msg void OnBtnTemperature();
	afx_msg void OnBtnLogin();
	afx_msg void OnBtnLogout();
	afx_msg void OnBtnUserManage();
	//afx_msg void OnBtnPowerManage();
	afx_msg void OnEditDeviceIP();
	afx_msg void OnEditDevicePort();
	afx_msg void OnEditInputCount();
	afx_msg void OnEditOutputCountH();
	afx_msg void OnEditOutputCountV();
	afx_msg void OnUpdateBtnOpenNet(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnCloseNet(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnLogin(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnLogout(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnUserManage(CCmdUI *pCmdUI);
	//afx_msg void OnUpdateBtnPowerManage(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnSaveScence(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnOpenScence(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnDeleteScence(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnScreenMove(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnTimedPolling(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnSetScreenResulation(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnDeleteAllSignal(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditInputCount(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditOutputCountH(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditOutputCountV(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditDeviceIP(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditDevicePort(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnRunOldOrder(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnPan(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnChip(CCmdUI *pCmdUI);
	afx_msg void OnUpdataBtnNewView(CCmdUI* pCmdUI);
	afx_msg void OnUpdataBtnPreview(CCmdUI* pCmdUI);
	afx_msg void OnScreenCloseSignal();
	afx_msg void OnScreenSeparate();
	afx_msg void OnScreenNoSeparate();
	afx_msg void OnBtnChangeScreen();
	afx_msg void OnScreenAttribute();
	afx_msg void OnBtnSetSignalTop();
	afx_msg void OnBtnSetSignalBottom();
	afx_msg void OnBtnSetSignalShiftUp();
	afx_msg void OnBtnSetSignalShiftDown();
	afx_msg void OnBtnChangeInput();
	afx_msg void OnBtnExpandSignal();
	afx_msg void OnBtnMenuScreenSet();
	afx_msg void OnBtnMenuSaveScence();

	afx_msg void OnSplitNetSet();
	afx_msg void OnSplitBitRate();

	afx_msg void OnBtnNormal();
	afx_msg void OnBtnFull();
	afx_msg void OnBtnFour();
	afx_msg void OnBtnInter();
	afx_msg void OnUpDateBtnNormal(CCmdUI* pCmdUI);
	afx_msg void OnUpDateBtnFull(CCmdUI* pCmdUI);
	afx_msg void OnUpDateBtnFour(CCmdUI* pCmdUI);
	afx_msg void OnUpDateBtnInter(CCmdUI* pCmdUI);

	afx_msg void OnBtnTipModel();
	afx_msg void OnUpDateBtnTipModel(CCmdUI* pCmdUI);
	afx_msg void OnBtnUpModel();
	afx_msg void OnUpDateBtnUpModel(CCmdUI* pCmdUI);
	afx_msg void OnBtnDownModel();
	afx_msg void OnUpDateBtnDownModel(CCmdUI* pCmdUI);
	afx_msg void OnBtnCopyModal();
	afx_msg void OnUpDateBtnCopy(CCmdUI* pCmdUI);

	afx_msg void OnBtnSaveAllScene();
	afx_msg void OnUpDateBtnSaveAllScene(CCmdUI* pCmdUI);

	afx_msg void OnBtnSaveSingleScene();
	afx_msg void OnUpDateSaveSingleScene(CCmdUI* pCmdUI);

	

	afx_msg void OnScreenResulationOfMatrix();
	afx_msg LRESULT OnAfxWmOnchangeActiveTab(WPARAM wParam, LPARAM lParam);

	afx_msg void OnSetRowDpi();
	afx_msg void OnSetColDpi();


	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

public:

	//��ʼ������
	void InitManage();

	//��ʼ��Pane
	void InitPane();

	//���
	void Clear();

	XBaseInternalManage* GetInterManage();

	void ShowMenu(CPoint& point);

public:

	//��ͼ����
	virtual void ViewDraw(CDC* pDC, CRect rect, int noffsetX, 
		int noffsetY);

	//��ͼ��ȡ��С
	virtual CSize ViewGetSize();

	//��ͼ�������
	virtual void ViewLButtonDown(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ�������
	virtual void ViewLButtonUp(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ����ƶ�
	virtual void ViewMouseMove(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ����뿪
	virtual void ViewMouseLeave();

	//��ͼ��������
	virtual void ViewKeyUp(UINT nChar);

	//��ͼ�Ҽ�����
	virtual void ViewRButtonUp(CWnd* pWnd, UINT& nFlags, CPoint& point, 
		CRect& rect, int noffsetX, int noffsetY);

	virtual void ViewLBDClick(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

public:

	//��ȡCWnd
	virtual CWnd* GetCWND();

	//��ʾ��Ϣ�Ի���
	virtual int MessageBox(CString szText, CString szCaption, UINT uType);

	//������ͼ��С
	virtual void ResetViewSize();

	//ˢ����ͼ
	virtual void InvalidateView();

	//��ȡ���ھ��
	virtual HWND GetHWND();

	//��ȡ��ͼ
	virtual CView* GetView();

private:

	//��ʼ��ʱ��
	void BeginTimer();

private:

	//���Ĺ���
	XBaseInternalManage* m_pInternalManage;

	BOOL m_bIsReady;

	CMFCTabCtrl* m_pTabCtrl;
};


