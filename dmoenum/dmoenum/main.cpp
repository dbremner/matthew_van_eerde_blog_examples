// main.cpp

#include <windows.h>
#include <objbase.h>
#include <stdio.h>

#include "log.h"
#include "dmoenum.h"
#include "cleanup.h"

int _cdecl wmain() {

    HRESULT hr;
    
    hr = CoInitialize(NULL);
    if (FAILED(hr)) {
        ERR(L"CoInitialize failed: hr = 0x%08x", hr);
        return hr;
    }
  
    CoUninitializeOnExit coUninit;

    hr = EnumerateDMOs();
    
    return (SUCCEEDED(hr) ? 0 : hr);
}