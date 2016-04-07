// ChatView.cpp : implementation file
//

#include "stdafx.h"
#include "FeiQ.h"
#include "ChatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatView

IMPLEMENT_DYNCREATE(CChatView, CFormView)

CChatView::CChatView()
	: CFormView(CChatView::IDD)
{
	//{{AFX_DATA_INIT(CChatView)
	//}}AFX_DATA_INIT
	m_pUserClient = NULL;
}

CChatView::~CChatView()
{
}

void CChatView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatView)
	DDX_Control(pDX, IDC_CMB_CHATIP, m_wndChatIP);
	DDX_Control(pDX, IDC_LIST_CHAT, m_wndChatList);
	DDX_Control(pDX, IDC_EDIT_CHAT, m_wndChatEdit);
	DDX_Control(pDX, IDC_BTN_SEND, m_wndChatBtn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChatView, CFormView)
	//{{AFX_MSG_MAP(CChatView)
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	ON_LBN_DBLCLK(IDC_LIST_CHAT, OnDblclkListChat)
	ON_BN_CLICKED(IDC_BTN_FILE, OnBtnFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatView diagnostics

#ifdef _DEBUG
void CChatView::AssertValid() const
{
	CFormView::AssertValid();
}

void CChatView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChatView message handlers

void CChatView::OnBtnSend() 
{
	if (m_pUserClient == NULL)
	{
		return;
	}
	CString strData;
	m_wndChatEdit.GetWindowText(strData);

	int nSel = m_wndChatIP.GetCurSel();
	if ( nSel == 0 )
	{
		m_pUserClient->SendChat("", strData);
	}
	else
	{
		CString strIP;
		m_wndChatIP.GetLBText(nSel, strIP);
		m_pUserClient->SendChat(strIP, strData, FALSE);
	}
}


//界面显示数据
void CChatView::AddChat(CString strChat, CString strIP)
{
	CString strData =  strIP + _T(":") + strChat;
	int nItem = m_wndChatList.AddString(strData);
	m_wndChatList.SetCurSel(nItem);
}

//Combox 里面加入IP
void CChatView::AddUser(CString strIP)
{
	if ( -1 != m_wndChatIP.FindString(0,strIP))
	{
		return;
	}
	else
	{
		m_wndChatIP.AddString(strIP);
	}
}

void CChatView::DelUser(CString strIP)
{
	int nItem = m_wndChatIP.FindString(0,strIP);
	if (  -1 != nItem )
	{
		return;
	}
	else
	{
		m_wndChatIP.DeleteString(nItem);
	}
}

void CChatView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();

	m_wndChatIP.SetCurSel(0);
	
	// TODO: Add your specialized code here and/or call the base class
	
	
}

void CChatView::OnDblclkListChat() 
{
	
}


#include "FileThread.h"

void CChatView::OnBtnFile() 
{
	//选择发送的文件
	CFileDialog dlg(TRUE);
	if (IDOK != dlg.DoModal())
	{
		return;
	}
	CString strFilePath = dlg.GetPathName();

	CString strIP;

	/////////////////////////////////////
	int SendThreadNum = 1;
	if (m_wndChatIP.GetCurSel() == 0)
	{
		SendThreadNum = m_wndChatIP.GetCount()-1;//获取当前IP总数	,群发	
		for (int i = 1; i <= SendThreadNum; ++i)
		{
			m_wndChatIP.GetLBText(i, strIP);
			//创建一个界面线程  挂起
			CFileThread* pFileThread = (CFileThread*)
				AfxBeginThread(RUNTIME_CLASS(CFileThread),
				THREAD_PRIORITY_NORMAL,
				0,
				CREATE_SUSPENDED);

			//设置参数 将 socket 和 ip 传入
			//	strIP = _T("127.0.0.1");
			pFileThread->SetSocket(strFilePath, strIP, TRUE);
			//开始线程
			pFileThread->ResumeThread();
		}
	}
	else
	{		
		SendThreadNum = m_wndChatIP.GetCurSel();//获取当前选中IP，单发
		m_wndChatIP.GetLBText(SendThreadNum, strIP);
		//创建一个界面线程  挂起
		CFileThread* pFileThread = (CFileThread*)
			AfxBeginThread(RUNTIME_CLASS(CFileThread),
			THREAD_PRIORITY_NORMAL,
			0,
			CREATE_SUSPENDED);

		//设置参数 将 socket 和 ip 传入
		//将m_bSendDlg=TRUE;
		//	strIP = _T("127.0.0.1");
		pFileThread->SetSocket(strFilePath, strIP, TRUE);
		//开始线程
		pFileThread->ResumeThread();
	}
	/////////////////////////////////////
	
	
}
/*
void CChatView::OnBtnFile()
{
int nSel = m_wndChatIP.GetCurSel();
if (nSel == 0)
{
AfxMessageBox(_T("当选择所有IP时，可以设定群发"));
return;
}
/////////////////////////////////////
int SendThreadNum = 1;
if (nSel==0)
{
SendThreadNum = 1;
}
else
{
SendThreadNum = m_wndChatIP.GetCount();//获取当前IP总数
}
/////////////////////////////////////
CString strIP;
m_wndChatIP.GetLBText(nSel, strIP);


//选择发送的文件
CFileDialog dlg(TRUE);
if (IDOK != dlg.DoModal())
{
return;
}

CString strFilePath = dlg.GetPathName();

//创建一个界面线程  挂起
CFileThread* pFileThread = (CFileThread*)
AfxBeginThread(RUNTIME_CLASS(CFileThread),
THREAD_PRIORITY_NORMAL,
0,
CREATE_SUSPENDED);

//设置参数 将 socket 和 ip 传入
//	strIP = _T("127.0.0.1");
pFileThread->SetSocket(strFilePath, strIP, TRUE);
//开始线程
pFileThread->ResumeThread();

}

*/