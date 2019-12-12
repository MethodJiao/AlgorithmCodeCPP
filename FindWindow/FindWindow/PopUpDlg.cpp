// PopUpDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FindWindow.h"
#include "PopUpDlg.h"
#include "afxdialogex.h"


// PopUpDlg 对话框

IMPLEMENT_DYNAMIC(PopUpDlg, CDialogEx)

PopUpDlg::PopUpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_MODAL, pParent)
{
	
}

PopUpDlg::~PopUpDlg()
{
}

void PopUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, editCtrl);
}


BEGIN_MESSAGE_MAP(PopUpDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PopUpDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// PopUpDlg 消息处理程序


void PopUpDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//SetWindowText(_T("ssss"));

}
