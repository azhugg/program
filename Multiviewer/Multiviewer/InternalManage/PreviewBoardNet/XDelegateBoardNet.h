#pragma once

class XDelegateBoardNet
{
public:
	XDelegateBoardNet(void);
	~XDelegateBoardNet(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;
};