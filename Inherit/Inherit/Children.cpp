#include "stdafx.h"
#include "Children.h"


Children::Children():Father(),m_int(2)
{
	int a = 0;
}


Children::~Children()
{
}

int Children::ShowString()
{
	MessageBox(GetForegroundWindow(), _T("���Ǽ̳���"), _T("��ʾ"), 1);
	return 0;
}

void Children::ShowMessage()
{
	ShowString();
}
