#pragma once
#include "../resource.h"
#include "XDelegateResolution.h"
#include "XScreen.h"

// XResolution �Ի���

class XScreenManage;

class XResolution : public CDialogEx
{
	DECLARE_DYNAMIC(XResolution)

public:
	XResolution(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XResolution();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_SPLICRESULATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	afx_msg void OnBtnCancle();
	afx_msg void OnClickedExpand();
	afx_msg void OnSelchangeIndex();
	afx_msg void OnSelchangeRefresh();
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateResolution* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen*& p);

	void ReloadInterface();

	void SetDialog();

	void Init();

	void InitCombo();

	void InitShowData();

private:

	XDelegateResolution* m_Delegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

	CRect m_Rect;

	CRect m_ExpaneRect;

	CComboBox m_Combo_Index;

	CComboBox m_Combo_Refresh;
};
