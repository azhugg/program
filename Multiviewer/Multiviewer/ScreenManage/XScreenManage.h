#pragma once

#include "XBaseScreenManage.h"
#include "XConstantIM.h"
#include "XExpandInfo.h"
#include "XDragInfo.h"
#include "XScreen.h"
#include "XDelegateResolution.h"
#include "XDelegateSaveScence.h"
#include "XDelegateChangeInput.h"
#include "XDelegateScreenMoveDlg.h"
#include "XDelegateScreenAttributes.h"
#include "XDelegateTimedPollingDlg.h"
#include "XSendData.h"
#include "XScreenMoveDlg.h"
#include "XDelegateDeleteScene.h"
#include "XDelegateAllResulation.h"
#include "XDelegateRunOldOrder.h"
#include "XOldOrderInfo.h"
#include "XScreenMoveInfo.h"
#include "XTimedPollingInfo.h"
#include "XAllResulationInfo.h"
#include "XDelegateChangeScreen.h"
#include "XDelegateScreenMoveChangeDlg.h"
#include "XDelegateSelectEquipment.h"
#include "XDelegateSetBoard.h"
#include "XDelegateSetScreenRange.h"
#include "XMenuScreenSetInfo.h"
#include "VideoPlayerConstant.h"
#include "XScreenRetInfo.h"
#include "XDelegateMatrixResolution.h"
#include "XDelegateAllMatrixResolution.h"
#include "XDelegateMatrixScreenAttributes.h"
#include "XDelegateSetScreenName.h"
#include "XSaveScence.h"
#include "XResulationHCutInfo.h"
#include "XResulationVCutInfo.h"
#include "XDelegateSetRowResoluation.h"
#include "XDelegateSetColResoluation.h"


class XSignal;
class XInputSignal;
class XRTSPInfo;
class CMultiviewerView;
class XScreenSetInfo;




class XScreenManage : public XBaseScreenManage,
					  public XDelegateResolution,
					  public XDelegateSaveScence,
					  public XDelegateChangeInput,
					  public XDelegateScreenMoveDlg,
					  public XDelegateScreenAttributesDlg,
					  public XDelegateTimedPollingDlg,
					  public XDelegateDeleteSceneDlg,
					  public XDelegateAllResulution,
					  public XDelegateRunOldOrderDlg,
					  public XDelegateChangeScreen,
					  public XDelegateScreenMoveChangeDlg,
					  public XDelegateSelectEquipment,
					  public XDelegateSetBoard,
					  public XDelegateSetScreenRange,
					  public XDelegateMatrixResolution,
					  public XDelegateAllMatrixResolution,
					  public XDelegateMatrixScreenAttributesDlg,
					  public XDelegateSetScreenName,
					  public XDelegateSetRowResoluation,
					  public XDelegateSetColResoluation
			
{
public:
	XScreenManage(void);
	~XScreenManage(void);

	//���¿ؼ�������ʾ
	virtual void UpdateControlDataShow(XDATATYPE type, void* pControl);

	//�ؼ����ݸı�
	virtual void ControlDataChange(XDATATYPE type, void* pControl);

	//��ȡ����
	virtual void GetData(CArchive& arch);

	//��������
	virtual void SaveData(CArchive& arch);

	//��ȡ����
	virtual float GetMultiScale();

	//��ȡˮƽ��Ļ
	virtual int GetFramesCountH();

	//��ȡ��ֱ��Ļ����
	virtual int GetFramesCountV();

	//��ȡ��Ļ�ֱ���
	virtual int GetFramesResulationH();

	//��ȡ��Ļ�ֱ���
	virtual int GetFramesResulationV();

	//��ȡ�Ҳ�ˮƽ�ֱ���
	virtual int GetFramesRightResulationH();

	//��ȡ�ײ���ֱ�ֱ���
	virtual int GetFramesBottomResulationV();

	//��������
	virtual void ResetData();

	//��ͼ����
	virtual void ViewDraw(CDC* pDC, CRect rect, int noffsetX, 
		int noffsetY);

	//��ͼ��ȡ��С
	virtual CSize ViewGetSize();

	//��ͼ�������
	virtual void ViewLButtonDown(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ˫��
	virtual void ViewLBDClick(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ�������
	virtual void ViewLButtonUp(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ����ƶ�
	virtual void ViewMouseMove(UINT& nFlags, CPoint& point, CRect& rect, 
		int noffsetX, int noffsetY);

	//��ͼ����뿪
	virtual void ViewMouseLeave();

	//��ͼ��������
	virtual void ViewKeyUp(UINT nChar);

	//��ͼ�Ҽ�����
	virtual void ViewRButtonUp(CWnd* pWnd, UINT& nFlags, CPoint& point, 
		CRect& rect, int noffsetX, int noffsetY);

	//����
	virtual void Operate(OPERATETYPE type, void* pData);

	//����KEY��ʾ��Ϣ�Ի���
	virtual int MessageBoxFromKey(CString szKey, CString szDefault, UINT uType);

	//���¿ؼ�UI
	virtual void UpdateControlUI(CMDUITYPE type, CCmdUI* pCmdUI);

	//��ȡ�ַ���
	virtual CString GetTranslationString(CString szKey, CString szDefault);

	//��ʾ������
	virtual void ShowManage(int nShowState);

	//�϶���Ϣ
	virtual BOOL DragInfo(CRect rc,CPoint point,XDragInfo* pInfo);

	//Ԥ���϶���Ϣ
	virtual BOOL DragInfo(CRect rc, XRTSPInfo* pInfo);

	//��ȡ�������
	virtual int GetOutputCount();

	//������ͼ����
	virtual void SetViewName(CString szName);

	//��ȡ��ͼ����
	virtual CString GetViewName();

	//�򿪳�������������
	virtual void OpenScene(CString szSceneName,int nSceneIndex,CString szViewName);

	//ɾ������
	virtual void DeleteScene(int nSceneIndex);

	//�Ƿ��¼
	virtual BOOL IsLogin();

	//ˢ����ͼ
	virtual void InvalidateView();

	//������ͼ��С
	virtual void ResetViewSize();

	//��ʾ�˵����Ҽ���ǩ����
	virtual void ShowMenu(CPoint& point);

	//��ͼ��������Ԥ��ǽ��С
	virtual void AdjustMultiVideoWindowSize();

	//��ȡ��Ļ����
	virtual VEC_SCREEN& GetVecScreen1();

	//�˵���Ļ����
	virtual XMenuScreenSetInfo* GetMenuScreenSetInfo();

	//��ȡ��Ļ�����ź���RTSP����
	virtual int GetRTSPCountBySignal(CString szRTSP);

	//������Ļ����
	virtual CString SetText(XScreen* pScreen);

	//ˢ�½��棨���룩
	virtual void ReLoadInterface();

	//������Ļ�����źŵ�RTSP(��קԤ��ʱ)
	virtual void SetScreenSignalRTSPAddrByIndex(int nInputIndex,CString szRTSP);

	virtual MAP_BOARDTYPE& GetMapBoardType();

	//�ı�Ԥ��ǽ�����źű���
	virtual void ChangeMultiVideoWindowsAnotherName(int nInputIndex,CString szAnotherName);

	//������Ļ��ʼ���
	virtual void SetBeginIndex(int n);

	//������Ļ���ͣ�����ƴ�ӣ�
	virtual void SetScreenModel(int n);

	//��ȡ��Ļ����
	virtual int GetScreenModel();

	//��ȡ��Ļ����
	virtual int GetScreenType();

	//��ӳ���
	virtual void OnBtnNewScene();

	//�رձ�ǩҳʱ����ʾ���泡��
	virtual void SaveSceneByCloseView();

	//��ȡ������
	virtual MAP_SCENEGROUP& GetMapSceneGroup();

	//����ȫ������
    virtual void SaveAllScene(CString szSceenName,int nSceneIndex,CString szSceneGroup,int nIndex,int nType);

	//��ȫ������
	virtual void OpenAllScene(CString szSceneName,int nSceneIndex,int nIndex,int nType,CString szViewName=_T(""));

	virtual void CopyOrderToShare(CString szSceneName,int nSceneIndex,int nIndex,CString szViewName);

	virtual void CopySingleOrderToShare(CString szSceneNane,int nSceneIndex,CString szViewName);

	//���õ�ǰ��ͼ����
	virtual void SetMultiScale(float f);

	//��ȡ��ק��Ϣ
	virtual XDragInfo& GetDragInfo();

	//������
	virtual BOOL AddScalingByMouseWheel(short zDelta);

	//˫����ǩ΢��
	virtual void SetScreenByDbClick();

	virtual MAP_COLINFO& GetMapColInfo();

	virtual MAP_ROWINFO& GetMapRowInfo();

public:

	//��ȡ���ű���
	float GetScale();

	//�������ű���
	void SetCurScale(int n);

	//��ȡ��������
	int GetCurScale();

	//��ȡ�豸IP
	CString GetDeviceIP();

	//�����豸IP
	void SetDeviceIP(CString str);

	//��ȡ�豸�˿�
	int GetDevicePort();

	//�����豸�˿ں�
	void SetDevicePort(int n);

	//��ȡ��������
	CString GetLanguagetype();

	//������Ļ�����ı���������
	void ResetDataBySceneScreenCountChange();

	//������������
	void ResetDataBySceneInputCountChange();

	//������������
	void SetLanguagetype(CString type);

	//��������
	BOOL SendData(char* pData, int nDataLen);

	//��ȡ��Ļ
	XScreen* GetScreen(int n);

	//�ƶ��ź�
	void MoveSignal(POINTF& point1, POINTF& point2);

	//��ק�������ź�
	void MoveSignalOfNew(POINTF& point1, POINTF& point2);

	//��ȡ�����
	RECTF GetInterRect();

	//������IDɾ���ź�
	void DeleteSignalBySignalGroupID(unsigned int nID);

	//����IDɾ���ź�
	void DeleteSignalBySignalID(unsigned int nID);

	//���������źŸ���
	void SetInputCount(int n);

	//��ȡ�����źŸ���
	int GetInputCount();

	//�����Ҳ����
	void SetRightResulationH(int n);

	//��ȡ�Ҳ����
	int GetRightResulationH();

	//���õײ�����
	void SetBottomResulationV(int n);

	//��ȡ�ײ�����
	int GetBottomResulationV();

	//�ӳ���·����ȡ�������
	int GetSceneIndexFromScenePath(CString szPath);

	//�ж���Ļ�����豸
	BOOL IsHaveDevice(int nIndex);

	//���ʹ������
	void SendAllData(BOOL bCopy=FALSE);

	//��ȡ��ͼ�Ƿ������
	BOOL GetISViewButtonDown();

	//��ȡ��Ļ��ʼ���
	int GetBeginIndex();

	//�Ƿ�Ϊ��·
	void IsTwoScreen(int nIndex);

	//����OSD
	void SetOSD(int nIndex);

	//��ȡview
	CMultiviewerView* GetView();

	//����view
	void SetView(CMultiviewerView* pView);

	//�����Ƿ�Ϊ��ǩ���Ҽ����
	void SetIsMenuSet(BOOL b);

	//��ȡ�Ƿ�Ϊ��ǩ�˵��Ҽ����
	BOOL GetIsMenuSet();

	//������Ż�ȡ�źŸ���
	int GetSignalCountByIndex(int nIndex);

	//�����������Ԥ������RTSP����Ϊ1
	void SetFrameRTSPCountByIndex(int nInputIndex);

	//������Ż�ȡ�忨����
	int GetBoardTypeByReStatus(int nStatus);

	int GetInputTypeByReStatus(int nStatus);

	BOOL JudgeIsCanOpenScene();

public:

	//��ȡ��Ļ����
	VEC_SCREEN& GetVecScreen();

	//��ȡ�����źż���
	VEC_INPUTSIGNAL& GetVecInputSignal();

	//������Ļ��Ϣ
	void SetVecScreenInfo(VEC_SCREENINFO& VecScreenInfo);

	//��ȡ��Ļ���ݼ���
	VEC_SCREENDATA& GetVecScreenData();

	//������Ļ���ݼ���
	void SetVecScreenData(VEC_SCREENDATA& VecData);

	//��ȡ�쿨���
	//MAP_BOARDTYPE& GetMapBoardType();

	MAP_INPUTTYPE& GetMapInputType();

	VEC_BASESCREENMANAGE& GetVecBaseScreenManage();


public:

	//��ȡ��Ļ��������
	XScreenMoveInfo* GetScreenMoveInfo();

	//��ѯʱ����
	XTimedPollingInfo* GetTimedPollingInfo();

	//���зֱ���
	XAllResulationInfo* GetAllResulationInfo();

	//�Ҳ����
	XResulationHCutInfo* GetResulationHCutInfo();

	//�ײ�����
	XResulationVCutInfo* GetResulationVCutInfo();

	//��ָ��
	XOldOrderInfo* GetOldOrderInfo();


private:

	//��ʼ����Ļ����
	void InitVecScreen();

	//��ʼ��������Ļ����
	void InitSceneVecScreen();

	//���ݷֱ���������Ļ����
	void ResetScreenArray();

	void ResetScreenArrayByRow();

	void ResetScreenArrayByCol();

	//��ȡ���
	HCURSOR GetCursor(CURSORTYPE type);

	//�������
	void SetCursor(CURSORTYPE type);

	//��ʾ��Ļ�˵�
	void ShowScreenMenu();

	//��ʾ�źŲ˵�
	void ShowSignalMenu();

	//ɾ�������ź�
	void DeleteAllSignal();

	//ɾ������Frame
	void DeleteAllFrame();

	//����ͬ��ʱ��
	void UpdateSynTime();

	//������Ļ�����ı���������
	void ResetDataByScreenCountChange();

	//�Ƿ�������ź�
	BOOL CanAddNewSignal(VEC_SCREEN& VecScreen);

	//�Ƿ�������ź�
	BOOL CanAddNewSignal(VEC_RECTF& VecRectF);

	//�Ƿ����ƶ��ź�
	BOOL CanMoveSignal(VEC_SCREEN& VecScreen,unsigned int nSignalID);

	//�Ƿ����ƶ��ź�
	BOOL IsCanMoveSignal(VEC_SCREEN& VecScreen,unsigned int nSignalID);

	//�ָ���Ļ�źŸ���
	void ResetSignalNumInScreen();

	//�Ƿ����ƶ��ź�
	BOOL CanMoveSignal(VEC_RECTF& VecDragRectF,VEC_UNINT& VecSignalID,unsigned int GroupID);

	//�Ƿ�������ź�
	BOOL IsCreateNewSignal(VEC_SCREEN& VecScreen,unsigned int nSignalID);

	//�ж������Ƿ����ź�
	BOOL IsHaveSignal(int nIndex);

	//�ж������Ƿ�������
	BOOL IsHavePane(int nIndex);

	//������Ż�ȡ��Ļ
	XScreen* GetScreenByIndex(int nIndex);

	//���ݰ忨�Ż�ȡ��Ļ���
	void GetScreenIndexByPaneIndex(int& nPaneIndex,int& nNum,int& nScreenIndex);

	//���ݰ忨�Ż�ȡ��Ļ���
	void GetScreenIndexByPaneIndex(int& nPaneIndex,int& nScreenIndex);

	//ͬ����ȡ��Ļ�ֱ���
	BOOL GetScreenResulation(int nIndex,int& nH,int& nV);

	//ͬ����ȡ��Ļ�ֱ���
	BOOL GetSignalResulation(int nIndex,int& nH,int& nV);

	//�л�����
	void ChangeInput(XInputSignal*& pInputSignal,RECTF& rect,BOOL bResIsUltra);

	//У���
	unsigned short CheckNum(char* pData,int nLen);

	//У����У��
	BOOL CheckSumNum(char* pData,int nLen);

	//��ȡ�ź�ID����ż���
	void SetVecInputSignalIndexAndID(XSignal* pSignal);

	//����4��RTSP
	void CreateRTSPAddr(CString szIP,CString szUseName,CString szPassWd);

	//����RTSP������
	void CreateRTSPAddr(CString szIP,CString szUseName,CString szPassWd,VEC_CSTRING& Vec);

	//����ֿ飨4�飩
	void SetRectToFoure(RECTF rect,VEC_RECTF& VecRect);

	//����ֿ飨���飩
	void SetRectToTwo(RECTF rect,VEC_RECTF& VecRect);

	//����ֱ��ʷֿ�
	void SetInputResulationToFoure(RECTF rect,VEC_RECTF& VecRect);

	//����ÿ���ź���ռ��Ļ
	void CalculateVecScreen(RECTF rect,VEC_SCREEN& VecScreen);

	//������ID��ȡID����
	void GetVecSignalID(unsigned int nGroupID,VEC_UNINT& VecInt);

	//������ID��ȡID����
	void GetVecSignalIndex(unsigned int nGroupID,HYVEC_NUM& VecInt);

	//�����϶�Frame
	void AddDragFrame(RECTF rectInter);

	//����Frame��ʾ������
	void SetPreviewFrameShow(unsigned int nGroupID,BOOL bShow);

	//�ж��Ƿ�Ϊ��ǩҳ�˵�����
	void DecideIsMenuSet(BOOL bIsMenuSet);

	//�ж�����Դ�Ƿ�Ϊ4K
	void JudgetInputIsultra(int nInputIndex);

	//ɾ�����������źţ�4k��2k,�ƶ���
	void DeleteAnotherSignalByGroupID(unsigned int nSignalGroupID,unsigned int nSignalID);

	//��ѡ�ź�ID�ö�
	void SetSelectSignalIDTopInVecDrag(unsigned int nSignalID);

	//����RTSP����
	void SetRTSPAddrCountReset();

	//�򿪳���������Ԥ��ǽ��
	void AddScene();

	void AddSceneToCopyScene(XScreenManage* pTemp,CString szPath);

	//����ƴ��ģʽ����������״̬
	void UpdateControlUIByStatus(CCmdUI* pCmdUI,int nStatus);

	//������קģʽ����������״̬
	void UpdateControlUIByModel(CCmdUI* pCmdUI,int nModel);

	//��קƴ��
	BOOL DragSplicInfo(CRect rc, XDragInfo* pInfo);

	//��ק����
	BOOL DragMatrixInfo(CRect rc, XDragInfo* pInfo);

	//��קƴ��
	BOOL DragSplicInfo(CRect rc, XRTSPInfo* pInfo);

	//��ק����
	BOOL DragMatrixInfo(CRect rc, XRTSPInfo* pInfo);

	//���ݰ忨�Լ���Ļ������Ż�ȡ��Ļ
	XScreen* GetScreenByBoardIndex(int nBoardIndex,int nChenal);

	//��ȡ�����ź�ID(ȫ��ID)
	unsigned int GetMatrixSignalID();

	//���þ����ź�ID
	void SetMatrixSignalID(unsigned int nID);

	//���������ȡҪɾ���ź���ID
	void GetDeleteSignalByCount(RECTF rect,int nType,MAP_GROUPID& Map);

	//�����ź�ѡ��
	void SetSignalSelectByGroupID(unsigned int nGroupID);

	//����Frameѡ��
	void SetFrameSelectByGroupID(unsigned int nGroupID);

	//�����·ֱ������¿���
	void ResetSignalByNewResulation();

	CString GetRTSPAddrFromPreviewPane(int nSignalIndex);

	void SetScreenWidthAndHight();

public:

	//�����Ļ����
	void ClearVecScreen();

	//������ͻ��漯��
	void ClearVecSendData();

	//�����Ļ���ݼ���
	void ClearVecScreenData();

	void ClearVecScreenInfo();

	//����忨���
	void ClearMapBoardType();

	//����϶�����
	void ClearDragFrame();

	void ClearReMapRTSP();

	//�ͷžֲ��Ŵ���Ϣ
	void ClearExpandInfo();

	void ClearInputType();

	void ClearRowInfo();

	void ClearColInfo();

private:

	//����ˮƽ���������ʾ
	void UpdateControlDataShowOfOutputCountH(CMFCRibbonEdit* p);

	//ˮƽ��������ı�
	void ControlDataChangeOfOutputCountH(CMFCRibbonEdit* p);

	void UpdateControlDataShowOfScale(CMFCRibbonComboBox* pCombox);

	//���´�ֱ���������ʾ
	void UpdateControlDataShowOfOutputCountV(CMFCRibbonEdit* p);

	void ControlDataChangeOfScale(CMFCRibbonComboBox* pCombox);

	//��ֱ��������ı�
	void ControlDataChangeOfOutputCountV(CMFCRibbonEdit* p);

	//�ź��ö�
	void OperateOfTopSignal();

	//�ź��õ�
	void OperateOfBottomSignal();

	//�ź�����
	void OperateOfShiftUPSignal();

	//�ź�����
	void OperateOfShiftDownSignal();

	//�ź���չ
	void OperateOfExpandSignal();

	//�л�����Դ
	void OperateOfChangeInput();

	//ɾ���ź�
	BOOL OperateOfCloseSignal();

	//ɾ�������ź�
	void OperateOfDeleteAllSignal();

	//��������
	void OperateOfSetScreenMove();

	//���ö�ʱ��ѯʱ����
	void OperateOfSetTimedPolling();

	//������Ļ�ֱ���
	void OperateOfSetScreenResulation();

	//��Ļ�ֱ���
	void OperateOfScreenResulation();

	//��Ļ����
	void OperateOfScreenAttribute();

	//�������ݻ�ȡ��Ļ����
	void OperateOfGetScreenParamater();

	//��ȡ����Ļ����(����)
	void OperateOfSetScreenParamaterOfMatrix(char* pData);

	//��ȡ�����źŲ���
	void OperatorOfGetSignalParamater();

	//��ȡ��������
	void OperatorOfGetWindowParamater();

	//���ô�������
	void OperatorOfSetWindowParamater(char* pData);

	//���û�ȡ���źŲ���
	void OperateOfSetSignalParamater(char* pData);

	//��ȡ����Ļ����
	void OperateOfSetScreenParamater(char* pData);

	//��ȡ��Ļ����Ӧ��
	void OperatorOfSetScreenMoveAsk(char* pData);

	//���ó������
	void OperatorOfSetSceneIndex(char* pData);

	//�����豸״̬
	void OperateOfSetDeviceStatus(char* pData);

	//���泡��
	void OperateOfSaveScene();

	//�򿪳���
	void OperateOfOpenScene();

	//ɾ������
	void OperateOfDeleteScene();

	//��ȡ�������
	void OperateOfGetSceneIndex();

	//��ȡ�豸״̬
	void OperateOfGetDeviceStatus();

	//ִ�о�ָ��
	void OperateOfRunOldOrder();

	//������Ļ
	void OperateOfChangeScreen();

	//��ǩҳ�˵���������Ļ��
	void OperateMenuScreenSet();

	//��ǩҳ�˵������泡����
	void OperateMenuSaveScene();

	//��ȡ�����ź����
	void OperateOfGetInputNum();

	//���������ź����
	void OperateOfSetInputNum(char* pData);

	//������ͨ״̬
	void OperateOfSetNormal();

	//����ȫ��״̬
	void OperateOfSetFull();

	//�����ĵȷ�ģʽ
	void OperateOfSetFour();

	//��������ģʽ
	void OperateOfSetInter();

	//���ø���ģʽ
	void OperateOfSetCopyModel();

	//����������קģʽ
	void OperateOfSetTipModel();

	//����ɾ��������קģʽ
	void OperateOfSetUpModel();

	//ɾ���ײ���קģʽ
	void OperateOfSetDownModel();

	//������Ļ�ֱ��ʣ�����
	void OperateOfSetScreenResulationByMatrix();

	//ͬ������
	void OperateOfSetMatrixWindowParamater(char* pData);

	//�����зֱ���
	void OperateOfSetRowDpi();

	//�����зֱ���
	void OperateOfSetColDpi();

public:

	inline int GetScreenCountH(){return m_nScreenCountH;}

	inline void SetScreenCountH(int n){m_nScreenCountH=n;}

	inline int GetScreenCountV(){return m_nScreenCountV;}

	inline void SetScreenCountV(int n){m_nScreenCountV=n;}

	inline int GetResolutionH(){return m_nResolutionH;}

	inline void SetResolutionH(int n){m_nResolutionH=n;}

	inline int GetResolutionV(){return m_nResolutionV;}

	inline void SetResolutionV(int n){m_nResolutionV=n;}

	inline int GetDragStatus(){return m_nStatus;}

	inline void SetDragStatus(int n){m_nStatus=n;}

	inline int GetDragModel(){return m_nDragModel;}

	inline void SetDragModel(int n){m_nDragModel=n;}

private:

	//��ͼ����
	CString m_ViewName;

	//��Ļ��ʼ���
	int m_BeginIndex;

	//��ʾ����
	int m_ShowType;

	//ͬ��ʱ��
	DWORD m_SynTime;

	//��갴��λ��
	POINTF m_Point;

	//��Ļ����
	XScreen* m_TempScreen;

	//ˮƽ����
	int m_nScreenCountH;

	//��ֱ����
	int m_nScreenCountV;

	//ˮƽ�ֱ���
	int m_nResolutionH;

	//��ֱ�ֱ���
	int m_nResolutionV;

	//�Ҳ����
	int m_nRightResulationH;

	//�ײ�����
	int m_nBottomResulationV;

	//�������
	CURSORTYPE m_CursorType;

	//������źŵ�λ��,���������ź�
	POSITIONTYPE m_PositionType;

	//��ͼ��갴��
	BOOL m_ISViewButtonDown;

	//�ź�������������������ʽ�ʹ������δ���
	RECTF m_InterRect;

	//���������ƶ�������
	//RECTF m_NewRect;

	//�Ƿ񻺴����
	BOOL m_IsSendPocket;

	//�Ҽ��ź���������ź��л�
	int m_RBtnIndex;

	//�Ҽ��ź�ID�����Ҽ�����
	unsigned int m_RBtnSignalID;

	//�Ҽ��ź���ID
	unsigned int m_RBtnSignalGroupID;

	//˫���ź���������ź��л�
	int m_LBDIndex;

	//˫���ź�ID�����Ҽ�����
	unsigned int m_LBDSignalID;

	//˫���ź���ID
	unsigned int m_LBDSignalGroupID;
	
	//��Ļ����Ӧ������
	char* pAskData;

	//��Ļ�ƶ��Ի���
	XScreenMoveDlg* m_pScreenMoveDlg;

	//���泡���Ի���
	XSaveScence m_SaveSceneDlg;

	//�Ƿ�˫��
	BOOL m_bIsLBDClick;

	//�Ƿ��ƶ�
	BOOL m_bIsMoveSignal;

	//RTSP��ַ�������ƶ���
	CString m_szRBRTSPAddr;

	//IP��ַ�������ƶ���
	CString m_szRBIPAddr;

	//�Ƿ���Ҫ��ֵ
	BOOL m_bIsMenuSet;

	//��Ļģʽ
	int m_nScreenModel;

	//��ק״̬
	int m_nStatus;

	//��קģʽ
	int m_nDragModel;

	//��ǰ��Ļ��������
	int m_nCurScale;

	//�Ƿ񴴽��źţ��϶���
	BOOL m_bCreateSignal;

	//û��֮ǰ�ֱ���
	int m_nPreResolutionH;

	int m_nPreResolutionV;

private:

	//�ƶ�ʱ��ק��Ϣ
	XDragInfo m_DragInfo;

	//��Ļ��������
	XScreenMoveInfo m_MoveInfo;

	//��ʱ��ѯ
	XTimedPollingInfo m_PollingInfo;

	//���зֱ���
	XAllResulationInfo m_AllInfo;

	//��ָ��
	XOldOrderInfo m_OldOrderInfo;

	//�˵���Ļ����
	XMenuScreenSetInfo m_ScreenSetInfo;

	//���зֱ���
	XResulationHCutInfo m_ResulationHInfo;

	//�ײ�����
	XResulationVCutInfo m_ResulationVInfo;

private:

	//��Ļ����
	VEC_SCREEN m_VecScreen;

	//�������ݼ���
	VEC_SENDDATA m_VecSendData; 

	//��Ļ���ݼ���
	VEC_SCREENDATA m_VecScreenData;

	//��Ļ��Ϣ����
	VEC_SCREENINFO m_VecScreenInfo;

	//�϶�Frame
	VEC_MULTIVIDEOWINDOWFRAME m_VecDragFrame;

	//�忨���
	MAP_BOARDTYPE m_MapBoardType;

	//���뿨����
	MAP_INPUTTYPE m_MapInputType;

	//����ֲ��Ŵ�
	VEC_EXPANDINFO m_VecExpandInfo;

	//ͬ��RTSP��ַ
	MAP_RERTSPADDR m_MapReRTSPAddr;

	MAP_ROWINFO m_MapRowInfo;

	MAP_COLINFO m_MapColInfo;
};

