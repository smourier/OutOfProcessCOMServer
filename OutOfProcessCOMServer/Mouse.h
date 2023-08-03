// Mouse.h : Declaration of the CMouse

#pragma once
#include "resource.h"       // main symbols
#include "OutOfProcessCOMServer_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

class ATL_NO_VTABLE CMouse :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMouse, &CLSID_Mouse>,
	public IDispatchImpl<IMouse, &IID_IMouse, &LIBID_OutOfProcessCOMServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IKeyboard
{
public:
	CMouse()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)

BEGIN_COM_MAP(CMouse)
	COM_INTERFACE_ENTRY(IMouse)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IKeyboard)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	HRESULT STDMETHODCALLTYPE click(BSTR buttonName)
	{
		ATLTRACE2(L"click %s", buttonName);
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE scroll(LONG amount)
	{
		ATLTRACE2(L"scroll %i", amount);
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE pressKey(LPCWSTR keyName)
	{
		ATLTRACE2(L"pressKey %s", keyName);
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE releaseKey(LPCWSTR keyName)
	{
		ATLTRACE2(L"releaseKey %s", keyName);
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(Mouse), CMouse)
