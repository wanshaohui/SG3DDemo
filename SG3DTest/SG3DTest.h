
// SG3DTest.h : main header file for the SG3DTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSG3DTestApp:
// See SG3DTest.cpp for the implementation of this class
//

class CSG3DTestApp : public CWinAppEx
{
public:
	CSG3DTestApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSG3DTestApp theApp;
