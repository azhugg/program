#pragma once

#include "XConstantIM.h"

class HYXTreeNode;

class HYXTreeNodeItem
{
public:
	HYXTreeNodeItem(void);
	~HYXTreeNodeItem(void);

public:

	//��������
	void SetData(void* p);

	//��������
	void SetName(CString s);

	//�������ڵ�
	void SetTreeNode(HYXTreeNode* p);
	
	//��������
	void SetType(int nType);

	//�����Ƿ�������Ϣ
	void SetHaveChildInfo(BOOL b);

	//�����Ƿ��ȡ����Ϣ
	void SetGetChildInfo(BOOL b);

	//������չ
	void SetExpand(BOOL b);

	//���ø��ڵ�
	void SetParentItem(HYXTreeNodeItem* p);

	//�����Ƿ����
	void SetRoot(BOOL b);

	void SetInputIndex(int n);

	int GetInputIndex();

	//��ȡ����
	void* GetData();

	//��ȡ����
	CString GetName();

	//��ȡ����
	int GetType();

	//��ȡ�Ƿ�չ��
	BOOL GetExpand();

	//��ȡ����
	HYXTreeNodeItem* GetRootItem();

	//��ȡ���
	HYVEC_TREENODEITEM& GetVecItem();

	//����
	void Draw(CDC* pDC, CRect rt);

	//��ȡ�߿�����
	CRect GetFrameRect();

	//��������
	void AdjustLayout(int x, int y);

	//��������������
	void HandleLButtonUP(CPoint p);

	//�����
	void AddItem(HYXTreeNodeItem* p);

	//�����������С
	void CalculateTotalSize();

	//������
	void ClearVecItem();

private:

	//������������
	void AdjustTextRect(int centerX, int y);

	//����չ����ť��������
	void AdjustExpandBtnRect(int centerX, int y);

	//������������
	void AdjustItemRect(int x, int y);

	//�����߿�����
	void AdjustFrameRect(int x, int y);

	//�������
	void ClearData();

	//������չ��ť
	void DrawExpandBtn(CDC* pDC);

	//��������
	void DrawChildItem(CDC* pDC, CRect rt);

	//����ֱ��
	void DrawLine(CDC* pDC, CRect rt);

	//�������������С
	CSize GetItemTotalSize();

	//���������������С
	void CalculateItemTotalSize();

private:

	//���ڵ�
	HYXTreeNode* m_TreeNode;

	//���ڵ�
	HYXTreeNodeItem* m_ParentItem;

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
	HYVEC_TREENODEITEM m_VecItem;

	int m_InputIndex;
};