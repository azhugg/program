#pragma once

#include "..\resource.h"
#include "XConstant.h"
#include "XBtn.h"
#include "XDialog.h"

// XMessageBoxDlg �Ի���

class XMessageBoxDlg : public XDialog
{
	DECLARE_DYNAMIC(XMessageBoxDlg)

public:
	XMessageBoxDlg(CString szText, CString szCaption, UINT uType, CWnd* pParent = NULL,CString szPhotoPath=_T(""));
	
	virtual ~XMessageBoxDlg();

	virtual BOOL OnInitDialog();

	virtual void OnOK();

	virtual void OnCancel();

// �Ի�������
	enum { IDD = IDD_DIALOG_MESSAGEBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnBTNLClick(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:

	//��ʼ���ؼ�
	void InitControl();

	//��ʼ����̬�ı��ؼ�
	void InitControlOfStatic();

	//��ʼ����ť�ؼ�
	void InitControlOfButton();

	//��������
	void AdjustLayout();

	//������̬�ı�����
	void AdjustLayoutOfStatic(CRect& rectDlg);

	//������ť����
	void AdjustLayoutOfButton(CRect& rectDlg);

	//���
	void Clear();

	CString GetTranslationString(CString szKey,CString szDefault=_T(""));

	void OnBnClickedBtn1();

	void OnBnClickedBtn2();

	void OnBnClickedBtn3();

private:

	CString m_szText;
	
	CString m_szCaption;
	
	UINT m_uType;

	CStatic* m_pStatic;

	XBtn* m_pBtnArr;

	int m_nBtnCount;
};
