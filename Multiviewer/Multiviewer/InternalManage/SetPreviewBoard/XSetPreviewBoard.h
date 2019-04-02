#pragma once

#include "../resource.h"
#include "XPreviewChild.h"


class XDelegateSetPreviewBoard;
class XInternalManage;


class XSetPreviewBoard : public CDialogEx
{
	DECLARE_DYNAMIC(XSetPreviewBoard)

public:
	XSetPreviewBoard(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSetPreviewBoard();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_PREVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBnClickedOk();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateSetPreviewBoard* p);

	void SetBaseManage(XInternalManage* p);

	void InitData();

	void InitChildDlg();

	void OnSplitNetSet();

	void OnSplitBiteRate();

	void SetButtonStatus(BOOL b);

public:

	void OperateOfReadPreviewNet(char* pData);

	void OperateOfReadPreviewBitRate(char* pData);

private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateSetPreviewBoard* m_pDelegate;

	XInternalManage* m_pBaseManage;

	XPreviewChild m_PreviewDlg;
};
