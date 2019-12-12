
// MallocDemoDlg.h : 头文件
//
#include <Windows.h>
#include <iostream>
#include "vector"
using namespace std;
#pragma once


// CMallocDemoDlg 对话框
class CMallocDemoDlg : public CDialogEx
{
// 构造
public:
	CMallocDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MALLOCDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//DWORD WINAPI myfun1(LPVOID  pvoid);
	vector<int*> memoryMalloc;
	vector<HANDLE> threadHandle;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
};
