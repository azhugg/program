#pragma once

#include "../resource.h"


class XDelegateNewViewDlg;
class XInternalManage;


class XNewViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XNewViewDlg)

public:
	XNewViewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XNewViewDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_VIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateNewViewDlg* p);

	void SetBaseManage(XInternalManage* p);

	//���������ź�����
	void SetViewName(CString s);

	CString GetViewName();

	int GetBeginIndex();

	void InitData();

	void InitCombo();

	int GetScreenModel();

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateNewViewDlg* m_pDelegate;

	XInternalManage* m_pBaseManage;

	CComboBox m_Combox_Model;

	int m_nScreenModel;

	//�����ź�����
	CString m_ViewName;

	int m_BeginIndex;
};