#pragma once
#include "Rectangle.h"

class mPolygon : public mRectangle {
	DECLARE_SERIAL(mPolygon)
public:
	mPolygon(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: mRectangle(p1, p2, color, bkcolor, borderSize, tShape) {}
	mPolygon() {}
	mPolygon(const mPolygon& pen) : mRectangle(pen) {}

	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

