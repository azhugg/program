#pragma once

class XDelegateNetManage
{
public:
	XDelegateNetManage(void);
	~XDelegateNetManage(void);

	//��ȡ���ھ��
	virtual HWND GetHWND() = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//����UDP����
	virtual void HandleUDPData(unsigned char* pData, int nDataLen, SOCKADDR_IN addr) = 0;
};

