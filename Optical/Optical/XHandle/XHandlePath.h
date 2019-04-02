#pragma once

class XHandlePath
{
private:
	XHandlePath(void);
	~XHandlePath(void);

public:

	//��ʼ��
	static void Init();

	//��ȡӦ�ó����ļ���·��
	static CString GetAppFolderPath();

	//�ж��ļ�·���Ƿ����
	static BOOL	PathExists(CString szPath);

	//��ȡͼƬ·��
	static CString GetPhotoPath(CString szPhotoName);

	//��ȡIni·��
	static CString GetIniPath(CString name);

	//��ȡ�����ļ�·��
	static CString GetTranslationFilePath(CString name);

	//��ȡDump�ļ���·��
	static CString GetDumpFolderPath();

private:

	//Ӧ�ó����ļ���·�� 
	static CString m_szAppFolderPath;
};

