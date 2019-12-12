#pragma once
#include "Father.h"
class Children :
	public Father
{
public:
	Children();
	~Children();
private:
	virtual int ShowString() override;
	virtual void ShowMessage() override;
	int m_int;
};

