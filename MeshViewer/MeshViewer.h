
// MeshViewer.h : main header file for the MeshViewer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMeshViewerApp:
// See MeshViewer.cpp for the implementation of this class
//

class CMeshViewerApp : public CWinApp
{
public:
	CMeshViewerApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMeshViewerApp theApp;
