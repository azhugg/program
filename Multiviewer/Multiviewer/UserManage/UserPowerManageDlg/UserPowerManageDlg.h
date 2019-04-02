#pragma once

#include "../resource.h"
#include "HYXText.h"
#include "HYXInputNode.h"
#include "HYXOutputNode.h"
#include "HYXGrid.h"
#include "HYXDelegateInputNode.h"
#include "HYXDelegateOutputNode.h"
#include "HYXDelegateGrid.h"

class XUserManage;
class XUserInfo;

#define NOTICETEXT_HEIGHT			40			//��ʾ���ָ߶�
#define INPUTNODERECT_HEIGHT		50			//����ڵ�߶�
#define OUTPUTNODERECT_WIDTH		120			//��������

// CUserPowerManageDlg �Ի���

class CUserPowerManageDlg : public CDialogEx, 
							public HYXDelegateInputNode, 
							public HYXDelegateOutputNode, 
							public HYXDelegateGrid
{
	DECLARE_DYNAMIC(CUserPowerManageDlg)

public:
	CUserPowerManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserPowerManageDlg();

	virtual BOOL OnInitDialog();

	virtual void OnOK();

// �Ի�������
	enum { IDD = IDD_DLG_USERPOWERMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	DECLARE_MESSAGE_MAP()

public:

	void SetUserManage(XUserManage* p);

	void SetUserInfo(XUserInfo* p);

private:

	//���ؽ���
	void ReloadInterface();

	//���öԻ�������
	void SetDlgRect();

	//��ʼ����ʾ����
	void InitNoticeText();

	//��ʼ������ڵ�
	void InitInputNodes();

	//��ʼ������ڵ�
	void InitOutputNodes();

	//��ʼ�����
	void InitGrid();

private:

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault);

	//��������
	virtual void AdjustGrid();

	//����ˮƽ����
	virtual void AdjustScrollH();

	//����ˮƽ����
	virtual void AdjustScrollV();

	//��ȡ�������
	virtual int GetScrollWidth();

	//��ȡ�����߶�
	virtual int GetScrollHeight();

	//ˮƽ����
	virtual void ScrollH(int nPos);

	//��ֱ����
	virtual void ScrollV(int nPos);

	//��ȡ����չ���豸���
	virtual void GetInputExpandDeviceItem(HYVEC_TREENODEITEM& VecItem);

	//��ȡ���չ���豸���
	virtual void GetOutputExpandDeviceItem(HYVEC_VTREENODEITEM& VecItem);

	//�����Ƶ������
	virtual void GridRectClick(HYXGridItem* pItem);

	//����Ҽ�����
	virtual void GridRButtonUp();

	//��ȡ�ڵ�Ȩ��
	virtual BOOL GetNodePower(int nInputIndex, int nOutputIndex);

private:

	XUserManage* m_UserManage;

	XUserInfo* m_UserInfo;

	HYXText m_NoticeInputNode;

	HYXText m_NoticeOutputNode;

	//����ڵ�
	HYXInputNode m_InputNode;

	//����ڵ�
	HYXOutputNode m_OutputNode;

	//���
	HYXGrid m_Grid;
};
