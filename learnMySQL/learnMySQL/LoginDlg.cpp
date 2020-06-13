// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "learnMySQL.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "learnMySQLDlg.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
{

	m_Li_user = _T("");
	m_Li_password = _T("");
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Li_User, m_Li_user);
	DDX_Text(pDX, IDC_Li_Password, m_Li_password);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Li_Li, &CLoginDlg::OnBnClickedLiLi)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序
BOOL CLoginDlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void CLoginDlg::OnBnClickedLiLi()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_Li_user == "" && m_Li_password == "")
	//if (m_Li_user == "admin" && m_Li_password == "123456")
	{
		CLoginDlg::OnOK();
		ClearnMySQLDlg m;
		m.DoModal();
	}
	else
	{
		AfxMessageBox("用户名或密码错误，请重新输入！");
		return ;
	}
}
