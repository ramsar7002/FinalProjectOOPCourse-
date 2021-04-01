
// testSerialization.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CtestSerializationApp:
// See testSerialization.cpp for the implementation of this class
//

class CtestSerializationApp : public CWinApp
{
public:
	CtestSerializationApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
//	afx_msg void OnFileSave32771();
//	afx_msg void OnBordersize5Button();
};

extern CtestSerializationApp theApp;
