#pragma once

#include "XDelegateAddExpandDlg.h"
#include "XDelegateEditExpandDlg.h"
#include "XDelegateSetOSDDlg.h"
#include "XDelegateInputSignalCutDlg.h"
#include "XDelegateBorderOverlayDlg.h"
#include "XDelegateAttributeDlg.h"
#include "XInputSignalTreeCtrl.h"
#include "XDelegateEDIDDlg.h"
#include "XConstantIM.h"
#include "XDelegateSetAnotherNameDlg.h"
#include "XDelegateChangeChanelDlg.h"
#include "XDelegateUltraAttributeDlg.h"
#include "XDelegateStreamAddr.h"
#include "XDelegatePaneIPAddr.h"
#include "XStreamAddr.h"
#include "XPaneIPAddr.h"
#include "XDelegateAddGroup.h"


class XDelegateInputSignalPane;
class XDragInfo;


// XInputSignalPane

class XInputSignalPane : public CDockablePane, 
	public XDelegateAddExpandDlg,
	public XDelegateEditExpandDlg,
	public XDelegateSetOSDDlg,
	public XDelegateInputSignalCutDlg,
	public XDelegateBorderOverlayDlg,
	public XDelegateAttributeDlg,
	public XDelegateEDIDDlg,
	public XDelegateSetAnotherNameDlg,
	public XDelegateChangeChenalDlg,
	public XDelegateUltraAttributeDlg,
	public XDelegateStreamAddr,
	public XDelegatePaneIPAddr,
	public XDelegateAddGroup
{
	DECLARE_DYNAMIC(XInputSignalPane)
public:

	XInputSignalPane();
	virtual ~XInputSignalPane();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnNMRClickTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDelExpand();
	afx_msg void OnAddExpand();
	afx_msg void OnEditExpand();
	afx_msg void OnSetDefaultExpand();
	afx_msg void OnSetOSD();
	afx_msg void OnInputSignalCut();
	afx_msg void OnBorderOverlay();
	afx_msg void OnSetEDID();
	afx_msg void OnAttribute();
	afx_msg void OnSetAnotherName();
	afx_msg void OnChangeAnotherName();
	afx_msg void OnSelectChanel();
	afx_msg void OnIPStreamAddr();
	afx_msg void OnPaneIPSet();
	afx_msg void OnAddGroup();
	afx_msg void OnDelFromGroup();
	afx_msg void OnDeleteGroup();
	afx_msg void OnChangeGroup();

	DECLARE_MESSAGE_MAP()

public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate(XDelegateInputSignalPane* pDelegate);

	//��ȡί��
	XDelegateInputSignalPane* GetDelegate();

	//��������
	void ResetData();

	//���ؽ���
	void ReloadInterface();

	//��ȡ����
	void GetData(CArchive& arch);

	//��������
	void SaveData(CArchive& arch);

	//����
	void Operate(OPERATETYPE type, void* pData);

	//���¿ؼ�������ʾ
	void UpdateControlDataShow(XDATATYPE type, void* pControl);

	//�ؼ����ݸı�
	void ControlDataChange(XDATATYPE type, void* pControl);

	//�������ݣ�������
	void ResetDataOfScene();

	void ResetDataBySceneInputCountChange();

	//�����϶�����
	XDragWnd* CreateDragWnd(XDragInfo* pInfo);

	//�϶���Ϣ
	void DragInfo(CRect rc,CPoint point,XDragInfo* pInfo);

	//��������
	BOOL SendData(char* pData, int nDataLen);

	//��ȡ����״̬
	BOOL GetNetState();

	//��ȡ�������
	int GetInputCount();

	//�����������
	void SetInputCount(int n);
	
	//�ж��Ƿ����ź�
	BOOL IsHaveSignal(int nIndex);

	//�ж��Ƿ����豸
	BOOL IsHavePan(int nIndex);

	//�Ƿ�Ϊ4K
	void IsUltra(int nIndex);

	//�Ƿ�ΪIPԤ����
	BOOL IsIpPreview(int nIndex);

	//ˢ�������ź�ͼ��
	void RefreshInputIcon();

	//������Ż�ȡ��������
	CString GetInputNameByIndex(int nIndex);

	//������Ż�ȡInput
	XInputSignal* GetInputByIndex(int nIndex);

	//����Ԥ�����ڱ���
	void SetPreviewNameByAnotherName(int& nInputIndex,CString szAnotherName);

	//����Ԥ�����ڱ���
	void SetPreviewNameByAnotherName();

	void SetInputRTSPAddrByIndex(int nIndex,CString szRTSP);

	void SetInputParaByIndex(int nIndex,CString szIP,CString szUseName,CString szPassWd);

	void SetInputSignalPara();

	//�������Ƿ����
	BOOL IsNameHas(CString szName);

	//�ı�������״̬
	void ChangeInputModel();

	XInputSignal* GetInputSignalByIndex(int nIndex);

	int GetInputIndexByItemName(CString szItemText);

	//���������ź���ק
	void AddDragIntoGroup(const HTREEITEM& itemDragS,const HTREEITEM& itemDragD);

	void SetOSD(XInputSignal* pInputSignal);

	//����ѡ��������Ϣ
	BOOL SetSelInputDataInfo();

	//��ȡ��ק��Ϣ
	XDragInfo& GetDragInfo();

public:

	//��ȡ�����źż���
	VEC_INPUTSIGNAL& GetVecInputSignal();

	//��ȡ�鼯��
	MAP_GROUP& GetMapGroup();

private:

	//����Pane
	void CreatePane();

	//��ʼ�����οؼ�
	BOOL InitTreeCtrl();

	//��ʼ��ͼƬ�б�
	BOOL InitImageList();

	//��ʼ�������ź�
	void InitInputSignal();

	//��������
	void AdjustLayout();

	//���ؽ���-��
	void ReloadInterfaceOfTree();

	//�Ƿ������ź���
	BOOL IsInputSignalItem(HTREEITEM item);

	void ShowMenuOfInputSignal();

	void ShowMenuOfInputSignalExpand();

	void ShowMenuOfInputGroup();

	//���������źžֲ��Ŵ�ͼ��
	void AdjustInputSignalExpandImage(XInputSignal* pInputSignal);

	//�������������ʾ
	void UpdateControlDataShowOfInputCount(CMFCRibbonEdit* p);

	//��������ı�
	void ControlDataChangeOfInputCount(CMFCRibbonEdit* p);

	//���������ź�
	void ResetInputSignal();

	void CopyAnotherNameByVecInput(VEC_NAMEINFO& VecNameInfo);

	void CopyAnotherNameToVecInput(VEC_NAMEINFO& VecNameInfo);

	void OperateOfReadPaneIP(char* pData);

	void OperateOfReadStreamAddr(char* pData);

	BOOL CheckSumNum(char* pData,int nLen);

	unsigned short CheckNum(char *pData,int nLen);

	void SetAnotherName(XInputSignal* pInput,CString szAnotherName);

	void SetAnotherNameInOther(XInputSignal* pInput,CString szAnotherName);

	void ChangeInputAnotherNameInGroup(int nInputIndex,CString szAnotherName);

	void ChangeMultiVideoWindowsAnotherName(int nInputIndex,CString szAnotherName);

	void InsertInputSignal(XInputSignal* pInputSignal,HTREEITEM itemRoot=NULL);

	CString GetGroupNameByFrontName(CString szName);

	int GetInputTypeByReStatus(int nStatus);

private:

	//��������źż���
	void ClearVecInputSignal();

	//�����������
	void ClearNameInfo();

	//�����
	void ClearInputGroup();

	//���ͼƬ����
	void ClearImageList();

public:

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault);

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType);

private:

	//ί��
	XDelegateInputSignalPane* m_pDelegate;

	//���οؼ�
	XInputSignalTreeCtrl m_TreeCtrl;

	//ͼƬ�б�
	CImageList m_ImageList;

	//����Ҽ������ź�
	XInputSignal* m_RBInputSignal;

	//����Ҽ������źžֲ��Ŵ�
	XInputSignalExpand* m_RBInputSignalExpand;

	//�������
	int m_InputCount;

	//�Ҽ�ѡ�����ڵ�
	HTREEITEM m_RBItem;

private:

	//��Ƶ���Ի���
	XStreamAddr m_StreamAddrDlg;

	//�忨����Ի���
	XPaneIPAddr m_PaneIPAddrDlg;

private:

	//�����źż���
	VEC_INPUTSIGNAL m_VecInputSignal;

	//��������
	VEC_NAMEINFO m_VecNameInfo;

	//�鼯��
	MAP_GROUP m_MapGroup;
};


