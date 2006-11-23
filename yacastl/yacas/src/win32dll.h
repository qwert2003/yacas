
#ifndef __win32dll_h__
#define __win32dll_h__

#include "lispplugin.h"

class Win32Dll : public LispDllBase
{
public:
    Win32Dll() : handle(NULL) {}
    virtual ~Win32Dll();
    virtual LispInt Open(LispChar * aDllFile,LispEnvironment& aEnvironment);
    virtual LispInt Close(LispEnvironment& aEnvironment);
    virtual LispPluginBase* GetPlugin(LispChar * aDllFile);
private:
    void *handle;
};

#endif
