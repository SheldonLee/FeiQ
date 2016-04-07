#if !defined(AFX_FILETHREAD_H__2C277819_1962_41EA_9EED_29E37B94D8DD__INCLUDED_)
#define AFX_FILETHREAD_H__2C277819_1962_41EA_9EED_29E37B94D8DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileThread.h : header file
//

#include "FileRecvDlg.h"
#include "FileSendDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CFileThread thread

class CFileThread : public CWinThread
{
	DECLARE_DYNCREATE(CFileThread)
protected:
	CFileThread();           // protected constructor used by dynamic creation

// Attributes
public:
	CFileRecvDlg		m_FileRecvDlg;	//声明一个接收dlg的成员变量
	CFileSendDlg		m_FileSendDlg;	//发送dlg

// Operations
public:
	//标示
	BOOL m_bSendDlg;
	void SetSocket(SOCKET sock, CString strIP,BOOL fileSendDlg = FALSE);
	void SetSocket(CString strFile, CString strIP, BOOL fileSendDlg = TRUE);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFileThread();

	// Generated message map functions
	//{{AFX_MSG(CFileThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETHREAD_H__2C277819_1962_41EA_9EED_29E37B94D8DD__INCLUDED_)
