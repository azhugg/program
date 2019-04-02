#pragma once

#include "XConstantIM.h"
#include "HYXVTreeNode.h"

class HYXDelegateOutputNode;

class HYXOutputNode : public CWnd
{
	DECLARE_DYNAMIC(HYXOutputNode)

public:
	HYXOutputNode();
	virtual ~HYXOutputNode();

	virtual void PreSubclassWindow();

	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
	
public:

	//��ʼ��
	void Init();

	//�������
	void ClearData();

	//����ί��
	void SetDelegate(HYXDelegateOutputNode* p);

	//��ȡ�����߶�
	int GetScrollHeight();

	//����
	void Scroll(int nPos);

	//ˢ������
	void InvalidateRect();

	//��ȡCWnd
	CWnd* GetWnd();

	//��չ��ť���
	void ExpandBtnClick(int nType, void* pData);

	//���������Ϣ
	void SetOutputInfo(int nOutputCount);

	//�ڵ�ı�
	void NodeItemChange();

	//��ȡչ���豸���
	void GetExpandDeviceItem(HYVEC_VTREENODEITEM& VecItem);

	//��ȡ��������ɫ
	virtual COLORREF GetTreeNodeItemTextColor(HYXVTreeNodeItem* pItem);

private:

	//����
	void Draw(CDC* pDC, CRect rt);

	//��ȡ¥����
	HYXVTreeNodeItem* GetLayerItem(CString szID);

	//��ȡ�豸��
	HYXVTreeNodeItem* GetClassItem(CString szID);

private:

	//ί��
	HYXDelegateOutputNode* m_Delegate;

	//����λ��
	int m_ScrollPos;

	//�Ƿ���
	BOOL m_bDown;

	//�ڵ�
	HYXVTreeNode m_TreeNode;
};


