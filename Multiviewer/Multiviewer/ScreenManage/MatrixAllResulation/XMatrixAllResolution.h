#pragma once
#include "../resource.h"
#include "XDelegateAllMatrixResolution.h"
#include "XScreen.h"

// XMatrixAllResolution �Ի���

class XScreenManage;

class XMatrixAllResolution : public CDialogEx
{
	DECLARE_DYNAMIC(XMatrixAllResolution)

public:
	XMatrixAllResolution(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XMatrixAllResolution();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_MATRIXALLRESALUTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	afx_msg void OnBtnCancle();
	afx_msg void OnClickedExpand();
	afx_msg void OnSelchangeIndex();
	afx_msg void OnSelchangeRefresh();
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateAllMatrixResolution* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen*& p);

	void ReloadInterface();

	void SetDialog();

	void Init();

	void InitCombo();

	void InitShowData();

private:

	XDelegateAllMatrixResolution* m_Delegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

	CRect m_Rect;

	CRect m_ExpaneRect;

	CComboBox m_Combo_Index;

	CComboBox m_Combo_Refresh;

	CComboBox m_Combo_Model;
};
