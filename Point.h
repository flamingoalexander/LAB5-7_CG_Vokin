#pragma once
class Point
{
public:
	float x = 0;
	float y = 0;
	float z = 0;
	Point(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	Point(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

