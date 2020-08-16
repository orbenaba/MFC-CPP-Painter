#pragma once
#include "shape.h"
class Ellipse1 :
	public Shape
{
	DECLARE_SERIAL(Ellipse1)
public:
	Ellipse1(void);
	Ellipse1(int x1,int y1, int x2, int y2,COLORREF bgColor);
	virtual ~Ellipse1(void);
	virtual void Draw(CDC* dc);
};

//