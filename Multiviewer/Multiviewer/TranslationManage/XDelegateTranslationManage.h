#pragma once

#include "XConstantIM.h"

class XDelegateTranslationManage
{
public:
	XDelegateTranslationManage(void);
	~XDelegateTranslationManage(void);

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;
};

