#pragma once

#include "XUserManage.h"

class XUserInfo
{
public:
	XUserInfo(void);
	~XUserInfo(void);

public:

	void SetAccount(CString s);

	void SetPassword(CString s);

	void SetPower(POWERTYPE n);

	CString GetAccount();

	CString GetPassword();

	char GetPower();

	//��ȡ�ڵ�Ȩ��
	BOOL GetNodePower(int nInputIndex, int nOutputIndex);

	//��ȡ�ڵ�Ȩ����Ϣ
	XNodePowerInfo* GetNodePowerInfo(int nInputIndex, int nOutputIndex);

	//���ýڵ�Ȩ����Ϣ
	void SetNodePowerInfo(int nInputIndex, int nOutputIndex, BOOL bPower);

	//����ڵ�Ȩ����Ϣ����
	void ClearMapNodePowerInfo();

	MAP_NODEPOWERINFO& GetMapPowerInfo();

public:

	void GetData(CArchive& arch, unsigned char* pKey);

	void SaveData(CArchive& arch, unsigned char* pKey);

	void GetNodePowerInfoData(CArchive& arch, unsigned char* pKey);

	void SaveNodePowerInfoData(CArchive& arch, unsigned char* pKey);

private:

	//�������
	void ClearData();
	
private:

	CString m_Account;

	CString m_Password;

	char m_Power;

	MAP_NODEPOWERINFO m_MapNodePowerInfo;
};

