#pragma once
#include "Figures.h" 

class L_Line : public Figures {
	DECLARE_SERIAL(L_Line)
public:
	L_Line(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: Figures(p1, p2, color, bkcolor, borderSize, tShape) {}
	L_Line() {}
	L_Line(const L_Line& rec) : Figures(rec) {}

	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};
