#pragma once

#include "../resource.h"

class XVideoPreviewFrame;

// CChangeRTSPAddrDlg �Ի���

class CChangeRTSPAddrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeRTSPAddrDlg)

public:
	CChangeRTSPAddrDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeRTSPAddrDlg();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DLG_CHANGERTSPADDR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:
	
	void SetRTSPAddr(CString s);

	CString GetRTSPAddr();

	void SetFrame(XVideoPreviewFrame* p);

private:

	CString m_RTSPAddr;

	XVideoPreviewFrame* m_Frame;
};
