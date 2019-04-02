#pragma once
#include "XConstantIM.h"

class HandleListCtrl
{
private:
	HandleListCtrl(void);
	~HandleListCtrl(void);

public:

	//��ʼ���б�
	static void InitList(CListCtrl* pListCtrl, int nColumnCount, BOOL bCheckBox, int nColumnWidth = -1);

	//�����б��������
	static void SetColumnText(CListCtrl* pListCtrl, int n, CString s);

	//��ȡ�б�ѡ����
	static int GetListSelectItem(CListCtrl* pListCtrl);

	//��ȡ�б�ѡ����
	static int GetListCheckCount(CListCtrl* pListCtrl);

	//��ȡ�б�ѡ��
	static int GetListCheckItem(CListCtrl* pListCtrl);

	//��ȡ�б�ѡ�������
	static CString GetListCheckItemText(CListCtrl* pListCtrl);

	//��ȡ�б�ѡ�������
	static void GetListCheckItemText(CListCtrl* pListCtrl,VEC_CSTRING& VecStr);

	//��ȡ�б�ѡ�������
	static void GetListCheckItemText(CListCtrl* pListCtrl,MAP_SELSCENE& MapScene);

	//��ȡ�б�ѡ���
	static void GetListCheckNum(CListCtrl* pListCtrl,HYVEC_NUM& VecNum);

	//�����б���ѡ��
	static void SetListItemSelect(CListCtrl* pListCtrl, int nItem);


};

