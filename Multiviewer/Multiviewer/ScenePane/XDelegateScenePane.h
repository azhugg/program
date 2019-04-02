#pragma once

class XDelegateScenePane
{
public:
	XDelegateScenePane(void);
	~XDelegateScenePane(void);

	//��ȡCWnd
	virtual CWnd* GetCWND() = 0;

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	virtual void OpenScene(CString szSceneName,int nSceneIndex,CString szViewName)= 0;

	virtual void OpenAllScene(CString szSceneName,int nScreenIndex)=0;

	virtual void OpenOneSceneOfAll(CString szSceneName,int nSceneIndex,CString szViewName)=0;

	virtual void DeleteScene(int nSceneIndex)=0;

	virtual CString GetSceneFilePath(int nSceneIndex, CString szSceneName)=0;

	virtual BOOL IsLogin()=0;

	virtual int GetVecBaseManageSize()=0;

	virtual CString GetAllSceneFilePath(int nSceneIndex,CString szSceneName,int nIndex)=0;

	virtual void CopyOrderToShare(CString szSceneName,int nSceneIndex,CString szViewName)=0;

	virtual void CopySingleOrderToShare(CString szSceneName,int nSceneIndex,CString szViewName)=0;
};

