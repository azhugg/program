#pragma once

#include "XConstantIM.h"
#include "HYXTreeNode.h"

class HYXDelegateInputNode;

class HYXInputNode : public CWnd
{
	DECLARE_DYNAMIC(HYXInputNode)

public:
	HYXInputNode();
	virtual ~HYXInputNode();

	virtual void PreSubclassWindow();

	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	
public:

	//��ʼ��
	void Init();

	//�������
	void ClearData();

	//����ί��
	void SetDelegate(HYXDelegateInputNode* p);

	//��ȡ�������
	int GetScrollWidth();

	//����
	void Scroll(int nPos);

	//ˢ������
	void InvalidateRect();

	//��ȡCWnd
	CWnd* GetWnd();

	//��չ��ť���
	void ExpandBtnClick(int nType, void* pData);

	//����������Ϣ
	void SetInputInfo(int nInputCount);

	//�ڵ�ı�
	void NodeItemChange();

	//��ȡչ���豸���
	void GetExpandDeviceItem(HYVEC_TREENODEITEM& VecItem);

	//��ȡ��������ɫ
	virtual COLORREF GetTreeNodeItemTextColor(HYXTreeNodeItem* pItem);

private:

	//����
	void Draw(CDC* pDC, CRect rt);

private:

	//ί��
	HYXDelegateInputNode* m_Delegate;

	//����λ��
	int m_ScrollPos;

	//�Ƿ���
	BOOL m_bDown;

	//�ڵ�
	HYXTreeNode m_TreeNode;
};


