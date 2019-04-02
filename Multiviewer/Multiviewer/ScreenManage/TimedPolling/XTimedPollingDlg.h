#pragma once

#include "../resource.h"

class XDelegateTimedPollingDlg;
class XScreen;
class XScreenManage;

class XTimedPollingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XTimedPollingDlg)

public:
	XTimedPollingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XTimedPollingDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_TIMEDPOLLING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBtnOK();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateTimedPollingDlg* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void InitData();

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateTimedPollingDlg* m_pDelegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

};