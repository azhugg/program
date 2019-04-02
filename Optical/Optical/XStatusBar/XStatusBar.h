#pragma once


class XStatusBar : public CWnd
{
	DECLARE_DYNAMIC(XStatusBar)

public:
	XStatusBar();
	virtual ~XStatusBar();

protected:
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

public:

	//���ð汾��Ϣ
	void SetVersion(CString szVersion);

	//������Ϣ
	void SetInfo(CString szInfo);

	//���¼��ؽ���
	void ReloadInterface();

	void SetDlgType(DWORD dType);

private:

	void SetTextInfo();

private:

	//�汾��Ϣ
	CString m_szVersion;

	//��Ϣ
	CString m_szInfo;

	//���Ի�������
	DWORD m_dDlgType;
};


