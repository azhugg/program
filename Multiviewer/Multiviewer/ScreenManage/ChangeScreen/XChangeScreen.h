#pragma once
#include "../resource.h"
#include "XDelegateChangeScreen.h"
#include "XConstantIM.h"

class XScreenManage;
class XScreen;

class XChangeScreen : public CDialogEx
{
	DECLARE_DYNAMIC(XChangeScreen)

public:
	XChangeScreen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XChangeScreen();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_CHANGEASCREEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateChangeScreen* p);

	void SetScreenMange(XScreenManage* p);

	void SetScreen(XScreen* p);

	void ReloadInterface();

	void InitData();

	void InitCombo();

	int GetComboIndex();

	int GetScreenIndex();

	void SetScreenIndex(int n);

private:

	XDelegateChangeScreen *m_pDelegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

	CComboBox m_ComboBox_After;

	int m_ComboIndex;

	int m_ScreenIndex;
	
};