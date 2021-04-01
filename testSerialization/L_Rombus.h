#pragma once
#include "L_Line.h"


class L_Rombus : public L_Line {
	DECLARE_SERIAL(L_Rombus)
public:
	L_Rombus(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: L_Line(p1, p2, color, bkcolor, borderSize, tShape) {}
	L_Rombus() {}
	L_Rombus(const L_Rombus& rec) : L_Line(rec) {}
	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

