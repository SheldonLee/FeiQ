// UserView.cpp : implementation file
//

#include "stdafx.h"
#include "FeiQ.h"
#include "UserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserView

IMPLEMENT_DYNCREATE(CUserView, CListView)

CUserView::CUserView()
{
}

CUserView::~CUserView()
{
}


BEGIN_MESSAGE_MAP(CUserView, CListView)
	//{{AFX_MSG_MAP(CUserView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserView drawing

void CUserView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CUserView diagnostics

#ifdef _DEBUG
void CUserView::AssertValid() const
{
	CListView::AssertValid();
}

void CUserView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUserView message handlers

int CUserView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	ModifyStyle(0, LVS_REPORT);

	CListCtrl& theCtrl = GetListCtrl();
	theCtrl.InsertColumn(0, _T("计算机名称"), LVCFMT_LEFT, 100);
	theCtrl.InsertColumn(1, _T("IP地址"), LVCFMT_LEFT, 100);
	theCtrl.InsertColumn(2, _T("签名"), LVCFMT_LEFT, 230);


	SetTimer(2,1000*10,NULL);
	return 0;
}
//把收到的信息添加到用户信息
void CUserView::AddUser(CString strName, CString strIP, CString strSign)
{
	
	CListCtrl& theCtrl = GetListCtrl();
	int nItem = theCtrl.GetItemCount();
	if (-1 != FindUser(strIP))
	{
		theCtrl.SetItemData(nItem, 1); //列表里面存在  广播心跳包过来 把heartbeat置为1 表示存活
		return;
	}

	nItem = theCtrl.InsertItem(nItem, strName);
	theCtrl.SetItemText(nItem, 1, strIP);
	theCtrl.SetItemText(nItem, 2, strSign);
	theCtrl.SetItemData(nItem, 1);  //新加的用户  heartbeat置为1  表示存活
}

int CUserView::FindUser(CString strIP)
{
	CListCtrl & theCtrl = GetListCtrl();
	int nCount = theCtrl.GetItemCount();
	for (int nItem = 0; nItem < nCount; nItem++)
	{
		CString strItemIP = theCtrl.GetItemText(nItem, 1); //得到IP地址
		if ( 0 == strItemIP.CompareNoCase(strIP))
		{
			return nItem;
		}
	}
	return -1;
}

void CUserView::DelUser(CString strIP)
{
	//查找指定IP的用户
	int nItem = FindUser(strIP);
	if ( nItem == -1)
	{
		return;
	}
	//删除用户
	CListCtrl &theCtrl = GetListCtrl();
	theCtrl.DeleteItem(nItem);
}

void CUserView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//处理心跳包数据标志
	
	if (nIDEvent != 2)
	{
		return;
	}

	CListCtrl& theCtrl = GetListCtrl();

	int nCount = theCtrl.GetItemCount();

	//AfxMessageBox(_T("nCount = ")+nCount);

	for (int nItem = nCount - 1; nItem >= 0; nItem--)
	{
		//获取heartbeat数值
		DWORD nData = theCtrl.GetItemData(nItem);
		if (nData > 0)
		{
			theCtrl.SetItemData(nItem, 0);//每隔一段时间  获取heartbeat值  如果为1表示存活 置为0  下次收到心跳包 再ADDUser 又置为1
		}
		else//如果heartbeat值上次置为0，这次还是为0，说明在AddUser里面没有收到该Item的心跳包 已经断开  去除
		{
			theCtrl.DeleteItem(nItem);
		}
	}

	CListView::OnTimer(nIDEvent);
}


void CUserView::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CListCtrl& theCtrl  = GetListCtrl();
	
	//int nItem = (int)theCtrl.GetFirstSelectedItemPosition() - 1;
	int nItem = (int)theCtrl.GetFirstSelectedItemPosition();
	CString strData = theCtrl.GetItemText(nItem,0);
	
	AfxMessageBox(strData);
	*pResult = 0;
}

void CUserView::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
