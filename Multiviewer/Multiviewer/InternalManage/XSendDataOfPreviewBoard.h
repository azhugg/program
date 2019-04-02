
#pragma once
#include "XConstantIM.h"

class XInternalManage;

class XSendDataPreviewBoard
{
private:

	XSendDataPreviewBoard();
	~XSendDataPreviewBoard();

public:

	//����Ԥ��������
	static void SendDataOfSetPreviewNet(XInternalManage* pManage);

	//��ȡԤ�����������
	static void SendDataOfGetPreviewNet(XInternalManage* pManage);

	//��ȡ�忨����
	static void AddSendDataOfReadBitRateInfo(XInternalManage* pManage,int nBoardIndex);

	//��������
	static void AddSendDataOfBitRate(XInternalManage* pManage,int nBoardIndex);

	static void SendDataBySaveScene(XInternalManage* pMagage,int nSceneIndex);

private:

	//��ӷ�������-Э��
	static void AddSendDataByProtocol(XInternalManage* pManage, unsigned char* pSrcData, unsigned short nSrcDataLen,ORDERNUM orderNum,ORDERTYPE orderType);

	static unsigned short CheckNum(unsigned char *pData,int nLen);

public:

	static int m_nIndex;
	static int m_nChenal;

};