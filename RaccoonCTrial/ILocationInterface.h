#pragma once

struct Vector2
{
public:
	int X;
	int Y;

public:
	Vector2() : X(0), Y(0) { ; };
	Vector2(int NewX, int NewY) : X(NewX), Y(NewY) { ; };

public:
	Vector2(const Vector2& Other)
	{
		this->X = Other.X;
		this->Y = Other.Y;
	}
};

class ILocationInterface
{
public:
	virtual Vector2 GetLocation() = 0;
	virtual void SetLocation(Vector2 NewLocation) = 0;
};

