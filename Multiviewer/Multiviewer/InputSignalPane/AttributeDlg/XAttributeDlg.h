#pragma once

#include "../resource.h"

class XInputSignal;
class XInputSignalPane;
class XDelegateAttributeDlg;


class XAttributeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XAttributeDlg)

public:
	XAttributeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XAttributeDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SIGNALATTRIBUTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateAttributeDlg* p);

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
	XDelegateAttributeDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;
};