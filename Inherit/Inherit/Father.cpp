#include "stdafx.h"
#include "Father.h"


Father::Father()
{
	int a = 0;
}


Father::~Father()
{
}

void Father::ShowMessage()
{
	ShowString();
}

int Father::ShowString()
{
	MessageBox(GetForegroundWindow(), _T("���ǻ���"), _T("��ʾ"), 1);
	return 0;
}
