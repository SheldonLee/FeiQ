// FileServer.h: interface for the CFileServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILESERVER_H__4B87C854_435F_41B2_8659_EAC23A157D8C__INCLUDED_)
#define AFX_FILESERVER_H__4B87C854_435F_41B2_8659_EAC23A157D8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFileServer  
{
public:
	CFileServer();
	virtual ~CFileServer();

public:
	//初始化服务器
	BOOL InitServer();
	//接收客户端连接的线程
	static UINT FileThread(LPVOID pParam);

	//处理连接
	void OnConnect(SOCKET clientSocket,LPSTR pszIP);

public:
	SOCKET m_svrSocket;

};

#endif // !defined(AFX_FILESERVER_H__4B87C854_435F_41B2_8659_EAC23A157D8C__INCLUDED_)
