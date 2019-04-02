#pragma once

#include "../resource.h"

class XDelegateMatrixScreenAttributesDlg;
class XScreen;
class XScreenManage;

class XScreenMatrixAttributesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XScreenMatrixAttributesDlg)

public:
	XScreenMatrixAttributesDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XScreenMatrixAttributesDlg();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_MATRIXSCREENATTRIBUTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateMatrixScreenAttributesDlg* p);

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
	XDelegateMatrixScreenAttributesDlg* m_pDelegate;

	//�����ź�����
	CString m_InputSignalName;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

};