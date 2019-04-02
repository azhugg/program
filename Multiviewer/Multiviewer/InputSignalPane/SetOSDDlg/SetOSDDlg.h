#pragma once

#include "../resource.h"
#include "XDelegateOSDGrid.h"
#include "XOSDGrid.h"

class XDelegateSetOSDDlg;
class XInputSignal;
class XInputSignalPane;

// CSetOSDDlg �Ի���

class CSetOSDDlg : public CDialogEx, public XDelegateOSDGrid
{
	DECLARE_DYNAMIC(CSetOSDDlg)

public:
	CSetOSDDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetOSDDlg();

	virtual BOOL OnInitDialog();

// �Ի�������
	enum { IDD = IDD_DLG_SETOSD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnSet();
	afx_msg void OnBtnSend();
	afx_msg void OnEnChangeEditText();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateSetOSDDlg* p);

	//���������ź�
	void SetInputSignal(XInputSignal* p);

	//���������ź����
	void SetInputSignalPane(XInputSignalPane* p);

	//���������ź�����
	void SetInputSignalName(CString s);

public:

	void AddFont(CString s);

private:

	//���ؽ���
	void ReloadInterface();

	//��ʼ����ʾ����
	void InitShowData();

	//��ʼ������
	void InitComboBoxFont();

	//��ʼ����ʽ
	void InitComboBoxType();

	//����OSD����
	void CreateOSDGrid();

	//����OSD��ģ
	void SetOSDMutrix();

	//����λ��
	void AdjustPos();


private:

	//ί��
	XDelegateSetOSDDlg* m_pDelegate;

	//�����ź�
	XInputSignal* m_InputSignal;

	//�����ź����
	XInputSignalPane* m_InputSignalPane;

	//�����ź�����
	CString m_InputSignalName;

	CMFCColorButton m_Color;

	CMFCColorButton m_Color_Bk;

	CComboBox m_ComboBox_Font;

	CComboBox m_ComboBox_Type;

	CComboBox m_ComboBox_Center;

	XOSDGrid m_Grid;

	//�Ի�����С����
	CRect m_DlgMinRect;

	//�Ƿ��ʼ���Ի���
	BOOL m_InitDlg;

	
};
