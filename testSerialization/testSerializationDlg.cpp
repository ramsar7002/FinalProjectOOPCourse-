
// testSerializationDlg.cpp : implementation file
//
#include <iostream>
#include "pch.h"
#include "framework.h"
#include "testSerialization.h"
#include "testSerializationDlg.h"
#include "afxdialogex.h"
#include"Figures.h"

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CtestSerializationDlg dialog

//Default constructor
CtestSerializationDlg::CtestSerializationDlg(CWnd* pParent) : CDialogEx(IDD_TESTSERIALIZATION_DIALOG, pParent),

cornerTopL(0,0), cornerButtomR(99999999, 99999999){
	int m_ind;
	tShape = RECTANGLE;
	isPressed = false;
	bkColor = RGB(243, 243, 243);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	MovShape = (-1);
}

void CtestSerializationDlg::DoDataExchange(CDataExchange* pDX){
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_ColorBorder);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_Backcolor);
	DDX_Control(pDX, IDC_BUTTON1, btnRectangle);
	DDX_Control(pDX, IDC_BTNCLEAR, BtnClear);
}

BEGIN_MESSAGE_MAP(CtestSerializationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CtestSerializationDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestSerializationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CtestSerializationDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CtestSerializationDlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDC_BTNCLEAR, &CtestSerializationDlg::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_BTNLINE, &CtestSerializationDlg::OnBnClickedBtnline)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(Undo_Button, &CtestSerializationDlg::OnBnClickedButton)
	ON_COMMAND(ID_FILE_SAVE32771, &CtestSerializationDlg::OnFileSaveMenu)
	ON_COMMAND(ID_FILE_OPEN32772, &CtestSerializationDlg::OnFileOpenMenu)
	ON_COMMAND(ID_BORDERSIZE_5, &CtestSerializationDlg::OnBordersize5)
	ON_COMMAND(ID_BORDERSIZE_10, &CtestSerializationDlg::OnBordersize10)
	ON_COMMAND(ID_BORDERSIZE_15, &CtestSerializationDlg::OnBordersize15)
	ON_BN_CLICKED(IDC_BTN_Rombus, &CtestSerializationDlg::OnBnClickedBtnRombus)
	ON_BN_CLICKED(IDC_BTN_Polygon, &CtestSerializationDlg::OnBnClickedBtnPolygon)
	ON_BN_CLICKED(IDC_BTN_MadenDavid, &CtestSerializationDlg::OnBnClickedBtnMadendavid)
	ON_BN_CLICKED(IDC_BTN_MoveObject, &CtestSerializationDlg::OnBnClickedBtnMoveobject)
	ON_BN_CLICKED(IDC_BUTTON8, &CtestSerializationDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CtestSerializationDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CtestSerializationDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CtestSerializationDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CtestSerializationDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CtestSerializationDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BTN_CopyObject, &CtestSerializationDlg::OnBnClickedBtnCopyobject)
	ON_COMMAND(ID_FILE_NEW_FRAME, &CtestSerializationDlg::OnFileNewProject)
	ON_COMMAND(ID_BORDERSIZE_3, &CtestSerializationDlg::OnBordersize3)
	ON_BN_CLICKED(ScreenCalBtn, &CtestSerializationDlg::OnBnClickedScreencalbtn)
	ON_BN_CLICKED(DeleteSpecificBtn, &CtestSerializationDlg::OnBnClickedDeletespecificbtn)
END_MESSAGE_MAP()

void CtestSerializationDlg::OnLButtonDown(UINT nFlags, CPoint point){

	//Change the screen corners
	if (screenCal){
		pStart = point;
		pEnd = pStart;
		AllocateNewShapeObject();
	}
	else // Validate where is the mouse pointer
		if (point.y >= cornerTopL.y && point.y <= cornerButtomR.y && point.x >= cornerTopL.x && point.x <= cornerButtomR.x){

			if (!isPressed)
				pStart = point;
			pEnd = point;
			isPressed = true;
			if (isPressed && !MoveObjMode && !deleteSpecificShape) {
				for (int i = 0; i < deletedSize; i++) {
					delete deletedShapes[i];
				}
				deletedSize = 0;
				pEnd = point;
				isPressed = true;

				if (pEnd.y <= cornerTopL.y)
					pEnd.y = cornerTopL.y;
				if (pEnd.y >= cornerButtomR.y)
					pEnd.y = cornerButtomR.y;
				if (pEnd.x <= cornerTopL.x)
					pEnd.x = cornerTopL.x;
				if (pEnd.x >= cornerButtomR.x)
					pEnd.x = cornerButtomR.x;

				AllocateNewShapeObject();

				shapes.Add(shp);
				counter = 0;
				newShape = true;
			}
			else {
				CClientDC dc(this);
				CBrush myBrush, * oldBrush;

				myBrush.CreateSolidBrush(bkColor);
				oldBrush = dc.SelectObject(&myBrush);

				CPen myPen1(PS_SOLID, borderSize, m_Backcolor.GetColor());
				CPen* oldPen;
				oldPen = dc.SelectObject(&myPen1);
				dc.SetROP2(R2_NOTXORPEN);
				MovShape = (-1);
				isPressed = true;
				if (MoveObjMode || CopyObjMode || deleteSpecificShape) {
					for (int i = shapes.GetCount() - 1; 0 <= i; i--) {
						if (shapes.ElementAt(i)->isInside(point)) {
							MovShape = i;
							tShape = shapes.GetAt(MovShape)->m_tShape;

							AllocateNewShapeObject(&shapes.ElementAt(MovShape), shapes.GetAt(MovShape)->m_borderSize);
							if (MoveObjMode || CopyObjMode) {
								shp->Draw(&dc);
								temp = shp;
							}
							if (CopyObjMode) {
								temp = shapes.ElementAt(MovShape);
								shapes.RemoveAt(MovShape);
								shapes.InsertAt(MovShape, shp);
								shapes.Add(temp);
								MovShape = shapes.GetCount() - 1;
							}

							if (deleteSpecificShape) {
								deletedShapes[deletedSize++] = shp;
								shapes.RemoveAt(MovShape);
								//deleteSpecificShape = false;
								newShape = true;
		
							}
							break;
						}
					}
				}
			}
		}
}

void CtestSerializationDlg::OnLButtonUp(UINT nFlags, CPoint point){
	// Screen calibration for printing
	

	if (screenCal){
		pEnd = point;
		cornerTopL.x = pStart.x > pEnd.x ? pEnd.x+5 : pStart.x+5;
		cornerTopL.y = pStart.y > pEnd.y ? pEnd.y+5 : pStart.y+5;

		cornerButtomR.x = pStart.x < pEnd.x ? pEnd.x-5 : pStart.x-5;
		cornerButtomR.y = pStart.y < pEnd.y ? pEnd.y-5 : pStart.y-5;
		screenBorder = shp;
		
		//InvalidateMyShape(shp->m_p1, shp->m_p2, shp->m_borderSize);
		newShape = true;
		screenCal = false;
		InvalidateMyShape(shp->m_p1, shp->m_p2, shp->m_borderSize);
		borderSize = borderTemp;
		color = ColorTemp;
		bkColor = bkColorTemp;
	}
	// Regular case
	else {
		isPressed = false;
		newShape = true;
		//InvalidateMyShape(shp->m_p1,shp->m_p2,shp->m_borderSize);
		Invalidate();
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CtestSerializationDlg::OnMouseMove(UINT nFlags, CPoint point){
	CClientDC dc(this);
	CBrush myBrush, * oldBrush;

	myBrush.CreateSolidBrush(bkColor);
	oldBrush = dc.SelectObject(&myBrush);

	CPen myPen1(PS_SOLID, borderSize, m_Backcolor.GetColor());
	CPen* oldPen;
	oldPen = dc.SelectObject(&myPen1);
	dc.SetROP2(R2_NOTXORPEN);

	if (screenCal && shp) {
		shp->m_borderSize = 20;
		shp->Draw(&dc);
		isOutOfTheScreen(point);
		shp->m_borderSize = 20;
		shp->Draw(&dc);
	}

	if (isPressed && !MoveObjMode && !deleteSpecificShape) {
		shp->Draw(&dc);
		isOutOfTheScreen(point);
		shp->Draw(&dc);
	}
	else {
		CPoint DPoint;
		if (isPressed && MovShape!=-1 && !deleteSpecificShape)
			shp = shapes.ElementAt(MovShape);
		if (MoveObjMode && isPressed && MovShape != (-1)) {
			if (shp->m_p1.x > cornerTopL.x && shp->m_p1.x < cornerButtomR.x &&
				shp->m_p1.y > cornerTopL.y && shp->m_p1.y < cornerButtomR.y &&
				shp->m_p2.x > cornerTopL.x && shp->m_p2.x < cornerButtomR.x &&
				shp->m_p2.y > cornerTopL.y && shp->m_p2.y < cornerButtomR.y)
			{
				shp->Draw(&dc);
				DPoint = point - pStart;
				pStart += DPoint;
				shp->m_p1 += DPoint;
				shp->m_p2 += DPoint;
				shp->Draw(&dc);

			}
			else{
				shapes.GetAt(MovShape)->Draw(&dc);
				CtestSerializationDlg::OnLButtonUp(nFlags, point);
				shapes.RemoveAt(MovShape);
				shapes.InsertAt(MovShape, temp);
				shapes.GetAt(MovShape)->Draw(&dc);
			}
		}
	}

	dc.SelectObject(oldPen);
	dc.SetROP2(R2_COPYPEN);
	dc.SelectObject(oldBrush);

	CDialogEx::OnMouseMove(nFlags, point);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CtestSerializationDlg::OnPaint(){
	CRect rect;
	GetClientRect(&rect);

	CPaintDC dc(this);
	CPen pen;
	pen.CreatePen(PS_DASH, borderSize, color);
	dc.SelectObject(&pen);
	if (newShape) {
		if (screenBorder)
			screenBorder->Draw(&dc);
		for (int i = 0; i < shapes.GetCount() ; i++)
			shapes.GetAt(i)->Draw(&dc);
		newShape = false;
	}
}

// Delete all the shapes
void CtestSerializationDlg::OnBnClickedBtnclear(){
	int borderSize;
	for (int i = shapes.GetCount()-1; i >= 0 ; i--) {
		borderSize = shapes.GetAt(i)->m_borderSize;
		AllocateNewShapeObject (&shapes.ElementAt(i), borderSize);
		CPoint pStart = shapes.GetAt(i)->m_p1, pEnd = shapes.GetAt(i)->m_p2;
		InvalidateMyShape(pStart, pEnd, borderSize);
		deletedShapes[deletedSize++] = shp;
	}
	shapes.RemoveAll();
	LogicSize = 0;
	newShape = true;
}

//Create new window
void CtestSerializationDlg::OnFileNewProject(){
	shapes.RemoveAll();

	for (int i = deletedSize - 1; i >= 0; i--)
		delete deletedShapes[i];
	if (screenBorder)
	{
		delete screenBorder;
	}
	screenBorder = NULL;
	Invalidate();
	deletedSize = LogicSize = 0;
}

//Delete the last shape
void CtestSerializationDlg::OnBnClickedButton(){
	if (shapes.GetCount() > 0){
		int borderSize = shapes.GetAt(shapes.GetCount() - 1)->m_borderSize;
		AllocateNewShapeObject(&shapes.ElementAt(shapes.GetCount()-1), borderSize);
		CPoint pStart = shapes.GetAt(shapes.GetCount() -1)->m_p1, 
			   pEnd   = shapes.GetAt(shapes.GetCount() -1)->m_p2;
		
		InvalidateMyShape(pStart, pEnd, shapes.GetAt(shapes.GetCount()-1)->m_borderSize);
		deletedShapes[deletedSize++] = shp;
		shapes.RemoveAt(shapes.GetCount() - 1);
		newShape = true;
	}
}

//Draw the last deleted shape
void CtestSerializationDlg::OnBnClickedButton13(){
	if (deletedSize > 0) {
		int borderSize = deletedShapes[deletedSize - 1]->m_borderSize;
		AllocateNewShapeObject(&deletedShapes[deletedSize - 1], borderSize);
		CPaintDC dc(this);
		CPen pen;
		pen.CreatePen(PS_DASH, borderSize, color);
		dc.SelectObject(&pen);
		shapes.Add(shp);
		delete deletedShapes[deletedSize-1];
		deletedSize--;
		shapes.GetAt(shapes.GetCount()-1)->Draw(&dc);
		InvalidateMyShape(shp->m_p1, shp->m_p2, shp->m_borderSize);
		//Invalidate();
		newShape = true;
	}
}

//Save shapes to file
void CtestSerializationDlg::OnFileSaveMenu(){
	// Choice and open file ostream
	CFileDialog dlg(FALSE, _TEXT("dat"), _TEXT("*.dat"));
	CString fname;
	int res = dlg.DoModal();
	if (res == IDOK)
		fname = dlg.GetPathName();

	// write to file
	CFile fOut;
	if (fOut.Open(fname, CFile::modeCreate | CFile::modeWrite)){
		CArchive ar(&fOut, CArchive::store);
		int size = shapes.GetCount();
		ar << size;
		for (int i = 0; i < size; i++) {
			shapes.GetAt(i)->Serialize(ar);
		}
		ar.Close();
		fOut.Close();
	}
	newShape = true;
	Invalidate();
}


//Load shapes from specific file
void CtestSerializationDlg::OnFileOpenMenu(){
	// Choice and open file ostream
	CFileDialog dlg(TRUE, _TEXT("dat"), _TEXT("*.dat"));
	CString fname;
	int res = dlg.DoModal();
	if (res == IDOK)
		fname = dlg.GetPathName();

	// load to file
	CFile fOut;
	if (fOut.Open(fname, CFile::modeRead)){
		CArchive ar(&fOut, CArchive::load);
		shapes.RemoveAll();
		ar >> LogicSize;
		for (int i = 0; i < LogicSize; i++) {
			int ts;
			ar >> ts;
			switch (ts) {
			case 0:
				shapes.Add(new mRectangle);
				shapes.ElementAt(i) ->m_tShape= RECTANGLE;
				break;
			case 1:
				shapes.Add(new mEllipse);
				shapes.ElementAt(i)-> m_tShape = ELLIPSE;
				break;
			case 2:
				shapes.Add(new L_Line);
				shapes.ElementAt(i)->m_tShape = L_LINE;
				break;
			case 3:
				shapes.Add(new L_Rombus);
				shapes.ElementAt(i)->m_tShape = L_ROMBUS;
				break;
			case 4:
				shapes.Add(new L_Pentagon);
				shapes.ElementAt(i)->m_tShape = L_PENTAGON;
				break;
			case 5:
				shapes.Add(new mPolygon);
				shapes.ElementAt(i)->m_tShape = POLYGON;
				break;
			case 6:
				shapes.Add(new L_TransparentRect);
				shapes.ElementAt(i)->m_tShape = L_RECTANGLE;
				break;
			case 7:
				shapes.Add(new L_Triangular);
				shapes.ElementAt(i)->m_tShape = L_TRIANGULAR;
				break;
			case 8:
				shapes.Add(new L_Star);
				shapes.ElementAt(i)->m_tShape = L_STAR;
				break;
			case 9:
				shapes.Add(new mTrianguler);
				shapes.ElementAt(i)->m_tShape = TRIANGULAR;
				break;
			case 10:
				shapes.Add(new mPentagon);
				shapes.ElementAt(i)->m_tShape = PENTAGON;
				break;
			}
			shapes.ElementAt(i)->Serialize(ar);
		}
		ar.Close();
		fOut.Close();
	}
	btnRectangle.SetFocus();
	newShape = true;
	Invalidate();
}

//Check is the mouse pointer is out of the screen
void  CtestSerializationDlg::isOutOfTheScreen(CPoint point) {
	if (point.y >= cornerTopL.y && point.y <= cornerButtomR.y && point.x >= cornerTopL.x && point.x <= cornerButtomR.x) {
		shp->m_p2 = point;
	}
	else {
		if (point.y <= cornerTopL.y && point.x <= cornerTopL.x) {
			shp->m_p2 = cornerTopL;
		}
		if (point.x >= cornerButtomR.x && point.y <= cornerTopL.y) {
			shp->m_p2.x = cornerButtomR.x; shp->m_p2.y = cornerTopL.y;
		}
		if (point.x <= cornerTopL.x && point.y >= cornerButtomR.y) {
			shp->m_p2.x = cornerTopL.x; shp->m_p2.y = cornerButtomR.y;
		}
		if (point.y >= cornerButtomR.y && point.x >= cornerButtomR.x) {
			shp->m_p2.x = cornerButtomR.x; shp->m_p2.y = cornerButtomR.y;
		}
		if (point.x <= cornerTopL.x && point.y >= cornerTopL.y && point.y <= cornerButtomR.y) {
			shp->m_p2.x = cornerTopL.x; shp->m_p2.y = point.y;
		}
		if (point.x >= cornerButtomR.x && point.y >= cornerTopL.y && point.y <= cornerButtomR.y) {
			shp->m_p2.x = cornerButtomR.x; shp->m_p2.y = point.y;
		}
		if (point.y >= cornerButtomR.y && point.x >= cornerTopL.x && point.x <= cornerButtomR.x) {
			shp->m_p2.x = point.x; shp->m_p2.y = cornerButtomR.y;
		}
		if (point.y <= cornerTopL.y && point.x >= cornerTopL.x && point.x <= cornerButtomR.x) {
			shp->m_p2.x = point.x; shp->m_p2.y = cornerTopL.y;
		}
	}
}


//Refresh the specific shape area
void CtestSerializationDlg::InvalidateMyShape(CPoint& pStart, CPoint& pEnd, int borderSize=0){
	RECT r;
	r.left = (pStart.x < pEnd.x) ? pStart.x - borderSize : pEnd.x - borderSize;
	r.top = (pStart.y < pEnd.y) ? pStart.y - borderSize : pEnd.y - borderSize;
	r.right = (pStart.x > pEnd.x) ? pStart.x + borderSize : pEnd.x + borderSize;
	r.bottom = (pStart.y > pEnd.y) ? pStart.y + borderSize : pEnd.y + borderSize;
	InvalidateRect(&r);
}


//Allocate new figure
void CtestSerializationDlg::AllocateNewShapeObject(Figures** of, int borderSize){
	switch ((*of)->m_tShape) {
	case RECTANGLE:
		shp = new mRectangle((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case ELLIPSE:
		shp = new mEllipse((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case L_LINE:
		shp = new L_Line((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case L_ROMBUS:
		shp = new L_Rombus((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case L_PENTAGON:
		shp = new L_Pentagon((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case POLYGON:
		shp = new mPolygon((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case L_RECTANGLE:
		shp = new L_TransparentRect((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case L_TRIANGULAR:
		shp = new L_Triangular((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case L_STAR:
		shp = new L_Star((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case TRIANGULAR:
		shp = new mTrianguler((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	case PENTAGON:
		shp = new mPentagon((*of)->m_p1, (*of)->m_p2, (*of)->m_color, (*of)->m_bkcolor, borderSize, (*of)->m_tShape);
		break;
	}
}

void CtestSerializationDlg::AllocateNewShapeObject(){
	switch (tShape) {
	case RECTANGLE:
		shp = new mRectangle(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case ELLIPSE:
		shp = new mEllipse(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case L_LINE:
		shp = new L_Line(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case L_ROMBUS:
		shp = new L_Rombus(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case L_PENTAGON:
		shp = new L_Pentagon(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case POLYGON:
		shp = new mPolygon(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case L_RECTANGLE:
		shp = new L_TransparentRect(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case L_TRIANGULAR:
		shp = new L_Triangular(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case L_STAR:
		shp = new L_Star(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case TRIANGULAR:
		shp = new mTrianguler(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	case PENTAGON:
		shp = new mPentagon(pStart, pEnd, color, bkColor, borderSize, tShape);
		break;
	}
}

// CtestSerializationDlg message handlers

BOOL CtestSerializationDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CtestSerializationDlg::OnQueryDragIcon(){
	return static_cast<HCURSOR>(m_hIcon);
}

// Define pen color
void CtestSerializationDlg::OnBnClickedMfccolorbutton1(){
	color = m_ColorBorder.GetColor();
	newShape = true;
	Invalidate();
}

// Define background color
void CtestSerializationDlg::OnBnClickedMfccolorbutton2(){
	bkColor = m_Backcolor.GetColor();
	newShape = true;
	Invalidate();
}


//choose figure kind 
void CtestSerializationDlg::OnBnClickedButton1(){
	if (!isPressed)
		tShape = RECTANGLE;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedButton2(){
	if (!isPressed)
		tShape = ELLIPSE;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedBtnline(){
	if (!isPressed)
		tShape = L_LINE;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedBtnRombus(){
	if (!isPressed)
		tShape = L_ROMBUS;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedBtnPolygon(){
	if (!isPressed)
		tShape = L_PENTAGON;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedBtnMadendavid(){
	if (!isPressed)
		tShape = POLYGON;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedButton8(){
	if (!isPressed)
		tShape = L_TRIANGULAR;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedButton9(){
	if (!isPressed)
		tShape = L_RECTANGLE;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedButton10(){
	if (!isPressed)
		tShape = L_STAR;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedButton11(){
	if (!isPressed)
		tShape = PENTAGON;
	MoveObjMode = false;
	deleteSpecificShape = false;
}

//choose figure kind 
void CtestSerializationDlg::OnBnClickedButton12(){
	if (!isPressed)
		tShape = TRIANGULAR;
	MoveObjMode = false;
	deleteSpecificShape = false;
}
//choose figure kind 
void CtestSerializationDlg::OnBnClickedBtnMoveobject(){
	MoveObjMode = true;
	isPressed = false;
	CopyObjMode = false;
	deleteSpecificShape = false;
}

//choose border size
void CtestSerializationDlg::OnBordersize3(){
	borderSize = 1;
}

//choose border size
void CtestSerializationDlg::OnBordersize5(){
	borderSize = 3;
}

//choose border size
void CtestSerializationDlg::OnBordersize10(){
	borderSize = 9;
}

//choose border size
void CtestSerializationDlg::OnBordersize15(){
	borderSize = 15;
}

//Copy figure button
void CtestSerializationDlg::OnBnClickedBtnCopyobject(){
	MoveObjMode = true;
	CopyObjMode = true;
	isPressed = false;
	deleteSpecificShape = false;
}

//Initilize screen size button
void CtestSerializationDlg::OnBnClickedScreencalbtn(){
	screenCal = true;
	isPressed = false;
	MoveObjMode = false;
	CopyObjMode = false;
	shp = NULL;
	if (screenBorder)
		delete screenBorder;
	screenBorder = NULL;
	borderTemp = borderSize;   bkColorTemp = bkColor;            ColorTemp = color;
	borderSize = 1;            bkColor = RGB(243, 243, 243);     color = RGB(0, 0, 0);
	deleteSpecificShape = false;
	cornerTopL.x = 0; cornerTopL.y = 0; cornerButtomR.x = 99999999; cornerButtomR.y = 99999999;
	tShape = RECTANGLE;
	OnFileNewProject();
}



void CtestSerializationDlg::OnBnClickedDeletespecificbtn()
{
	deleteSpecificShape = true;
	screenCal = false;
	isPressed = false;
	MoveObjMode = false;
	CopyObjMode = false;
}
