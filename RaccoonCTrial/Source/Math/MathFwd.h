#pragma once

#include <algorithm>

struct FVector2D
{
public:
	FVector2D() : X(0), Y(0) { ; }
	FVector2D(float NewX, float NewY) : X(NewX), Y(NewY) { ; }
	virtual ~FVector2D() { ; }

	FVector2D(const FVector2D& Other)
	{
		this->X = Other.X;
		this->Y = Other.Y;
	}

	FVector2D& operator+=(const FVector2D& Other)
	{
		X += Other.X;
		Y += Other.Y;
		return *this;
	}

	FVector2D operator+(const FVector2D& Other) const
	{
		return FVector2D(this->X + Other.X, this->Y + Other.Y);
	}

public:
	float X;
	float Y;
};

struct FBox
{
public:
    FBox() : Min(0, 0), Max(0, 0) { ; }
	FBox(const FVector2D& InA, const FVector2D& InB)
	{
		Min = FVector2D(std::min(InA.X, InB.X), std::min(InA.Y, InB.Y));
		Max = FVector2D(std::max(InA.X, InB.X), std::max(InA.Y, InB.Y));
	}

    virtual ~FBox() { ; }

    bool IsInside(const FVector2D& Point) const
    {
        return (Point.X >= Min.X && Point.X <= Max.X && Point.Y >= Min.Y && Point.Y <= Max.Y);
    }

    bool Intersects(const FBox& Other) const
    {
        return !(Max.X < Other.Min.X || Min.X > Other.Max.X || Max.Y < Other.Min.Y || Min.Y > Other.Max.Y);
    }

public:
    FVector2D Min;
    FVector2D Max;
};

