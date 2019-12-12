
// MallocDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MallocDemo.h"
#include "MallocDemoDlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <iostream>
#include "vector"
#include "amp.h"

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMallocDemoDlg 对话框



CMallocDemoDlg::CMallocDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MALLOCDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMallocDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMallocDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMallocDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMallocDemoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CMallocDemoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMallocDemoDlg 消息处理程序

BOOL CMallocDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMallocDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMallocDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMallocDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

DWORD WINAPI myfun1(LPVOID  pvoid)
{
	while (1)
	{
		double PI = atan(1.0) * 4;
		PI = PI + PI;
		PI = PI - PI;
	}
	return 0;
}





void CMallocDemoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	double s = atan(1.0) * 4;
	threadHandle.clear();
	for (size_t i = 0; i < 8; i++)
	{
		HANDLE s = CreateThread(NULL, 0, myfun1, NULL, 0, NULL);
		threadHandle.push_back(s);
	}
}


void CMallocDemoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	memoryMalloc.clear();
	while (true)
	{
		MEMORYSTATUS status;
		GlobalMemoryStatus(&status);
		if (status.dwAvailPhys < 2048 * 1024)
			break;

		int *p = (int*)malloc(4096);
		memoryMalloc.push_back(p);
	}
}


void CMallocDemoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	for each (int* var in memoryMalloc)
	{
		if (var != NULL)
		{
			free(var);
		}
	}
	memoryMalloc.clear();
	for each (HANDLE var in threadHandle)
	{
		if (var != NULL)
		{
			TerminateThread(var, EXIT_FAILURE);
			CloseHandle(var);
		}
	}
	threadHandle.clear();
}
