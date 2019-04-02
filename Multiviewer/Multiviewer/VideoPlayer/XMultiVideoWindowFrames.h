#pragma once

#include "XConstantIM.h"
#include "VideoPlayerConstant.h"

class XMultiVideoWindow;
class XVideoPlayer;

class XMultiVideoWindowFrames
{
public:
	XMultiVideoWindowFrames(void);
	~XMultiVideoWindowFrames(void);

public:

	void SetMultiVideoWindow(XMultiVideoWindow* p);

	XVideoPlayer* GetVideoPlayer();

	SDL_Renderer* GetRenderer();


	//��Ļ���
	int GetScreenIndex();
	void SetScreenIndex(int n);

	//�忨���
	int GetBoardIndex();
	void SetBoardIndex(int n);

	//����
	RECTF GetScreenRect();
	void SetScreenRect(RECTF rect);

	//num Ofscreen
	int GetPaneNum();
	void SetPaneNum(int n);

	//�Ƿ���·
	BOOL GetIsTwoScreen();
	void SetIsTwoScreen(BOOL b);

	void SetFrameSelectByGroupID(unsigned int nGroupID);

	//��ȡFrame����
	VEC_MULTIVIDEOWINDOWFRAME& GetVecFrame();

	//���Frame
	XMultiVideoWindowFrame* AddFrame(CString szRTSPAddr, RECTF rFrame, RECTF rImage, 
		BOOL bShow);

	//��ȡFrame
	XMultiVideoWindowFrame* GetFrame(unsigned int nSignalID);

	//����Frame
	void SetFrame(XMultiVideoWindowFrame* pFrame, RECTF rFrame, RECTF rImage);

	//����Frame
	void SetFrame(XMultiVideoWindowFrame* pFrame, RECTF rFrame);

	//����Frame
	void SetFrame(XMultiVideoWindowFrame* pFrame, CString szRTSPAddr);

	//����Frame
	void SetFrameID(XMultiVideoWindowFrame* pFrame,unsigned int nFrameID);

	//����Frame
	void SetFrameGroupID(XMultiVideoWindowFrame* pFrame,unsigned int nFrameGroupID);

	//����Frame�Ƿ����
	void SetFrameIsUltra(XMultiVideoWindowFrame* pFrame,BOOL b);

	//����Frame����
	void SetFrameIndex(XMultiVideoWindowFrame* pFrame,int nFrameIndex);

	//���ø������
	void SetFrameUltraIndex(XMultiVideoWindowFrame* pFrame,int nUltraFrameIndex);

	//����Frame��ע
	void SetFrameAnotherName(XMultiVideoWindowFrame* pFrame,CString szAnotherName);

	//����Frame����
	void SetFrameText(XMultiVideoWindowFrame* pFrame, CString text);

	//����Frame����
	void SetFrameText(XMultiVideoWindowFrame* pFrame, COLORREF nTextColor, int nTextSize);

	//����Frames����
	void SetFramesText(CString szText,int nTextSize);

	//����Frame Image
	void SetFrameImage(XMultiVideoWindowFrame* pFrame, RECTF rImage);

	//ɾ��Frame
	void DeleteFrame(XMultiVideoWindowFrame* pFrame);

	//��ʾ������Frame
	void ShowFrame(XMultiVideoWindowFrame* pFrame, BOOL bShow);

	//��ʾ������Frame
	void ShowFrame(unsigned int nGroup, BOOL bShow);

	//����Frame�ö�
	void SetFrameTop(XMultiVideoWindowFrame* pFrame);
	void SetFrameTopByGroupID(unsigned int nGroupID);

	//����Frame�õ�
	void SetFrameBottom(XMultiVideoWindowFrame* pFrame);
	void SetFrameBottomByGroupID(unsigned int nGroupID);

	//����Frame����
	void SetFrameUp(XMultiVideoWindowFrame* pFrame);
	void SetFrameUpByGroupID(unsigned int nGroupID);

	//����Frame����
	void SetFrameDown(XMultiVideoWindowFrame* pFrame);
	void SetFrameDownByGroupID(unsigned int nGroupID);

	//����Frame���
	void SetFrameLevel(XMultiVideoWindowFrame* pFrame,int nLevel);

	//ɾ������Frame
	void DeleteAllFrame();

	//����Frame
	void SortFrame();

	void ClearVecFrame();

public:

	void CreateScreenText(float f=1.0f);

	void ClearScreenText();

	BOOL GetCreateTextureText();

public:

	void SetReDataLen(int n);

	void SetReScreenIndex(int n);

	void SetReStatus(int n);

	void SetReScreenHdpi(int n);

	void SetReScreenVdpi(int n);

	void SetReDpiIndex(int n);

	void SetReRefresh(int n);

	int GeteDataLen();

	int GetReScreenIndex();

	int GetReStatus();

	int GetReScreenHdpi();

	int GetReScreenVdpi();

	int GetReDpiIndex();

	int GetReRefresh();

public:

	XMultiVideoWindow* m_MultiVideoWindow;

	SDL_Texture* m_textureText;

	int m_nScreenIndex;

	int m_nBoardIndex;

	RECTF m_ScreenRect;

	int m_nPaneNum;

	BOOL m_bIsTwoScreen;

	VEC_MULTIVIDEOWINDOWFRAME m_VecFrame;

	int GetTextureTextWidth();

	int GetTextureTextHeight();

	SDL_Texture* GetTextureText();

private:

	CString m_szText;

	int m_nTextSize;

	SDL_Color m_ColorText;

	//���ֿ��
	int m_nTextureTextWidth;

	//���ָ߶�
	int m_nTextureTextHeight;

	//�Ƿ񴴽�����
	BOOL m_CreateTextureText;

private:
	//��������

	int m_nReScreenIndex;

	int m_ReDataLen;

	int m_ReStatus;

	int m_ReScreenHdpi;

	int m_ReScreenVdpi;

	int m_ReDpiIndex;

	int m_ReRefresh;

};