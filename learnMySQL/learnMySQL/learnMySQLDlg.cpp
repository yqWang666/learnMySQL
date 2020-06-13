
// learnMySQLDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "learnMySQL.h"
#include "learnMySQLDlg.h"
#include "afxdialogex.h"
#include "Ch_AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// ClearnMySQLDlg �Ի���




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


// ClearnMySQLDlg ��Ϣ�������

BOOL ClearnMySQLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_StuInformation.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// ����ѡ��������
	m_StuInformation.InsertColumn(0, _T("id"),	LVCFMT_LEFT, 0);
	m_StuInformation.InsertColumn(1, _T("ѧ��"), LVCFMT_LEFT, 100);	// �����2�е�����
	m_StuInformation.InsertColumn(2, _T("����"), LVCFMT_LEFT, 100);	// �����3�е�����
	m_StuInformation.InsertColumn(3, _T("�Ա�"), LVCFMT_LEFT, 100);	// �����4�е�����
	m_StuInformation.InsertColumn(4, _T("����"), LVCFMT_LEFT, 100);	// �����5�е�����
	m_StuInformation.InsertColumn(5, _T("��ѧ"), LVCFMT_LEFT, 100);	// �����6�е�����
	m_StuInformation.InsertColumn(6, _T("Ӣ��"), LVCFMT_LEFT, 100);	// �����7�е�����
	m_StuInformation.InsertColumn(7, _T("����"), LVCFMT_LEFT, 100);	// �����8�е�����
	m_StuInformation.InsertColumn(8, _T("��ѧ"), LVCFMT_LEFT, 100);	// �����9�е�����
	m_StuInformation.InsertColumn(9, _T("����"), LVCFMT_LEFT, 100);	// �����10�е�����
	m_StuInformation.InsertColumn(10, _T("����"), LVCFMT_LEFT, 100);// �����11�е�����
	m_StuInformation.InsertColumn(11, _T("�ܷ�"), LVCFMT_LEFT, 100);// �����12�е�����
	////�����и�
	CImageList   m_l;  
	m_l.Create(1,25,TRUE|ILC_COLOR32,1,0);  
	m_StuInformation.SetImageList(&m_l,LVSIL_SMALL);
	////��������
	CFont m_font;
	m_font.CreatePointFont(100, "������");
	m_StuInformation.SetFont(&m_font);

	m_StuInformation.SetColumnWidth (0,80); //�����п�
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ClearnMySQLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR ClearnMySQLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ClearnMySQLDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ClearnMySQLDlg::OnOK();
	CCh_AddDlg m;
	m.DoModal();
}
