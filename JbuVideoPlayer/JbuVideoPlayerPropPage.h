#pragma once

class CJbuVideoPlayerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CJbuVideoPlayerPropPage)
	DECLARE_OLECREATE_EX(CJbuVideoPlayerPropPage)


public:
	CJbuVideoPlayerPropPage();


	enum { IDD = IDD_PROPPAGE_JBUVIDEOPLAYER };


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    


protected:
	DECLARE_MESSAGE_MAP()
};

