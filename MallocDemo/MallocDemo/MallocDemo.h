
// MallocDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMallocDemoApp: 
// �йش����ʵ�֣������ MallocDemo.cpp
//

class CMallocDemoApp : public CWinApp
{
public:
	CMallocDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMallocDemoApp theApp;