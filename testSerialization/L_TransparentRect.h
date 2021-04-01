#pragma once
#include "L_Line.h"

class L_TransparentRect: public L_Line
{
	DECLARE_SERIAL(L_TransparentRect)
public:
	L_TransparentRect(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: L_Line(p1, p2, color, bkcolor, borderSize, tShape) {}
	L_TransparentRect() {}
	L_TransparentRect(const L_TransparentRect& rec) : L_Line(rec) {}

	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

