#include<iostream>
#include"Rectangle.h"
#include"Circle.h"

using namespace std;


int main()
{
	Circle donut;
	donut.setRadius(5);
	double area = donut.getArea();
	cout << "도넛 면적은 " << area << endl;

	Circle pizza;
	pizza.setRadius(5);
	double area1 = pizza.getArea();
	cout << "피자 면적은 " << area1 << endl;


	Rectangle rect;
	rect.setHeight(5);
	rect.setWidth(3);
	cout << "사각형의 면적은 " << rect.getArea() << endl;

	Rectangle rect1(2,5);

	if (rect1.isSquare())
	{
		cout << "정사각형" << endl;
	}
	else
	{
		cout << "정사각형이 아니다." << endl;
	}

	Rectangle rect2(3);

	if (rect2.isSquare())
	{
		cout << "정사각형" << endl;
	}
	else
	{
		cout << "정사각형이 아니다." << endl;
	}
		

	

	return 0;

}
