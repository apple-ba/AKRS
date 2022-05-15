#pragma once
#include "afxdialogex.h"


// CReplyDlg 对话框

class CReplyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CReplyDlg)

public:
	CReplyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CReplyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REPLY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
