#pragma once

#include "XConstantIM.h"
#include "HYXTreeNode.h"

class HYXVTreeNode;

class HYXVTreeNodeItem
{
public:
	HYXVTreeNodeItem(void);
	~HYXVTreeNodeItem(void);

public:

	//��������
	void SetData(void* p);

	//��������
	void SetName(CString s);

	//�������ڵ�
	void SetTreeNode(HYXVTreeNode* p);
	
	//��������
	void SetType(int nType);

	//�����Ƿ�������Ϣ
	void SetHaveChildInfo(BOOL b);

	//�����Ƿ��ȡ����Ϣ
	void SetGetChildInfo(BOOL b);

	//������չ
	void SetExpand(BOOL b);

	//���ø��ڵ�
	void SetParentItem(HYXVTreeNodeItem* p);

	//�����Ƿ����
	void SetRoot(BOOL b);

	void SetOutputIndex(int n);

	int GetOutputIndex();

	//��ȡ����
	void* GetData();

	//��ȡ����
	CString GetName();

	//��ȡ����
	int GetType();

	//��ȡ�Ƿ�չ��
	BOOL GetExpand();

	//��ȡչ����ť����
	CRect GetExpandBtnRect();

	//��ȡ����
	HYXVTreeNodeItem* GetRootItem();

	//��ȡ���
	HYVEC_VTREENODEITEM& GetVecItem();

	//����
	void Draw(CDC* pDC, CRect rect);

	//��ȡ�߿�����
	CRect GetFrameRect();

	//��������
	void AdjustLayout(int x, int y);

	//��������������
	void HandleLButtonUP(CPoint p);

	//�����
	void AddItem(HYXVTreeNodeItem* p);

	//�����������С
	void CalculateTotalSize();

	//������
	void ClearVecItem();

private:

	//������������
	void AdjustTextRect(int x, int y);

	//����չ����ť��������
	void AdjustExpandBtnRect(int x, int y);

	//������������
	void AdjustItemRect(int x, int y);

	//�����߿�����
	void AdjustFrameRect(int x, int y);

	//�������
	void ClearData();

	//������չ��ť
	void DrawExpandBtn(CDC* pDC);

	//��������
	void DrawChildItem(CDC* pDC, CRect rect);
	
	//����ֱ��
	void DrawLine(CDC* pDC, CRect rect);

	//�������������С
	CSize GetItemTotalSize();

	//���������������С
	void CalculateItemTotalSize();

private:

	//���ڵ�
	HYXVTreeNode* m_TreeNode;

	//���ڵ�
	HYXVTreeNodeItem* m_ParentItem;

	//�ڵ�����
	int m_Type;

	//����
	void* m_Data;

	//����
	CString m_Name;

	//�Ƿ��ȡ����Ϣ
	BOOL m_GetChildInfo;

	//�Ƿ�չ��
	BOOL m_Expand;

	//�Ƿ�������Ϣ
	BOOL m_HaveChildInfo;

	//�Ƿ����
	BOOL m_Root;

	//��߶�
	int m_ItemHeight;

	//���ִ�С
	CSize m_TextSize;

	//�������С
	CSize m_TotalSize;

	//������
	CSize m_ItemTotalSize;

	//չ����ť����
	CRect m_ExpandBtnRect;

	//��������
	CRect m_TextRect;

	//�߿�����
	CRect m_FrameRect;

	//���
	HYVEC_VTREENODEITEM m_VecItem;

	int m_OutputIndex;
};