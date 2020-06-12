// Ch_AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "learnMySQL.h"
#include "Ch_AddDlg.h"
#include "afxdialogex.h"
#include "learnMySQLDlg.h"


// CCh_AddDlg �Ի���

IMPLEMENT_DYNAMIC(CCh_AddDlg, CDialogEx)

CCh_AddDlg::CCh_AddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCh_AddDlg::IDD, pParent)
{

	m_Add_id = 0;
	m_Add_name = _T("");
	m_Add_stuID = _T("");
	m_Add_gene = _T("");
}

CCh_AddDlg::~CCh_AddDlg()
{
}

void CCh_AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Add_id, m_Add_id);
	DDX_Text(pDX, IDC_Add_name, m_Add_name);
	DDX_Text(pDX, IDC_Add_stuID, m_Add_stuID);
	DDX_Text(pDX, IDC_Add_gene, m_Add_gene);
}


BEGIN_MESSAGE_MAP(CCh_AddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCh_AddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCh_AddDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCh_AddDlg ��Ϣ�������


void CCh_AddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int local_id = m_Add_id;
	CString local_name = m_Add_name;
	CString local_stuID = m_Add_stuID;
	CString local_gene = m_Add_gene;
	// ���� MYSQL ����
	MYSQL local_mysql;
	// ��ʼ�� MYSQL ����
	mysql_init(&local_mysql);
	// �������ݿ�
	if(!mysql_real_connect(&local_mysql,"localhost","root","root","learnmysql",3306,NULL,0))
	{
		AfxMessageBox(_T("connect to database failed!"));
	}
	else
	{
		AfxMessageBox(_T("connect to database success!"));
		// �����ַ����� ʹ����֧�����ġ�
		mysql_query(&local_mysql, "set names 'gb2312'");
	}

	// ���� SQL ����ַ���
	CString sql_insert;
	sql_insert.Format("insert into stuInf(id, name, stuID, gene) values (%d, \"%s\", \"%s\",\"%s\")", local_id, local_name, local_stuID, local_gene);
	// ִ�� sql ��䡣
	// mysql_query() �ķ���ֵ�ݺܶ����Σ� �����ж�ʹҪע�⡣
	if(mysql_query(&local_mysql,(char*)(LPCTSTR)sql_insert)==0)
	{   
		AfxMessageBox("insert succeed!");   
	}
	else
	{
		AfxMessageBox("insert failed!");
    }
	// �ر� local_mysql �����������ݿ����ӣ� һ������²���д��
	mysql_close(&local_mysql);

	CDialogEx::OnOK();
	ClearnMySQLDlg m;
	m.DoModal();
}


void CCh_AddDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	ClearnMySQLDlg m;
	m.DoModal();
}
