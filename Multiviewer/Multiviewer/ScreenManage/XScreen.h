#pragma once

#include "XConstantIM.h"
#include "XResulationInfo.h"
#include "XAllResulationInfo.h"

class XSignal;
class XExpandInfo;
class XScreenManage;
class XSignalCutInfo;


class XScreen
{
public:
	XScreen(void);
	~XScreen(void);

	//��ȡ��Ļ���
	int GetIndex();

	//������Ļ���
	void SetIndex(int n);

	RECTF GetRect();

	void SetRect(RECTF r);

	//����ź�Դ
	XSignal* AddSignal(
		RECTF& rect, 
		int& nLevel,
		int& nInputIndex,
		CString szAnothgerName,
		unsigned int& signalID,
		unsigned int& signalGroupID,
		XExpandInfo* pExpandInfo,
		BOOL bIsUltra);

	//��ȡ�źż���
	VEC_SIGNAL& GetVecSignal();

	//����ź�Դ����
	void ClearVecSignal();

	//������IDɾ���ź�
	void DeleteSignalBySignalGroupID(XScreenManage *pManage,int nScreenIndex,unsigned int nGroupID);
	void DeleteSignalBySignalID(XScreenManage *pManage,int nScreenIndex,unsigned int nID);

	//ɾ���ź�
	void DeleteSignal(XSignal* p);

	//������Ļ����
	void SetManage(XScreenManage* p);

	//��ȡ��Ļ����
	XScreenManage* GetManage();

	//��Ļ�ֱ��ʲ���
	XResulationInfo* GetResulationInfo();

	//��Ļ�ֱ���
	XAllResulationInfo* GetAllResulationInfo();

	//�����ź��ö�
	void SetSignalTopByGroupID(int nScreenIndex,unsigned int nGroupID);
	void SetSignalTopByID(int nScreenIndex,unsigned int nID);

	//�����ź��õ�
	void SetSignalBottom(int nScreenIndex,unsigned int nGroupID);

	//�����ź�����
	void SetSignalShiftUp(int nScreenIndex,unsigned int nGroupID);

	//�����ź�����
	void SetSignalShiftDown(int nScreenIndex,unsigned int nGroupID);

	XSignal* GetSignalByID(unsigned int nID);

	BOOL CanAddSignal(int i);

	BOOL CanAddSignal();

	//ͬ���ź�����
	void SortSignal();

	int GetScreenHdpi();

	int GetScreenVdpi();

	void SetScreenHdpi(int n);

	void SetScreenVdpi(int n);

	//������Ļ�źŸ���
	void SetAddSignalNumInScreen(int n);

	//��ȡ��Ļ�źŸ���
	int GetAddSignalNumInScreen();

	//����������
	void SetMaxSignalNumInScreen(int n);

	//��ȡ����źŸ���
	int GetMaxSignalNumInScreen();

	//�����Ƿ�Ϊ��·
	void SetIsTwoSignal(BOOL b);

	//��ȡ�Ƿ�Ϊ��·
	BOOL GetIsTwoSignal();

	//���ð忨���
	void SetBoardIndex(int n);

	//��ȡ�忨���
	int GetBoardIndex();

	//������·�ڼ���
	void SetNumOfTwoScreen(int n);

	//��ȡ��·�ڼ���
	int GetNumOfTwoScreen();

	//�������������
	void ResetMaxSignalInScreen();

	//�Ƿ�ΪԤ����
	void SetIsPreview(BOOL b);

	//��ȡ�Ƿ�ΪԤ����
	BOOL GetIsPreview();


public:

	void SeteDataLen(int n);

	void SetReScreenIndex(int n);

	void SetReStatus(int n);

	void SetReScreenHdpi(int n);

	void SetReScreenVdpi(int n);

	void SetReDpiIndex(int n);

	void SetReRefresh(int n);

	int GeteDataLen();

	int GetReScreenIndex();

	int GetReStatus();

	int GetReScreenHdpi();

	int GetReScreenVdpi();

	int GetReDpiIndex();

	int GetReRefresh();

	//////////////////////////////////////////////////////////////////////////
	BOOL GetIsHasSignalOfMatrix();
	void SetIsHasSignalOfMatrix(BOOL b);

	void SetScreenType(int n);
	int GetScreenType();

public:
	
	inline CString GetScreenName(){return m_szScreenName;}

	inline void SetScreenName(CString szName){m_szScreenName=szName;}

	inline BOOL GetIsRight(){return m_bIsRight;}

	inline void SetIsRight(BOOL b){m_bIsRight=b;}

	inline BOOL GetIsBottom(){return m_bIsBottom;}

	inline void SetIsBottom(BOOL b){m_bIsBottom=b;}

	inline void SetScreenRow(int n){m_nRow=n;}

	inline int GetScreenRow(){return m_nRow;}

	inline void SetScreenCol(int n){m_nCol=n;}

	inline int GetScreenCol(){return m_nCol;}

private:

	//��Ļ����
	XScreenManage* m_pManage;

	//��Ļ�ֱ���
	XResulationInfo m_ResulationInfo;

	//��Ļ�ֱ�����Ϣ
	XAllResulationInfo m_AllResulationInfo;

	//�źż���
	VEC_SIGNAL m_VecSignal;

	//��Ļ���
	int m_nIndex;

	//�忨���
	int m_nBoardIndex;

	//����
	RECTF m_Rect;

	int m_Hdpi;

	int m_Vdpi;

	//ÿ����Ļ��������źŸ���
	int m_nAddSignalNum;

	//ÿ����Ļ��������źŸ���
	int m_nMaxSignalNum;

	//��Ļ�Ƿ�Ϊ��·
	BOOL m_bIsTwoSignal;

	//��·���Ϊ�ڼ���
	int m_nNumOfTwoScreen;

	//�Ƿ�ΪԤ����
	BOOL m_bIsPreview;

	//�Ƿ�Ϊ�Ҳ���Ļ
	BOOL m_bIsRight;

	//�Ƿ�Ϊ�ײ�
	BOOL m_bIsBottom;

	int m_nCol;

	int m_nRow;

private:
	//��������
	int m_ScreenIndex;

	int m_ReDataLen;

	int m_ReStatus;

	int m_ReScreenHdpi;

	int m_ReScreenVdpi;

	int m_ReDpiIndex;

	int m_ReRefresh;

	private:

	BOOL m_bIsHasSignalOfMatrix;

	int m_nScreenType;

	CString m_szScreenName;
};

