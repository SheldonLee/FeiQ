// UserClient.cpp: implementation of the UserClient class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FeiQ.h"
#include "UserClient.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UserClient::UserClient()
{

}

UserClient::~UserClient()
{

}

BOOL UserClient::InitClient()
{
	WSADATA wsaData;
	WORD version = MAKEWORD(2, 0);
	int ret = WSAStartup(version, &wsaData);

	//创建SOCKET
	m_ClientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == m_ClientSocket)
	{
		return FALSE;
	}

	//设置广播模式
	BOOL bBroadCast = true;
	setsockopt(m_ClientSocket, SOL_SOCKET, SO_BROADCAST, (char FAR*)&bBroadCast, sizeof(bool));
	return TRUE;
}

BOOL UserClient::Broadcast()
{
	//构造数据
	USERBROADCAST  user  = {0};
	user.header.nVersion	=1;
	user.header.nCmdID		= NETCMDID_USERBROADCAST;  //广播数据类型
	user.header.nDataLength	= sizeof(user) - sizeof(NETHEADER);

	DWORD nLen = 128;
	GetComputerName(user.szName, &nLen);
	strcpy(user.szSign, _T("Hello World"));

	//广播数据
	SendData((CHAR*)&user, sizeof(user));

	return TRUE;
}

BOOL UserClient::SendData(CHAR* psxData, UINT nLen,LPCSTR strIP)
{
	//设置广播地址
	struct sockaddr_in addr = { 0 };//指向目的套接字的地址
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT_USERSVR);

	if (strIP == NULL)
	{
		addr.sin_addr.S_un.S_addr = htonl(INADDR_BROADCAST);
		//发送广播数据
		if (SOCKET_ERROR == sendto(m_ClientSocket, psxData, nLen, 0, (struct sockaddr*)&addr, sizeof(addr)))
		{
			TCHAR str[100];
			itoa(WSAGetLastError(), str, 10);
			MessageBox(NULL, str, "socket", IDOK);
			AfxMessageBox(_T("发送数据失败"));
		}
	}
	else
	{
		SOCKET  sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
		addr.sin_addr.S_un.S_addr = inet_addr(strIP);
		sendto(sock,psxData,nLen,0,(struct sockaddr*)&addr,sizeof(addr));
	}


	return TRUE;

}

//用户正常退出
BOOL UserClient::UserQuit()
{
	USERQUIT quit = { 0 };
	quit.header.nVersion = 1;
	quit.header.nCmdID = NETCMDID_USERQUIT;
	quit.header.nDataLength = sizeof(quit)-sizeof(USERQUIT);
	quit.nExitCode = 0;

	SendData((CHAR*)&quit, sizeof(quit));

	return TRUE;
}

//聊天
BOOL UserClient::SendChat(CString strIP, CString strData, BOOL bBroadcast)
{
	//构造数据
	USERCHAT chat = { 0 };
	chat.header.nVersion = 1;
	chat.header.nCmdID = NETCMDID_USERCHAT;
	chat.header.nDataLength = sizeof(chat)-sizeof(USERCHAT);
	strcpy(chat.szChat, strData);

	if (TRUE == bBroadcast)
	{
		SendData((LPSTR)&chat, sizeof(chat));
	}
	else
	{
		SendData((LPSTR)&chat,sizeof(chat),strIP);
	}

	return TRUE;
}
