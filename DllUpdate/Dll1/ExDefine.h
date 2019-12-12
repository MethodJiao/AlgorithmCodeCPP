#pragma once
#ifdef Dll1Exprot
#define DLL_EXPORT_DECL __declspec(dllexport)
#endif
#ifndef Dll1Exprot
#define DLL_EXPORT_DECL __declspec(dllimport)
#endif