#include "stdafx.h"
#include "flower.h"
//
IMPLEMENT_SERIAL (Flower, Shape, 1)

Flower::Flower() : Circle()
{
	leaves=new Circle[4];
}
Flower::Flower(int x1,int y1, int x2, int y2,COLORREF bgColor) :Circle (x1,y1,x2,y2,bgColor)
{
	center = Circle(x1,y1,x2,y2,bgColor);
	leaves=new Circle[4];



	
	
	leaves[0] = Circle( x1-1.5*(abs(y2-y1)),(y1-y2)/4+y1,x1,5*(y2-y1)/4+y1,bgColor);//שמאל
	leaves[1] = Circle( x1+abs(y2-y1),(y1-y2)/4+y1, x1-abs(y2-y1)+1.5*(abs(y2-y1)),5*(y2-y1)/4+y1,bgColor);//ימין
	
	



	leaves[2] = Circle(x1-(abs(y1-y2))/4 ,y1-1.5*(y2-y1),5*(abs(y1-y2))/4+x1,y1,bgColor); //למעלה
	leaves[3] = Circle(x1-(abs(y1-y2))/4,y2-1.5*(y1-y2),5*(abs(y1-y2))/4+x1,y2,bgColor); //למטה
	 


	

}
Flower::~Flower()
{
}

void Flower::Draw(CDC* dc)
{
	center.Draw(dc);
	for(int i = 0; i < 4 ;i++)
		leaves[i].Draw(dc);

}