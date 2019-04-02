#pragma once

#include "../resource.h"
#include "..\XConstantIM.h"

class XInputSignal;
class XInputSignalPane;


class XDelegatePaneIPAddr;


class XPaneIPAddr : public CDialogEx
{
	DECLARE_DYNAMIC(XPaneIPAddr)

public:
	XPaneIPAddr(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XPaneIPAddr();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DIALOG_PANEIP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		afx_msg void OnBnClickedOk();
		afx_msg void OnBtnRead();
		afx_msg void OnIpnFieldchangedIp(NMHDR *pNMHDR, LRESULT *pResult);
		afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegatePaneIPAddr* p);

	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	void InitData();

	void InitCombo();

	//���������ź�����
	void SetInputSignalName(CString s);

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


	//����MAC
	void SetMAC(CString szMAC);

	void SpiltCString(CString szSrc,CString ch,VEC_CSTRING& VecStr);

	void ResetNet();

	void UpdateText();

	void ReRead();

private:

	//���ؽ���
	void ReloadInterface();

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

private:

	//ί��
	XDelegatePaneIPAddr* m_pDelegate;

	CIPAddressCtrl m_IP;

	CIPAddressCtrl m_Mask;

	CIPAddressCtrl m_GateWay;

	//�����ź�����
	CString m_InputSignalName;

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

	//����
	int m_Index;

	int m_nReadIndex;

	//��ʼ��ȡʱ��
	DWORD m_dBeginTime;

	CString m_szReadIndex;

	CComboBox m_Combo_Model;

	int m_nModel;
};