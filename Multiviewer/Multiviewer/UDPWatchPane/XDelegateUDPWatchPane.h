#pragma once

class XDelegateUDPWatchPane
{
public:
	XDelegateUDPWatchPane(void);
	~XDelegateUDPWatchPane(void);

	//��ȡCWnd
	virtual CWnd* GetCWND() = 0;

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;
};

