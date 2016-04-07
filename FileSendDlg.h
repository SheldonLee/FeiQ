#if !defined(AFX_FILESENDDLG_H__B4B8638B_8B83_42D2_89D4_72336858156D__INCLUDED_)
#define AFX_FILESENDDLG_H__B4B8638B_8B83_42D2_89D4_72336858156D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileSendDlg.h : header file
//

#include "FileClient.h"

/////////////////////////////////////////////////////////////////////////////
// CFileSendDlg dialog

class CFileSendDlg : public CDialog
{
// Construction
public:
	CFileSendDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFileSendDlg)
	enum { IDD = IDD_DLG_SEND };
	CProgressCtrl	m_wndSendProgress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSendDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileSendDlg)
	afx_msg void OnBtnSend();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	BOOL		m_bDownSend;

	CString		m_strIP;
	CString		m_strFile;
	CFileClient	m_FileClient;


	static UINT SendThread(LPVOID pParam);
	afx_msg void OnBnClickedButton1();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILESENDDLG_H__B4B8638B_8B83_42D2_89D4_72336858156D__INCLUDED_)
