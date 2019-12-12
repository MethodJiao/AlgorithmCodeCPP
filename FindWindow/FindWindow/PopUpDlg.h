#pragma once
#include "afxwin.h"

#define AFX_DESIGN_TIME
// PopUpDlg 对话框

class PopUpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PopUpDlg)

public:
	PopUpDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PopUpDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MODAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit editCtrl;
};
