#pragma once

class XSocketUDP;
class XDelegateNetManage;

class XNetManage
{
public:
	XNetManage(void);
	~XNetManage(void);

	//��ʼ��
	virtual void Init();

	//��ȡ״̬
	virtual BOOL GetState();

	//���ʹ�������
	virtual BOOL SendData(CString szIP, int nPort, const char* pData, const int nLen);

	//����UDP��Ϣ
	virtual void HandleUDPMsg(WPARAM wParam, LPARAM lParam);

public:

	//����UDP����
	void HandleUDPData(unsigned char* pData, int nDataLen, SOCKADDR_IN addr);

	void SetDelegate(XDelegateNetManage* p);

private:

	//��
	void Open();

	//�ر�
	void Close();

private:

	//Socket
	XSocketUDP* m_pSocketUDP;

	XDelegateNetManage* m_pDelegate;

};

