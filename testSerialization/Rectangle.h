#pragma once
#include "Figures.h"

class mRectangle : public Figures {
	DECLARE_SERIAL(mRectangle)
public:
	mRectangle(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: Figures(p1, p2, color, bkcolor, borderSize, tShape) {}
	mRectangle() {}

	mRectangle(const mRectangle& rec) : Figures(rec) {}

	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

