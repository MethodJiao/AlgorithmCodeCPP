
// FindWindowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FindWindow.h"
#include "FindWindowDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CFindWindowDlg �Ի���



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


// CFindWindowDlg ��Ϣ�������

BOOL CFindWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFindWindowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFindWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFindWindowDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//popUp = std::make_unique<PopUpDlg>();
	//popUp->Create(PopUpDlg::IDD, this);
	//popUp->ShowWindow(true);

	/*HWND hWnd = ::FindWindow(NULL, _T("��������OL"));
	HWND subwnd = ::FindWindowEx(hWnd, NULL, NULL, _T("Tab Control"));
	HWND button = ::FindWindowEx(subwnd, NULL, NULL, _T("���"));
	::SendMessage(button, WM_LBUTTONDOWN, 0, MAKELPARAM(2, 2));
	::SendMessage(button, WM_LBUTTONUP, 0, MAKELPARAM(2, 2));*/

	HWND hWnd = ::FindWindow(NULL, _T("��������OL"));
	HWND subwnd = ::FindWindowEx(hWnd, NULL, NULL, _T("Tab Control"));
	HWND text = ::FindWindowEx(subwnd, NULL, NULL, _T("������:Loading ... ..."));
	::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("������:�󶨵�QQ��(781892526)"));

	text = ::FindWindowEx(subwnd, NULL, NULL, _T("�˺�:Loading ... ..."));
	::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("�˺�:yingzong"));

	text = ::FindWindowEx(subwnd, NULL, NULL, _T("����ʱ��:Loading ... ..."));
	::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("����ʱ��:2018-11-05 16:48:34"));
}


void CFindWindowDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//----------------------�����ı��ĵ�----------------------//
	/*HWND hWnd = ::FindWindow(_T("Notepad"), NULL);
	HWND subwnd = ::FindWindowEx(hWnd, NULL, _T("Edit"), NULL);
	::SendMessage(subwnd, WM_SETTEXT, 0, (LPARAM)_T("1111"));*/
	
	//--------------------������ģ̬�Ի���--------------------//
	//HWND hWnd = ::FindWindow(NULL, _T("PopUp"));
	////CRect rect;
	////::GetWindowRect(hWnd, &rect);
	////::MoveWindow(hWnd, 0, 0, 200, 200, true);//�ƶ�����
	//HWND edit = ::GetDlgItem(hWnd, 1001);
	//::SendMessage(edit, WM_SETTEXT, 0, (LPARAM)_T("1111"));
	//

	HWND hWnd = ::FindWindow(NULL,_T("��������OL"));
	HWND subwnd = ::FindWindowEx(hWnd, NULL, NULL, _T("Tab Control"));

	HWND button = ::FindWindowEx(subwnd, NULL, NULL, _T("������Ϸ"));
	//::SendMessage(text, WM_SETTEXT, 0, (LPARAM)_T("F:\\��������online\\��Ѷ��Ϸ\\��������Online"));
	::SendMessage(button, WM_LBUTTONDOWN, 0, MAKELPARAM(2, 2));
	::SendMessage(button, WM_LBUTTONUP, 0, MAKELPARAM(2, 2));
	
}
