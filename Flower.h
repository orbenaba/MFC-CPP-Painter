#pragma once
#include "circle.h"
#include "math.h"
//
class Flower : public Circle
{
	DECLARE_SERIAL(Flower)
private:
	Circle center;
	Circle *leaves;
public:
	Flower(void);
	Flower(int x1,int y1, int x2, int y2,COLORREF bgColor);
	virtual ~Flower();
	virtual void Draw(CDC* dc);
};