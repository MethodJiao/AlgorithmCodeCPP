#pragma once
class ExportClass1
{
public:
	DLL_EXPORT_DECL ExportClass1();
	DLL_EXPORT_DECL ~ExportClass1();
	DLL_EXPORT_DECL void Method1();

	DLL_EXPORT_DECL void Method2() { int a = 0; };
};

