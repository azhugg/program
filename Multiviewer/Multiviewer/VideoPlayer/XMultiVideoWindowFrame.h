#pragma once

#include "XConstantIM.h"

class XRTSP;
class XMultiVideoWindowFrames;

class XMultiVideoWindowFrame
{
public:
	XMultiVideoWindowFrame(void);
	~XMultiVideoWindowFrame(void);

public:

	void SetMultiVideoWindowFrames(XMultiVideoWindowFrames* p);

	CString GetRTSPAddr();

	void SetRTSPAddr(CString s);

	void SetRect(RECTF r);

	SDL_Rect GetRect();

	void SetRectImage(RECTF r);

	RECTF& GetRectImage();

	BOOL CreateTexture(SDL_Renderer* renderer, XRTSP* pRTSP);

	void ClearTexture();

	SDL_Texture* GetTexture();

	SDL_Rect GetRectImageReal();

	BOOL GetSetRectImageReal();

	void SetRectImageReal();

	void Show(BOOL bShow);

	BOOL GetShow();

	unsigned int GetFrameID();

	void SetFrameID(unsigned int nID);

	unsigned int GetFrameGroupID();

	void SetFrameGroupID(unsigned int nGroupID);

	int GetFrameIndex();
	
	void SetFrameIndex(int n);

	int GetFrameUltraIndex();

	void SetFrameUltraIndex(int n);

	CString GetFrameAnotherName();

	void SetFrameAnotherName(CString szName);

	void SetFrameIsUltra(BOOL b);

	BOOL GetFrameIsUltra();

	void SetLevel(int n);

	int GetLevel();



public:

	XMultiVideoWindowFrames* m_MultiVideoWindowFrames;

	//RTSP��ַ
	CString m_RTSPAddr;

	//��ʾ����
	SDL_Rect m_Rect;

	//��ʾͼ������,����1920*1088����
	RECTF m_RectImage;

	//�Ƿ񴴽�Texture
	BOOL m_CreateTexture;

	SDL_Texture* m_texture;

	int m_textureWidth;

	int m_textureHeight;

	//�Ƿ�������ʵͼ������
	BOOL m_SetRectImageReal;

	//��ʵͼ������
	SDL_Rect m_RectImageReal;

	//��ʾ״̬
	BOOL m_Show;

	//�Ƿ����
	BOOL m_Draw;

public://����

	void SetText(CString text);

	void SetText(COLORREF nTextColor, int nTextSize);

	BOOL GetCreateTextureText();

	void CreateTextureText();

	SDL_Texture* GetTextureText();

	int GetTextureTextWidth();

	int GetTextureTextHeight();

	void ClearTextureText();

public:

	inline void SetFrameSelected(BOOL b){m_bIsSelected=b;}

	inline BOOL GetFrameSelected(){return m_bIsSelected;}

private://����

	//����Texture
	SDL_Texture* m_textureText;

	//����
	CString m_szText;

	//������ɫ
	SDL_Color m_ColorText;

	//���ִ�С
	int m_nTextSize;

	//�Ƿ񴴽�����
	BOOL m_CreateTextureText;

	//���ֿ��
	int m_nTextureTextWidth;

	//���ָ߶�
	int m_nTextureTextHeight;

	//FrameID
	unsigned int m_nFrameID;

	//Frame GroupID
	unsigned int m_nFrameGroupID;

	int m_nIndex;

	int m_nUltraIndex;

	CString m_szAnotherName;

	int m_nLevel;

	BOOL m_bIsUltra;

	BOOL m_bIsSelected;


};


