#pragma once
#include "mysql.h" 


// CCh_AddDlg 对话框

class CCh_AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCh_AddDlg)

public:
	CCh_AddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCh_AddDlg();

// 对话框数据
	enum { IDD = IDD_Ch_Add };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL CCh_AddDlg::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	int m_Add_id;
	CString m_Add_name;
	CString m_Add_stuID;
	CString m_Add_gene;
};
