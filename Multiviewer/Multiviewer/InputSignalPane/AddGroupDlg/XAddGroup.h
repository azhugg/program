#pragma once

#include "../resource.h"


class XInputSignal;
class XInputSignalPane;


class XDelegateAddGroup;


class XAddGroup : public CDialogEx
{
	DECLARE_DYNAMIC(XAddGroup)

public:
	XAddGroup(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XAddGroup();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_INPUTGROUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnAddGroup();
	afx_msg void OnNMRClickTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDelete();
	afx_msg void OnChange();
	afx_msg void OnAddInGroup();

	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateAddGroup* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	void Init();

	void InitData();

	void SetGroupName(CString s);

	CString GetGroupName();

	void InitTreeImageList();

	

private:

	//���ؽ���
	void ReloadInterface();

	HTREEITEM AddRoot(CString szRoot);

	HTREEITEM AddChild(CString szChild);

	HTREEITEM AddChildChild(CString szChildChild);

	void SetItemRoot(HTREEITEM h);

	HTREEITEM GetItemRoot();

	void SetItemChild(HTREEITEM h);

	HTREEITEM GetItemCHild();

	void ShowMenu();


private:

	//ί��
	XDelegateAddGroup* m_pDelegate;

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

	//ѡ�з�������
	CString m_szGroupName;

	//������
	CTreeCtrl m_TreeGroup;

	CImageList m_TreeImageList;

	HTREEITEM m_ItemRoot;

	HTREEITEM m_ItemChild;

	CString m_szRoot;

	CString m_szNewGroupName;

	CString m_szRbGroupName;

	int m_nType;

	HTREEITEM m_RbItem;

};