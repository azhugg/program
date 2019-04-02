#pragma once

class XDelegateScreenMoveGrid;
class XScreenMoveInfo;

class XScreenMoveGrid:public CWnd
{
	DECLARE_DYNAMIC(XScreenMoveGrid)

public:
	XScreenMoveGrid();
	virtual ~XScreenMoveGrid();

	virtual void PreSubclassWindow();

	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

	virtual ULONG GetGestureStatus(CPoint ptTouch);

protected:

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

public:

	//��ʼ��
	void Init();

	void SetDelegate(XDelegateScreenMoveGrid* p);

	void SetScreenMoveInfo(XScreenMoveInfo* pInfo);

	//����
	void Reset();

	//������������λ��
	void AdustGridRectPos();

	//����-�Ի����С�ı�
	void ResetByDlgSizeChange();

protected:

	//����������
	void AdjustScroll();

	//����ˮƽ������
	void AdjustScrollH();

	//������ֱ������
	void AdjustScrollV();

	//����
	void Draw(CDC* pDC, CRect rt);

	//��������
	void DrawGrid(CDC* pDC, CRect drawRect);

	//���������������
	void ClearGridRectArr();

	//����������������
	void SetGridRectArr();

	//���ù�����
	void ResetScroll();

private:

	BOOL m_bScrollTimerH;

	int m_nScrollPosH;

	int m_nScrollTimerH;

private:

	BOOL m_bScrollTimerV;

	int m_nScrollPosV;

	int m_nScrollTimerV;

protected:

	XDelegateScreenMoveGrid* m_pDelegate;

	XScreenMoveInfo* m_MoveInfo;

	int m_GridCountH;

	int m_GridCountV;

	int m_GridWidth;

	int m_GridHeight;

	//������������
	CRect* m_GridRectArr;

	//�Ƿ���
	BOOL m_bDown;
};