#pragma once


// XChildDialog �Ի���

class XChildDialog : public CDialogEx
{
	DECLARE_DYNAMIC(XChildDialog)

public:
	XChildDialog(UINT nIDD,CWnd *pParent);   // ��׼���캯��
	virtual ~XChildDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	DECLARE_MESSAGE_MAP()

protected:

	//���ƶԻ���
	virtual void DrawDlg(CDC* pDC);

protected:

	//VK_RETURN״̬
	BOOL m_bEnableVK_RETURN;

	//VK_ESCAPE״̬
	BOOL m_bEnableVK_ESCAPE;
};
