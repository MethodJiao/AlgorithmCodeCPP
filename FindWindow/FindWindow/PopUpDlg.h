#pragma once
#include "afxwin.h"

#define AFX_DESIGN_TIME
// PopUpDlg �Ի���

class PopUpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PopUpDlg)

public:
	PopUpDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PopUpDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MODAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit editCtrl;
};
