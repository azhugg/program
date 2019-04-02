#pragma once

#include "XConstantIM.h"

class XDelegateDataManage;

class XDataManage
{
public:
	XDataManage(void);
	~XDataManage(void);

public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate(XDelegateDataManage* p);

	//����
	void Operate(OPERATETYPE type, void* pData);

	//����UDP����
	BOOL HandleUDPData(unsigned char* pData, int nDataLen, SOCKADDR_IN addr);

private:

	//����¶�
	void CheckTemperature();

	//�����¶�
	void ResetTemperature();


private:

	XDelegateDataManage* m_pDelegate;

private:

	//�¶�
	CString m_szTemperature;

	//�����¶�ʱ��
	DWORD m_TemperatureTime;

private:

	//��Ļͬ����Ϣ����
	MAP_SCREENSYNINFO m_MapScreenSynInfo;

private:

	void DecodeInput(unsigned char* pData, int nDataLen);

	void DecodeOutput(unsigned char* pData, int nDataLen);

	void DecodeWindowParamater(unsigned char* pData, int nDataLen);

	void DecodeAsk(unsigned char* pData, int nDataLen);

	void DecodeSceneIndex(unsigned char* pData, int nDataLen);
	
	void DecodeDeviceStatus(unsigned char* pData, int nDataLen);

	void DecodeSignalNum(unsigned char* pData, int nDataLen);

	void DecodePaneIP(unsigned char* pData,int nDataLen);

	void DecodeStreamAddr(unsigned char* pData,int nDataLen);

	void DecodeBitRate(unsigned char* pData, int nDataLen);

	void DecodeMatrixWindowParamater(unsigned char* pData, int nDataLen);
};

