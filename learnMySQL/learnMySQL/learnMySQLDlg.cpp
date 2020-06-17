
// learnMySQLDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "learnMySQL.h"
#include "learnMySQLDlg.h"
#include "afxdialogex.h"
#include "Ch_AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ClearnMySQLDlg 对话框




ClearnMySQLDlg::ClearnMySQLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClearnMySQLDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClearnMySQLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_StuInformation);
}

BEGIN_MESSAGE_MAP(ClearnMySQLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Add, &ClearnMySQLDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDOK, &ClearnMySQLDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Delete, &ClearnMySQLDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_Update, &ClearnMySQLDlg::OnBnClickedUpdate)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &ClearnMySQLDlg::OnNMRClickList1)
	ON_COMMAND(ID_FILE_32774, &ClearnMySQLDlg::OnFile32774)
	ON_COMMAND(ID_FILE_32775, &ClearnMySQLDlg::OnFile32775)
	ON_COMMAND(ID_FILE_32776, &ClearnMySQLDlg::OnFile32776)
END_MESSAGE_MAP()


// ClearnMySQLDlg 消息处理程序

BOOL ClearnMySQLDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_StuInformation.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	m_StuInformation.InsertColumn(0, _T("id"),	LVCFMT_LEFT, 0);
	m_StuInformation.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 100);	// 插入第2列的列名
	m_StuInformation.InsertColumn(2, _T("学号"), LVCFMT_LEFT, 100);	// 插入第3列的列名
	m_StuInformation.InsertColumn(3, _T("性别"), LVCFMT_LEFT, 100);	// 插入第4列的列名
	m_StuInformation.InsertColumn(4, _T("语文"), LVCFMT_LEFT, 100);	// 插入第5列的列名
	m_StuInformation.InsertColumn(5, _T("数学"), LVCFMT_LEFT, 100);	// 插入第6列的列名
	m_StuInformation.InsertColumn(6, _T("英语"), LVCFMT_LEFT, 100);	// 插入第7列的列名
	m_StuInformation.InsertColumn(7, _T("物理"), LVCFMT_LEFT, 100);	// 插入第8列的列名
	m_StuInformation.InsertColumn(8, _T("化学"), LVCFMT_LEFT, 100);	// 插入第9列的列名
	m_StuInformation.InsertColumn(9, _T("生物"), LVCFMT_LEFT, 100);	// 插入第10列的列名
	m_StuInformation.InsertColumn(10, _T("理综"), LVCFMT_LEFT, 100);// 插入第11列的列名
	m_StuInformation.InsertColumn(11, _T("总分"), LVCFMT_LEFT, 100);// 插入第12列的列名
	////设置行高
	CImageList   m_l;  
	m_l.Create(1,25,TRUE|ILC_COLOR32,1,0);  
	m_StuInformation.SetImageList(&m_l,LVSIL_SMALL);
	////设置字体
	CFont m_font;
	m_font.CreatePointFont(100, "新宋体");
	m_StuInformation.SetFont(&m_font);

	m_StuInformation.SetColumnWidth (0,80); //设置列宽
	m_StuInformation.SetColumnWidth (1,120);
	m_StuInformation.SetColumnWidth (2,120);
	m_StuInformation.SetColumnWidth (3,60);
	m_StuInformation.SetColumnWidth (4,60);
	m_StuInformation.SetColumnWidth (5,60);
	m_StuInformation.SetColumnWidth (6,60);
	m_StuInformation.SetColumnWidth (7,60);
	m_StuInformation.SetColumnWidth (8,60);
	m_StuInformation.SetColumnWidth (9,60);
	m_StuInformation.SetColumnWidth (10,60);
	m_StuInformation.SetColumnWidth (11,60);

	// 创建 MYSQL 对象。
	//MYSQL local_mysql;
	// 初始化 MYSQL 对象。
	mysql_init(&local_mysql);
	// 连接数据库
	if(!mysql_real_connect(&local_mysql,"localhost","root","root","learnmysql",3306,NULL,0))
	{
		AfxMessageBox(_T("connect to database failed!"));
	}
	else
	{
		//AfxMessageBox(_T("connect to database success!"));
		// 设置字符集， 使程序支持中文。
		mysql_query(&local_mysql, "set names 'gb2312'");
	}

	CString select_sql_by_id;
	// 存放查询结果的变量
	//MYSQL_RES* result;
	MYSQL_ROW row;
	select_sql_by_id.Format("select * from stuinf");
	int res = mysql_query(&local_mysql, (char*)(LPCSTR)select_sql_by_id);
	// mysql_query 函数返回 0  表示 查询成功。
	if(res == 0)
	{
		// 获取查询结果，并保存在 result 里面。
		result = mysql_store_result(&local_mysql);
		// 循环地从查询结果中拿出一行， 并赋值给 row 变量。
		while(row = mysql_fetch_row(result))
		{
			CString local_id;
			CString local_name;
			CString local_salary;
			CString local_message;
			// 将从数据库中获取的数据 保存在字符串中， row[0], row[1], row[2], 分别表示一条查询结果中的第1， 2， 3 个字段，
			Str_id = row[0];
			Str_name.Format(row[1]);
			Str_stuId.Format(row[2]);	
			Str_gene.Format(row[3]);
			m_StuInformation.InsertItem(list_row, _T(""));						// 插入行
			m_StuInformation.SetItemText(list_row, 0, Str_id);				    // 设置第1列(id)
			m_StuInformation.SetItemText(list_row, 1, Str_name);				// 设置第2列(姓名)
			m_StuInformation.SetItemText(list_row, 2, Str_stuId);				// 设置第3列(学号)
			m_StuInformation.SetItemText(list_row, 3, Str_gene);				// 设置第4列(性别)
			list_row++;
		}
		//mysql_free_result(result);
		//AfxMessageBox("query succeed!");
	}
	else
	{
		AfxMessageBox("no results!");
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void ClearnMySQLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClearnMySQLDlg::OnPaint()
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
HCURSOR ClearnMySQLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


////增加
void ClearnMySQLDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	//ClearnMySQLDlg::OnOK();
	CCh_AddDlg m;
	m.DoModal();
}


void ClearnMySQLDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	mysql_free_result(result);
	CDialogEx::OnOK();
}

////删除
void ClearnMySQLDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码

}

////修改
void ClearnMySQLDlg::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码

}

////右键
void ClearnMySQLDlg::OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	//pNMListView = (NM_LISTVIEW*)pNMHDR;
	if (pNMListView->iItem != -1)
	{

		CPoint pt;
		GetCursorPos(&pt);
		CMenu menu;
		menu.LoadMenu(IDR_MENU1);
		CMenu *popmenu;
		popmenu = menu.GetSubMenu(0);
		popmenu->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
	}

	*pResult = 0;
}

////插入
void ClearnMySQLDlg::OnFile32774()
{
	// TODO: 在此添加命令处理程序代码

}

////修改
void ClearnMySQLDlg::OnFile32775()
{
	// TODO: 在此添加命令处理程序代码
}

////删除
void ClearnMySQLDlg::OnFile32776()
{
	// TODO: 在此添加命令处理程序代码
	int stuinf_id = 0;  //被删除的列对应到数据库表格中的id

	////从表格中删除
	int i, iState;
	int nItemSelected = m_StuInformation.GetSelectedCount();
	int nItemCount = m_StuInformation.GetItemCount();
	if (nItemSelected < 1)
		return;
	for (i = nItemCount - 1; i >= 0; i--)
	{
		iState = m_StuInformation.GetItemState(i, LVIS_SELECTED);
		if (iState != 0)
		{
			CString del_sql_id = m_StuInformation.GetItemText(i,0); //i是行，j是列。m_list是个list control 对象
			stuinf_id = atoi(del_sql_id);
			m_StuInformation.DeleteItem(i);
		}
	}

	////从数据库中删除
	CString delete_sql_by_id;
	// 存放查询结果的变量
	//MYSQL_RES* result;
	delete_sql_by_id.Format("delete from stuinf where id = %d",stuinf_id);
	int res = mysql_query(&local_mysql, (char*)(LPCSTR)delete_sql_by_id);
	// mysql_query 函数返回 0  表示 查询成功。
	if(res == 0)
	{
		//mysql_free_result(result);
		AfxMessageBox("数据库文件删除成功！");
	}
	else
	{
		AfxMessageBox("数据库文件删除失败！");
	}

	////listCtrl中的行数要减一
	list_row--;
}
