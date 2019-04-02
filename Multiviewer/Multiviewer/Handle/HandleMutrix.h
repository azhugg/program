#pragma once

class XOSDInfo;
class XScreenMoveInfo;

class HandleMutrix
{
private:
	HandleMutrix(void);
	~HandleMutrix(void);

public:

	//����OSD��ģ
	static BOOL SetOSDMutrix(CClientDC& dc, XOSDInfo* pOSDInfo, BOOL& bExceed);

	//���ù���������ģ
	static BOOL SetScreenMoveMutrix(CClientDC& dc, XScreenMoveInfo* pMoveInfo, BOOL& bExceed);

private:

	//����OSD����
	static BOOL CreateOSDFont(XOSDInfo* pOSDInfo, CFont& font);

	//��ȡ�ַ���ģ
	static BOOL GetTextMutrix(CClientDC& dc, GLYPHMETRICS& glyph, TCHAR c, 
		unsigned char*& pTextMutrix);

	//��ʾ�ַ���ģ����
	static void ShowTextMatrixData(TCHAR c, unsigned char* pTextMutrix, GLYPHMETRICS& glyph, 
		XOSDInfo* pOSDInfo);

	//����OSD������ģ����
	static int SetOSDTextMatrixData(XOSDInfo* pOSDInfo, int& nX, int& nY, 
		TCHAR c, TEXTMETRIC& tm, CClientDC& dc);

	//�����ģ���ݵ�OSD
	static int FillTextMatrixDataToOSD(XOSDInfo* pOSDInfo, int nX, int nY, 
		unsigned char* pTextMutrix, GLYPHMETRICS& glyph, TEXTMETRIC& tm);

	//***********************************
	//����������������
	static BOOL CreateScreenMoveFont(XScreenMoveInfo* pMoveInfo, CFont& font);

	//��ʾ���������ַ���ģ����
	static void ShowScreenMoveTextMatrixData(TCHAR c, unsigned char* pTextMutrix, GLYPHMETRICS& glyph, 
		XScreenMoveInfo* pMoveInfo);

	//���ù�������������ģ����
	static int SetScreenMoveTextMatrixData(XScreenMoveInfo* pMoveInfo, int& nX, int& nY, 
		TCHAR c, TEXTMETRIC& tm, CClientDC& dc);

	//�����ģ���ݵ���������
	static int FillTextMatrixDataToScreenMove(XScreenMoveInfo* pMoveInfo, int nX, int nY, 
		unsigned char* pTextMutrix, GLYPHMETRICS& glyph, TEXTMETRIC& tm);

	//��������
	static void CenterMutrixData(XOSDInfo* pOSDInfo,int& nMaxX,int& nMaxY);

	//��������
	static void CenterMoveMutrixData(XScreenMoveInfo* pMoveInfo,int& nMaxX,int& nMaxY);

};

