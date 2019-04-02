#pragma once

class HYXVTreeNodeItem;
class HYXTreeNodeItem;
class HYXGridRow;
class PROTOCOL_DeviceInfo;

#define ITEM_SECECTWIDTH		20
#define ITEM_SECECTHEIGHT		20
#define ITEM_SECECTDISTANCEX	3

class HYXGridItem
{
public:
	HYXGridItem(void);
	~HYXGridItem(void);

	//���ô�ֱ�����
	void SetVNodeItem(HYXVTreeNodeItem* p);

	//����ˮƽ�����
	void SetHNodeItem(HYXTreeNodeItem* p);

	void SetGridRow(HYXGridRow* p);

	//��ȡ��ֱ�����
	HYXVTreeNodeItem* GetVNodeItem();

	//��ȡˮƽ�����
	HYXTreeNodeItem* GetHNodeItem();

	HYXGridRow* GetGridRow();

	//��ȡ�Ƿ���ʾ
	BOOL GetShow();

	//�����Ƿ���ʾ
	void SetShow(BOOL b);

	//��������
	void AdjustRect();

	//��ȡ����
	CRect GetRect();

	//��ȡ�������
	int GetInputIndex();

	//��ȡ������
	int GetOutputIndex();

private:

	HYXVTreeNodeItem* m_VNodeItem;

	HYXTreeNodeItem* m_HNodeItem;

	HYXGridRow* m_GridRow;

	//�Ƿ���ʾ
	BOOL m_Show;

	//����
	CRect m_Rect;
};

