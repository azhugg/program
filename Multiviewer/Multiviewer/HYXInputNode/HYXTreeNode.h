#pragma once

#include "XConstantIM.h"

#define TREE_EXPANDBTN_WIDTH			20					//��չ��ť���
#define TREE_EXPANDBTN_HEIGHT			20					//��չ��ť�߶�
#define TREE_ITEM_DISTANCEX				25					//��ˮƽ���
#define TREE_ITEM_CHILDDISTANCEX		10					//������ˮƽ���
#define TREE_ITEM_CHILDDISTANCEY		20					//�����ֱ���
#define TREE_ITEM_INSIDEDISTANCEY		2					//���ڲ���ֱ���
#define TREE_TREE_ITEM_FONTSIZE			20					//�������С
#define TREE_ITEM_WIDTHMIN				43					//����С���,��Ϊ������ѡ����Ϊ20��������

class HYXInputNode;

class HYXTreeNode
{
public:
	HYXTreeNode(void);
	~HYXTreeNode(void);

public:

	//��ʼ��
	void Init();

	//�������
	void ClearData();

	//���ýڵ�
	void SetNodes(HYXInputNode* p);

	//����
	void Draw(CDC* pDC, CRect rt, CRect drawRect);

	//��������������
	void HandleLButtonUP(CPoint p);

	//��ȡ�������
	int GetScrollWidth();

	//��ȡ���ִ�С
	CSize GetTextSize(CString s);

	//�����
	HYXTreeNodeItem* AddItem(int nType, CString szName, void* pData,
		HYXTreeNodeItem* pParent = NULL);

	//��������
	void AdjustLayout();

	//��չ��ť���
	void ExpandBtnClick(int nType, void* pData);

	//�ڵ�ı�
	void NodeItemChange(HYXTreeNodeItem* pItem);

	//��ȡ���
	HYVEC_TREENODEITEM& GetVecItem();

	//��ȡ��������ɫ
	COLORREF GetTreeNodeItemTextColor(HYXTreeNodeItem* pItem);

private:

	//����ڵ㼯��
	void ClearVecNode();

	//��ʼ������
	void InitFont();

private:

	//�ڵ�
	HYXInputNode* m_Node;

	//����
	CFont m_Font;

	//���
	HYVEC_TREENODEITEM m_VecItem;
};

