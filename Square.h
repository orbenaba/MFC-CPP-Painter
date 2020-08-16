#pragma once
#include "Shape.h"
class Square :
	public Shape
{
	DECLARE_SERIAL(Square)
public:
	Square(void);
	Square(int x1,int y1, int x2, int y2,COLORREF bgColor);
	virtual ~Square(void);
	virtual void Draw(CDC* dc);
};
//