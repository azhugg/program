
// Optical.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COpticalApp:
// �йش����ʵ�֣������ Optical.cpp
//

class COpticalApp : public CWinApp
{
public:
	COpticalApp();
	~COpticalApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()

private:

	//GDI+����
	ULONG_PTR m_TokenGdi;
};

extern COpticalApp theApp;