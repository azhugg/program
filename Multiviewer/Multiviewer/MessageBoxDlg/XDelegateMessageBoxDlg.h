#pragma once

class XDelegateMessageBoxDlg
{
public:
	XDelegateMessageBoxDlg(void);
	~XDelegateMessageBoxDlg(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;
};

