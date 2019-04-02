#pragma once

#include "../resource.h"
#include "XListCtrl.h"
#include "XConstantIM.h"

class XUserManage;

// CUserManageDlg �Ի���

class CUserManageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUserManageDlg)

public:
	CUserManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserManageDlg();

	virtual BOOL OnInitDialog();

	virtual void OnOK();

// �Ի�������
	enum { IDD = IDD_DLG_USERMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnClickedAdd();
	afx_msg void OnBtnClickedEdit();
	afx_msg void OnBtnClickedDel();
	afx_msg void OnBtnClickedSave();
	afx_msg void OnBtnClickedCancel();
	afx_msg void OnBtnClickedCopy();
	afx_msg void OnNMDblclkListCtrlUser(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEditNoticeChange();
	DECLARE_MESSAGE_MAP()

public:

	void SetUserManage(XUserManage* p);

private:

	//���ؽ���
	void ReloadInterface();

	//�����б����
	void ReloadListInterface();

	//��ʼ���б�
	void InitList();

	//��ʼ���б�����
	void InitListData();

	void InitNotice();

	//�����Ϣ
	int AddInfo(CString szAccount);

	//������Ϣ
	void SetInfo(int n, CString szAccount);

	//��ʾ�������ͽ���
	void ShowOperateInterface(char type);

	//�������
	void SaveAdd();

	//����༭
	void SaveEdit();

	void SaveCopy();

	//��ȡѡ���Ȩ������
	POWERTYPE GetSelectPower();

	//ѡ��Ȩ������
	void SelectPower(POWERTYPE type);

	//����Ȩ��
	void SetPower();

private:

	XUserManage* m_UserManage;

	XListCtrl m_ListCtrl_User;

	//�ʺ�
	CEdit m_Edit_Account;

	//����
	CEdit m_Edit_PSW;

	//��������
	char m_OperateType;

	//�༭���û���Ϣ
	XUserInfo* m_EditUserInfo;

	XUserInfo* m_CopyUserInfo;

	//�༭������
	int m_EditListItem;
};
