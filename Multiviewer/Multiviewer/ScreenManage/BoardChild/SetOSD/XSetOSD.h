#pragma once

#include "../resource.h"

class XScreenManage;

class XSetOSD : public CDialogEx
{
	DECLARE_DYNAMIC(XSetOSD)

public:
	XSetOSD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSetOSD();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SCREENINDEX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	DECLARE_MESSAGE_MAP()

public:

	void SetScreenManage(XScreenManage* p);

	void InitCombo();

	int GetOSDIndex();

	void SetInputIndex(int n);

	int GetInputIndex();

private:

	//���ؽ���
	void ReloadInterface();

private:

	XScreenManage* m_pScreenManage;

	CComboBox m_Combo_ScreenIndex;

	int m_nOSDIndex;

	int m_nInputIndex;
};