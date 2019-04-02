
// Optical.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Optical.h"
#include "OpticalDlg.h"
#include "XHandlePath.h"
#include "XConstant.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpticalApp

BEGIN_MESSAGE_MAP(COpticalApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// COpticalApp ����

COpticalApp::COpticalApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	m_TokenGdi = NULL;
}

COpticalApp::~COpticalApp()
{
	if (NULL != m_TokenGdi)
	{
		GdiplusShutdown(m_TokenGdi);

		m_TokenGdi = NULL;
	}
}

// Ψһ��һ�� COpticalApp ����

COpticalApp theApp;


// COpticalApp ��ʼ��

BOOL COpticalApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		return FALSE;
	}

	//GDI+��ʼ��
	Gdiplus::GdiplusStartupInput input = 0;
	Gdiplus::Status state = Gdiplus::GdiplusStartup(&m_TokenGdi, &input, 0);
	if (Gdiplus::Ok != state)
	{
		return FALSE;
	}

	//·����ʼ��
	XHandlePath::Init();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(APP_REGISTRYKEY);

	COpticalDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

