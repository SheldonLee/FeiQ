// FileThread.cpp : implementation file
//

#include "stdafx.h"
#include "FeiQ.h"
#include "FileThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileThread

IMPLEMENT_DYNCREATE(CFileThread, CWinThread)

CFileThread::CFileThread()
{
	m_bSendDlg = FALSE;
}

CFileThread::~CFileThread()
{
}

BOOL CFileThread::InitInstance()
{
	if (FALSE == m_bSendDlg)
	{
		m_pMainWnd = &m_FileRecvDlg;
		m_FileRecvDlg.DoModal();
	}
	else
	{
		m_pMainWnd = &m_FileSendDlg;
		m_FileSendDlg.DoModal();
	}


	return TRUE;
}

int CFileThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CFileThread, CWinThread)
	//{{AFX_MSG_MAP(CFileThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileThread message handlers

// CFileThread 消息处理程序
void CFileThread::SetSocket(SOCKET sock, CString strIP, BOOL fileSendDlg)
{
	m_FileRecvDlg.m_ClientSocket	= sock;
	m_FileRecvDlg.m_strIP			= strIP;
	m_bSendDlg						= fileSendDlg;

}

void CFileThread::SetSocket(CString strFile, CString strIP, BOOL fileSendDlg)
{
	m_FileSendDlg.m_strIP = strIP;
	m_FileSendDlg.m_strFile = strFile;
	m_bSendDlg = fileSendDlg;
}
