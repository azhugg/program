#pragma once

#include "../resource.h"
#include "..\XConstantIM.h"


class XDelegateBoardNet;
class XInternalManage;


class XBoardNet : public CDialogEx
{
	DECLARE_DYNAMIC(XBoardNet)

public:
	XBoardNet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XBoardNet();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_PANEIPOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBnClickedOk();
		afx_msg void OnBnClickedOk2();
		afx_msg void OnBnClickedRead();
		afx_msg void OnIpnFieldchangedIp(NMHDR *pNMHDR, LRESULT *pResult);
		afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateBoardNet* p);

	void SetInternalManage(XInternalManage* p);

	void InitData();

	void InitComboModel();

	void InitComboPassWd();

	void SetBoardIndex(int n);

	int GetBoardIndex();

	//�����û���
	void SetUseName(CString szName);
	CString GetUseName();

	//��������
	void SetPassWd(CString szPassWd);
	CString GetPassWd();

	//����IP��ַ
	void SetIP(CString szIP);
	CString GetIP();

	//��������
	void SetMask(CString szMask);
	CString GetMask();

	//��������
	void SetGateWay(CString szGateWay);
	CString GetGateWay();

	//����ģʽ
	void SetModel(int n);
	int GetModel();
	

	void SetSecret(int n);
	int GetSecret();

	//����MAC
	void SetMAC(CString szMAC);

	//���ð汾
	void SetVersion(CString szVer);

	void SpiltCString(CString szSrc,CString ch,VEC_CSTRING& VecStr);

	void ResetNet();

	void UpdateText();

	void ReRead();

	void SetDialog();

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateBoardNet* m_pDelegate;

	XInternalManage* m_pManage;

	CIPAddressCtrl m_IP;

	CIPAddressCtrl m_Mask;

	CIPAddressCtrl m_GateWay;

	CComboBox m_Combo_Model;

	CComboBox m_Combo_PassWd;

	CEdit m_Edit_Name;

	CEdit m_Edit_PassWd;

	CString m_szUseName;

	CString m_szPassWd;

	//IP��ַ
	CString m_szIP;

	//��������
	CString m_szMask;

	//����
	CString m_szGateWay;

	//MAC��ַ
	CString m_szMAC;

	//����
	CString m_Text;

	//�汾��Ϣ
	CString m_szVersion;

	//����
	int m_Index;

	int m_nReadIndex;

	//��ʼ��ȡʱ��
	DWORD m_dBeginTime;

	CString m_szReadIndex;

	int m_nModel;

	int m_nModelSel;

	CRect m_Rect;

	CRect m_ExpaneRect;

	long m_nSetTime;

	int m_nSecret;

	int m_nSecretSelect;

	int m_nBoardIndex;


};