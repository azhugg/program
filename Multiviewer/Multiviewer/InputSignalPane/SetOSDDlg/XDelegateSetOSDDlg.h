#pragma once

class XDelegateSetOSDDlg
{
public:
	XDelegateSetOSDDlg(void);
	~XDelegateSetOSDDlg(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//��ȡ����״̬
	virtual BOOL GetNetState() = 0;
};

