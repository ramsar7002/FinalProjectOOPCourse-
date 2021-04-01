#include "pch.h"
#include "L_Triangular.h"

void L_Triangular::Draw(CDC* dc){
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	int New_X;
	New_X = (m_p2.x - m_p1.x) / 2 + m_p1.x;
	dc->MoveTo(New_X, m_p1.y);
	dc->LineTo(m_p2.x, m_p2.y);
	dc->LineTo(m_p1.x, m_p2.y);
	dc->LineTo(New_X, m_p1.y);
}

IMPLEMENT_SERIAL(L_Triangular, CObject, 1)

void L_Triangular::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 7;
		ar << t;
	}
	Figures::Serialize(ar);
}
