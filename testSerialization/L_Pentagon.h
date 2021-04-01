#pragma once
#include "L_Line.h"

class L_Pentagon : public L_Line {
	DECLARE_SERIAL(L_Pentagon)
public:
	L_Pentagon(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: L_Line(p1, p2, color, bkcolor, borderSize, tShape) {}
	L_Pentagon() {}
	L_Pentagon(const L_Pentagon& rec) : L_Line(rec) {}

	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

