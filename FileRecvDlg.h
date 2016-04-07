#if !defined(AFX_FILERECVDLG_H__25DA6C3A_8B6B_457B_BCF7_2D83576697BC__INCLUDED_)
#define AFX_FILERECVDLG_H__25DA6C3A_8B6B_457B_BCF7_2D83576697BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileRecvDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileRecvDlg dialog

class CFileRecvDlg : public CDialog
{
// Construction
public:
	CFileRecvDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFileRecvDlg();

// Dialog Data
	//{{AFX_DATA(CFileRecvDlg)
	enum { IDD = IDD_DLG_RECV };
	CStatic	m_wndInfo;
	CProgressCtrl	m_wndProgress;
	CButton	m_btnRecv;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileRecvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL




// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileRecvDlg)
	afx_msg void OnBtnRecv();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


public:
	SOCKET			m_ClientSocket;
	CString			m_strIP;

	SENDFILE		m_sendFile;
	CString			m_strFilePath;

public:
	//接收线程
	static UINT FileRecvThread(LPVOID pParam);

	//数据的接收
	BOOL RecvData(LPVOID pData, DWORD nLen);
	
	afx_msg void OnBnClickedBtnRecvClose();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILERECVDLG_H__25DA6C3A_8B6B_457B_BCF7_2D83576697BC__INCLUDED_)
