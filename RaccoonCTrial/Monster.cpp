#include "Monster.h"
#include "random"

string Monster::GetScreenString()
{
    return "M";
}

void Monster::RandomMove()
{
	random_device RandomDevice;
	mt19937 Generator(RandomDevice());
	uniform_int_distribution<> Distribution(0, 3);
	int MonsterValue = Distribution(Generator);

	Vector2 TargetVector;
	switch (MonsterValue)
	{
	case 0:
		TargetVector = Vector2(this->GetLocation().X, this->GetLocation().Y - 1);
		break;
	case 1:
		TargetVector = Vector2(this->GetLocation().X - 1, this->GetLocation().Y);
		break;
	case 2:
		TargetVector = Vector2(this->GetLocation().X, this->GetLocation().Y + 1);
		break;
	case 3:
		TargetVector = Vector2(this->GetLocation().X + 1, this->GetLocation().Y);
		break;
	}

	OwningMap->MoveScreenPrintTarget(this->GetLocation(), TargetVector);
}
