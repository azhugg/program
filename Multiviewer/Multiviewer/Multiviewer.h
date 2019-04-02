// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// Multiviewer.h : Multiviewer Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMultiviewerApp:
// �йش����ʵ�֣������ Multiviewer.cpp
//

class CMDITabOptions
{
public:
	CMDITabOptions();

	enum MDITabsType
	{
		None,
		MDITabsStandard,
		MDITabbedGroups
	};


	MDITabsType			m_nMDITabsType;
	BOOL				m_bTabsOnTop;
	BOOL				m_bActiveTabCloseButton;
	CMFCTabCtrl::Style	m_nTabsStyle;
	BOOL				m_bTabsAutoColor;
	BOOL				m_bMDITabsIcons;
	BOOL				m_bMDITabsDocMenu;
	BOOL				m_bDragMDITabs;
	BOOL				m_bMDITabsContextMenu;
	int					m_nMDITabsBorderSize;
	BOOL				m_bDisableMDIChildRedraw;
	BOOL				m_bFlatFrame;
	BOOL				m_bCustomTooltips;

	void Load ();
	void Save ();

	BOOL IsMDITabsDisabled () const {return m_nMDITabsType == CMDITabOptions::None;}
};


class CMultiviewerApp : public CWinAppEx
{
public:
	CMultiviewerApp();
	~CMultiviewerApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	CMDITabOptions	m_Options;

// ʵ��
	UINT  m_nAppLook;
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	

	DECLARE_MESSAGE_MAP()

private:

	ULONG_PTR m_TokenGdi;
};

extern CMultiviewerApp theApp;
