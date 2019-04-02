#pragma once

#include "../resource.h"

class XDelegateScreenAttributesDlg;
class XScreen;
class XScreenManage;

class XScreenAttributesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XScreenAttributesDlg)

public:
	XScreenAttributesDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XScreenAttributesDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SCREENATTRIBUTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateScreenAttributesDlg* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void InitData();

	//���������ź�����
	void SetInputSignalName(CString s);

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateScreenAttributesDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

};