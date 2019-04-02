#pragma once

class HandlePath
{
private:
	HandlePath(void);
	~HandlePath(void);

public:

	//��ʼ��
	static void Init();

	//��ȡӦ�ó����ļ���·��
	static CString GetAppFolderPath();

	//�ж��ļ�·���Ƿ����
	static BOOL	PathExists(CString szPath);

	//��ȡ�����ļ�·��
	static CString GetTranslationFilePath(CString szName);

	//��ȡ�����ļ�·��
	static CString GetDataFilePath(CString szName);

	//��ȡ�����ļ���·��
	static CString GetSceneFolderPath();

	//��ȡDUMP�ļ���·��
	static CString GetDumpFolderPath();

	//��ȡIni·��
	static CString GetIniPath(CString name);

	//��ȡͼƬ·��
	static CString GetPhotoPath(CString szPhotoName);

	//��ȡ����·��
	static CString GetFontPath(CString szFont);

private:

	//Ӧ�ó����ļ���·�� 
	static CString m_szAppFolderPath;
};

