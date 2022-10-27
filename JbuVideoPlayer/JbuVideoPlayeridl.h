

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Oct 27 16:04:39 2022
 */
/* Compiler settings for JbuVideoPlayer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __JbuVideoPlayeridl_h__
#define __JbuVideoPlayeridl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DJbuVideoPlayer_FWD_DEFINED__
#define ___DJbuVideoPlayer_FWD_DEFINED__
typedef interface _DJbuVideoPlayer _DJbuVideoPlayer;

#endif 	/* ___DJbuVideoPlayer_FWD_DEFINED__ */


#ifndef ___DJbuVideoPlayerEvents_FWD_DEFINED__
#define ___DJbuVideoPlayerEvents_FWD_DEFINED__
typedef interface _DJbuVideoPlayerEvents _DJbuVideoPlayerEvents;

#endif 	/* ___DJbuVideoPlayerEvents_FWD_DEFINED__ */


#ifndef __JbuVideoPlayer_FWD_DEFINED__
#define __JbuVideoPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class JbuVideoPlayer JbuVideoPlayer;
#else
typedef struct JbuVideoPlayer JbuVideoPlayer;
#endif /* __cplusplus */

#endif 	/* __JbuVideoPlayer_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_JbuVideoPlayer_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_JbuVideoPlayer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_JbuVideoPlayer_0000_0000_v0_0_s_ifspec;


#ifndef __JbuVideoPlayerLib_LIBRARY_DEFINED__
#define __JbuVideoPlayerLib_LIBRARY_DEFINED__

/* library JbuVideoPlayerLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_JbuVideoPlayerLib;

#ifndef ___DJbuVideoPlayer_DISPINTERFACE_DEFINED__
#define ___DJbuVideoPlayer_DISPINTERFACE_DEFINED__

/* dispinterface _DJbuVideoPlayer */
/* [uuid] */ 


EXTERN_C const IID DIID__DJbuVideoPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("855D40DF-C6CF-4970-B0A9-35D4C45B7FA7")
    _DJbuVideoPlayer : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DJbuVideoPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DJbuVideoPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DJbuVideoPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DJbuVideoPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DJbuVideoPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DJbuVideoPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DJbuVideoPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DJbuVideoPlayer * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DJbuVideoPlayerVtbl;

    interface _DJbuVideoPlayer
    {
        CONST_VTBL struct _DJbuVideoPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DJbuVideoPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DJbuVideoPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DJbuVideoPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DJbuVideoPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DJbuVideoPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DJbuVideoPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DJbuVideoPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DJbuVideoPlayer_DISPINTERFACE_DEFINED__ */


#ifndef ___DJbuVideoPlayerEvents_DISPINTERFACE_DEFINED__
#define ___DJbuVideoPlayerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DJbuVideoPlayerEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DJbuVideoPlayerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("827254BE-C48B-4E39-BC60-8E9DCD13E544")
    _DJbuVideoPlayerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DJbuVideoPlayerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DJbuVideoPlayerEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DJbuVideoPlayerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DJbuVideoPlayerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DJbuVideoPlayerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DJbuVideoPlayerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DJbuVideoPlayerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DJbuVideoPlayerEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DJbuVideoPlayerEventsVtbl;

    interface _DJbuVideoPlayerEvents
    {
        CONST_VTBL struct _DJbuVideoPlayerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DJbuVideoPlayerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DJbuVideoPlayerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DJbuVideoPlayerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DJbuVideoPlayerEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DJbuVideoPlayerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DJbuVideoPlayerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DJbuVideoPlayerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DJbuVideoPlayerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_JbuVideoPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("C1AA0568-B4D4-4E0E-AE6E-1081E8756FCF")
JbuVideoPlayer;
#endif
#endif /* __JbuVideoPlayerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


