#pragma once

#include "XConstantIM.h"

class XDelegateUserManage
{
public:
	XDelegateUserManage(void);
	~XDelegateUserManage(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;

	//��ȡ�������
	virtual int GetOutputCount() = 0;

	//��ȡ�������
	virtual int GetInputCount() = 0;
};

