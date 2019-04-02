#pragma once
#include "../resource.h"
#include "XDelegateSaveAllScence.h"
#include "XListCtrl.h"

class XInternalManage;
// XResolution �Ի���

class XSaveAllScence : public CDialogEx
{
	DECLARE_DYNAMIC(XSaveAllScence)

public:
	XSaveAllScence(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSaveAllScence();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DLG_SAVEALLSCENCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	afx_msg void OnSelchangeCombo();
	DECLARE_MESSAGE_MAP()

public:

	void SetDelegate(XDelegateSaveAllScence* p);

	void SetManage(XInternalManage* pManage);

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

	void InitList();

	void ReloadListInterface();

	void InitListData();

	int AddInfo(CString szInput);

	void ClearMapSelScene();

	MAP_SELSCENE& GetMapSelScene();

private:

	XDelegateSaveAllScence* m_pDelegate;

	XInternalManage* m_pManege;

	//��������
	CString m_szSceneName;

	//�������
	int m_nSceneIndex;

	CString m_szSceneGroup;

	int m_Index[32];

	CComboBox m_ComboBox_Index;

	CComboBox m_ComboBox_Group;

	XListCtrl m_List_ScreenManage;

	MAP_SELSCENE m_MapSelSceen;
};
