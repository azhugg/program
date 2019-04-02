#pragma once

class HandleCalculate
{
private:
	HandleCalculate(void);
	~HandleCalculate(void);

public:

	//������ͼԭ��
	static void SetViewPortOrg(CRect& rect, int& noffsetX, int& noffsetY, 
		CSize& size, float& dwScale, const int& nDrawDistanceX, const int& nDrawDistanceY, CDC& dc);

	static void SetPreviewOrg(CRect& rect, int& noffsetX, int& noffsetY, 
		CSize& size, float& dwScale, const int& nDrawDistanceX, const int& nDrawDistanceY,CSize& orgSize);


	//��ȡ��ͼ����ԭ��
	static void GetViewPortOrg(CRect& rect, int& noffsetX, int& noffsetY,
		CSize& size, float& dwScale, const int& nDrawDistanceX, const int& nDrawDistanceY, int& nOrgX, int& nOrgY);

	//�ж�IP�Ƿ���ȷ
	static BOOL DecideIP(CString szIP);

	//�ж�RTSP��ַ�Ƿ���ȷ
	static BOOL DecideRTSPAddr(CString szRTSPAddr);

	static CString GetIPByRTSPAddr(CString szRTSPAddr);
};

