
// ChildFrm.cpp : CChildFrame ���ʵ��
//

#include "stdafx.h"
#include "Multiviewer.h"
#include "XInternalManage.h"
#include "XBaseScreenManage.h"
#include "XUserManage.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)

	ON_WM_MDIACTIVATE()
	ON_WM_CLOSE()

END_MESSAGE_MAP()

// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	m_pScreenManage = NULL;
}

CChildFrame::~CChildFrame()
{

}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame ��Ϣ�������


void CChildFrame::setParentDelegate(XInternalManage* p)
{
	m_pManage=p;
}

void CChildFrame::setScreenManage(XBaseScreenManage* p)
{
	m_pScreenManage=p;
}

XBaseScreenManage* CChildFrame::GetScreenManage()
{
	return m_pScreenManage;
}

void CChildFrame::OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd) 
{
	CMDIChildWnd::OnMDIActivate(bActivate, pActivateWnd, pDeactivateWnd);

	if(m_pScreenManage==NULL)
	{
		return;
	}

	if(bActivate)
	{
		CChildFrame* pFrame=(CChildFrame*)pActivateWnd;

		XBaseScreenManage* pManage=pFrame->GetScreenManage();

		m_pScreenManage=pFrame->GetScreenManage();

		m_pManage->SetNowScreenManage(m_pScreenManage);

		m_pScreenManage->GetDelegate()->UpdateControlDataShow(XDATATYPE_OUTPUTCOUNTH);

		m_pScreenManage->GetDelegate()->UpdateControlDataShow(XDATATYPE_OUTPUTCOUNTV);
	}
	else
	{
		if(pActivateWnd==NULL)
		{
			m_pManage->SetNowScreenManage(NULL);
		}
	}
}

void CChildFrame::OnClose()
{
	if(!m_pManage->GetUserManage()->IsLogin())
	{
		m_pManage->MessageBoxFromKey(_T("377"), _T("��û��Ȩ�޽��д˲���!"), MB_OK);

		return;
	}

	if(!m_pManage->IsAdminUser())
	{
		m_pManage->MessageBoxFromKey(_T("377"), _T("��û��Ȩ�޽��д˲���!"), MB_OK);

		return;
	}

	VEC_BASESCREENMANAGE& VecBaseScreenManage=m_pManage->GetBaseManage();

	int nCount=VecBaseScreenManage.size();

	if(nCount==1)
	{
		return;
	}

	if(IDCANCEL==m_pManage->MessageBoxFromKey(_T("773"),_T("�ر���ͼ��"),MB_OKCANCEL))
	{
		return;
	}

	if(IDYES==m_pManage->MessageBoxFromKey(_T("727"),_T("�رյ�ǰ��ͼ���Ƿ�Ҫ���泡����"),MB_YESNO))
	{
		//���泡��
		m_pManage->SaveSceneByCloseView();
	}

	m_pManage->CloseMDI(m_pScreenManage);

	MDIDestroy();
}




