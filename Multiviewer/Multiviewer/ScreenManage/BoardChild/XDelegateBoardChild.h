#pragma once

class XDelegateBoardChild
{
public:
	XDelegateBoardChild(void);
	~XDelegateBoardChild(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;
};