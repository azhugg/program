#pragma once

#include "../resource.h"

class XDelegateScreenMoveChangeDlg;
class XScreen;
class XScreenManage;

class XChangeMoveScreenDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XChangeMoveScreenDlg)

public:
	XChangeMoveScreenDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XChangeMoveScreenDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_MOVECHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBtnSet();

	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateScreenMoveChangeDlg* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void InitData();

	//���������ź�����
	void SetInputSignalName(CString s);

private:

	//���ؽ���
	void ReloadInterface();

	void InitCombo();

private:

	//ί��
	XDelegateScreenMoveChangeDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

private:

	CMFCColorButton m_FColor_Change;

	CMFCColorButton m_BColor_Change;

	int m_Space;

	int m_Speed;
public:
	CComboBox m_ComboBox_BeginX;
	CComboBox m_ComboBox_BeginY;
	CComboBox m_ComboBox_Type;
};