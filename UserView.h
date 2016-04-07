#if !defined(AFX_USERVIEW_H__57B6DEC1_4BDE_452E_AD76_FB7AB0D22DCF__INCLUDED_)
#define AFX_USERVIEW_H__57B6DEC1_4BDE_452E_AD76_FB7AB0D22DCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserView view

class CUserView : public CListView
{
protected:
	CUserView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CUserView)

// Attributes
public:
	

// Operations
public:
	void AddUser(CString strName, CString strIP, CString strSign);
	int  FindUser(CString strIP);

	void DelUser(CString strIP);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CUserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CUserView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERVIEW_H__57B6DEC1_4BDE_452E_AD76_FB7AB0D22DCF__INCLUDED_)
