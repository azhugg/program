#pragma once

#include "XConstantIM.h"
#include <vector>

class XScreenManage;
class XScreen;
class XSignal;

class XSendDataScreenManage
{
public:

	//��ӷ�������-�ź�
	static void AddSendDataOfSignal(XScreenManage* pScreenManage, XSignal*& pSignal,RECTF& rect);

	//������Ӿ������ݡ��ź�
	static void AddSendDataOfMatrixSignal(XScreenManage* pScreenManage,XSignal* pSignal,XScreen* pScreen);

	//��ӷ�������-�������
	static void AddSendDataOfFinash(XScreenManage* pScreenManage);

	//��ӷ�������-ɾ�������ź�
	static void AddSendDataOfDeleteAllSignal(XScreenManage* pScreenManage);

	//ɾ�������ź�
	static void AddSendDataOfDeleteAllMatrixSignal(XScreenManage* pScreenManage);

	//��ӷ�������-�ź��ö�
	static void AddSendDataOfSetSignalTop(XScreenManage* pScreenManage,int nScreenIndex,unsigned int ID,int nNum,BOOL bIsTwoScreen);

	//��ӷ�������-�ź��õ�
	static void AddSendDataOfSetSignalBottom(XScreenManage* pScreenManage,int nScreenIndex,unsigned int ID,int nNum,BOOL bIsTwoScreen);

	//��ӷ�������-�ź�����
	static void AddSendDataOfSetSignalShiftUP(XScreenManage* pScreenManage, int nScreenIndex,unsigned int ID,int nNum,BOOL bIsTwoScreen);

	//��ӷ�������-�ź�����
	static void AddSendDataOfSetSignalShiftDown(XScreenManage* pScreenManage, int nScreenIndex,unsigned int ID,int nNum,BOOL bIsTwoScreen);

	//��ӷ�������-�ر��ź�
	static void AddSendDataOfSignalClose(XScreenManage* pScreenManage,int nScreenIndex,unsigned int ID,int nNum,BOOL bIsTwoScreen);

	//��ӷ�������-�ر��ź�(����)
	static void AddSendDataOfDeleteMatrixSignal(XScreenManage* pScreenManage,XScreen* pScreen);

	//��ӷ�������-��ȡĻ����
	static void AddSendDataOfGetScreenParamater(XScreenManage* pScreenManage);

	//��ӷ�������-��ȡ�ź���Ϣ
	static void AddSendDataOfGetSignalParamater(XScreenManage* pScreenManage);

	//��ӷ�������-��ȡ������Ϣ
	static void AddSendDataOfGetWindowParamater(XScreenManage* pScreenManage);

	//��ӷ�������-���泡��
	static void SendDataBySaveScene(XScreenManage* pScreenManage,int nSceneIndex);

	//��ӷ�������-�򿪳���
	static void SendDataByOpenScene(XScreenManage* pScreenManage,int nSceneIndex);

	//��ӷ�������-��ȡ�������
	static void AddSendDataOfDeleteScene(XScreenManage* pScreenManage,int nSceneIndex);

	//��ӷ�������-������Ļ�ֱ���
	static void SendDataOfSetScreenResualtion(XScreenManage* pScreenManage,XScreen*& pScreen);

	//��ӷ�������-����������Ļ�ֱ���
	static void SendDataOfSetAllScreenResualtion(XScreenManage* pScreenManage);

	static void SendDataOfSetScreenRowResualtion(XScreenManage* pScreenManage);

	//ȫ���ֱ���֮ǰ
	static void AddSendDataOfResulationFront(XScreenManage* pScreenManage);

	//��ӷ�������-��Ļ��������
	static void SendDataOfScreenMove(XScreenManage* pScreenManage,XScreen*& pScreen);

	//��ӷ�������-��Ļ������������
	static void SendDataOfScreenMoveData(XScreenManage* pScreenManage,unsigned char* pMutrixData,int nMutrixDataLen);

	//��ӷ�������-ʱ����
	static void SendDataByTimedPolling(XScreenManage* pScreenManage);

	//��ӷ�������-ѯ���Ƿ���Է���
	static void SendDataOfScreenMoveAsk(XScreenManage* pScreenManage);

	//��ӷ�������-��ȡ�������
	static void AddSendDataOfGetSceneIndex(XScreenManage* pScreenManage);

	//��ӷ�������-ִ�о�ָ��
	static void SendDataByRunOldOrder(XScreenManage* pScreenManage);

	//��ȡ�豸״̬
	static void SendDataByDeviceStatus(XScreenManage* pScreenManage);

	//����ƴ�Ӹ�λ��
	static void AddSendDataOfScreenMoveOff(XScreenManage* pScreenManage);

	//����ƴ�Ӳ���ʾ
	static void AddSendDataOfScreenMoveZero(XScreenManage* pScreenManage);

	//����ƴ�Ӹ�λ��
	static void AddSendDataOfScreenMoveOn(XScreenManage* pScreenManage);

	//����ƴ�Ӳ���
	static void AddSendDataOfChangeMoveParamater(XScreenManage* pScreenManage);

	//��ȡ�ź����
	static void AddSendDataOfGetSignalNum(XScreenManage* pScreenManage);

	//��ӷ�������-������Ļ�ֱ���(����)
	static void SendDataOfSetMatrixScreenResualtion(XScreenManage* pScreenManage,XScreen* pScreen);

	static void SendDataOfSetMatrixAllScreenResualtion(XScreenManage* pScreenManage);

	//��ȡ������Ļ����
	static void AddSendDataOfGetMatrix(XScreenManage* pScreenManage);

	//*****************
	static BOOL GetReScreenResulation(XScreenManage* pScreenManage,XScreen*& pScreen,int& nReH,int& nReV);
	static BOOL GetReSignalResulation(XScreenManage* pScreenManage,XSignal*& pSignal,int& nResH,int& nResV);

private:

	//��ӷ�������-�ر���Ļ�ź�
	static void AddSendDataOfScreenClose(XScreenManage* pScreenManage, int nScreenIndex, char type);

	//��ӷ�������-Э��
	static void AddSendDataByProtocol(XScreenManage* pScreenManage, unsigned char* pSrcData, unsigned short nSrcDataLen,ADDRESSTYPE addressType,ORDERNUM orderNum,ORDERTYPE orderType);

	//У���
	static unsigned short CheckNum(unsigned char *pData,int nLen);

private:
	XSendDataScreenManage(void);
	~XSendDataScreenManage(void);

public:

	static int m_Index;

	static int m_Chenal;

	static int m_Index2;

	static int m_Chenal2;

	static int m_nScreenNumOfTwo;
};

