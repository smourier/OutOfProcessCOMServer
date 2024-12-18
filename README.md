# OutOfProcessCOMServer
An ATL C++ Out-Of-Process COM server and clients (C++, .NET, VBscript) sample.

The **OutOfProcessCOMServer** project is the COM server executable. It has been created using Visual Studio's ATL wizard and an "ATL Simple Object" item has been added (renamed as "Mouse").

Key points:

* The *IMouse* dual (*IUnknown-derived* + *IDispatch*) interface methods were added manually.
* The *IKeyboard* *IUnknown-derived* interface was added manually in *OutOfProcessCOMServer.idl* and was also added to the list of interfaces the *CMouse* class implements (in Mouse.h). For demonstration purposes, *IKeyboard* uses a non-OLE-automation type (the Windows LPCWSTR type), which needs proper marshaling.
* Both *IMouse* and *IKeyboard* have been simply implemented (in *Mouse.h*).
* Building (MIDL) create (among other files) a *OutOfProcessCOMServer.tlb* (Type Library) file needed for the .NET client.
* Self-registration was removed from config so Visual Studio doesn't need to run as admin.
* The server starts and shutdowns automatically (ATL does that).
* It must be registered (with admin rights) with `OutOfProcessCOMServer.exe /regserver`.
* It can be unregistered (with admin rights) with `OutOfProcessCOMServer.exe /unregserver`.



The **OutOfProcessCOMServerPS** project is the Proxy/Stub dll for the OutOfProcessCOMServer COM server. It's only needed for the *IKeyboard* interface which is an *IUnknown-derived* interface (not *IDispatch*, not dual) which needs to be proxied and marshaled since it's not dual nor OLE-Automation and not using OLE-Automation compatible types. When using only interfaces like *IMouse*, this project is not needed at all.

Key points:

* It has not been created by Visual Studio automatically, the project was created from an empty DLL project.

* it references ATL-generated files *xdlldata.c*, *xdlldata.h*, *OutOfProcessCOMServer_i.c*, *OutOfProcessCOMServer_p.c* from the OutOfProcessCOMServer  project.
* the *OutOfProcessCOMServerPS.def* file has been added manually to export standard COM functions so the DLL can be registered/unregistered.
* It must be registered (with admin rights) with `regsvr32 OutOfProcessCOMServerPS.dll`
* It can be unregistered (with admin rights) with `regsvr32 /u OutOfProcessCOMServerPS.dll`



The **Client** project is a C++ client (using ATL). It includes OutOfProcessCOMServer project's MIDL-generated files for IIDs and CLSIDs definitions.



The **NetCoreClient** project is a .NET 8.0 client project. It references the .TLB (by it's LIBID so it must exist before this project can compile) generated by OutOfProcessCOMServer project's MIDL pass. It can access *IMouse* and *IKeyboard*.



The **VBScriptClient.vbs** is a VBScript file. It can only access *IMouse* since VBScript only supports OLE-Automation interfaces.
