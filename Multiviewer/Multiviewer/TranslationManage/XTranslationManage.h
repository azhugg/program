#pragma once

#include "XBaseTranslationManage.h"

class XTranslationManage : public XBaseTranslationManage
{
public:
	XTranslationManage(void);
	~XTranslationManage(void);

	//��ʼ��
	virtual void Init();

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault);

	//���¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type, void* pControl);

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type, void* pControl);

	//��ȡ��������
	virtual CString GetLanguagetype();

	//������������
	virtual void SetLanguagetype(CString type);

	//���ý���
	virtual void ReLoadInterface();

private:

	//��ȡ��������
	LANGUAGETYPE GetLanguageType();

	//������������
	void SetLanguageType(LANGUAGETYPE type);

	//������������
	void SaveLanguageType(LANGUAGETYPE type);

	//�����������ͻ�ȡ�����ļ�·��
	CString GetTranslationFilePath(LANGUAGETYPE type);

	//�����������ƻ�ȡ��������
	LANGUAGETYPE GetLanguageType(CString szLanguageName);

	//�����������ͻ�ȡ��������
	CString GetLanguageName(LANGUAGETYPE type);

private:

	//��������������ʾ
	void UpdateControlDataShowOfLanguageName(CMFCRibbonComboBox* pCombox);

	//�������͸ı�
	void ControlDataChangeOfLanguageName(CMFCRibbonComboBox* pCombox);

private:

	//��������
	LANGUAGETYPE m_LanguageType;

	//�����ļ�·��
	CString m_szTranslationFilePath;
};

