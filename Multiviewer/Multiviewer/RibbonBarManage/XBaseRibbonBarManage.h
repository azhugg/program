#pragma once

#include "XConstantIM.h"

class XDelegateRibbonBarManage;

class XBaseRibbonBarManage
{
public:
	XBaseRibbonBarManage(void);
	virtual ~XBaseRibbonBarManage(void);

public:

	//��ʼ��
	virtual void Init() = 0;

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type) = 0;

	//���ؽ���
	virtual void ReloadInterface() = 0;

	//�����������͸��¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type) = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;
	
public:

	//����ί��
	void SetDelegate(XDelegateRibbonBarManage* p);

protected:

	//ί��
	XDelegateRibbonBarManage* m_pDelegate;
};

