
#include "pch.h"
#include "L_Pentagon.h"

void L_Pentagon::Draw(CDC* dc){
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	int New_X1, New_X2, New_X3, New_Y1;
	New_X1 = (m_p2.x - m_p1.x) / 2 / 2;
	New_X2 = New_X1 + m_p1.x;
	New_X3 = New_X1 * 3 + m_p1.x;
	New_X1 = New_X1 * 2 + m_p1.x;
	New_Y1 = (m_p2.y - m_p1.y) / 3 + m_p1.y;
	dc->MoveTo(New_X1, m_p1.y);
	dc->LineTo(m_p2.x, New_Y1);
	dc->LineTo(New_X3, m_p2.y);
	dc->LineTo(New_X2, m_p2.y);
	dc->LineTo(m_p1.x, New_Y1);
	dc->LineTo(New_X1, m_p1.y);
}

IMPLEMENT_SERIAL(L_Pentagon, CObject, 1)

void L_Pentagon::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 4;
		ar << t;
	}
	Figures::Serialize(ar);
}
