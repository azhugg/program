#pragma once

class HYXText : public CWnd
{
	DECLARE_DYNAMIC(HYXText)

public:
	HYXText();
	virtual ~HYXText();

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
};


