; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileSendDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FeiQ.h"
LastPage=0

ClassCount=9
Class1=CFeiQApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_DLG_RECV
Resource3=IDD_FORMVIEW (English (U.S.))
Class2=CChildView
Class5=CUserView
Class6=CChatView
Class7=CFileThread
Resource4=IDD_FORMVIEW (Chinese (Singapore))
Class8=CFileRecvDlg
Resource5=IDD_ABOUTBOX
Class9=CFileSendDlg
Resource6=IDD_DLG_SEND

[CLS:CFeiQApp]
Type=0
HeaderFile=FeiQ.h
ImplementationFile=FeiQ.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=FeiQ.cpp
ImplementationFile=FeiQ.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_APP_ABOUT
CommandCount=6

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_CUT
Command10=ID_EDIT_UNDO
CommandCount=10

[CLS:CUserView]
Type=0
HeaderFile=UserView.h
ImplementationFile=UserView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC
LastObject=CUserView

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
Class=CChatView
ControlCount=0

[DLG:IDD_FORMVIEW (Chinese (Singapore))]
Type=1
Class=CChatView
ControlCount=5
Control1=IDC_EDIT_CHAT,edit,1350631552
Control2=IDC_BTN_SEND,button,1342242816
Control3=IDC_LIST_CHAT,listbox,1352728833
Control4=IDC_CMB_CHATIP,combobox,1344340995
Control5=IDC_BTN_FILE,button,1342242816

[CLS:CChatView]
Type=0
HeaderFile=ChatView.h
ImplementationFile=ChatView.cpp
BaseClass=CFormView
Filter=D
LastObject=CChatView
VirtualFilter=VWC

[CLS:CFileThread]
Type=0
HeaderFile=FileThread.h
ImplementationFile=FileThread.cpp
BaseClass=CWinThread
Filter=N
LastObject=CFileThread

[DLG:IDD_DLG_RECV]
Type=1
Class=CFileRecvDlg
ControlCount=3
Control1=IDC_PROGRESS1,msctls_progress32,1350565888
Control2=IDC_BTN_RECV,button,1342242816
Control3=IDC_STC_Info,static,1342308352

[CLS:CFileRecvDlg]
Type=0
HeaderFile=FileRecvDlg.h
ImplementationFile=FileRecvDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BTN_RECV
VirtualFilter=dWC

[DLG:IDD_DLG_SEND]
Type=1
Class=CFileSendDlg
ControlCount=2
Control1=IDC_BTN_SEND,button,1342242816
Control2=IDC_PROGRESS1,msctls_progress32,1350565888

[CLS:CFileSendDlg]
Type=0
HeaderFile=FileSendDlg.h
ImplementationFile=FileSendDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CFileSendDlg
VirtualFilter=dWC

