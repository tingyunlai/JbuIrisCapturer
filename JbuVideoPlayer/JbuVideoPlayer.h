#pragma once



#if !defined( __AFXCTL_H__ )
#error "¡°afxctl.h¡±"
#endif

#include "resource.h"      
using namespace ATL;


class CJbuVideoPlayerApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

