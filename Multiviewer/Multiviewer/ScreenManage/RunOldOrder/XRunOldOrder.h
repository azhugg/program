#pragma once

#include "../resource.h"

class XDelegateRunOldOrderDlg;
class XScreen;
class XScreenManage;

class XRunOldOrderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XRunOldOrderDlg)

public:
	XRunOldOrderDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XRunOldOrderDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_OLDORDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateRunOldOrderDlg* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void InitData();



private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateRunOldOrderDlg* m_pDelegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

};