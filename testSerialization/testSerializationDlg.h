#pragma once
//#include "Figures.h"
#include <iostream>
#include "pch.h"
#include "framework.h"
#include "testSerialization.h"
#include "afxdialogex.h"
//#include "L_Line.h"
//#include "Rectangle.h"
#include "Ellipse.h"
#include "L_Pentagon.h"
#include "Polygon.h"
#include "L_Rombus.h"
#include "L_TransparentRect.h"
#include "L_Triangular.h"
#include "L_Star.h"
#include "Trianguler.h"
#include "Pentagon.h"

// CtestSerializationDlg dialog
class CtestSerializationDlg : public CDialogEx
{
	// Private data
	CTypedPtrArray <CObArray, Figures*> shapes;
	//Figures* shapes[200];	// Array of shapes
	Figures* shp = NULL;	// Pointer to one shape only
	int LogicSize = 0;		// Logic size of shapes
	CPen pen;					// pen of border
	COLORREF color = m_ColorBorder.GetColor();				// color of border
	COLORREF bkColor = m_Backcolor.GetColor();	// color of background
	CPoint pStart, pEnd;				// diagonales points
	BOOL newShape = false;			// is new shape adding
	typeFIGERS tShape;
	bool isPressed;
	bool CopyObjMode;
	int borderSize = 3;
	int MovShape;
	COLORREF bkColorTemp;
	COLORREF ColorTemp;
	int counter = 0;
	CPoint  cornerTopL,  cornerButtomR;
	CPoint temp_p1, temp_p2;
	Figures* deletedShapes[200];
	int deletedSize=0;
	Figures* temp;
	int borderTemp;
	bool screenCal = false;
	bool deleteSpecificShape = false;
	Figures* screenBorder;

	// Construction
public:
	CtestSerializationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTSERIALIZATION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	void isOutOfTheScreen(CPoint point);
	void InvalidateMyShape(CPoint&, CPoint&, int);
	void AllocateNewShapeObject(Figures**, int);
	void AllocateNewShapeObject();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton rdRectangle;
	CButton rdEllipse;
	CMFCColorButton m_ColorBorder;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedMfccolorbutton1();
	CButton rd_Rect;
	CComboBox lstShapes;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedMfccolorbutton2();
	CMFCColorButton m_Backcolor;
	CButton btnRectangle;
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnline();
	afx_msg void OnBnClickedButton();
	CButton BtnClear;
	afx_msg void OnFileSaveMenu();
	afx_msg void OnFileOpenMenu();
	afx_msg void OnBordersize5();
	afx_msg void OnBordersize10();
	afx_msg void OnBordersize15();
	afx_msg void OnBnClickedBtnRombus();
	afx_msg void OnBnClickedBtnPolygon();
	afx_msg void OnBnClickedBtnMadendavid();
	afx_msg void OnBnClickedBtnMoveobject();
	bool MoveObjMode;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedBtnCopyobject();
	afx_msg void OnFileNewProject();
	afx_msg void OnBordersize3();
	afx_msg void OnBnClickedScreencalbtn();
	afx_msg void OnBnClickedDeletespecificbtn();
};
