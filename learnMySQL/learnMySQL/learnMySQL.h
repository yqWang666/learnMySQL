
// learnMySQL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// ClearnMySQLApp:
// �йش����ʵ�֣������ learnMySQL.cpp
//

class ClearnMySQLApp : public CWinApp
{
public:
	ClearnMySQLApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern ClearnMySQLApp theApp;