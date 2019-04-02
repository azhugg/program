#pragma once

#include "XConstantIM.h"

class XDelegateDataManage
{
public:
	XDelegateDataManage(void);
	~XDelegateDataManage(void);

	//��������
	virtual BOOL SendData(char* pData, int nDataLen) = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;
};

