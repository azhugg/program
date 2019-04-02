#pragma once

#include "XBasePathManage.h"

class XPathManage : public XBasePathManage
{
public:
	XPathManage(void);
	~XPathManage(void);

	//��ʼ��
	virtual void Init();

	//��ȡ�����ļ�·��
	CString GetTranslationFilePath(CString szName);

	//��ȡ�����ļ�·��
	CString GetDataFilePath(CString szName);

	//��ȡ�����ļ�·��
	CString GetSceneFilePath(int nSceneIndex, CString szSceneName);

	CString GetAllSceneFilePath(int nSceneIndex, CString szSceneName,int nIndex);

	//��ȡ�����ļ���·��
	CString GetSceneFolderPath();

	//��ȡDUMP�ļ�·��
	CString GetDumpFilePath();

private:

	//��ȡӦ�ó����ļ���·��
	CString GetAppFolderPath();

private:

	//Ӧ�ó����ļ���·�� 
	CString m_szAppFolderPath;
};

