#pragma once
#include "Core/Math/Vector2.h"

struct FBox
{
public:
	FVector2 Min;
    FVector2 Max;

public:
	FBox() : Min(0, 0), Max(0, 0) { ; }
	FBox(const FVector2& InMin, const FVector2& InMax) : Min(InMin), Max(InMax) { ; }

    bool IsInside(const FVector2& Point) const
    {
        return (Point.X >= Min.X && Point.X <= Max.X && Point.Y >= Min.Y && Point.Y <= Max.Y);
    }

    bool Intersects(const FBox& Other) const
    {
        return !(Max.X < Other.Min.X || Min.X > Other.Max.X ||  Max.Y < Other.Min.Y || Min.Y > Other.Max.Y);
    }

};

