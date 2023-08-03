

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for OutOfProcessCOMServer.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __OutOfProcessCOMServer_i_h__
#define __OutOfProcessCOMServer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IMouse_FWD_DEFINED__
#define __IMouse_FWD_DEFINED__
typedef interface IMouse IMouse;

#endif 	/* __IMouse_FWD_DEFINED__ */


#ifndef __IKeyboard_FWD_DEFINED__
#define __IKeyboard_FWD_DEFINED__
typedef interface IKeyboard IKeyboard;

#endif 	/* __IKeyboard_FWD_DEFINED__ */


#ifndef __Mouse_FWD_DEFINED__
#define __Mouse_FWD_DEFINED__

#ifdef __cplusplus
typedef class Mouse Mouse;
#else
typedef struct Mouse Mouse;
#endif /* __cplusplus */

#endif 	/* __Mouse_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMouse_INTERFACE_DEFINED__
#define __IMouse_INTERFACE_DEFINED__

/* interface IMouse */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMouse;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f18d5855-7d92-4aed-ada7-87d1a9595377")
    IMouse : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE click( 
            BSTR buttonName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE scroll( 
            LONG amount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMouseVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMouse * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMouse * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMouse * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMouse * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMouse * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMouse * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMouse * This,
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
        
        DECLSPEC_XFGVIRT(IMouse, click)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *click )( 
            IMouse * This,
            BSTR buttonName);
        
        DECLSPEC_XFGVIRT(IMouse, scroll)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *scroll )( 
            IMouse * This,
            LONG amount);
        
        END_INTERFACE
    } IMouseVtbl;

    interface IMouse
    {
        CONST_VTBL struct IMouseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMouse_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMouse_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMouse_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMouse_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMouse_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMouse_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMouse_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMouse_click(This,buttonName)	\
    ( (This)->lpVtbl -> click(This,buttonName) ) 

#define IMouse_scroll(This,amount)	\
    ( (This)->lpVtbl -> scroll(This,amount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMouse_INTERFACE_DEFINED__ */


#ifndef __IKeyboard_INTERFACE_DEFINED__
#define __IKeyboard_INTERFACE_DEFINED__

/* interface IKeyboard */
/* [object][nonextensible][uuid] */ 


EXTERN_C const IID IID_IKeyboard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5790d466-f696-470f-a9f0-707d483e5d13")
    IKeyboard : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE pressKey( 
            LPCWSTR keyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE releaseKey( 
            LPCWSTR keyName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IKeyboardVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKeyboard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKeyboard * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKeyboard * This);
        
        DECLSPEC_XFGVIRT(IKeyboard, pressKey)
        HRESULT ( STDMETHODCALLTYPE *pressKey )( 
            IKeyboard * This,
            LPCWSTR keyName);
        
        DECLSPEC_XFGVIRT(IKeyboard, releaseKey)
        HRESULT ( STDMETHODCALLTYPE *releaseKey )( 
            IKeyboard * This,
            LPCWSTR keyName);
        
        END_INTERFACE
    } IKeyboardVtbl;

    interface IKeyboard
    {
        CONST_VTBL struct IKeyboardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKeyboard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKeyboard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKeyboard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKeyboard_pressKey(This,keyName)	\
    ( (This)->lpVtbl -> pressKey(This,keyName) ) 

#define IKeyboard_releaseKey(This,keyName)	\
    ( (This)->lpVtbl -> releaseKey(This,keyName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IKeyboard_INTERFACE_DEFINED__ */



#ifndef __OutOfProcessCOMServerLib_LIBRARY_DEFINED__
#define __OutOfProcessCOMServerLib_LIBRARY_DEFINED__

/* library OutOfProcessCOMServerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_OutOfProcessCOMServerLib;

EXTERN_C const CLSID CLSID_Mouse;

#ifdef __cplusplus

class DECLSPEC_UUID("3eb17078-42bb-425f-adaa-e050e6b3add4")
Mouse;
#endif
#endif /* __OutOfProcessCOMServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


