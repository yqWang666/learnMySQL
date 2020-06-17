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

BOOL CCh_AddDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}



void CCh_AddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int local_id = m_Add_id;
	CString local_name = m_Add_name;
	CString local_stuID = m_Add_stuID;
	CString local_gene = m_Add_gene;
	//// ���� MYSQL ����
	MYSQL local_mysql;
	// ��ʼ�� MYSQL ����
	mysql_init(&local_mysql);
	// �������ݿ�
	if(!mysql_real_connect(&local_mysql,"localhost","root","root","learnmysql",3306,NULL,0))
	{
		AfxMessageBox(_T("�������ݿ�ʧ�ܣ�"));
	}
	else
	{
		//AfxMessageBox(_T("�������ݿ�ɹ���"));
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
		AfxMessageBox("���ݿ�������ݳɹ���");   
	}
	else
	{
		AfxMessageBox("���ݿ��������ʧ�ܣ�");
    }
	// �ر� local_mysql �����������ݿ����ӣ� һ������²���д��
	mysql_close(&local_mysql);

	CDialogEx::OnOK();
	//ClearnMySQLDlg m;
	//m.DoModal();

	//////�����ӵ�������ʾ��listCtrl��
	Str_id.Format("%d",local_id);
	Str_name = m_Add_name;
	Str_stuId= m_Add_stuID;
	Str_gene = m_Add_gene;
	m_StuInformation.InsertItem(list_row, _T(""));						// ������
	m_StuInformation.SetItemText(list_row, 0, Str_id);				    // ���õ�1��(id)
	m_StuInformation.SetItemText(list_row, 1, Str_name);				// ���õ�2��(����)
	m_StuInformation.SetItemText(list_row, 2, Str_stuId);				// ���õ�3��(ѧ��)
	m_StuInformation.SetItemText(list_row, 3, Str_gene);				// ���õ�4��(�Ա�)
	
}


void CCh_AddDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	ClearnMySQLDlg m;
	m.DoModal();
}
