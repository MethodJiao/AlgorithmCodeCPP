
// FindWindow.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFindWindowApp: 
// �йش����ʵ�֣������ FindWindow.cpp
//

class CFindWindowApp : public CWinApp
{
public:
	CFindWindowApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFindWindowApp theApp;