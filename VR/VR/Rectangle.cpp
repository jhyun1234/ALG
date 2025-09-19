#include "Rectangle.h"

double Rectangle::getArea()
{
	return width * height;
}

void Rectangle::setHeight(int _height)
{
	height = _height;
}

void Rectangle::setWidth(int _width)
{
	width = _width;
}

Rectangle::Rectangle(int _width, int _height)
{
	width = _width;
	height = _height;
}
Rectangle::Rectangle(int _width)
{
	width = height = _width;
}
Rectangle::Rectangle()
{
	width = 0;
	height = 0;
}
bool Rectangle::isSquare()
{
	return width == height;

}