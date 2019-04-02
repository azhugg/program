#pragma once

#include "../resource.h"

#include "XBoardChild.h"



class XDelegateSelectEquipment;
class XScreen;
class XScreenManage;

class XSetBoard : public CDialogEx
{
	DECLARE_DYNAMIC(XSetBoard)

public:
	XSetBoard(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSetBoard();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_BOARD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateSelectEquipment* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void InitBoardChild();

	void InitData();

	void SetEquipment(int n);

	int GetEquipment();

	BOOL CheckVec();

	int GetInputNum();

	int GetOutputNum();

	int GetInput();

	int GetOutput();

	VEC_EQUIPMENTINPUT& GetVecInput();

	VEC_EQUIPMENTOUTPUT& GetVecOutput();

	//////////////////////////////////////////////////////////////////////////

	void SetScreenNumH(int n);

	int GetScreenNumH();

	void SetScreenNumV(int n);

	int GetScreenNumV();

	void SetIsMenuSet(BOOL b);

	BOOL GetIsMenuSet();

private:

	//���ؽ���
	void ReloadInterface();

public:

	inline void SetScreenModel(int n){m_nScreenModel=n;}

	inline int GetScreenModel(){return m_nScreenModel;}

private:

	//ί��
	XDelegateSelectEquipment* m_pDelegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

private:

	XBoardChild m_BoardChildDlg;

	CStatic m_Static_Dialog;

	int m_nEquipment;

	int m_nInputNum;

	int m_nOutputNum;

	VEC_EQUIPMENTINPUT m_VecEquInput;

	VEC_EQUIPMENTOUTPUT m_VecEquOutput;

	//////////////////////////////////////////////////////////////////////////

	int m_nScreenNumH;

	int m_nScreenNumV;

	BOOL m_bIsMenuSet;

	int m_nScreenModel;
};