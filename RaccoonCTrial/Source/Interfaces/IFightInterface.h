#pragma once
class IFightInterface
{
public:
	virtual void GetDamaged(IFightInterface* Other) = 0;
	virtual void DoAttack(IFightInterface* Target) = 0;
};

