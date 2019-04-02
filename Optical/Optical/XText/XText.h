#pragma once

class XText : public CWnd
{
	DECLARE_DYNAMIC(XText)

public:
	XText();
	virtual ~XText();

	virtual void PreSubclassWindow();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

public:

	void SetText(CString szText);

	void SetFillColor(COLORREF color);

	void SetTextColor(COLORREF color);

	void SetVertical(BOOL b);

	void SetTextSize(int nSize);

	void SetLeft(BOOL b);

private:

	void DrawText(Graphics& graphics, CRect& rt);

protected:
	
	//�����ɫ
	COLORREF m_FillColor;

	//������ɫ
	COLORREF m_TextColor;

	//����
	CString m_Text;

	//��ֱ
	BOOL m_Vertical;

	//����
	BOOL m_Left;

	//�����С
	int m_nTextSize;
};


