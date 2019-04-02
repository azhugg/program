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

// MultiviewerView.h : CMultiviewerView ��Ľӿ�
//

#pragma once

class CMultiviewerDoc;
class XDelegateView;
class XBaseScreenManage;

class CMultiviewerView : public CScrollView
{
protected: // �������л�����
	CMultiviewerView();
	DECLARE_DYNCREATE(CMultiviewerView)

// ����
public:
	CMultiviewerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();

protected:

// ʵ��
public:
	virtual ~CMultiviewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseLeave();
	afx_msg BOOL OnMouseWheel(UINT fFlags, short zDelta, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate();

	//������ͼ��С
	void ResetSize();

	void SetScreenManage(XBaseScreenManage* p);

	XBaseScreenManage* GetScreenManage();

private:

	//ί��
	XDelegateView* m_pDelegate;

	XBaseScreenManage* m_pScreenManage;

	//����뿪��ʶ
	BOOL m_bMouseLeave;

};

#ifndef _DEBUG  // MultiviewerView.cpp �еĵ��԰汾
inline CMultiviewerDoc* CMultiviewerView::GetDocument() const
   { return reinterpret_cast<CMultiviewerDoc*>(m_pDocument); }
#endif

