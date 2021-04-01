#pragma once
#include "L_Line.h"
class L_Star : public L_Line
{
	DECLARE_SERIAL(L_Star)
public:
	L_Star(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: L_Line(p1, p2, color, bkcolor, borderSize, tShape) {}
	L_Star() {}
	L_Star(const L_Star& rec) : L_Line(rec) {}
	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

