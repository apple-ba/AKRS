// CReplyDlg.cpp: 实现文件
//

#include "pch.h"
#include "AKRS.h"
#include "afxdialogex.h"
#include "CReplyDlg.h"


// CReplyDlg 对话框

IMPLEMENT_DYNAMIC(CReplyDlg, CDialogEx)

CReplyDlg::CReplyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REPLY_DIALOG, pParent)
{

}

CReplyDlg::~CReplyDlg()
{
}

void CReplyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CReplyDlg, CDialogEx)
END_MESSAGE_MAP()


// CReplyDlg 消息处理程序
