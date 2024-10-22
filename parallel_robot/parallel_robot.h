
// parallel_robot.h : main header file for the parallel_robot application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CparallelrobotApp:
// See parallel_robot.cpp for the implementation of this class
//

class CparallelrobotApp : public CWinAppEx
{
public:
	CparallelrobotApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CparallelrobotApp theApp;
