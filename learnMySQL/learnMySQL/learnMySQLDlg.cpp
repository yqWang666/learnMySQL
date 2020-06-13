
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
	m_StuInformation.InsertColumn(1, _T("学号"), LVCFMT_LEFT, 100);	// 插入第2列的列名
	m_StuInformation.InsertColumn(2, _T("姓名"), LVCFMT_LEFT, 100);	// 插入第3列的列名
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



void ClearnMySQLDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ClearnMySQLDlg::OnOK();
	CCh_AddDlg m;
	m.DoModal();
}
