#pragma once

#include "..\OutOfProcessCOMServer\OutOfProcessCOMServer_i.h"

using namespace ATL;

static GUID CLSID_Proxy = { 0x19e94d6d, 0xc0b5, 0x46b8, { 0xb2,0x55,0xb4,0xbe,0xc0,0xe5,0x23,0xab } };

template <class T, class Ti>
static
HRESULT CreateInstance(Ti** ppObject)
{
	CComObject<T>* pObject = nullptr;
	HRESULT hr = CComObject<T>::CreateInstance(&pObject);
	if (SUCCEEDED(hr))
	{
		hr = pObject->QueryInterface(ppObject);
	}
	return hr;
}

void TraceIID(REFIID riid, LPCWSTR text);

class ATL_NO_VTABLE CKeyboardProxy :
	public CComObjectRootEx<CComMultiThreadModel>,
	public IRpcProxyBuffer,
	public IKeyboard
{
	CComPtr<IRpcChannelBuffer> _channelBuffer;
	CComPtr<IUnknown> _outer;

public:
	CKeyboardProxy()
	{
	}

	void SetOuter(IUnknown* outer)
	{
		_outer = outer;
	}

	BEGIN_COM_MAP(CKeyboardProxy)
		COM_INTERFACE_ENTRY(IRpcProxyBuffer)
		COM_INTERFACE_ENTRY(IKeyboard)
		COM_INTERFACE_ENTRY_FUNC_BLIND(0, MyQueryInterface)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

		static HRESULT STDMETHODCALLTYPE MyQueryInterface(void* pv, REFIID riid, void** ppv, DWORD_PTR dw)
	{
		auto cls = (CKeyboardProxy*)pv;
		TraceIID(riid, L"CKeyboardProxy QI failed");
		if (cls->_outer)
			return cls->_outer->QueryInterface(riid, ppv);

		return E_NOINTERFACE;
	}

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	HRESULT STDMETHODCALLTYPE Connect(IRpcChannelBuffer* pRpcChannelBuffer)
	{
		_channelBuffer = pRpcChannelBuffer;
		return S_OK;
	}

	void STDMETHODCALLTYPE Disconnect()
	{
		_channelBuffer.Release();
	}

	HRESULT STDMETHODCALLTYPE pressKey(LPCWSTR keyName)
	{
		RPCOLEMESSAGE message{};
		auto len = lstrlen(keyName) + 1;
		message.cbBuffer = keyName ? len * 2 : 0;
		if (message.cbBuffer < 256)
		{
			message.cbBuffer = 256;
		}

		ATLASSERT(SUCCEEDED(_channelBuffer->GetBuffer(&message, __uuidof(IKeyboard))));

		message.iMethod = 3;
		if (keyName)
		{
			lstrcpyn((LPWSTR)message.Buffer, keyName, len);
		}

		ULONG status;
		auto hr = _channelBuffer->SendReceive(&message, &status);
		_channelBuffer->FreeBuffer(&message);
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE releaseKey(LPCWSTR keyName)
	{
		return S_OK;
	}
};

class ATL_NO_VTABLE CKeyboardStub :
	public CComObjectRootEx<CComMultiThreadModel>,
	public IRpcStubBuffer
{
	CComPtr<IKeyboard> _keyboard;
	ULONG _refs;

public:
	CKeyboardStub() :
		_refs(0)
	{
	}

	BEGIN_COM_MAP(CKeyboardStub)
		COM_INTERFACE_ENTRY(IRpcStubBuffer)
		COM_INTERFACE_ENTRY_FUNC_BLIND(0, MyQueryInterface)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

		static HRESULT STDMETHODCALLTYPE MyQueryInterface(void* pv, REFIID riid, void** ppv, DWORD_PTR dw)
	{
		TraceIID(riid, L"CKeyboardStub QI failed");
		return E_FAIL;
	}

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	HRESULT STDMETHODCALLTYPE Connect(IUnknown* pUnkServer)
	{
		ATLASSERT(SUCCEEDED(pUnkServer->QueryInterface(&_keyboard)));
		InterlockedIncrement(&_refs);
		return S_OK;
	}

	void STDMETHODCALLTYPE Disconnect()
	{
		_keyboard.Release();
		InterlockedDecrement(&_refs);
	}

	HRESULT STDMETHODCALLTYPE Invoke(RPCOLEMESSAGE* _prpcmsg, IRpcChannelBuffer* _pRpcChannelBuffer)
	{
		return S_OK;
	}

	IRpcStubBuffer* STDMETHODCALLTYPE IsIIDSupported(REFIID riid)
	{
		if (riid == __uuidof(IKeyboard))
		{
			this->AddRef();
			return (IRpcStubBuffer*)this;
		}
		return NULL;
	}

	ULONG STDMETHODCALLTYPE CountRefs()
	{
		return _refs;
	}

	HRESULT STDMETHODCALLTYPE DebugServerQueryInterface(void** ppv)
	{
		return E_NOTIMPL;
	}

	void STDMETHODCALLTYPE DebugServerRelease(void* pv)
	{
	}
};


class ATL_NO_VTABLE CProxy :
	public CComObjectRootEx<CComMultiThreadModel>,
	public IPSFactoryBuffer
{
public:
	CProxy()
	{
	}

	BEGIN_COM_MAP(CProxy)
		COM_INTERFACE_ENTRY(IPSFactoryBuffer)
		COM_INTERFACE_ENTRY_FUNC_BLIND(0, MyQueryInterface)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

		static HRESULT STDMETHODCALLTYPE MyQueryInterface(void* pv, REFIID riid, void** ppv, DWORD_PTR dw)
	{
		TraceIID(riid, L"CProxy QI failed");
		return E_FAIL;
	}

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	HRESULT STDMETHODCALLTYPE CreateProxy(IUnknown* pUnkOuter, REFIID riid, IRpcProxyBuffer** ppProxy, void** ppv)
	{
		if (riid != __uuidof(IKeyboard))
			return E_NOINTERFACE;

		CComObject<CKeyboardProxy>* proxy;
		ATLASSERT(SUCCEEDED(CComObject<CKeyboardProxy>::CreateInstance(&proxy)));
		proxy->SetOuter(pUnkOuter);

		ATLASSERT(SUCCEEDED(proxy->QueryInterface(ppProxy)));
		ATLASSERT(SUCCEEDED(proxy->QueryInterface(riid, ppv)));
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE CreateStub(REFIID riid, IUnknown* pUnkServer, IRpcStubBuffer** ppStub)
	{
		if (riid != __uuidof(IKeyboard))
			return E_NOINTERFACE;

		ATLASSERT(SUCCEEDED(::CreateInstance<CKeyboardStub>(ppStub)));
		ATLASSERT(SUCCEEDED((*ppStub)->Connect(pUnkServer)));
		return S_OK;
	}
};
