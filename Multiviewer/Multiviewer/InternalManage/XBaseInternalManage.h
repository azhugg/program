#pragma once

#include "XConstantIM.h"

class XDelegateInternalManage;


class XBaseInternalManage
{
public:
	XBaseInternalManage(void);
	virtual ~XBaseInternalManage(void);

public:

	//��ʼ��
	virtual void Init() = 0;

	//����ر�
	virtual BOOL AppClose() = 0;

	//�����������͸��¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type) = 0;

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type) = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;

	//���¿ؼ�UI
	virtual void UpdateControlUI(CMDUITYPE type, CCmdUI* pCmdUI) = 0;

	//��ͼ����
	virtual void ViewDraw(CDC* pDC, CRect rect, int noffsetX, 
		int noffsetY) = 0;

	//��ͼ��ȡ��С
	virtual CSize ViewGetSize() = 0;

	//��ͼ�������
	virtual void ViewLButtonDown(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY) = 0;

	//��ͼ�������
	virtual void ViewLButtonUp(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY) = 0;

	//��ͼ����ƶ�
	virtual void ViewMouseMove(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY) = 0;

	//��ͼ����뿪
	virtual void ViewMouseLeave() = 0;

	//��ͼ��������
	virtual void ViewKeyUp(UINT nChar) = 0;

	//��ͼ�Ҽ�����
	virtual void ViewRButtonUp(CWnd* pWnd, UINT& nFlags, CPoint& point, 
		CRect& rect, int noffsetX, int noffsetY) = 0;

	virtual void ViewLBDClick(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY)=0;

	//����UDP��Ϣ
	virtual void HandleUDPMsg(WPARAM wParam, LPARAM lParam) = 0;

	//��ʼ��Pane
	virtual void InitPane() = 0;

	virtual void AddDocument() = 0; 

	virtual void SetIsFirstTime(BOOL IsFirstTime)=0;

	virtual BOOL GetIsFirstTime()=0;

	virtual void ShowMenu(CPoint& point)=0;

	virtual void SetActiveDockPane()=0;

	virtual void CloseActivePane()=0;

	virtual BOOL SetTabCtrlDbCLick(POINT point)=0;

	virtual BOOL SetViewTabBarDbClick(POINT point)=0;

	virtual void SetTabCtrlCLick(POINT point)=0;


public:

	//����ί��
	void SetDelegate(XDelegateInternalManage* p);

protected:

	//ί��
	XDelegateInternalManage* m_pDelegate;
};

