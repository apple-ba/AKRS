﻿
// AKRSDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AKRS.h"
#include "AKRSDlg.h"
#include "afxdialogex.h"


#include "CReplyDlg.h"


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


// CAKRSDlg 对话框



CAKRSDlg::CAKRSDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AKRS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAKRSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAKRSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABOUT, &CAKRSDlg::OnBnClickedAbout)
	ON_BN_CLICKED(IDC_EXIT, &CAKRSDlg::OnBnClickedExit)
	ON_EN_CHANGE(IDC_EDIT, &CAKRSDlg::OnEnChangeEdit)
END_MESSAGE_MAP()


// CAKRSDlg 消息处理程序

BOOL CAKRSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CAKRSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAKRSDlg::OnPaint()
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
HCURSOR CAKRSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAKRSDlg::OnBnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg* pDlg = new CAboutDlg;
	pDlg->DoModal();
}


void CAKRSDlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(EXIT_SUCCESS);
}

#define Show() \
{CReplyDlg* pDlg = new CReplyDlg;\
pDlg->DoModal();\
return;}

void CAKRSDlg::OnEnChangeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString ss;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->GetWindowText(ss);
#define l ss.GetLength()
	ss.MakeLower();
	if (l > 6)
	{
		ss.Delete(0, l - 7);
		if (ss == _T("farther"))Show();
	}
	if (l > 5)
	{
		ss.Delete(0, l - 6);
		if (ss == _T("father"))Show();
	}
	if (l > 4)
	{
		ss.Delete(0, l - 6);
		if (ss == _T("daddy"))Show();
	}
	if (l > 2) 
	{
		ss.Delete(0, l - 3);
		if (ss == _T("die")||ss==_T("dad"))Show();
	}
	if (l > 1)
	{
		ss.Delete(0, l - 2);
		if (ss == _T("ba"))Show();
	}
	if (l > 0)
	{
		const wchar_t ls[] = L"芭捌扒叭吧笆八疤巴拔跋靶把耙坝霸罢爸伯湃茇菝萆捭岜灞杷钯粑鲅魃8跌爹碟蝶迭谍叠涉踢至窒佚垤堞揲喋渫轶牒瓞褶耋蹀鲽鳎";
		for (int i = 0; i < sizeof(ls); i++)
			if (ss[l - 1] == ls[i]) Show();
	}
}

