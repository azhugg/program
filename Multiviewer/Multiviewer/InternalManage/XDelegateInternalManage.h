#pragma once

class XDelegateInternalManage
{
public:
	XDelegateInternalManage(void);
	~XDelegateInternalManage(void);

	//��ȡCWnd
	virtual CWnd* GetCWND() = 0;

	//��ȡ���ھ��
	virtual HWND GetHWND() = 0;

	//��ʾ��Ϣ�Ի���
	virtual int MessageBox(CString szText, CString szCaption, UINT uType) = 0;

	//������ͼ��С
	virtual void ResetViewSize() = 0;

	//ˢ����ͼ
	virtual void InvalidateView() = 0;

	//��ȡ��ͼ
	virtual CView* GetView() = 0;
};

