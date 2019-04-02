#pragma once

#include "XConstantIM.h"
#include "XUDPWatchPaneToolBar.h"

class XDelegateUDPWatchPane;

// XUDPWatchPane

class XUDPWatchPane : public CDockablePane
{
	DECLARE_DYNAMIC(XUDPWatchPane)
public:

	XUDPWatchPane();
	virtual ~XUDPWatchPane();

	virtual BOOL CanBeClosed() const{return FALSE;};

	virtual BOOL FloatPane(CRect rectFloat, AFX_DOCK_METHOD dockMethod = DM_UNKNOWN, bool bShow = true) { return FALSE; }

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnClear();
	DECLARE_MESSAGE_MAP()

public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate(XDelegateUDPWatchPane* pDelegate);

	//���ؽ���
	void ReloadInterface();

	//���UDP��Ϣ
	void AddUDPInfo(unsigned char* pData, int nDataLen);

public:

	//��ȡ�ַ���
	CString GetTranslationString(CString szKey, CString szDefault);

private:

	//����Pane
	void CreatePane();

	//��������
	void AdjustLayout();

	//��ʼ������
	void InitFont();

	//��ʼ����Ϣ�б��
	BOOL InitListBoxInfo();

	//��ʼ��������
	BOOL InitToolBar();

	//�����Ϣ
	void AddInfo(CString szInfo);

private:

	//ί��
	XDelegateUDPWatchPane* m_pDelegate;

	//��Ϣ�б��
	CListBox m_ListBox_Info;

	//������
	XUDPWatchPaneToolBar m_wndToolBar;

	//��Ϣ���
	int m_InfoIndex;

	CFont m_Font;
};


