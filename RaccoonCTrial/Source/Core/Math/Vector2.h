#pragma once

struct FVector2
{
public:
	int X;
	int Y;

public:
	FVector2() : X(0), Y(0) {}
	FVector2(int NewX, int NewY) : X(NewX), Y(NewY) {}

	FVector2(const FVector2& Other)
	{
		this->X = Other.X;
		this->Y = Other.Y;
	}

	FVector2& operator+=(const FVector2& Other)
	{
		X += Other.X;
		Y += Other.Y;
		return *this;
	}

	FVector2 operator+(const FVector2& Other) const
	{
		return FVector2(this->X + Other.X, this->Y + Other.Y);
	}
};