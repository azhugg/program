#pragma once

//Ribbon������ί����
class XDelegateRibbonBar
{
public:
	XDelegateRibbonBar(void);
	~XDelegateRibbonBar(void);

	//Ribbon��ʾ�����
	virtual void RibbonBarShowCategory(CString szName) = 0;
};

