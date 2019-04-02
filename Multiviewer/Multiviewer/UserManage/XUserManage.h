#pragma once

#include "XConstantIM.h"

class XDelegateUserManage;
class XUserInfo;

#define DEFAULTACCOUNT _T("admin")//Ĭ���ʺ�

class XUserManage
{
public:
	XUserManage(void);
	~XUserManage(void);

public:

	//��ʼ��
	void Init();

	void SetDelegate(XDelegateUserManage* p);

	//��������
	void ResetData();

	//��ȡ����
	void GetData(CArchive& arch);

	//��������
	void SaveData(CArchive& arch);

	//�ж��ʺ��Ƿ����
	BOOL DecideAccountExist(CString name);

	//��ȡ�ʺ���Ϣ
	XUserInfo* GetAccountInfo(CString name);

	//�ж��û���������
	XUserInfo* DecideAccountAndPsw(CString name, CString psw);

	//����û���Ϣ
	XUserInfo* AddUserInfo(CString szAccount, CString szPSW, POWERTYPE type);

	//ɾ���ʺ�
	void DeleteAccount(CString name);

	//��ȡ��ͨ�û�
	void GetNormalUser(VEC_USERINFO& VecUesrInfo);

	//��ȡ�û���Ϣ����
	VEC_USERINFO& GetVecUserInfo();

	//��ȡ�û�����
	int GetUserCount();

	//����
	void Operate(OPERATETYPE type, void* pData);

	//���¿ؼ�UI
	void UpdateControlUI(CMDUITYPE type, CCmdUI* pCmdUI);

	//�Ƿ��¼
	BOOL IsLogin();

	//��ȡ�û��ڵ�Ȩ��
	BOOL GetUserNodePower(int nInputIndex, int nOutputIndex);

	//�Ƿ����Ա�û�
	BOOL IsAdminUser();

	inline CString GetNotice(){return m_szNotice;}

	inline void SetNotice(CString szNotice){m_szNotice=szNotice;}

public:

	XDelegateUserManage* GetDelegate();

	//���õ�ǰ�û���Ϣ
	void SetCurUserInfo(XUserInfo* p);

	//��ȡ��ǰ�û���Ϣ
	XUserInfo* GetCurUserInfo();

private:

	void OperateOfLogin();

	void OperateOfUserManage();

	void OperateOfPowerManage();

	void OperateOfResetUserNodePower();

	void UpdateControlUIByAdmin(CCmdUI* pCmdUI);

private:

	//�������
	void ClearData();

private:

	XDelegateUserManage* m_pDelegate;

	//�û���Ϣ����
	VEC_USERINFO m_VecUserInfo;

	//��ǰ�û���Ϣ
	XUserInfo* m_CurUserInfo;

	CString m_szNotice;
};

