 #pragma once
class Rectangle
{
private:
	int width;
	int height;
public:

	double getArea();
	void setWidth(int _width);
	void setHeight(int _height);
	bool isSquare();
	Rectangle();
	Rectangle(int _width, int _height);
	Rectangle(int _width);
};