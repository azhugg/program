#pragma once
#include "XConstantIM.h"
#include "XBoardChild.h"

class XEquipmentOutputWnd;
class HYXText;
class CMyButton;



class XEquipmentOutput
{
public:
	XEquipmentOutput(void);
	~XEquipmentOutput(void);

	//��ʼ��
	void Init();

	//��������
	void SetRect(CRect r);

	//�������
	void SetBoardIndex(int n);

	//��ȡ���
	int GetBoardIndex();

	//������Ļ���
	void SetScreenIndex(int n);

	//��ȡ��Ļ���
	int GetScreenIndex();

	//������Ļ���
	void SetScreenIndex2(int n);

	//��ȡ��Ļ���
	int GetScreenIndex2();

	//��ȡ����
	CRect GetRect();

	//���ø�����
	void SetOutputBoardChild(XBoardChild* pChild);

	XBoardChild* GetOutputBoardChild();

	//���ؽ���
	void ReloadInterface();

	//��ȡ����
	CRect GetEquipmentRect();

	//���������ź�����
	void SetInputName(CString szName);

	//��ȡ�����ź�����
	CString GetInputName();

	//�������
	void ClearEquipmentWnd();

	//���ComboBox
	void ClearComboBox();

	//������ִ���
	void ClearEquipmentTextWnd();

	//���MAP
	void ClearMapNumOfScreen();

	//��������
	void SetEquipmentType(int n);

	//�����Ƿ�Ϊ��·
	void SetIsTwoScreen(BOOL b);

	//��ȡ�Ƿ�Ϊ��·
	BOOL GetIsTwoScreen();

	void SetIsFirstPan(BOOL b);

	BOOL GetIsFirstPan();

	void SetCheckNum(int n);

	int GetCheckNum();

	void SetComboBox();

	MAP_NUMOFSCREEN& GetMapNumOfScreen();

	void SetMapNumOfScreen(MAP_NUMOFSCREEN& MapNumOfScreen);

public:

	//��������
	void UpdateText();

	void UpdateImage();

	void UpdateComboBox();

	void InitComboBox();

private:

	//��������
	void CreateEquipmentWnd();

	//�������ִ���
	void CreateEquipmentTextWnd();

	//����CheckBox
	void CreateCheckBox();

	//����ComboBox
	void CreateComboBox();

	//void CreateCombo();

public:

	inline void SetBoardType(int n){m_nBoardType=n;}

	inline int GetBoardType(){return m_nBoardType;}

public:

	//������Ļ���
	inline void SetScreenIndex3(int n){m_nScreenIndex3=n;}

	//��ȡ��Ļ���
	inline int GetScreenIndex3(){return m_nScreenIndex3;}

	//������Ļ���
	inline void SetScreenIndex4(int n){m_nScreenIndex4=n;}

	//��ȡ��Ļ���
	inline int GetScreenIndex4(){return m_nScreenIndex4;}

	inline void SetScreenModel(int nModel){m_nScreenModel=nModel;}

	inline int GetScreenModel(){return m_nScreenModel;}

	//���ö�Ӧ��Ļ����
	inline void SetCorrpScreenNum(int n){m_nCorrpScreenNum=n;}

	inline int GetCorrpScreenNum(){return m_nCorrpScreenNum;}

private:

	XBoardChild* m_pChild;

	//����
	CRect m_Rect;

	//�忨����
	CRect m_PaneRect;

	//�忨���
	int m_nBoardIndex;

	//��Ļ���
	int m_nScreenIndex;

	//��Ļ���2
	int m_nScreenIndex2;

	//��Ļ���3
	int m_nScreenIndex3;

	int m_nScreenIndex4;

	//�Ƿ�Ϊ��·
	BOOL m_bIsTwoScreen;

	//�����ź�mingc
	CString m_szInputName;

	//����
	XEquipmentOutputWnd* m_EquipmentWnd;

	//���ִ���
	HYXText* m_EquipmentTextWnd;

	//checkbox
	CMyButton* m_ChecKBox;

	//ComboBox
	CComboBox* m_ComboBox;

	//�ڼ����忨
	BOOL m_bIsFirstPan;

	//checkBox
	int m_nCheckNum;

	MAP_NUMOFSCREEN m_NumOfScreen;

	int m_nScreenModel;

	int m_nCorrpScreenNum;

	int m_nBoardType;

};

