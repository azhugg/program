#pragma once

class XInputSignalPane;
class XInputSignal;

class XDataInputSignalPane
{
private:
	XDataInputSignalPane(void);
	~XDataInputSignalPane(void);

public:

	//��ȡ����
	static void GetData(XInputSignalPane* pPane, CArchive& arch);

	//��������
	static void SaveData(XInputSignalPane* pPane, CArchive& arch);

private:

	//��ȡ�汾1����
	static void GetDataOfVersion1(XInputSignalPane* pPane, CArchive& arch);

	static void SaveVecInputSignal(XInputSignalPane* pPane,CArchive& arch);

	static void SaveMapInputGroup(XInputSignalPane* pPane,CArchive& arch);

	static void GetVecInputSignal(XInputSignalPane* pPane,CArchive& arch);

	static void GetMapInputGroup(XInputSignalPane* pPane,CArchive& arch);

	static void SaveVecInput(XInputSignal* pInputSignal,CArchive& arch);

	static void GetVecInput(XInputSignal* pInputSignal,CArchive& arch);
};

