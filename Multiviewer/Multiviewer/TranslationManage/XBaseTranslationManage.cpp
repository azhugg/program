#include "StdAfx.h"
#include "XBaseTranslationManage.h"


XBaseTranslationManage::XBaseTranslationManage(void)
{
}


XBaseTranslationManage::~XBaseTranslationManage(void)
{
}

/***********************************************************
** ��������: ����ί��
************************************************************/
void XBaseTranslationManage::SetDelegate(XDelegateTranslationManage* p)
{
	m_pDelegate = p;
}

