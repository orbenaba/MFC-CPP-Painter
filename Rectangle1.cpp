//
#include "StdAfx.h"
#include "Rectangle1.h"

IMPLEMENT_SERIAL (Rectangle1, Shape, 1)

Rectangle1::Rectangle1(void) : Shape(){} 

Rectangle1::Rectangle1(int x1,int y1, int x2, int y2,COLORREF bgColor) :Shape (x1,y1,x2,y2, bgColor){}

Rectangle1::~Rectangle1(void){}

void Rectangle1::Draw(CDC* dc)
{
	(*dc).Rectangle(x1,y1,x2,y2);
}


