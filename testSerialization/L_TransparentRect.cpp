#include "pch.h"
#include "L_TransparentRect.h"

void L_TransparentRect::Draw(CDC* dc){
	dc->SelectObject(m_border);
	dc->SelectObject(m_bkground);
	dc->MoveTo(m_p1.x, m_p1.y);
	dc->LineTo(m_p2.x, m_p1.y);
	dc->LineTo(m_p2.x, m_p2.y);
	dc->LineTo(m_p1.x, m_p2.y);
	dc->LineTo(m_p1.x, m_p1.y);
}

IMPLEMENT_SERIAL(L_TransparentRect, CObject, 1)

void L_TransparentRect::Serialize(CArchive& ar){
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		int t = 6;
		ar << t;
	}
	Figures::Serialize(ar);
}
