#pragma once

#include "../resource.h"

class XInputSignal;
class XInputSignalPane;


class XDelegateBorderOverlayDlg;

// CAddExpandDlg �Ի���

class XBorderOverlayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XBorderOverlayDlg)

public:
	XBorderOverlayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XBorderOverlayDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_BORDEROVERLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateBorderOverlayDlg* p);

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

	//�����ź�����
	CString m_InputSignalName;

private:

	//ί��
	XDelegateBorderOverlayDlg* m_pDelegate;

	CMFCColorButton m_BorderColor;
};