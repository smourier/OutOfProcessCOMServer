#include <windows.h>
#include <atlbase.h>
#include <atlcom.h>
#include <iostream>

#include "..\OutOfProcessCOMServer\OutOfProcessCOMServer_i.h"
#include "..\OutOfProcessCOMServer\OutOfProcessCOMServer_i.c"

class CClientModule : public ATL::CAtlExeModuleT<CClientModule>
{
};

CClientModule _pAtlModule;

int main()
{
	auto hr = CoInitialize(nullptr);
	{
		CComPtr<IMouse> mouse;
		ATLASSERT(SUCCEEDED(mouse.CoCreateInstance(CLSID_Mouse)));

		ATLASSERT(SUCCEEDED(mouse->click(CComBSTR(L"myButton"))));
		ATLASSERT(SUCCEEDED(mouse->scroll(1234)));

		CComPtr<IKeyboard> keyboard;
		ATLASSERT(SUCCEEDED(mouse.QueryInterface(&keyboard)));

		ATLASSERT(SUCCEEDED(keyboard->pressKey(L"myKey")));
		ATLASSERT(SUCCEEDED(keyboard->releaseKey(L"myKey")));
	}
	CoUninitialize();
	return 0;
}