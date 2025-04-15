#pragma once
#include "ILocationInterface.h"
#include "string"


class IRenderInterface
{
public:
	virtual ~IRenderInterface() { ; }
	virtual std::string GetRenderString() = 0;
	virtual void SetRenderString(const std::string& NewScreenString) = 0;
};

