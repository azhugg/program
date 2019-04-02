#pragma once

#include "XConstantIM.h"

class HYXTreeNodeItem;

class HYXGridRow
{
public:
	HYXGridRow(void);
	~HYXGridRow(void);

public:

	//��ȡ��
	HYXGridItem* GetItem(HYXTreeNodeItem* pNodeItem);

	//��ȡ��
	HYXGridItem* GetItem(int nInputID);

	//��ȡ���
	HYVEC_GRIDITEM& GetVecItem();

	//���ô�ֱ�����
	void SetVNodeItem(HYXVTreeNodeItem* p);

	//��ȡ�Ƿ���ʾ
	BOOL GetShow();

	//�����Ƿ���ʾ
	void SetShow(BOOL b);

	//��������ʾ״̬
	void SetItemShow(BOOL b);

	//��ȡ��ֱ�����
	HYXVTreeNodeItem* GetVNodeItem();

	//��ȡ������
	int GetOutputIndex();

private:

	//������
	void ClearVecItem();

private:

	//���,���ڲ���
	HYMAP_GRIDITEM m_MapItem;

	//���
	HYVEC_GRIDITEM m_VecItem;

	//��ֱ�����
	HYXVTreeNodeItem* m_VNodeItem;

	//�Ƿ���ʾ
	BOOL m_Show;
};

