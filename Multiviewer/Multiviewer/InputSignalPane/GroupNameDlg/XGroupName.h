#pragma once

#include "../resource.h"

class XInputSignal;
class XInputSignalPane;


class XGroupName : public CDialogEx
{
	DECLARE_DYNAMIC(XGroupName)

public:
	XGroupName(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XGroupName();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_ADDGROUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	//void SetDelegate(XDelegateSetAnotherNameDlg* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	//���������ź�����
	void SetInputSignalName(CString s);

	void InitData();

	CString GetAnotherName();

private:

	//���ؽ���
	void ReloadInterface();

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

private:

	//ί��
	//XDelegateSetAnotherNameDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;

	//����
	CString m_AnotherName;

};