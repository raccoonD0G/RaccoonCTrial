#pragma once
#include "ILocationInterface.h"
#include "string"

class UWorld;

using namespace std;

class IRenderInterface : public ILocationInterface
{
public:
	virtual string GetScreenString() = 0;
	virtual void SetWorld(UWorld* InOwningMap) = 0;
};

