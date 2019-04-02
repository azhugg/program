#pragma once

#include "XConstantIM.h"

#define HTREE_EXPANDBTN_WIDTH			20					//��չ��ť���
#define HTREE_EXPANDBTN_HEIGHT			20					//��չ��ť�߶�
#define HTREE_LEFTWIDTH					27					//����߿��
#define HTREE_CHILDITEM_INDENTATION		20					//�����������
#define HTREE_ITEM_DISTANCEY			15					//�ֱ���

class HYXOutputNode;

class HYXVTreeNode
{
public:
	HYXVTreeNode(void);
	~HYXVTreeNode(void);

public:

	//��ʼ��
	void Init();

	//�������
	void ClearData();

	//���ýڵ�
	void SetNodes(HYXOutputNode* p);

	//����
	void Draw(CDC* pDC, CRect rect, CRect drawRect);

	//��������������
	void HandleLButtonUP(CPoint p);

	//��ȡ�����߶�
	int GetScrollHeight();

	//��ȡ���ִ�С
	CSize GetTextSize(CString s);

	//��ȡ¥����
	HYXVTreeNodeItem* GetLayerItem(CString szID);

	//��ȡ�豸��
	HYXVTreeNodeItem* GetClassItem(CString szID);

	//�����
	HYXVTreeNodeItem* AddItem(int nType, CString szName, void* pData,
		HYXVTreeNodeItem* pParent = NULL);

	//��������
	void AdjustLayout();

	//��չ��ť���
	void ExpandBtnClick(int nType, void* pData);

	//�ڵ�ı�
	void NodeItemChange(HYXVTreeNodeItem* pItem);

	//��ȡ���
	HYVEC_VTREENODEITEM& GetVecItem();

	//��ȡ��������ɫ
	COLORREF GetTreeNodeItemTextColor(HYXVTreeNodeItem* pItem);

private:

	//����ڵ㼯��
	void ClearVecNode();

	//��ʼ������
	void InitFont();

private:

	//�ڵ�
	HYXOutputNode* m_Node;

	//����
	CFont m_Font;

	//���
	HYVEC_VTREENODEITEM m_VecItem;
};

