

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_JbuVideoPlayerLib,0xBAD43083,0x3C24,0x4210,0x95,0x93,0x5D,0xBA,0x55,0xE7,0xA3,0x66);


MIDL_DEFINE_GUID(IID, DIID__DJbuVideoPlayer,0x855D40DF,0xC6CF,0x4970,0xB0,0xA9,0x35,0xD4,0xC4,0x5B,0x7F,0xA7);


MIDL_DEFINE_GUID(IID, DIID__DJbuVideoPlayerEvents,0x827254BE,0xC48B,0x4E39,0xBC,0x60,0x8E,0x9D,0xCD,0x13,0xE5,0x44);


MIDL_DEFINE_GUID(CLSID, CLSID_JbuVideoPlayer,0xC1AA0568,0xB4D4,0x4E0E,0xAE,0x6E,0x10,0x81,0xE8,0x75,0x6F,0xCF);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



