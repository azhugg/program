#pragma once
#include "..\resource.h"

class XDelegateSetRowResoluation;
class XScreenManage;
class XScreen;

// CAboutDlg �Ի���

class XSetRowResoluation : public CDialogEx
{
	DECLARE_DYNAMIC(XSetRowResoluation)

public:
	XSetRowResoluation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSetRowResoluation();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_ROWRESOLUATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnClickedOk();
	afx_msg void OnSelDpiChange();

	DECLARE_MESSAGE_MAP()

public:

	inline void SetScreenManage(XScreenManage* p){m_pScreenManage=p;} 

	inline void SetScreen(XScreen* p){m_pScreen=p;}

public:

	void SetDelegate(XDelegateSetRowResoluation* p);

	void Init();

	void InitData();

	void ReloadInterface();

private:

	XDelegateSetRowResoluation* m_Delegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;
};
