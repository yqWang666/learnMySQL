// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "learnMySQL.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "learnMySQLDlg.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedLiLi()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_Li_user == "admin" && m_Li_password == "123456")
	{
		CLoginDlg::OnOK();
		ClearnMySQLDlg m;
		m.DoModal();
	}
	else
	{
		AfxMessageBox("�û���������������������룡");
		return ;
	}

}
