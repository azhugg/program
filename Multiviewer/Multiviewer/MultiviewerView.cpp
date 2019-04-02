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

// MultiviewerView.cpp : CMultiviewerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Multiviewer.h"
#endif

#include "MultiviewerDoc.h"
#include "MultiviewerView.h"
#include "MainFrm.h"
#include "XDelegateView.h"
#include "XBaseScreenManage.h"
#include "XInternalManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiviewerView

IMPLEMENT_DYNCREATE(CMultiviewerView, CScrollView)

BEGIN_MESSAGE_MAP(CMultiviewerView, CScrollView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYUP()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_SETCURSOR()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMultiviewerView ����/����

CMultiviewerView::CMultiviewerView()
{
	//m_pDelegate = nullptr;

	m_bMouseLeave=TRUE;

	m_pScreenManage=NULL;

}

CMultiviewerView::~CMultiviewerView()
{
}

BOOL CMultiviewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	//cs.style &=~ WS_BORDER;

	return CScrollView::PreCreateWindow(cs);
}

void CMultiviewerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMultiviewerView ���

#ifdef _DEBUG
void CMultiviewerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMultiviewerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMultiviewerDoc* CMultiviewerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiviewerDoc)));
	return (CMultiviewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiviewerView ��Ϣ�������

void CMultiviewerView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	Init();
}

void CMultiviewerView::Init()
{
	SetDelegate();

	ResetSize();
}

void CMultiviewerView::SetDelegate()
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();

	m_pDelegate = (XDelegateView*)pMainFrame;
}

void CMultiviewerView::SetScreenManage(XBaseScreenManage* p)
{
	m_pScreenManage=p;
}

XBaseScreenManage* CMultiviewerView::GetScreenManage()
{
	return m_pScreenManage;
}

BOOL CMultiviewerView::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

BOOL CMultiviewerView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	return TRUE;
}

void CMultiviewerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (nullptr != m_pScreenManage)
	{
		SetCapture();

		CRect rect;
		GetClientRect(rect);

		m_pScreenManage->ViewLButtonDown(nFlags, point, rect, GetScrollPos(SB_HORZ), GetScrollPos(SB_VERT));
	}
}

void CMultiviewerView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if (nullptr != m_pScreenManage)
	{
		//SetCapture();

		CRect rect;
		GetClientRect(rect);

		m_pScreenManage->ViewLBDClick(nFlags, point, rect, GetScrollPos(SB_HORZ), GetScrollPos(SB_VERT));
	}
}

void CMultiviewerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (nullptr != m_pScreenManage)
	{
		if(GetCapture() == this)
		{
			ReleaseCapture();

			CRect rect;
			GetClientRect(rect);

			m_pScreenManage->ViewLButtonUp(nFlags, point, rect, GetScrollPos(SB_HORZ), GetScrollPos(SB_VERT));
		}
	}
}

void CMultiviewerView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nullptr != m_pScreenManage)
	{
		if (m_bMouseLeave)
		{
			TRACKMOUSEEVENT evt = {0};
			evt.cbSize = sizeof(evt);
			evt.dwFlags = TME_LEAVE;
			evt.hwndTrack = m_hWnd;

			TrackMouseEvent(&evt);

			m_bMouseLeave = FALSE;
		}

		CRect rect;
		GetClientRect(rect);

		m_pScreenManage->ViewMouseMove(nFlags, point, rect, GetScrollPos(SB_HORZ), GetScrollPos(SB_VERT));
	}
}

BOOL CMultiviewerView::OnMouseWheel(UINT fFlags, short zDelta, CPoint point)
{	
	CRect rect;
	GetWindowRect(&rect);

	if (!rect.PtInRect(point))
	{
		return __super::OnMouseWheel(fFlags,zDelta,point);
	}

	if(fFlags==MK_CONTROL)
	{
		if(NULL!=m_pScreenManage)
		{
			return m_pScreenManage->AddScalingByMouseWheel(zDelta);
		}
		
		return FALSE;
	}
	else
	{
		return __super::OnMouseWheel(fFlags,zDelta,point);
	}	
}

void CMultiviewerView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nullptr != m_pScreenManage)
	{
		m_pScreenManage->ViewKeyUp(nChar);
	}
}

void CMultiviewerView::ResetSize()
{
	if (nullptr != m_pScreenManage)
	{
		CSize size = m_pScreenManage->ViewGetSize();

		//��1��Ϊsize�����ù������ֵ,��0��(���-1)
		size.cx -= 1;
		size.cy -= 1;

		//��ΪС��0������쳣,���Լ����ж�
		size.cx = size.cx < 0 ? 0 : size.cx;
		size.cy = size.cy < 0 ? 0 : size.cy;

		SetScrollSizes(MM_TEXT, size);
	}
	else
	{
		SetScrollSizes(MM_TEXT, CSize(0,0));
	}
}

void CMultiviewerView::OnMouseLeave()
{
	if (nullptr != m_pScreenManage)
	{
		m_bMouseLeave = TRUE;

		m_pScreenManage->ViewMouseLeave();
	}
}

void CMultiviewerView::OnDraw(CDC* pDC)
{
	CMultiviewerDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(nullptr!=m_pScreenManage)
	{
		CRect rect;
		GetClientRect(rect);

		//m_pScreenManage->ViewDraw(pDC, rect, GetScrollPos(SB_HORZ), GetScrollPos(SB_VERT));
	}
}

void CMultiviewerView::OnRButtonUp(UINT nFlags, CPoint point)
{
	if (nullptr != m_pScreenManage)
	{
		CRect rect;
		GetClientRect(rect);

		m_pScreenManage->ViewRButtonUp(this, nFlags, point, rect, GetScrollPos(SB_HORZ), GetScrollPos(SB_VERT));
	}
}

void CMultiviewerView::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	if (nullptr != m_pScreenManage)
	{
		m_pScreenManage->AdjustMultiVideoWindowSize();
	}
}


