#pragma once

class HYXDelegateInputNode
{
public:
	HYXDelegateInputNode(void);
	~HYXDelegateInputNode(void);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault) = 0;

	//��������
	virtual void AdjustGrid() = 0;

	//����ˮƽ����
	virtual void AdjustScrollH() = 0;
};

