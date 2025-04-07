#pragma once

class Vector2
{
private:
	float X;
	float Y;

public:
	Vector2() : X(0), Y(0) { ; }
	Vector2(float NewX, float NewY) : X(NewX), Y(NewY) { ; }

	inline float GetX() { return X; }
	inline float GetY() { return Y; }

	Vector2& operator=(const Vector2& Other)
	{
		this->X = Other.X;
		this->Y = Other.Y;
		return *this;
	}

	Vector2(const Vector2& Other)
	{
		this->X = Other.X;
		this->Y = Other.Y;
	}

	Vector2(const Vector2&& Other) noexcept
	{
		this->X = Other.X;
		this->Y = Other.Y;
	}

	Vector2 operator+(const Vector2& Other) const
	{
		return Vector2(this->X + Other.X, this->Y + Other.Y);
	}

	Vector2 operator-(const Vector2& Other) const
	{
		return Vector2(this->X - Other.X, this->Y - Other.Y);
	}

	Vector2& operator+=(const Vector2& Other)
	{
		this->X + Other.X;
		this->Y + Other.Y;
		return *this;
	}

	Vector2& operator-=(const Vector2& Other)
	{
		this->X - Other.X;
		this->Y - Other.Y;
		return *this;
	}

	Vector2& operator*=(const Vector2& Other)
	{
		this->X * Other.X;
		this->Y * Other.Y;
		return *this;
	}

	Vector2& operator/=(const Vector2& Other)
	{
		this->X / Other.X;
		this->Y / Other.Y;
		return *this;
	}

	bool operator==(const Vector2& Other) const
	{
		return (this->X == Other.X) && (this->Y == Other.Y);
	}

	bool operator!=(const Vector2& Other) const
	{
		return (this->X != Other.X) || (this->Y != Other.Y);
	}

	Vector2 operator*(float Scaler) const
	{
		return Vector2(this->X * Scaler, this->Y * Scaler);
	}

	Vector2 operator/(float Scaler) const
	{
		return Vector2(this->X / Scaler, this->Y / Scaler);
	}

	Vector2 operator+(float Scaler) const
	{
		return Vector2(this->X + Scaler, this->Y + Scaler);
	}

	Vector2 operator-(float Scaler) const
	{
		return Vector2(this->X - Scaler, this->Y - Scaler);
	}
};

template <typename T>
T GetArrSum(const T Arr[], int Count)
{
	T Sum = Arr[0];
	for (int Index = 1; Index < Count; Count++)
	{
		Sum += Arr[Index];
	}

	return Sum;
}