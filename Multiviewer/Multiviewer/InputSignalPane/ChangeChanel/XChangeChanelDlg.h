#pragma once

#include "../resource.h"

class XInputSignal;
class XInputSignalPane;


class XDelegateChangeChenalDlg;


class XChangeChenalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XChangeChenalDlg)

public:
	XChangeChenalDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XChangeChenalDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_CHANGECHANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();

	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateChangeChenalDlg* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	void InitData();

	void InitCombo();

	//���������ź�����
	void SetInputSignalName(CString s);

	int GetCurChe();

	int GetSelectedChe();

private:

	//���ؽ���
	void ReloadInterface();

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

private:

	//ί��
	XDelegateChangeChenalDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;

	int m_CurChe;

	int m_SelectedChe;

	CComboBox m_Combo_SelectedChe;
};

