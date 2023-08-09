// OutOfProcessCOMServer.cpp : Implementation of WinMain
#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "OutOfProcessCOMServer_i.h"
#include "xdlldata.h"

using namespace ATL;

class COutOfProcessCOMServerModule : public CAtlExeModuleT<COutOfProcessCOMServerModule>
{
public:
	DECLARE_LIBID(LIBID_OutOfProcessCOMServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OUTOFPROCESSCOMSERVER, "{ca11ab1e-85fc-409a-a0bc-ae9f8a1037eb}")
};

COutOfProcessCOMServerModule _AtlModule;

extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
	LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

