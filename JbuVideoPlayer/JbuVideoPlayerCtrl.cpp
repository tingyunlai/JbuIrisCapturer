

#include "stdafx.h"
#include "JbuVideoPlayer.h"
#include "JbuVideoPlayerCtrl.h"
#include "JbuVideoPlayerPropPage.h"
#include "afxdialogex.h"
#include "Fcsmedia_i.c"
#include <initguid.h>
#include <DShow.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CJbuVideoPlayerCtrl, COleControl)





BEGIN_MESSAGE_MAP(CJbuVideoPlayerCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_NCPAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()





BEGIN_DISPATCH_MAP(CJbuVideoPlayerCtrl, COleControl)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "OpenVideo", dispidOpenVideo, OpenVideo, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetGraphPath", dispidSetGraphPath, SetGraphPath, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "HasVideo", dispidHasVideo, HasVideo, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "Play", dispidPlay, Play, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "Stop", dispidStop, Stop, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "Pause", dispidPause, Pause, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetRate", dispidSetRate, SetRate, VT_I4, VTS_R8)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "StepFwd", dispidStepFwd, StepFwd, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "StepRew", dispidStepRew, StepRew, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SecondFwd", dispidSecondFwd, SecondFwd, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SecondRew", dispidSecondRew, SecondRew, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetVolume", dispidSetVolume, SetVolume, VT_I4, VTS_R8)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "FullScreen", dispidFullScreen, FullScreen, VT_I4, VTS_I2)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetCurPosTcString", dispidGetCurPosTcString, GetCurPosTcString, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetCurPosByFrame", dispidGetCurPosByFrame, GetCurPosByFrame, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetCurPosByMSec", dispidGetCurPosByMSec, GetCurPosByMSec, VT_I8, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetStatus", dispidGetStatus, GetStatus, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetVideoWidth", dispidGetVideoWidth, GetVideoWidth, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetVideoHeight", dispidGetVideoHeight, GetVideoHeight, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetVideoFps", dispidGetVideoFps, GetVideoFps, VT_R8, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetLengthByFrame", dispidGetLengthByFrame, GetLengthByFrame, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetLengthByMSec", dispidGetLengthByMSec, GetLengthByMSec, VT_I8, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetInPoint", dispidSetInPoint, SetInPoint, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOutPoint", dispidSetOutPoint, SetOutPoint, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetSegment", dispidSetSegment, SetSegment, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "Mute", dispidMute, Mute, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetVolume", dispidGetVolume, GetVolume, VT_R8, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "IsMute", dispidIsMute, IsMute, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SnapShot", dispidSnapShot, SnapShot, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetVuMeter", dispidGetVuMeter, GetVuMeter, VT_R8, VTS_I2)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetSegmentCount", dispidGetSegmentCount, GetSegmentCount, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetDefaultSegment", dispidSetDefaultSegment, SetDefaultSegment, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetInPointByFrame", dispidGetInPointByFrame, GetInPointByFrame, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "Open", dispidOpen, Open, VT_I4, VTS_PI1)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetOutPointByFrame", dispidGetOutPointByFrame, GetOutPointByFrame, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetInTcCode", dispidGetInTcCode, GetInTcCode, VT_BSTR, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetOutTcCode", dispidGetOutTcCode, GetOutTcCode, VT_BSTR, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "PlaySegment", dispidPlaySegment, PlaySegment, VT_I4, VTS_I4)
	//DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetTemplateID", dispidSetTemplateID, SetTemplateID, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetPositionByFrame", dispidSetPositionByFrame, SetPositionByFrame, VT_I2, VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetPositionByMs", dispidSetPositionByMs, SetPositionByMs, VT_I2, VTS_I8 VTS_I8)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetVideoName", dispidGetVideoName, GetVideoName, VT_BSTR, VTS_NONE)
	DISP_PROPERTY_NOTIFY_ID(CJbuVideoPlayerCtrl, "TemplateID", dispidTemplateID, m_TemplateID, OnTemplateIDChanged, VT_I4)
	DISP_PROPERTY_NOTIFY_ID(CJbuVideoPlayerCtrl, "GraphPath", dispidGraphPath, m_GraphPath, OnGraphPathChanged, VT_BSTR)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetFaceRect", dispidGetFaceRect, GetFaceRect, VT_I4, VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetFaceWidth", dispidGetFaceWidth, GetFaceWidth, VT_I4, VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetFaceHeight", dispidGetFaceHeight, GetFaceHeight, VT_I4, VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetLEyeRect", dispidGetLEyeRect, GetLEyeRect, VT_I4, VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetREyeRect", dispidGetREyeRect, GetREyeRect, VT_I4, VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetREyeballRect", dispidGetREyeballRect, GetREyeballRect, VT_I4, VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetLEyeballRect", dispidGetLEyeballRect, GetLEyeballRect, VT_I4, VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetFaceImg", dispidGetFaceImg, GetFaceImg, VT_I4, VTS_PUI1 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetLEyeImg", dispidGetLEyeImg, GetLEyeImg, VT_I4, VTS_PUI1 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetREyeImg", dispidGetREyeImg, GetREyeImg, VT_I4, VTS_PUI1 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetLEyeballImg", dispidGetLEyeballImg, GetLEyeballImg, VT_I4, VTS_PUI1 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetREyeballImg", dispidGetREyeballImg, GetREyeballImg, VT_I4, VTS_PUI1 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetLeadFace", dispidGetLeadFace, GetLeadFace, VT_I4, VTS_PUI1)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetActivativedValue", dispidGetActivativedValue, GetActivativedValue, VT_I4, VTS_PR8)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetBlinkCount", dispidGetBlinkCount, GetBlinkCount, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetCurTimeMs", dispidGetCurTimeMs, GetCurTimeMs, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetCurTime", dispidGetCurTime, GetCurTime, VT_I8, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "ResetCounter", dispidResetCounter, ResetCounter, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetCheck", dispidSetCheck, SetCheck, VT_I2, VTS_I2)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetCheck", dispidGetCheck, GetCheck, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetFaceRectLineWidth", dispidSetFaceRectLineWidth, SetFaceRectLineWidth, VT_I2, VTS_R4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetFaceRectLineWidth", dispidGetFaceRectLineWidth, GetFaceRectLineWidth, VT_I4, VTS_PR4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetEyeRectLineWidth", dispidSetEyeRectLineWidth, SetEyeRectLineWidth, VT_I2, VTS_R4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetEyeRectLineWidth", dispidGetEyeRectLineWidth, GetEyeRectLineWidth, VT_I4, VTS_PR4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetEvent", dispidGetEvent, GetEvent, VT_I2, VTS_PI4 VTS_PI4 VTS_PI4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "DeleteSegment", dispidDeleteSegment, DeleteSegment, VT_I4, VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOverlayImgPosition", dispidSetOverlayImgPosition, SetOverlayImgPosition, VT_I2, VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I2 VTS_I2 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOverlayFontName", dispidSetOverlayFontName, SetOverlayFontName, VT_I2, VTS_I4 VTS_BSTR)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "DisplayOverlay", dispidDisplayOverlay, DisplayOverlay, VT_I2, VTS_I4 VTS_I2)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOverlayPosition", dispidSetOverlayPosition, SetOverlayPosition, VT_I2, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOverlayColor", dispidSetOverlayColor, SetOverlayColor, VT_I2, VTS_I4 VTS_COLOR)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOverlayFontSize", dispidSetOverlayFontSize, SetOverlayFontSize, VT_I2, VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOverlayFont", dispidSetOverlayFont, SetOverlayFont, VT_I2, VTS_I4 VTS_I4 VTS_I2 VTS_I2 VTS_I2 VTS_I2)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetOverlayText", dispidSetOverlayText, SetOverlayText, VT_I2, VTS_I4 VTS_BSTR)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetCountOfArray", dispidGetCountOfArray, GetCountOfArray, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "Free", dispidFree, Free, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetCurrentPositionByFrame", dispidSetCurrentPositionByFrame, SetCurrentPositionByFrame, VT_I2, VTS_I8)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetFps", dispidGetFps, GetFps, VT_R8, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetFps", dispidSetFps, SetFps, VT_EMPTY, VTS_R8)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "OpenVideo1", dispidOpenVideo1, OpenVideo1, VT_I4, VTS_BSTR VTS_I4)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "GetVideoEvent", dispidGetVideoEvent, GetVideoEvent, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetSelect", dispidSetSelect, SetSelect, VT_I2, VTS_I2)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetEmbedded", dispidSetEmbedded, SetEmbedded, VT_I2, VTS_I2)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "IsEmbedded", dispidIsEmbedded, IsEmbedded, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "IsSelected", dispidIsSelected, IsSelected, VT_I2, VTS_NONE)
	DISP_FUNCTION_ID(CJbuVideoPlayerCtrl, "SetParentLong", dispidSetParentLong, SetParentLong, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()





BEGIN_EVENT_MAP(CJbuVideoPlayerCtrl, COleControl)
END_EVENT_MAP()






BEGIN_PROPPAGEIDS(CJbuVideoPlayerCtrl, 1)
	PROPPAGEID(CJbuVideoPlayerPropPage::guid)
END_PROPPAGEIDS(CJbuVideoPlayerCtrl)





IMPLEMENT_OLECREATE_EX(CJbuVideoPlayerCtrl, "JBUVIDEOPLAYER.JbuVideoPlayerCtrl.1",
	0xc1aa0568, 0xb4d4, 0x4e0e, 0xae, 0x6e, 0x10, 0x81, 0xe8, 0x75, 0x6f, 0xcf)





IMPLEMENT_OLETYPELIB(CJbuVideoPlayerCtrl, _tlid, _wVerMajor, _wVerMinor)





const IID IID_DJbuVideoPlayer = { 0x855D40DF, 0xC6CF, 0x4970, { 0xB0, 0xA9, 0x35, 0xD4, 0xC4, 0x5B, 0x7F, 0xA7 } };
const IID IID_DJbuVideoPlayerEvents = { 0x827254BE, 0xC48B, 0x4E39, { 0xBC, 0x60, 0x8E, 0x9D, 0xCD, 0x13, 0xE5, 0x44 } };




static const DWORD _dwJbuVideoPlayerOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CJbuVideoPlayerCtrl, IDS_JBUVIDEOPLAYER, _dwJbuVideoPlayerOleMisc)



BOOL CJbuVideoPlayerCtrl::CJbuVideoPlayerCtrlFactory::UpdateRegistry(BOOL bRegister)
{

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_JBUVIDEOPLAYER,
			IDB_JBUVIDEOPLAYER,
			afxRegApartmentThreading,
			_dwJbuVideoPlayerOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


CJbuVideoPlayerCtrl::CJbuVideoPlayerCtrl()
{
	InitializeIIDs(&IID_DJbuVideoPlayer, &IID_DJbuVideoPlayerEvents);
	m_bHasVideo = FALSE;
	m_pParent = NULL;
	m_pDesktopWnd = NULL;
	m_bFullScreen = FALSE;
	m_hWndParent = NULL;
	m_PrevTemplateID = -1;
	m_bFirsttimeFullScreen = TRUE;
	m_TemplateID = Jbu_Template_NoToolbar;
	m_nIndex = 0;
	memset(&m_lf, 0, sizeof(LOGFONT));       // zero out structure
	m_lf.lfHeight = 26;                      // request a 12-pixel-height font
	_stprintf_s(m_lf.lfFaceName, _T("%s"), _T("Arial"));   
	m_systemColor = RGB(246, 246, 246);
	m_pPlayer = NULL;
	HRESULT hr = CoCreateInstance(CLSID_FcsPlayer, 
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IFcsPlayer,
		(void **)&m_pPlayer);	// call DragAcceptFiles only if there's a suffix
	if (hr != S_OK)
	{
		AfxMessageBox(_T("ero"));
	}

	m_bSelected = FALSE;
}





CJbuVideoPlayerCtrl::~CJbuVideoPlayerCtrl()
{

}





void CJbuVideoPlayerCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	if (m_pPlayer == NULL)
		return;
	m_pPlayer->HasVideo(&m_bHasVideo);
	if (!m_bHasVideo)
		return;
	CRect rt;
	GetClientRect(&rt);
	m_pPlayer->UpdateVideoWindow(&rt);
	m_pPlayer->ReFresh();

}





void CJbuVideoPlayerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);


}




void CJbuVideoPlayerCtrl::OnResetState()
{
	COleControl::OnResetState();  

}


void CJbuVideoPlayerCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_JBUVIDEOPLAYER);
	dlgAbout.DoModal();
}





int CJbuVideoPlayerCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}


void CJbuVideoPlayerCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
		if (m_pPlayer == NULL)
			return;

	if (cx >0 && cy > 0)
	{
		CRect rect;
		GetClientRect(&rect);
		m_pPlayer->UpdateVideoWindow(&rect);
		if (!m_bFullScreen)
		{

		}
	}
}


LONG CJbuVideoPlayerCtrl::OpenVideo(LPCTSTR bstrFileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	CString szPathname = CString(bstrFileName);
	BSTR sFile = szPathname.AllocSysString();
	hr = m_pPlayer->Open(sFile, -1, 0);
	if (SUCCEEDED(hr))
		hr = m_pPlayer->SetWindow(this->GetSafeHwnd());
	if (SUCCEEDED(hr))
		hr = m_pPlayer->Play();
	if (SUCCEEDED(hr))
		hr = m_pPlayer->Pause();
	SysFreeString(sFile);
	return hr;
}


LONG CJbuVideoPlayerCtrl::SetGraphPath(LPCTSTR bstrPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	CString szPathname = CString(bstrPath);
	BSTR sFile = szPathname.AllocSysString();
	m_pPlayer->SetGraphPath(sFile);
	SysFreeString(sFile);
	return S_OK;

}


SHORT CJbuVideoPlayerCtrl::HasVideo(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	SHORT hr = 0;
	BOOL b;
	if (m_pPlayer != NULL)
	{
		m_pPlayer->HasVideo(&b);
	}
	hr = b;
	return hr;
}


LONG CJbuVideoPlayerCtrl::Play(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	BOOL hr = 0;
	HRESULT hr1 = S_FALSE;
	m_pPlayer->HasVideo(&hr);
	if (hr)
	{
		hr1 = m_pPlayer->Play();
	}			
	if (hr1 == S_OK)
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::Stop(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	BOOL hr = 0;
	HRESULT hr1 = S_FALSE;
	m_pPlayer->HasVideo(&hr);
	if (hr)
	{
		hr1 = m_pPlayer->Stop();
	}			
	if (hr1 == S_OK)
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::Pause(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	BOOL hr = 0;
	HRESULT hr1 = S_FALSE;
	m_pPlayer->HasVideo(&hr);
	if (hr)
	{
		hr1 = m_pPlayer->Pause();
	}			
	if (hr1 == S_OK)
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::StepFwd(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	long nLength;
	HRESULT hr;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	hr = m_pPlayer->MP_GetLength(&nLength);
	if (m_nIndex == nLength -1)
		return JBU_FALSE;
	else
		m_nIndex++;
	if (SUCCEEDED(hr))
		 hr = m_pPlayer->MP_Seek(m_nIndex);
	if (SUCCEEDED(hr))
		return TRUE;
	else
		return FALSE;
}


LONG CJbuVideoPlayerCtrl::StepRew(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	if (m_nIndex == 0)
		return JBU_FALSE;
	else
		m_nIndex--;
	hr = m_pPlayer->MP_Seek(m_nIndex);
	if (SUCCEEDED(hr))
		return TRUE;
	else
		return FALSE;
}


LONG CJbuVideoPlayerCtrl::SecondFwd(LONG nSecond)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	long nLength;
	HRESULT hr;
	double dFps;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	hr = m_pPlayer->MP_GetLength(&nLength);
	if (SUCCEEDED(hr))
		hr = m_pPlayer->GetFps(&dFps);
	if (SUCCEEDED(hr))
	{
		m_nIndex = m_nIndex + (long)dFps * nSecond;
		if (m_nIndex >= nLength -1)
			m_nIndex = nLength -1;
		hr = m_pPlayer->MP_Seek(m_nIndex);
	}
	return (LONG)hr;
}


LONG CJbuVideoPlayerCtrl::SecondRew(LONG nSecond)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	long nLength;
	HRESULT hr;
	double dFps;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	hr = m_pPlayer->MP_GetLength(&nLength);
	if (SUCCEEDED(hr))
		hr = m_pPlayer->GetFps(&dFps);
	if (SUCCEEDED(hr))
	{
		m_nIndex = m_nIndex - (long)dFps *nSecond;
		if (m_nIndex <=0)
			m_nIndex = 0;
		hr = m_pPlayer->MP_Seek(m_nIndex);
	}
	return (LONG)hr;
}


LONG CJbuVideoPlayerCtrl::SetVolume(LONG dAmount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	BOOL bHasVideo = 0;
	HRESULT hr = S_FALSE;
	LONG nVolume = 0;
	if (dAmount < 0 || dAmount > 10000)
		nVolume = -5000;
	else
		nVolume = dAmount - 10000;
	hr = m_pPlayer->HasVideo(&bHasVideo);
	if (SUCCEEDED(hr) && bHasVideo)
		hr = m_pPlayer->SetVolume(nVolume);
	return (LONG)hr;
}

LONG CJbuVideoPlayerCtrl::GetCurPosByFrame(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	long n = 0;
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->MP_GetPosition(&n);
	return n;
}

LONG CJbuVideoPlayerCtrl::GetVideoWidth(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	LONG nWidth;
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->GetVideoInfo(&nWidth, NULL, NULL);
	return nWidth;
}


LONG CJbuVideoPlayerCtrl::GetVideoHeight(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	LONG nHeight;
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->GetVideoInfo(NULL, &nHeight, NULL);
	return nHeight;
}

LONG CJbuVideoPlayerCtrl::Mute(LONG bMute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = S_OK;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	hr = m_pPlayer->Mute((BOOL)bMute);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}

LONG CJbuVideoPlayerCtrl::GetSegmentCount(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONG nSize = m_segment_array.GetSize();
	return nSize;
}


LONG CJbuVideoPlayerCtrl::SetDefaultSegment(LONG nIndex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_nDefaultSegmentId = nIndex;
	return S_OK;
}
BOOL CJbuVideoPlayerCtrl::IsAvailable(long nPos)
{
	long nCount = m_segment_array.GetSize();
	for (long i = 0; i <nCount; i++)
	{
		CRmfSegment* pSegment = m_segment_array.GetAt(i);
		if (nPos >= pSegment->m_nInPoint && nPos <= pSegment->m_nOutPoint)
			return FALSE;
	}
	return TRUE;
}
LONG CJbuVideoPlayerCtrl::SetInPoint(LONG nPos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	long length;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->MP_GetLength(&length);
	if (SUCCEEDED(hr))
	{
		if (nPos < 0 || nPos >= (length -1))
			return JBU_FALSE;
		if (!IsAvailable(nPos))
			return JBU_FALSE;
		m_nInPoint = nPos;
	}
	return JBU_OK;
}


LONG CJbuVideoPlayerCtrl::SetOutPoint(LONG nPos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	long length;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->MP_GetLength(&length);
	if (SUCCEEDED(hr))
	{
		if (nPos < 0 || nPos >= (length -1))
			return JBU_FALSE;
		if (!IsAvailable(nPos))
			return JBU_FALSE;
		if (nPos < m_nInPoint)
			return JBU_FALSE;
		m_nOutPoint = nPos;
	}
	return JBU_OK;
}

LONG CJbuVideoPlayerCtrl::SetSegment(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_nInPoint == 0 || m_nOutPoint == 0)
		return -1;
	long nCount = m_segment_array.GetSize();
	CRmfSegment* pSegment = new CRmfSegment;
	pSegment->m_nId = nCount;
	pSegment->m_nInPoint = m_nInPoint;
	pSegment->m_nOutPoint = m_nOutPoint;
	m_segment_array.Add(pSegment);
	return (nCount+1);
}
LONG CJbuVideoPlayerCtrl::GetInPointByFrame(LONG nSegmentID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	long nSize = m_segment_array.GetSize();
	if (nSegmentID < 0 || nSegmentID > nSize -1)
		return -1;
	CRmfSegment* pSegment = m_segment_array.GetAt(nSegmentID);
	long n = pSegment->m_nInPoint;
	return n;

}
LONG CJbuVideoPlayerCtrl::Open()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	return S_OK;
}

LONG CJbuVideoPlayerCtrl::GetOutPointByFrame(LONG nSegmentID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	long nSize = m_segment_array.GetSize();
	if (nSegmentID < 0 || nSegmentID > nSize -1)
		return -1;
	CRmfSegment* pSegment = m_segment_array.GetAt(nSegmentID);
	long n = pSegment->m_nOutPoint;
	return n;
}

BSTR CJbuVideoPlayerCtrl::GetInTcCode(LONG nSegmentID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	LONG nPos = GetInPointByFrame(nSegmentID);

	LONGLONG timeNow;
	BSTR bstrTime = _T("");
	HRESULT hr = m_pPlayer->FrameToRefTime(nPos, &timeNow);
	hr = m_pPlayer->GetTcCode(timeNow, &bstrTime);
	return bstrTime;
}

BSTR CJbuVideoPlayerCtrl::GetOutTcCode(LONG nSegmentID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	LONG nPos = GetOutPointByFrame(nSegmentID);

	LONGLONG timeNow;
	BSTR bstrTime = _T("");
	HRESULT hr = m_pPlayer->FrameToRefTime(nPos, &timeNow);
	hr = m_pPlayer->GetTcCode(timeNow, &bstrTime);

	return bstrTime;
}

BSTR CJbuVideoPlayerCtrl::GetCurPosTcString(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	BSTR bstr = _T("");
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetCurrentTimeString(&bstr);
	return bstr;
}

LONG CJbuVideoPlayerCtrl::FullScreen(SHORT nState)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (nState != 0 && nState != 1)
		return FALSE;
	m_bFullScreen = (BOOL) nState;
	CWnd* pParent = GetParent();
	if (m_bFullScreen)
	{
		if (m_bFirsttimeFullScreen)
		{
			m_pParent = GetParent();
			m_pParent->GetClientRect(&m_rtParent);
			m_bFirsttimeFullScreen = FALSE;
		}
	}
	CRect rt;
	BOOL hr;
	if (m_bFullScreen)
	{
		int cx = ::GetSystemMetrics(SM_CXSCREEN);
		int cy = ::GetSystemMetrics(SM_CYSCREEN);
		SetParent(GetDesktopWindow());
		rt = CRect(0,0, cx,cy);
		SetRectInContainer(&rt);
		hr = SetWindowPos(&CWnd::wndTopMost,0,0, cx, cy, SWP_SHOWWINDOW);
	}
	else
	{
		SetParent(m_pParent);
		hr = SetRectInContainer(&m_rtParent);
		hr = SetWindowPos(&CWnd::wndTopMost,m_rtParent.left, m_rtParent.top, m_rtParent.right, m_rtParent.bottom, SWP_SHOWWINDOW);
	}
	return TRUE;
}
LONGLONG CJbuVideoPlayerCtrl::GetCurPosByMSec(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONGLONG timeNow = 0;
	LONGLONG timeInMsec = 0;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	BSTR bstr = _T("");
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
	{
		m_pPlayer->GetCurrentPosition(&timeNow);
		timeInMsec = timeNow / ONE_MSEC;
	}
	return timeInMsec;
}


LONG CJbuVideoPlayerCtrl::GetStatus(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	UINT nStatus = STATE_CLOSED;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->State(&nStatus);
	return nStatus;
}

DOUBLE CJbuVideoPlayerCtrl::GetVideoFps(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	double dFps;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		dFps = m_pPlayer->GetVideoInfo(NULL, NULL, &dFps);
	return dFps;
}

LONG CJbuVideoPlayerCtrl::GetLengthByFrame(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONG nLength = 0;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->MP_GetLength(&nLength);
	return nLength;
}

LONGLONG CJbuVideoPlayerCtrl::GetLengthByMSec(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONGLONG nDuration = 0;
	LONGLONG timeInMsec = 0;

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
	{
		m_pPlayer->GetDuration(&nDuration);
		timeInMsec = nDuration / ONE_MSEC;
	}
	return timeInMsec;
}
DOUBLE CJbuVideoPlayerCtrl::GetVolume(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LONG nVolume = 0;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->GetVolume(&nVolume);
	return (DOUBLE)nVolume;
}


SHORT CJbuVideoPlayerCtrl::IsMute(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BOOL bMuted= 0;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->IsMuted(&bMuted);
	return bMuted;
}


LONG CJbuVideoPlayerCtrl::SnapShot(LPCTSTR bstrImageName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LONG nIndex = 0;
	BSTR bstrImage;
	CString str = CString(bstrImageName);
	bstrImage = str.AllocSysString();
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
	{
		m_pPlayer->MP_GetPosition(&nIndex);
		m_pPlayer->snapImage(nIndex, bstrImage);
	}
	SysFreeString(bstrImage);
	return S_OK;
}


DOUBLE CJbuVideoPlayerCtrl::GetVuMeter(SHORT nChannel)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	return 0;
}


LONG CJbuVideoPlayerCtrl::PlaySegment(LONG nSegmentID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	long nSegCount  = m_segment_array.GetSize();
	if (nSegmentID < 0 || nSegmentID >(nSegCount -1))
		return JBU_FALSE;
	CRmfSegment* pSegment = m_segment_array.GetAt(nSegmentID);
	long nStart = pSegment->m_nInPoint;
	long nEnd  = pSegment->m_nOutPoint;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->Stop();
	if (SUCCEEDED(hr))
		hr = m_pPlayer->SetSegment(nStart, nEnd);
	if (SUCCEEDED(hr))
		hr = m_pPlayer->Play();
	return (LONG)hr;
}

SHORT CJbuVideoPlayerCtrl::SetPositionByFrame(LONG nBeginFrame, LONG nEndFrame)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	long nLength;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->MP_GetLength(&nLength);
	if (nEndFrame != -1 && nEndFrame < nBeginFrame )
	{
		return JBU_FALSE;
	}
	if (nBeginFrame > nLength && hr == S_OK)
	{
		return JBU_OK;
	}
	if (nEndFrame == -1)
		nEndFrame = nLength;

	if (SUCCEEDED(hr))
		hr = m_pPlayer->SetSegment(nBeginFrame, nEndFrame);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::SetPositionByMs(LONGLONG nStartTime, LONGLONG nStopTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetSegmentByMs(nStartTime, nStopTime);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


BSTR CJbuVideoPlayerCtrl::GetVideoName(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return m_szVideoName.AllocSysString();
}


void CJbuVideoPlayerCtrl::OnTemplateIDChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_PrevTemplateID == m_TemplateID)
		return;
	m_PrevTemplateID = m_TemplateID;

}


void CJbuVideoPlayerCtrl::OnGraphPathChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	SetModifiedFlag();
}


LONG CJbuVideoPlayerCtrl::GetFaceRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetFaceRect(left, top, right, bottom);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetFaceWidth(LONG* nWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetFaceWidth(nWidth);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetFaceHeight(LONG* nHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetFaceHeight(nHeight);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetLEyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetLEyeRect(left, top, right, bottom);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetREyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetREyeRect(left, top, right, bottom);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetREyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetREyeballRect(left, top, right, bottom);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetLEyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetLEyeballRect(left, top, right, bottom);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetFaceImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetFaceImg(pImage, nSize);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetLEyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetLEyeImg(pImage, nSize);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetREyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetREyeImg(pImage, nSize);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetLEyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetLEyeballImg(pImage, nSize);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetREyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetREyeballImg(pImage, nSize);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetLeadFace(BYTE* pLeadFace)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetLeadFace(pLeadFace);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetActivativedValue(DOUBLE* dActivation)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetActivativedValue(dActivation);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetBlinkCount(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONG nCount = 0;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetBlinkCount(&nCount);
	if (SUCCEEDED(hr))
		return nCount;
	else
		return 0;
}


LONG CJbuVideoPlayerCtrl::GetCurTimeMs(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONG nTime;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetCurTimeMs(&nTime);
	if (SUCCEEDED(hr))
		return nTime;
	else
		return 0;
}


LONGLONG CJbuVideoPlayerCtrl::GetCurTime(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	LONGLONG nTime;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetCurTime(&nTime);
	if (SUCCEEDED(hr))
		return nTime;
	else
		return 0;
}


SHORT CJbuVideoPlayerCtrl::ResetCounter(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->ResetCounter();
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::SetCheck(SHORT nCheck)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetCheck(nCheck);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::GetCheck(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	SHORT nCheck;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetCheck(&nCheck);
	return nCheck;
}


SHORT CJbuVideoPlayerCtrl::SetFaceRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetFaceRectLineWidth(fLineWidth);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetFaceRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetFaceRectLineWidth(fLineWidth);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::SetEyeRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetEyeRectLineWidth(fLineWidth);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


LONG CJbuVideoPlayerCtrl::GetEyeRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetEyeRectLineWidth(fLineWidth);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::GetEvent(LONG* evCode, LONG* L1, LONG* L2)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetEvent(evCode, L1, L2);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}

LONG CJbuVideoPlayerCtrl::DeleteSegment(LONG nSegmentID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		m_pPlayer->Stop();
	CRmfSegment* pSegment = m_segment_array.GetAt(nSegmentID);
	delete pSegment;
	m_segment_array.RemoveAt(nSegmentID);
	long nCount  = m_segment_array.GetSize();
	if (nCount != 0)
		SetDefaultSegment(0);
	//ÐÞ¸ÄID
	for (long i = 0; i < nCount; i++)
	{
		pSegment = m_segment_array.GetAt(i);
		pSegment->m_nId = i;
		m_segment_array.SetAt(i, pSegment);
	}
	return JBU_OK;
}


SHORT CJbuVideoPlayerCtrl::SetOverlayImgPosition(LPCTSTR szImgName, LONG nLeft, LONG nTop, LONG nRight, LONG nBottom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString str = CString(szImgName);
	BSTR sImgName = str.AllocSysString();

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetOverlayImgPosition(sImgName,nLeft,nTop,nRight,nBottom,bDisplay,bScaleFit,nTranspency);
	SysFreeString(sImgName);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::SetOverlayFontName(LONG nID, LPCTSTR szFontName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString str = CString(szFontName);
	BSTR szTempFontName = str.AllocSysString();
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetOverlayFontName(nID,szTempFontName);
	SysFreeString(szTempFontName);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::DisplayOverlay(LONG nID, SHORT bIsDisplay)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->DisplayOverlay(nID,bIsDisplay);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}

SHORT CJbuVideoPlayerCtrl::SetOverlayPosition(LONG nID, LONG nLeft, LONG nTop, LONG nRight, LONG nBottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetOverlayPosition(nID,nLeft,nTop,nRight,nBottom);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}

SHORT CJbuVideoPlayerCtrl::SetOverlayColor(LONG nID, OLE_COLOR nColor)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetOverlayColor(nID,nColor);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::SetOverlayFontSize(LONG nID, LONG nFontSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetOverlayFontSize(nID,nFontSize);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::SetOverlayFont(LONG nID, LONG nFontStyle, SHORT bUnderLine, SHORT bWrap, SHORT bVertical, SHORT bRightAlign)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetOverlayFont(nID,nFontStyle,bUnderLine,bWrap,bVertical,bRightAlign);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::SetOverlayText(LONG nID, LPCTSTR szText)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString str = CString(szText);
	BSTR sTempText = str.AllocSysString();
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetOverlayText(nID,sTempText);
	SysFreeString(sTempText);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


SHORT CJbuVideoPlayerCtrl::GetCountOfArray(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return -1;
}


void CJbuVideoPlayerCtrl::Free(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->Free();
}


SHORT CJbuVideoPlayerCtrl::SetCurrentPositionByFrame(LONGLONG nCurrentFrame)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->MP_Seek(nCurrentFrame);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}


DOUBLE CJbuVideoPlayerCtrl::GetFps(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	double dFps = 0.0;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetFps(&dFps);
	return dFps;
}


void CJbuVideoPlayerCtrl::SetFps(DOUBLE dFps)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->SetFps(dFps);
}


LONG CJbuVideoPlayerCtrl::OpenVideo1(LPCTSTR VideoName, LONG GraphID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	CString szPathName = CString(VideoName);
	BSTR sFile = szPathName.AllocSysString();
	HWND hWnd = GetSafeHwnd();
	hr = m_pPlayer->SetWindow(hWnd);
	hr = m_pPlayer->Open(sFile, GraphID, 0);
	if (SUCCEEDED(hr))
	{
		hr =  m_pPlayer->Play();
		hr =  m_pPlayer->Pause();
	}
	CRect rect;
	GetClientRect(&rect);
	hr = m_pPlayer->UpdateVideoWindow(&rect);
	if (SUCCEEDED(hr))
		return TRUE;
	else
		return FALSE;
}


SHORT CJbuVideoPlayerCtrl::GetVideoEvent(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	long evCode, l1,l2;
	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
		hr = m_pPlayer->GetEvent(&evCode, &l1, &l2);
	return (SHORT)evCode;
}


void CJbuVideoPlayerCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (!m_bEmbedded)
		return;
	m_bSelected = TRUE;
	::SendMessage(m_hWndParent, WM_LBUTTONDOWN, NULL, NULL);
	Invalidate();
	COleControl::OnLButtonDown(nFlags, point);
}


SHORT CJbuVideoPlayerCtrl::SetSelect(SHORT bSelected)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_bSelected = bSelected;
	return 0;
}


SHORT CJbuVideoPlayerCtrl::SetEmbedded(SHORT bEmbedded)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_bEmbedded = bEmbedded;

	return 0;
}


SHORT CJbuVideoPlayerCtrl::IsEmbedded(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return m_bEmbedded;
}


SHORT CJbuVideoPlayerCtrl::IsSelected(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return m_bSelected;
}


void CJbuVideoPlayerCtrl::SetParentLong(LONG Parent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_hWndParent = (HWND)Parent;
}
LONG CJbuVideoPlayerCtrl::SetRate(DOUBLE dRate)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CJbuVideoPlayerApp* pApp = (CJbuVideoPlayerApp*)AfxGetApp();
	HRESULT hr = m_pPlayer->HasVideo(&m_bHasVideo);
	if (SUCCEEDED(hr) && m_bHasVideo)
			hr = m_pPlayer->SetRate(dRate);
	if (SUCCEEDED(hr))
		return JBU_OK;
	else
		return JBU_FALSE;
}