
// ConvexHullVisialization.h : main header file for the ConvexHullVisialization application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CConvexHullVisializationApp:
// See ConvexHullVisialization.cpp for the implementation of this class
//

class CConvexHullVisializationApp : public CWinApp
{
public:
	CConvexHullVisializationApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CConvexHullVisializationApp theApp;
