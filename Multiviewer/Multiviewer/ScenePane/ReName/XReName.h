#pragma once

#include "../resource.h"


class XDelegateReName;

class XReName : public CDialogEx
{
	DECLARE_DYNAMIC(XReName)

public:
	XReName(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XReName();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SCENERENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateReName* p);

	void InitData();

	CString GetScreenName();

	void SetTitle(CString szTitle);

	void SetName(CString szName);

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateReName* m_pDelegate;

	//����
	CString m_szScreenName;

	CString m_szTitle;

	CString m_szName;

};