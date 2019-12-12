// OpenMPDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <omp.h>

int main()
{
	//omp_set_num_threads(8);
	int coreCount = omp_get_num_procs();
	//std::cout << coreCount << "\n";
	double t1, t2;
	t1 = omp_get_wtime();
#pragma omp parallel for
	for (size_t i = 0; i < 100000000; i++)
	{
		double num = 3.1415926 * 3.1415926;
		num += 3.1415926 * 3.1415926;
		num += 3.1415926 * 3.1415926;
		num += 3.1415926 * 3.1415926;
		//std::cout << omp_get_thread_num() << "\n";
	}
	t2 = omp_get_wtime();
	std::cout <<"并行费时："<< t2 - t1<< "\n";
	for (size_t i = 0; i < 100000000; i++)
	{
		double num = 3.1415926 * 3.1415926;
		num += 3.1415926 * 3.1415926;
		num += 3.1415926 * 3.1415926;
		num += 3.1415926 * 3.1415926;
	}
	t1 = omp_get_wtime();
	std::cout << "串行费时：" << t1 - t2 << "\n";
	system("PAUSE");
}
