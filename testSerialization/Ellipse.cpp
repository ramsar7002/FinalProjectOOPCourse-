#include "pch.h"
#include "Ellipse.h"

void mEllipse::Draw(CDC* dc) {
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);

	dc->Ellipse(m_p1.x, m_p1.y, m_p2.x, m_p2.y);
}

IMPLEMENT_SERIAL(mEllipse, CObject, 1)
void mEllipse::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 1;
		ar << t;
	}
	Figures::Serialize(ar);
}