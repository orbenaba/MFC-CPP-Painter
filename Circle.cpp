#include "StdAfx.h"
#include "Circle.h"
//
IMPLEMENT_SERIAL (Circle, Shape, 1)

Circle::Circle(void) :Shape(){} 


Circle::Circle(int x1,int y1, int x2, int y2,COLORREF bgColor) :Shape (x1,y1,x2,y2,bgColor){}

Circle::~Circle(void){}

void Circle::Draw(CDC* dc)
{
	(*dc).Ellipse(x1,y1,x1+abs(y2-y1),y2);
}


