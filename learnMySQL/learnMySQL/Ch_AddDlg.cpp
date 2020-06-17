// Ch_AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "learnMySQL.h"
#include "Ch_AddDlg.h"
#include "afxdialogex.h"
#include "learnMySQLDlg.h"


// CCh_AddDlg 对话框

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


// CCh_AddDlg 消息处理程序

BOOL CCh_AddDlg::OnInitDialog()
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



void CCh_AddDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int local_id = m_Add_id;
	CString local_name = m_Add_name;
	CString local_stuID = m_Add_stuID;
	CString local_gene = m_Add_gene;
	//// 创建 MYSQL 对象。
	MYSQL local_mysql;
	// 初始化 MYSQL 对象。
	mysql_init(&local_mysql);
	// 连接数据库
	if(!mysql_real_connect(&local_mysql,"localhost","root","root","learnmysql",3306,NULL,0))
	{
		AfxMessageBox(_T("连接数据库失败！"));
	}
	else
	{
		//AfxMessageBox(_T("连接数据库成功！"));
		// 设置字符集， 使程序支持中文。
		mysql_query(&local_mysql, "set names 'gb2312'");
	}

	// 创建 SQL 语句字符串
	CString sql_insert;
	sql_insert.Format("insert into stuInf(id, name, stuID, gene) values (%d, \"%s\", \"%s\",\"%s\")", local_id, local_name, local_stuID, local_gene);
	// 执行 sql 语句。
	// mysql_query() 的返回值份很多情形， 进行判断使要注意。
	if(mysql_query(&local_mysql,(char*)(LPCTSTR)sql_insert)==0)
	{   
		AfxMessageBox("数据库插入数据成功！");   
	}
	else
	{
		AfxMessageBox("数据库插入数据失败！");
    }
	// 关闭 local_mysql 所关联的数据库连接， 一般情况下不用写。
	mysql_close(&local_mysql);

	CDialogEx::OnOK();
	//ClearnMySQLDlg m;
	//m.DoModal();

	//////将增加的数据显示到listCtrl中
	Str_id.Format("%d",local_id);
	Str_name = m_Add_name;
	Str_stuId= m_Add_stuID;
	Str_gene = m_Add_gene;
	m_StuInformation.InsertItem(list_row, _T(""));						// 插入行
	m_StuInformation.SetItemText(list_row, 0, Str_id);				    // 设置第1列(id)
	m_StuInformation.SetItemText(list_row, 1, Str_name);				// 设置第2列(姓名)
	m_StuInformation.SetItemText(list_row, 2, Str_stuId);				// 设置第3列(学号)
	m_StuInformation.SetItemText(list_row, 3, Str_gene);				// 设置第4列(性别)
	
}


void CCh_AddDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	ClearnMySQLDlg m;
	m.DoModal();
}
