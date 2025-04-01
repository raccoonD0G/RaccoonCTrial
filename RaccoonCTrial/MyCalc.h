#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Calculater
{
public:
	template <typename T>
	inline static T Add(T InNum0, T InNum1)
	{
		return InNum0 + InNum1;
	}

	template <typename T>
	inline static T Minus(T InNum0, T InNum1)
	{
		return InNum0 - InNum1;
	}

	template <typename T>
	inline static T Multiply(T InNum0, T InNum1)
	{
		return InNum0 * InNum1;
	}

	template <typename T>
	inline static T Divide(T InNum0, T InNum1)
	{
		return InNum0 / InNum1;
	}
};

class IntCalculater
{
public:
	inline static int Add(int InNum0, int InNum1)
	{
		return Calculater::Add(InNum0, InNum1);
	}

	inline static int Minus(int InNum0, int InNum1)
	{
		return Calculater::Minus(InNum0, InNum1);
	}

	inline static int Multiply(int InNum0, int InNum1)
	{
		return Calculater::Multiply(InNum0, InNum1);
	}

	inline static int Divide(int InNum0, int InNum1)
	{
		return Calculater::Divide(InNum0, InNum1);
	}
};

class FloatCalculater
{
public:
	inline static float Add(float InNum0, float InNum1)
	{
		return Calculater::Add(InNum0, InNum1);
	}

	inline static float Minus(float InNum0, float InNum1)
	{
		return Calculater::Minus(InNum0, InNum1);
	}

	inline static float Multiply(float InNum0, float InNum1)
	{
		return Calculater::Multiply(InNum0, InNum1);
	}

	inline static float Divide(float InNum0, float InNum1)
	{
		return Calculater::Divide(InNum0, InNum1);
	}
};
