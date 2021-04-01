// Figers.cpp : implementation file
//

#include "pch.h"
#include "testSerialization.h"
#include "Figures.h"


Figures::Figures(const Figures& fig) :m_p1(fig.m_p1), m_p2(fig.m_p2), m_color(fig.m_color),
m_bkcolor(fig.m_bkcolor), m_tShape(fig.m_tShape){
	m_borderSize = fig.m_borderSize;
	m_border.CreatePen(PS_SOLID, m_borderSize, fig.m_color);
	m_bkground.CreateSolidBrush(fig.m_bkcolor);
}

Figures::~Figures() {}

bool Figures::isInside(const CPoint & P ){
	if ((m_p1.x <= P.x && P.x <= m_p2.x || m_p1.x >= P.x && P.x >= m_p2.x) 
		&& (m_p1.y <= P.y && P.y <= m_p2.y || m_p1.y >= P.y && P.y >= m_p2.y))
		return true;
	else
		return false;
}

void Figures::Serialize(CArchive& ar){
	if (ar.IsStoring()) {
		ar << m_p1 << m_p2 << m_color << m_bkcolor << m_borderSize;
	}
	else {
		ar  >> m_p1 >> m_p2 >> m_color >> m_bkcolor >> m_borderSize;
		m_border.CreatePen(PS_SOLID, m_borderSize, m_color);
		m_bkground.CreateSolidBrush(m_bkcolor);
	}
}
