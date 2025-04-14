#pragma once
class ICollisionInterface
{
public:
	virtual bool CheckOverlap(ICollisionInterface* InCollisionInterface) = 0;
};

