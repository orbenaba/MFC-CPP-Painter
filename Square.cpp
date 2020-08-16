//
#include "StdAfx.h"
#include "Square.h"

IMPLEMENT_SERIAL (Square, Shape, 1)

Square::Square(void): Shape(){} 

Square::Square(int x1,int y1, int x2, int y2,COLORREF bgColor) :Shape (x1,y1,x2,y2,bgColor){}

Square::~Square(void){}

void Square::Draw(CDC* dc)
{
	(*dc).Rectangle(x1,y1,x1+abs(y2-y1),y2);
}
