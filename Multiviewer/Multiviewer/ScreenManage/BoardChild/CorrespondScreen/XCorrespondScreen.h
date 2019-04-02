#pragma once

#include "../resource.h"

class XEquipmentOutput;

class XCorrespondScreen : public CDialogEx
{
	DECLARE_DYNAMIC(XCorrespondScreen)

public:
	XCorrespondScreen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XCorrespondScreen();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_CORRSCREEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	afx_msg void OnSelchange();
	DECLARE_MESSAGE_MAP()

public:

	void SetEquipmentOutputWnd(XEquipmentOutput* p);

	void InitCombo();

	int GetScreenNum();

	int GetScreenIndex1();

	int GetScreenIndex2();

	BOOL CheckIndex(int nIndex);

private:

	//���ؽ���
	void ReloadInterface();

private:

	XEquipmentOutput* m_pEquipmentOutput;

	CComboBox m_Combo_Correspond;

	int m_nScreenNum;

	int m_nScreenIndex1;

	int m_nScreenIndex2;
};