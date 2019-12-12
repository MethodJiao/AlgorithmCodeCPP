// PtrTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <memory>

#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#define WAITKEY_DELAY 30
#define CAMERA_DEVICE 0
using namespace std;
using namespace cv;
struct MyStruct
{
public:
	MyStruct()
	{
	};
	~MyStruct()
	{
	};
	string str;
	shared_ptr<MyStruct> my = nullptr;
};
MyStruct Method1()
{
	shared_ptr<MyStruct> child  = make_shared<MyStruct>();
	child->str = "bbbbbbb";
	child->my = nullptr;

	MyStruct mystruct;
	mystruct.str = "aaaaaaa";
	mystruct.my = child;

	return mystruct;
}
int main()
{
	//MyStruct my = Method1();
	//

	//int a = 0;

	//VideoCapture cap(0);
	//Mat frame;
	//while (waitKey(30) != 27)
	//{
	//	cap >> frame;
	//	cvtColor(frame, frame, COLOR_BGR2GRAY);
	//	Mat out;
	//	Canny(frame, out, 20, 80, 3);
	//	imshow("调用摄像头", out);
	//}


	//Mat img = imread("C://Users//Method.Jiao//Desktop//PtrTest//Debug//timg.jpg");
	//imshow("原始图", img);
	//Mat DstPic, edge, grayImage;

	////创建与src同类型和同大小的矩阵
	//DstPic.create(img.size(), img.type());

	////将原始图转化为灰度图
	//cvtColor(img, grayImage, COLOR_BGR2GRAY);

	////先使用3*3内核来降噪
	//blur(grayImage, edge, Size(3, 3));

	////运行canny算子
	//Canny(edge, edge, 3, 9, 3);

	//imshow("边缘提取效果", edge);

	//waitKey(0);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
