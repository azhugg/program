#pragma once


class XScreenManage;
class XScreen;
class XSignal;

class XSceneDataManage
{
public:

	XSceneDataManage();
	~XSceneDataManage();

public:

	static BOOL SaveData(XScreenManage* p, CString szPath);

	static void SaveData(XScreenManage* p, CArchive& arch);

	//������Ļ��������
	static void SaveSceneOfVecScreen(XScreenManage* p, CArchive& arch);

	//������Ļ�źż���ID����
	static void SaveSceneOfVecSignalID(XScreenManage* p, CArchive& arch);

	//������Ļ����
	static void SaveSceneOfScreen(XScreen* p, CArchive& arch);

	//������Ļ�źż�������
	static void SaveSceneOfVecSignal(XScreen* p, CArchive& arch);

	//������Ļ�ź�����
	static void SaveSceneOfSignal(XSignal* p, CArchive& arch);

public:

	static BOOL GetData(XScreenManage* p, CString szPath);

	static void GetData(XScreenManage* p, CArchive& arch);

	static void GetVecScreen(XScreenManage* p,CArchive& arch);

	static void GetSceneOfScreen(XScreen* pScreen,CArchive& arch);

	static void GetSceneOfVecSignal(XScreen* pScreen,CArchive& arch);

	static void GetSignalOfScreen(XSignal* pSignal,CArchive& arch);
};