#pragma once
#include "ILocationInterface.h"
#include "string"

class Map;

using namespace std;

class IScreenPrintInterface : public ILocationInterface
{
public:
	virtual string GetScreenString() = 0;
	virtual void SetOwningMap(Map* InOwningMap) = 0;
};

