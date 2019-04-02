#pragma once
#include "../resource.h"
#include "XDelegateSaveScence.h"


// XResolution �Ի���

class XSaveScence : public CDialogEx
{
	DECLARE_DYNAMIC(XSaveScence)

public:
	XSaveScence(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSaveScence();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DLG_SAVESCENCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	afx_msg void OnSelchangeCombo();
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateSaveScence* p);

	void SetData(char* pData);

	//���ؽ���
	void ReloadInterface();

	void InitCombo();

	void InitComboIndex();

	void InitComboGroup();

	//��������
	CString GetSceneName();

	//�������
	int GetSceneIndex();

	CString GetSceneGroup();

	void InitIndex();

private:

	XDelegateSaveScence* m_pDelegate;

	//��������
	CString m_szSceneName;

	//�������
	int m_nSceneIndex;

	CString m_szSceneGroup;

	int m_Index[32];

	CComboBox m_ComboBox_Index;

	CComboBox m_ComboBox_Group;
};
