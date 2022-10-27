#pragma once
#include "FcsMedia.h"

class CRmfSegment
{
public:
	CRmfSegment();
	virtual ~CRmfSegment();
	long m_nInPoint;
	long m_nOutPoint;
	long m_nId;
};
CRmfSegment::CRmfSegment()
{
}

CRmfSegment::~CRmfSegment()
{
}
class CJbuVideoPlayerCtrl : public COleControl
{
	DECLARE_DYNCREATE(CJbuVideoPlayerCtrl)


public:
	CJbuVideoPlayerCtrl();
	BOOL m_bHasVideo;


protected:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

protected:
	CComPtr<IFcsPlayer> m_pPlayer;
	long m_nInPoint;
	long m_nOutPoint;
	long m_nIndex;
	CWnd* m_pParent;
	CRect m_rtParent;
	BOOL m_bFirsttimeFullScreen;
	CArray<CRmfSegment*, CRmfSegment*> m_segment_array;
	long m_nDefaultSegmentId;
	CWnd* m_pDesktopWnd;
	CWnd* m_pMainFrame;
	BOOL m_bFullScreen;
	HWND m_hWndParent;
	int m_nFrameNo;
	CString m_szVideoName;
	LOGFONT m_lf;
	COLORREF m_systemColor;
	BOOL m_bSelected;
	BOOL m_bEmbedded; 

protected:
	~CJbuVideoPlayerCtrl();

	DECLARE_OLECREATE_EX(CJbuVideoPlayerCtrl)    
	DECLARE_OLETYPELIB(CJbuVideoPlayerCtrl)      
	DECLARE_PROPPAGEIDS(CJbuVideoPlayerCtrl)    
	DECLARE_OLECTLTYPE(CJbuVideoPlayerCtrl)		


	DECLARE_MESSAGE_MAP()


	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();


	DECLARE_EVENT_MAP()


public:
	enum {
		dispidSetParentLong = 97L,
		dispidIsSelected = 96L,
		dispidIsEmbedded = 95L,
		dispidSetEmbedded = 94L,
		dispidSetSelect = 93L,
		dispidGetVideoEvent = 92L,
		dispidOpenVideo1 = 91L,
		dispidSetFps = 90L,
		dispidGetFps = 89L,
		dispidSetCurrentPositionByFrame = 88L,
		dispidFree = 87L,
		dispidGetCountOfArray = 86L,
		dispidSetOverlayText = 85L,
		dispidSetOverlayFont = 84L,
		dispidSetOverlayFontSize = 83L,
		dispidSetOverlayColor = 82L,
		dispidSetOverlayPosition = 81L,
		dispidDisplayOverlay = 80L,
		dispidSetOverlayFontName = 79L,
		dispidSetOverlayImgPosition = 78L,
		dispidDeleteSegment = 77L,
		dispidGetEvent = 69L,
		dispidGetEyeRectLineWidth = 68L,
		dispidSetEyeRectLineWidth = 67L,
		dispidGetFaceRectLineWidth = 66L,
		dispidSetFaceRectLineWidth = 65L,
		dispidGetCheck = 64L,
		dispidSetCheck = 63L,
		dispidResetCounter = 62L,
		dispidGetCurTime = 61L,
		dispidGetCurTimeMs = 60L,
		dispidGetBlinkCount = 59L,
		dispidGetActivativedValue = 58L,
		dispidGetLeadFace = 57L,
		dispidGetREyeballImg = 56L,
		dispidGetLEyeballImg = 55L,
		dispidGetREyeImg = 54L,
		dispidGetLEyeImg = 53L,
		dispidGetFaceImg = 52L,
		dispidGetLEyeballRect = 51L,
		dispidGetREyeballRect = 50L,
		dispidGetREyeRect = 49L,
		dispidGetLEyeRect = 48L,
		dispidGetFaceHeight = 47L,
		dispidGetFaceWidth = 46L,
		dispidGetFaceRect = 45L,
		dispidGraphPath = 44,
		dispidTemplateID = 43,
		dispidGetVideoName = 42L,
		dispidSetPositionByMs = 41L,
		dispidSetPositionByFrame = 40L,
		dispidSetTemplateID = 39L,
		dispidPlaySegment = 38L,
		dispidGetOutTcCode = 37L,
		dispidGetInTcCode = 36L,
		dispidGetOutPointByFrame = 35L,
		dispidOpen = 34L,
		dispidGetInPointByFrame = 33L,
		dispidSetDefaultSegment = 32L,
		dispidGetSegmentCount = 31L,
		dispidGetVuMeter = 30L,
		dispidSnapShot = 29L,
		dispidIsMute = 28L,
		dispidGetVolume = 27L,
		dispidMute = 26L,
		dispidSetSegment = 25L,
		dispidSetOutPoint = 24L,
		dispidSetInPoint = 23L,
		dispidGetLengthByMSec = 22L,
		dispidGetLengthByFrame = 21L,
		dispidGetVideoFps = 20L,
		dispidGetVideoHeight = 19L,
		dispidGetVideoWidth = 18L,
		dispidGetStatus = 17L,
		dispidGetCurPosByMSec = 16L,
		dispidGetCurPosByFrame = 15L,
		dispidGetCurPosTcString = 14L,
		dispidFullScreen = 13L,
		dispidSetVolume = 12L,
		dispidSecondRew = 11L,
		dispidSecondFwd = 10L,
		dispidStepRew = 9L,
		dispidStepFwd = 8L,
		dispidSetRate = 7L,
		dispidPause = 6L,
		dispidStop = 5L,
		dispidPlay = 4L,
		dispidHasVideo = 3L,
		dispidSetGraphPath = 2L,
		dispidOpenVideo = 1L
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	BOOL IsAvailable(long nPos);
	LONG StepFwd(void);
	LONG StepRew(void);
	LONG SecondFwd(LONG nSecond);
	LONG SecondRew(LONG nSecond);
	LONG Play(void);
	LONG Stop(void);
	LONG Pause(void);

	//
	LONG OpenVideo(LPCTSTR bstrFileName);
	LONG SetGraphPath(LPCTSTR bstrPath);
	SHORT HasVideo(void);
	LONG SetRate(DOUBLE dRate);
	LONG SetVolume(LONG dAmount);
	LONG FullScreen(SHORT nState);
	BSTR GetCurPosTcString(void);
	LONG GetCurPosByFrame(void);
	LONGLONG GetCurPosByMSec(void);
	LONG GetStatus(void);
	LONG GetVideoWidth(void);
	LONG GetVideoHeight(void);
	DOUBLE GetVideoFps(void);
	LONG GetLengthByFrame(void);
	LONGLONG GetLengthByMSec(void);
	LONG SetInPoint(LONG nPos);
	LONG SetOutPoint(LONG nPos);
	LONG SetSegment(void);
	LONG Mute(LONG bMute);
	DOUBLE GetVolume(void);
	SHORT IsMute(void);
	LONG SnapShot(LPCTSTR bstrImageName);
	DOUBLE GetVuMeter(SHORT nChannel);
	LONG GetSegmentCount(void);
	LONG SetDefaultSegment(LONG nSegmentID);
	LONG GetInPointByFrame(LONG nSegmentID);
	LONG Open();
	LONG GetOutPointByFrame(LONG nSegmentID);
	BSTR GetInTcCode(LONG nSegmentID);
	BSTR GetOutTcCode(LONG nSegmentID);
protected:
	LONG PlaySegment(LONG nSegmentID);

	//LONG SetTemplateID(LONG nID);
	SHORT SetPositionByFrame(LONG nBeginFrame, LONG nEndFrame);
	SHORT SetPositionByMs(LONGLONG nStartTime, LONGLONG nStopTime);
	BSTR GetVideoName(void);
	void OnTemplateIDChanged(void);
	LONG m_TemplateID;
	LONG m_PrevTemplateID;
	void OnGraphPathChanged(void);
	CString m_GraphPath;
	LONG GetFaceRect(LONG* left, LONG* top, LONG* right, LONG* bottom);
	LONG GetFaceWidth(LONG* nWidth);
	LONG GetFaceHeight(LONG* nHeight);
	LONG GetLEyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom);
	LONG GetREyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom);
	LONG GetREyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom);
	LONG GetLEyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom);
	LONG GetFaceImg(BYTE* pImage, LONG nSize);
	LONG GetLEyeImg(BYTE* pImage, LONG nSize);
	LONG GetREyeImg(BYTE* pImage, LONG nSize);
	LONG GetLEyeballImg(BYTE* pImage, LONG nSize);
	LONG GetREyeballImg(BYTE* pImage, LONG nSize);
	LONG GetLeadFace(BYTE* pLeadFace);
	LONG GetActivativedValue(DOUBLE* dActivation);
	LONG GetBlinkCount(void);
	LONG GetCurTimeMs(void);
	LONGLONG GetCurTime(void);
	SHORT ResetCounter(void);
	SHORT SetCheck(SHORT nCheck);
	SHORT GetCheck(void);
	SHORT SetFaceRectLineWidth(FLOAT fLineWidth);
	LONG GetFaceRectLineWidth(FLOAT* fLineWidth);
	SHORT SetEyeRectLineWidth(FLOAT fLineWidth);
	LONG GetEyeRectLineWidth(FLOAT* fLineWidth);
	SHORT GetEvent(LONG* evCode, LONG* L1, LONG* L2);
public:
protected:
	LONG DeleteSegment(LONG nSegmentID);
	SHORT SetOverlayImgPosition(LPCTSTR szImgName, LONG nLeft, LONG nTop, LONG nRight, LONG nBottom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency);
	SHORT SetOverlayFontName(LONG nID, LPCTSTR szFontName);
	SHORT DisplayOverlay(LONG nID, SHORT bIsDisplay);
	SHORT SetOverlayPosition(LONG nID, LONG nLeft, LONG nTop, LONG nRight, LONG nBottom);
	SHORT SetOverlayColor(LONG nID, OLE_COLOR nColor);
	SHORT SetOverlayFontSize(LONG nID, LONG nFontSize);
	SHORT SetOverlayFont(LONG nID, LONG nFontStyle, SHORT bUnderLine, SHORT bWrap, SHORT bVertical, SHORT bRightAlign);
	SHORT SetOverlayText(LONG nID, LPCTSTR szText);
	SHORT GetCountOfArray(void);
	void Free(void);
	SHORT SetCurrentPositionByFrame(LONGLONG nCurrentFrame);
	DOUBLE GetFps(void);
	void SetFps(DOUBLE dFps);
	LONG OpenVideo1(LPCTSTR VideoName, LONG GraphID);
	SHORT GetVideoEvent(void);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
protected:
	SHORT SetSelect(SHORT bSelected);
	SHORT SetEmbedded(SHORT bEmbedded);
	SHORT IsEmbedded(void);
	SHORT IsSelected(void);
	void SetParentLong(LONG Parent);
};

