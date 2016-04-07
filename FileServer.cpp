// FileServer.cpp: implementation of the CFileServer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FeiQ.h"
#include "FileServer.h"
#include "FileThread.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileServer::CFileServer()
{

}

CFileServer::~CFileServer()
{

}

BOOL CFileServer::InitServer()
{
	//创建socket
	m_svrSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (INVALID_SOCKET == m_svrSocket)
	{
		AfxMessageBox("服务端套接字创建 失败");
		
		return FALSE;
	}
	//绑定IP端口
	SOCKADDR_IN addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port  = htons(PORT_FILESVR);
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	bind(m_svrSocket,(struct sockaddr*)&addr,sizeof(addr));

	//侦听状态
	listen(m_svrSocket,5);

	//创建等候客户端的线程，因为等候是阻塞函数
	AfxBeginThread(FileThread,this);

	
	return TRUE;

}


UINT CFileServer::FileThread(LPVOID pParam)
{
	CFileServer* pThis = (CFileServer*)pParam;

	while (1)
	{
		//等候客户端连接，客户端socket过来
		SOCKADDR_IN clientAddr = {0};
		int nLen = sizeof(clientAddr);
		//阻塞函数  放到一个线程里面
		SOCKET clientSocket = accept(pThis->m_svrSocket,
									(SOCKADDR*)&clientAddr,
									&nLen);

		if (INVALID_SOCKET == clientSocket)
		{
			continue;
		}

		//得到clientSocket 就可以和客户端通信
		CHAR*  pszIP = inet_ntoa(clientAddr.sin_addr);

		pThis->OnConnect(clientSocket,pszIP);
	}
}

void CFileServer::OnConnect(SOCKET clientSocket,LPSTR pszIP)
{
	//创建一个界面线程(具有消息循环)  挂起
	CFileThread* pFileThread = (CFileThread*)
								AfxBeginThread( RUNTIME_CLASS(CFileThread),
								THREAD_PRIORITY_NORMAL,
								0,
								CREATE_SUSPENDED);

	//设置参数将 socket 和 ip传入
	pFileThread->SetSocket(clientSocket,pszIP);

	//开始线程
	pFileThread->ResumeThread();

}