#pragma once
class Circle
{

	int radius;
public:
	double getArea();
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r);
};