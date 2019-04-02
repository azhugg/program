#pragma once

class XBasePathManage
{
public:
	XBasePathManage(void);
	virtual ~XBasePathManage(void);

	//��ʼ��
	virtual void Init() = 0;

	//��ȡ�����ļ�·��
	virtual CString GetTranslationFilePath(CString szName) = 0;

	//��ȡ�����ļ�·��
	virtual CString GetDataFilePath(CString szName) = 0;

	//��ȡ�����ļ�·��
	virtual CString GetSceneFilePath(int nSceneIndex, CString szSceneName) = 0;

	virtual CString GetAllSceneFilePath(int nSceneIndex, CString szSceneName,int nIndex) = 0;

	//��ȡ�����ļ���·��
	virtual CString GetSceneFolderPath() = 0;

	//��ȡDUMP�ļ�·��
	virtual CString GetDumpFilePath() = 0;
};

