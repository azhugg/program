#pragma once

class XUserManage;

class XDataUserManage
{
private:
	XDataUserManage(void);
	~XDataUserManage(void);

public:

	//��ȡ����
	static void GetData(XUserManage* pManage, CArchive& arch);

	//��������
	static void SaveData(XUserManage* pManage, CArchive& arch);

public:

	static void SaveStringData(CArchive& arch, unsigned char* pKey, CString s);

	static void SaveIntData(CArchive& arch, unsigned char* pKey, int n);

	static CString GetStringData(CArchive& arch, unsigned char* pKey);

	static int GetIntData(CArchive& arch, unsigned char* pKey);

private:

	//��ȡ�汾1����
	static void GetDataOfVersion1(XUserManage* pManage, CArchive& arch);
};

