#pragma once

class XScreenManage;
class XScreen;
class XSignal;
class XScreenDataInfo;

class XDataScreenManage
{
private:
	XDataScreenManage(void);
	~XDataScreenManage(void);

public:

	//��ȡ����
	static BOOL GetData(XScreenManage* p, CString szPath);

	//��ȡ����
	static void GetData(XScreenManage* p, CArchive& arch);

	//��ȡ�汾1����
	static void GetDataOfVersion1(XScreenManage* p, CArchive& arch);

	//��ȡ��Ļ��������
	static void GetDataOfVecScreen(XScreenManage* p, CArchive& arch);

	//��ȡ��Ļ����
	static void GetDataOfScreen(XScreen* p, CArchive& arch);

	static void GetDataOfRowColInfo(XScreenManage* p, CString szPath);
public:

	//��������
	static void SaveData(XScreenManage* p, CArchive& arch);

	//��������
	static BOOL SaveData(XScreenManage* p, CString szPath);

	//������Ļ����
	static void SaveDataOfScreen(XScreen* p, CArchive& arch);

	static void SaveDataOfRowColInfo(XScreenManage* p, CString szPath);

};



