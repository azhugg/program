#pragma once

#include "../resource.h"
#include "XEquipmentInput.h"
#include "XEquipmentOutput.h"


class XDelegateSelectEquipment;
class XScreen;
class XScreenManage;

class XSelectEquipment : public CDialogEx
{
	DECLARE_DYNAMIC(XSelectEquipment)

public:
	XSelectEquipment(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~XSelectEquipment();

	virtual BOOL OnInitDialog();

	// �Ի�������
	enum { IDD = IDD_DLG_SELECTEQUIPMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void OnBtnOK();
	DECLARE_MESSAGE_MAP()

public:

	//����ί��
	void SetDelegate(XDelegateSelectEquipment* p);

	void SetScreenManage(XScreenManage* p);

	void SetScreen(XScreen* p);

	void InitComoboBox();

	int GetEquipment();

	void SetEquipment(int n);

	void SetIsMenuSet(BOOL b);

	void InitData();


private:

	//���ؽ���
	void ReloadInterface();

private:

	//ί��
	XDelegateSelectEquipment* m_pDelegate;

	XScreenManage* m_pScreenManage;

	XScreen* m_pScreen;

	CComboBox m_Combo_Equipment;

	int m_nEquipment;

	BOOL m_bIsMenuSet;
};