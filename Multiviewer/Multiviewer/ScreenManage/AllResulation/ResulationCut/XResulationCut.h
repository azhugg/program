#pragma once
#include "../resource.h"


// XAllResulution �Ի���

class XScreenManage;
class XScreen;
class XAllResulution;

class XResulationCut : public CDialogEx
{
	DECLARE_DYNAMIC(XResulationCut)

public:
	XResulationCut(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XResulationCut();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_RESULATIONCUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	afx_msg void OnBtnCancel();
	afx_msg void OnSelRightCut();

	DECLARE_MESSAGE_MAP()

public:

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen*& p);

	void SetParent(XAllResulution* p);

	void ReloadInterface();

	void Init();

	void InitDate();

	void SetResulationIndex(int n);

private:

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

	XAllResulution* m_pAllResulation;

	int m_nResulationIndex;
};
