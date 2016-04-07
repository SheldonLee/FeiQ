// UserServer.h: interface for the UserServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERSERVER_H__01328ECD_C819_490A_9E1F_C29BFCDC3642__INCLUDED_)
#define AFX_USERSERVER_H__01328ECD_C819_490A_9E1F_C29BFCDC3642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ChatView.h"
#include "UserView.h"
class UserServer  
{
public:
	UserServer();
	virtual ~UserServer();

public:

	//初始化User服务器
	BOOL InitServer();
	//接受数据的线程
	static UINT UserThread(LPVOID pParam);
	//处理用户广播过来的数据 服务端把数据显示到 UserView视图窗口上面
	BOOL OnUserBroadcast(LPUSERBROADCAST pUserBroadcast,CHAR* pszIP);

	//处理用户正常退出 服务端把UserView视图中 list列表里面对应的用户删除
	BOOL OnUserQuit(LPUSERQUIT pUserQuit, CHAR* pszIP);

	//处理聊天数据
	BOOL OnUserChat(LPUSERCHAT pUserChat, CHAR* pszIP);

public:
	SOCKET			m_svrSocket;
	CUserView*		m_pUserView;
	CChatView*		m_pChatView;

};

#endif // !defined(AFX_USERSERVER_H__01328ECD_C819_490A_9E1F_C29BFCDC3642__INCLUDED_)
