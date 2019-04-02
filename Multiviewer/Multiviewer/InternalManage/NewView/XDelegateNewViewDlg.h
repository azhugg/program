#pragma once

class XMenuScreenSetInfo;

class XDelegateNewViewDlg
{
public:
	XDelegateNewViewDlg(void);
	~XDelegateNewViewDlg(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	virtual XMenuScreenSetInfo* GetMenuScreenSetInfo()=0;
};