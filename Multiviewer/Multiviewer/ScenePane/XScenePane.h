#pragma once

#include "XConstantIM.h"
#include "XInputSignalPane.h"
#include "XSceneTree.h"
#include "XDelegateReName.h"

class XDelegateScenePane;

// XScenePane

class XScenePane : public CDockablePane,
	               public XDelegateReName
{
	DECLARE_DYNAMIC(XScenePane)
public:

	XScenePane();
	virtual ~XScenePane();

	virtual BOOL CanBeClosed() const{return FALSE;};

	virtual BOOL FloatPane(CRect rectFloat, AFX_DOCK_METHOD dockMethod = DM_UNKNOWN, bool bShow = true) { return FALSE; }

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnDblclkTreeVcard(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeleteScene();
	afx_msg void OnReSceneName();
	afx_msg void OnReMove();
	afx_msg void OnDeleteGroup();
	afx_msg void OnReNameGroup();

	afx_msg void OnCopyOrder();


	DECLARE_MESSAGE_MAP()

public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate(XDelegateScenePane* pDelegate);

	//��ȡί��
	XDelegateScenePane* GetDelegate();

	//���ؽ���
	void ReloadInterface();

	//��ȡ�������
	void SetInputSignalPane(XInputSignalPane* pPane);

	//��ӳ�������
	HTREEITEM AddSceneToTree(int nSceneIndex,CString szSceneName,int nType,CString szSceneGroup);

	void AddViewNameToScene(HTREEITEM item,CString szSceneName,int nIndex,CString szViewName);

	//��ӳ�������
	void AddSceneIntoGroup(HTREEITEM hItemDragS,HTREEITEM hItemDragD);

	//�жϳ����Ƿ�����
	BOOL JudgeSceneName(CString szName);

	//��ȡ��������
	MAP_SCENE& GetMapScene();

	//��ȡ������
	MAP_SCENEGROUP& GetMapSceneGroup();

private:

	void ClearMapItem();

	void ClearMapItemName();

	void ClearMapScene();

	void ClearSceneGroup();

public:

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault);

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType);

public:

	void GetData(CArchive& arch);

	void SaveData(CArchive& arch);

	void ResetData();

private:

	//����Pane
	void CreatePane();

	//��ʼ������
	void InitData();

	//��������
	void AdjustLayout();

	//��ʼ�����οؼ�
	BOOL InitTreeCtrl();

	//��ʼ��ͼƬ�б�
	BOOL InitImageList();

	//��Ӹ��ڵ�
	HTREEITEM AddRoot(CString szRoot,int nType);

	//���ýڵ�
	void SetItemRoot(HTREEITEM h);

	//��ȡ���ڵ�
	HTREEITEM GetItemRoot();

	//����ӽڵ�
	HTREEITEM AddChild(CString szChild);

	//�����ӽڵ�
	void SetItemChild(HTREEITEM h);

	//��ȡ�ӽڵ�
	HTREEITEM GetItemChild();

	//����ӽڵ�
	HTREEITEM AddChildChild(CString szChildChild);

	//�����ӽڵ�
	void SetItemChildChild(HTREEITEM h);

	//��ȡ�ӽڵ�
	HTREEITEM GetItemChildChild();

	//����ӽڵ�
	HTREEITEM AddChildChildChild(CString szChildChild);

	//��ʾ�����˵�
	void ShowMenu();

	//��ʾ�����˵�
	void ShowCopyMenu();

	//��ʾ������˵�
	void ShowGroupMenu();
	
	//���ݳ������ƻ�ȡ������Ϣ��
	XSceneInfo* GetSceenInfoBySceneName(CString szSceneName);

	//��ȡĬ��������
	CString GetGroupNameByFrontName(CString szName);

	//�ı䳡������̬
	void ChangeSceneTreeModel();

	//�жϳ����Ƿ�������
	BOOL JudgeSceneIsInGroup(CString szName);

	//�ж������Ƿ��г���
	BOOL JudgetGroupHaveScene(CString szGroupName);

private:

	//ί��
	XDelegateScenePane* m_pDelegate;

	//�������
	XInputSignalPane* m_pInputSignalPane;

	//ͼƬ�б�
	CImageList m_ImageList;

	//������
	XSceneTree m_SceneTree;

	//���ڵ�
	HTREEITEM m_RootItem;

	//�ӽڵ�
	HTREEITEM m_ChildItem;

	//�ӽڵ�
	HTREEITEM m_ChildChildItem;

	//�ӽڵ�
	HTREEITEM m_ChildChildChildItem;

	//�Ҽ����ڵ�
	HTREEITEM m_RbItem;

	//��������
	CString m_szSceneName;

	//��������
	MAP_SCENE m_MapScene;

	//���ڵ㼯��
	MAP_ITEM m_MapItem;

	//������(��Ҫ����)
	MAP_SCENEGROUP m_MapSceneGroup;

	//���ƺͽڵ㼯��
	MAP_ITEMNAME m_MapItemName;
};