#pragma once

#include "XConstantIM.h"

class HYXGridItem;

class HYXDelegateGrid
{
public:
	HYXDelegateGrid(void);
	~HYXDelegateGrid(void);

	//��ȡ�������
	virtual int GetScrollWidth() = 0;

	//��ȡ�����߶�
	virtual int GetScrollHeight() = 0;

	//ˮƽ����
	virtual void ScrollH(int nPos) = 0;

	//��ֱ����
	virtual void ScrollV(int nPos) = 0;

	//��ȡ����չ���豸���
	virtual void GetInputExpandDeviceItem(HYVEC_TREENODEITEM& VecItem) = 0;

	//��ȡ���չ���豸���
	virtual void GetOutputExpandDeviceItem(HYVEC_VTREENODEITEM& VecItem) = 0;

	//�����Ƶ������
	virtual void GridRectClick(HYXGridItem* pItem) = 0;

	//����Ҽ�����
	virtual void GridRButtonUp() = 0;

	//��ȡ�ڵ�Ȩ��
	virtual BOOL GetNodePower(int nInputIndex, int nOutputIndex) = 0;
};

