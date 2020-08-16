//
#include "StdAfx.h"
#include "Shape.h"

IMPLEMENT_SERIAL (Shape, CObject, 1)

Shape::Shape(void):x1(0),x2(0),y1(0),y2(0),bgColor(RGB(255,255,255)){}

Shape::Shape(int x1,int y1, int x2, int y2,COLORREF bgColor) : x1(x1),x2(x2),y1(y1),y2(y2),bgColor(bgColor){}

Shape::~Shape(void){}

COLORREF Shape::getBgColor()
{
	return bgColor;
}
void Shape::setBgColor(COLORREF bgColor1)
{
	bgColor=bgColor1;
}


Shape& Shape::operator=(const Shape& s1)
{
	(*this).x1 = s1.x1;
	(*this).y1 = s1.y1;
	(*this).x2 = s1.x2;
	(*this).y2 = s1.y2;
	(*this).bgColor=s1.bgColor;
	return *this;
}

void Shape::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
		ar << x1;
		ar << x2;
		ar << y1;
		ar << y2;
		ar << bgColor;
	}
	else
	{	// loading code
        ar >> x1;
		ar >> x2;
		ar >> y1;
		ar >> y2;
		ar >> bgColor;
	}
}
