#pragma once

#include "XConstantIM.h"

class XDelegateIniManage;

class XIniManage
{
public:
	XIniManage(void);
	~XIniManage(void);

public:

	//��ʼ��
	void Init();

	//����ί��
	void SetDelegate(XDelegateIniManage* p);

	//���¿ؼ�������ʾ
	void UpdateControlDataShow(XDATATYPE type, void* pControl);

	//�ؼ����ݸı�
	void ControlDataChange(XDATATYPE type, void* pControl);

public:

	//��ȡ�豸IP
	CString GetDeviceIP();

	//�����豸IP
	void SetDeviceIP(CString str);

	//��ȡ�豸�˿�
	int GetDevicePort();

	//�����豸�˿ں�
	void SetDevicePort(int n);

private:

	//��ȡIni����
	void GetIniData();

private:

	//�����豸IP��ʾ
	void UpdateControlDataShowOfDeviceIP(CMFCRibbonEdit* pCombox);

	//�豸IP�ı�
	void ControlDataChangeOfDeviceIP(CMFCRibbonEdit* pCombox);

	//�����豸�˿���ʾ
	void UpdateControlDataShowOfDevicePort(CMFCRibbonEdit* pCombox);

	//�豸�˿ڸı�
	void ControlDataChangeOfDevicePort(CMFCRibbonEdit* pCombox);
	
private:

	//�����豸IP
	void SaveDataOfDeviceIP(CString s);

	//�����豸�˿�
	void SaveDataOfDevicePort(int n);

private:

	XDelegateIniManage* m_pDelegate;

private:

	//���ű���
	int m_Scale;

	//�豸IP
	CString m_DeviceIP;

	//�豸�˿�
	int m_DevicePort;
};

