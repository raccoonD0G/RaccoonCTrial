#pragma once
#include "ILocationInterface.h"
#include "string"

using namespace std;

class IRenderInterface : public virtual ILocationInterface
{
public:
	virtual string GetScreenString() = 0;
	virtual void SetScreenString(string NewScreenString) = 0;
};

