#include <iostream>
#include "Circle.h"
using namespace std;
void Circle::setRadius(int r)
{
	radius = r;
}
double Circle::getArea()
{
	return 3.14 * radius * radius;
}

Circle::Circle()
{
	radius = 1;
	cout << "반지름" << radius << "원 생성" << endl;
}
Circle::Circle(int r)
{
	radius = r;
	cout << "반지름" << radius << "원 생성" << endl;
}

Circle::~Circle()
{
	cout << "반지름" << radius << "원 소멸" << endl;
}