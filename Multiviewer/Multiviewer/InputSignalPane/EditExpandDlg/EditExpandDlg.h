#pragma once

#include "../resource.h"

class XDelegateEditExpandDlg;
class XInputSignalExpand;
class XInputSignalPane;

// CEditExpandDlg �Ի���

class CEditExpandDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditExpandDlg)

public:
	CEditExpandDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditExpandDlg();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DLG_EDITEXPAND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateEditExpandDlg* p);

	//���������źžֲ��Ŵ�
	void SetInputSignalExpand(XInputSignalExpand* p);

	void SetInputSignalPan(XInputSignalPane* p);

private:

	//���ؽ���
	void ReloadInterface();

	//��ʼ����ʾ����
	void InitShowData();

private:

	//ί��
	XDelegateEditExpandDlg* m_pDelegate;

	//�����źžֲ��Ŵ�
	XInputSignalExpand* m_InputSignalExpand;

	XInputSignalPane* m_InputSignalPan;
};
