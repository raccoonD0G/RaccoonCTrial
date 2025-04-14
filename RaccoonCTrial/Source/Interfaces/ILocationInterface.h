#pragma once

struct FVector2
{
public:
	int X;
	int Y;

public:
	FVector2() : X(0), Y(0) { ; };
	FVector2(int NewX, int NewY) : X(NewX), Y(NewY) { ; };

public:
	FVector2(const FVector2& Other)
	{
		this->X = Other.X;
		this->Y = Other.Y;
	}
};

class ILocationInterface
{
public:
	virtual FVector2 GetLocation() = 0;
	virtual void SetLocation(FVector2 NewLocation) = 0;
};

