#pragma once

#include "../resource.h"


class XDelegateSetScreenName;


class XSetScreenName : public CDialogEx
{
	DECLARE_DYNAMIC(XSetScreenName)

public:
	XSetScreenName(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSetScreenName();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SCREENNAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateSetScreenName* p);

	void InitData();

	CString GetScreenName();

	void SetTitle(CString szTitle);

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateSetScreenName* m_pDelegate;

	//����
	CString m_szScreenName;

	CString m_szTitle;

};