#pragma once


class XVideoPreviewPane;

class XDataVideoPreviewPane
{
private:
	XDataVideoPreviewPane(void);
	~XDataVideoPreviewPane(void);

public:

	//��ȡ����
	static void GetData(XVideoPreviewPane* pPane, CArchive& arch);

	//��������
	static void SaveData(XVideoPreviewPane* pPane, CArchive& arch);

private:

	//��ȡ�汾1����
	static void GetDataOfVersion1(XVideoPreviewPane* pPane, CArchive& arch);
	//////////////////////////////////////////////////////////////////////////

	//��ȡ������Ϣ
	static void GetVecFrame(XVideoPreviewPane* pPane, CArchive& arch);

	//��ȡǰ���豸��Ϣ
	static void GetForntVecDeviceInfo(XVideoPreviewPane* pPane, CArchive& arch);

	//��ȡ�����豸��Ϣ
	static void GetBackVecDeviceInfo(XVideoPreviewPane* pPane, CArchive& arch);

	//��ȡԤ�������缯��
	static void GetMapBoardNetInfo(XVideoPreviewPane* pPane,CArchive& arch);

	//////////////////////////////////////////////////////////////////////////

	//���洰����Ϣ
	static void SaveVecFrame(XVideoPreviewPane* pPane, CArchive& arch);

	//����ǰ���豸��Ϣ
	static void SaveForntVecDeviceInfo(XVideoPreviewPane* pPane, CArchive& arch);

	//��������豸��Ϣ
	static void SaveBackVecDeviceInfo(XVideoPreviewPane* pPane, CArchive& arch);

	//����Ԥ�������缯��
	static void SaveMapBoardNetInfo(XVideoPreviewPane* pPane,CArchive& arch);

	//����Ԥ�����������
	//static void SaveBoardNetInfo(XBoardNetInfo* pInfo,CArchive& arch);
};

