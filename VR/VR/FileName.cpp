#include<iostream>
#include"Rectangle.h"
#include"Circle.h"

using namespace std;


int main()
{
	Circle donut;
	donut.setRadius(5);
	double area = donut.getArea();
	cout << "���� ������ " << area << endl;

	Circle pizza;
	pizza.setRadius(5);
	double area1 = pizza.getArea();
	cout << "���� ������ " << area1 << endl;


	Rectangle rect;
	rect.setHeight(5);
	rect.setWidth(3);
	cout << "�簢���� ������ " << rect.getArea() << endl;

	Rectangle rect1(2,5);

	if (rect1.isSquare())
	{
		cout << "���簢��" << endl;
	}
	else
	{
		cout << "���簢���� �ƴϴ�." << endl;
	}

	Rectangle rect2(3);

	if (rect2.isSquare())
	{
		cout << "���簢��" << endl;
	}
	else
	{
		cout << "���簢���� �ƴϴ�." << endl;
	}
		

	

	return 0;

}
