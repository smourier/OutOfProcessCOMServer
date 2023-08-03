#include <windows.h>
#include <atlbase.h>
#include <atlcom.h>
#include <iostream>

#include "..\OutOfProcessCOMServer\OutOfProcessCOMServer_i.h"
#include "..\OutOfProcessCOMServer\OutOfProcessCOMServer_i.c"

int main()
{
	CoInitialize(nullptr);
	{
		CComPtr<IMouse> mouse;
		auto hr = mouse.CoCreateInstance(CLSID_Mouse);
		std::cout << "CoCreateInstance 0x" << std::hex << hr << std::endl;

		hr = mouse->click(CComBSTR(L"myButton"));
		std::cout << "click 0x" << std::hex << hr << std::endl;

		hr = mouse->scroll(1234);
		std::cout << "scroll 0x" << std::hex << hr << std::endl;

		CComPtr<IKeyboard> keyboard;
		hr = mouse.QueryInterface(&keyboard);
		std::cout << "QueryInterface 0x" << std::hex << hr << std::endl;

		hr = keyboard->pressKey(L"myKey");
		std::cout << "pressKey 0x" << std::hex << hr << std::endl;

		hr = keyboard->releaseKey(L"myKey");
		std::cout << "releaseKey 0x" << std::hex << hr << std::endl;
	}
	CoUninitialize();
	return 0;
}