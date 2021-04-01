#pragma once
#include "L_Line.h"

class L_Triangular : public L_Line
{
	DECLARE_SERIAL(L_Triangular)
public:
	L_Triangular(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: L_Line(p1, p2, color, bkcolor, borderSize, tShape) {}
	L_Triangular() {}
	L_Triangular(const L_Triangular& rec) : L_Line(rec) {}
	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

