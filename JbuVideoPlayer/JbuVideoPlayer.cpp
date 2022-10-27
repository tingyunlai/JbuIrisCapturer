

#include "stdafx.h"
#include "JbuVideoPlayer.h"
#include "Fcsmedia_i.c"
#include <initguid.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CJbuVideoPlayerApp theApp;

const GUID CDECL _tlid = { 0xBAD43083, 0x3C24, 0x4210, { 0x95, 0x93, 0x5D, 0xBA, 0x55, 0xE7, 0xA3, 0x66 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CJbuVideoPlayerApp::InitInstance -

BOOL CJbuVideoPlayerApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();
	return bInit;
}



// CJbuVideoPlayerApp::ExitInstance

int CJbuVideoPlayerApp::ExitInstance()
{

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
