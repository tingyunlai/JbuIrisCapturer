
#include "stdafx.h"
#include "JbuVideoPlayer.h"
#include "JbuVideoPlayerPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CJbuVideoPlayerPropPage, COlePropertyPage)





BEGIN_MESSAGE_MAP(CJbuVideoPlayerPropPage, COlePropertyPage)
END_MESSAGE_MAP()


IMPLEMENT_OLECREATE_EX(CJbuVideoPlayerPropPage, "JBUVIDEOPLAYER.JbuVideoPlayerPropPage.1",
	0xd0e8e4a, 0x3a71, 0x4d8f, 0xa1, 0x37, 0x3d, 0xbf, 0x8b, 0x72, 0x93, 0x7e)


BOOL CJbuVideoPlayerPropPage::CJbuVideoPlayerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_JBUVIDEOPLAYER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


CJbuVideoPlayerPropPage::CJbuVideoPlayerPropPage() :
	COlePropertyPage(IDD, IDS_JBUVIDEOPLAYER_PPG_CAPTION)
{
}


void CJbuVideoPlayerPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

