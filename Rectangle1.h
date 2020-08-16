#pragma once
#include "Shape.h"
class Rectangle1 :
	public Shape
{
	DECLARE_SERIAL(Rectangle1)
public:
	Rectangle1(void);
	Rectangle1(int x1,int y1, int x2, int y2,COLORREF bgColor);
	virtual ~Rectangle1(void);
	virtual void Draw(CDC* dc);
};
	
////