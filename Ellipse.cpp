#include "StdAfx.h"
#include "Ellipse.h"
//
IMPLEMENT_SERIAL (Ellipse1, Shape, 1)

Ellipse1::Ellipse1(void): Shape(){} 

Ellipse1::Ellipse1(int x1,int y1, int x2, int y2,COLORREF bgColor) :Shape (x1,y1,x2,y2,bgColor){}

Ellipse1::~Ellipse1(void){}

void Ellipse1::Draw(CDC* dc)
{
	(*dc).Ellipse(x1,y1,x2,y2);
}
