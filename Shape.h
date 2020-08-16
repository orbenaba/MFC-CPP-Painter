#pragma once
class Shape : public CObject //  מחלקת אב שהצורה יורשת ממנה
{
	DECLARE_SERIAL(Shape)//סריליזציה
protected:
	int x1, x2, y1, y2;
	COLORREF bgColor; 

public:
	Shape(void);
	Shape(int x1,int y1, int x2, int y2,COLORREF bgColor);
	virtual void Draw(CDC *dc){};
	virtual ~Shape(void);
	virtual void Serialize(CArchive& ar);
	COLORREF getBgColor();
	void setBgColor(COLORREF bgColor1);
	Shape& operator=(const Shape& s1);

};
//