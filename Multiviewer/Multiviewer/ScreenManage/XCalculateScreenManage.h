#pragma once

#include "XConstantIM.h"

class XScreenManage;
class XSignal;
class XInputSignal;

class XCalculateScreenManage
{
public:
	XCalculateScreenManage(void);
	~XCalculateScreenManage(void);

	//��ͼ��ȡ��С
	static CSize ViewGetSize(XScreenManage* pManage);

	//������ͼԭ��
	static void SetViewPortOrg(CRect& rect, int& noffsetX, int& noffsetY, CSize& size, float& dwScale, CDC& dc);

	//����Ԥ��ǽ����ԭ��
	static void SetPreviewOrg(CRect& rect, int& noffsetX, int& noffsetY, CSize& size, float& dwScale,CSize& orgSize);

	//��ԭ���ŵĵ�
	static void ReductionPoint(XScreenManage* pManage, CRect& rect, int noffsetX, int noffsetY, CPoint& srcPoint, POINTF& desPoint);

	//���ݵ��ȡ��Ļ
	static XScreen* GetScreenByPoint(XScreenManage* pManage, POINTF& point);

	//���ݵ��ȡ�ź�
	static XSignal* GetSignalByPoint(XScreen* pScreen, POINTF& point);

	//�����ź�λ�����ͻ�ȡ�ź�����
	static RECTF GetSignalRectBySignalPosType(XScreen*& pScreen, SIGNALPOSTYPE type);

	//�жϵ����ź�����
	static BOOL DecidePointInSignal(XScreenManage* pManage,XSignal*& pSignal, POINTF& point);

	//static BOOL DecidePointInScreen(XScreenManage* pManage,POINTF& point);

	//�жϵ����ź������λ������
	static POSITIONTYPE DecidePointInSignalPosition(XScreenManage* pManage, RECTF& rect, POINTF& point);

	//����λ�����ͻ�ȡ�������
	static CURSORTYPE GetCursorTypeByPositionType(POSITIONTYPE type);

	//��ȡ�ź���������
	static RECTF GetRectBySignal(XScreenManage* pManage, unsigned int nSignalID);

	//��ȡ��ռ��Ļ������
	static RECTF GetRectByVecScreen(VEC_SCREEN& VecScreen);

	//�ƶ��ź�
	static void MoveSignal(POSITIONTYPE PositionType,RECTF& rect,SIZEF& size);

	//�ƶ��ź�
	static void MoveSignalOfNew(RECTF& rect,SIZEF& size);

	//�ж��������ͼ����
	static BOOL DecidePointInScreen(XScreenManage *pManage,POINTF& point);

	//����ID��ȡ�ź�
	static XSignal* GetSignalByID(XScreenManage *pManage,unsigned int ID);

	//������Ż�ȡ�ź�
	static XInputSignal* GetSignalByIndex(XScreenManage *pManage,int nIndex);

	//��������������
	static int GetIntFromFloat(float fwData);

	//////////////////////////////////////////////////////////////////////////
	static RECTF GetInterRectByAllScreen(XScreenManage* pManage);
	



private:

	//��ȡ��ͼ����ԭ��
	static void GetViewPortOrg(CRect& rect, int& noffsetX, int& noffsetY,
		CSize& size, float& dwScale, int& nOrgX, int& nOrgY);
};





