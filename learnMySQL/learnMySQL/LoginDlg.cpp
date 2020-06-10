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
	DDX_Text(pDX, IDC_Li_Pw, m_Li_password);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Li_Li, &CLoginDlg::OnBnClickedLiLi)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedLiLi()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_Li_user == "admin" && m_Li_password == "123456")
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
