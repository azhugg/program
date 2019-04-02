#pragma once

#include "XConstantIM.h"
#include "XDragInfo.h"

class XScreenManage;
class XScreen;
class XSignal;

class XDrawScreenManage
{
private:
	XDrawScreenManage(void);
	~XDrawScreenManage(void);

public:

	//��ͼ����
	static void ViewDraw(CDC* pDC,CRect rect, int noffsetX, 
		int noffsetY, XScreenManage* pManage);

private:

	//����
	static void Draw(Graphics& graphics, XScreenManage* pManage);

	//������Ļ����
	static void DrawVecScreen(Graphics& graphics, XScreenManage* pManage);

	//�����ź��ƶ�����
	static void DrawDragRect(Graphics& graphics, XScreenManage* pManage);

private:

	XDragInfo m_DragInfo;
};

