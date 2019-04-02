#pragma once

#include "../resource.h"

class XVideoPreviewFrame;

// CChangeInputDlg �Ի���

class CChangeInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeInputDlg)

public:
	CChangeInputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeInputDlg();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DLG_CHANGEPREVIEWINPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:
	
	void SetInputIndex(int n);

	int GetInputIndex();

	void SetFrame(XVideoPreviewFrame* p);

	int GetSelectIndex();

	BOOL GetIsUltra(int nIndex);

private:

	void InitComboInput();

	void ReloadInterface();

	void InitData();

private:

	int m_nInputIndex;

	CComboBox m_Combo_Input;

	int m_nSelectIndex;

	XVideoPreviewFrame* m_Frame;

};
