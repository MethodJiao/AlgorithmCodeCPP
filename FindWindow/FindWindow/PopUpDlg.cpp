// PopUpDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FindWindow.h"
#include "PopUpDlg.h"
#include "afxdialogex.h"


// PopUpDlg �Ի���

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


// PopUpDlg ��Ϣ�������


void PopUpDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//SetWindowText(_T("ssss"));

}
