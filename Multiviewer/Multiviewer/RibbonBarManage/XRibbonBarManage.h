#pragma once

#include "XBaseRibbonBarManage.h"
#include "XRibbonBar.h"
#include "XDelegateRibbonBar.h"

class XRibbonBarManage : public XBaseRibbonBarManage, XDelegateRibbonBar
{
public:
	XRibbonBarManage(void);
	~XRibbonBarManage(void);

	//��ʼ��
	virtual void Init();

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type);

	//���ؽ���
	virtual void ReloadInterface();

	//�����������͸��¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type);

	//Ribbon��ʾ�����
	virtual void RibbonBarShowCategory(CString szName);

	//����
	void Operate(OPERATETYPE type, void* pData);

private:

	//��ʼ��RibbonBar
	void InitRibbonBar();

	//��ʼ��״̬��
	void InitStatusBar();

	//��ʼ��RibbonBar
	void InitRibbonBar(CMFCRibbonBar* pRibbonBar);

	BOOL InitImageList();

	//��ȡCWnd
	CWnd* GetCWND();

	//��ȡ�ַ���
	CString GetTranslationString(CString szKey, CString szDefault);

	//�������пؼ�������ʾ
	void UpdateControlDataShowOfAll();

	//�����¶���Ϣ
	void SetTemperatureInfo(CString s);

	void SetPanInfo(CString s);

	void SetChipInfo(CString s);


private://������ҳ�� 

	XRibbonBar m_wndRibbonBar;

	//��ҳ
	CMFCRibbonCategory* m_pCategoryMain;

private:

	CMFCRibbonStatusBar m_wndStatusBar;

private:

	//�ر�
	CMFCRibbonButton* m_pBtnAbout;

private:

	//������
	CMFCRibbonPanel* m_pPanelMainSet;

	//�½���ͼ
	CMFCRibbonButton* m_pBtnNewView;

	//�ر���ͼ
	CMFCRibbonButton* m_pBtnCloseView;

	//�л���ͼ
	//CMFCRibbonComboBox* m_pComboBoxView;

	//��������
	CMFCRibbonComboBox* m_pComboBoxLanguage;

	//����
	CMFCRibbonComboBox* m_pComboBoxScale;

private:

	//����
	CMFCRibbonPanel* m_pPanelMainScene;

	//���泡��
	CMFCRibbonButton* m_pBtnSaveScence;

	//�򿪳���
	CMFCRibbonButton* m_pBtnOpenScence;

	//ɾ������
	CMFCRibbonButton* m_pBtnDeleteScence;

private:

	//����
	CMFCRibbonPanel* m_pPanelMainOperator;

	//ɾ�������ź�
	CMFCRibbonButton* m_pBtnDeleteAllSignal;

	//���ö�ʱ��ѯ
	CMFCRibbonButton* m_pBtnTimedPolling;

	//��Ļ����
	CMFCRibbonButton* m_pBtnScreenMove;

	//��������ֱ���
	CMFCRibbonButton* m_pBtnScreenResulation;

	//��ָ��
	CMFCRibbonButton* m_pBtnOldOrder;

private:

	//����
	CMFCRibbonPanel* m_pPanelScene;

	//��ҳ�泡��
	CMFCRibbonButton* m_pBtnInterScene;

	//��ҳ�泡��
	CMFCRibbonButton* m_pSingleScene;

private:

	//Ԥ��
	CMFCRibbonPanel* m_pPanelMainPreview;

	CMFCRibbonButton* m_pBtnPreview;

private:
	
	//�������
	CMFCRibbonPanel* m_pPanelMainNet;

	//������
	CMFCRibbonButton* m_pBtnOpenNet;

	//�ر�����
	CMFCRibbonButton* m_pBtnCloseNet;
	
private:

	//�豸���
	CMFCRibbonPanel* m_pPanelMainDevice;

	//�豸IP
	CMFCRibbonEdit* m_pEditDeviceIP;

	//�豸�˿�
	CMFCRibbonEdit* m_pEditDevicePort;

private:

	//�¶����
	CMFCRibbonPanel* m_pPanelMainTemperature;

	//�¶�ͼ��
	CMFCRibbonButton* m_pBtnTemperature;

private:

	//�������
	CMFCRibbonPanel* m_pPanelMainMultiviewer;

	//�������
	CMFCRibbonEdit* m_pEditInputCount;

	//ˮƽ�������
	CMFCRibbonEdit* m_pEditOutputCountH;

	//��ֱ�������
	CMFCRibbonEdit* m_pEditOutputCountV;

private:

	//�û����
	CMFCRibbonPanel* m_pPanelMainUser;

	//��½
	CMFCRibbonButton* m_pBtnLogin;

	//ע��
	CMFCRibbonButton* m_pBtnLogout;

	//�û�����
	CMFCRibbonButton* m_pBtnUserManage;

	//Ȩ�޹���
	CMFCRibbonButton* m_pBtnPowerManage;

private:

	//״̬
	CMFCRibbonPanel* m_pPanelMainStatus;

	CMFCRibbonButton* m_pBtnPan;

	CMFCRibbonButton* m_pBtnChip;

private:

	//ģʽC
	CMFCRibbonPanel* m_pPaneModel;

	CMFCRibbonButton* m_pBtnNamal;

	CMFCRibbonButton* m_pBtnFull;

	CMFCRibbonButton* m_pBtnFoure;

	CMFCRibbonButton* m_pBtnInter;

	CMFCRibbonButton* m_pBtnCopy;

private:

	CMFCRibbonPanel* m_pPaneDrag;

	CMFCRibbonButton* m_pBtnTip;

	CMFCRibbonButton* m_pBtnUp;

	CMFCRibbonButton* m_pBtnDown;
};

