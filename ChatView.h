#if !defined(AFX_CHATVIEW_H__C71C5315_7E77_4A14_9475_E1BB396EF3DE__INCLUDED_)
#define AFX_CHATVIEW_H__C71C5315_7E77_4A14_9475_E1BB396EF3DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChatView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "UserClient.h"

class CChatView : public CFormView
{
protected:
	CChatView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CChatView)

// Form Data
public:
	//{{AFX_DATA(CChatView)
	enum { IDD = IDD_FORMVIEW };
	CComboBox	m_wndChatIP;
	CListBox	m_wndChatList;
	CEdit	m_wndChatEdit;
	CButton	m_wndChatBtn;
	//}}AFX_DATA

// Attributes
public:
	UserClient* m_pUserClient;

// Operations
public:
	void AddChat(CString strChat, CString strIP);

	void AddUser(CString strIP);
	void DelUser(CString strIP);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CChatView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CChatView)
	afx_msg void OnBtnSend();
	afx_msg void OnDblclkListChat();
	afx_msg void OnBtnFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATVIEW_H__C71C5315_7E77_4A14_9475_E1BB396EF3DE__INCLUDED_)
