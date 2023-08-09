#include "pch.h"
#include "Proxy.h"

void TraceIID(REFIID riid, LPCWSTR text)
{
	CComHeapPtr<wchar_t> iid;
	StringFromCLSID(riid, &iid);
	ATLTRACE2(L"%s iid:%s\n", text, iid.m_pData);
}
