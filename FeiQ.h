// FeiQ.h : main header file for the FEIQ application
//

#if !defined(AFX_FEIQ_H__4697CAA7_4BE8_4AB7_9BF1_24CBAAC00FE9__INCLUDED_)
#define AFX_FEIQ_H__4697CAA7_4BE8_4AB7_9BF1_24CBAAC00FE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFeiQApp:
// See FeiQ.cpp for the implementation of this class
//

class CFeiQApp : public CWinApp
{
public:
	CFeiQApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFeiQApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CFeiQApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FEIQ_H__4697CAA7_4BE8_4AB7_9BF1_24CBAAC00FE9__INCLUDED_)
