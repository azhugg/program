#pragma once

class XScenePane;

class XDataScenePane
{
private:
	XDataScenePane(void);
	~XDataScenePane(void);

public:

	//��ȡ����
	static void GetData(XScenePane* pPane, CArchive& arch);

	//��������
	static void SaveData(XScenePane* pPane, CArchive& arch);

	static void GetDataOfVersion1(XScenePane* pPane, CArchive& arch);

};
