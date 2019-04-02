#pragma once

#include "XConstantIM.h"

class XDelegateIniManage
{
public:
	XDelegateIniManage(void);
	~XDelegateIniManage(void);

	//������ͼ��С
	virtual void ResetViewSize() = 0;

	//ˢ����ͼ
	virtual void InvalidateView() = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;

	virtual void SetMultiScale(float f)=0;
};

