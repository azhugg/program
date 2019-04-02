
// ChildFrm.h : CChildFrame ��Ľӿ�
//

#pragma once

class XInternalManage;
class XBaseScreenManage;

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// ����
public:

// ����
public:

// ��д
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

#endif

// ���ɵ���Ϣӳ�亯��
protected:

	afx_msg void OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd);

	afx_msg void OnClose();

	DECLARE_MESSAGE_MAP()

public:

	void setParentDelegate(XInternalManage* p);

	void setScreenManage(XBaseScreenManage* p);

	XBaseScreenManage* GetScreenManage();

private:

	XInternalManage* m_pManage;

	XBaseScreenManage* m_pScreenManage;

};
