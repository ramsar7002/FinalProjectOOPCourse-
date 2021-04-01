#pragma once
#include "Rectangle.h"
class mTrianguler:public mRectangle
{
	DECLARE_SERIAL(mTrianguler)
public:
	mTrianguler(CPoint p1, CPoint p2, COLORREF& color, COLORREF& bkcolor, int borderSize, typeFIGERS tShape)
		: mRectangle(p1, p2, color, bkcolor, borderSize, tShape) {}
	mTrianguler() {}
	mTrianguler(const mTrianguler& rec) : mRectangle(rec) {}

	void Draw(CDC* dc);

	void Serialize(CArchive& ar);
};

