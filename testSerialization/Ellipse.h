#pragma once
#include "Rectangle.h"

class mEllipse : public mRectangle {
	DECLARE_SERIAL(mEllipse)
public:
	mEllipse(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		:mRectangle(p1, p2, color, bkcolor, borderSize, tShape) { }
	mEllipse() {}
	mEllipse(const mEllipse& el): mRectangle(el) {}

	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

