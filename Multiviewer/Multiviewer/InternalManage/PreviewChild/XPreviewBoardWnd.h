#pragma once

class XPreviewBoard;

class XPreviewBoardWnd : public CWnd
{
	DECLARE_DYNAMIC(XPreviewBoardWnd)

public:
	XPreviewBoardWnd();
	virtual ~XPreviewBoardWnd();

	virtual void PreSubclassWindow();

protected:

	//afx_msg void OnSetCorrespondScreenNum();

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEnable(BOOL bEnable);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);


private:

	enum
	{
		State_Normal,
		State_Focus
	};

public:

	void SetImage(CString szImg);

	void SetCaption(CString szText);

	void SetCheck(BOOL bCheck);

	BOOL GetCheck();

	void SetFillColor(Gdiplus::Color col);

protected:

	virtual BOOL DrawItem(CDC *pDC);

	virtual void DrawImg(Graphics& graphics, CRect& rt);

	virtual void PostLClickMsg();

private:

	void DrawText(Graphics& graphics, CRect& rt);

	void DrawFillColor(Graphics& graphics, CRect& rt);

public:

	void SetParent(XPreviewBoard* p);

protected:

	//״̬
	DWORD m_dwState;

	//�ж�����Ƿ��뿪
	BOOL m_bMouseLeave;

	//�ж�����Ƿ���
	BOOL m_bDowned;

	//�ж�����Ƿ񼤻�
	BOOL m_bFocus;

	//ͼƬ·��
	CString m_strImg;

	//��ʾ����
	CString m_strText;

	//�Ƿ������ɫ
	BOOL m_bFillColor;

	//�����ɫ
	Gdiplus::Color m_FillColor;

private:

	XPreviewBoard* m_pParent;

};


