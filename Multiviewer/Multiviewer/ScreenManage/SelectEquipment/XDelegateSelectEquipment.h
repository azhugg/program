#pragma once

class XDelegateSelectEquipment
{
public:
	XDelegateSelectEquipment(void);
	~XDelegateSelectEquipment(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//�Ƿ��¼
	virtual BOOL IsLogin() = 0;
};