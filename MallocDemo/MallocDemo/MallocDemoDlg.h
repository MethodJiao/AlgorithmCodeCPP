
// MallocDemoDlg.h : ͷ�ļ�
//
#include <Windows.h>
#include <iostream>
#include "vector"
using namespace std;
#pragma once


// CMallocDemoDlg �Ի���
class CMallocDemoDlg : public CDialogEx
{
// ����
public:
	CMallocDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MALLOCDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
