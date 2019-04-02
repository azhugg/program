#pragma once
#include "XConstantIM.h"
#include "XBoardChild.h"

class XEquipmentInputWnd;
class HYXText;


class XEquipmentInput
{
public:
	XEquipmentInput(void);
	~XEquipmentInput(void);

	//��ʼ��
	void Init();

	//��������
	void SetRect(CRect r);

	//�������
	void SetIndex(int n);

	//��ȡ����
	CRect GetRect();

	//���ø�����
	void SetInputBoardChild(XBoardChild* pChild);

	XBoardChild* GetInputBoardChild();

	//��ȡ���
	int GetIndex();

	//���ؽ���
	void ReloadInterface();

	//��ȡ����
	CRect GetEquipmentRect();

	//���������ź�����
	void SetInputName(CString szName);

	//��ȡ�����ź�����
	CString GetInputName();

	//�������
	void ClearEquipmentWnd();

	//������ִ���
	void ClearEquipmentTextWnd();

	//��������
	void SetEquipmentType(int n);

	void SetInputType(int n);

public:

	//��������
	void UpdateText();

private:

	//��������
	void CreateEquipmentWnd();

	//�������ִ���
	void CreateEquipmentTextWnd();

private:

	XBoardChild* m_pChild;

	//����
	CRect m_Rect;

	//���
	int m_Index;

	//�����ź�mingc
	CString m_szInputName;

	//����
	XEquipmentInputWnd* m_EquipmentWnd;

	//���ִ���
	HYXText* m_EquipmentTextWnd;

	int m_nInputType;
};

