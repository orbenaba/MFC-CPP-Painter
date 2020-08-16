#pragma once
#include "Shape.h"
class Circle :public Shape
{
		DECLARE_SERIAL(Circle)
public:
	Circle(void);
	Circle(int x1,int y1, int x2, int y2,COLORREF bgColor);
	virtual ~Circle(void);
	virtual void Draw(CDC* dc);
};

	
//
	

