

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for DeskInfo.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
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


#ifndef __DeskInfo_h_h__
#define __DeskInfo_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDeskInfo_FWD_DEFINED__
#define __IDeskInfo_FWD_DEFINED__
typedef interface IDeskInfo IDeskInfo;

#endif 	/* __IDeskInfo_FWD_DEFINED__ */


#ifndef __DeskInfo_FWD_DEFINED__
#define __DeskInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class DeskInfo DeskInfo;
#else
typedef struct DeskInfo DeskInfo;
#endif /* __cplusplus */

#endif 	/* __DeskInfo_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __DeskInfo_LIBRARY_DEFINED__
#define __DeskInfo_LIBRARY_DEFINED__

/* library DeskInfo */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DeskInfo;

#ifndef __IDeskInfo_DISPINTERFACE_DEFINED__
#define __IDeskInfo_DISPINTERFACE_DEFINED__

/* dispinterface IDeskInfo */
/* [uuid] */ 


EXTERN_C const IID DIID_IDeskInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ad5d62fa-d938-4cd9-87e5-05d8ee5ffafe")
    IDeskInfo : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IDeskInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDeskInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDeskInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDeskInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDeskInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDeskInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDeskInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDeskInfo * This,
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
    } IDeskInfoVtbl;

    interface IDeskInfo
    {
        CONST_VTBL struct IDeskInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDeskInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDeskInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDeskInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDeskInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDeskInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDeskInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDeskInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IDeskInfo_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DeskInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("35e4f1a6-343a-44d0-9876-35ea4e2a70dc")
DeskInfo;
#endif
#endif /* __DeskInfo_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


