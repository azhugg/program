#pragma once

#include "../resource.h"

class XDelegateDeleteSceneDlg;
class XScreen;
class XScreenManage;

class XDeleteSceneDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XDeleteSceneDlg)

public:
	XDeleteSceneDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XDeleteSceneDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_DELETESCENE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateDeleteSceneDlg* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void SetData(char* pData);

	void InitCombo();

	void SetDelIndex(int n);

	int GetDelIndex();
private:

	//���ؽ���
	void ReloadInterface();
	 
private:

	//ί��
	XDelegateDeleteSceneDlg* m_pDelegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

	int m_Index[32];

	CComboBox m_ComboBox_DelIndex;

	int m_DelIndex;
};