#pragma once

class HYXDelegateOutputNode
{
public:
	HYXDelegateOutputNode(void);
	~HYXDelegateOutputNode(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//��������
	virtual void AdjustGrid() = 0;

	//����ˮƽ����
	virtual void AdjustScrollV() = 0;
};

