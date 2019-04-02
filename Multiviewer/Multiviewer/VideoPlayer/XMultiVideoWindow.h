#pragma once

#include "XConstantIM.h"
#include "videoinc.h"
#include "VideoPlayerConstant.h"

class XMultiVideoWindowFrames;
class XVideoPlayer;
class XMultiVideoWindowFrame;
class XBaseScreenManage;
class XScreenManage;
class XScreenDataInfo;

class XMultiVideoWindow
{
public:
	XMultiVideoWindow(void);
	~XMultiVideoWindow(void);

public:

	void SetVideoPlayer(XVideoPlayer* p);

	XVideoPlayer* GetVideoPlayer();

	BOOL CreateSDLWindow();

	BOOL CreateSDLRenderer();

	BOOL GetCreateSDLWindow();

	//��ȡ�Ƿ񴴽�SDLRenderer
	BOOL GetCreateSDLRenderer();

	HWND GetHWND();

	void SetHWND(HWND h);

	void InitFont();

	//���ñ߿�
	void SetFrame(int nRow, int nColumn);

	//����
	void Draw();

	//////////////////////////////////////////////////////////////////////////
	void SetMultiScale(float f);

	void SetFramesCountH(int n);

	void SetFramesCountV(int n);

	void SetFramesResulationH(int n);

	void SetFramesResulationV(int n);

	void SetFramesRightResulationH(int n);

	void SetFramesBottomResulationV(int n);

	void SetFrameSelectByGroupID(unsigned int nGroupID);
	//////////////////////////////////////////////////////////////////////////
	//���ڻ�ȡ��ͼ�����С�����Ϻ�����ʱ���ã�
	void SetMapRowInfo(MAP_ROWINFO& MapRowInfo);
	void SetMapColInfo(MAP_COLINFO& MapColInfo);
	//////////////////////////////////////////////////////////////////////////
	//���Frame
	XMultiVideoWindowFrame* AddFrame(int nScreenIndex, CString szRTSPAddr, RECTF rFrame, 
		RECTF rImage, BOOL bShow = TRUE);

	//���Frames
	XMultiVideoWindowFrames* AddFrames(int nScreenIndex,int nBoardIndex,RECTF rScreenRect,int nPaneNum,BOOL bIsTwoScreen);

	//��ȡ�ź�
	XMultiVideoWindowFrame* GetFrame(int nScreenIndex,unsigned int nSignalID);

	//����Frame
	void SetFrame(int nScreenIndex, XMultiVideoWindowFrame* pFrame, RECTF rFrame, RECTF rImage);

	//����Frame
	void SetFrame(int nScreenIndex, XMultiVideoWindowFrame* pFrame, RECTF rFrame);

	//����Frame
	void SetFrame(int nScreenIndex, XMultiVideoWindowFrame* pFrame, CString szRTSPAddr);

	//����Frame
	void SetFrameID(int nScreenIndex,XMultiVideoWindowFrame* pFrame,unsigned int nFrameID);

	//����Frame
	void SetFrameGroupID(int nScreenIndex,XMultiVideoWindowFrame* pFrame,unsigned int nFrameGroupID);

	//����frame�Ƿ�Ϊ����
	void SetFrameIsUltra(int nScreenIndex,XMultiVideoWindowFrame* pFrame,BOOL b);

	//����Frame����
	void SetFrameIndex(int nScreenIndex,XMultiVideoWindowFrame* pFrame,int nIndex);

	//���ø������
	void SetFrameUltraIndex(int nScreenIndex,XMultiVideoWindowFrame* pFrame,int nUltraIndex);

	//����Frame��ע
	void SetFrameAnotherName(int nScreenIndex,XMultiVideoWindowFrame* pFrame,CString szAnotherName);

	//����Frame Image
	void SetFrameImage(int nScreenIndex, XMultiVideoWindowFrame* pFrame, RECTF rImage);

	//����Frame����
	void SetFrameText(int nScreenIndex, XMultiVideoWindowFrame* pFrame, CString text);

	//����Frame����
	void SetFrameText(int nScreenIndex, XMultiVideoWindowFrame* pFrame, COLORREF nTextColor, int nTextSize);

	//����Frames����
	void SetFramesText(int nScreenIndex,CString szText,int ntextSize);

	//ɾ��Frame
	void DeleteFrame(int nScreenIndex, XMultiVideoWindowFrame* pFrame);

	//ɾ����ĻFrame
	void DeleteFrame(int nScreenIndex);

	//��ʾ������Frame
	void ShowFrame(int nScreenIndex, XMultiVideoWindowFrame* pFrame, BOOL bShow);

	//��ʾ������Frame
	void ShowFrame(int nScreenIndex, unsigned int nGroupID, BOOL bShow);

	//����Frame�ö�
	void SetFrameTop(int nScreenIndex, XMultiVideoWindowFrame* pFrame);

	//����Frame�ö�
	void SetFrameTopByGroupID(int nScreenIndex,unsigned int nGroupID);

	//����Frame�õ�
	void SetFrameBottom(int nScreenIndex,XMultiVideoWindowFrame* pFrame);

	//����Frame�õ�
	void SetFrameBottomByGroupID(int nScreenIndex,unsigned int nGroupID);

	//����Frame����
	void SetFrameUp(int nScreenIndex, XMultiVideoWindowFrame* pFrame);

	//����Frame����
	void SetFrameUpByGroupID(int nScreenIndex, unsigned int nGroupID);

	//����Frame����
	void SetFrameDown(int nScreenIndex, XMultiVideoWindowFrame* pFrame);

	//����Frame����
	void SetFrameDownByGroupID(int nScreenIndex, unsigned int nGroupID);

	//����Frame���
	void SetFrameLevel(int nScreenIndex,XMultiVideoWindowFrame* pFrame,int nLevel);

	//������Ļ����
	void SetScreenModel(int n);

	//ɾ������Frames
	//void DeleteAllFrames();

	//ɾ������Frame
	void DeleteAllFrame();

	//����Frames�������
	void SetFramesReIndex(int nScreenIndex,int nIndex);

	//����Frames�������ݳ���
	void SetFramesReDateLen(int nScreenIndex,int nDataLen);

	//����frames����״̬
	void SetFramesReStatus(int nScreenIndex,int nStatus);

	//����Frames���طֱ���
	void SetFramesReResulationH(int nScreenIndex,int nResulationH);

	//����Frames���طֱ���
	void SetFramesReResulationV(int nScreenIndex,int nResulationV);

	//����Frames���طֱ������
	void SetFramesReResulationIndex(int nScreenIndex,int nIndex);

	//����Frames����ˢ����
	void SetFramesReRefreash(int nScreenIndex,int nRefreash);

	//ð������Frame
	void SortFrame(int nScreenIndex);

	//���ñ���ͼƬ
	void SetBGImage(CString szPath);

	//���ñ�����ɫ
	void SetBGColor(Uint8 r, Uint8 g, Uint8 b);

	//���÷ָ�����ɫ
	void SetLineColor(Uint8 r, Uint8 g, Uint8 b);

	//ɾ������ͼƬ
	void DeleteBGImage();

	//����������Ƶ��ʾ
	void SetResetVideoShow(BOOL b);

	//��ȡ������Ƶ��ʾ
	BOOL GetResetVideoShow();

	void ResetVideoShow();

	SDL_Renderer* GetRenderer();

	void SetMushHardCode(BOOL b);

	//��ȡFrames����
	MAP_MULTIVIDEOWINDOWFRAMES& GetMapFrames();

	void ClearVecFrames();

	BOOL IsHaveDevice(int nIndex);

	CSize ViewGetSize();

	void SetIsMainMultiVideo(BOOL b);

	SDL_Rect GetInterRectByGroupID(unsigned int nGroupID);

	CString GetAnotherNameByIndex(int nIndex);

	CString GetShowText(CString szName,int nIndex);

	void SetIsDragFrame(BOOL b);

	void ChangeMultiVideoWindowsAnotherName(int nInputIndex,CString szAnotherName);

	void GetVecIndexByFrameGroupID(unsigned int nFrameGroupID,VEC_NUM& VecIndex);

	//�����Ļ������Ϣ
	void ClearRowInfo();

	void ClearColInfo();


private:

	
	//�������
	void ClearData();

	//���Ʊ�����ɫ
	void DrawBGColor();

	void DrawFrames();

	void DrawFrame();

	void DrawRect(RECTF& rect);

	void DrawFrame(XMultiVideoWindowFrames* pFrames);

	//��ȡԤ����Ļ
	XMultiVideoWindowFrames* GetFrames(int nScreenIndex);

	void DrawBGImage();

	SDL_Texture* GetImageTexture(SDL_Renderer *pRenderer, char *szFile);

	void ClearTextureBGImage();

	void ClearRenderer();

	void ClearMapFramesTexture();

	void ReloadBGImage();

	void SetFrameDraw(XMultiVideoWindowFrames* pFrames);

	BOOL DecideRectInVecRect(VEC_RECT& VecRect, CRect& rect);

	void CreateTextureText();

	void ClearTextureText();

	void SetText(CString text);

	BOOL GetCreateTextureText();

	SDL_Texture* GetTextureText();

public:

	XVideoPlayer* m_VideoPlayer;

	//XBaseScreenManage* m_pManage;

	//���
	HWND m_HWND;

	//�Ƿ񴴽�Window
	BOOL m_CreateWindow;

	SDL_Window* m_window;

	SDL_Renderer* m_renderer;

	//�Ƿ񴴽�renderer
	BOOL m_CreateRender;

	int m_Row;

	int m_Column;

	CRITICAL_SECTION m_CS;

	CRITICAL_SECTION m_CSBGImage;

	SDL_Texture* m_textureBGImage;

	SDL_Texture* m_textureText;

	CString m_szBGImagePath;

	MAP_MULTIVIDEOWINDOWFRAMES m_MapFrames;

	BOOL m_bResetVideoShow;

	//������ɫ
	SDL_Color m_ColorBG;

	//�ָ�����ɫ
	SDL_Color m_ColorLine;

	//������ɫ
	SDL_Color m_TextColor;

	//�Ƿ����Ӳ��
	BOOL m_MushHardCode;

	//������
	int m_nTextureTextWidth;

	//����߶�
	int m_nTextureTextHeight;

	//��Ļ��Ϣ����
	VEC_SCREENDATAINFO m_VecScreenInfo;

	//ԭ��ƫ��
	int m_nOrgX;

	int m_nOrgY;

	//��Ļ����
	int m_nScreenModel;

	float m_dwScale;

	//ˮƽ����
	int m_nFramesCountH;

	//��ֱ����
	int m_nFramesCountV;

	//ˮƽ�ֱ���
	int m_nFramesResolutionH;

	//��ֱ�ֱ���
	int m_nFramesResolutionV;

	int m_nRightResulationH;

	int m_nBottomResulationV;

	BOOL m_bIsMainMultiVideo;

private:

	//������ɫ
	SDL_Color m_ColorText;

	//����
	CString m_szText;

	//���ִ�С
	int m_nTextSize;

	//�Ƿ񴴽�����
	BOOL m_CreateTextureText;

	BOOL m_DrawText;

	BOOL m_bIsDragFrame;

	SDL_Rect m_TempRectImage;

	MAP_FRAMEID m_MapFrameID;
	
	MAP_FRAMECOLINFO m_MapColInfo;

	MAP_FRAMEROWINFO m_MapRowInfo;

};