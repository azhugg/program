#pragma once

#include "XConstantIM.h"

class XInputSignalPane;
class XInputSignal;

class XSendDataInputSignal
{
public:

	//��ӷ�������-OSD
	static void AddSendDataOfOSDData(XInputSignalPane* pPane, XInputSignal* pInputSignal);

	//��ӷ�������-OSD
	static void AddSendDataOfOSD(XInputSignalPane* pPane, XInputSignal* pInputSignal,int n);

	//��ӷ�������-�źŲü�
	static void AddSendDataOfSignalCut(XInputSignalPane* pPane, XInputSignal* pInputSignal);

	static void AddSendDataOfBorderOverlay(XInputSignalPane* pPane, XInputSignal* pInputSignal);

	static void AddSendDataOfEDID(XInputSignalPane* pPane, XInputSignal* pInputSignal);

	static void AddSendDataOfChangeChenal(XInputSignalPane* pPan,XInputSignal* pInputSignal,int& nCurChe,int& nSelectedChe);

	static void AddSendDataOfStreamAddr(XInputSignalPane* pPane,XInputSignal* pInputSignal);

	static void AddSendDataOfPaneIPAddr(XInputSignalPane* pPane,XInputSignal* pInputSignal);

	//��ȡ�忨��������
	static void AddSendDataOfGetPaneNet(XInputSignalPane* pPane,XInputSignal* pInputSignal);

	static void AddSendDataOfGetStreamAddr(XInputSignalPane* pPane,XInputSignal* pInputSignal);

private:
	//��ӷ�������
	static void AddSendDataByProtocol(XInputSignalPane* pPane, unsigned char* pSrcData, unsigned short nSrcDataLen,ORDERNUM orderNum,ORDERTYPE orderType);

	//У���
	static unsigned short CheckNum(unsigned char *pData,int nLen);

private:
	XSendDataInputSignal(void);
	~XSendDataInputSignal(void);

public:

	static int m_nIndex;
	static int m_nChenal;
};

