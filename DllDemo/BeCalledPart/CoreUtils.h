#pragma once
#include "ExportDef.h"
#include <string>
using namespace std;
class CoreUtils
{
public:
	DLL_API CoreUtils();
	DLL_API ~CoreUtils();

public:
	DLL_API string GetOwnClassName();
};

