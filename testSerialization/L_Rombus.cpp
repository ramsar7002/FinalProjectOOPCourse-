#include "pch.h"
#include "L_Rombus.h"

void L_Rombus::Draw(CDC* dc){
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	int New_X, New_Y;
	New_X = (m_p2.x - m_p1.x) / 2 + m_p1.x;
	New_Y = (m_p2.y - m_p1.y) / 2 + m_p1.y;
	dc->MoveTo(New_X, m_p1.y);
	dc->LineTo(m_p2.x, New_Y);
	dc->LineTo(New_X, m_p2.y);
	dc->LineTo(m_p1.x, New_Y);
	dc->LineTo(New_X, m_p1.y);
}

IMPLEMENT_SERIAL(L_Rombus, CObject, 1)
void L_Rombus::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	int t = 3;
	if (ar.IsStoring()) {
		int t = 3;
		ar << t;
	}
	Figures::Serialize(ar);
}