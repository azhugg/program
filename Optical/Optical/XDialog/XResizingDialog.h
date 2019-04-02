#pragma once
#include "XDialog.h"

// XResizingDialog �Ի���

class XResizingDialog : public XDialog
{
	DECLARE_DYNAMIC(XResizingDialog)

public:
	XResizingDialog(UINT nIDD, CWnd *pParent,CString szPtotoPath);   // ��׼���캯��
	virtual ~XResizingDialog();

protected:
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

protected:

	//�Ի�����С���
	int m_DlgMinWidth;

	//�Ի�����С�߶�
	int m_DlgMinHeight;

	CString m_szPtotoPath;
};
