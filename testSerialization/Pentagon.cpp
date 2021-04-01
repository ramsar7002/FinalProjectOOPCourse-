#include "pch.h"
#include "Pentagon.h"

void mPentagon::Draw(CDC* dc){
	CPoint vertices[5];
	int New_X1, New_X2, New_X3, New_Y1;
	New_X1 = (m_p2.x - m_p1.x) / 2 / 2;
	New_X2 = New_X1 + m_p1.x;
	New_X3 = New_X1 * 3 + m_p1.x;
	New_X1 = New_X1 * 2 + m_p1.x;
	New_Y1 = (m_p2.y - m_p1.y) / 3 + m_p1.y;

	vertices[0].x = New_X1;       vertices[0].y = m_p1.y;
	vertices[1].x = m_p2.x;       vertices[1].y = New_Y1;
	vertices[2].x = New_X3;       vertices[2].y = m_p2.y;
	vertices[3].x = New_X2;       vertices[3].y = m_p2.y;
	vertices[4].x = m_p1.x;       vertices[4].y = New_Y1;

	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	dc->Polygon(vertices, 5);
}

IMPLEMENT_SERIAL(mPentagon, CObject, 1)

void mPentagon::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 10;
		ar << t;
	}
	Figures::Serialize(ar);
}