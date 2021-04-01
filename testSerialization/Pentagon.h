#pragma once
#include "Rectangle.h"
class mPentagon: public mRectangle 
{
	DECLARE_SERIAL(mPentagon)
public:
	mPentagon(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: mRectangle(p1, p2, color, bkcolor, borderSize, tShape) {}
	mPentagon() {}
	mPentagon(const mPentagon& pen) : mRectangle(pen) {}


	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

