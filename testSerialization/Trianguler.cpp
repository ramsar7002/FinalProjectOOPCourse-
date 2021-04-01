#include "pch.h"
#include "Trianguler.h"

void mTrianguler::Draw(CDC* dc){
	CPoint vertices[3];
	vertices[0].x = m_p1.x + (m_p2.x - m_p1.x) / 2;
	vertices[0].y = m_p1.y;
	vertices[1].x = m_p2.x;
	vertices[1].y = m_p2.y;
	vertices[2].x = m_p1.x;
	vertices[2].y = m_p2.y;
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	dc->Polygon(vertices, 3);
}

IMPLEMENT_SERIAL(mTrianguler, CObject, 1)

void mTrianguler::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 9;
		ar << t;
	}
	Figures::Serialize(ar);
}