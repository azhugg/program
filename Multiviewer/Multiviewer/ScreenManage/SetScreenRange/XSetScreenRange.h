#pragma once

#include "../resource.h"
#include "XConstantIM.h"

class XDelegateSetScreenRange;
class XScreen;
class XScreenManage;

class XSetScreenRange : public CDialogEx
{
	DECLARE_DYNAMIC(XSetScreenRange)

public:
	XSetScreenRange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSetScreenRange();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SCREENRANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateSetScreenRange* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void InitData();

	void SetIsMenuSet(BOOL b);

	BOOL GetIsMenuSet();


	//void SetInputNum(int n);

	//void SetOutputNum(int n);

	////��������忨����
	//void SetVecEquInput(VEC_EQUIPMENTINPUT& VecInput);

	////��������忨����
	//void SetVecEquOutput(VEC_EQUIPMENTOUTPUT& VecOutput);

	void SetEquipmentNum(int n);

	int GetEquipmentNum();

	void SetScreenNumH(int n);

	int GetScreenNumH();

	void SetScreenNumV(int n);

	int GetScreenNumV();

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateSetScreenRange* m_pDelegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

	//int m_nInputNum;

	//int m_nOutputNum;

	//VEC_EQUIPMENTINPUT m_VecEquInput;

	//VEC_EQUIPMENTOUTPUT m_VecEquOutput;

	int m_nEquipmentNum;

	int m_nScreenNumH;

	int m_nScreenNumV;

	BOOL m_bIsMenuSet;

};