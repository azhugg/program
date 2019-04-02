#pragma once
#include "XConstantIM.h"

class XDelegateSaveScence
{
public:
	XDelegateSaveScence(void);
	~XDelegateSaveScence(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	virtual MAP_SCENEGROUP& GetMapSceneGroup()=0;

	virtual int GetScreenType()=0;

};