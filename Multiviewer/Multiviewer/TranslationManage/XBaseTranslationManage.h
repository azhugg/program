#pragma once

#include "XConstantIM.h"

class XDelegateTranslationManage;

class XBaseTranslationManage
{
public:
	XBaseTranslationManage(void);
	virtual ~XBaseTranslationManage(void);

	//��ʼ��
	virtual void Init() = 0;

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//���¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type, void* pControl) = 0;

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type, void* pControl) = 0;

	//��ȡ��������
	virtual CString GetLanguagetype()=0;

	//������������
	virtual void SetLanguagetype(CString type)=0;

	//���ý���
	virtual void ReLoadInterface()=0;

public:

	//����ί��
	void SetDelegate(XDelegateTranslationManage* p);

protected:

	//ί��
	XDelegateTranslationManage* m_pDelegate;
};

