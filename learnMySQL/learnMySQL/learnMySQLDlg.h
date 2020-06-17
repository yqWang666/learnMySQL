
// learnMySQLDlg.h : 头文件
//

#pragma once
#include "mysql.h"


// ClearnMySQLDlg 对话框
class ClearnMySQLDlg : public CDialogEx
{
// 构造
public:
	ClearnMySQLDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LEARNMYSQL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
