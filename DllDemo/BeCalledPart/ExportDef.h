#pragma once
#if defined (__BECALLEDPART_BUILD__)
#define DLL_API    __declspec(dllexport)
#else
#define DLL_API    __declspec(dllimport)
#endif