// ADOOperatePic2.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ADOOperatePic2.h"
#include "ADOOperatePic2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePic2App

BEGIN_MESSAGE_MAP(CADOOperatePic2App, CWinApp)
	//{{AFX_MSG_MAP(CADOOperatePic2App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePic2App construction

CADOOperatePic2App::CADOOperatePic2App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CADOOperatePic2App object

CADOOperatePic2App theApp;

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePic2App initialization

BOOL CADOOperatePic2App::InitInstance()
{
	AfxEnableControlContainer();
	AfxOleInit();//��ʼ��COM
	m_pConnection.CreateInstance("ADODB.Connection");
	/******************�������ݿ�********************/
	try
	{
		m_pConnection->ConnectionTimeout = 6;
		//m_pConnection->Open("Driver=SQL Server;Database=test;Server=127.0.0.1;UID=sa;PWD=;","","",adModeUnknown);
		//����ACCESS2000
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=PicInfo.mdb","","",adModeUnknown);
	}
	catch(_com_error e)///��׽�쳣
	{
		AfxMessageBox("���ݿ�����ʧ��!");
		return FALSE;
	} 
	/**********************************************/

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CADOOperatePic2Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CADOOperatePic2App::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_pConnection->State)
		m_pConnection->Close();//�ر����Ӷ���
	m_pConnection.Release();
	return CWinApp::ExitInstance();
}