#include "pch.h"
#include "L_Star.h"

void L_Star::Draw(CDC* dc){
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	int x[9],deltaX;
	int y[5],deltaY;
	deltaX = (m_p2.x - m_p1.x) / 12;
	deltaY = (m_p2.y - m_p1.y) / 9;
	dc->MoveTo(m_p1.x + deltaX * 6, m_p1.y);
	dc->LineTo(m_p1.x + deltaX * 7, m_p1.y + deltaY * 3);
	dc->LineTo(m_p2.x, m_p1.y + deltaY * 3);
	dc->LineTo(m_p1.x + deltaX * 8, m_p1.y + deltaY * 5);
	dc->LineTo(m_p1.x + deltaX * 9, m_p2.y);
	dc->LineTo(m_p1.x + deltaX * 6, m_p1.y + deltaY * 6);
	dc->LineTo(m_p1.x + deltaX * 3, m_p2.y);
	dc->LineTo(m_p1.x + deltaX * 4, m_p1.y + deltaY * 5);
	dc->LineTo(m_p1.x, m_p1.y + deltaY * 3);
	dc->LineTo(m_p1.x + deltaX * 5, m_p1.y + deltaY * 3);
	dc->LineTo(m_p1.x + deltaX * 6, m_p1.y);
}

IMPLEMENT_SERIAL(L_Star, CObject, 1)

void L_Star::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 8;
		ar << t;
	}
	Figures::Serialize(ar);
}