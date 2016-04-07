// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "FeiQ.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "ChatView.h"
#include "UserView.h"
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_SETFOCUS()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	//AfxMessageBox(_T("hello sunny pig"));
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the fram

	//修改应用程序左上角的图片
	HICON m_hIcon = AfxGetApp()->LoadIcon(IDI_MYICON);
	SetIcon(m_hIcon,TRUE);
	SetIcon(m_hIcon,FALSE);

	Initialize();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.cx = 550;
	cs.cy = 650;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class


	//切分窗口
	m_wndSplitter.CreateStatic(this, 2, 1);
	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CUserView), CSize(200, 200), pContext);
	m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(CChatView), CSize(200, 200), pContext);


	//获取UserView的地址
	m_userServer.m_pUserView = (CUserView*)m_wndSplitter.GetPane(0,0);


	//获取ChatView的地址
	CChatView* pChatView     = (CChatView*)m_wndSplitter.GetPane(1, 0);


	m_userServer.m_pChatView = pChatView;//服务端调里面有ChatView的一个指针，指向ChatView的地址

	pChatView->m_pUserClient = &m_userClient;//创建好chatview后 chatView里面有一个 UserClient的指针，指向 m_userClient；
	
	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::Initialize()
{
	if (TRUE != m_userServer.InitServer())
	{
		AfxMessageBox(_T("用户创建服务器失败！"));
	}

	if (TRUE != m_userClient.InitClient())
	{
		AfxMessageBox(_T("用户客户端创建失败！"));
	}
	
	if (TRUE != m_FileServer.InitServer())
	{
		AfxMessageBox(_T("文件服务器创建失败！"));
	}
	
	m_userClient.Broadcast();

	SetTimer(1, 500 * 10, NULL);
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_userClient.Broadcast();
	CFrameWnd::OnTimer(nIDEvent);
}

//关闭程序，用户正常退出
void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	m_userClient.UserQuit(); // 调用正常退出消息，向服务端发送正常退出消息
	CFrameWnd::OnClose();
}
