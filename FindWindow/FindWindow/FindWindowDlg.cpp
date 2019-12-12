
// FindWindowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FindWindow.h"
#include "FindWindowDlg.h"
#include "afxdialogex.h"

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


// CFindWindowDlg 对话框



CFindWindowDlg::CFindWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FINDWINDOW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFindWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFindWindowDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFindWindowDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFindWindowDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CFindWindowDlg 消息处理程序

BOOL CFindWindowDlg::OnInitDialog()
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

void CFindWindowDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFindWindowDlg::OnPaint()
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
HCURSOR CFindWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFindWindowDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//popUp = std::make_unique<PopUpDlg>();
	//popUp->Create(PopUpDlg::IDD, this);
	//popUp->ShowWindow(true);

	/*HWND hWnd = ::FindWindow(NULL, _T("怪物猎人OL"));
	HWND subwnd = ::FindWindowEx(hWnd, NULL, NULL, _T("Tab Control"));
	HWND button = ::FindWindowEx(subwnd, NULL, NULL, _T("浏览"));
	::SendMessage(button, WM_LBUTTONDOWN, 0, MAKELPARAM(2, 2));
	::SendMessage(button, WM_LBUTTONUP, 0, MAKELPARAM(2, 2));*/

	HWND hWnd = ::FindWindow(NULL, _T("怪物猎人OL"));
	HWND subwnd = ::FindWindowEx(hWnd, NULL, NULL, _T("Tab Control"));
	HWND text = ::FindWindowEx(subwnd, NULL, NULL, _T("绑定类型:Loading ... ..."));
	::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("绑定类型:绑定到QQ号(781892526)"));

	text = ::FindWindowEx(subwnd, NULL, NULL, _T("账号:Loading ... ..."));
	::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("账号:yingzong"));

	text = ::FindWindowEx(subwnd, NULL, NULL, _T("过期时间:Loading ... ..."));
	::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("过期时间:2018-11-05 16:48:34"));
}


void CFindWindowDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//----------------------操作文本文档----------------------//
	/*HWND hWnd = ::FindWindow(_T("Notepad"), NULL);
	HWND subwnd = ::FindWindowEx(hWnd, NULL, _T("Edit"), NULL);
	::SendMessage(subwnd, WM_SETTEXT, 0, (LPARAM)_T("1111"));*/
	
	//--------------------操作非模态对话框--------------------//
	//HWND hWnd = ::FindWindow(NULL, _T("PopUp"));
	////CRect rect;
	////::GetWindowRect(hWnd, &rect);
	////::MoveWindow(hWnd, 0, 0, 200, 200, true);//移动窗体
	//HWND edit = ::GetDlgItem(hWnd, 1001);
	//::SendMessage(edit, WM_SETTEXT, 0, (LPARAM)_T("1111"));
	//

	HWND hWnd = ::FindWindow(NULL,_T("怪物猎人OL"));
	HWND subwnd = ::FindWindowEx(hWnd, NULL, NULL, _T("Tab Control"));

	HWND button = ::FindWindowEx(subwnd, NULL, NULL, _T("运行游戏"));
	//::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("F:\\怪物猎人online\\腾讯游戏\\怪物猎人Online"));
	::SendMessage(button, WM_LBUTTONDOWN, 0, MAKELPARAM(2, 2));
	::SendMessage(button, WM_LBUTTONUP, 0, MAKELPARAM(2, 2));
	
}
