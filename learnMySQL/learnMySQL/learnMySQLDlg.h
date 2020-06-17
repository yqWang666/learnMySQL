
// learnMySQLDlg.h : ͷ�ļ�
//

#pragma once
#include "mysql.h"


// ClearnMySQLDlg �Ի���
class ClearnMySQLDlg : public CDialogEx
{
// ����
public:
	ClearnMySQLDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LEARNMYSQL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAdd();
	MYSQL local_mysql;
	MYSQL_RES* result;
	
	/*CListCtrl m_StuInformation;
	CString Str_id,Str_name,Str_stuId,Str_gene;*/
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnFile32774();
	afx_msg void OnFile32775();
	afx_msg void OnFile32776();
};
