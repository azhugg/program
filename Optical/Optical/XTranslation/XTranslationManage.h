#pragma once
#include "XConstant.h"


class XTranslationManage
{
private:
	XTranslationManage();
	~XTranslationManage();

public:

	//��ȡ����
	static XTranslationManage* GetInstance();

	//�ͷŵ���
	static void Release();

public:

	//��ʼ��
	void Init();

	//��ȡ�ַ���
	CString GetTranslationString(CString szKey, CString szDefault=_T(""));

	//��ȡ��������
	LANGUAGETYPE GetLanguageType();

	//�������ƻ�ȡ��������
	LANGUAGETYPE GetLanguageType(CString szLanguageName);

	//������������
	void SetLanguageType(LANGUAGETYPE type);

	//�������ͻ�ȡ��������
	CString GetLanguageName(LANGUAGETYPE type);

	//������������
	void SaveLanguageType();

private:

	//�����������ͻ�ȡ�����ļ�·��
	CString GetTranslationFilePath(LANGUAGETYPE type);

private:

	//��������
	LANGUAGETYPE m_LanguageType;

	//�����ļ�·��
	CString m_szTranslationFilePath;

private:

	static XTranslationManage* m_pTranslationManage;

	//���������ͷ�
	//class GC
	//{
	//public:
	//	~GC();
	//};
	//static GC gc;
};