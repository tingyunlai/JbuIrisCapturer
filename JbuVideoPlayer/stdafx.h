#pragma once



#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      
#define _ATL_NO_AUTOMATIC_NAMESPACE            

#include <afxctl.h>         
#include <afxext.h>         
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     
#endif // _AFX_NO_AFXCMN_SUPPORT


#ifndef _WIN64

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                     
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     
#endif // _AFX_NO_DAO_SUPPORT

#endif // _WIN64
#include <afxcontrolbars.h>
#include <afxwin.h>
#include "jbuvar.h"
void Delay(float dSecond);

