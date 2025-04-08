#pragma once
#include "ILocationInterface.h"
#include "string"

using namespace std;

class IScreenPrintInterface : public ILocationInterface
{
public:
	virtual string GetScreenString() = 0;
};

