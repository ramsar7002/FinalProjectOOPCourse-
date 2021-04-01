#include "pch.h"
#include "Polygon.h"

void mPolygon::Draw(CDC* dc){
	CPoint center = m_p1 + m_p2;
	center.x /= 2.0; center.y /= 2.0;
	double radius = abs(m_p1.x - m_p2.x) < abs(m_p1.y - m_p2.y) ? abs(m_p1.x - m_p2.x) / 2.0 : abs(m_p1.y - m_p2.y) / 2.0;
	CPoint vertices[12];
	double two_pi = atan(1) * 8;
	for (int i = 0; i < 12; i++){
		if (i % 2 == 0){
			vertices[i].x = center.x + radius / sqrt(3) * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius / sqrt(3) * sin(two_pi / 12 * i);
		}
		else{
			vertices[i].x = center.x + radius * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius * sin(two_pi / 12 * i);
		}
	}
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	dc->Polygon(vertices, 12);
}

IMPLEMENT_SERIAL(mPolygon, CObject, 1)

void mPolygon::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 5;
		ar << t;
	}
	Figures::Serialize(ar);
}