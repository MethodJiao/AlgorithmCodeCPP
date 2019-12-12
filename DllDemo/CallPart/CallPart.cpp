// CallPart.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include <string>

#pragma comment(lib,"BeCalledPart.lib") 
#include "../BeCalledPart/CoreUtils.h"

using namespace std;

int main()
{
	CoreUtils coreUtils;
	string className = coreUtils.GetOwnClassName();
	std::cout << className << "\n";
}
