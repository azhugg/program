#pragma once

#include "XConstantIM.h"

class HYXDelegateGrid;

class HYXGrid : public CWnd
{
	DECLARE_DYNAMIC(HYXGrid)

public:
	HYXGrid();
	virtual ~HYXGrid();

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
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
	 
public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate(HYXDelegateGrid* p);

	//����ˮƽ������
	void AdjustScrollH();

	//������ֱ������
	void AdjustScrollV();

	//��������
	void AdjustGrid();

protected:

	//����
	void Draw(CDC* pDC, CRect rt);

	//����ֱ��
	void DrawLine(CDC* pDC, CRect rect, CRect drawRect);

	//���Ʊ��
	virtual void DrawGrid(CDC* pDC, CRect drawRect);

	//�������м���
	void ClearVecGridRow();

	//��ȡ�����
	HYXGridRow* GetGridRow(HYXVTreeNodeItem* pNodeItem);

	//��ȡ�����
	HYXGridRow* GetGridRow(int nOutputID);

	//���ñ������ʾ״̬
	void SetGridRowShow(BOOL b);

	//��ʼ������
	void InitFont();

	//����ڵ�Ȩ����Ϣ����
	void ClearMapNodePower();

	//��������������
	void HandleLButtonUP(CPoint p);

private:

	//ί��
	HYXDelegateGrid* m_Delegate;

	//����
	CFont m_Font;

private:

	BOOL m_bScrollTimerH;

	int m_nScrollPosH;

	int m_nScrollTimerH;

	int m_ScrollPosH;

private:

	BOOL m_bScrollTimerV;

	int m_nScrollPosV;

	int m_nScrollTimerV;

	int m_ScrollPosV;

protected:

	//����м��ϣ����ڲ���
	HYMAP_GRIDROW m_MapGridRow;

	//����м���
	HYVEC_GRIDROW m_VecGridRow;

	//ˮƽֱ�߼���
	HYVEC_NUM m_VecLineX;

	//��ֱֱ�߼���
	HYVEC_NUM m_VecLineY;

	//�Ƿ���
	BOOL m_bDown;
};


