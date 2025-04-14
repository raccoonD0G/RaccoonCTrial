#pragma once

template<typename Key, typename Value>
class TPair
{
public:
	Key CurrentKey;
	Value CurrentValue;

public:
	TPair(Key InKey, Value InValue) : CurrentKey(InKey), CurrentValue(InValue) { ; }

	bool operator==(const TPair<Key, Value>& OtherPair) const
	{
		return this->CurrentValue == OtherPair.CurrentValue;
	}
};

