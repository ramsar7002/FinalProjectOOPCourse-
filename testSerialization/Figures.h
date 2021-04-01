#pragma once
#include "pch.h"
#include "testSerialization.h"


enum typeFIGERS { RECTANGLE,    ELLIPSE,      L_LINE,   L_ROMBUS,     L_PENTAGON,   POLYGON, 
	              L_RECTANGLE,  L_TRIANGULAR, L_STAR,   TRIANGULAR,   PENTAGON   };

class Figures : public CObject {
public:
	CPoint m_p1, m_p2;
	CPen m_border;
	COLORREF m_color;
	COLORREF m_bkcolor;
	CBrush m_bkground;
	typeFIGERS m_tShape;
	int m_borderSize;
	Figures* shp = NULL;

	Figures(CPoint p1, CPoint p2, COLORREF color, COLORREF bkcolor, int borderSize, typeFIGERS tShape)
		:m_p1(p1), m_p2(p2), m_color(color), m_bkcolor(bkcolor) ,m_tShape(tShape){
		m_borderSize = borderSize;
		m_border.CreatePen(PS_SOLID, m_borderSize, color);
		m_bkground.CreateSolidBrush(bkcolor);
	}

	Figures() : m_p1(0, 0), m_p2(0, 0), m_color(RGB(0, 0, 0)), m_bkcolor(RGB(255, 255, 255)), m_tShape(RECTANGLE) {}
	Figures(const Figures&);

	virtual ~Figures();
	

	virtual void Draw(CDC*) = 0;
	virtual bool isInside(const CPoint&);
	virtual void Serialize(CArchive&) = 0;
};
