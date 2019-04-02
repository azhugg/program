#pragma once

#include "../resource.h"

class XInputSignal;
class XInputSignalPane;


class XDelegateEDIDDlg;


class XEDIDDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XEDIDDlg)

public:
	XEDIDDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XEDIDDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_EDID };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateEDIDDlg* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	//���������ź�����
	void SetInputSignalName(CString s);

	void InitData();

private:

	//���ؽ���
	void ReloadInterface();

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

private:

	//ί��
	XDelegateEDIDDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;

};