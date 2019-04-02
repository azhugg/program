#pragma once

#include "XExpandInfo.h"
#include "XSignalCutInfo.h"

class XInputSignal;

class XInputSignalExpand
{
public:
	XInputSignalExpand(void);
	~XInputSignalExpand(void);

	//���������ź�
	void SetInputSignal(XInputSignal* p);

	void SetExpand(XExpandInfo* pInfo);

	void SetName(CString s);

	//�������οؼ�������
	void SetTreeItem(HTREEITEM h);

	//�����Ƿ��ܱ༭
	void SetCanEdit(BOOL b);

	//����ID
	void SetID(int n);

	XExpandInfo* GetExpandInfo();

	XSignalCutInfo* GetSignalCutInfo();

	CString GetName();

	//��ȡ���οؼ�������
	HTREEITEM GetTreeItem();

	//��ȡ�����ź�
	XInputSignal* GetInputSignal();

	//��ȡ�Ƿ��ܱ༭
	BOOL GetCanEdit();

	//��ȡID
	int GetID();

private:

	//�����ź�
	XInputSignal* m_InputSignal;

	//���οؼ�������
	HTREEITEM m_TreeItem;

	XExpandInfo m_ExpandInfo;

	//����ü�
	XSignalCutInfo m_CutInfo;

	CString m_szName;

	//�Ƿ��ܱ༭
	BOOL m_CanEdit;

	//ID
	int m_ID;

};

