#pragma once

#include "../resource.h"

class XInputSignal;
class XInputSignalPane;


class XDelegateUltraAttributeDlg;


class XUltraAttributeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XUltraAttributeDlg)

public:
	XUltraAttributeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XUltraAttributeDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SIGNALULTRAATTRIBUTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateUltraAttributeDlg* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	void InitData();

	//���������ź�����
	void SetInputSignalName(CString s);

private:

	//���ؽ���
	void ReloadInterface();

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

private:

	//ί��
	XDelegateUltraAttributeDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;
};