#pragma once

#include "XConstantIM.h"

class XMultiVideoWindow;

class XDelegateScreenManage
{
public:
	XDelegateScreenManage(void);
	~XDelegateScreenManage(void);

	//������ͼ��С
	virtual void ResetViewSize() = 0;

	//ˢ����ͼ
	virtual void InvalidateView() = 0;

	//�����������͸��¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type) = 0;

	//���¿ؼ�����
	virtual void ControlDataChange(XDATATYPE type)=0;

	//��ȡCWnd
	virtual CWnd* GetCWND() = 0;

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType) = 0;

	//��ȡ�����ļ�·��
	virtual CString GetSceneFilePath(int nSceneIndex, CString szSceneName) = 0;

	virtual CString GetAllSceneFilePath(int nSceneIndex, CString szSceneName,int nIndex) = 0;

	//��ȡ�����ļ���·��
	virtual CString GetSceneFolderPath() = 0;

	//���¿ؼ�UI
	virtual void UpdateControlUI(CMDUITYPE type, CCmdUI* pCmdUI) = 0;

	//��������
	virtual BOOL SendData(char* pData, int nDataLen) = 0;

	//����
	virtual void Operate(OPERATETYPE type, void* pData) = 0;

	//��ȡ��ͼ
	virtual CView* GetView() = 0;

	//��ȡ���ű���
	virtual float GetScale() = 0;

	//�������ű���
	virtual void SetScale(float f)=0;

	//��ȡ�豸IP
	virtual CString GetDeviceIP()=0;

	//�����豸IP
	virtual void SetDeviceIP(CString str)=0;

	//��ȡ�豸�˿�
	virtual int GetDevicePort()=0;

	//�����豸�˿ں�
	virtual void SetDevicePort(int n)=0;

	//��ȡ��������
	virtual CString GetLanguagetype()=0;

	//������������
	virtual void SetLanguagetype(CString type)=0;

	//��ȡ����״̬
	virtual BOOL GetNetState() = 0;

	//�Ƿ��¼
	virtual BOOL IsLogin() = 0;

	//��ȡ�û��ڵ�Ȩ��
	virtual BOOL GetUserNodePower(int nInputIndex, int nOutputIndex) = 0;

	//�Ƿ����Ա�û�
	virtual BOOL IsAdminUser() = 0;

	//��ȡ�������
	virtual int GetInputCount()=0;

	//���������źŸ���
	virtual void SetInputCount(int n)=0;

	//�����������ݣ��򿪳�����
	virtual void ReSetInputData()=0;

	//��ȡ�����źż���
	virtual VEC_INPUTSIGNAL& GetVecInputSignal()=0;

	//����OSD
	virtual void SetOSD(XInputSignal* pInputSignal)=0;
	
	//
	virtual void ResetDataBySceneInputCountChange()=0;

	//�ж������Ƿ�Ϊ4K
	virtual void JudgetInputIsultra(int nInputIndex)=0;

	//RTSP����+1
	virtual void SetRTSPAddrCountPlus(CString szRTSPAddr)=0;

	//RTSP����-1
	virtual void SetRTSPAddrCountLess(CString szRTSPAddr)=0;

	//����RTSP����
	virtual void SetRTSPAddrCountReset(CString szRTSPAddr)=0;

	//ֱ������RTSP����
	virtual void SetRTSPAddrCount(CString szRTSPAddr,int nCount)=0;

	//�ж��Ƿ����ź�
	virtual BOOL IsHaveSignal(int nIndex)=0;

	//�ж��Ƿ��а忨
	virtual BOOL IsHavePane(int nIndex)=0;

	//����Ԥ��ǽ��С
	virtual void AdjustMultiVideoWindowHWNDSize(XMultiVideoWindow* p,int nWidth,int nHight)=0;

	//��ӳ�������
	virtual HTREEITEM AddSceneToTree(int nSceneIndex,CString szSceneName,int nYtpe,CString szSceneGroup)=0;

	//�жϳ�������
	virtual BOOL JudgeSceneName(CString szName)=0;

	//��ȡ�����鼯��
	virtual MAP_SCENEGROUP& GetMapSceneGroup()=0;

	//�����������Ԥ������RTSP����Ϊ1
	virtual void SetFrameRTSPCountByIndex(int nInputIndex)=0;

	//���ҳ�����Ƶ�����ĳ���
	virtual void AddViewNameToScene(HTREEITEM item,CString szSceneName,int nIndex,CString szViewName)=0;

	virtual CString GetNotice()=0;

	virtual VEC_BASESCREENMANAGE& GetVecBaseScreenManage()=0;

	//����ѡ���ź���Ϣ
	virtual BOOL SetSelInputDataInfo()=0;

	virtual CString GetRTSPAddrFromPreviewPane(int nSignalIndex)=0;
};



