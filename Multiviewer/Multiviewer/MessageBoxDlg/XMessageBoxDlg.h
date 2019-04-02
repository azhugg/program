#pragma once

#include "..\resource.h"

class XDelegateMessageBoxDlg;
// XMessageBoxDlg �Ի���

class XMessageBoxDlg : public CDialogEx
{
	DECLARE_DYNAMIC(XMessageBoxDlg)

public:
	XMessageBoxDlg(CString szText, CString szCaption, UINT uType, 
		CWnd* pParent = NULL);
	
	virtual ~XMessageBoxDlg();

	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();

// �Ի�������
	enum { IDD = IDD_DLG_MESSAGEBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateMessageBoxDlg* p);

private:

	//��ʼ���ؼ�
	void InitControl();

	//��ʼ����̬�ı��ؼ�
	void InitControlOfStatic();

	//��ʼ����ť�ؼ�
	void InitControlOfButtn();

	//��������
	void AdjustLayout();

	//������̬�ı�����
	void AdjustLayoutOfStatic(CRect& rectDlg);

	//������ť����
	void AdjustLayoutOfButtn(CRect& rectDlg);

	//���
	void Clear();

private:

	CString m_szText;
	
	CString m_szCaption;
	
	UINT m_uType;

	CStatic* m_pStatic;

	CButton* m_pBtnArr;

	int m_nBtnCount;

	//ί��
	XDelegateMessageBoxDlg* m_pDelegate;
};
