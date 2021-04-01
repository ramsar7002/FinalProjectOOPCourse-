#include "pch.h"
#include "Rectangle.h"

void mRectangle::Draw(CDC* dc) {
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	dc->Rectangle(m_p1.x, m_p1.y, m_p2.x, m_p2.y);
}

IMPLEMENT_SERIAL(mRectangle, CObject, 1)
void mRectangle::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 0;
		ar << t;
	}
	Figures::Serialize(ar);
}